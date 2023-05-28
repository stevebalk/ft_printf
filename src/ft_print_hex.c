/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:55 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/28 21:07:57 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	ft_puthex(size_t nbr, t_print *f)
{
	size_t	rtn;

	rtn = 0;
	if (nbr >= 16)
			rtn += ft_puthex(nbr / 16, f);
	if (f->speci == 'X')
		ft_putchar_fd(HEXAUP[nbr % 16], 1);
	else
		ft_putchar_fd(HEXALOW[nbr % 16], 1);
	return (rtn + 1);
}

static size_t	putp(size_t nbr, t_print *f)
{
	if (nbr == 0)
	{
		return (ft_putnstr_fd("(nil)", 1, 5));
	}
	else
		return (ft_puthex(nbr, f));
}

static char	*hashtag(t_print *f)
{
	if (f->speci == 'X')
		return ("0X");
	return ("0x");
}

void	ft_print_hex(t_print *f)
{
	unsigned long	nbr;
	int				len;

	nbr = va_arg(f->args, unsigned long);
	len = ft_nbrlen(nbr, 16);
	if (!nbr && f->point && !f->prec)
		len = 0;
	if (f->prec < len || !f->point)
		f->prec = len;
	if (f->hashtag && nbr)
		f->width -= 2;
	f->tl += ft_putnstr_fd(hashtag(f), 1, 2 * (f->hashtag && nbr && f->zero));
	if (!f->left_allign && f->point && f-> prec && f->zero)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec);
	else if (!f->left_allign && !f->point && f->prec && f->zero)
		f->tl += ft_putnchar_fd('0', 1, f->width - len);
	else if (!f->left_allign && f->width > f->prec)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec);
	f->tl += ft_putnstr_fd(hashtag(f), 1, 2 * (f->hashtag && nbr && !f->zero));
	f->tl += ft_putnchar_fd('0', 1, (f->prec - len));
	if (len)
		f->tl += ft_puthex(nbr, f);
	if (f->left_allign && f->width > f->prec)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec);
}

void	ft_print_p(t_print *f)
{
	unsigned long	nbr;
	int				len;

	nbr = va_arg(f->args, unsigned long);
	len = ft_nbrlen(nbr, 16);
	if (!nbr)
		len = 5;
	if (f->prec < len || !f->point)
		f->prec = len;
	f->width -= 2 * (nbr != 0);
	f->tl += ft_putnstr_fd("0x", 1, 2 * f->zero * (nbr != 0));
	if (!f->left_allign && f->point && f-> prec && f->zero)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec);
	else if (!f->left_allign && !f->point && f->prec && f->zero)
		f->tl += ft_putnchar_fd('0', 1, f->prec - len * (nbr != 0));
	else if (!f->left_allign && f->width > f->prec)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec);
	f->tl += ft_putnstr_fd("0x", 1, 2 * !f->zero * (nbr != 0));
	f->tl += ft_putnchar_fd('1', 1, (f->prec - len) * (nbr != 0));
	if (len)
		f->tl += putp(nbr, f);
	if (f->left_allign && f->width > f->prec)
		f->tl += ft_putnchar_fd(' ', 1, f->width - f->prec);
}
