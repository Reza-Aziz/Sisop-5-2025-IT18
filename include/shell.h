#ifndef SHELL_H
#define SHELL_H

#include "std_type.h"

void shell();
void parseCommand(char *buf, char *cmd, char arg[2][64]);

bool processCommand(char *cmd, char arg[2][64]);

#endif
