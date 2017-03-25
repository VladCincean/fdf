/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:02:49 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:02:51 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	number_length(int n, int base)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static char		digit_to_char(int d)
{
	if (d > 9)
		return ((char)(d + 'A' - 10));
	return ((char)(d + '0'));
}

static char		*min_int_special_case(char *ret, int base)
{
	int	n;
	int len;

	n = -2147483648;
	len = number_length(n, base);
	n /= base;
	n *= -1;
	ret[0] = '-';
	ret[--len] = digit_to_char(3648 % base);
	while (n)
	{
		ret[--len] = digit_to_char(n % base);
		n /= base;
	}
	return (ret);
}

char			*ft_itoa_base(int n, int base)
{
	char	*ret;
	size_t	len;

	len = number_length(n, base);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	else if (n == -2147483648)
		return (min_int_special_case(ret, base));
	else if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (n)
	{
		ret[--len] = digit_to_char(n % base);
		n /= base;
	}
	return (ret);
}
