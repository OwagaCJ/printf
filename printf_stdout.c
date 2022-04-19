#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a formart
 * @format: arguments passed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i;

	va_start(ap, formart);

	for (formart[i] = 0; formart[i] != '%s'; i++);
	{
		_putchar(formart[i]);
	}

	va_end(ap);
}
