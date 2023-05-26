/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:17 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/26 13:53:07 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Prints string until n-th size to the given file descriptor 
* and returns number of wrote chars*/
static size_t	ft_putstrn_fd(const char *str, int fd, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar_fd((char) *str, fd);
		str++;
	}
	return (n);
}

size_t	ft_putnchar_fd(const char ch, int fd, size_t len)
{
	size_t	i;
	
	i = 0;
	while (i++ < len)
		write(fd, &ch, 1);
	return (len);
}

/* Print formatted char */
void	ft_print_char(t_print *f)
{
	int	ch;

	ch = va_arg(f->args, int);
	if (f->left_allign && f->width)
		f->tl += write(1, &ch, 1);
	while (f->width > 1)
	{
		f->tl += write(1, " ", 1);
		f->width--;
	}
	if (!f->left_allign)
		f->tl += write(1, &ch, 1);
}

/* Print formatted string */
void	ft_print_string(t_print *f)
{
	const char *str;

	str = (const char *) va_arg(f->args, char *);
	int len;
	len = ft_strlen(str);
	if (f->point && len > f->prec)
		len = f->prec;
	if (f->width > len && f->left_allign)
		f->tl += ft_putstrn_fd(str, 1, len);
	while (f->width > len)
	{
		f->tl += write(1, " ", 1);
		f->width--;
	}
	if (!f->left_allign)
		f->tl += ft_putstrn_fd(str, 1, len);
}
