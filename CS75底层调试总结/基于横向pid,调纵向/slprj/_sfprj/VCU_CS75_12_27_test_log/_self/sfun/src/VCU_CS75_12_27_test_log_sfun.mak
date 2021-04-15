# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64
!include <ntwin32.mak>

MACHINE     = VCU_CS75_12_27_test_log
TARGET      = sfun
CHART_SRCS   = c1_VCU_CS75_12_27_test_log.c c2_VCU_CS75_12_27_test_log.c c3_VCU_CS75_12_27_test_log.c c4_VCU_CS75_12_27_test_log.c c6_VCU_CS75_12_27_test_log.c c7_VCU_CS75_12_27_test_log.c c8_VCU_CS75_12_27_test_log.c c9_VCU_CS75_12_27_test_log.c c10_VCU_CS75_12_27_test_log.c c11_VCU_CS75_12_27_test_log.c c12_VCU_CS75_12_27_test_log.c c13_VCU_CS75_12_27_test_log.c c14_VCU_CS75_12_27_test_log.c c16_VCU_CS75_12_27_test_log.c c17_VCU_CS75_12_27_test_log.c c18_VCU_CS75_12_27_test_log.c c19_VCU_CS75_12_27_test_log.c c20_VCU_CS75_12_27_test_log.c c26_VCU_CS75_12_27_test_log.c c27_VCU_CS75_12_27_test_log.c c28_VCU_CS75_12_27_test_log.c c29_VCU_CS75_12_27_test_log.c c30_VCU_CS75_12_27_test_log.c c31_VCU_CS75_12_27_test_log.c
MACHINE_SRC  = VCU_CS75_12_27_test_log_sfun.c
MACHINE_REG = VCU_CS75_12_27_test_log_sfun_registry.c
MAKEFILE    = VCU_CS75_12_27_test_log_sfun.mak
MATLAB_ROOT  = D:\matlab
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "D:\matlab\extern\include" \
    /I "D:\matlab\simulink\include" \
    /I "D:\matlab\stateflow\c\mex\include" \
    /I "D:\matlab\rtw\c\src" \
    /I "D:\项目实验室\长安CS75plus\CS75底层调试总结\基于横向pid,调纵向\slprj\_sfprj\VCU_CS75_12_27_test_log\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = VCU_CS75_12_27_test_log_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = 
BLAS_LIBS = "D:\matlab\extern\lib\win64\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "D:\matlab\extern\lib\win64\microsoft\sf_runtime.lib" "D:\matlab\extern\lib\win64\microsoft\libmx.lib" "D:\matlab\extern\lib\win64\microsoft\libmex.lib" "D:\matlab\extern\lib\win64\microsoft\libmat.lib" "D:\matlab\extern\lib\win64\microsoft\libfixedpoint.lib" "D:\matlab\extern\lib\win64\microsoft\libut.lib" "D:\matlab\extern\lib\win64\microsoft\libmwmathutil.lib" "D:\matlab\extern\lib\win64\microsoft\libemlrt.lib" "D:\matlab\extern\lib\win64\microsoft\libmwsl_log_load_blocks.lib" "D:\matlab\lib\win64\libippmwipt.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


