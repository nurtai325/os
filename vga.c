#include "vga.h"
#include "asm.h"

void vga_write(char *text, int len, int offset) {
    struct vga_cell *fb = (struct vga_cell *)VGA_BUFFER_ADDRESS;
    fb += offset;

    for (int i = 0; i < len; i++) {
        struct vga_cell cell;
        cell.ch = *(text + i);
        cell.color = VGA_COLOR_WHITE;

        *(fb + i) = cell;
    }
}

void vga_move_cursor(unsigned short pos) {
    outb(0x3D4, 14);
    outb(0x3D5, ((pos >> 8) & 0x00FF));
    outb(0x3D4, 15);
    outb(0x3D5, pos & 0x00FF);
}
