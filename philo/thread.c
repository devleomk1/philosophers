/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:26:40 by jisokang          #+#    #+#             */
/*   Updated: 2021/10/08 02:20:13 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitor_philo(void *philo_void)
{
	t_philo	*p;

	p = (t_philo *)philo_void;
	while (1)
	{
		if (p->info->num_phi_full == p->info->num_philo)
		{
			pthread_mutex_lock(&(p->info->print_mutex));
			printf(BLUE"🍝All philosophers have finished their meals.\n"RESET);
			usleep(100);
			pthread_mutex_unlock(&(p->info->die_mutex));
			return (EXIT_SUCCESS);
		}
		if (get_time_ms() - p->diecnt_start_time > p->info->time_die)
		{
			p->stat = DEAD;
			print_message(p, "dead\t\t");
			usleep(100);
			pthread_mutex_unlock(&(p->info->die_mutex));
			return (EXIT_SUCCESS);
		}
		usleep(100);
	}
}

static void	*philo_routine(void *philo_void)
{
	t_philo		*p;
	pthread_t	tid;

	p = (t_philo *)philo_void;
	p->diecnt_start_time = p->info->main_start_time;
	if (pthread_create(&tid, NULL, &monitor_philo, philo_void) != 0)
		return ((void *)EXIT_FAILURE);
	pthread_detach(tid);
	while (1)
	{
		philo_take_forks(philo_void);
		philo_eat(philo_void);
		philo_sleep(philo_void);
		philo_think(philo_void);
		usleep(100);
	}
	return ((void *)EXIT_SUCCESS);
}

static int	run_philo(t_info *info, int p_num)
{
	void		*p;
	pthread_t	tid;

	while (p_num < info->num_philo)
	{
		p = (void *)(&(info->philo[p_num]));
		if (pthread_create(&tid, NULL, &philo_routine, p) != 0)
			return (EXIT_FAILURE);
		pthread_detach(tid);
		p_num += 2;
	}
	if (p_num % 2 == 0)
		usleep(500 * info->time_eat);
	return (EXIT_SUCCESS);
}

int	thread_run(t_info *info)
{
	info->main_start_time = get_time_ms();
	if (run_philo(info, 0) == EXIT_FAILURE
		|| run_philo(info, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
