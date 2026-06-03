#include "gdt.h"
#include "vga.h"

int len(char *str) {
    char *s = str;
    while (*s) {
        s++;
    }
    return s - str;
}

void kmain() {
    gdt_install();

    char *nurtai = "Hello from Nurtai OS";
    char *nurtai2 = "Another hello from Nurtai OS";
    char *nurtai3 = "Yet another hello from Nurtai OS";

    vga_move_cursor(0);

    vga_write(nurtai, len(nurtai), 80 * 0);
    vga_move_cursor(1);

    vga_write(nurtai2, len(nurtai2), 80 * 1);
    vga_move_cursor(2);

    vga_write(nurtai3, len(nurtai3), 80 * 2);
    vga_move_cursor(3);
}
