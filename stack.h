//
// Created by Remi Robert on 09/03/2018.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

struct s_stack;

struct s_stack *make_stack(int);

int stack_length(struct s_stack *);

int stack_push(struct s_stack *, int);

int stack_pop(struct s_stack *);

#endif //STACK_STACK_H
