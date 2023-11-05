#ifndef IO_H
# define IO_H

#include <unistd.h>

void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr(char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void	    ft_putnbr(int nb);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr_hexa_fd(int nb);

#endif