/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:40:14 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/13 11:07:43 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max(t_stack *stack)
{
    t_stack *next;
    t_stack_data    *data;
    int max;

    next = stack;
    data = (t_stack_data *) next->content;
    max = data->value;
    while (next)
    {
        data = (t_stack_data *) next->content;
        if (data->value > max)
            max = data->value;
        next = next->next;
    }
    return (max);
}

int get_min(t_stack *stack)
{
    t_stack *next;
    t_stack_data    *data;
    int min;

    next = stack;
    data = (t_stack_data *) next->content;
    min = data->value;
    while (next)
    {
        data = (t_stack_data *) next->content;
        if (data->value < min)
            min = data->value;
        next = next->next;
    }
    return (min);
}

t_stack *get_last_node(t_stack **stack)
{
    t_stack *head;
    t_stack *last;

    head = *stack;
    last = head;
    while (head)
    {
        last = head;
        head = head->next;
    }
    return (last);
}

int is_stack_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (get_value(stack) > get_value(stack->next))
            return (0);
        stack = stack->next;
    }
    return (1);
}

t_stack *get_max_node(t_stack *node)
{
    t_stack *next;
    t_stack *max;
    t_stack_data    *data;

    next = node;
    data = (t_stack_data *) next->content;
    max = next;
    while (next)
    {
        data = (t_stack_data *) next->content;
        if (data->value > ((t_stack_data *) max->content)->value)
            max = next;
        next = next->next;
    }
    return (max);
}

t_stack *get_min_node(t_stack *node)
{
    t_stack *next;
    t_stack *min;
    t_stack_data    *data;

    next = node;
    data = (t_stack_data *) next->content;
    min = next;
    while (next)
    {
        data = (t_stack_data *) next->content;
        if (data->value < ((t_stack_data *) min->content)->value)
            min = next;
        next = next->next;
    }
    return (min);
}

void    print_stack(t_stack *stack)
{
    t_stack *cursor;
    cursor = stack;
    while (cursor)
    {
        ft_printf("%d\n", get_value(cursor));
        if (cursor->next)
            cursor = cursor->next;
        else
            break;
    }
}