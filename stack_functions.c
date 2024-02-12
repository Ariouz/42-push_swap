/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:11:46 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/12 20:23:30 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// ROTATE BOTH
void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a, 0, 'a');
    rotate(stack_b, 0, 'b');
    ft_printf("rr\n");
}

// REVERSE ROTATE BOTH
void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a, 0, 'a');
    reverse_rotate(stack_b, 0, 'b');
    ft_printf("rrr\n");
}