#include "asm.h"

// TODO: replace magic numbers with constants
// TODO: transition to 64 bit

int strlen(char *str) {
    char *s = str;
    while (*s) {
        s++;
    }
    return s - str;
}

void sleep(int ticks) {
    for (int i = 0; i < ticks; i++) {
        __asm__ volatile("pause");
    }
}

struct __attribute__((packed)) vga_cell {
    char ch;
    char color;
};

void vga_write(char *text, int len, int offset) {
    struct vga_cell *fb = (struct vga_cell *)0x000B8000;
    fb += offset;

    for (int i = 0; i < len; i++) {
        struct vga_cell cell;
        cell.ch = *(text + i);
        cell.color = 0x0F;

        *(fb + i) = cell;
    }
}

void vga_move_cursor(unsigned short pos) {
    outb(0x3D4, 14);
    outb(0x3D5, ((pos >> 8) & 0x00FF));
    outb(0x3D4, 15);
    outb(0x3D5, pos & 0x00FF);
}

struct gdt {
    unsigned int address;
    unsigned short size;
} __attribute__((packed));

void kmain() {
    char *nurtai = "Hello from Nurtai OS";
    char *nurtai2 = "Another hello from Nurtai OS";
    char *nurtai3 = "Yet another hello from Nurtai OS";

    vga_move_cursor(0);
    sleep(10000000);

    vga_write(nurtai, strlen(nurtai), 80 * 0);
    vga_move_cursor(1);
    sleep(10000000);

    vga_write(nurtai2, strlen(nurtai2), 80 * 1);
    vga_move_cursor(2);
    sleep(10000000);

    vga_write(nurtai3, strlen(nurtai3), 80 * 2);
    vga_move_cursor(3);
    sleep(10000000);
}
