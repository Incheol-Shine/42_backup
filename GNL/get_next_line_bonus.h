/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:54 by incshin           #+#    #+#             */
/*   Updated: 2022/05/26 18:13:53 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 100

typedef struct s_list
{
	struct s_list	*next;
	size_t			offset;
	ssize_t			fd;
	ssize_t			rd_size;
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
void	ft_lstclear(t_list **lst, ssize_t fd, int depth);
t_list	*ft_lstnew(ssize_t fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	lstdel(t_list *node);

#endif
