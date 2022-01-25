#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strcmp(char s1, char s2);
void	ft_go_nl(int *fd, int *i);
char	*ft_parse_dict(char *str, char *dictpath);
int		check_arg(int argc, char **argv);
int		gest_argv(int argc, char **argv, char **nb, char **dictpath);

#endif
