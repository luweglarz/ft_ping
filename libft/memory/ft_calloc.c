#include "memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	int		total;

	total = nmemb * size;
	if (!(str = malloc(total)))
		return (NULL);
	ft_bzero(str, total);
	return (str);
}
