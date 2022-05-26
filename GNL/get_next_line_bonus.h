/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:54 by incshin           #+#    #+#             */
/*   Updated: 2022/05/26 17:18:35 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 42
typedef	struct	s_list
{
	struct s_list	*next;
	size_t			offset;
	ssize_t			fd;
	ssize_t			rd_size;
	char			*buff;
}				t_list;
char	*get_next_line(ssize_t fd);
t_list	*ft_lstnew(ssize_t fd);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **head, t_list *new);
void	view(t_list *head);
void	lstdel(t_list *node);
ssize_t	get_size(t_list **head, ssize_t fd);
char	*cpy_line(t_list **head, ssize_t size, ssize_t fd);
void	ft_lstclear(t_list **lst, ssize_t fd);

#endif
