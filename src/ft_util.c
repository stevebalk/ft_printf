/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:47 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/25 21:15:34 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_reset_t_print(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->left_allign = 0;
	tab->sign = 0;
	tab->space = 0;
	tab->hashtag = 0;
	tab->set = 0;
}

void	ft_choose_print_func(const char *str, t_print *tab)
{
	if (*str == 'c')
		ft_print_char(tab);
	else if (*str == '%')
		tab->total_length += write(1, "%", 1);
	else if (*str == 'u')
		ft_print_u(tab);
	else if (*str == 's')
		ft_print_string(tab);
	// else if (*str == 'd' || *str == 'i')
	// 	tab->total_length = ft_putnbr_base();
}
