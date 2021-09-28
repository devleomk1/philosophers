# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

uint64_t	get_time_ms(void)
{
	uint64_t		ms_sec;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms_sec = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return (ms_sec);
}

int main(void)
{
	uint64_t	start_time;
	uint64_t	end_time;

	start_time = get_time_ms();
	usleep(1000 * 1000);
	end_time = get_time_ms();
	printf("%llu\n", end_time - start_time);
	return (0);
}
