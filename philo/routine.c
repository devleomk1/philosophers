/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:48:44 by jisokang          #+#    #+#             */
/*   Updated: 2021/10/07 11:01:59 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message(philo, "has taken a fork R");
	pthread_mutex_lock(philo->l_fork);
	print_message(philo, "has taken a fork L");
	philo->stat = FORKS;
}

void	philo_eat(t_philo *philo)
{
	philo->stat = EAT;
	philo->eat_start_time = get_time_ms();
	while (get_time_ms() - philo->eat_start_time < philo->info->time_eat)
		usleep(100);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	print_message(philo, "is eating\t");
	philo->died_time = get_time_ms() + philo->info->time_die;
	(philo->eat_cnt)++;
	if (philo->eat_cnt == philo->info->num_phi_eat && philo->starve == FILL)
	{
		philo->starve = FULL;
		(philo->info->num_phi_full)++;
	}
}

void	philo_sleep(t_philo *philo)
{
	philo->stat = SLEEP;
	philo->slp_start_time = get_time_ms();
	while (get_time_ms() - philo->slp_start_time < philo->info->time_sleep)
		usleep(100);
	print_message(philo, "is sleeping\t");
}

void	philo_think(t_philo *philo)
{
	philo->stat = THINK;
	print_message(philo, "is thinking\t");
}
