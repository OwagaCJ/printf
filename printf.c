#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _print - utility function for choosing printer function
 *	    varies with different format types
 *
 * @ap: va_list - current list of variadic variables
 * @format: the format to be printed
 *
 * Return: the number of characters printed
 *	   actual value is returned by the printer function
 */
int _print(va_list ap, char format)
{
	int iter;

	printmap printer[] = {
		{"c", print_char},
		{"s", print_str},
		{NULL, NULL}
	};

	for (iter = 0; printer[iter].type != NULL; iter++)
	{
		if (format == printer[iter].type[0])
		{
			return (printer[iter].printer(ap));
		}
	}
	return (0);
}

/**
 * _printf - implementation of the standard printf function
 *
 * @format: formatted string to be printed
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int i, count;
	va_list ap;

	va_start(ap, format);

	count = 0;
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			continue;
		}

		if (format[i + 1] == '%')
		{
			count += _putchar('%');
			i++;
			continue;
		}

		count += _print(ap, format[i + 1]);
		i++;
	}

	va_end(ap);

	return (count);
}
