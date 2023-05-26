/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:47 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/27 00:05:22 by sbalk            ###   ########.fr       */
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

// size_t	ft_putnbr_base(size_t nbr, char *base, size_t base_size, t_print *f)
// {
// 	size_t	rtn;
//
// 	rtn = 0;
// 	if (nbr >= base_size)
// 		rtn += ft_putnbr_base(nbr / base_size, base, base_size);
// 	ft_putchar_fd(base[nbr % base_size], 1);
// 	return (rtn + 1);
// }

char	*ft_uitoa(unsigned int nbr)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = nbr;
	len = 0;
	if (nbr == 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

size_t	ft_nbrlen(size_t nbr, size_t base)
{
	size_t	len;

	len = 0;
	if (nbr >= base)
		len += ft_nbrlen(nbr / base, base);
	return (len + 1);
}

void print_debug_struct(t_print *f)
{
	printf("Speci = %c\n", f->speci);
	printf("Width = %i\n", f->width);
	printf("Zero  = %i\n", f->zero);
	printf("Point = %i\n", f->point);
	printf("LeftA = %i\n", f->left_allign);
	printf("Sign  = %i\n", f->sign);
	printf("Space = %i\n", f->space);
	printf("HashT = %i\n", f->hashtag);
	printf("Set   = %i\n", f->set);
	printf("Total = %lu\n", f->tl);
	fflush(stdout);
}