/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:05:15 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/29 15:25:40 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size < dest_len + 1)
		return (size + src_len);
	if (size == dest_len + 1)
		return (dest_len + src_len);
	ft_memcpy(dest + dest_len, src, size - dest_len - 1);
	dest[size - 1] = '\0';
	return (dest_len + src_len);
}
