/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:17 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/25 22:34:06 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Prints string until n-th size to the given file descriptor 
* and returns number of wrote chars*/
static size_t	ft_putstrn_fd(int fd, const char *str, size_t n)
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

// size_t	ft_putcharn(int fd, const char ch, size_t len)
// {

// }

/* Print formatted char */
void	ft_print_char(t_print *tab)
{
	int	ch;

	ch = va_arg(tab->args, int);
	if (tab->left_allign && tab->width)
		tab->total_length += write(1, &ch, 1);
	while (tab->width > 1)
	{
		tab->total_length += write(1, " ", 1);
		tab->width--;
	}
	if (!tab->left_allign)
		tab->total_length += write(1, &ch, 1);
}

/* Print formatted string */
void	ft_print_string(t_print *tab)
{
	const char *str;

	str = (const char *) va_arg(tab->args, char *);
	size_t len;
	len = ft_strlen(str);
	if (tab->point && len > tab->precision)
		len = tab->precision;
	if (tab->width > len && tab->left_allign)
		tab->total_length += ft_putstrn_fd(1, str, len);
	while (tab->width > len)
	{
		tab->total_length += write(1, " ", 1);
		tab->width--;
	}
	if (!tab->left_allign)
		tab->total_length += ft_putstrn_fd(1, str, len);
}
