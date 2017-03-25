/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:02:02 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:02:03 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search(t_btree *root, void *content, size_t content_size,
			int (*cmpf)(void *, size_t, void *, size_t))
{
	if ((root == NULL) || (cmpf(root->content, root->content_size,
					content, content_size)))
		return (root);
	if (cmpf(root->content, root->content_size, content, content_size) < 0)
		return (ft_btree_search(root->left, content, content_size, cmpf));
	return (ft_btree_search(root->right, content, content_size, cmpf));
}
