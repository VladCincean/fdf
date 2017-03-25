/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:51:03 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/25 14:05:17 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>
#define KEYCODE_ESC 53

int				ctrl_key_hook(int keycode)
{
	if (keycode == KEYCODE_ESC)
	{
		exit(0);
	}
	return (1);
}

t_controller	*ctrl_init(char *window_title)
{
	t_controller	*ctrl;

	if ((ctrl = (t_controller *)malloc(sizeof(t_controller))) == NULL)
		return (NULL);
	ctrl->mlx = mlx_init();
	ctrl->title = ft_strdup(window_title);
	ctrl->win = mlx_new_window(ctrl->mlx, WIN_SIZE_X, WIN_SIZE_Y, ctrl->title);
	mlx_key_hook(ctrl->win, ctrl_key_hook, NULL);
	ctrl->data = NULL;
	ctrl->color_data = NULL;
	ctrl->data_rows = 0;
	ctrl->data_cols = 0;
	return (ctrl);
}

void			ctrl_destroy(t_controller **ctrl)
{
	size_t	i;

	if (ctrl == NULL || *ctrl == NULL)
		return ;
	i = 0;
	while (i < (*ctrl)->data_rows)
	{
		ft_memdel((void **)&(*ctrl)->data[i]);
		ft_memdel((void **)&(*ctrl)->color_data[i]);
		i++;
	}
	ft_memdel((void **)&(*ctrl)->data);
	ft_memdel((void **)&(*ctrl)->color_data);
	mlx_destroy_window((*ctrl)->mlx, (*ctrl)->win);
	ft_memdel((void **)&(*ctrl)->title);
	ft_memdel((void **)ctrl);
}
