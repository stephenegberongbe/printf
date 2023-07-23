#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an Unsigned number
 * @types: List  of arguments a
 * @buffer: Buffer Array to handle print
 * @flags:  Cals active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[b--] = '0';

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an Unsigned num in Hexadecimal Notation
 * @types: List of arguments a
 * @buffer: Buffer Array to Handle print
 * @flags:  Cals active flags
 * @width: get width.
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Num of chars to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an Unsigned num in upper Hexadecimal Notation
 * @types: List of arguments a
 * @buffer: Buffer Array to Handle print
 * @flags:  Cals active flags
 * @width: get Width
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Number of chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints  Hexadecimal num in lower or upper case
 * @types: List of arguments a
 * @map_to: An Array of values to map the num to
 * @buffer: Buffer Array to Handle print
 * @flags:  Cals active flags
 * @flag_ch: Cals active flags
 * @width: get Width
 * @precision: Precision Specification
 * @size: Size Specifier
 * @size: Size Specification
 * Return: Num of chars to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[b--] = flag_ch;
		buffer[b--] = '0';
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}
