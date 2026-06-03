#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

void outb(unsigned short port, unsigned char data);

unsigned char inb(unsigned short port);

void gdt_flush();

#endif
