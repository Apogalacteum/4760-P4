#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

struct Semaphore {
	int value;
	Queue<process> q;
};
P(struct Semaphore s)
{
	s.value = s.value - 1;
	if (s.value < 0)
	{
		q.push(p);
		block();
	}
	else
		return;
};
V(struct Semaphore s)
{
	s.value = s.value + 1;
	if (s.value <= 0)
	{
		q.pop();
		wakeup(p);
	}
};

struct Clock
{
	int sec;
	int nan;
	//incSec(){sec++;}
	//incNan(){nan++;}
};

struct processControlBlock
{
	pid_t pid;
	long state;
	unsigned int totalCPUTime;
	unsigned int totalSysTime;
	unsigned int lastBurstTime;
	int pPriority;
}

int main(){	
	shmid = shmget(key, sizeof(int*), 0666 | IPC_CREAT);
	struct Clock *freshClock = (struct Clock *)shmat(shmid, (void*)0,0);
	freshClock.sec = 0;
	freshClock.nan = 0;

	

	return 0;
}
