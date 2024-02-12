/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:05:26 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/12 20:50:23 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
    t_stack *stack_a;
    t_stack *stack_b;
    stack_b = NULL;

    stack_a = create_stack(11, NULL);
    push(&stack_a, create_stack(4, &stack_a));
    push(&stack_a, create_stack(6, &stack_a));
    push(&stack_a, create_stack(7, &stack_a));
    push(&stack_a, create_stack(1, &stack_a));
    print_stack(stack_a);
    
    ft_printf("\npush_swap \n");
    push_swap(&stack_a, &stack_b);

    ft_printf("\nStack a \n");
    print_stack(stack_a);
    ft_printf("\nStack b \n");
    print_stack(stack_b);
    
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