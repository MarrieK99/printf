#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints to stdout according to format
 * @format: format string
 * @...: variadic arguments
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
switch (*++format)
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
count += puts(va_arg(args, char *));
break;
case '%':
count += _putchar('%');
break;
default:
/* ignore unrecognized conversion specifiers */
break;
}
}
else
{
count += _putchar(*format);
}
++format;
}
va_end(args);

return (count);
}

