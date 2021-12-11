/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_limits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/10 17:32:07 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	get_t_die(void)
{
	t_diner *diner;

	diner = get_diner();
	return (diner->t_die);
}

int	get_t_sleep(void)
{
	t_diner *diner;

	diner = get_diner();
	return (diner->t_sleep);
}

int	get_t_eat(void)
{
	t_diner *diner;

	diner = get_diner();
	return (diner->t_eat);
}
