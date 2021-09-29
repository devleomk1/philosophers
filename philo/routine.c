/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:48:44 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/29 16:40:54 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *philo)
{
	// pthread_mutex_lock(philo->info->forks_mutex + philo->num /* R */); // take fork R
	// pthread_mutex_lock(philo->info->forks_mutex + philo->num /* R */); // take fork L
	philo->stat = FORKS;
	print_message(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	philo->stat = EAT;
	philo->eat_start_time = get_time_ms();
	while (get_time_ms() - philo->eat_start_time < philo->info->time_eat)
		usleep(100);
	// pthread_mutex_unlock(philo->info->forks_mutex + philo->num /* R */); // take fork L
	// pthread_mutex_unlock(philo->info->forks_mutex + philo->num /* R */); // take fork R
	print_message(philo, "is eating");
	(philo->eat_cnt)++;
}

void	philo_sleep(t_philo *philo)
{
	philo->stat = SLEEP;
	philo->slp_start_time = get_time_ms();
	while (get_time_ms() - philo->slp_start_time < philo->info->time_sleep)
		usleep(100);
	print_message(philo, "is sleeping");
}

void	philo_think(t_philo *philo)
{
	philo->stat = THINK;
	print_message(philo, "is thinking");
}
