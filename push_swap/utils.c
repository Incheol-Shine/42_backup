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
	else if (err_no == MALLOC_ERR)
		ft_printf("init_stack / new_node : malloc error\n");
	else if (err_no == ATOI_ERR)
		ft_printf("atoi : not int type\n");
	exit(0);
}
/*
	else if (err_no == ALREADY_SORTED)
		ft_printf("already sorted\n");
*/

int	*str_to_int_arr(int size, char *argv[])
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

void	set_pivot(t_pivot *pivot, int a, int b, int c)
{
	pivot->one_third = a;
	pivot->a_half = b;
	pivot->two_third = c;
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	check_overlap_pivot(int size, int *numbers, t_pivot *pivot)
{
	int	num_cpy[size];
	int	i;
	int	flag;
	int	temp;

	temp = size;
	ft_memcpy(num_cpy, numbers, sizeof(int) * size);
	flag = 0;
	while (size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (num_cpy[i] == num_cpy[i + 1])
				print_error_exit(ARG_ERR);
			else if (num_cpy[i] > num_cpy[i + 1])
			{
				ft_swap(num_cpy + i, num_cpy + i + 1);
				flag = 1;
			}
			i++;
		}
		size--;
	}
	set_pivot(pivot, num_cpy[temp / 3], num_cpy[temp / 2], num_cpy[2 * temp / 3]);
	if (!flag)
		print_error_exit(ALREADY_SORTED);
}
