/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/28 16:08:53 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//philosopher's number must start no.1

void	*monitor_philo()
{

}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->info->forks_mutex + philo->num); // take fork R
	pthread_mutex_lock(philo->info->forks_mutex + philo->num); // take fork L
	philo->stat = FORKS;

}

void	eat(t_philo *philo)
{

	pthread_mutex_unlock(philo->info->forks_mutex + philo->num);
}

void	sleep(t_philo *philo)
{

}

void	think(t_philo *philo)
{

}

void	*philo_work(void *philo_void)
{
	pthread_t	tid;

	if(pthread_create(tid, NULL, &monitor_philo, philo_void) != 0);
		return ((void *)EXIT_FAILURE);
	pthread_detach(tid);

	while (1)
	{
		//take_forks();
		//eat();
		//sleep();
		//think();
	}
	return ((void *)EXIT_SUCCESS);
}

int	init_info(t_info *info, int argc, int *argv_num)
{
	int	i;

	info->num_philo = argv_num[NUM_PHIL];
	info->time_die = argv_num[TIME_DIE];
	info->time_eat = argv_num[TIME_EAT];
	info->time_sleep = argv_num[TIME_SLP];
	if (argc != 6)
		info->num_phi_eat = argv_num[NUM_PEAT];
	else
		info->num_phi_eat = PEAT_INF;
	// 이 부분 다시 이해해!
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (info->philo == NULL)
		return (EXIT_FAILURE);	//어떻게 나가게 만들지?
	info->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (info->forks_mutex == NULL)
	{
		free(info->philo);
		return (EXIT_FAILURE);	//어떻게 나가게 만들지?
	}
	i = 0;
	while (i < info->num_philo)
	{
		//init_philo()
		info->philo[i].num = i + 1;
		info->philo[i].eat_cnt = 0;
		info->philo[i].stat = THINK;
		info->philo[i].info = info;
		//init_fork() here
		pthread_mutex_init(info->forks_mutex + i, NULL);
	}

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
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		argv_num[i] = ft_atoi_philo(argv[i]);
		i++;
	}
	if (init_info(&info, argc, argv_num) == EXIT_FAILURE);
		return (EXIT_FAILURE);


	//lock(_die.mutex)
	//unlock(_die.mutex)
	//바로 하는 이유
	//init에서 lock을 하면 unlock이 되기전까지 main()문이 멈춤.
	return (EXIT_SUCCESS);
}
