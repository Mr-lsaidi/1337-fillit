/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:26 by otel-jac          #+#    #+#             */
/*   Updated: 2018/11/02 17:44:32 by lsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place(char grid[20][20], t_block *b, int y, int x)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (grid[y + b->block[i].y][x + b->block[i].x] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[y + b->block[i].y][x + b->block[i].x] == '.')
			grid[y + b->block[i].y][x + b->block[i].x] = b[0].l;
		i++;
	}
	return (1);
}

int		ft_unplace(char grid[20][20], t_block *b, int y, int x)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (grid[y + b->block[i].y][x + b->block[i].x] != '.')
			grid[y + b->block[i].y][x + b->block[i].x] = '.';
		i++;
	}
	return (0);
}

void	ft_init(char grid[20][20], int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
			grid[i][j++] = (i < size && j < size) ? '.' : '0';
		i++;
	}
}

int		ft_brain(char grid[20][20], t_block *t, int size)
{
	int		i[2];

	i[0] = -1;
	while (grid[++i[0]][0] != '0')
	{
		i[1] = -1;
		while (grid[i[0]][++i[1]] != '0')
		{
			if (ft_place(grid, t, i[0], i[1]) == 1)
			{
				if (!t->next)
					return (1);
				if (ft_brain(grid, t->next, size) == 1)
					return (1);
				else
					ft_unplace(grid, t, i[0], i[1]);
			}
		}
	}
	if (t && t->l == 'A')
	{
		ft_init(grid, size + 1);
		ft_brain(grid, t, size + 1);
	}
	return (0);
}

int		grid_calc(int fd)
{
	int		i;
	char	grid[20][20];
	t_block	*lst;
	char	**tab;

	lst = NULL;
	tab = NULL;
	i = 0;
	if ((tab = check_err(fd)) == NULL)
		ft_error();
	while (tab[i])
	{
		ft_push_back_block(&lst, ft_create_new_blocks(tab[i], i));
		i++;
	}
	ft_init(grid, 0);
	ft_brain(grid, lst, 0);
	ft_display(grid);
	ft_delete_blocks(&lst);
	return (1);
}
