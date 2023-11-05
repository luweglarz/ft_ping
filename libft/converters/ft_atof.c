#include "converters.h"

float	ft_atof(char *nptr)
{
	float	ent;
	float	dec;
	int		size;
	char	tmp;

	tmp = nptr[0];
	ent = (float)ft_atoi(nptr);
	while (*nptr && *nptr != '.')
		nptr++;
	if (*nptr == '.')
		nptr++;
	dec = (float)(ft_atoi(nptr));
	size = ft_strlen(nptr);
	while (size--)
		dec /= 10;
	if (ent <= 0 && tmp == '-')
		return ((ent + -dec));
	return ((ent + dec) * 1);
}
