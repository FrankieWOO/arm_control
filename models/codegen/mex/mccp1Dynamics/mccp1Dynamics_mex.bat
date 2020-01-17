@echo off
set MATLAB=D:\MATLAB\R2017a
set MATLAB_ARCH=win64
set MATLAB_BIN="D:\MATLAB\R2017a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=mccp1Dynamics_mex
set MEX_NAME=mccp1Dynamics_mex
set MEX_EXT=.mexw64
call "D:\MATLAB\R2017a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for mccp1Dynamics > mccp1Dynamics_mex.mki
echo COMPILER=%COMPILER%>> mccp1Dynamics_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> mccp1Dynamics_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> mccp1Dynamics_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> mccp1Dynamics_mex.mki
echo LINKER=%LINKER%>> mccp1Dynamics_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> mccp1Dynamics_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> mccp1Dynamics_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> mccp1Dynamics_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> mccp1Dynamics_mex.mki
echo BORLAND=%BORLAND%>> mccp1Dynamics_mex.mki
echo OMPFLAGS= >> mccp1Dynamics_mex.mki
echo OMPLINKFLAGS= >> mccp1Dynamics_mex.mki
echo EMC_COMPILER=lcc64>> mccp1Dynamics_mex.mki
echo EMC_CONFIG=optim>> mccp1Dynamics_mex.mki
"D:\MATLAB\R2017a\bin\win64\gmake" -B -f mccp1Dynamics_mex.mk
