
#POWERPCTG := 1


#=========================================
#设置交叉编译器
#=========================================
ifeq ($(POWERPCTG), 1)
ARCH := powerpc
#CROSS_COMPILE := /home/ygliu/WindRiver/wrlinux-4/sysroots/fsl_p1020_p1011-glibc_std/x86-linux2/powerpc-wrs-linux-gnu-ppc_e500v2-glibc_std-
CROSS_COMPILE := /home/ygliu/WindRiver/wrlinux-4/sysroots/fsl_p2020-glibc_cgl/x86-linux2/ppc_e500v2-target-linux-gnu-
else
ARCH := i386
CROSS_COMPILE :=
endif

CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)g++
LD := $(CROSS_COMPILE)ld
AS := $(CROSS_COMPILE)as
AR := $(CROSS_COMPILE)ar
MAKE := make
RM	 := rm
MV	:= mv


#=========================================
#定义模块路径
#=========================================
top_dir := $(shell pwd)
BFD_PATH := ../src/appl
BFD_OUTPUT_PATH := $(top_dir)/../output
BFD_LIB_PATH := $(shell pwd)/../lib
BFD_OBJ_PATH := $(top_dir)/../obj

#=========================================
#定义需编译的C文件
#=========================================
BFD_SRC := $(wildcard $(BFD_PATH)/*.c)

CFLAGS += -g -O0 -Wall -pipe -fPIC
CXXFLAGS += -g -O0 -Wall -pipe -fPIC

#=========================================
#额外宏定义
#=========================================
DEFINE := -D USING_LINUX_OS

ifeq ($(POWERPCTG), 1)
DEFINE += -D BFD_BIG_ENDIAN
else
DEFINE += -D X86_UINT_TEST
DEFINE += -D BFD_LITTLE_ENDIAN
ifeq ($(USEBMULIB), 1)
DEFINE += -D USE_BMU_LIB
endif
endif

CFLAGS += $(DEFINE)
CXXFLAGS += $(DEFINE)

#=========================================
#头文件搜索路径  linux_bmulib
#=========================================
INCLUDE := -I $(top_dir)/../src/inc/arad\
		   -I $(top_dir)/../src/inc/bfd\
		   -I $(top_dir)/../src/inc/bmulib\
		   -I $(top_dir)/../src/inc/NBB\
		   -I $(top_dir)/../src/inc/tp_oam
								
CFLAGS += $(INCLUDE)
CXXFLAGS += $(INCLUDE)

#CFLAGS += -g -O0 -Wall -pipe -fPIC
#CXXFLAGS += -g -O0 -Wall -pipe -fPIC

#=========================================
#动态库
#=========================================
ifeq ($(POWERPCTG), 1)
SHARED := -shared
else
SHARED :=
endif

#=========================================
#链接的库
#=========================================
LIB := 
ifeq ($(POWERPCTG), 1)
else
	ifeq ($(USEBMULIB), 1)
		LIB += -L $(BFD_LIB_PATH) -lbmu
		LIB += -ldl -lrt -lutil
	else
		LIB += -lrt
	endif
endif

#=========================================
#最终生成目标
#=========================================
ifeq ($(POWERPCTG), 1)
BFD_TARGET_NAME := libbfd.so
BFD_OUTPUT_NAME := libtp_oam.so
else
BFD_TARGET_NAME := bfd.out
BFD_OUTPUT_NAME := $(BFD_TARGET_NAME)
endif

bfd_target := $(BFD_PATH)/$(BFD_TARGET_NAME)
bfd_output := $(BFD_OUTPUT_PATH)/$(BFD_OUTPUT_NAME)

#=========================================
#中间目标
#=========================================
bfd_obj_name := $(patsubst %.c, %.o, $(notdir $(BFD_SRC)))
bfd_obj := $(addprefix $(BFD_OBJ_PATH)/,$(bfd_obj_name))

#=========================================
# 定义生成的目标
#=========================================
Q := @
exes := $(bfd_target)

#=========================================
# 定义执行顺序目标
#=========================================
poly_exes := starttip
poly_exes += $(exes)
poly_exes += mvtip
poly_exes += endtip

.PHONY : all
all : $(poly_exes)

starttip :
	$(Q)echo ++++++++++++++++++++++++++++ start of making ++++++++++++++++++++++++++++

mvtip :
	$(MV) $(bfd_target) $(bfd_output)

endtip :
	$(Q)echo ++++++++++++++++++++++++++++ end of making  ++++++++++++++++++++++++++++

$(bfd_target) :  $(bfd_obj)
	$(CC) $(CFLAGS) $(SHARED) -rdynamic -Wl,-rpath=./ $^ -o $@ $(LIB)

$(bfd_obj) : $(BFD_OBJ_PATH)/%.o:$(BFD_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
#=========================================
#设置 make clean
#=========================================
clean_path := $(BFD_OBJ_PATH) $(BFD_OUTPUT_PATH)
				
.PHONY : clean
clean:
	$(RM) -rf `find $(clean_path) -name "*.o"`
	$(RM) -rf `find $(clean_path) -name "*.so"`
	$(RM) -rf `find $(clean_path) -name "*.out"`
	
	
