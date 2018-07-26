TARGET=start.S
C_SOURCES=start.S system.h
ASM_SOURCES=start.S
ASM_OUTPUT=$(TARGET).S
OBJ_FILES=start.o $(ASM_SOURCES:.S=.o) $(C_SOURCES:.c=.o)
SIMDIR=../sim
GCC_ROOT=/opt/gcc-mips-7.1.0
LD=$(GCC_ROOT)/bin/mips-elf-ld
CC=$(GCC_ROOT)/bin/mips-elf-gcc
AS=$(GCC_ROOT)/bin/mips-elf-as
OBJDUMP=$(GCC_ROOT)/bin/mips-elf-objdump
CFLAGS=-G 0 -Os -Wall -ffreestanding -fno-stack-protector \
	   -nostdinc -nostdlib -fdelayed-branch -fno-builtin

.PHONY: clean run
.SUFFIXES:

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(LD) -G 0 -T link_script.ld -o $@ $^

%.o: %.S
	$(CC) $(CFLAGS) -c -mips1 -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -mips1 -o $@ $<
	
$(ASM_OUTPUT): $(TARGET)
	$(OBJDUMP) -D $< > $@

run: $(TARGET)
	$(SIMDIR)/VMIPS32SOC-x86_64.AppImage --font $(SIMDIR)/mif/font_rom.mif --elf $<

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f $(ASM_OUTPUT)
