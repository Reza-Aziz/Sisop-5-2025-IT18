#include "shell.h"
#include "kernel.h"

int main() {
  clearScreen();
  shell();
}

void printString(char *str)
{
  int i = 0;
    while (str[i] != '\0') {
        _interrupt(0x10, 0x0E00 + str[i], 0, 0, 0);
        i++;
    }
}

void readString(char *buf)
{
  int i = 0;
    char c;

    while (true) {
        _interrupt(0x16, 0x0000, 0, 0, 0);
        asm volatile("mov %%al, %0" : "=r"(c)); 

        if (c == '\r') {
            buf[i] = '\0';
            printString("\n");
            break;
        } else if (c == '\b') {
            if (i > 0) {
                i--;
                printString("\b \b");
            }
        } else {
            buf[i++] = c;
            _interrupt(0x10, 0x0E00 + c, 0, 0, 0);
        }
    }
}

void clearScreen()
{
  _interrupt(0x10, 0x0600, 0x0700, 0x0000, 0x184F);
  _interrupt(0x10, 0x0200, 0x0000, 0x0000, 0x0000);
}
