#ifndef LISTS_H
# define LISTS_H

#include <stdlib.h>
#include "../memory/memory.h"

typedef struct  s_list{
    void            *content;
    struct s_list   *next;
}               t_list;

t_list      *ft_lstnew(void *content);
int         ft_lstsize(t_list *list);
t_list      *ft_lstlast(t_list *list);
void        ft_lstadd_back(t_list **list, t_list *newElem);
void        ft_lstdone(t_list *list, void (*del)(void*));
void        ft_lstclear(t_list **list, void(*del)(void*));
void        ft_lstiter(t_list *list, void (*f)(void*));
void        ft_lstadd_front(t_list **list, t_list *new);

#endif