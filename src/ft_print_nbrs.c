/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:46 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/26 00:19:56 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static size_t	get_number_length(size_t nbr)
{
	size_t	len;

	len = 0;
	if (nbr >= 10)
		len += get_number_length(nbr / 10);
	return (len + 1);
}

static size_t	ft_putnbr_base(size_t nbr, char *base, size_t base_size)
{
	size_t	rtn;

	rtn = 0;
	if (nbr >= base_size)
		rtn += ft_putnbr_base(nbr / base_size, base, base_size);
	ft_putchar_fd(base[nbr % base_size], 1);
	return (rtn + 1);
}

void	ft_print_u(t_print *tab)
{
	size_t	nbr;
	int	nbr_length;

	nbr = va_arg(tab->args, unsigned int);
	if (nbr == 0 && tab->point && tab->precision == 0)
		return ;
	nbr_length = get_number_length(nbr);
	tab->zero = (!tab->left_allign && !tab->point && tab->zero);
	if (tab->point && !tab->left_allign && tab->width - tab->precision > nbr_length)
		while (tab->width - tab->precision + nbr_length != nbr_length)
		{
				tab->width--;
				tab->total_length += write(1, " ", 1);
				// printf("width: %lu\n", tab->width);
		}
	if (!tab->left_allign && tab->width > nbr_length && tab->zero)
		while (tab->width-- != nbr_length)
				tab->total_length += write(1, "0", 1);
	else if (tab->point && tab->precision > nbr_length)
		while (tab->precision-- != nbr_length)
				tab->total_length += write(1, "0", 1);
	tab->total_length += ft_putnbr_base(nbr, DECI_BASE, 10);
	if (tab->left_allign && tab->width > nbr_length)
		while (tab->width-- != nbr_length)
			tab->total_length += write(1, " ", 1);
}

// void	ft_print_u(t_print *tab)
// {
// 	size_t	nbr;
// 	size_t	nbr_length;

// 	nbr = va_arg(tab->args, unsigned int);
// 	if (nbr == 0 && tab->point && tab->precision == 0)
// 		return ;
// 	nbr_length = get_number_length(nbr);
// 	tab->width -= ((tab->sign || tab->space) && tab->width);
// 	if (tab->sign)
// 		tab->total_length += write(1, "+", 1);
// 	else if (tab->space)
// 		tab->total_length += write(1, " ", 1);
// 	tab->zero = (!tab->left_allign && !tab->point && tab->zero);
// 	if (!tab->left_allign && tab->width > nbr_length && tab->zero)
// 		while (tab->width-- != nbr_length)
// 				tab->total_length += write(1, "0", 1);
// 	else if (tab->point && tab->precision && tab->precision > nbr_length)
// 		while (tab->width-- != nbr_length)
// 				tab->total_length += write(1, "0", 1);
// 	else if (tab->width > nbr_length)
// 		while (tab->width-- != nbr_length)
// 				tab->total_length += write(1, " ", 1);
// 	tab->total_length += ft_putnbr_base(nbr, DECI_BASE, 10);
// 	if (tab->left_allign && tab->width > nbr_length)
// 		while (tab->width-- != nbr_length)
// 			tab->total_length += write(1, " ", 1);
// }
