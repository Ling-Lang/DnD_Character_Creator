.PHONY: all clean debug

PROJECT_SOURCE_FILES ?= src/main.c \
						src/window_startup.c \
						src/startup_window.c \

PROJECT_NAME 		?= dnd_character_creator
PROJECT_VERSION 	?= 0.1
PROJECT_BUILD_PATH 	?= .

RAYLIB_PATH 		?= ./src/lib
RAYLIB_INCLUDE_PATH ?= $(RAYLIB_PATH)
RAYLIB_LIB_PATH		?= ./src/lib/

PLATFORM=			?= PLATFORM_DESKTOP

ifeq ($PLATFORM),PLATFORM_DESKTOP)
	ifeq ($(OS), Windows_NT)
		PLATFORM_OS=Windows
	else
		UNAMEOS=$(shell uname)
		ifeq ($(UNAMEOS), Linux)
			PLATFORM_OS=Linux
			$(EXT) = .out
		endif
		ifeq ($(UNAMEOS), Darwin)
			PLATFORM_OS=OSX
		endif
	endif
endif

CC = gcc

ifeq ($(PLATFORM), PLATFORM_DESKTOP)
	ifeq ($(PLATFORM_OS), OSX)
		cc = clang
	endif
endif

MAKE ?= make

# Define compiler flags:
# -O1					defines optimization level
# -g					include debug information 
# -s					strip unnecessary data from build
# -Wall					turns on most, but not all, compiler warnings
# -std=c99				defines C language mode (stadnard C from 1999 revision)
# -Wno-missing-braces	ignore invalid warning (GCC bug 53119)
# -Wno-unused-value		ignore unused return value of some functions
CFLAGS = -Wall -std=c99 -Wno-missing-braces -Wno-unused-value

# only use for debug mode becuase uses more space i think
ifeq ($(BUILD_MODE), DEBUG)
	CFLAGS += -g
endif

# Define include paths for required headers
INCLUDE_PATHS += -I ./src/include 

# define Library paths containing all libraries
LDLFLAGS = -L. -L $(RAYLIB_LIB_PATH) -lraylib -lm


# Define any libraries required for building
# for further libraries (libname.so or libname.a), use -lname

ifeq ($(PLATFORM), PLATFORM_DESKTOP)
	ifeq ($(OS), Windows_NT)
		# Libraries for Windows Desktop
		LDLIBS = -lopengl32 -lgdi32 -lwinmm -lopengl32
		# LDLIBS += -static -lpthread
	endif
	ifeq ($(PLATFORM_OS), Linux)
		LDLIBS = -lGL -lm -lpthread -ldl -lrt -lX11
	endif
	# For those mac users
	ifeq ($(PLATFOMR_OS), OSX)
		LDLIBS = -framework OpenGL -framework COcoa -framework IOKit -framework CoreAudio -framework CoreVideo
	endif
endif


########################################################################
####################### Real Makefile ##################################
########################################################################

# Define all source files 


#Define all object files from source files
OBJS = $(patsubst %.c, %.o, $(PROJECT_SOURCE_FILES))

# Default target entry 

all: 
	$(MAKE) $(PROJECT_NAME)

# Project targed defined by PROJECT_NAME
$(PROJECT_NAME): $(OBJS)
	$(CC) -o $(PROJECT_BUILD_PATH)/$(PROJECT_NAME)$(EXT) $(OBJS) $(CFLAGS) $(INCLUDE_PATHS) $(LDLFLAGS)  $(LDLIBS) -D$(PLATFORM) 

# Compile source files
# NOTE: This pattern will compile every module defined on $(OBJS)
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_PATHS) -D$(PLATFORM)

clean:
ifeq ($(OS), Windows_NT)
	del src\*.o
	del $(PROJECT_NAME).exe
endif
ifeq ($(PLATFORM_OS), Linux)
	rm src/*.o
	rm $(PROJECT_NAME)
endif
ifeq ($(PLATFORM_OS), OSX)
	rm src/*.o
	rm $(PROJECT_NAME)
endif

re: clean all

help:
	@echo Default platform is DESKTOP to compile normally type
	@echo make PLATFORM=DESKTOP
	@echo Rules are the following
	@echo all
	@echo clean not implemented yet due to technical difficulties
	@echo re same as above