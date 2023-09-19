#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char buffer[1024];

va_start(args, format);

while (*format)
{
if (*format != '%')
{
if (count < 1023)
{
buffer[count] = *format;
count++;
}
else
{
write(1, buffer, 1023);
count = 0;
}
}
else
{
format++;
char plusFlag = 0;
char spaceFlag = 0;
char hashFlag = 0;
char zeroFlag = 0;
char minusFlag = 0;
int fieldWidth = 0;
int precision = -1;

while (*format == '+' || *format == ' ' || *format == '#' || *format == '0' ||
*format == '-' || (*format >= '0' && *format <= '9') || *format == '.')
{
/* Handle flags, field width, precision*/

format++;
}

/* Handle conversion specifiers ('b' and others)*/
if (*format == 'b')
{
unsigned int num = va_arg(args, unsigned int);
int bit;
int i;

for (i = 31; i >= 0; i--)
{
bit = (num >> i) & 1;
if (count < 1023)
{
buffer[count] = bit + '0';
count++;
}
else
{
write(1, buffer, 1023);
count = 0;
buffer[count] = bit + '0';
count++;
}
}
}
/* Handle other conversion specifiers ('c', 's', '%', etc.)*/
}
format++;
}

/* Write any remaining characters in the buffer*/
if (count > 0)
{
write(1, buffer, count);
}

va_end(args);
return (count);
}
