/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:47 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/28 17:49:35 by sbalk            ###   ########.fr       */
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

int	ft_nbrlen(long nbr, int base)
{
	int	len;

	len = 0;
	if (nbr >= base)
		len += ft_nbrlen(nbr / base, base);
	return (len + 1);
}
