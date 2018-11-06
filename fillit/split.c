/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:37:15 by otel-jac          #+#    #+#             */
/*   Updated: 2018/11/02 17:21:52 by lsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

char	**split_line(char *str)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 1])
			str[i + 1] = '\t';
		i++;
	}
	if (str[i - 1] == '\t')
		ft_error();
	temp = ft_strsplit(str, '\t');
	return (temp);
}

char	**get_tetro(int fd)
{
	int		j;
	char	buff[5500];
	char	*ret;
	char	**temp;

	ret = ft_strnew(1);
	while ((j = read(fd, buff, 5500)) > 0)
	{
		buff[j] = '\0';
		ret = ft_strjoin(ret, buff);
	}
	if (ret[0] == '\0')
		ft_error();
	temp = split_line(ret);
	return (temp);
}

char	**check_err(int fd)
{
	int		i;
	int		k;
	char	**temp;

	k = 0;
	temp = get_tetro(fd);
	while (temp[k])
	{
		if (count_hach(temp[k]) == -1 || ft_check_caract(temp[k]) == 1)
			ft_error();
		i = 0;
		while (temp[k][i] != '#')
			i++;
		ft_crawl(temp[k], i);
		if (ft_check_hash(temp[k]) == 1)
			ft_error();
		k++;
	}
	return (temp);
}
