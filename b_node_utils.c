/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_node_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:24:40 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/13 09:41:05 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    update_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
    update_index(stack_a);
    update_index(stack_b);
    update_target_node_b(stack_a, stack_b);
}

void    update_target_node_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack         *a_cursor;
    t_stack         *target_node;
    t_stack_data    *a_data;
    t_stack_data    *b_data;
    long            best_target;
    
    while (stack_b)
    {
        b_data = (t_stack_data *) stack_b->content;
        best_target = LONG_MAX;
        a_cursor = stack_a;
        while (a_cursor)
        {
            a_data = (t_stack_data *) a_cursor->content;
            if (a_data->value > b_data->value && a_data->value < best_target)
            {
                best_target = a_data->value;
                target_node = a_cursor;
            }
            a_cursor = a_cursor->next;
        }
        if (best_target == LONG_MAX)
            b_data->target_node = get_min_node(stack_a);
        else
            b_data->target_node = target_node;
        stack_b = stack_b->next;
    }
}