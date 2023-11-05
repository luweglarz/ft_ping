#include "io.h"

void	ft_putnbr_hexa_fd(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 15)
	{
		ft_putnbr_hexa_fd(nbr / 16);
		ft_putnbr_hexa_fd(nbr % 16);
	}
	else if (nbr < 10)
		ft_putchar(nbr + '0');
	else
		ft_putchar(nbr - 10 + 'a');
}

