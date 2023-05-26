/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:47 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/26 18:38:54 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_reset_t_print(t_print *f)
{
	f->speci = 0;
	f->width = 0;
	f->prec = 0;
	f->zero = 0;
	f->point = 0;
	f->left_allign = 0;
	f->sign = 0;
	f->space = 0;
	f->hashtag = 0;
	f->set = 0;
}

void	ft_choose_print_func(const char *str, t_print *f)
{
	f->speci = *str;
	if (*str == 'c')
		ft_print_char(f);
	else if (*str == '%')
		f->tl += write(1, "%", 1);
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		ft_print_d_i_u(f);
	else if (*str == 's')
		ft_print_string(f);
}
