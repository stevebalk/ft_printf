#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;			// arg to print out
	char	speci;
	int		width;			// 1... minimum characters to print (padding)
	int		prec;		// .5 specifies the number of characters/digits after string or decimal point
	int		zero;			// 0 print leading zeroes (zero padding)
	int		point;			// . track if precision is set
	int		left_allign;	// - left allign
	size_t	tl;				// counts the legnth
	int		sign;			// + Show +sign in front of positive number
	int		space;			// should a space be printed / used with + for proper allignment
	int		hashtag;		// alternativ printing for x and X
	int		set;			// is width set
}	t_print;

/* String containing printf's specifiers */
# define SPECIFIERS	"cspdiuxX%"

/* Hexadecimal base */
# define HEXA_BASE	"0123456789abcdef"

void		ft_reset_t_print(t_print *f);
const char	*ft_eval_format(t_print *f, const char *str);
int			ft_printf(const char *str, ...);
void		ft_choose_print_func(const char *str, t_print *f);
size_t		ft_putnchar_fd(const char ch, int fd, size_t len);
void		ft_print_d_i_u(t_print *f);


/* Print formatted UINT */
void	ft_print_u(t_print *f);

/* Print formatted char */
void	ft_print_char(t_print *f);

/* Print formatted string */
void	ft_print_string(t_print *f);

#endif