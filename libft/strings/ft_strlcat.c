#include "strings.h"

static unsigned int	ft_strnlen(char *str, unsigned int size)
{
	unsigned int a;

	a = 0;
	while (str[a] != '\0' && a < size)
	{
		a++;
	}
	return (a);
}

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int tdest;

	i = 0;
	tdest = ft_strnlen(dst, dstsize);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize == tdest)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (tdest + i) < dstsize - 1)
	{
		dst[tdest + i] = src[i];
		i++;
	}
	dst[tdest + i] = '\0';
	return (tdest + ft_strlen(src));
}
