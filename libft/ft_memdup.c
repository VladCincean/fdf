/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:03:42 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:03:44 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(const void *src, size_t n)
{
	void	*ret;

	if (!src)
		return (NULL);
	ret = (void *)malloc(n);
	if (!ret)
		return (NULL);
	ret = ft_memcpy(ret, src, n);
	return (ret);
}
