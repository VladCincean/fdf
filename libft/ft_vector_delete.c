/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:00:22 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/23 11:39:15 by vcincean         ###   ########.fr       */
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

int			ft_vector_delete(t_vector *v, int index)
{
	if (index < 0 || (size_t)index >= v->size)
		return (0);
	while ((size_t)index < v->size - 1)
	{
		v->v[index] = v->v[index + 1];
		index++;
	}
	v->v[index] = NULL;
	v->size--;
	if (v->size > 0 && v->size == v->capacity / 4)
		return (f_resize(v, v->capacity / 2));
	return (1);
}
