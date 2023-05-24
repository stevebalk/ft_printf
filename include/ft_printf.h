#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	args;			// arg to print out
	int		width;			// 1... minimum characters to print (padding)
	int		precision;		// .5 specifies the number of characters/digits after string or decimal point
	int		zero;			// 0 print leading zeroes (zero padding)
	int		point;			// . track if precision is set
	int		left_allign;	// - left allign
	int		total_length;	// counts the legnth
	int		sign;			// + Show +sign in front of positive number
	int		percentage;		// % print %
	int		space;			// should a space be printed / used with + for proper allignment
	int		hashtag;		// alternativ printing for x and X
}	t_print;

int	ft_putnbr_base(unsigned long long nbr, char *base, size_t base_size);
const char	*ft_eval_format(t_print *tab, const char *str)
int		ft_printf(const char *str, ...);

#endif