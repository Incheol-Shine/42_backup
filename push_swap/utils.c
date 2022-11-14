#include "push_swap.h"

int	push_swap_atoi(const char *str)
{
	long	i;
	long	sign;
	long	answer;

	i = 0;
	sign = (str[i] != '-') * 2 - 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	answer = 0;
	while (ft_isdigit(str[i]))
	{
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] && (!ft_isdigit(str[i])))
		print_error_exit(ATOI_ERR);
	answer *= sign;
	if (answer > 2147483647 || answer < -2147483648)
		print_error_exit(ATOI_ERR);
	return ((int)answer);
}

void	print_error_exit(int err_no)
{
	if (err_no == ARG_ERR)
		ft_printf("main : arg error\n");	
	else if(err_no == MALLOC_ERR)
		ft_printf("init_stack / new_node : malloc error\n");
	else if (err_no == ATOI_ERR)
		ft_printf("atoi : not int type\n");
	// else if (err_no == ALREADY_SORTED)
	// 	ft_printf("already sorted\n");
	exit(0);
}

int *str_to_int_arr(int size, char *argv[])
{
	int	*numbers;
	int	i;

	numbers = (int *)malloc(sizeof(int) * (size));
	if (!numbers)
		print_error_exit(MALLOC_ERR);
	i = 0;
	while (i < size)
	{
		numbers[i] = push_swap_atoi(argv[i + 1]);
		i++;
	}
	return (numbers);
}

int	*check_overlap(int size, char *argv[])
{
	int	*numbers;
	int	i;
	int	j;
	int	flag;

	numbers = str_to_int_arr(size, argv);
	flag = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				print_error_exit(ARG_ERR);
			else if (numbers[i] > numbers[j])
				flag = 1;
			j++;
		}
		i++;
	}
	if (!flag)
		print_error_exit(ALREADY_SORTED);
	return (numbers);
}
