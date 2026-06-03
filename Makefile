CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
C_SOURCES = $(wildcard *.c)
S_SOURCES = $(wildcard *.s)
OBJECTS = $(C_SOURCES:.c=.o) $(S_SOURCES:.s=.o)

os.iso: iso/boot/kernel.elf
	grub-mkrescue -o os.iso iso

iso/boot/kernel.elf: $(OBJECTS)
	ld -T link.ld -melf_i386 -o iso/boot/kernel.elf $(OBJECTS)

%.o: %.c
	gcc $(CFLAGS) $< -o $@

%.o: %.s
	nasm -f elf32 -o $@ $<

clean:
	find . -regextype posix-extended -type f -regex ".*\.(o|elf|iso|log)" -delete

boch: os.iso
	bochs -f bochsrc.txt -q
