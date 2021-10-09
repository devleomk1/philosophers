/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:32:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/10/09 11:49:26 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(&(p->info->print_mutex));
	printf("%llums\t%d\t%s\t[%d]\n",
		get_time_ms() - p->info->main_start_time, p->num, str, p->eat_cnt);
	if (p->stat != DEAD)
		pthread_mutex_unlock(&(p->info->print_mutex));
}

int	ft_atoi_philo(const char *str)
{
	long	result;
	size_t	i;

	result = 0;
	i = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483648)
			return (0);
		i++;
	}
	return (result);
}

/* A function to get the current time in ms. */
uint64_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
