
#include "libft.h"

int	ft_error(void)
{
	ssize_t	ret;

	ret = write(2,"Error\n", 6);
	(void)ret;
	return (0);
}
