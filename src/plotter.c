/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:36:00 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/25 14:05:07 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include <mlx.h>
#include <math.h>

static t_2d_vector	iso(t_controller *ctrl, size_t i, size_t j)
{
	t_3d_vector	v;
	t_2d_vector	r;
	double		scaling_factor;
	double		avg;

	v = ctrl->data[i][j];
	avg = (ctrl->data_rows + ctrl->data_cols) / 2;
	if (avg < 25)
		scaling_factor = 22.0;
	else if (25 <= avg && avg < 40)
		scaling_factor = 15.0;
	else if (40 <= avg && avg < 120)
		scaling_factor = 2.8;
	else if (120 <= avg && avg < 170)
		scaling_factor = 2.2;
	else if (170 <= avg && avg < 350)
		scaling_factor = 1.6;
	else
		scaling_factor = 0.85;
	v = ft_3d_rotate_z(v, M_PI / 4.0);
	v = ft_3d_rotate_x(v, asin(tan(M_PI / 6.0)));
	r.x = scaling_factor * v.x + 300.0;
	r.y = scaling_factor * v.y + 200.0;
	return (r);
}

static t_pair		color_pair(int f, int s)
{
	t_pair p;

	p.f = f;
	p.s = s;
	return (p);
}

void				plot(t_controller *ctrl)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ctrl->data_rows - 1)
	{
		j = 0;
		while (j < ctrl->data_cols - 1)
		{
			draw_line(ctrl, iso(ctrl, i, j), iso(ctrl, i, j + 1),
				color_pair(ctrl->color_data[i][j], ctrl->color_data[i][j + 1]));
			draw_line(ctrl, iso(ctrl, i, j), iso(ctrl, i + 1, j),
				color_pair(ctrl->color_data[i][j], ctrl->color_data[i][j + 1]));
			j++;
		}
		i++;
	}
}
