/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:20:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/25 23:58:25 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

/* Check if the precision syntax is correct and return digit length
* if it's not a valid syntax, returns 0 */
static	size_t	parse_precision(t_print *tab, const char *str)
{
	size_t	i;

	i = 1;
	tab->point = 1;
	str++;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if (!tab->precision && ft_isdigit(*str))
		{
			tab->precision = (size_t) ft_atoi(str);
			// tab->set = 1;
		}
		str++;
		i++;
	}
	return (i);
}

static	size_t	parse_width(t_print *tab, const char *str)
{
	size_t	i;

	i = 0;
	tab->set = 1;
	tab->width = ft_atoi(str);
	str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

// static	size_t	parse_zero_padding(t_print *tab, const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	str++;
// 	tab->zero = ft_atoi(str);
// 	while (ft_isdigit(*str))
// 	{
// 		i++;
// 		str++;
// 	}
// 	return (i);
// }

const char	*ft_eval_format(t_print *tab, const char *str)
{
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
	{
		if (*str == '-')
			tab->left_allign = 1;
		else if (*str == '+')
			tab->sign = 1;
		else if (*str == ' ')
			tab->space = 1;
		else if (*str == '#')
			tab->hashtag = 1;
		else if (*str == '0' && !ft_isdigit(*(str - 1)))
			tab->zero = 1;
		else if (*str > '0' && *str <= '9' && !tab->set)
			str += parse_width(tab, str);
		str++;
	}
	if (*str == '.')
			str += parse_precision(tab, str);
	printf("Precision: %lu\n", tab->precision);
	printf("Width: %lu\n", tab->width);
	return (str);
}
