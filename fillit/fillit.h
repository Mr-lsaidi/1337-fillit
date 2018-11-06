/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 22:54:32 by otel-jac          #+#    #+#             */
/*   Updated: 2018/11/02 17:50:50 by lsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_cord
{
	int		x;
	int		y;
}					t_cord;

typedef struct		s_block
{
	char			l;
	t_cord			block[4];
	struct s_block	*next;
}					t_block;

void				ft_make_tetro(char *str, int k, t_block *b);
void				ft_cor_tetro(char *str, t_block *blocks, int i);
int					ft_check_caract(char *str);
void				ft_init(char grid[20][20], int size);
int					ft_place(char grid[20][20], t_block *b, int c, int r);
int					ft_unplace(char grid[20][20], t_block *b, int c, int r);
int					grid_calc(int fd);
void				ft_display(char grid[20][20]);
int					ft_fillit(int fd);
char				**check_err(int fd);
int					count_hach(char *str);
int					ft_check_hash(char *str);
int					ft_crawl(char *str, int i);
int					ft_brain(char grid[20][20], t_block *str, int size);
t_block				*ft_create_new_blocks(char *tab, int index);
void				ft_push_back_block(t_block **lst, t_block *new);
void				ft_delete_blocks(t_block **lst);
void				ft_error(void);
#endif
