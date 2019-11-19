#---------------------------------------------------------------------------------
# Lameguy's general-purpose makefile for PSX development
# (for official PlayStation SDK)
# 2017 Meido-Tek Productions
#
# Use mingw32-make (included with MinGW GCC compiler) to run this makefile. You may
# also need to setup msys and assign it to your PATH environment to get the clean
# and cleanall rules to work as make cannot execute del and rm is used instead.
#
# Download msys here:
# https:
#
# NOTE: Do not use msys' make program! Its bugged in Win9x and may delete your souce
# files when you clean and some programs such as asmpsx cannot read the arguments
# when run by it.
#
# For ISO build to work, you will need mkpsxiso and Orion's Win32 version of cpe2x.
# mkpsxiso: https:
# cpe2x: http:
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
# TARGET	- Name of the output
# PROGADDR	- Program load address (0x80010000 is the default)
# SOURCES	- Source directories (. for current directory)
# INCLUDES	- Include search directories
# ISOXML	- Name of mkpsxiso ISO project script
#---------------------------------------------------------------------------------
TARGET      = MAIN
PROGADDR	= 0x00010000
SOURCES		= GAME/PSX/
INCLUDES	= GAME/
DISC_ROOTFD	= DISC/

#---------------------------------------------------------------------------------
# LIBDIRS	- Library search directories
# LIBS		- Libraries to link during linking stage
#---------------------------------------------------------------------------------
LIBDIRS		=
LIBS		= LIBETC.LIB LIBPAD.LIB LIBGTE.LIB LIBMCRD.LIB LIBCD.LIB LIBSN.LIB LIBSPU.LIB LIBAPI.LIB

#---------------------------------------------------------------------------------
# CFLAGS	- Base C compiler options
# AFLAGS	- Base assembler options
#---------------------------------------------------------------------------------
CFLAGS		= -Xm -g -w -O2
AFLAGS		= /g /l /zd /oat+,w-,c+ /q

#---------------------------------------------------------------------------------
## CC		- C compiler (usually ccpsx)
## AS		- Assembler (usually asmpsx)
#---------------------------------------------------------------------------------
CC			= ccpsx
AS			= asmpsx

#---------------------------------------------------------------------------------
# Parse source directories for source files
#---------------------------------------------------------------------------------
#CFILES		= $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.C))
CFILES		= D:\Proyectos\KainSoul\KAIN2\GAME\PSX\MAIN.C
AFILES		= $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.MIP))

#---------------------------------------------------------------------------------
# Generate file names for object binaries
#---------------------------------------------------------------------------------
OFILES		= $(AFILES:.MIP=.obj) $(CFILES:.C=.obj) $(RFILES:.C=.obj)

#---------------------------------------------------------------------------------
# Default rule, compiles all source files
#---------------------------------------------------------------------------------
all: $(OFILES)
	$(CC) -Xo$(PROGADDR) $(CFLAGS) $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIBS)) $(OFILES)
#---------------------------------------------------------------------------------
# Clean-up rule
#---------------------------------------------------------------------------------
clean: cleanall

#---------------------------------------------------------------------------------
# ISO build rule (requires MKPSXISO)
#---------------------------------------------------------------------------------
iso:
	cpe2x $(DISC_ROOTFD)$(TARGET).CPE
	cd DISC
	mkpsxisox.exe $(ISOXML)

#---------------------------------------------------------------------------------
# Rule for compiling C source
#---------------------------------------------------------------------------------
%.obj: %.C
	$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -c $< -o $@

#---------------------------------------------------------------------------------
# Rule for assembling assembly source
#---------------------------------------------------------------------------------
%.obj: %.MIP
	$(AS) $(AFLAGS) $<,$@