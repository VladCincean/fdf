/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_postorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:01:55 by vcincean          #+#    #+#             */
/*   Updated: 2016/12/27 14:01:57 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_postorder(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	ft_btree_postorder(root->left, f);
	ft_btree_postorder(root->right, f);
	f(root->content, root->content_size);
}
