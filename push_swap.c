/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:05:26 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/13 13:56:41 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
    t_stack *stack_a;
    t_stack *stack_b;
    stack_b = NULL;

    stack_a = create_stack(10, NULL);

    (void) stack_b;
    push(&stack_a, create_stack(5, &stack_a));
    push(&stack_a, create_stack(42, &stack_a));
    push(&stack_a, create_stack(100, &stack_a));
    push(&stack_a, create_stack(0, &stack_a));
    push(&stack_a, create_stack(70, &stack_a));
    push(&stack_a, create_stack(1, &stack_a));
    push(&stack_a, create_stack(4, &stack_a));
    push(&stack_a, create_stack(9, &stack_a));
    push(&stack_a, create_stack(-15, &stack_a));
    push(&stack_a, create_stack(-14, &stack_a));
    push(&stack_a, create_stack(24, &stack_a));
    
    push_swap(&stack_a, &stack_b);
    
    print_stack(stack_a);

    cleanup(stack_a);
    cleanup(stack_b);
    free(stack_b);
    return (0);
}

void    cleanup(t_stack *stack)
{
    t_stack *cursor;
    t_stack *tmp;

    cursor = stack;
    while (cursor)
    {
        free(cursor->content);
        tmp = cursor->next;
        free(cursor);
        cursor = tmp;
    }
}