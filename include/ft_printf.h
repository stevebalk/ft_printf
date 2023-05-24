#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	args;			// arg to print out
	size_t	width;			// 1... minimum characters to print (padding)
	int		precision;		// .5 specifies the number of characters/digits after string or decimal point
	size_t	zero;			// 0 print leading zeroes (zero padding)
	int		point;			// . track if precision is set
	int		left_allign;	// - left allign
	size_t	total_length;	// counts the legnth
	int		sign;			// + Show +sign in front of positive number
	int		percentage;		// % print %
	int		space;			// should a space be printed / used with + for proper allignment
	int		hashtag;		// alternativ printing for x and X
}	t_print;

void		ft_reset_t_print(t_print *tab);
const char	*ft_eval_format(t_print *tab, const char *str);
int			ft_printf(const char *str, ...);
void		ft_choose_print_func(const char *str, t_print *tab);

#endif