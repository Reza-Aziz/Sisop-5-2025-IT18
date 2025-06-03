#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

char currentUsername[32] = "user";

void shell(){
  char buf[128];
  char cmd[64];
  char arg[2][64];
  
  printString("Welcome to EorzeOS!\n");
  while (true) {
    printString(currentUsername);
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
  if (strcmp(cmd, "user") == 0) {
    if (arg[0][0] == '\0') {
      strcpy(currentUsername, "user");
      printString("Username changed to user\n");
    } else {
      strcpy(currentUsername, arg[0]);
      printString("Username changed to ");
      printString(arg[0]);
      printString("\n");
    }
    return true;
  }
  
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

if (strcmp(cmd, "grandcompany") == 0) {
    if (strcmp(arg[0], "maelstrom") == 0) {
      clearScreen();
      setColor(0x04); // merah
      strcpy(grandCompanyTitle, "@Storm");
      printString("Grand Company set to Maelstrom\n");
    } else if (strcmp(arg[0], "twinadder") == 0) {
      clearScreen();
      setColor(0x0E); // kuning
      strcpy(grandCompanyTitle, "@Serpent");
      printString("Grand Company set to Twin Adder\n");
    } else if (strcmp(arg[0], "immortalflames") == 0) {
      clearScreen();
      setColor(0x01); // biru
      strcpy(grandCompanyTitle, "@Flame");
      printString("Grand Company set to Immortal Flames\n");
    } else {
      printString("Error: Invalid Grand Company\n");
    }
    return true;
}

if (strcmp(cmd, "clear") == 0) {
    clearScreen();
    setColor(0x07); // warna default putih
    strcpy(grandCompanyTitle, "");
    printString("Grand Company cleared\n");
    return true;
  }

if (strcmp(cmd, "add") == 0) {
    int x = atoi(arg[0]);
    int y = atoi(arg[1]);
    int res = x + y;
    char resStr[16];
    itoa(res, resStr);
    printString(resStr);
    printString("\n");
    return true;
  }

  if (strcmp(cmd, "sub") == 0) {
    int x = atoi(arg[0]);
    int y = atoi(arg[1]);
    int res = x - y;
    char resStr[16];
    itoa(res, resStr);
    printString(resStr);
    printString("\n");
    return true;
  }

  if (strcmp(cmd, "mul") == 0) {
    int x = atoi(arg[0]);
    int y = atoi(arg[1]);
    int res = x * y;
    char resStr[16];
    itoa(res, resStr);
    printString(resStr);
    printString("\n");
    return true;
  }

  if (strcmp(cmd, "div") == 0) {
    int x = atoi(arg[0]);
    int y = atoi(arg[1]);
    if (y == 0) {
      printString("Error: Division by zero\n");
    } else {
      int res = x / y;
      char resStr[16];
      itoa(res, resStr);
      printString(resStr);
      printString("\n");
    }
    return true;
  }

  return false;
}
