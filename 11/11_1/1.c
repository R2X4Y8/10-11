#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler(int signo) 
{
	if (signo == SIGINT)
		printf("Ñaptured signal SIGINT\n");
	else if (signo == SIGTERM)
		printf("Captured signal SIGTERM\n");
	else 
	{
		fprintf(stderr, "No waiting signal\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


int main (void) 
{
	if (signal(SIGINT, signal_handler) == SIG_ERR) 
	{
		fprintf(stderr, "²mpossible to process SIGINT!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGTERM, signal_handler) == SIG_ERR) 
	{
		fprintf(stderr, "²mpossible to process SIGTERM!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGPROF, SIG_DFL) == SIG_ERR) 
	{
		fprintf(stderr, "²mpossible to reset SIGPROF!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGHUP, SIG_IGN) == SIG_ERR) 
	{
		fprintf(stderr, "Impossible to ignore SlGHUP!\n");
		exit(EXIT_FAILURE);
	}
	for (;;) 
	{
		raise(SIGTERM);
		pause();
	}
	return 0;
}
