/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:06 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/11/22 11:08:07 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_ps *push);
static void	three_sort(t_ps *push, int first, int second, int third);
static void	mini_sort(t_ps *push);

void	solve(t_ps *push)
{
	if (is_sorted(push->a))
		return ;
	if (push->size < 4)
		three_sort(push, push->a->i, push->a->next->i, push->a->next->next->i);
	else if (push->size < 7)
		mini_sort(push);
	else
		radix_sort(push);
}

/* Checked in this order
 * 123
 * 132
 * 213
 * 321
 * 312
 * 231
 **/
static void	three_sort(t_ps *push, int first, int second, int third)
{
	if (first < second && second < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		rra(push);
		sa(push);
	}
	else if (first > second && second < third && first < third)
		sa(push);
	else if (first > second && second > third)
	{
		sa(push);
		rra(push);
	}
	else if (first > second && second < third && first > third)
	{
		rra(push);
		rra(push);
	}
	else
		rra(push);
}

static void	mini_sort(t_ps *push)
{
	int	j;

	j = 0;
	while (stack_size(push->a) >= 4)
	{
		j = find_smallest_number(push->a, stack_size(push->a));
		if (j == 0)
			pb(push);
		else if (j <= (push->size / 2))
			ra(push);
		else if (j > (push->size / 2))
			rra(push);
	}
	three_sort(push, push->a->i, push->a->next->i, push->a->next->next->i);
	while (stack_size(push->b) != 0)
		pa(push);
}

static void	radix_sort(t_ps *push)
{
	int	i;
	int	j;

	j = 0;
	while (!is_sorted(push->a))
	{
		i = 0;
		while (i < push->size)
		{
			if ((((push->a->i) >> j) & 1) == 0)
				pb(push);
			else
				ra(push);
			i++;
		}
		while (stack_size(push->b) != 0)
			pa(push);
		j++;
	}
}
