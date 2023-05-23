#include <stdio.h>
#include <unistd.h>
#include "printf_util_func.c"


int	main(void)
{
	int a = 3;
	int *p = &a;

	printf("1. Integer Formatting:\n");
	// %d or %i: Signed decimal integer.
	// %u: Unsigned decimal integer.
	// %o: Unsigned octal integer.
	// %x or %X: Unsigned hexadecimal integer (lowercase or uppercase).
	printf("%i, %u, %o, %#X\n\n", -42, -3, 42, 100);

	printf("2. Floating-Point Formatting:\n");
	// %f: Decimal floating-point.
	// %e or %E: Scientific notation (lowercase or uppercase).
	// %g or %G: Compact decimal or scientific notation (lowercase or uppercase).
	// %a or %A: Hexadecimal floating-point (lowercase or uppercase).
	printf("%f, %e, %g, %a\n\n", 3.14159, 3.14159, 3.14159, 3.14159);

	printf("3. Character and String Formatting:\n");
	// %c: Character.
	// %s: String of characters.
	printf("%c, %s\n\n", 'A', "Hello");

	printf("4. Width and Precision:\n");
	// width: Specifies the minimum field width.
	// precision: Specifies the number of digits after the decimal
	// point (for floats) or maximum string length (for strings).
	printf("%-+5d, %5.2f, %-10s\n\n", 42, 3.14159, "Hello");

	printf("5. Flags:\n");
	// -: Left-justify the output.
	// +: Display the sign for positive numbers.
	// 0: Pad with leading zeros.
	// #: Alternative form (varies based on the specifier).
	// .: Maximum number of characters to be printed
	printf("%-6s, %+05d, %.3d, %#x, %-20.8s\n\n", "Peter", 42, 4244, 42, "Hello, World");

	printf("6. Field Width and Precision as Arguments:\n");
	// *: Specifies that the field width or precision will be
	// provided as an argument before the corresponding value.
	printf("%*d, %.*f\n\n", 6, 42, 3, 3.14159);

	printf("7. Escape Characters:\n");
	// %%: Prints a literal '%' character.
	printf("This is a literal percent sign: %%\n\n");

	printf("8. Pointer\n");
	// Prints pointer
	printf("Pointer: %p\n\n", p);

	printf("Example for + \n");
	printf("%d\n%+d\n% d\n", 42, 42, 42);
	fflush(stdout);

	unsigned int nbr			= 33454562;
	char *base			= "0123456789";
	size_t base_size	= 10;
	ft_putnbr_base(nbr, base, base_size);
	ft_putchar('\n');
	printf("printf(hex): %x\n", nbr);

}