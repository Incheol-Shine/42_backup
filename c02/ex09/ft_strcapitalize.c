/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:53:14 by incshin           #+#    #+#             */
/*   Updated: 2022/01/19 21:18:17 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		ft_str_is_word(char *str, int i);

int	ft_str_is_word(char *str, int i)
{
	int	is_word_char;

	while (str[i] != '\0')
	{
		is_word_char = 0;
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			is_word_char = 1;
			str[i] += 'a' - 'A';
		}
		if ('0' <= str[i] && str[i] <= '9')
			is_word_char = 1;
		if ('a' <= str[i] && str[i] <= 'z')
			is_word_char = 1;
		if (!is_word_char)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] += 'A' - 'a';
			i++;
		}
		i = ft_str_is_word(str, i);
		i++;
	}
	return (str);
}
