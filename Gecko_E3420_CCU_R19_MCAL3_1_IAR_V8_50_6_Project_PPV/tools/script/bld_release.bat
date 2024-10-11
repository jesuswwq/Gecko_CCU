@echo off

::get the parent folder
set cur_path=%cd%
for %%a in ("%cur_path%") do set "root_dir=%%~dpa"

set PATH=%root_dir%\MCAL_Tools\toolchains\msys\usr\bin;%root_dir%\MCAL_Tools\toolchains\gcc-arm-none-eabi\bin;

if "%1"=="help" SET flag=T
if "%1"=="" SET flag=T

if "%flag%"=="T" (
    echo "Usage: bld.bat [board]"
    echo "      <board>  the target board  eg:E3_z1/E3_evb/E3_ref_gateway/E3_ref_motor/E3_ref_176/E3_ref_144"
    echo "      <core>   the target core, sf core is must"
    echo "                    eg:sf/sp/sp0/sp1/sx/sx0/sx"
    exit
)

if "%1" == "clean_all" (
    make clean_all
) else (
    for %%I in (%*) do (
        if "%%I" == "sf" (
            make clean
            make CFG=%1 D=1 TARGET_CORE=sf WINDOWS=1 bin -j4
        )

        if "%%I" == "sx" (
            make clean
            make CFG=%1 D=1 TARGET_CORE=sx WINDOWS=1 bin -j4
        )

        if "%%I" == "sx0" (
            make clean
            make CFG=%1 D=1 TARGET_CORE=sx0 WINDOWS=1 bin -j4
        )

        if "%%I" == "sx1" (
            make clean
            make CFG=%1 D=1 TARGET_CORE=sx1 WINDOWS=1 bin -j4
        )

        if "%%I" == "sp" (
            make clean
            make CFG=%1 D=1 TARGET_CORE=sp WINDOWS=1 bin -j4
        )

        if "%%I" == "sp0" (
            make clean
            make CFG=%1 D=1 TARGET_CORE=sp0 WINDOWS=1 bin -j4
        )

        if "%%I" == "sp1" (
            make clean
            make CFG=%1 D=1 TARGET_CORE=sp1 WINDOWS=1 bin -j4
        )
    )
)
