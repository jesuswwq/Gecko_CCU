@echo off & color 0A
set DIR=%~dp0
set targetdir=%DIR%..\
echo DIR=%DIR%
echo "%targetdir%"

setlocal ENABLEDELAYEDEXPANSION
for %%f in (!targetdir!..) do set par=%%~ff
for %%f in (!targetdir!) do set tar=%%~ff
echo par=%par%
echo tar=%tar%
set work=!DIR:%tar%=!
echo %work%
for /R "%targetdir%" %%f in (*.h) do (
	set rslt=%%f
	set rslt_t=!rslt:%tar%=!
	if	"!rslt_t:%work%=!" == "!rslt_t!" (
		set add=#include "..!rslt:%par%=!"
		set out=!out!!add!
		echo !add!
		)
	)
pause
