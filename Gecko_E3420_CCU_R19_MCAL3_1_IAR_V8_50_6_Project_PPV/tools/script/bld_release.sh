#!/bin/bash
export compiler=$(which arm-none-eabi-gcc)

### get version code
MAJOR=$(echo __GNUC__ | $compiler -E -xc - | tail -n 1)
MINOR=$(echo __GNUC_MINOR__ | $compiler -E -xc - | tail -n 1)
PATCHLEVEL=$(echo __GNUC_PATCHLEVEL__ | $compiler -E -xc - | tail -n 1)

if [ "$MAJOR" == "10" ]; then
    analyzer=true
fi

SIGN_CMD=tools/sign_tool_e3/atb_signer/build/atb_signer
#ATB_PACKER=${ATB_TOOLS}/atb_signer/build/atb_signer
IMG_DIR=build/E3_z1

if [ "$1" = "" -o "$1" = "help" ]; then
    echo "Usage: $0 [board]"
    echo "      board:  the board to be built, the valid options are as followed"
    echo "          E3_ref_gateway_E3648/E3_ref_gateway_E3640/E3_ref_gateway_E3430/E3_ref_gateway_E3420/E3_ref_motor/E3_ref_176_E3210/E3_ref_E3110"
    exit 0
fi

time1=$(date +%s)

if [ "$1" = "E3_ref_176_E3210" -o "$1" = "E3_ref_176_E3110" ]; then
    make clean
    make CFG=$1 D=1 TARGET_CORE=sf SOC=taishan bin -j4 ANALYZER=$analyzer
    if [ $? -ne 0 ]; then
        echo "$0: Opps, fail to build ${TARGET_CORE}!"
        exit 1
    fi
elif [ "$1" = "E3_ref_176_lite_E3106" -o "$1" = "E3_ref_176_lite_E3104" -o "$1" = "E3_ref_144_lite_E3205"  -o "$1" = "E3_ref_176_lite_E3206" \
       -o "$1" = "E3_ref_176_lite_E3106_crypto" -o "$1" = "E3_ref_176_lite_E3104_crypto" -o "$1" = "E3_ref_144_lite_E3205_crypto"  \
       -o "$1" = "E3_ref_176_lite_E3206_crypto" -o "$1" = "E3_evb_176_lite" ]; then
    make clean
    make CFG=$1 D=1 TARGET_CORE=sf SOC=taishan_l bin -j4
    if [ $? -ne 0 ]; then
        echo "$0: Opps, fail to build ${TARGET_CORE}!"
        exit 1
    fi
else
for i in "$@"; do
    if [ $i = "sf" ]; then
        make clean
        make CFG=$1 D=1 TARGET_CORE=sf SOC=taishan bin -j4 ANALYZER=$analyzer
        if [ $? -ne 0 ]; then
            echo "$0: Opps, fail to build ${TARGET_CORE}!"
            exit 1
        fi
    fi
    if [ $i = "sp0" ]; then
        make clean
        make CFG=$1 D=1 TARGET_CORE=sp0 SOC=taishan bin -j4 ANALYZER=$analyzer
        if [ $? -ne 0 ]; then
            echo "$0: Opps, fail to build ${TARGET_CORE}!"
            exit 1
        fi
    fi
    if [ $i = "sp1" ]; then
        make clean
        make CFG=$1 D=1 TARGET_CORE=sp1 SOC=taishan bin -j4 ANALYZER=$analyzer
        if [ $? -ne 0 ]; then
            echo "$0: Opps, fail to build ${TARGET_CORE}!"
            exit 1
        fi
    fi
    if [ $i = "sx0" ]; then
        make clean
        make CFG=$1 D=1 TARGET_CORE=sx0 SOC=taishan bin -j4 ANALYZER=$analyzer
        if [ $? -ne 0 ]; then
            echo "$0: Opps, fail to build ${TARGET_CORE}!"
            exit 1
        fi
    fi
    if [ $i = "sx1" ]; then
        make clean
        make CFG=$1 D=1 TARGET_CORE=sx1 SOC=taishan bin -j4 ANALYZER=$analyzer
        if [ $? -ne 0 ]; then
            echo "$0: Opps, fail to build ${TARGET_CORE}!"
            exit 1
        fi
    fi
    if [ $i = "sx" ]; then
        make clean
        make CFG=$1 D=1 TARGET_CORE=sx SOC=taishan bin -j4 ANALYZER=$analyzer
        if [ $? -ne 0 ]; then
            echo "$0: Opps, fail to build ${TARGET_CORE}!"
            exit 1
        fi
    fi
    if [ $i = "sp" ]; then
        make clean
        make CFG=$1 D=1 TARGET_CORE=sp SOC=taishan bin -j4 ANALYZER=$analyzer
        if [ $? -ne 0 ]; then
            echo "$0: Opps, fail to build ${TARGET_CORE}!"
            exit 1
        fi
    fi
done
fi

time2=$(date +%s)
time2=`expr $time2 - $time1`
echo "total build time:" $time2 's'