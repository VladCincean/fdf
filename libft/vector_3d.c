/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:09:06 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/27 13:28:35 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

/*
**	Translation of vector (tx, ty, tz)
*/

t_3d_vector	ft_3d_translate(t_3d_vector v, double tx, double ty, double tz)
{
	v.x += tx;
	v.y += ty;
	v.z += tz;
	return (v);
}

/*
**	Rotation about the x-axis of angle theta
*/

t_3d_vector	ft_3d_rotate_x(t_3d_vector v, double theta)
{
	t_3d_vector	ret;

	ret.x = v.x;
	ret.y = cos(theta) * v.y - sin(theta) * v.z;
	ret.z = sin(theta) * v.y + cos(theta) * v.z;
	return (ret);
}

/*
**	Rotation about the y-axis of angle theta
*/

t_3d_vector	ft_3d_rotate_y(t_3d_vector v, double theta)
{
	t_3d_vector	ret;

	ret.x = cos(theta) * v.x + sin(theta) * v.z;
	ret.y = v.y;
	ret.z = -sin(theta) * v.x + cos(theta) * v.z;
	return (ret);
}

/*
**	Rotation about the z-axis of angle theta
*/

t_3d_vector	ft_3d_rotate_z(t_3d_vector v, double theta)
{
	t_3d_vector	ret;

	ret.x = cos(theta) * v.x - sin(theta) * v.y;
	ret.y = sin(theta) * v.x + cos(theta) * v.y;
	ret.z = v.z;
	return (ret);
}

/*
**	Scaling of scaling factor (sx, sy, sz)
*/

t_3d_vector	ft_3d_scale(t_3d_vector v, double sx, double sy, double sz)
{
	v.x *= sx;
	v.y *= sy;
	v.z *= sz;
	return (v);
}
