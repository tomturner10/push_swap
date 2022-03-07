/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:15:34 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 14:15:34 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_link
{
	int				num;
	int				normalized;
	struct s_link	*next;
}				t_link;

typedef struct s_linkedList
{
	struct s_link	*top;
}				t_linkedList;

typedef struct s_stacks
{
	struct s_linkedList	*stack_a;
	struct s_linkedList	*stack_b;
}				t_stacks;

void				ft_free_links(struct s_linkedList *stack);
int					ft_duplicate(struct s_linkedList *stack, int num);
void				ft_sort_small_stack(struct s_stacks *stacks);
int					ft_size(struct s_linkedList *stack);
void				ft_sort_large_stack(struct s_stacks *stacks);
void				ft_normalize(struct s_linkedList *stack);
int					ft_is_sorted(struct s_linkedList *stack);
void				ft_choose_op(struct s_stacks *stacks, char *operation);
struct s_linkedList	*ft_init_stack(char **argv);
struct s_linkedList	*ft_init_linked_list(void);
void				ft_push_link(t_linkedList *stack, int value);
struct s_link		*ft_last(struct s_linkedList *stack);
struct s_link		*ft_get_index(struct s_linkedList *stack, int index);
void				ft_swap(struct s_linkedList *stack);
void				ft_push(struct s_linkedList *origin, \
struct s_linkedList *dest);
void				ft_rotate(struct s_linkedList *stack);
void				ft_reverse_rotate(struct s_linkedList *stack);

#endif //PUSHSWAP_PUSH_SWAP_H
