#include "main.h"
#include <stdarg.h>

int str_print(char *string);
int character(char c);
int zero_space(char *str);

/**
 * _printf - produces output according to a formart
 * @format: arguments passed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, k, len;
	char *str;

	va_start(ap, format);
	len = 0;
	if (!format)
		return (0);
	for (i = 0; format[i] != '\0'; i++)
	{
		k = 1;
		if (format[i] == '%' && format[i + 1] == ' ')
		{
			str = (char *)(format + i + 1);
			k += zero_space(str);
		}
		if (format[i] == '%' && format[i + k] == 's')
		{
			str = va_arg(ap, char *);
			len += str_print(str);
			i += k + 1;
		}

		if (format[i] == '%' && format[i + k] == 'c')
		{
			len += character(va_arg(ap, int));
			i += k + 1;
		}

		if (format[i] == '%' && format[i + k] == '%')
		{
			_putchar('%');
			len++;
			i += k;
		}
		if (format[i] == '%' && format[i + k] == '\0')
		{
			len = -1;
			i += k - 1;
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

/**
 * str_print - prints a string
 *
 * @string: a character array
 *
 * Return: length of string
 */
int str_print(char *string)
{
	int k;

	for (k = 0; string[k] != '\0'; k++)
	{
		_putchar(string[k]);
	}
	return (k);
}

/**
 * character - prints a character
 *
 * @c: character
 *
 * Return: 1 (length of character)
 *
 */
int character(char c)
{
	_putchar(c);
	return (1);
}

/**
 * zero_space - counts number of consecutive whitespaces
 *
 * @str: string that starts with whitespace
 *
 * Return: Number of consecutive whitespaces
 */
int zero_space(char *str)
{
	int i;

	for (i = 0; str[i] == ' '; i++)
		;
	return (i);
}
