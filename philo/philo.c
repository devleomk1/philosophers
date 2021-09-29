/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/29 20:26:24 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//philosopher's number must start no.1
//usleep() -> while(get_time_ms - SET_TIME < 1000)

void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->info->print_mutex));
	printf("%llums %d %s\n", get_time_ms() - philo->info->main_start_time, philo->num, str);
	pthread_mutex_unlock(&(philo->info->print_mutex));	//if()	출력하기 싫으면 if걸어서 unlock 안하게 해!
}

void	*monitor_philo()
{
	return (0);
}

void	*philo_routine(void *philo_void)
{
	pthread_t	tid;
	t_philo		*p;

	p = (t_philo *)philo_void;
	// if(pthread_create(tid, NULL, &monitor_philo, philo_void) != 0);
	// 	return ((void *)EXIT_FAILURE);
	// pthread_detach(tid);
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

int	run_philo(t_info *info, int p_num)
{
	void		*p;
	pthread_t	tid;

	while (p_num < info->num_philo)
	{
		p = (void*)(&(info->philo[p_num]));
		pthread_create(&tid, NULL, &philo_routine, p);
		pthread_detach(tid);
		p_num += 2;
	}
	return(EXIT_SUCCESS);
}

void	thread_run(t_info *info)
{
	pthread_t	tid;

	info->main_start_time = get_time_ms();
	run_philo(info, 0);

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
		info->philo[i].eat_start_time = 0;
		info->philo[i].slp_start_time = 0;
		//init_fork() here
		pthread_mutex_init(info->forks_mutex + i, NULL);
		i++;
	}
	pthread_mutex_init(&(info->print_mutex), NULL);
	return (0);
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
	if (init_info(&info, argc, argv_num) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	thread_run(&info);
	usleep(10000*1000);
	//lock(_die.mutex)
	//unlock(_die.mutex)
	//바로 하는 이유
	//init에서 lock을 하면 unlock이 되기전까지 main()문이 멈춤.
	return (EXIT_SUCCESS);
}
