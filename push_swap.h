/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:14 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/09 12:25:55 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libs/libft/libft.h"
#include <stdlib.h>

typedef t_list  t_stack;

typedef struct s_stack_data
{
    int value;
}   t_stack_data;

void    cleanup(t_stack *head);
t_stack *create_stack(int val);
void	push(t_stack **head, t_stack *new);
void    swap(t_stack    *stack);
void    push_to(t_stack **from, t_stack **to);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    remove_last(t_stack **stack);
int     pop(t_stack **head);
int	    get_value(t_stack	*stack);
int 	stack_size(t_stack	*stack);

#endif