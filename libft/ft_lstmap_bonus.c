/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:56:53 by nyrandri          #+#    #+#             */
/*   Updated: 2024/08/08 07:57:34 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*tmp;
	void	*nw;

	tmp = lst;
	begin = NULL;
	if (f == NULL)
		return (begin);
	while (tmp != NULL)
	{
		nw = (*f)(tmp->content);
		if (nw == NULL)
		{
			ft_lstdelone(nw, del);
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, nw);
		tmp = tmp->next;
	}
	return (begin);
}
