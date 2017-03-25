/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:51:30 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/25 14:04:39 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include <math.h>
#include <mlx.h>

/*
**	This function is unprotected.
*/

static void		ft_swap(double *a, double *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}

static char		get_steep(t_2d_vector *p0, t_2d_vector *p1)
{
	char	steep;

	steep = 0;
	if (fabs(p0->x - p1->x) < fabs(p0->y - p1->y))
	{
		ft_swap(&(p0->x), &(p0->y));
		ft_swap(&(p1->x), &(p1->y));
		steep = 1;
	}
	if (p0->x > p1->x)
	{
		ft_swap(&(p0->x), &(p1->x));
		ft_swap(&(p0->y), &(p1->y));
	}
	return (steep);
}

static double	denom(double p0, double p1)
{
	if (fabs(p1 - p0) < 0.005)
		return (1);
	return (p1 - p0);
}

void			draw_line(t_controller *ctrl, t_2d_vector p0, t_2d_vector p1,
		t_pair color)
{
	char		s;
	double		error;
	double		derror;
	t_2d_vector	p;

	s = get_steep(&p0, &p1);
	derror = fabs((p1.y - p0.y) / (double)(p1.x - p0.x));
	error = 0.0;
	p.y = p0.y;
	p.x = p0.x;
	while (p.x <= p1.x)
	{
		mlx_pixel_put(ctrl->mlx, ctrl->win, s * p.y + (1 - s) * p.x, s * p.x
		+ (1 - s) * p.y, color_avg(color, (p1.x - p.x) / denom(p0.x, p1.x)));
		error += derror;
		if (error > 0.5)
		{
			if (p1.y > p0.y)
				p.y += 1;
			else
				p.y -= 1;
			error -= 1.0;
		}
		p.x++;
	}
}
