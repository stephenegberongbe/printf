#include "main.h"

/**
 * get_width - Cals the Width for printing
 * @format: Formatted string in Which to print the arguments.
 * @b: List of Arguments to be printed.
 * @list: list of Arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *b, va_list list)
{
	int curr_b;
	int width = 0;

	for (curr_b = *b + 1; format[curr_b] != '\0'; curr_b++)
	{
		if (is_digit(format[curr_b]))
		{
			width *= 10;
			width += format[curr_b] - '0';
		}
		else if (format[curr_b] == '*')
		{
			curr_b++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*b = curr_b - 1;

	return (width);
}
