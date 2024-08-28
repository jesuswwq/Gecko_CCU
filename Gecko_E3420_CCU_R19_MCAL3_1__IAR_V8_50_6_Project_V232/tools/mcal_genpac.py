# coding=UTF-8
#!/usr/bin/python
import json
import sys
import getopt
import os
import glob
import shutil
import distutils.dir_util
import subprocess
import shlex
import math
import platform
import re

global BPT_SZ
BPT_SZ=0x1000
global XSPI1_MEM_BASE
XSPI1_MEM_BASE = 0x10000000
global SP_EXIT
global SX_EXIT
global RAM_SIZE
global RAM_BASE
SP_EXIT = True
SX_EXIT = True
global CHIP_ID
global XIP
global CASCADE
global GHS

g_objEncryption=[]
DEF_BOOT_SZ=0x400000
PAC_ALIGN=0x20000

def str_trans(input):
    if input == "true":
        return "1"
    else:
        return "0"


def file_align(file_name, align_size):
    try:
        file_size = math.ceil(os.path.getsize(file_name) / align_size) * align_size
        fo = open(file_name, "r+")
        fo.truncate(file_size)
        fo.close()
        print("%s is aligned to 0x%x" %(file_name, align_size))
    except Exception as e:
        raise Exception("getsize %s error:\n    %s" %(file_name,e))

def pac_align(mem_offset, align_size):
    return math.ceil(mem_offset / align_size) * align_size

def calc_dlp(mem_offset):
    return int(mem_offset/512)

def try_copy(file, path):
    try:
        shutil.copy(file, path)
    except Exception as e:
        raise Exception("copy %s error:\n    %s" %(file,e))

def is_taishan_l(chip_id):
    if chip_id == "E3104" or chip_id == "E3106" or chip_id == "E3205" or chip_id == "E3206":
        return True
    else:
        return False

def exe_pac(pac_type, BOARD, PROJECT,  slave_project,\
iib_str_list, lib_str_list_cascade, sfs_name, boot0_addr, boot1_addr, boot2_addr, rfd_name,  \
key_str, boot_package_num, ctl_str, uuid_str, dloader_entry, other_file_list, ver):

    global g_objEncryption
    print("exe_pac_start")
    dloader_unsigned = ("dloader_%s.bin" % BOARD)
    dloader_signed = ("dloader_%s_signed.bin" % BOARD)
    flashloader_unsigned = ("flashloader_%s.bin" % BOARD)
    flashloader_signed = ("flashloader_%s_signed.bin" % BOARD)

    output_pac = os.path.join(PAC_TEMP_PATH, ("%s_%s.pac" % (pac_type, PROJECT)))
    sign_boot_package_slv = "none"

    #Clean the env
    if os.path.exists(output_pac):
        os.remove(output_pac)

    #Change work path
    os.chdir(os.path.join(PWD, "tools", "sdtools"))

    if DOWNLOADER_TYPE == "both" or DOWNLOADER_TYPE == "dloader":
        print("\n-----sign dloader key = %s:" % key_str)
        #sign Dloader
        try:
            sign_dloader = ATB_SIGNER + " sign --v 2 --sec_ver 0x1234 --dgst sha256 %s \n--iib core=0 type=0x0 image=temp/%s to=%s entry=%s %s %s \n--psn 0x01 --of temp/%s" %(key_str, dloader_unsigned, dloader_entry, dloader_entry, ctl_str, uuid_str, dloader_signed)
            print(sign_dloader)
            args = shlex.split(sign_dloader)
            subprocess.run(args, check=True)
        except Exception as e:
            raise Exception("sign dloader error:\n    %s" %e)
        if DOWNLOADER_TYPE == "both":
            print("copy flashload...")
            shutil.copy(os.path.join(os.getcwd(), "temp", flashloader_unsigned), os.path.join(os.getcwd(), "temp", flashloader_signed))            
    else:
        #Copy flashloader to temp 
        print("copy flashload...")
        shutil.copy(os.path.join(os.getcwd(), "temp", flashloader_unsigned), os.path.join(os.getcwd(), "temp", flashloader_signed))

    mcal_name=["mcal_signed_normal.bin", "mcal_signed_backup.bin", "mcal_signed_third.bin"]
    boot_package_version = ver
    num = [0, 1, 2]
    for i in num:
        if i >= boot_package_num:
            break
        print("\n-----sign boot package %d key = %s:" % (num[i], key_str))
        sign_boot_package = ATB_SIGNER + " sign --v 2 --sec_ver 0x1234 --dgst sha256 %s \n%s --psn %s --of temp/%s" %(key_str, iib_str_list[i], boot_package_version[i], mcal_name[i])   
        print(sign_boot_package)
        #Slv Project only sign one time
        if i == 0:     
            if lib_str_list_cascade[0] != "none":
                print("Sign the slave project")
                sign_boot_package_slv = ATB_SIGNER + " sign --v 2 --sec_ver 0x1234 --dgst sha256 %s \n%s --psn %s --of temp/%s_iar_signed.bin" %(key_str, lib_str_list_cascade[0], boot_package_version[i], slave_project)   
                print(sign_boot_package_slv)


        #RFD
        try:
            if sign_boot_package_slv != "none":
                args = shlex.split(sign_boot_package_slv)
                subprocess.run(args, check=True)

            args = shlex.split(sign_boot_package)
            subprocess.run(args, check=True)
            #Encrypte boot image
            if len(g_objEncryption) > 0 and \
                    g_objEncryption["encryption_on"] == "true" and \
                    i < len(g_objEncryption["rfd"]):

                strOriginalFile = mcal_name[i]
                strEncryFile = mcal_name[i] + ".sign"
                strEncrypteCmd = ATB_SIGNER + " xspi_enc "

                strKs = ""
                if "ks" in g_objEncryption:
                    strKs = g_objEncryption["ks"]
                    strEncrypteCmd += " ks={0} ".format(strKs)

                strPvkName = ""
                pvkName = ["pvk0", "pvk1", "pvk2", "pvk3"]
                for pvk in pvkName:
                    if pvk in g_objEncryption["rfd"][i]:
                        strPvkName = pvk
                        break

                strKek = ""
                if "kek" in g_objEncryption["rfd"][i]:
                    strKek = g_objEncryption["rfd"][i]["kek"]

                strIek = ""
                if "iek" in g_objEncryption["rfd"][i]:
                    strIek = g_objEncryption["rfd"][i]["iek"]

                strIv = g_objEncryption["rfd"][i]["iv"]

                if strPvkName != "":
                    strPvkVal = g_objEncryption["rfd"][i][strPvkName]
                    strEncrypteCmd = strEncrypteCmd + " {0}={1} iv={2} " \
                            .format(strPvkName,strPvkVal,strIv)
                else:
                    strEncrypteCmd = strEncrypteCmd + " iek={0} iv={1} " \
                            .format(strIek,strIv)
                pass
                strEncrypteCmd = strEncrypteCmd + " if=temp/{0} of=temp/{1}" \
                        .format(strOriginalFile , strEncryFile)

                print("Encryte Boot Image...")
                print(strEncrypteCmd)
                args = shlex.split(strEncrypteCmd)
                subprocess.run(args, check=True)
                mcal_name[i] = strEncryFile
            file_align( ("temp/%s" %mcal_name[i]), 4096)
        except Exception as e:
            raise Exception("sign boot package error:\n    %s" %e)


    #gen sfs binary
    if pac_type == "ospi":
        print("\n-----gen_sfs_binary:")
        gen_sfs_binary = "pactool/gen_sfs_binary.exe --json ../sfs/%s \n--out temp/sfs.img \n--normal_img_off %s \n--backup_img_off %s \n--third_img_off %s" %(sfs_name, boot0_addr, boot1_addr, boot2_addr)
        print(gen_sfs_binary)
        try:
            args = shlex.split(gen_sfs_binary)
            subprocess.run(args, check=True)
        except Exception as e:
            raise Exception("gen_sfs_binary error:\n    %s" %e)

    if CASCADE == True:
        PROJECT = PROJECT + "_cascade_mst"
    #gen pac
    if DOWNLOADER_TYPE == "both":
        print("\n-----generating PAC  without parition : %s" % output_pac)
        if pac_type == "ospi":
            paccmd = "pactool/pactool.exe make_pac_image_no_gpt \n" + \
            ("--output temp_pac/%s/%s_%s.pac \n" % (PROJECT, pac_type, PROJECT)) + \
            ("--product e3 \n") + \
            ("--allow_empty_partitions \n") + \
            ("--preload sfs|temp/sfs.img \n") + \
            ("--preload rfd|%s \n" % rfd_name) + \
            ("--preload boot0|temp/%s \n" % mcal_name[0]) + \
            ("--da FDA|temp/%s \n" % flashloader_signed) + \
            ("--da FDA|temp/%s \n" % dloader_signed)
    else:
        print("\n-----generating PAC  without parition : %s" % output_pac)
        if pac_type == "ospi":
            paccmd = "pactool/pactool.exe make_pac_image_no_gpt \n" + \
            ("--output temp_pac/%s/%s_%s.pac \n" % (PROJECT, pac_type, PROJECT)) + \
            ("--allow_empty_partitions \n") + \
            ("--preload sfs|temp/sfs.img \n") + \
            ("--preload rfd|%s \n" % rfd_name) + \
            ("--preload boot0|temp/%s \n" % mcal_name[0]) + \
            ("--da FDA|temp/%s \n" % dloader_signed)

    if boot_package_num > 1:
        paccmd = paccmd +("--preload boot1|temp/%s \n" % mcal_name[1])

    if boot_package_num > 2:
        paccmd = paccmd +("--preload boot2|temp/%s \n" % mcal_name[2])

    if CASCADE == False:
        if (other_file_list != "none"):
            if TOOLCHAIN == "IAR":
                paccmd = paccmd +("--image 0x140000|temp/%s \n" % ("%s_iar.bin"%(PROJECT)))
            elif TOOLCHAIN == "GCC":
                paccmd = paccmd +("--image 0x140000|temp/%s \n" % ("%s_xip_gcc.bin"%(PROJECT)))
    else:
        if XIP == False:
            if TOOLCHAIN == "IAR":
                paccmd = paccmd +("--image 0xD00000|temp/%s \n" % ("%s_iar_signed.bin"%(slave_project)))
            elif TOOLCHAIN == "GCC":
                paccmd = paccmd +("--image 0xD00000|temp/%s \n" % ("%s_gcc.bin"%(slave_project)))  
        else:
            if TOOLCHAIN == "IAR":
                paccmd = paccmd +("--image 0x140000|temp/%s \n" % ("%s_xip_iar.bin"%(PROJECT)))   
                paccmd = paccmd +("--image 0xD00000|temp/%s \n" % ("%s_iar_signed.bin"%(slave_project)))    
    try:
        args = shlex.split(paccmd)
        print(paccmd)
        subprocess.run(args, check=True)
    except Exception as e:
        raise Exception("generating PAC  without parition error:\n    %s" %e)


    os.chdir(PWD)

    try_copy(os.path.join(PAC_TEMP_PATH, "%s_%s.pac" % (pac_type, PROJECT)), PAC_PTAH)
    print("exe_pac_end, pac path is %s" %(os.path.join(PAC_PTAH,"%s_%s.pac" % (pac_type, PROJECT))))

def gen_pac(board_name, project_name, json_cfg, downloader, slave_project):

    global g_objEncryption
    global RAM_SIZE
    global SX_EXIT
    global SP_EXIT
    global DOWNLOADER_TYPE
    global CHIP_ID
    flash_type = "none"
    
    if CASCADE == True:
        CHIP_ID = "cascade"
    print(CHIP_ID)

    if "pac" in json_cfg:
        pac = json_cfg.get("pac")
        for pac_inst in pac :

            flash_type = pac_inst.get("flash_type", "hyperflash")
            
            DOWNLOADER_TYPE = pac_inst.get("downloader_type", "both")
            print("DOWNLOADER_TYPE is %s!\n" % DOWNLOADER_TYPE)

            #Find the flashloader or dloader
            if downloader == "default":
                #deloader
                if DOWNLOADER_TYPE == "dloader":
                    if json_cfg.get("board") == "bga324":
                        downloader = os.path.join(os.getcwd(), "tools", "IAR_Ddf", "flashloader", "SemiDrive",CHIP_ID ,("%s_dloader_%s.bin" % (("bga324_" + CHIP_ID), flash_type)))
                    else:
                        downloader = os.path.join(os.getcwd(), "tools", "IAR_Ddf", "flashloader", "SemiDrive",CHIP_ID ,("%s_dloader_%s.bin" % (CHIP_ID, flash_type)))
                    try_copy(downloader, os.path.join(BIN_PATH, ("dloader_%s.bin" % board_name)))
                #flashloader
                elif DOWNLOADER_TYPE == "flashloader":
                    downloader = os.path.join(os.getcwd(), "tools", "IAR_Ddf", "flashloader", "SemiDrive",CHIP_ID ,("flashloader_%s.out" % (flash_type)))
                    try_copy(downloader, os.path.join(BIN_PATH, ("flashloader_%s.bin" % board_name)))
                #both
                elif DOWNLOADER_TYPE == "both":
                    if json_cfg.get("board") == "bga324":
                        downloader = os.path.join(os.getcwd(), "tools", "IAR_Ddf", "flashloader", "SemiDrive",CHIP_ID ,("%s_dloader_%s.bin" % (("bga324_" + CHIP_ID), flash_type)))
                    else:
                        downloader = os.path.join(os.getcwd(), "tools", "IAR_Ddf", "flashloader", "SemiDrive",CHIP_ID ,("%s_dloader_%s.bin" % (CHIP_ID, flash_type)))
                    try_copy(downloader, os.path.join(BIN_PATH, ("dloader_%s.bin" % board_name)))
                    downloader = os.path.join(os.getcwd(), "tools", "IAR_Ddf", "flashloader", "SemiDrive",CHIP_ID ,("flashloader_%s.out" % (flash_type)))
                    try_copy(downloader, os.path.join(BIN_PATH, ("flashloader_%s.bin" % board_name)))
           
            # Json file has bootloader file,it is xip project
            else:
                #Copy flashloader
                if DOWNLOADER_TYPE != "dloader":
                    downloader = os.path.join(os.getcwd(), "tools", "IAR_Ddf", "flashloader", "SemiDrive",CHIP_ID ,("flashloader_%s.out" % (flash_type)))
                    try_copy(downloader, os.path.join(BIN_PATH, ("flashloader_%s.bin" % board_name)))

            # copy dloder binary or flash loader
            if os.path.exists(downloader) == False:
                print("Copye downloader file fail!\n")            

            # copy bin dir to temp dir
            for files in glob.glob(os.path.join(BIN_PATH, "*")):
                try_copy(files, TEMP_PATH)

            print("copy to temp successfully!\n")
            try:
                pac_type = pac_inst["type"]
            except:
                raise Exception("can not find [pac]-[type] in [%s] please check json file" %pac_json)

            if pac_type == "emmc" and DOWNLOADER_TYPE == "flashloader":
                sys.exit()

            print("\n****************************************gen pac for %s************************************************\n " % pac_type)

            #Get sfs configuration information
            try:
                sfs = pac_inst["sfs"]
                sfs_name = sfs["name"]
                boot0_addr = sfs["boot0_addr"]
                boot1_addr = sfs["boot1_addr"]
                boot2_addr = sfs["boot2_addr"]
            except:
                if pac_type == "ospi":
                    raise Exception("Error in [%s] 's sfs, please check json file"  % pac_json)
                else:
                    raise Exception("Error in [%s] 's sfs, please check json file"  % pac_json)

            boot0_end = 0x0
            boot1_end = 0x0
            boot2_end = 0x0
            
            #Normally boot1_addr wont be 0
            if boot1_addr == "":
                boot0_end = int(boot0_addr,16) + int(DEF_BOOT_SZ,16)
            else:
                boot0_end = int(boot1_addr,16)

            if boot2_addr == "":
                boot1_end = int(boot1_addr,16) + int(boot1_addr, 16) - int(boot0_addr)
            else:
                boot1_end = int(boot2_addr,16)
                #int(boot2_addr, 16) - int(boot1_addr,16) caculate the capacity of boot2
                boot2_end = int(boot2_addr, 16) + int(boot2_addr, 16) - int(boot1_addr,16)
            
            #Caculate region of 3 boot packages 
            boot_region = [{"start":int(boot0_addr,16), "end":boot0_end},{"start":int(boot1_addr,16), "end":boot1_end},{"start":int(boot2_addr,16), "end":boot2_end}]
            #Read Encryption configuration
            strNewRfd=""

            #If RFD should be packed in package
            if "encryption" in pac_inst:
                g_objEncryption = pac_inst["encryption"]
                print("Begin to creating rfd image..."+g_objEncryption["encryption_on"])
                if g_objEncryption["encryption_on"] == "true":
                    print("Begin to creating rfd image...")
                    strRfdCmd = ""
                    strSrkKey = ""
                
                    if "srk" in g_objEncryption:
                        strSrkKey = g_objEncryption["srk"]

                    strKs = ""
                    if "ks" in g_objEncryption:
                        strKs = g_objEncryption["ks"]

                    objRfdArray = g_objEncryption["rfd"]

                    strRfdCmd = " xspi_wrap "
                    if strSrkKey != "":
                        strRfdCmd += " srk=" + strSrkKey

                    if strKs != "":
                        strRfdCmd += " ks=" + strKs

                    print("strRfdCmd:"+strRfdCmd)
                    rfdIdx = 0
                    for objRfd in objRfdArray:
                        strCurRfdCmd=""
                        strKek = ""
                        if "kek" in objRfd:
                            strKek = objRfd["kek"]

                        strIek = ""
                        if "iek" in objRfd:
                            strIek = objRfd["iek"]
                        
                        #Must
                        strIv = objRfd["iv"]
                        strStart = objRfd["start"]
                        strEnd = objRfd["end"]
                        strPvk = ""
                        pvkName = ["pvk0", "pvk1", "pvk2", "pvk3"]
                        for pvk in pvkName:
                            if pvk in objRfd:
                                strPvk = pvk
                                break
                        
                        #Normally must
                        if "boot" in objRfd and objRfd["boot"] == "true":
                            if boot_region[rfdIdx]["start"] != int(strStart, 16) or boot_region[rfdIdx]["end"] != int(strEnd, 16):
                                print("rfd:"+str(rfdIdx)+" region addr is not match sfs!")
                                print("rfd start:" + strStart + " rfd end:"+ strEnd)
                                print("boot start:%#x"%boot_region[rfdIdx]["start"] + " boot end:%#x"%boot_region[rfdIdx]["end"])
                                exit()

                        if strPvk != "":
                            strPvkVal = objRfd[strPvk]
                            strCurRfdCmd = " --rfd {0}={1} iv={2} start={3} end={4} "\
                                    .format(strPvk,strPvkVal,strIv,strStart,strEnd)
                            pass
                        else:
                            strCurRfdCmd = " --rfd kek={0} iek={1} iv={2} start={3} end={4} "\
                                    .format(strKek,strIek,strIv,strStart,strEnd)
                            pass
                        rfdIdx += 1
                        strRfdCmd = strRfdCmd + strCurRfdCmd
                    strNewRfd="temp/new.rfd"
                    os.chdir(os.path.join(os.getcwd(),"tools", "sdtools"))
                    strRfdCmd = ATB_SIGNER  + strRfdCmd + " of=" + strNewRfd
                    print("Generate RFD Command:")
                    print(strRfdCmd)
                    args = shlex.split(strRfdCmd)
                    subprocess.run(args, check=True)
                    os.chdir(PWD)
            else:
                print("No Encryption configuration,Skip...")
                g_objEncryption = []
            #RFD generating ends
            
            rfd_name      = pac_inst.get("rfd_name", "xspi_wrap_rfd_blk_pvk1_ks.rfd")
            key           = pac_inst.get("key", "none")
            ctl           = pac_inst.get("ctl", "none")
            uuid          = pac_inst.get("uuid", "none")
            dloader_entry = pac_inst.get("dloader_entry", "0x404000")
            ver0          = pac_inst.get("ver0", "0x100")
            ver1          = pac_inst.get("ver1", "0x100")
            ver2          = pac_inst.get("ver2", "0x100")
            ver           = [ver0, ver1, ver2]

            #if has not generated rfd documents
            if strNewRfd == "":
                rfd_name = "rfd/" + rfd_name
            else:
                rfd_name = strNewRfd

            #Involved
            if key != "none":
                key_str = "--rcp key=sign_tool/keys/%s" % key
            else:
                key_str = " "

            #not involved.
            if ctl != "none":
                ctl_str = "ctl=%s" % ctl
            else:
                ctl_str = " "

            #not involved.
            if uuid != "none":
                uuid_str = "uuid=%s" % uuid
            else:
                uuid_str = " "

            boot_package_num    = int(pac_inst.get("boot_package_num", "3"))

            if (boot_package_num > 3) or (boot_package_num <= 0):
                boot_package_num = 3

            if boot_package_num == 1:
                boot1_addr = "0x0"
                boot2_addr = "0x0"
            if boot_package_num == 2:
                boot2_addr = "0x0"

            try:
                core = pac_inst["core"]
                iib_str_list = []
                lib_str_list_cascade = []
                lib_str_list_cascade.append("none")

                SF_ALIGN = int(core.get("sf_pad_size", "0x1000"),16)

                BOOTLOADER_ALIGN = int(core.get("bootloader_pad_size", "0x1000"),16)
                #pad the bin
                for files in glob.glob(os.path.join(TEMP_PATH, "*")):
                    
                    #Align sf.bin
                    if XIP == False:
                        if os.path.basename(files) == (("%s.bin" % (project_name))) and SF_ALIGN!= 0:
                            file_align(files, SF_ALIGN)
                            print("n_xip align boot package successfully!\n")
                        #Align bootload.bin
                        # elif os.path.basename(files) == "bootloader.bin" and BOOTLOADER_ALIGN!= 0:
                        #     file_align(files, BOOTLOADER_ALIGN)
                    elif XIP == True:
                        if os.path.basename(files) == (("%s_bootloader.bin" % (project_name))) and SF_ALIGN!= 0:
                            file_align(files, SF_ALIGN)
                            print("xip align bootlader successfully!\n")
                num = [0, 1, 2]
                membase = 0
                memsize = 0
                pacoffset = 0
                dlp = 0

                print("Ready to Caculate boot region.\n")

                if pac_type == "ospi":
                    boot_addr_array = [int(boot0_addr,16), int(boot1_addr,16), int(boot2_addr,16)]

                for i in num:
                    # sf iib str

                    if i >= boot_package_num:
                        break
                        
                    if XIP == False:
                        if os.path.exists(os.path.join(TEMP_PATH, ("%s.bin" % (project_name)))) == False:
                            raise Exception("can not find project.bin in %s" % os.path.join(TEMP_PATH, ("%s.bin" % (project_name))))
                    elif XIP == True:
                        if os.path.exists(os.path.join(TEMP_PATH, ("%s_bootloader.bin" % (project_name)))) == False:
                            raise Exception("can not find project.bin in %s" % os.path.join(TEMP_PATH, ("%s_bootloader.bin" % (project_name))))                        

                    pacoffset = BPT_SZ

                    membase = int(core.get("sf_entry", "0x404000"), 16)
                    
                    if XIP == False:
                        memsize = os.path.getsize(os.path.join(TEMP_PATH, ("%s.bin" % (project_name))))
                    elif XIP == True:
                        memsize = os.path.getsize(os.path.join(TEMP_PATH, ("%s_bootloader.bin" % (project_name))))

                    if ((membase > (RAM_SIZE + RAM_BASE)) or ((membase + memsize) > (RAM_SIZE + RAM_BASE))):
                        print("membase 0x%x or memsize 0x%x exceed the limit size 0x%x\n" %(membase, memsize, (RAM_SIZE + RAM_BASE)))
                        sys.exit(1)

                    #Offset
                    dlp = calc_dlp(pacoffset)
                    pacoffset = pac_align((pacoffset + memsize), PAC_ALIGN)

                    if XIP == False:
                        iib_str = "--iib core=0 type=0x0 image=temp/%s.bin dlp=0x%x to=0x%x entry=0x%x %s %s \n" % (project_name, dlp, membase, membase, ctl_str, uuid_str)
                    elif XIP == True:
                        iib_str = "--iib core=0 type=0x0 image=temp/%s_bootloader.bin dlp=0x%x to=0x%x entry=0x%x %s %s \n" % (project_name, dlp, membase, membase, ctl_str, uuid_str)

                    iib_str_list.append(iib_str)
                    #print(iib_str_list[i])
                if CASCADE == True:
                    if TOOLCHAIN == "IAR":
                        lib_str_list_cascade[0] = "--iib core=0 type=0x0 image=temp/%s.bin to=0x504000  entry=0x504000  %s %s \n" % (slave_project + "_cascade_slv_iar", ctl_str, uuid_str)


            except Exception as e:
                raise Exception("parse project:[%s] 's core setup error:\n    %s" % (project_name, e))



            #Xip_mode will use,to copy project bin to temp dir.
            if TOOLCHAIN == "IAR":
                if CASCADE == False:
                    other_file_list = pac_inst.get("other_file", "none")
                    #Xip project
                    if (other_file_list != "none"):
                        print("find other file!\n")
                        other_file_list[0] = os.path.join(os.getcwd(), "iar", "iar_v850", project_name, CONFIG_NAME, "Exe", "%s.bin" % (project_name))
                        print("copy %s to %s" %(other_file_list[0], os.path.join(TEMP_PATH, os.path.basename(other_file_list[0]))))
                        try_copy(other_file_list[0], os.path.join(TEMP_PATH, "%s_iar.bin"%(project_name)))                            
                elif CASCADE == True:
                    if XIP == False:
                        slave_project = slave_project + "_cascade_slv"
                        other_file_list = os.path.join(os.getcwd(), "iar", "iar_v850", slave_project, CONFIG_NAME, "Exe", "%s.bin" % (slave_project))
                        print("Other file is:",other_file_list) 
                        if os.path.exists(other_file_list) == False:
                            print ("fail")
                            sys.exit(-1) 
                        else:
                            print(other_file_list)           
                            try_copy(other_file_list, os.path.join(TEMP_PATH, "%s_iar.bin" %(slave_project)))     
                    else:
                        other_file_list = pac_inst.get("other_file", "none")
                        project_name = project_name + "_cascade_mst_xip"
                        slave_project = slave_project + "_cascade_slv"
                        other_file_list[0] = os.path.join(os.getcwd(), "iar", "iar_v850", project_name, CONFIG_NAME, "Exe", "%s.bin" % (project_name))
                        other_file_list[1] = os.path.join(os.getcwd(), "iar", "iar_v850", slave_project, CONFIG_NAME, "Exe", "%s.bin" % (slave_project))
                        print("Other file is:",other_file_list[0])
                        print("Other file is:",other_file_list[1])
                        if os.path.exists(other_file_list[0]) == False:
                            print ("fail to find cascade_mst_xip.bin")
                            sys.exit(-1) 
                        else:
                            print(other_file_list[0])           
                            try_copy(other_file_list[0], os.path.join(TEMP_PATH, "%s_iar.bin" %(project_name)))

                        if os.path.exists(other_file_list[1]) == False:
                            print ("fail to find cascade_slv.bin")
                            sys.exit(-1) 
                        else:
                            print(other_file_list[1])           
                            try_copy(other_file_list[1], os.path.join(TEMP_PATH, "%s_iar.bin" %(slave_project)))     

                        project_name = str(project_name).replace("_cascade_mst_xip", "")  


            elif TOOLCHAIN == "GCC":
                other_file_list = pac_inst.get("other_file", "none")
                if other_file_list != "none":
                    other_file_list = os.path.join(os.getcwd(), "build", project_name, "%s_sf_mcal_testsuite.elf.bin" % (project_name)) 
                    print(other_file_list)               
                    if os.path.exists(other_file_list) == False:
                        print ("fail")
                        sys.exit(-1) 
                    else:
                        print(other_file_list)
                        print(TEMP_PATH)          
                        try_copy(other_file_list, os.path.join(TEMP_PATH, "%s_xip_gcc.bin" %(project_name)))                                              
                if CASCADE == True:
                    slave_project = slave_project + "_cascade_slv"
                    other_file_list = os.path.join(os.getcwd(), "build", slave_project, "%s.elf.bin" % (slave_project))
                    print("Other file is:",other_file_list) 
                    if os.path.exists(other_file_list) == False:
                        print ("fail")
                        sys.exit(-1) 
                    else:
                        print(other_file_list)           
                        try_copy(other_file_list, os.path.join(TEMP_PATH, "%s_gcc.bin" %(slave_project)))   
            elif TOOLCHAIN == "GHS":
                other_file_list = pac_inst.get("other_file", "none")

            try:
                exe_pac(pac_type , board_name, project_name, slave_project, iib_str_list, lib_str_list_cascade, sfs_name, \
                boot0_addr, boot1_addr, boot2_addr, rfd_name,  key_str, boot_package_num, ctl_str, uuid_str, dloader_entry, other_file_list, \
                ver)

            except Exception as e:
                raise Exception("exe_pac error:\n    %s"  %e)


    else:
        raise Exception("can not find 'pac' in json %s, please check" %json_cfg)

class LazyDecoder(json.JSONDecoder):
    def decode(self, s, **kwargs):
        regex_replacements = [
            (re.compile(r'([^\\])\\([^\\])'), r'\1\\\\\2'),
            (re.compile(r',(\s*])'), r'\1'),
        ]
        for regex, replacement in regex_replacements:
            s = regex.sub(replacement, s)
        return super().decode(s, **kwargs)

if __name__ == "__main__":
    QUERY_MODE = 0
    CONFIG_NAME = "Debug"
    CHIP_ID = "none"
    PAC_ONLY_BY_FILE  = False
    PAC_CONFIG_FILE_NAME = "none"
    downloader = "default"
    BOARD = "none"
    PROJECT = "none"
    PYTHON = "none"
    CASCADE_PROJECT = []
    CASCADE_BOARD = []
    CASCADE_CHIPID = []
    CASCADE_PROJECT_PATH = []

    TOOLCHAIN = "IAR"
    PROJECT_PATH = "none"
    DOWNLOADER_TYPE = "none"
    XIP = False
    FLASHTYPE = "none"
    JSON_PROJECT = "none"
    CRYPTO = False
    BGA = False
    CASCADE = False
    GHS = False
    

    try:
        opts, args = getopt.getopt(sys.argv[1:], '-p:-v:-f:-x:')
    except Exception as e:
        print("get opt error:\n    %s" % e)
        sys.exit(-1)

    for opt_name, opt_value in opts:     
        #e.g. E3_ref_gateway_E3640/E3_ref_176_lite_E3106
        if opt_name in ('-p', '--project'):
            PROJECT = opt_value
            os.environ['PROJECT'] = opt_value
            print("PROJECT is %s" % PROJECT)

            #Cascade project
            if re.findall('cascade_mst', PROJECT) == ['cascade_mst']:
                CASCADE = True
                print("It is a Cascade_Mst Project")
                CASCADE_PROJECT.append(PROJECT.replace("".join(re.findall('_cascade_mst', PROJECT)), ''))  
                print("Cascade Master is %s" %CASCADE_PROJECT[0])
                continue
            if re.findall('cascade_slv', PROJECT) == ['cascade_slv']:
                print("It is a Cascade_Slv Project")
                CASCADE_PROJECT.append(PROJECT.replace("".join(re.findall('_cascade_slv', PROJECT)), ''))  
                print("Cascade Slave is %s" %CASCADE_PROJECT[1])
                break

            #Normal Project
            if re.findall('sf', PROJECT) == ['sf']:
                GHS = True
                print("The output is from GHS compiling!")
                PROJECT = PROJECT.replace("".join(re.findall('_sf', PROJECT)), '')

            if re.findall('xip', PROJECT) == ['xip']:
                XIP = True
                print("It is a xip project!")
                PROJECT = PROJECT.replace("".join(re.findall('_xip', PROJECT)), '')
            else:
                print("It is an iram-build project!")
            
            #Crypro project
            if "crypto" in PROJECT:
                CRYPTO = True
                PROJECT = PROJECT.replace("_crypto", '')
                print("It is a crypto project")
        
            #Bga project
            if "bga" in PROJECT:
                BGA = True
                BOARD = re.findall('E...[0-9]$',PROJECT)
                BOARD = "".join(BOARD)

                CHIP_ID = re.findall('[0-9]',BOARD)
                CHIP_ID = "".join(CHIP_ID)

                BOARD = PROJECT.replace("_%s"%BOARD, '')
                PROJECT = PROJECT.replace("_%s"%("".join(re.findall('E...[0-9]$', PROJECT))), '')
                print("It is a bga version.")

            else:
                BOARD = re.findall('E...[0-9]$',PROJECT)
                BOARD = "".join(BOARD)

                CHIP_ID = re.findall('[0-9]',BOARD)
                CHIP_ID = "".join(CHIP_ID)

                BOARD = PROJECT.replace("_%s"%BOARD, '')

            if CRYPTO == True:
                PROJECT = PROJECT +"_crypto"

            JSON_PROJECT = PROJECT    

            print("Board is %s." %BOARD)
            print("ChipId is %s." %CHIP_ID)

        #IAR
        if opt_name in ('-v', '--version'):
            TOOLCHAIN = opt_value
            print("TOOLCHAIN is %s" % TOOLCHAIN)
            if TOOLCHAIN == "IAR":
                CONFIG_NAME = "Release"
                print("IAR Release project will be packed.")
            elif TOOLCHAIN == "GCC":
                print("GCC compile project will be packed.")
            elif TOOLCHAIN == "GHS":
                print("GHS compile project will be packed.")               
        
        #Kind of Flash
        if opt_name in ('-f', '--flash'):
            if opt_value == "hyperflash":
                FLASHTYPE = "hyperflash"
            elif opt_value == "norflash":
                FLASHTYPE = "norflash"

    #Deal with Cascade Project
    if CASCADE == True:
        #Cascade:Collect TOOLCHAIN & FLASHTYPE & XIP
        for opt_name, opt_value in opts:
            if opt_name in ('-v', '--version'):
                TOOLCHAIN = opt_value
                print("TOOLCHAIN is %s" % TOOLCHAIN)
                if TOOLCHAIN == "IAR":
                    CONFIG_NAME = "Release"
                    print("IAR Release project will be packed.")
                elif TOOLCHAIN == "GCC":
                    print("GCC compile project will be packed.")
                elif TOOLCHAIN == "GHS":
                    print("GHS compile project will be packed.")                
        
            #Kind of Flash
            if opt_name in ('-f', '--flash'):
                if opt_value == "hyperflash":
                    FLASHTYPE = "hyperflash"
                elif opt_value == "norflash":
                    FLASHTYPE = "norflash"

            #Xip project
            if opt_name in ('-x', '--xip'):
                if opt_value == "xip":
                    XIP = True

        
        #Cascade:Collect Board's name and Master's chip ID
        CASCADE_BOARD.append(re.findall('E...[0-9]$',CASCADE_PROJECT[0]))
        CASCADE_BOARD.append(re.findall('E...[0-9]$',CASCADE_PROJECT[1]))
        CASCADE_BOARD[0] = "".join(CASCADE_BOARD[0])
        CASCADE_BOARD[1] = "".join(CASCADE_BOARD[1])

        CASCADE_CHIPID.append(re.findall('[0-9]',CASCADE_BOARD[0]))
        CASCADE_CHIPID.append(re.findall('[0-9]',CASCADE_BOARD[1]))
        CASCADE_CHIPID[0] = "".join(CASCADE_CHIPID[0])
        CASCADE_CHIPID[1] = "".join(CASCADE_CHIPID[1])

        CASCADE_BOARD[0] = str(CASCADE_PROJECT[0]).replace("_%s"%CASCADE_BOARD[0], '')
        CASCADE_BOARD[1] = str(CASCADE_PROJECT[1]).replace("_%s"%CASCADE_BOARD[1], '')

        print("Mst Board is %s." %CASCADE_BOARD[0])
        print("Slv Board is %s." %CASCADE_BOARD[1])

        print("Mst ChipId is %s." %CASCADE_CHIPID[0])
        print("Slv ChipId is %s." %CASCADE_CHIPID[1])

        CHIP_ID = str(CASCADE_CHIPID[0])

        if FLASHTYPE == "none":
            if CHIP_ID == 3640:
                FLASHTYPE = "hyperflash"


    if FLASHTYPE == "none":
        if CHIP_ID == "3106" or CHIP_ID == "3104" or CHIP_ID == "3110" or CHIP_ID == "3205":
            FLASHTYPE = "norflash"
        elif CHIP_ID == "3420" or CHIP_ID == "3430" or CHIP_ID == "3640" or CHIP_ID == "3648":
            FLASHTYPE = "hyperflash"
        elif CHIP_ID == "3206" or CHIP_ID == "3210":
            FLASHTYPE = "hyperflash"

    print("FlashType is ", FLASHTYPE)


                

    # #Crypro project
    if CRYPTO == True:
        JSON_PROJECT = PROJECT.replace("_crypto", '')
        print("Json file will find in %s folder."%JSON_PROJECT)
        

    #Bga project
    if BGA == True:
        JSON_PROJECT = PROJECT + "_" + CHIP_ID
        print("Json file will find in %s folder."%JSON_PROJECT)
        

    #Json file
    #PAC_CONFIG_FILE_NAME will be given by project and xip.
        
    #Normal Project
    if CASCADE == False:
        #Xip project
        if XIP == True:
            PAC_CONFIG_FILE_NAME = os.path.join(os.getcwd(), "tools", "json_file", "%s" %(JSON_PROJECT), "pacconfig", "xip", "pac_config_sf_%s_xip.json" %(FLASHTYPE))
            if os.path.exists(PAC_CONFIG_FILE_NAME) == False:
                print ("Can not find the json file,please check your input.")
                sys.exit(-1)
            else:
                if TOOLCHAIN == "IAR":
                    PROJECT = PROJECT + "_xip"
                    print("Project",PROJECT)
        #N_xip project
        else:
            PAC_CONFIG_FILE_NAME = os.path.join(os.getcwd(), "tools", "json_file", "%s" %(JSON_PROJECT), "pacconfig", "n_xip", "pac_config_sf_%s.json" %(FLASHTYPE))
            if os.path.exists(PAC_CONFIG_FILE_NAME) == False:
                print ("Can not find the json file,please check your input.")
                sys.exit(-1)
    #Cascade Project            
    else:
        #Xip project
        if XIP == True:
            PAC_CONFIG_FILE_NAME = os.path.join(os.getcwd(), "tools", "json_file", "%s" %(CASCADE_PROJECT[0]), "pacconfig", "xip", "pac_config_sf_%s_xip.json" %(FLASHTYPE))
            if os.path.exists(PAC_CONFIG_FILE_NAME) == False:
                print ("Can not find the json file,please check your input.")
                sys.exit(-1)
            else:
                if TOOLCHAIN == "IAR":
                    print("Master Project", CASCADE_PROJECT[0] + "_xip")
                    print("Slave Project", CASCADE_PROJECT[1] + "_xip")
        #N_xip project
        else:
            PAC_CONFIG_FILE_NAME = os.path.join(os.getcwd(), "tools", "json_file", "%s" %(CASCADE_PROJECT[0]), "pacconfig", "n_xip", "pac_config_sf_%s.json" %(FLASHTYPE))
            if os.path.exists(PAC_CONFIG_FILE_NAME) == False:
                print ("Can not find the json file,please check your input.")
                sys.exit(-1)



    #Open the json file
    try:
        f = open(PAC_CONFIG_FILE_NAME)
    except:
        raise("Can not find %s" % PAC_CONFIG_FILE_NAME)
    json_cfg = json.load(f, cls=LazyDecoder)
    description = json_cfg.get("description", "e3 pac json file")
    print("description is " + description)


    
    if CASCADE == False:
        if BOARD == "none" or PROJECT == "none":
            print("Must input the PROJECT")
            sys.exit(-1)    
    else:           
        if str(CASCADE_BOARD[0]) == None or str(CASCADE_PROJECT[0]) == None:
            print("Must input the CASCADE PROJECT")
            sys.exit(-1)        

    taishan_l_flag = is_taishan_l(CHIP_ID)

    if taishan_l_flag:
        RAM_BASE = 0x500000
    else:
        RAM_BASE = 0x400000
    RAM_SIZE = 0x400000

    PWD            = os.path.join(os.getcwd())
    SDTOOLS        = os.path.join(os.getcwd(), "tools", "sdtools")
    OTHERS_PATH    = os.path.join(os.getcwd(), "tools", "sdtools", "others")
    
    TEMP_PATH      = os.path.join(SDTOOLS, "temp")
    BIN_PATH       = os.path.join(SDTOOLS, "bin")
    if CASCADE == False:
        PAC_TEMP_PATH  = os.path.join(SDTOOLS, "temp_pac", PROJECT)
    else:
        PAC_TEMP_PATH  = os.path.join(SDTOOLS, "temp_pac", CASCADE_BOARD[0] + "_E" + CHIP_ID + "_cascade_mst")

    sysstr = platform.system()
    if sysstr =="Windows":
        ATB_SIGNER = "../sign_tool_e3/atb_signer_win/atb_signer.exe"
        print ("Call Windows tasks")

    shutil.rmtree(TEMP_PATH, ignore_errors=True)
    shutil.rmtree(BIN_PATH, ignore_errors=True)
    shutil.rmtree(PAC_TEMP_PATH, ignore_errors=True)

    os.makedirs(TEMP_PATH, exist_ok=True)
    os.makedirs(BIN_PATH, exist_ok=True)
    os.makedirs(PAC_TEMP_PATH, exist_ok=True)

    #Normal Project
    if CASCADE == False:
        #N_xip project
        if(XIP == False):
            if PAC_CONFIG_FILE_NAME == "none":
                print ("Must select a pac config file, eg: -f devices\E3640\pac_config_sf.json")
                sys.exit(-1)

            pac_json = PAC_CONFIG_FILE_NAME
            if os.path.exists(pac_json) == False:
                print ("pac config file %s not exist." % pac_json)
                sys.exit(-1)

            #Project
            if TOOLCHAIN == "IAR":
                project_path = os.path.join(os.getcwd(), "iar", "iar_v850", PROJECT, CONFIG_NAME, "Exe", "%s.bin" % (PROJECT))
                if os.path.exists(project_path) == False:
                    print ("Fail to find the bin.")
                    sys.exit(-1)
                else:
                    PROJECT_PATH = os.path.abspath(project_path)
            elif TOOLCHAIN == "GCC":
                project_path = os.path.join(os.getcwd(), "build", PROJECT, "%s_sf_mcal_testsuite.elf.bin" % (PROJECT))
                print(project_path)
                if os.path.exists(project_path) == False:
                    print ("Fail to find the bin.")
                    sys.exit(-1)
                else:
                    PROJECT_PATH = os.path.abspath(project_path)      
            elif TOOLCHAIN == "GHS":
                project_path = os.path.join(os.getcwd(), "ghs", "%s_sf" % (PROJECT), "bin", "debug", "%s_sf.mem" % (PROJECT))
                if os.path.exists(project_path) == False:
                    print ("Fail to find the bin.")
                    sys.exit(-1)
                else:
                    PROJECT_PATH = os.path.abspath(project_path)                             

            if PROJECT_PATH == "none":
                print ("can not find the project path")
                sys.exit(-1)

            print("gen pac for board=%s, project=%s toolchain=%s project_path =%s" % (BOARD, PROJECT, TOOLCHAIN, PROJECT_PATH))
            
            if os.path.exists(os.path.join(PROJECT_PATH)) == True:
                if TOOLCHAIN == "IAR":
                    mcal_bin_file  = os.path.join(PROJECT_PATH)
                elif TOOLCHAIN == "GCC":
                    mcal_bin_file  = os.path.join(PROJECT_PATH)
                elif TOOLCHAIN == "GHS":
                    mcal_bin_file  = os.path.join(PROJECT_PATH)    

            # Copy binaries to bin dir
            for bin in glob.glob(mcal_bin_file):
                try_copy(bin, os.path.join(BIN_PATH, "%s.bin" % (PROJECT)))
                print("\ncopy %s file to %s." %(bin, BIN_PATH))

            print("Generate PAC according to %s" % pac_json)
            try:
                f = open(pac_json)
            except:
                raise("Can not find %s" % pac_json)
            json_cfg = json.load(f)
            description = json_cfg.get("description", "e3 pac json file")
            print("description is " + description)
            if TOOLCHAIN == "IAR":
                PAC_PTAH       = os.path.join(os.getcwd(), "iar", "iar_v850", PROJECT)
            elif TOOLCHAIN == "GCC":
                PAC_PTAH       = os.path.join(os.getcwd(), "build", PROJECT)
            elif TOOLCHAIN == "GHS":
                PAC_PTAH       = os.path.join(os.getcwd(), "ghs", "%s_sf" %(PROJECT))                
        else:
            print("Generate PAC according to %s" % PAC_CONFIG_FILE_NAME)
            if "bootload_path" in json_cfg:
                bootload_path = json_cfg.get("bootload_path")
                try_copy(bootload_path, os.path.join(BIN_PATH, "%s_bootloader.bin" %(PROJECT)))
                print("bootload file is %s" % bootload_path)
            else:
                print("must have a sf file:\n    %s")
                sys.exit(-1)

            if "downloader_path" in json_cfg:
                downloader_path = json_cfg.get("downloader_path")
                try_copy(downloader_path, os.path.join(BIN_PATH, "dloader_%s.bin" %(BOARD)))
                print("downloader file is %s" % downloader_path)
                downloader = downloader_path

            #Output file path
            if TOOLCHAIN == "IAR":
                PAC_PTAH       = os.path.join(os.getcwd(), "iar", "iar_v850", PROJECT)
            elif TOOLCHAIN == "GCC":
                PAC_PTAH       = os.path.join(os.getcwd(), "build", PROJECT)       
            elif TOOLCHAIN == "GHS":
                PAC_PTAH       = os.path.join(os.getcwd(), "ghs", "%s_sf" %(PROJECT))                   

        try:
            gen_pac(BOARD, PROJECT, json_cfg, downloader, None)
        except Exception as e:
            print("gen_pac error:\n    %s" % e)
            sys.exit(-1)
    else:
        #N_xip project
        print("It is a Cascade Project")
        if(XIP == False):
            if PAC_CONFIG_FILE_NAME == "none":
                print ("Must select a pac config file, eg: -f devices\E3640\pac_config_sf.json")
                sys.exit(-1)

            pac_json = PAC_CONFIG_FILE_NAME
            if os.path.exists(pac_json) == False:
                print ("pac config file %s not exist." % pac_json)
                sys.exit(-1)

            #Project
            if TOOLCHAIN == "IAR":
                CASCADE_PROJECT_PATH.append("%s_cascade_mst"%str(CASCADE_PROJECT[0]))

                project_path = os.path.join(os.getcwd(), "iar", "iar_v850", CASCADE_PROJECT_PATH[0], CONFIG_NAME, "Exe", "%s.bin" % (CASCADE_PROJECT_PATH[0]))
                if os.path.exists(project_path) == False:
                    print ("Fail to find the bin.")
                    sys.exit(-1)
                else:
                    PROJECT_PATH = os.path.abspath(project_path)
            elif TOOLCHAIN == "GCC":
                CASCADE_PROJECT_PATH.append("%s_cascade_mst"%str(CASCADE_PROJECT[0]))

                project_path = os.path.join(os.getcwd(), "build", CASCADE_PROJECT_PATH[0], "%s_sf_mcal_testsuite.elf.bin" % (CASCADE_PROJECT_PATH[0]))
                if os.path.exists(project_path) == False:
                    print ("Fail to find the bin.")
                    sys.exit(-1)
                else:
                    PROJECT_PATH = os.path.abspath(project_path)            

            if CASCADE_PROJECT_PATH[0] == "":
                print ("can not find the cascade project path")
                sys.exit(-1)

            print("gen pac for board=%s, project=%s toolchain=%s Mst_project_path =%s" % (CASCADE_BOARD[0] + "&&" + CASCADE_BOARD[1], CASCADE_PROJECT[0] + "&&" + CASCADE_PROJECT[1], TOOLCHAIN, project_path))
            
            if os.path.exists(os.path.join(PROJECT_PATH)) == True:
                if TOOLCHAIN == "IAR":
                    mcal_bin_file  = os.path.join(PROJECT_PATH)
                elif TOOLCHAIN == "GCC":
                    mcal_bin_file  = os.path.join(PROJECT_PATH)

            # Copy binaries to bin dir
            for bin in glob.glob(mcal_bin_file):
                try_copy(bin, os.path.join(BIN_PATH, "%s.bin" % (CASCADE_PROJECT[0])))
                print("\ncopy %s file to %s." %(bin, BIN_PATH))

            print("Generate PAC according to %s" % pac_json)
            try:
                f = open(pac_json)
            except:
                raise("Can not find %s" % pac_json)
            json_cfg = json.load(f)
            description = json_cfg.get("description", "e3 pac json file")
            print("description is " + description)
            if TOOLCHAIN == "IAR":
                PAC_PTAH       = os.path.join(os.getcwd(), "iar", "iar_v850", CASCADE_PROJECT_PATH[0])
            elif TOOLCHAIN == "GCC":
                PAC_PTAH       = os.path.join(os.getcwd(), "build", CASCADE_PROJECT_PATH[0])

        else:
            print("Generate PAC according to %s" % PAC_CONFIG_FILE_NAME)
            if "bootload_path" in json_cfg:
                bootload_path = json_cfg.get("bootload_path")
                try_copy(bootload_path, os.path.join(BIN_PATH, "%s_bootloader.bin" %(CASCADE_PROJECT[0])))
                print("bootload file is %s" % bootload_path)
            else:
                print("must have a sf file:\n    %s")
                sys.exit(-1)

            if "downloader_path" in json_cfg:
                downloader_path = json_cfg.get("downloader_path")
                try_copy(downloader_path, os.path.join(BIN_PATH, "dloader_%s.bin" %(CASCADE_BOARD[0])))
                print("downloader file is %s" % downloader_path)
                downloader = downloader_path

            #Output file path
            if TOOLCHAIN == "IAR":
                PAC_PTAH       = os.path.join(os.getcwd(), "iar", "iar_v850", CASCADE_PROJECT[0] + "_cascade_mst_xip")
            elif TOOLCHAIN == "GCC":
                PAC_PTAH       = os.path.join(os.getcwd(), "build", CASCADE_PROJECT[0] + "_cascade_mst")       

        try:
            gen_pac(CASCADE_BOARD[0], str(CASCADE_PROJECT[0]), json_cfg, downloader, str(CASCADE_PROJECT[1]))
        except Exception as e:
            print("gen_pac error:\n    %s" % e)
            sys.exit(-1)        
