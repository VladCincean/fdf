/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:53:10 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/23 11:30:38 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_vector	*ft_vector_init(int capacity)
{
	t_vector	*v;

	if ((v = (t_vector *)malloc(sizeof(t_vector))) == NULL)
		return (NULL);
	if ((v->v = (void **)malloc(capacity * sizeof(void *))) == NULL)
	{
		free(v);
		return (NULL);
	}
	v->size = 0;
	v->capacity = capacity;
	return (v);
}
