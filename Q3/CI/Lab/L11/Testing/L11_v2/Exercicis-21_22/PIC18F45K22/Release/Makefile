###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = PIC18F45K22
COMPILER = "MPLAB XC8"
TARGET = Release
SHELL = C:\Windows\system32\cmd.exe

## Tools general options
CCFLAGS=--pass1 --errformat="Error at file %%f line %%l column %%c: (%%n) %%s" --warnformat="Warning at file %%f line %%l column %%c: (%%n) %%s" --msgformat="Message at file %%f line %%l column %%c: (%%n) %%s" --chip=18F45K22
LDFLAGS=--output=intel --chip=18F45K22

## Processing Tools
CC=xc8.exe
ASM=xc8.exe
LD=xc8.exe
LIB=xc8.exe
#  C:/Users/alvar/Desktop/GLCDK22/PIC18F45K22/Release/Release.hex: TOOL=LD
#  Post: rm startup.as
#  Post: rm Release.as
#     C:/Users/alvar/Desktop/GLCDK22/PIC18F45K22/Release/main.p1: TOOL=CC
#        C:/Users/alvar/Desktop/GLCDK22/PIC18F45K22/main.c
#     C:/Users/alvar/Desktop/GLCDK22/PIC18F45K22/Release/RUTINE~1.p1: TOOL=CC
#        C:/Users/alvar/Desktop/GLCDK22/PIC18F45K22/rutines_GLCD.c

# Build tree:
all:	Release

Release:	Release.hex
	cp "Release.hex" "C:/Users/alvar/Desktop/GLCDK22/PIC18F45K22.hex"

Release.hex:	main.p1 RUTINE~1.p1 
	$(LD) $(LDFLAGS)  -O"Release.hex" "main.p1" "RUTINE~1.p1"
	rm startup.as
	rm Release.as

main.p1:	../main.c 
	$(CC) $(CCFLAGS)  -O"main.p1" "../main.c"

RUTINE~1.p1:	../rutines_GLCD.c 
	$(CC) $(CCFLAGS)  -O"RUTINE~1.p1" "../rutines_GLCD.c"

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Release.hxl
	rm -rf Release.lst
	rm -rf Release.sym
	rm -rf Release.obj
	rm -rf Release.sdb
	rm -rf Release.as
	rm -rf ./startup.obj
	rm -rf ./startup.rlf
	rm -rf ./startup.as
	rm -rf ./startup.lst
	rm -rf ./funclist.
	rm -rf main.pre
	rm -rf main.lst
	rm -rf RUTINE~1.pre
	rm -rf RUTINE~1.lst

# cleanup - delete all generated files
clean:	tidy
	rm -rf Release.hex
	rm -rf main.p1
	rm -rf RUTINE~1.p1
