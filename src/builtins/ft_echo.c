#include "forty_two_sh.h"

void	print_args(char **str, int i)
{
	while (str[i])
	{
		ft_printf(1, "%s", str[i]);
		if (str[i + 1])
			ft_printf(1, " ");
		++i;
	}
}

int	ft_echo(char **args, t_vector *red)
{
	int	i;
	int	opt_n;

	i = 1;
	opt_n = 0;
	(void)red;
	if (write(1, NULL, 0) == -1)
	{
		ft_putstr_fd("42sh: echo: write error: Bad file descriptor\n", 2);
		g_exit_status = 1;
		return (g_exit_status);
	}
	while (args[i] && !ft_strcmp("-n", args[i]))
	{
		opt_n = 1;
		i++;
	}
	print_args(args, i);
	if (opt_n == 0)
		ft_printf(1, "\n");
	g_exit_status = 0;
	return (g_exit_status);
}
