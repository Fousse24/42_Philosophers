/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:59:19 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/13 14:32:50 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void get_offsets(int state, int *offset, int *pre_offset)
{
	if (state == EATING)
	{
		*offset = get_t_eat();
		*pre_offset = get_t_sleep();
	}
	else if (state == SLEEPING)
	{
		*offset = get_t_eat();
		*pre_offset = get_t_sleep();
	}
	else if (state == THINKING)
	{
		*offset = 0;
		*pre_offset = 0;
	}
	else if (state == DEAD)
		*offset = get_t_die();
}