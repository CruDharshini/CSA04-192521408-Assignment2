# CSA04 – Assignment 2

C programs for Operating Systems Assignment 2.

## Programs
- **Q1_Process_Fork.c** – Creates a child process using `fork()`.
- **Q2_Round_Robin_Scheduling.c** – Round Robin CPU scheduling; calculates waiting and turnaround times.
- **Q3_Pthread_Threads.c** – Creates and joins a POSIX thread.
- **Q4_IPC_Pipe.c** – Parent-child communication using a pipe.
- **Q5_Producer_Consumer_Semaphore.c** – Producer-consumer synchronization using semaphores and threads.
- **Q6_Bankers_Algorithm.c** – Banker's algorithm safety check.

## Compile and run (Linux)
```bash
gcc Q1_Process_Fork.c -o q1 && ./q1
gcc Q2_Round_Robin_Scheduling.c -o q2 && ./q2
gcc Q3_Pthread_Threads.c -o q3 -pthread && ./q3
gcc Q4_IPC_Pipe.c -o q4 && ./q4
gcc Q5_Producer_Consumer_Semaphore.c -o q5 -pthread && ./q5
gcc Q6_Bankers_Algorithm.c -o q6 && ./q6
```

For thread/semaphore programs, use the `-pthread` compiler option.
