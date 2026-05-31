CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

os.iso: iso/boot/kernel.elf
	grub-mkrescue -o os.iso iso

iso/boot/kernel.elf: loader.o kmain.o
	ld -T link.ld -melf_i386 -o iso/boot/kernel.elf loader.o kmain.o

loader.o: loader.s
	nasm -f elf32 -o loader.o loader.s

kmain.o: kmain.c
	gcc $(CFLAGS) kmain.c -o kmain.o

clean:
	find . -regextype posix-extended -type f -regex ".*\.(o|elf|iso|log)" -delete

boch: os.iso
	bochs -f bochsrc.txt -q
