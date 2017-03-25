/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_preorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:01:58 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:02:00 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_preorder(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	f(root->content, root->content_size);
	ft_btree_preorder(root->left, f);
	ft_btree_preorder(root->right, f);
}
