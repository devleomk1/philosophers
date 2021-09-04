/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 00:48:02 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/05 00:57:20 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*p_function(void *data);

int	main(void)
{
	pthread_t	pthread;
	int			thr_id;
	int			status;
	char		p1[] = "thread_created";
	char		p2[] = "thread_main";

	thr_id = pthread_create(&pthread, NULL, p_function, (void*)p1);
	if (thr_id < 0)
	{
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}
	p_function((void *)p2);
	printf("created thread id: %x\n", pthread);
	printf("end\n");
	return (0);
}

void	*p_function(void *data)
{
	pthread_t	tid;
	char		*thread_name;
	int			i;

	thread_name = (char *)data;
	tid = pthread_self();
	i = 0;
	while (i < 3)
	{
		printf("thread name : %s,\ttid : %x\n", thread_name, (unsigned int)tid);
		i++;
		usleep(1000 * 1000);
	}
}
