/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:55:58 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/13 11:44:50 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    update_index(t_stack *stack)
{
    int index;
    int median;
    t_stack_data    *data;

    index = 0;
    if (!stack)
        return ;
    median = get_stack_size(stack) / 2;
    while (stack)
    {
        data = (t_stack_data *) stack->content;
        data->index = index;
        if (index <= median)
            data->above_median = 1;
        else
            data->above_median = 0;
        stack = stack->next;
        index++;
    }
}

void    update_cheapest(t_stack *stack)
{
    long    cheapest;
    t_stack *node;
    
    if (!stack)
        return ;
    cheapest = LONG_MAX;
    while (stack)
    {
        if (((t_stack_data *) stack->content)->push_cost < cheapest)
        {
            cheapest = ((t_stack_data *) stack->content)->push_cost;
            node = stack;
        }
        stack = stack->next;
    }
    ((t_stack_data *) node->content)->cheapest = 1;
}

t_stack *get_cheapest(t_stack *stack)
{
    while (stack)
    {
        if (((t_stack_data *)stack->content)->cheapest == 1)
            return stack;
        stack = stack->next;
    }
    return (stack);
}

void    prepare_push(t_stack **stack, t_stack *top, char c)
{
    t_stack_data     *data;
    t_stack_data     *top_data;

    top_data = (t_stack_data *) top->content;
    data = (t_stack_data *) (*stack)->content;
    while (data->value != top_data->value)
    {
        data = (t_stack_data *) (*stack)->content;
        //ft_printf("stack %c data val %d, top val %d\n", c, data->value, top_data->value);
        if (top_data->above_median)
            rotate(stack, 1, c);
        else
            reverse_rotate(stack, 1, c);
    }
}

void    set_min_on_top(t_stack **stack)
{
    while (((t_stack_data *)(*stack)->content)->value != ((t_stack_data *)get_min_node(*stack)->content)->value)
    {
        if (((t_stack_data *)get_min_node(*stack)->content)->above_median)
            rotate(stack, 1, 'a');
        else
            reverse_rotate(stack, 1, 'a');
    }
}