/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/25 17:30:56 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//static int	error_msg(char *str)
//{

//}

//philosopher's number must start no.1

static void	*philo_work(void *philo_void)
{
	int	*p;

	p = (void *)philo_void;
	printf("EAT\n");
	usleep(20000);
	printf("SLEEP\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	int			argv_num[6];
	t_state		state;
	pthread_t	p1;
	pthread_t	p2;
	pthread_t	p3;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong argument! Please check usage.\n"\
			YELLOW"Usage: ./philo [num_philos] [time_die] [time_eat]"\
			" [time_sleep] [num_each_philos_eat(optional)]\n"RESET);
		return (ERROR);
	}

	i = 1;
	while (i < argc)
	{
		//atoi -> ft_atoi for philo -> 음수 처리
		argv_num[i] = atoi(argv[i]);
		i++;
	}
	//define
	//argv_num_name 0 = NUM_PHIL
	//argv_num_name 1 = TIME_DIE
	//argv_num_name 2 = TIME_EAT
	//argv_num_name 3 = TIME_SLP
	//argv_num_name 4 = NU_P_EAT


	pthread_mutex_lock();
	if (argv_num[1] < 2)
	{
		printf("ERROR\n");
		return (ERROR);
	}
	//init();
	state.num_philo = argv_num[1];
	state.time_die = argv_num[2];
	state.time_eat = argv_num[3];
	state.time_sleep = argv_num[4];
	if (argc != 6)
		state.num_phi_eat = argv_num[5];
	else
		state.num_phi_eat = 0;

		//malloc() -> philo
		//malloc() -> forks
	pthread_create(&p1, NULL, &philo_work, NULL);
	pthread_create(&p2, NULL, &philo_work, NULL);
	pthread_create(&p3, NULL, &philo_work, NULL);
	usleep(100000);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);
	return (0);
}
