# Exp 7: Dining Philosopher
Problem Statement

In the problem, five philosophers sit at a round table, alternating between eating and thinking. Between each pair of philosophers is a single fork. To eat, a philosopher needs both the fork to their left and the fork to their right. However, since there’s only one fork between each pair, if every philosopher picks up their left fork at the same time, they will all wait indefinitely for the right fork to become available, resulting in a deadlock.

Solution Approach

The goal is to design a solution where:

	1.	Deadlock is avoided (no philosopher should indefinitely wait for forks).
	2.	Starvation is prevented (every philosopher eventually gets to eat).
	3.	A maximum of one philosopher is allowed to eat with any pair of forks.

C Program Solution Using Semaphores

In C, we can use semaphores to control access to forks. Each fork is represented by a semaphore, and philosophers attempt to acquire the forks on both sides before they start eating.

# Exp 8: FCFS and SJF
1. First-Come, First-Serve (FCFS)

In FCFS, the process that arrives first is executed first. This scheduling algorithm is simple but can lead to the “convoy effect,” where short processes wait for long processes to finish.

Explanation of FCFS Code

	1.	Waiting Time Calculation: For each process, the waiting time is the waiting time of the previous process plus its burst time.
	2.	Turnaround Time Calculation: Turnaround time is the sum of the process’s burst time and its waiting time.
	3.	Average Calculation: Calculates and displays the average waiting and turnaround times.

2. Shortest Job First (SJF) - Non-Preemptive

In SJF, the process with the shortest burst time is selected first. This can minimize waiting time but might lead to starvation for long processes if shorter processes keep arriving.

Explanation of SJF Code

	1.	Sorting by Burst Time: Processes are sorted by burst time before scheduling.
	2.	Waiting and Turnaround Times: These are calculated similarly to FCFS but after sorting by burst time.
	3.	Average Calculation: Displays the average waiting and turnaround times.

# Exp 9: Priority and Round Robin

1. Priority Scheduling

In Priority Scheduling, each process is assigned a priority, and the CPU is allocated to the process with the highest priority (lower numbers often represent higher priorities). If two processes have the same priority, they may be scheduled on a First-Come, First-Serve (FCFS) basis.

Explanation of Priority Scheduling Code

	1.	Sorting by Priority: Processes are sorted based on priority values. Lower values represent higher priorities.
	2.	Waiting and Turnaround Times: Calculated after sorting.
	3.	Average Calculation: Displays the average waiting and turnaround times.

2. Round Robin Scheduling

In Round Robin Scheduling, each process is assigned a fixed time slice or quantum. The CPU cycles through the processes, allowing each one to execute for a maximum of one time quantum at a time. This approach is fair but may not be optimal for CPU-intensive tasks.

Explanation of Round Robin Code

	1.	Time Quantum: A fixed quantum is provided, defining the maximum CPU time allocated per cycle for each process.
	2.	Remaining Time: remainingTime keeps track of how much burst time is left for each process.
	3.	Waiting and Turnaround Times: Calculated after cycling through processes based on the quantum.
	4.	Average Calculation: Displays the average waiting and turnaround times.

# Exp-10: Bankers Algorithm

The Banker’s Algorithm is a classic algorithm in operating systems used to avoid deadlock by managing resource allocation. It determines if a system is in a safe state by simulating resource allocation for processes, ensuring that each process can eventually complete its execution without causing deadlock.

Explanation of the Banker’s Algorithm Code

	1.	Input Variables:
	•	n: Number of processes.
	•	m: Number of resource types.
	•	avail[]: Array of available instances for each resource.
	•	max[][]: Matrix indicating the maximum demand of each process.
	•	alloc[][]: Matrix showing the currently allocated resources to each process.
	2.	Calculating Need Matrix:
	•	The need matrix is calculated as:

\text{need}[i][j] = \text{max}[i][j] - \text{alloc}[i][j]

	•	This matrix represents the remaining resource requirement for each process.
	3.	Safety Check (isSafe function):
	•	This function checks if the system is in a safe state by simulating the allocation of resources.
	•	It uses a work array initialized with the available resources and a finish array to track whether each process can complete.
	•	It attempts to find a sequence where each process can obtain the required resources, finish its execution, and release resources back to the pool (work array).
	•	If it can find a sequence that satisfies all processes without causing deadlock, the system is in a safe state, and it prints the safe sequence.
	4.	Execution:
	•	After taking input, the program calculates the need matrix and calls isSafe to determine if the system is in a safe state.


