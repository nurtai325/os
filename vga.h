#ifndef VGA_H
#define VGA_H

#define VGA_BUFFER_ADDRESS 0x000B8000
#define VGA_WIDTH 80
#define VGA_COLOR_WHITE 0x0F

struct __attribute__((packed)) vga_cell {
    char ch;
    char color;
};

void vga_write(char *text, int len, int offset);
void vga_move_cursor(unsigned short pos);

#endif
