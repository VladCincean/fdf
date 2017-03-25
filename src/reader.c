/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:49:58 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/17 15:44:18 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "libft.h"
#include <stdlib.h>

static t_vector	*read_fd_to_vector(int fd)
{
	char		*line;
	t_vector	*v;
	int			ret;
	size_t		i;

	if ((v = ft_vector_init(10)) == NULL)
		return (NULL);
	while ((ret = get_next_line(fd, &line)) == 1)
		ft_vector_push_back(v, line);
	if (ret == -1)
	{
		i = 0;
		while (i < v->size)
		{
			if (v->v[i] != NULL)
			{
				free(v->v[i]);
				v->v[i] = NULL;
			}
			i++;
		}
		ft_vector_destroy(&v);
		return (NULL);
	}
	return (v);
}

static int		ft_strarray_len(char **str)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i++])
		l++;
	return (l);
}

static void		ft_strarray_destroy(char **str)
{
	int	l;
	int	i;

	l = ft_strarray_len(str);
	i = -1;
	while (++i < l)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
}

static int		fill_matrix(t_controller *ctrl, char **tokens, size_t i)
{
	size_t	j;

	if ((ctrl->data[i] = (t_3d_vector *)malloc(sizeof(t_3d_vector)
					* ctrl->data_cols)) == 0 ||
	(ctrl->color_data[i] = (int *)malloc(sizeof(int) * ctrl->data_cols)) == 0)
	{
		ft_strarray_destroy(tokens);
		return (0);
	}
	j = 0;
	while (j < ctrl->data_cols)
	{
		ctrl->data[i][j].x = (double)i;
		ctrl->data[i][j].y = (double)j;
		ctrl->data[i][j].z = (double)ft_atoi(tokens[ctrl->data_cols - j - 1]);
		ctrl->color_data[i][j] = ft_get_rgb_data(tokens[
				ctrl->data_cols - j - 1]);
		j++;
	}
	ft_strarray_destroy(tokens);
	return (1);
}

int				read_file(t_controller *ctrl, int fd)
{
	t_vector	*v;
	size_t		i;
	char		**tokens;

	if ((v = read_fd_to_vector(fd)) == NULL ||
		(ctrl->data = (t_3d_vector **)malloc(sizeof(t_3d_vector *) * v->size))
			== NULL ||
		(ctrl->color_data = (int **)malloc(sizeof(int *) * v->size)) == NULL)
		return (0);
	i = 0;
	ctrl->data_rows = v->size;
	while (i < v->size)
	{
		if ((tokens = ft_strsplit((char const *)v->v[i], ' ')) == NULL)
			return (0);
		if (ctrl->data_cols == 0)
			ctrl->data_cols = ft_strarray_len(tokens);
		if (fill_matrix(ctrl, tokens, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
