/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:43:58 by ejolyn            #+#    #+#             */
/*   Updated: 2021/03/22 14:08:46 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_list_size(t_list *lst);
int					ft_list_push_front(t_list **head, void *data);


t_list	*ft_lstnew(void *content)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

int main(void)
{
	t_list *list = ft_lstnew("one");
	ft_list_push_front(&list, "two");
	ft_list_push_front(&list, "three");
	ft_list_push_front(&list, "four");
	
	printf("size of list: %d\n", ft_list_size(list));
	int i = 0;
	while (list)
	{
		printf("list[%d] = %s\n", i, list->content);
		list = list->next;
		i++;
	}
}

