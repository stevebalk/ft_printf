/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:47 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/25 00:51:24 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
// #include <stdio.h>

void	ft_reset_t_print(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->left_allign = 0;
	tab->sign = 0;
	tab->percentage = 0;
	tab->space = 0;
	tab->hashtag = 0;
}

static size_t	ft_putnbr_base(unsigned long long nbr, char *base, size_t base_size)
{
	size_t	rtn;

	rtn = 0;
	if (nbr >= base_size)
		rtn += ft_putnbr_base(nbr / base_size, base, base_size);
	ft_putchar_fd(base[nbr % base_size], 1);
	return (rtn + 1);
}

static	size_t get_number_length(size_t nbr)
{
	size_t len;

	len = 0;
	if (nbr >= 10)
		len += get_number_length(nbr / 10);
	return (len + 1);
}

static void	ft_print_uint(t_print *tab)
{
	unsigned int	nbr;
	size_t			nbr_length;

	nbr = va_arg(tab->args, unsigned int);
	nbr_length = get_number_length(nbr);
	if (tab->left_allign || tab->point)
		tab->zero = 0;
	if (!tab->left_allign && tab->width > nbr_length)
		while (tab->width-- != nbr_length)
			tab->total_length += write(1, " ", 1);
	else if (tab->zero > nbr_length)
		while (tab->zero-- != nbr_length)
			tab->total_length += write(1, "0", 1);
	tab->total_length += ft_putnbr_base(nbr, "0123456789", 10);
	if (tab->left_allign && tab->width > nbr_length)
		while (tab->width-- != nbr_length)
			tab->total_length += write(1, " ", 1);
}

static void	ft_print_char(t_print *tab)
{
	int	ch;

	ch = va_arg(tab->args, int);
	if (tab->left_allign && tab->width)
		tab->total_length += write(1, &ch, 1);
	while (tab->width > 1)
	{
		tab->total_length += write(1, " ", 1);
		tab->width--;
	}
	if (!tab->left_allign)
		tab->total_length += write(1, &ch, 1);
}

// Check if the precision syntax is correct and return digit length
// if it's not a valid syntax, returns 0
static	size_t	set_precision(t_print *tab, const char *str)
{
	size_t	i;

	i = 0;
	str++;
	if (ft_isdigit(*str))
	{
		tab->precision = ft_atoi(str);
		tab->point = 1;
		while (ft_isdigit(*str))
		{
			str++;
			i++;
		}
	}
	return (i);
}

static	size_t	set_width(t_print *tab, const char *str)
{
	size_t	i;

	i = 0;
	tab->width = ft_atoi(str);
	str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

static	size_t	set_zero_padding(t_print *tab, const char *str)
{
	size_t	i;

	i = 0;
	str++;
	tab->zero = ft_atoi(str);
	while (ft_isdigit(*str))
	{
		i++;
		str++;
	}
	return (i);
}

const char	*ft_eval_format(t_print *tab, const char *str)
{
	while (*str != 'd' && *str != 'i' && *str != 'u' && *str != '%'
		&& *str != 'x' && *str != 'X' && *str != 'c' && *str != 's'
		&& *str != 'p')
	{
		if (*str == '.')
			str += set_precision(tab, str);
		else if (*str == '-')
			tab->left_allign = 1;
		else if (*str == '+')
			tab->sign = 1;
		else if (*str == ' ')
			tab->space = 1;
		else if (*str == '%')
			tab->percentage = 1;
		else if (*str == '#')
			tab->hashtag = 1;
		else if (*str == '0')
			str += set_zero_padding(tab, str);
		else if (ft_isdigit(*str))
			str += set_width(tab, str);
		str++;
	}
	return (str);
}


void	ft_choose_print_func(const char *str, t_print *tab)
{
	if (*str == 'c')
		ft_print_char(tab);
	else if (*str == '%')
		tab->total_length += write(1, "%", 1);
	else if (*str == 'u')
		ft_print_uint(tab);
	// else if (*str == 'd' || *str == 'i')
	// 	tab->total_length = ft_putnbr_base();
}

// void	ft_print_integer(t_print *tab)
// {
// 	int	nb;
//
// 	nb = va_arg(tab->args, int);
// }

// else if (*(str - 1) == '.' && ft_isdigit(*str) && *str > '0')
// 		{
// 			tab->precision = ft_atoi(str);
// 			str += tab->precision - 1;
// 		}
// 		else if( ft_isdigit(*str) && *str > '0')
// 		{
// 			tab->width = ft_atoi(str);
// 			str += tab->width - 1;
// 		}
// 		else if (ft_isdigit(*str) && *str == '0')
// 		{
// 			tab->zero = ft_atoi(str);
// 			str += tab->zero;
// 		}