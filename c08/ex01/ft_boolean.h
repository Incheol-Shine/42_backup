/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:16:36 by incshin           #+#    #+#             */
/*   Updated: 2022/01/26 15:16:38 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define	FT_BOOLEAN_H

# include	<unistd.h>
# define	TRUE 1
# define	FALSE 0
# define	SUCCESS 0
# define	EVEN(nbr) (nbr % 2 == 0)
# define	EVEN_MSG "I have an even number of arguments.\n"
# define	ODD_MSG "I have an odd number of arguments.\n"
typedef int	t_bool;

#endif
