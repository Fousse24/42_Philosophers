/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/13 16:04:00 by sfournie         ###   ########.fr       */
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
	if (diff > threshold && threshold != 0)
		now_n = now_n - (diff - threshold);
	*now = long_to_time(now_n);

}

void	set_to_current_time(t_philo *philo, t_time *time, long threshold)
{
	t_time	now;

	if (!time)
		return ;
	gettimeofday(&now, NULL);
	// adjust_time(&now, &philo->start, threshold);
	copy_time(&philo->start, time);
}

void	copy_time(t_time *src, t_time *dest)
{
	*dest = long_to_time(time_to_long(*src));
}

long long	create_t_stamp(t_time time, int offset, int pre_offset)
{
	long long	timestamp;
	long long	temp;
	int			offset_n;

	offset_n = 0;
	timestamp = get_time_between(get_start_time(), time);
	temp = timestamp - pre_offset;
	if (offset > 0 && temp >= 0)
		offset_n = temp / offset;
	if (temp > offset * offset_n && offset)
		timestamp -= temp % offset;
	return (timestamp);
}
