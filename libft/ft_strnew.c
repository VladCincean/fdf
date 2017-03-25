/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:05:47 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:05:48 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
