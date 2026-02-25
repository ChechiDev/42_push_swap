#include "libft.h"

static int	is_nbr(char *s)
{
	int	j;

	j = 0;
	while (s[j] == 32 || (s[j] >= 9 && s[j] <= 13))
		j++;
	if (s[j] == '-' || s[j] == '+')
		j++;
	if (s[j] == '\0')
		return (0);
	while (s[j])
	{
		if (!(s[j] >= '0' && s[j] <= '9'))
			return (0);
		j++;
	}
	return (1);
}

int	parse_num(char **av)
{
	int	i;
	int	nbrs;

	i = 0;
	nbrs = 0;
	while (av[i])
	{
		if (is_nbr(av[i]) == 0)
			return (0);
		nbrs++;
		i++;
	}
	if (nbrs == 0)
		return (0);
	return (1);
}
