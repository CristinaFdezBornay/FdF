/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:25:20 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:12:30 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfold(t_list *first, t_list *(*f)(t_list*, t_list*))
{
	t_list		*current;
	t_list		*result;

	if (first && first->next && f)
	{
		result = f(first, first->next);
		current = first->next->next;
		while (current != NULL)
		{
			result = f(result, current);
			current = current->next;
		}
		return (result);
	}
	else
		return (NULL);
}
