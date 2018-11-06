/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:42:17 by otel-jac          #+#    #+#             */
/*   Updated: 2018/10/31 22:08:57 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	grid_calc(fd);
	return (0);
}
