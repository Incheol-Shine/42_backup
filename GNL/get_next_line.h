/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:54 by incshin           #+#    #+#             */
/*   Updated: 2022/05/17 17:37:29 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 10
typedef struct	s_param
{
	struct s_list	**head;
}				t_param;
typedef	struct	s_list
{
	struct s_list	*next;
	size_t			offset;
	ssize_t			fd;
	ssize_t			rd_size;
	char			buff[BUFF_SIZE];
}				t_list;
char	*get_next_line(ssize_t fd);
t_list	*ft_lstnew(ssize_t fd);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **head, t_list *new);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	view(t_list *head);
void	lstdel(t_list *node);
void	cpydel(char *line, t_list **head, size_t size);

#endif
