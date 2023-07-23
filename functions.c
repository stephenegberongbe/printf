#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints Char
 * @types: List  of arguments a
 * @buffer: Buffer Array to handle print
 * @flags:  Cals active flags
 * @width: Width
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Num of chars to be printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a String
 * @types: List of arguments a
 * @buffer: Buffer Array to Handle print
 * @flags:  Cals active flags
 * @width: get Width.
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Num of chars to be printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, b;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (b = width - length; b > 0; b--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (b = width - length; b > 0; b--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a Percent Sign
 * @types: List of arguments a
 * @buffer: Buffer Array to Handle print
 * @flags:  Cals active flags
 * @width: get Width.
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Num of chars to be printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print Int
 * @types: List of arguments a
 * @buffer: Buffer array to Handle print
 * @flags:  Cals active flags
 * @width: get Width.
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Num of chars to be printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;

	return (write_number(is_negative, b, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an Unsigned Num
 * @types: List of arguments a
 * @buffer: Buffer Array to Handle print
 * @flags:  Cals active flags
 * @width: get Width.
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Num of charto be printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, b, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (b = 1; b < 32; b++)
	{
		m /= 2;
		a[b] = (n / m) % 2;
	}
	for (b = 0, sum = 0, count = 0; b < 32; b++)
	{
		sum += a[b];
		if (sum || b == 31)
		{
			char z = '0' + a[b];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
