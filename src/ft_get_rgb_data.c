/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rgb_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:55:28 by vcincean          #+#    #+#             */
/*   Updated: 2017/03/17 15:43:32 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "libft.h"
#include <stdlib.h>

static int	hexa_to_dec(char digit)
{
	if ('a' <= digit && digit <= 'f')
		return (10 + digit - 'a');
	if ('A' <= digit && digit <= 'F')
		return (10 + digit - 'A');
	return (digit - '0');
}

int			ft_get_rgb_data(char *token)
{
	size_t	i;
	int		color;

	color = 0;
	if (!token)
		return (0);
	i = 0;
	while (token[i] && ft_isspace(token[i]))
		i++;
	if (token[i] == '+' || token[i] == '-')
		i++;
	while (token[i] && ft_isdigit(token[i]))
		i++;
	if (token[i] != ',' || token[i + 1] != '0' || token[i + 2] != 'x')
		return (0xffffff);
	i += 3;
	while (token[i] && ft_isxdigit(token[i]))
	{
		color = color * 16 + hexa_to_dec(token[i]);
		i++;
	}
	return (color);
}
