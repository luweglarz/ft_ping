#include "ft_ping.h"
#include "args.h"

int main(int ac, char **av){

    if (ac >= 1){
        if (get_opts(ac, av) == 1)
            return (1);
    }
    else{
        // Show usage
        return (2);
    }
    printf("options: %d\n", options);
    return (0);
}