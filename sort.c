/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:30:16 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/13 13:56:54 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size;

    stack_size = get_stack_size(*stack_a);
    
    if (!is_stack_sorted(*stack_a))
    {
        if (stack_size == 2)
            swap(*stack_a, 1, 'a');    
        else if (stack_size == 3)
            sort_three(stack_a);
        else
            sort(stack_a, stack_b);
    }
}

void    sort(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size_a;
    
    stack_size_a = get_stack_size(*stack_a);
    if (stack_size_a-- > 3 && !is_stack_sorted(*stack_a))
        push_to(stack_a, stack_b, 1, 'b');
    if (stack_size_a-- > 3 && !is_stack_sorted(*stack_a))
        push_to(stack_a, stack_b, 1, 'b');
    
    while (stack_size_a-- > 3 && !is_stack_sorted(*stack_a))
    {
        update_nodes_a(*stack_a, *stack_b);
        push_a_to_b(stack_a, stack_b);
    }
    sort_three(stack_a);

    while (*stack_b)
    {
        update_nodes_b(*stack_a, *stack_b);
        prepare_push(stack_a, ((t_stack_data *)(*stack_b)->content)->target_node, 'a');
        push_to(stack_b, stack_a, 1, 'a');
    }
    update_index(*stack_a);
    set_min_on_top(stack_a);
}

void    sort_three(t_stack **stack)
{
    if (get_value(*stack) == get_max(*stack))
        rotate(stack, 1, 'a');
    else if (get_value((*stack)->next) == get_max(*stack))
        reverse_rotate(stack,1, 'a');
    if (get_value(*stack) > get_value((*stack)->next))
        swap(*stack, 1, 'a');
}