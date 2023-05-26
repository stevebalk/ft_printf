/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:46 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/26 18:26:41 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

// static size_t	get_number_length(size_t nbr)
// {
// 	size_t	len;

// 	len = 0;
// 	if (nbr >= 10)
// 		len += get_number_length(nbr / 10);
// 	return (len + 1);
// }

// static size_t	ft_putnbr_base(size_t nbr, char *base, size_t base_size)
// {
// 	size_t	rtn;

// 	rtn = 0;
// 	if (nbr >= base_size)
// 		rtn += ft_putnbr_base(nbr / base_size, base, base_size);
// 	ft_putchar_fd(base[nbr % base_size], 1);
// 	return (rtn + 1);
// }

static char	*ft_uitoa(unsigned int nbr)
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

static char	plus(t_print *f)
{
	if (f->sign)
		return ('+');
	return ('-');
}

static void	ft_print_nbr(t_print *f, char *nbr, int len, int neg)
{
	f->width -= (f->space && !neg && !f->sign && f->width && f->speci != 'u');
	if ((f->sign || neg) && f->speci != 'u')
		f->tl += ft_putnchar_fd(plus(f), 1, f->zero && !f->point);
	else if (f->space && f->speci != 'u')
		f->tl += ft_putnchar_fd(' ', 1, f->zero && !f->point);
	if (!f->left_allign && f->width > f->prec && !f->point && f->zero)
		f->tl += ft_putnchar_fd('0', 1, f->width - f->prec - neg - f->sign);
	else if (!f->left_allign && f->width > f->prec)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec - neg - f->sign);
	if (f->sign)
		f->tl += ft_putnchar_fd('+', 1, !f->zero || f->point);
	else if (f->space && !neg && f->speci != 'u')
		f->tl += ft_putnchar_fd(' ', 1, !f->zero || f->point);
	f->tl += ft_putnchar_fd('0', 1, f->prec - len);
	f->tl += write(1, nbr, len);
	if (f->left_allign && f->width > f->prec)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec - neg - f->sign);
}

void	ft_print_d_i_u(t_print *f)
{
	int		n;
	int		neg;
	char	*nbr;
	int		len;

	n = va_arg(f->args, int);
	neg = (n < 0 && f->speci != 'u');
	if (neg || f->speci == 'u')
		f->sign = 0;
	if (neg)
		n *= -1;
	if (n == INT_MIN)
		nbr = ft_strdup("2147483648");
	else if (f->speci == 'u')
		nbr = ft_uitoa((unsigned int) n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f->prec && f->point)
		len = 0;
	if (f->prec < len || !f->point)
		f->prec = len;
	ft_print_nbr(f, nbr, len, neg);
	free(nbr);
}
