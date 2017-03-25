/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:28:59 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/27 13:28:11 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_matrix	*matrix_create(int rows, int cols)
{
	t_matrix	*mat;
	int			i;

	if ((mat = (t_matrix *)malloc(sizeof(t_matrix))) == NULL)
		return (NULL);
	if ((mat->m = (double **)malloc(sizeof(double *) * rows)) == NULL)
	{
		free(mat);
		return (NULL);
	}
	mat->rows = rows;
	mat->cols = cols;
	i = -1;
	while (++i < rows)
	{
		if ((mat->m[i] = (double *)malloc(sizeof(double) * cols)) == NULL)
		{
			matrix_destroy(mat);
			return (NULL);
		}
	}
	return (mat);
}

void		matrix_destroy(t_matrix *mat)
{
	int	i;

	if (mat == NULL || mat->m == NULL)
		return ;
	i = -1;
	while (++i < mat->rows)
	{
		if (mat->m[i] != NULL)
			free(mat->m[i]);
		mat->m[i] = NULL;
	}
	free(mat->m);
	mat->m = 0;
	mat->rows = 0;
	mat->cols = 0;
}
