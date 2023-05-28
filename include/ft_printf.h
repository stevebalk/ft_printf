/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:53:14 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/28 15:19:30 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_print
{
	va_list	args;			// arg to print out
	char	speci;
	int		width;			// 1... minimum characters to print (padding)
	int		prec;			// .5 specifies the number of characters/digits after string or decimal point
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
# define HEXALOW	"0123456789abcdef"
# define HEXAUP		"0123456789ABCDEF"

void		ft_reset_t_print(t_print *f);
const char	*ft_eval_format(t_print *f, const char *str);
int			ft_printf(const char *str, ...);

/* UTILITY */
int			ft_putnchar_fd(const char ch, int fd, int len);
int			ft_putnstr_fd(const char *str, int fd, int n);
char		*ft_uitoa(unsigned int nbr);
int			ft_nbrlen(int nbr, int base);

// DEBUG //
void		print_debug_struct(t_print *f);

/* PRINT FUNCTIONS */
void		ft_print_char(t_print *f);
void		ft_print_string(t_print *f);
void		ft_print_d_i_u(t_print *f);
void		ft_print_hex(t_print *f);

#endif