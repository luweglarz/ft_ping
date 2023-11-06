#include "args.h"
#include "ft_ping.h"

static char parse_opts(t_list **opts){
    while((*opts)){
        if (*((char*)((*opts)->content)) == 'v')
            options |= v;
		else if (*((char*)((*opts)->content)) == 'f')
            options |= f;
		else if (*((char*)((*opts)->content)) == 'n')
            options |= n;
		else if (*((char*)((*opts)->content)) == 'w')
            options |= w;
		else if (*((char*)((*opts)->content)) == 's')
            options |= s;
		else if (*((char*)((*opts)->content)) == 'T')
            options |= T;
		else
			return (*((char*)((*opts)->content)));
       	(*opts) = (*opts)->next;
    }
	return (0);
}

static int fill_opts(t_list **opts){
	char ret = parse_opts(&(*opts));
	t_list *tmpList;

	if (ret > 0){
		printf("ft_ping: invalid option -- '%c'\n", ret);
		print_usage();
		return (1);
	}
	while(*opts){
        tmpList = (*opts)->next;
        free(*opts);
        *opts = tmpList;
    }
	return (0);
}

static int parse_string_addrs(t_list **string_addrs){
	//((char*)((*string_addrs)->content))
	struct addrinfo hints;
    struct addrinfo *addrinfo;
	t_list *addrs = NULL;

	while((*string_addrs)){
		memset(&hints, 0, sizeof(struct addrinfo));
		hints.ai_family = AF_UNSPEC;
    	hints.ai_socktype = SOCK_STREAM;

		if (getaddrinfo(((char*)((*string_addrs)->content)), NULL, &hints, &addrinfo) != 0){
			printf("ft_ping: Unknown host: %s\n", ((char*)((*string_addrs)->content)));
			return (1);
		}
		else
			ft_lstadd_back(&addrs, ft_lstnew(addrinfo));
       	(*string_addrs) = (*string_addrs)->next;
    }
	return (0);
}

static int fill_addrs(t_list **string_addrs){
	if (*string_addrs == NULL){
		print_usage();
		return (1);
	}
	if (parse_string_addrs(&(*string_addrs)) == 1)
		return (1);
	ft_lstclear(&(*string_addrs), &free);
	return (0);
}

int parse_args(int ac, char **av){
    int i = 1;
	t_list *string_addrs = NULL;
	t_list *opts = NULL;

    while (i < ac){
		if (av[i][0] =='-' && av[i][1] != '\0'){
			int j = 1;
			while (av[i][j]){
				ft_lstadd_back(&opts,  ft_lstnew(&av[i][j]));
				j++;
			}
		}
		else
			ft_lstadd_back(&string_addrs, ft_lstnew(ft_strdup(av[i])));
		i++;
    }
	if (fill_opts(&opts) == 1)
		return (1);
	if (fill_addrs(&string_addrs) == 1)
		return (1);
    return 0;
}