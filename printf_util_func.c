/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:47 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/22 20:29:47 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static void ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}

static void ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

size_t	ft_putnbr_base(long nbr, char *base, size_t base_size)
{
	size_t	rtn;
	size_t	nbr_len;
	int		sign;

	if (nbr / base_size != 0)
		rtn += ft_putnbr_base(nbr / base_size, base, base_size);
	ft_putchar(base[nbr % base_size]);
	return (rtn + 1);
}
