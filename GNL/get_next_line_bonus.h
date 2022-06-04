/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:54 by incshin           #+#    #+#             */
/*   Updated: 2022/06/02 17:11:15 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	struct s_list	*next;
	size_t			offset;
	ssize_t			fd;
	ssize_t			ret_read;
	char			*buff;
}				t_list;
typedef struct s_param
{
	int		flag;
	char	*line;
}				t_param;
char	*get_next_line(ssize_t fd);
ssize_t	get_size(t_list **head, ssize_t fd);
ssize_t	get_size_part1(t_list **head, t_list *temp, ssize_t fd, ssize_t *size);
ssize_t	get_size_part2(t_list **head, t_list *temp, ssize_t fd, ssize_t *size);
char	*cpy_line(t_list *head, ssize_t size, ssize_t fd);
void	lstclear(t_list **lst, ssize_t fd);
void	lstclear2(t_list *lst, ssize_t fd);
t_list	*lstnew(ssize_t fd);
void	lstadd_back(t_list **lst, t_list *new);
void	lstdel(t_list *node);
#endif
