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

int get_opts(int ac, char **av){
    int i = 1;
	t_list *addrs = NULL;
	t_list *opts = NULL;

	// should divide this function to make it proper
    while (i < ac){
		if (av[i][0] =='-' && av[i][1] != '\0'){
			int j = 1;
			while (av[i][j]){
				ft_lstadd_back(&opts,  ft_lstnew(&av[i][j]));
				j++;
			}
		}
		else
			ft_lstadd_back(&addrs, ft_lstnew(ft_strdup(av[i])));
		i++;
    }
	if (addrs == NULL){
		//print usage
		return (1);
	}
	char ret = parse_opts(&opts);
	if (ret > 0){
		// make an home made perror instead of printf
		printf("ft_ping: invalid option -- '%c'\n", ret);
		return (1);
	}
	//free opt list
    return 0;
}