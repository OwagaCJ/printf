#include "main.h"
#include <stdarg.h>

int str_print(char *string);
int character(char c);

/**
 * _printf - produces output according to a formart
 * @format: arguments passed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j, len;
	char *str;

	va_start(ap, format);

	len = 0;
	if (!format)
	{
		return (0);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(ap, char *);
			len += str_print(str);
			i += 2;
		}

		if (format[i] == '%' && format[i + 1] == 'c')
		{
			len += character(va_arg(ap, char));
			i += 2;
		}

		if (format[i] == '%' && fornart[i + 1] == '%')
		{
			_putchar('%');
			len++;
			i += 2;
		}

		else
		{
			_putchar(format[i]);
			len++;
		}
	}

	va_end(ap);
	return (len);
}


int str_print(char *string)
{
	int k;

	for (k = 0; string[k] != '\0'; k++)
	{
		_putchar(string[k]);
	}
	return (k);
}

int character(char c)
{
	_putchar(c);
	return (1);
}
