
#include "libft.h"

void	ft_write(int fd, char *s, int len)
{
	ssize_t	ret;

	ret = write(fd, s, len);
	(void)ret;
}
