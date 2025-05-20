/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:33:49 by nyrandri          #+#    #+#             */
/*   Updated: 2024/08/08 06:46:00 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (del == NULL)
		return ;
	current = *lst;
	if (current != NULL)
	{
		while (current != NULL)
		{
			tmp = current->next;
			ft_lstdelone(current, del);
			current = tmp;
		}
	}
	*lst = NULL;
}
