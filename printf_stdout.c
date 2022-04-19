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
	int i, j, len;
	char *str;

	va_start(ap, format);

	len = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(ap, char *);

			for (j = 0; str[j] != '\0'; j++)
			{
				_putchar(str[j]);
				len++;
			}
			i += 2;
		}

		if (format[i] == '%' && format[i + 1] == 'c')
		{
			_putchar(va_arg(ap, int));
			len++;
			i++;
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
