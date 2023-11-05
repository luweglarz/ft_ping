#include "memory.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char*)dest;
	ptrs = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrs[i] == (unsigned char)c)
			return (ptrd + i + 1);
		i++;
	}
	return (NULL);
}
