#include "memory.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (ptrd > ptrs)
		while (n-- > 0)
			*(ptrd + n) = *(ptrs + n);
	else
		while (n-- > 0)
			*ptrd++ = *ptrs++;
	return (dest);
}
