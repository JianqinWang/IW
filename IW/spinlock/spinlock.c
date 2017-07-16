#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

/**
 * function prototpes
 */
void spinlock(int volatile *Destination);
void unlock(int volatile *Destination);
void *thread1(void *arg);
void *thread2(void *arg);

/**
 * Destination - volatile integer variable that the two threads will try to access
 */
int volatile Destination = 0;

/**
 * thread1 - the spinlock process for thread 1, would continuously try to access
 * Destination using spinlock and unlock
 * @arg: NULL argument
 * Return: arg, or NULL
 */
void *thread1(void *arg)
{
	printf("thread1 is starting\n");
	while (1)
	{
		spinlock(&Destination);
		printf("thread1 has locked Destination\n");
		sleep(1);
		unlock(&Destination);
	}
	return (arg);
}

 /**
 * thread2 - the spinlock process for thread 2, also continuously trying to access
 * Destination
 * @arg: NULL argument
 * Return: arg, or NULL
 */
void *thread2(void *arg)
{
	printf("thread2 is starting\n");
	while (1)
	{
		spinlock(&Destination);
		printf("thread2 has locked Destination\n");
		sleep(1);
		unlock(&Destination);
	}
	return (arg);
}

/**
 * spinlock - spinlock process for the two threads to take turns accessing Destination
 * @Destination: volatile integer that both threads are trying to access/change
 * Return: Nothing, void function
 */
void spinlock(int volatile *Destination)
{
	/* The function that I think is equivalent to _InterlockedCompareExchange64
	   for Linux */
        while (__sync_val_compare_and_swap(Destination, 0, 1) != 0)
		;
}

/**
 * unlock - function that unlocks the resource after the thread is done
 * @Destination: reset the value at Destination to 0, so another thread can access
 */
void unlock(int volatile *Destination)
{
	*Destination = 0;
}

/**
 * main - main function that creates 2 threads to test my version of spinlock
 * First creates two threads, which will both try to access Destination
 * Both threads are in infinite loops, and continuously try to access the same resource
 * The program then terminates both threads, and exits with return status 0.
 */
int main(void)
{
	pthread_t pth1, pth2;

	printf("Starting spinlock test\n");
	/* create 2 threads */
	pthread_create(&pth1, NULL, thread1, NULL);
	pthread_create(&pth2, NULL, thread2, NULL);
	/* wait for threads to execute */
	sleep(10);
	/* terminate threads (both are in infinite loops) */
	pthread_cancel(pth1);
	pthread_cancel(pth2);
	printf("Program exiting\n");
	return (0);
}
