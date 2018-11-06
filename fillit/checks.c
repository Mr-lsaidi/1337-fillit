/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:46:00 by otel-jac          #+#    #+#             */
/*   Updated: 2018/10/31 03:35:11 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_crawl(char *str, int i)
{
	str[i] = '@';
	if (i - 5 > 0 && str[i - 5] == '#')
		ft_crawl(str, i - 5);
	if (i - 1 > 0 && str[i - 1] == '#')
		ft_crawl(str, i - 1);
	if (str[i + 1] && str[i + 1] == '#')
		ft_crawl(str, i + 1);
	if (str[i + 5] && str[i + 5] == '#')
		ft_crawl(str, i + 5);
	return (0);
}

int		ft_check_hash(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int		count_hach(char *str)
{
	int i;
	int err[3];

	err[0] = 0;
	err[1] = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		err[2] = 0;
		while (str[i] != '\n' && str[i] != '\0')
		{
			err[2]++;
			if (str[i] == '#')
				err[0] = err[0] + 1;
			i++;
		}
		if (err[2] != 4)
			return (-1);
		if (str[i] == '\n')
			err[1]++;
	}
	if (err[1] != 4 || err[0] != 4)
		return (-1);
	return (0);
}

int		ft_check_caract(char *str)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (1);
	}
	return (0);
}
