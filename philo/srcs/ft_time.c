/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:42:59 by sfournie         ###   ########.fr       */
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

long long	get_cur_time(void)
{
	t_time	now;

	gettimeofday(&now, NULL);
	return (time_to_long(now));
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
