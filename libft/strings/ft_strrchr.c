#include "strings.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	if (c == 0)
		return ((char *)s + size);
	while (size > 0)
	{
		size--;
		if (s[size] == (char)c)
			return ((char *)s + size);
	}
	return (0);
}
