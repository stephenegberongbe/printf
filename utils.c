#include "main.h"

/**
 * is_printable - Evaluates if a Char Is printable
 * @c: Char to be Evaluated.
 *
 * Return: 1 if c is Printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in a Hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: 3 Always
 */
int append_hexa_code(char ascii_code, char buffer[], int b)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[b++] = '\\';
	buffer[b++] = 'x';

	buffer[b++] = map_to[ascii_code / 16];
	buffer[b] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a Digit.
 * @c: Char to be Evaluated.
 *
 * Return: 1. if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a numb to the specified size
 * @num: Num to be Casted.
 * @size: Num Indicating the type to be casted.
 *
 * Return: Casted Value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a num to the specified size
 * @num: Num to be casted
 * @size: Num Indicating the type to be casted
 *
 * Return: Casted Value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
