/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 11:41:48 by obdintal          #+#    #+#             */
/*   Updated: 2026/08/14 15:58:01 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*atual;
	t_list	*passado;

	if (!lst || !del)
		return ;
	atual = *lst;
	passado = atual;
	while (atual)
	{
		atual = atual->next;
		ft_lstdelone(passado, del);
		passado = atual;
	}
	*lst = NULL;
}
