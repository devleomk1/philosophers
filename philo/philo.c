/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/27 01:28:54 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	init_info(t_info *info, int argc, int *argv_num)
{
	info->num_philo = argv_num[NUM_PHIL];
	info->time_die = argv_num[TIME_DIE];
	info->time_eat = argv_num[TIME_EAT];
	info->time_sleep = argv_num[TIME_SLP];
	if (argc != 6)
		info->num_phi_eat = argv_num[NUM_PEAT];
	else
		info->num_phi_eat = -1; //define
	// 이 부분 다시 이해해!
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (info->philo == NULL)
		return (ERROR);	//어떻게 나가게 만들지?
}

int	main(int argc, char **argv)
{
	int			i;
	int			argv_num[6];
	t_info		info;

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
		argv_num[i] = ft_atoi_philo(argv[i]);
		i++;
	}
	init_info(&info, argc, argv_num);

	i = 0;
	while (i < info.num_philo)
	{
		info.philo[i].num = i + 1;
		info.philo[i].eat_cnt = 0;
		info.philo[i].stat = 1; //define stat
	}

		//malloc() -> forks
	//pthread_create(&p1, NULL, &philo_work, NULL);
	//pthread_create(&p2, NULL, &philo_work, NULL);
	//usleep(100000);
	//pthread_join(p1, NULL);
	//pthread_join(p2, NULL);
	return (0);
}
