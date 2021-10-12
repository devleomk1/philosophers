/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/10/12 21:19:43 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
		pthread_mutex_destroy(&(info->forks_mutex[i++]));
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->print_mutex));
	free(info->forks_mutex);
	free(info->philo);
}

int	print_usage(int exit_return)
{
	printf(RED"Wrong argument! Please check usage.\n"\
		YELLOW"Usage: ./philo [num_philos] [time_die] [time_eat]"\
		" [time_sleep] [num_each_philos_eat(optional)]\n"RESET);
	return (exit_return);
}

int	main(int argc, char **argv)
{
	int			i;
	int			argv_num[6];
	t_info		info;

	if (argc < 5 || argc > 6)
		return (print_usage(EXIT_FAILURE));
	i = 1;
	while (i < argc)
	{
		argv_num[i] = ft_atoi_philo(argv[i]);
		if (argv_num[i] == 0)
			return (print_usage(EXIT_FAILURE));
		i++;
	}
	if (init_info(&info, argc, argv_num) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (thread_run(&info) == EXIT_FAILURE)
	{
		printf(RED"thread_run Fail\n"RESET);
		return (EXIT_FAILURE);
	}
	// usleep(100000);
	// printf("############ main\n");
	if (!pthread_mutex_lock(&(info.die_mutex))) {
		if (!pthread_mutex_unlock(&(info.die_mutex))) {
			destroy_mutex_all(&info);
			printf(CYAN"main thread good bye\n"RESET);
		}
	}
	return (EXIT_SUCCESS);
}
