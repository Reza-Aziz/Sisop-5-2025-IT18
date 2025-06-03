#include "std_lib.h"

int div(int a, int b)
{
  int negative = 0;
    if (a < 0) {
        a = -a;
        negative = !negative;
    }
    if (b < 0) {
        b = -b;
        negative = !negative;
    }
    int result = 0;
    while (a >= b) {
        a = a - b;
        result++;
    }
    return negative ? -result : result;
}

int mod(int a, int b)
{
  int negative = 0;
    if (a < 0) {
        a = -a;
        negative = 1;
    }
    if (b < 0) {
        b = -b;
    }
    while (a >= b) {
        a = a - b;
    }
    return negative ? -a : a;
}

bool strcmp(char *str1, char *str2)
{
  int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return false;
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void strcpy(char *dst, char *src)
{
   int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void clear(byte *buf, unsigned int size)
{
  for (unsigned int i = 0; i < size; i++) {
        buf[i] = 0;
    }
}

void atoi(char *str, int *num)
{
   int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == ' ') i++;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    *num = sign * result;
}

void itoa(int num, char *str)
{
  int i = 0;
    int isNegative = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    char temp[20];
    int j = 0;
    while (num != 0) {
        temp[j++] = (num % 10) + '0';
        num = num / 10;
    }
    if (isNegative) {
        str[i++] = '-';
    }
    for (int k = j - 1; k >= 0; k--) {
        str[i++] = temp[k];
    }
    str[i] = '\0';
}
