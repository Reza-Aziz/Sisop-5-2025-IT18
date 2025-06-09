AS = nasm
CC = gcc
LD = ld
CFLAGS = -ffreestanding -m32 -nostdlib -fno-pie -fno-stack-protector
LDFLAGS = -m elf_i386 -T linker.ld

SRC = src
BUILD = build
BIN = bin

BOOT = $(SRC)/bootloader.asm
KERNEL = $(SRC)/kernel.c
SHELL = $(SRC)/shell.c
STDLIB = $(SRC)/std_lib.c

OBJS = $(BUILD)/bootloader.o $(BUILD)/kernel.o $(BUILD)/shell.o $(BUILD)/std_lib.o

ISO = $(BIN)/system.iso
BINFILE = $(BIN)/kernel.bin

prepare:
	mkdir -p $(BUILD)
	mkdir -p $(BIN)

bootloader:
	$(AS) -f bin $(BOOT) -o $(BIN)/bootloader.bin

stdlib:
	$(CC) $(CFLAGS) -c $(STDLIB) -o $(BUILD)/std_lib.o

shell:
	$(CC) $(CFLAGS) -c $(SHELL) -o $(BUILD)/shell.o

kernel:
	$(CC) $(CFLAGS) -c $(KERNEL) -o $(BUILD)/kernel.o

link:
	$(LD) $(LDFLAGS) -o $(BINFILE) $(OBJS)

build: prepare bootloader stdlib shell kernel link
	cat $(BIN)/bootloader.bin $(BINFILE) > $(BIN)/system.img
	truncate -s 1474560 $(BIN)/system.img
	mkisofs -o $(ISO) -b system.img -no-emul-boot -boot-load-size 4 -boot-info-table $(BIN)

run: build
	bochs -f bochsrc.txt

clean:
	rm -rf $(BUILD) $(BIN)
