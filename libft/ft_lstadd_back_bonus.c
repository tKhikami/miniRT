/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:17:59 by nyrandri          #+#    #+#             */
/*   Updated: 2024/08/08 07:58:31 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (tmp == NULL)
		*lst = nw;
	if (tmp != NULL)
		tmp->next = nw;
}
