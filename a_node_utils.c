/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_node_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:15:57 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/13 13:55:54 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    update_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("update node a\n");
    update_index(stack_a);
    update_index(stack_b);
    update_target_node_a(stack_a, stack_b);
    update_cost_a(stack_a, stack_b);
    update_cheapest(stack_a);
}

void    update_target_node_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack         *b_cursor;
    t_stack         *target_node;
    t_stack_data    *a_data;
    t_stack_data    *b_data;
    long            best_target;
    
    while (stack_a)
    {
        a_data = (t_stack_data *) stack_a->content;
        best_target = LONG_MIN;
        b_cursor = stack_b;
        while (b_cursor)
        {
            b_data = (t_stack_data *) b_cursor->content;
            if (b_data->value < a_data->value && b_data->value > best_target)
            {
                best_target = b_data->value;
                target_node = b_cursor;
            }
            b_cursor = b_cursor->next;
        }
        if (best_target == LONG_MIN)
        {
            ft_printf("stack b size %d\n", get_stack_size(stack_b));
            a_data->target_node = get_max_node(stack_b);
        }
        else
            a_data->target_node = target_node;
        stack_a = stack_a->next;
    }
}

void    update_cost_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack_data *data;
    int size_a;
    int size_b;

    size_a = get_stack_size(stack_a);
    size_b = get_stack_size(stack_b);
    if (!stack_a)
        return ;
    while (stack_a)
    {
        data = (t_stack_data *) stack_a->content;
        data->push_cost = data->index;
        if (data->above_median == 0)
            data->push_cost = size_a - data->index;
        if (((t_stack_data *) data->target_node->content)->above_median == 1)
            data->push_cost += ((t_stack_data *) data->target_node->content)->index;
        else
            data->push_cost += size_b - ((t_stack_data *) data->target_node->content)->index;
        stack_a = stack_a->next;
    }
}

void    push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest;
    t_stack_data *cheapest_data;

    cheapest = get_cheapest(*stack_a);
    cheapest_data = (t_stack_data *)cheapest->content;
    if (cheapest_data->above_median == 1 && ((t_stack_data *)cheapest_data->target_node->content)->above_median == 1)
        rotate_both(stack_a, stack_b, cheapest);
    else if (cheapest_data->above_median == 0 && ((t_stack_data *)cheapest_data->target_node->content)->above_median == 0)
        reverse_rotate_both(stack_a, stack_b, cheapest);
    prepare_push(stack_a, cheapest, 'a');
    prepare_push(stack_b, cheapest_data->target_node, 'b');
    push_to(stack_a, stack_b, 1, 'b');
}

void    push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    prepare_push(stack_a, ((t_stack_data *)(*stack_b)->content)->target_node, 'a');
    push_to(stack_a, stack_b, 1, 'b');
}

void    rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
    t_stack_data    *b_data;
    t_stack_data    *a_data;
    t_stack_data    *cheap_data;
    t_stack_data    *target_data;
    
    a_data = (t_stack_data *) (*stack_a)->content;
    b_data = (t_stack_data *) (*stack_b)->content;
    cheap_data = (t_stack_data *) cheapest->content;
    target_data = ((t_stack_data *) cheap_data->target_node->content);
    while (b_data->value != target_data->value && a_data->value != cheap_data->value)
    {
        rr(stack_a, stack_b);
        b_data = (t_stack_data *) (*stack_b)->content;
        a_data  = (t_stack_data *) (*stack_a)->content;
    }
    update_index(*stack_a);
    update_index(*stack_b);
}

void    reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
    while (*stack_b != ((t_stack_data *) cheapest)->target_node && *stack_a != cheapest)
        rrr(stack_a, stack_b);
    update_index(*stack_a);
    update_index(*stack_b);
}