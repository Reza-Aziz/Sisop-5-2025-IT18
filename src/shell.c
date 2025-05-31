#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

void shell(){
  char buf[128];
  char cmd[64];
  char arg[2][64];
  
  printString("Welcome to EorzeOS!\n");
  while (true) {
    printString("> ");
    readString(buf);
    
    parseCommand(buf, cmd, arg);
    
    if (processCommand(cmd, arg)) {
      continue;
    } else {
      printString(buf);
      printString("\n");
    }
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  clear(cmd, 64);
  clear(arg[0], 64);
  clear(arg[1], 64);
  
  int i = 0, j = 0;
  
  while (buf[i] == ' ' && buf[i] != '\0') i++;
  
  while (buf[i] != ' ' && buf[i] != '\0') {
    cmd[j++] = buf[i++];
  }
  cmd[j] = '\0';
  
  while (buf[i] == ' ' && buf[i] != '\0') i++;
  j = 0;
  while (buf[i] != ' ' && buf[i] != '\0') {
    arg[0][j++] = buf[i++];
  }
  arg[0][j] = '\0';
  
  while (buf[i] == ' ' && buf[i] != '\0') i++;
  j = 0;
  while (buf[i] != ' ' && buf[i] != '\0') {
    arg[1][j++] = buf[i++];
  }
  arg[1][j] = '\0';
}

bool processCommand(char *cmd, char arg[2][64]) {
  if (strcmp(cmd, "yo") == 0) {
    printString("gurt\n");
    return true;
  }
  
  if (strcmp(cmd, "gurt") == 0) {
    printString("yo\n");
    return true;
  }
  
  return false;
}
