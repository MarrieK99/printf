#include <stdio.h>
#include "main.h"

int main(void)
{
	int count;

	count = _printf("Hello, world!\n");
	printf("count = %d\n", count);

	count = _printf("%%a%%b%%c%%d%%e%%f%%g%%h%%i%%j%%k%%l%%m%%n%%o%%p%%q%%r%%s%%t%%u%%v%%w%%x%%y%%z\n");
	printf("count = %d\n", count);

	return 0;
}

