#include "push_swap.h"

int	find_smallest_number(t_stack *stack)
{
	int	i;
	int	size;
	int	smallest;
	int	smallest_index;
	int	*array;

	i = 0;
	size = stack_size(stack);
	array = (int *)malloc(size * sizeof(int));
	while (i < size && stack != NULL)
	{
		array[i] = stack->i;
		stack = stack->next;
	}
	i = 0;
	smallest = array[0];
	smallest_index = 0;
	while (i < size)
	{
		if (array[i] < smallest)
		{
			smallest = array[i];
			smallest_index = i;
		}
		i++;
	}
	free(array);
	return (smallest_index);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	size;
	int	*array;

	i = 0;
	size = stack_size(stack);
	array = (int *)malloc(size * sizeof(int));
	while (i < size && stack != NULL)
	{
		array[i] = stack->i;
		stack = stack->next;
	}
	i = size - 1;
	while (i != 0)
	{
		if (array[i] < array[i - 1])
		{
			free(array);
			return (0);
		}
		i--;
	}
	free(array);
	return (1);
}
