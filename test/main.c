#include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

int main(void)
{
	char *str;

	str = NULL;
	str = "Hello World";
	printf("%s\n", str);
	return (0);
}
