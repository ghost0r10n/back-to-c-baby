#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* thread_function(void* arg){
  int thread_id = *(int*)arg;
  printf("Hello from thread %d\n", thread_id);
  return NULL;
}

int main(){
  pthread_t thread;
  int thread_id = 1;

  pthread_create(&thread, NULL, thread_function, &thread_id);
  pthread_join(thread, NULL);

  return 0;
}
