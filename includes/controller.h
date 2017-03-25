/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:42:02 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/17 15:52:08 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include <stdlib.h>
# include "libft.h"
# define WIN_SIZE_X 600
# define WIN_SIZE_Y 600

# define R_MASK 0xff0000
# define G_MASK 0x00ff00
# define B_MASK 0x0000ff

typedef struct	s_pair
{
	int			f;
	int			s;
}				t_pair;

typedef struct	s_controller
{
	void		*mlx;
	void		*win;
	char		*title;
	t_3d_vector	**data;
	int			**color_data;
	size_t		data_rows;
	size_t		data_cols;
}				t_controller;

t_controller	*ctrl_init(char *window_title);
void			ctrl_destroy(t_controller **ctrl);
int				read_file(t_controller *ctrl, int fd);
int				ctrl_key_hook(int keycode);

int				ft_get_rgb_data(char *token);

void			draw_line(t_controller *ctrl, t_2d_vector p0,
		t_2d_vector p1, t_pair color);

void			plot(t_controller *ctrl);

int				color_avg(t_pair color, double weight);

#endif
