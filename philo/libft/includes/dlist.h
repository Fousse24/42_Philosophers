/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:43:33 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/01 20:00:44 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H
# include	"libft.h"

/* Node for generic double chained list */
typedef struct s_dlst
{
	void			*content;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

t_dlst	*ft_dlst_new_node(void *content);
void	ft_dlst_remove_node(t_dlst *node, void *(del)(void *));
void	*ft_dlst_clear_node(t_dlst **dlst, t_dlst *node, void *(del)(void *));
t_dlst	*ft_dlst_unlink_node(t_dlst **lst, t_dlst *node);
void	ft_dlst_add_front(t_dlst **lst, t_dlst *node);
void	ft_dlst_add_back(t_dlst **lst, t_dlst *node);
t_dlst	*ft_dlst_iter(t_dlst *lst, void *(iter)(void *), void *(del)(void *));
void	*ft_dlst_clear(t_dlst *lst, void *(del)(void *));
int		ft_dlst_size(t_dlst *lst);
t_dlst	*ft_dlst_get_tail(t_dlst *dlst);

#endif