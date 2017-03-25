/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:20:13 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/25 12:08:37 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include <math.h>

int	color_avg(t_pair color, double weight)
{
	int	r;
	int	g;
	int	b;

	r = ((int)floor(weight * (double)(color.f & R_MASK) +
			(1.0 - weight) * (double)(color.s & R_MASK))) >> 16;
	g = ((int)floor(weight * (double)(color.f & G_MASK) +
			(1.0 - weight) * (double)(color.s & G_MASK))) >> 8;
	b = (int)floor(weight * (double)(color.f & B_MASK) +
			(1.0 - weight) * (double)(color.s & B_MASK));
	return ((r << 16) | (g << 8) | b);
}
