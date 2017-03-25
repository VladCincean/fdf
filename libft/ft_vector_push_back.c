/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:44:02 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/23 11:38:57 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	f_resize(t_vector *v, int new_capacity)
{
	void	**new_v;

	if ((new_v = (void **)malloc(new_capacity * sizeof(void *))) == NULL)
		return (0);
	new_v = ft_memcpy((void *)new_v, (const void *)v->v, v->capacity
			* sizeof(void *));
	ft_memdel((void **)&(v->v));
	v->v = new_v;
	v->capacity = new_capacity;
	return (1);
}

int			ft_vector_push_back(t_vector *v, void *e)
{
	if (v->size == v->capacity && f_resize(v, 2 * v->capacity) == 0)
		return (0);
	v->v[v->size] = e;
	v->size++;
	return (1);
}
