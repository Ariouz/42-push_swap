/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:06:07 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/09 12:06:46 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int val)
{
	t_stack_data *stack_data;

	stack_data = malloc(sizeof(t_stack_data));
	stack_data->value = val;
	return (ft_lstnew(stack_data));
}

void	push(t_stack **head, t_stack *new)
{
	ft_lstadd_front(head, new);
}

int	pop(t_stack **head)
{
	t_stack_data *data;

	data = (t_stack_data *) (*head)->content;
	*head = (*head)->next;
	return (data->value);
}

int	stack_size(t_stack	*stack)
{
	return (ft_lstsize(stack));
}

int	get_value(t_stack	*stack)
{
	return (((t_stack_data *) stack->content))->value;
}