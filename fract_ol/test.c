#include <stdio.h>

typedef struct s_sub
{
	int a;
}				t_sub;

typedef struct s_strt
{
	int a;
	t_sub sub;
}				t_strt;	

void f(t_strt *c)
{
	c->a = 10;
}

int main(void)
{
	t_strt c;

	c.sub.a = 3;
	f(&(c.sub));
	printf("c.sub.a = %d\n", c.sub.a);
	
	return 0;
}