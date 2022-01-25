#include "rush02.h"

int	ft_strcmp(char s1, char s2)
{
	int	i;

	i = 0;
	while (s1 != '\0' || s2 != '\0')
	{
		if (s1 > s2)
			return (1);
		else if (s2 > s1)
			return (-1);
		i++;
	}
	if (s2 != '\0')
		return (-1);
	else if (s1 != '\0')
		return (1);
	else
		return (0);
}

void	ft_go_nl(int *fd, int *i)
{
	char	buf;

	while (read(*fd, &buf, 1))
	{
		if (buf == '\n')
			break ;
	}
	*i = 0;
}

char	*ft_parse_dict(char *str, char *dictpath)
{
	int		fd;
	int		i;
	char	buf;
	char	*result;

	fd = open(*dictpath, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &buf, 1))
	{
		if (str[i] != buf && str[i] != '\0')
		{
			ft_go_nl(&fd, &i);
			continue ;
		}
		if ((buf == ' ' || buf == ':') && str[i] != '\0')
		{
			i = 0;
			while (buffer != '\n')
			{
				str[i] = buffer;
				i++;
				read(fd, &buffer, 1);
			}
			str[i] = '\0';
			return (str);
		}
		if (str[i] == '\0')
		{
			ft_go_nl(&fd, &i);
			continue ;
		}
		i++;
	}
	return (result);
}
