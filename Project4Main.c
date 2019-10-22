#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
	
	shmid = shmget(key, sizeof(int*), 0666 | IPC_CREAT);
	int *clockSec = (int *)shmat(shmid, (void*)0,0);
	int *clockNan = (int *)shmat(shmid, (void*)0,0);
	
	return 0;
}
