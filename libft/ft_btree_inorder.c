/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_inorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:01:42 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:01:43 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_inorder(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	ft_btree_inorder(root->left, f);
	f(root->content, root->content_size);
	ft_btree_inorder(root->right, f);
}
