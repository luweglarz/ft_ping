#ifndef ARGS_H
# define ARGS_H

typedef enum    s_options{
    v = 1,
    f = 2,
    n = 4,
    w = 6,
    s = 8,
    T = 10,
}               e_options;

e_options options;

int     parse_args(int ac, char **av);

#endif