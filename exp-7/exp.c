#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define N 5 // Number of philosophers

sem_t forks[N]; // One semaphore for each fork

void* philosopher(void* num) {
    int id = *(int*)num;
    
    // Infinite loop for eating and thinking
    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1); // Simulate thinking

        // Try to pick up left fork
        printf("Philosopher %d is hungry and trying to pick up left fork %d\n", id, id);
        sem_wait(&forks[id]);

        // Try to pick up right fork
        printf("Philosopher %d picked up left fork %d and trying to pick up right fork %d\n", id, (id + 1) % N);
        sem_wait(&forks[(id + 1) % N]);

        // Eating
        printf("Philosopher %d is eating...\n", id);
        sleep(1); // Simulate eating

        // Put down right fork
        sem_post(&forks[(id + 1) % N]);
        printf("Philosopher %d put down right fork %d\n", id, (id + 1) % N);

        // Put down left fork
        sem_post(&forks[id]);
        printf("Philosopher %d put down left fork %d\n", id, id);
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    // Initialize semaphores for each fork
    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    // Create threads for each philosopher
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Join threads
    for (int i = 0; i < N; i++)
        pthread_join(philosophers[i], NULL);

    // Destroy semaphores
    for (int i = 0; i < N; i++)
        sem_destroy(&forks[i]);

    return 0;
}
