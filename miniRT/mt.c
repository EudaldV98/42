#include <pthread.h>

#define NUM_THREADS 4

int jeje = 2147483648;

unsigned long long		fac(int n)
{
	unsigned long long	f = 1;

	while (n > 1)
		f *= n--;
	return f;
}

void *hardwork(void *threadid)
{
	long	tid = (long)threadid;

	printf("Thread %ld finished with output %llu\n", tid, fac(jeje));
	return (0);
}
/*
void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   printf("Hello World! Thread ID, %d\n", tid);
   pthread_exit(NULL);
}*/

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   for( i = 0; i < NUM_THREADS; i++ ) {
      rc = pthread_create(&threads[i], NULL, hardwork, (void *)i);
      if (rc) {
         printf("Error:unable to create thread, %d\n", rc);
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
