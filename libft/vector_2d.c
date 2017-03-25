/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:54:57 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/27 13:28:25 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

/*
**	Translation of vector (tx, ty)
*/

t_2d_vector	ft_2d_translate(t_2d_vector v, double tx, double ty)
{
	v.x += tx;
	v.y += ty;
	return (v);
}

/*
**	Rotation about the origin of angle theta
*/

t_2d_vector	ft_2d_rotate(t_2d_vector v, double theta)
{
	t_2d_vector	ret;

	ret.x = cos(theta) * v.x - sin(theta) * v.y;
	ret.y = sin(theta) * v.x + cos(theta) * v.y;
	return (ret);
}

/*
**	Scaling of scaling factor (sx, sy)
*/

t_2d_vector	ft_2d_scale(t_2d_vector v, double sx, double sy)
{
	v.x *= sx;
	v.y *= sy;
	return (v);
}
