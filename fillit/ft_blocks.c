/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:04:30 by lsaidi            #+#    #+#             */
/*   Updated: 2018/11/02 17:12:37 by lsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block		*ft_create_new_blocks(char *tab, int index)
{
	t_block	*new;
	int		i;
	int		j;
	int		k;

	if ((new = (t_block *)malloc(sizeof(*new))))
	{
		i = -1;
		k = 0;
		while (tab[++i])
		{
			if (tab[i] == '@')
			{
				j = k ? j : i;
				new->block[k].x = (i % 5) - (j % 5);
				new->block[k].y = (i / 5) - (j / 5);
				k++;
			}
		}
		new->l = 'A' + index;
		new->next = NULL;
	}
	return (new);
}

void		ft_push_back_block(t_block **lst, t_block *new)
{
	t_block *p;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void		ft_delete_blocks(t_block **lst)
{
	t_block	*p;

	p = *lst;
	while (p)
	{
		*lst = (*lst)->next;
		free(p);
		p = *lst;
	}
	lst = NULL;
}
