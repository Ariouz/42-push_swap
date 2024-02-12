/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:06:07 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/12 19:59:14 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int val, t_stack **stack)
{
	t_stack_data *stack_data;
	t_stack	*last;
	t_stack	*node;

	stack_data = malloc(sizeof(t_stack_data));
	stack_data->value = val;
	
	stack_data->previous = NULL;
	stack_data->cheapest = 0;
	node = ft_lstnew(stack_data);
	if (*stack)
	{
		last = get_last_node(stack);
		last->next = node;
		stack_data->previous = last;
	}
	return (node);
}

void	push(t_stack **head, t_stack *new)
{
	ft_lstadd_front(head, new);
}

int	pop(t_stack **head)
{
	t_stack_data data;
	t_stack	*tmp;

	data = *(t_stack_data *) (*head)->content;
	tmp = (*head)->next;
	free((*head)->content);
	free(*head);
	*head = tmp;
	return (data.value);
}

int	get_stack_size(t_stack	*stack)
{
	return (ft_lstsize(stack));
}

int	get_value(t_stack	*stack)
{
	return (((t_stack_data *) stack->content))->value;
}