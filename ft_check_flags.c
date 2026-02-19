#include "../include/libft.h"

int	check_flags(int ac, char **av, t_flags flags)
{
	int	i;
	int	f;

	i = 1;
	f = 0;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (ft_strcmp(av[i], "--bench") == 0 && !flags.bench)
			flags.bench = 1;
		else if (ft_strcmp(av[i], "--simple") == 0 && !flags.simple && !f)
			flags.simple = 1;
		else if (ft_strcmp(av[i], "--medium") == 0 && !flags.medium && !f)
			flags.medium = 1;
		else if (ft_strcmp(av[i], "--complex") == 0 && !flags.complex && !f)
			flags.complex = 1;
		else if (ft_strcmp(av[i], "--adaptative") == 0 && !flags.adaptative && !f)
			flags.adaptative = 1;
		else
			return (-1);
		if (ft_strcmp(av[i], "--bench") != 0)
			f = 1;
		i++;
	}
	return (i);
}
