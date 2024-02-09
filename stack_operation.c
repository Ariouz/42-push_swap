/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:01:05 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/09 12:40:48 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack    *stack)
{
    t_stack_data    *tmp;
    t_stack *next;
    if (stack_size(stack) <= 1)
        return ;
    
    tmp = (t_stack_data *) stack->content;
    next = (t_stack *) stack->next;
    stack->content = next->content;
    next->content = tmp;
}

void    push_to(t_stack **from, t_stack **to)
{
    push(to, create_stack(pop(from)));
}

void    rotate(t_stack **stack)
{
    t_stack *tmp;
    
    tmp = create_stack(pop(stack));
    ft_lstadd_back(stack, tmp);
}

void    reverse_rotate(t_stack **stack)
{
    t_stack *tmp;

    tmp = create_stack(get_value(ft_lstlast(*stack)));
    remove_last(stack);
    push(stack, tmp);
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