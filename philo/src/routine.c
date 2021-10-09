/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:48:44 by jisokang          #+#    #+#             */
/*   Updated: 2021/10/08 02:31:05 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *p)
{
	p->stat = FORKS;
	pthread_mutex_lock(p->r_fork);
	print_message(p, "has taken a fork R");
	pthread_mutex_lock(p->l_fork);
	print_message(p, "has taken a fork L");
}

void	philo_eat(t_philo *p)
{
	p->stat = EAT;
	p->diecnt_start_time = get_time_ms();
	print_message(p, "is eating\t");
	while (get_time_ms() - p->diecnt_start_time < p->info->time_eat)
		usleep(100);
	(p->eat_cnt)++;
	if (p->eat_cnt == p->info->num_must_eat && p->starve == FILL)
	{
		p->starve = FULL;
		(p->info->num_phi_full)++;
	}
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
}

void	philo_sleep(t_philo *p)
{
	uint64_t	slp_start_time;

	p->stat = SLEEP;
	slp_start_time = get_time_ms();
	print_message(p, "is sleeping\t");
	while (get_time_ms() - slp_start_time < p->info->time_sleep)
		usleep(100);
}

void	philo_think(t_philo *p)
{
	p->stat = THINK;
	print_message(p, "is thinking\t");
}