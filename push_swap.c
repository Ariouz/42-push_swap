/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:05:26 by vicalvez          #+#    #+#             */
/*   Updated: 2024/02/09 12:42:10 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
    t_stack *head;

    head = create_stack(5);
    push(&head, create_stack(2));
    push(&head, create_stack(8));
    push(&head, create_stack(4));
    push(&head, create_stack(1));
    
    t_stack *cursor = head;
    while (cursor)
    {
        ft_printf("stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    ft_printf("\nremoved top stack element: %d\n", pop(&head));
    cursor = head;
    while (cursor)
    {
        ft_printf("A: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    swap(head);
    ft_printf("\nswap 1-2 stack element\n");
    cursor = head;
    while (cursor)
    {
        ft_printf("A: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    t_stack *b = NULL;
    
    ft_printf("\npush a to b\n");
    push_to(&head, &b);
    cursor = head;
    while (cursor)
    {
        ft_printf("A: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    cursor = b;
    while (cursor)
    {
        ft_printf("\nB: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    ft_printf("\nrotate\n");
    rotate(&head);
    cursor = head;
    while (cursor)
    {
        ft_printf("A: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    ft_printf("\nreverse rotate\n");
    reverse_rotate(&head);
    cursor = head;
    while (cursor)
    {
        ft_printf("A: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    ft_printf("\npush b to a\n");
    push_to(&b, &head);
    cursor = head;
    while (cursor)
    {
        ft_printf("A: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }

    cursor = b;
    while (cursor)
    {
        ft_printf("\nB: stack element: %d\n", get_value(cursor));
        cursor = cursor->next;
    }
    
    //cleanup(head);
    return (0);
}

void    cleanup(t_stack *head)
{
        t_stack *cursor;

        cursor = head;
        while (cursor)
        {
            
            cursor = cursor->next;
        }
}