#ifndef CONVERTERS_H
# define CONVERTERS_H

#include <stdlib.h>
#include "../strings/strings.h"

int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_itoa(int n);
int			ft_atoi(const char *nptr);
float	    ft_atof(char *nptr);

#endif