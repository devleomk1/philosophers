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
	uint64_t	now_time;

	printf("Tik\n");
	start_time = get_time_ms();
	while (now_time <= 10000)
	{
		now_time = get_time_ms() - start_time;
	}
	printf("Tok!\n%llu\n", now_time);
}
