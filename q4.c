#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char buffer[1024]; /* Local buffer of 1024 characters*/

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
/* If the buffer is full, write its contents and reset the count*/
write(1, buffer, 1023);
count = 0;
}
}
else
{
format++;
/* Ignore flag characters, field width, precision, and length modifiers*/
while (*format == '+' || *format == ' ' || *format == '#' || *format == '0' ||
*format == '-' || (*format >= '0' && *format <= '9') || *format == '.' ||
*format == 'l' || *format == 'h')
{
format++;
}

/* Handle conversion specifiers ('d', 'i', 'u', 'o', 'x', 'X', 'c', 's', '%')*/
if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'o' ||
*format == 'x' || *format == 'X' || *format == 'c' || *format == 's' ||
*format == '%')
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
format++;
}
}

/* Write any remaining characters in the buffer*/
if (count > 0)
{
write(1, buffer, count);
}

va_end(args);
return (count);
}

