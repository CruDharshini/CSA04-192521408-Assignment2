#include <stdio.h>
#include <pthread.h>

void *display(void *arg) {
    printf("Hello from worker thread!\n");
    return NULL;
}

int main(void) {
    pthread_t thread;
    if (pthread_create(&thread, NULL, display, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }
    pthread_join(thread, NULL);
    printf("Main thread completed.\n");
    return 0;
}
