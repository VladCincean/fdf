/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:03:45 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/29 14:56:25 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*char_dst;
	unsigned char	*char_src;
	unsigned char	*temp;
	size_t			i;

	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	temp = (unsigned char *)malloc(len);
	i = 0;
	while (i < len)
	{
		temp[i] = char_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		char_dst[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
