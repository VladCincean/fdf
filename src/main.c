/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:18:30 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/25 14:03:43 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "libft.h"
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>

void	f_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	f_usage(char *argv0)
{
	ft_putstr("usage: ");
	ft_putstr(argv0);
	ft_putstr(" <input file>\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_controller	*ctrl;
	int				fd;

	if (argc != 2)
		f_usage(argv[0]);
	ctrl = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1 ||
		(ctrl = ctrl_init(ft_strjoin("fdf | ", argv[1]))) == NULL ||
		read_file(ctrl, fd) == 0)
		f_error("Error: invalid file of file does not exist");
	close(fd);
	plot(ctrl);
	mlx_loop(ctrl->mlx);
	return (0);
}
