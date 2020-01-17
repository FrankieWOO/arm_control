@echo off
set MATLAB=D:\MATLAB\R2017a
set MATLAB_ARCH=win64
set MATLAB_BIN="D:\MATLAB\R2017a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=mccp1TauA_mex
set MEX_NAME=mccp1TauA_mex
set MEX_EXT=.mexw64
call "D:\MATLAB\R2017a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for mccp1TauA > mccp1TauA_mex.mki
echo COMPILER=%COMPILER%>> mccp1TauA_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> mccp1TauA_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> mccp1TauA_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> mccp1TauA_mex.mki
echo LINKER=%LINKER%>> mccp1TauA_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> mccp1TauA_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> mccp1TauA_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> mccp1TauA_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> mccp1TauA_mex.mki
echo BORLAND=%BORLAND%>> mccp1TauA_mex.mki
echo OMPFLAGS= >> mccp1TauA_mex.mki
echo OMPLINKFLAGS= >> mccp1TauA_mex.mki
echo EMC_COMPILER=lcc64>> mccp1TauA_mex.mki
echo EMC_CONFIG=optim>> mccp1TauA_mex.mki
"D:\MATLAB\R2017a\bin\win64\gmake" -B -f mccp1TauA_mex.mk
