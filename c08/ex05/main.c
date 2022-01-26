#include "ft_stock_str.h"

void    			ft_show_tab(struct s_stock_str *par);
struct s_stock_str  *ft_strs_to_tab(int ac, char **av);

int	main(int argc, char **argv)
{
	if (argc == 1)
		argc = 1;
	ft_show_tab(ft_strs_to_tab(argc, argv));
	return (0);
}
