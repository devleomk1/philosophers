/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:32:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/10/06 15:02:38 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *str)
{
	//print 못하게 막는다
	pthread_mutex_lock(&(philo->info->print_mutex));
	if (philo->num == 2)
		printf(YELLOW"%llums\t%d\t%s\t[%d]\n"RESET, get_time_ms() - philo->info->main_start_time, philo->num, str, philo->eat_cnt);
	else
		printf("%llums\t%d\t%s\t[%d]\n", get_time_ms() - philo->info->main_start_time, philo->num, str, philo->eat_cnt);
	if (philo->stat != DEAD)
		pthread_mutex_unlock(&(philo->info->print_mutex));	//if()	출력하기 싫으면 if걸어서 unlock 안하게 해!
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
