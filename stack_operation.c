/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:01:05 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/12 20:41:50 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack    *stack, int print, char c)
{
    t_stack_data    *tmp;
    t_stack *next;
    if (get_stack_size(stack) <= 1)
        return ;
    
    tmp = (t_stack_data *) stack->content;
    next = (t_stack *) stack->next;
    stack->content = next->content;
    next->content = tmp;
    if (print == 1)
        ft_printf("s%c\n", c);
}

void    push_to(t_stack **from, t_stack **to, int print, char c)
{
    if (print)
        ft_printf("p%c\n", c);
    push(to, create_stack(pop(from), to));
}

void    rotate(t_stack **stack, int rotate, char c)
{
    t_stack *tmp;
    
    tmp = create_stack(pop(stack), stack);
    ft_lstadd_back(stack, tmp);
    if (rotate == 1)
        ft_printf("r%c\n", c);
}

void    reverse_rotate(t_stack **stack, int print, char c)
{
    t_stack *tmp;

    tmp = create_stack(get_value(ft_lstlast(*stack)), stack);
    remove_last(stack);
    push(stack, tmp);
    if (print == 1)
        ft_printf("rr%c\n", c);
}

void    remove_last(t_stack **stack)
{
    t_stack *head;
    t_stack *next;

    head = *stack;
    next = head;
    while (next->next->next)
    {
        next = next->next;
    }
    free(next->next->content);
    free(next->next);
    next->next = NULL;
}