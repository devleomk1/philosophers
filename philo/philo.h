/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:54:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/29 20:00:09 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "color.h"

# define ERROR		-1
# define TRUE		1
# define FALSE		0
# define TO_MSEC	1000

# define NUM_PHIL	1
# define TIME_DIE	2
# define TIME_EAT	3
# define TIME_SLP	4
# define NUM_PEAT	5

# define PEAT_INF	-1

# define THINK		0
# define FORKS		1
# define EAT		2
# define SLEEP		3
# define DEAD		4

struct s_info;


typedef struct s_philo
{
	int				num;
	int				stat;
	int				eat_cnt;
	uint64_t		eat_start_time;
	uint64_t		slp_start_time;
	struct s_info	*info;
	pthread_mutex_t	eat_mutex;
}					t_philo;

typedef struct s_info
{
	int				num_philo;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
	int				num_phi_eat;
	uint64_t		main_start_time;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t print_mutex;
	pthread_mutex_t	*forks_mutex; //포크는 여러개니까아
	t_philo			*philo;
}					t_info;

void	philo_take_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/* UTIL */
int			ft_atoi_philo(const char *str);
uint64_t	get_time_ms(void);
void	print_message(t_philo *philo, char *str);
#endif
