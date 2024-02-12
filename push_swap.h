/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:14 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/12 20:48:10 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libs/libft/libft.h"
#include <stdlib.h>
#include <limits.h>

typedef t_list  t_stack;

typedef struct s_stack_data
{
    long value;
    int index;
    int push_cost;
    int above_median;
    int cheapest;
    t_stack *target_node;
    t_stack *previous;
}   t_stack_data;

void    cleanup(t_stack *head);
t_stack *create_stack(int val, t_stack **stack);
t_stack *get_last_node(t_stack **stack);
t_stack *get_max_node(t_stack *stack);
t_stack *get_min_node(t_stack *node);
t_stack *get_cheapest(t_stack *stack);
void	push(t_stack **head, t_stack *new);
void    swap(t_stack *stack, int print, char c);
void    push_to(t_stack **from, t_stack **to, int print, char c);
void    rotate(t_stack **stack, int print, char c);
void    reverse_rotate(t_stack **stack, int print, char c);
void    remove_last(t_stack **stack);
void    sort_three(t_stack **stack);
void    push_swap(t_stack **stack_a, t_stack **stack_b);
void    print_stack(t_stack *stack);
void    update_nodes_a(t_stack *stack_a, t_stack *stack_b);
void    update_cost_a(t_stack *stack_a, t_stack *stack_b);
void    update_nodes_b(t_stack *stack_a, t_stack *stack_b);
void    update_target_node_a(t_stack *stack_a, t_stack *stack_b);
void    update_target_node_b(t_stack *stack_a, t_stack *stack_b);
void    update_cheapest(t_stack *stack);
void    update_index(t_stack *stack);
void    push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void    rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void    reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void    prepare_push(t_stack **stack, t_stack *top, char c);
void    set_min_on_top(t_stack **stack);
void    sort(t_stack **stack_a, t_stack **stack_b);
int     pop(t_stack **head);
int	    get_value(t_stack	*stack);
int 	get_stack_size(t_stack	*stack);
int     get_max(t_stack *stack);
int     get_min(t_stack *stack);
int     is_stack_sorted(t_stack *stack);

void    rr(t_stack **stack_a, t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

#endif