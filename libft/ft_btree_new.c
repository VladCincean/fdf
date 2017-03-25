/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:01:52 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:16:08 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree	*ft_btree_new(void const *content, size_t content_size)
{
	t_btree	*ret;

	if (!(ret = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	if (!content)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		ret->content = ft_memdup(content, content_size);
		ret->content_size = content_size;
	}
	ret->left = NULL;
	ret->right = NULL;
	ret->height = 1;
	return (ret);
}
