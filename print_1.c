#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - prints a character
 *
 * @c: character to be printed
 *
 * Return: writes to stdout
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - utility function for printing char
 *
 * @ap: va_list with variadic variables
 *
 * Return: 1 - the number of chars printed
 */
int print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	_putchar(c);
	return (1);
}

/**
 * print_str - utility function to print a string
 *
 * @ap: - va_list with variadic variables
 *
 * Return: the number of characters printed
 */

int print_str(va_list ap)
{
	int i;
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}
