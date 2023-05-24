/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:48:12 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/25 00:43:31 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	t_print *tab;
	int ret;

	tab = (t_print *)calloc(sizeof(t_print), 1);
	if (tab == NULL)
		return(-1);
	va_start(tab->args, str);
	ret = 0;
	while(*str)
	{
		if (*str != '%')
			ret += write(1, str++, 1);
		else
		{
			str = ft_eval_format(tab, str + 1);
			ft_choose_print_func(str++, tab);
			ft_reset_t_print(tab);
		}
	}
	va_end(tab->args);
	ret += tab->total_length;
	free(tab);
	return (ret);
}
