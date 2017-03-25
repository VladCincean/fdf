/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:57:00 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/23 11:48:06 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_vector_destroy(t_vector **v)
{
	if (v == NULL || *v == NULL)
		return ;
	if ((*v)->v != NULL)
	{
		free((*v)->v);
		(*v)->v = NULL;
	}
	ft_memdel((void **)v);
}
