/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:02:46 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:02:48 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	number_length(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	len;

	len = number_length(n);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	else if (n == -2147483648)
	{
		ret = ft_strcpy(ret, "-2147483648");
		n = 0;
	}
	else if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (n)
	{
		ret[--len] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (ret);
}
