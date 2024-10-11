@echo off

::get the path of bat: bat_dir
set bat_dir=%~dp0
cd /d %bat_dir%

::get the path of mcal based on bat_dir: Path_copy_source
cd ../../.. && cd /d .\mcal
set Path_copy_source=%cd%
echo %Path_copy_source%

::get the path of plugins based on bat_dir: Path_copy_destin
cd ../.. && cd /d .\MCAL_Tools\EB\plugins
set Path_copy_destin=%cd%
echo %Path_copy_destin%

::set all file names and folder names under MCAL to file_ list
set file_list=Adc Aos Base Can CanIf CanTrcv Crypto ^
Det Dio Eth EthIf EthSwt EthTrcv Fls FuncSafetyPkg Gpt I2c ^
Icu IOExp IrqM Lib Lin Mailbox Makefile mcal.mk ^
Mcu Port Pwm RebootService ResM Rte SDPE Sent Spi Wdg Xtrg

::delete the corresponding file before copying
for %%i in (%file_list%) do if exist %%i (rd /s /q %%i)
xcopy %Path_copy_source% %Path_copy_destin% /sey

::switch back bat_dir
cd /d %bat_dir%

::get the path of each project based on bat_dir
cd ../../.. && cd /d .\Mcal_Cfg
set Path_E3_ref_gateway_E3640=%cd%\E3_ref_gateway_E3640
set Path_E3_ref_gateway_E3648=%cd%\E3_ref_gateway_E3648
set Path_E3_ref_gateway_E3430=%cd%\E3_ref_gateway_E3430
set Path_E3_ref_gateway_E3420=%cd%\E3_ref_gateway_E3420
set Path_E3_ref_176_E3210=%cd%\E3_ref_176_E3210
set Path_E3_ref_176_E3110=%cd%\E3_ref_176_E3110
set Path_bga324_dev_kit=%cd%\bga324_dev_kit
set Path_E3_ref_motor=%cd%\E3_ref_motor
set Path_E3_ref_144_lite_E3205=%cd%\E3_ref_144_lite_E3205
set Path_E3_ref_176_lite_E3104=%cd%\E3_ref_176_lite_E3104
set Path_E3_ref_176_lite_E3106=%cd%\E3_ref_176_lite_E3106
set Path_E3_ref_176_lite_E3206=%cd%\E3_ref_176_lite_E3206
set Path_E3_ref_144_lite_E3205_crypto=%cd%\E3_ref_144_lite_E3205_crypto
set Path_E3_ref_176_lite_E3104_crypto=%cd%\E3_ref_176_lite_E3104_crypto
set Path_E3_ref_176_lite_E3106_crypto=%cd%\E3_ref_176_lite_E3106_crypto
set Path_E3_ref_176_lite_E3206_crypto=%cd%\E3_ref_176_lite_E3206_crypto

::switch back bat_dir
cd /d %bat_dir%

::switch to the path of tresos_cmd.bat
cd ../../../.. && cd /d .\MCAL_Tools\EB\bin

::import project
for %%b in (%Path_E3_ref_gateway_E3640% %Path_E3_ref_gateway_E3648% %Path_E3_ref_gateway_E3430% %Path_E3_ref_gateway_E3420% %Path_E3_ref_176_E3210% %Path_E3_ref_176_E3110% %Path_bga324_dev_kit%  %Path_E3_ref_motor% %Path_E3_ref_144_lite_E3205% %Path_E3_ref_176_lite_E3104% %Path_E3_ref_176_lite_E3106% %Path_E3_ref_176_lite_E3206% %Path_E3_ref_144_lite_E3205_crypto% %Path_E3_ref_176_lite_E3104_crypto% %Path_E3_ref_176_lite_E3106_crypto% %Path_E3_ref_176_lite_E3206_crypto%) do (call tresos_cmd.bat importProject -c %%b)

::generate project
for %%c in (E3_ref_gateway_E3640,E3_ref_gateway_E3648,E3_ref_gateway_E3430,E3_ref_gateway_E3420,E3_ref_176_E3210,E3_ref_176_E3110,bga324_dev_kit,E3_ref_motor,E3_ref_144_lite_E3205,E3_ref_176_lite_E3104,E3_ref_176_lite_E3106,E3_ref_176_lite_E3206,E3_ref_144_lite_E3205_crypto,E3_ref_176_lite_E3104_crypto,E3_ref_176_lite_E3106_crypto,E3_ref_176_lite_E3206_crypto) do (call tresos_cmd.bat generate %%c)
