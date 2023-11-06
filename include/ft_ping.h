#ifndef FT_PING
# define FT_PING

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#include "libft.h"

extern t_list *addrs;

void print_usage();

#endif