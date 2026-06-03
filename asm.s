global outb
outb:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al
    ret

global inb
inb:
    mov dx, [esp + 4]
    in  al, dx
    ret

global gdt_flush
extern gp
gdt_flush:
    lgdt [gp]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2
flush2:
    ret
