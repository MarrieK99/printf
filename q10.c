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
*format == '-' || (*format >= '0' && *format <= '9') || *format == '.' ||
*format == 'l' || *format == 'h')
{
/* Handle flags, field width, precision, length modifiers */
if (*format == '+')
plusFlag = 1;
else if (*format == ' ')
spaceFlag = 1;
else if (*format == '#')
hashFlag = 1;
else if (*format == '0')
zeroFlag = 1;
else if (*format == '-')
minusFlag = 1;
else if (*format >= '1' && *format <= '9')
{
fieldWidth = 0;
while (*format >= '0' && *format <= '9')
{
fieldWidth = fieldWidth * 10 + (*format - '0');
format++;
}
continue;
}
else if (*format == '.')
{
format++;
precision = 0;
while (*format >= '0' && *format <= '9')
{
precision = precision * 10 + (*format - '0');
format++;
}
continue;
}
else if (*format == 'l')
{
/*Handle 'l' length modifier*/
format++;
continue;
}
else if (*format == 'h')
{
/* Handle 'h' length modifier */
format++;
continue;
}
format++;
}

/* Handle conversion specifiers ('d', 'i', 'u', 'o', 'x', 'X') */

/* Handle precision (if applicable)*/
if (precision >= 0)
{
                /* Implement precision handling here*/
}
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
