/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/10 19:14:49 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

t_time	get_start_time(void)
{
	static t_time	start;
	static int		init;

	if (!init)
	{
		gettimeofday(&start, NULL);
		init = 1;
	}
	return (start);
}

void	adjust_time(t_time *now, t_time *since, long threshold)
{
	long long	diff;
	long long	now_n;
	long long	since_n;

	now_n = time_to_long(*now);
	since_n = time_to_long(*since);
	diff = now_n - since_n;
	if (diff > threshold)
		now_n -= diff % threshold;
	*now = long_to_time(now_n);

}

void	set_to_current_time(t_philo *philo, t_time *time, long threshold)
{
	t_time	now;

	copy_time(&philo->start, &now);
	adjust_time(&now, time, threshold);
	*time = now;
	philo->timestamp = get_time_between(get_start_time(), *time);
}

void	copy_time(t_time *src, t_time *dest)
{
	*dest = long_to_time(time_to_long(*src));
}
