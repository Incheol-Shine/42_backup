#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
int		is_sep(char c, char *charset);
int		ft_strlen(char *str);
int		ft_destsize(char *str, char *charset);
void	ft_strncpy(char *dest, char *src, int n);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		cnt;
	int		size;
	char	**dest;

	size = ft_destsize(str, charset);
	printf("size done! %d\n",size);
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		cnt = 0;
		while(!is_sep(str[i + cnt], charset))
		{
			cnt++;
		}
		if (cnt)
		{
			printf("j:%d cnt:%d\n",j,cnt);
			dest[j] = (char *)malloc(sizeof(char) * (cnt + 1));
			if (!(dest[j]))
				return (0);
			ft_strncpy(dest[j], str + i, cnt);
			j++;
		}
		else
			i++;
		i += cnt;
	}
	dest[j] = NULL;
	return (dest);
}

int		ft_destsize(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
		{
			if(str[i + 1] && !(is_sep(str[i + 1], charset)))
				size ++;
		}
		else if (i == 0)
			size ++;
		i++;
	}
	return (size);
}

int	is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int main(void)
{
	char *str = "1asdf2zxcv3xc4pw5";
	char *charset = "12345";
	char **dest;

	int i;
	int j;

	dest = ft_split(str, charset);
	i = 0;
	while (dest[i] != NULL)
	{
		printf("%s\n", dest[i]);
		free(dest[i]);
		i++;
	}
	free(dest);
	return (0);
}