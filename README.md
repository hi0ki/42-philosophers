# philosophers

This project simulates the classic "Dining Philosophers" problem, a classic concurrency problem.

## Description

The "Dining Philosophers" problem involves a group of philosophers sitting around a circular table, each with a plate of spaghetti and a fork to their left. To eat, a philosopher needs both forks. This project simulates this scenario, focusing on preventing deadlocks and race conditions using threads and synchronization mechanisms.

## Key Concepts

* **Threads:** Each philosopher is represented by a separate thread.
* **Mutexes:** Mutexes are used to protect access to the forks, preventing race conditions.
* **Deadlock Prevention:** The project implements a strategy to prevent deadlocks, such as a deterministic order of fork acquisition.
* **Synchronization:** The simulation uses synchronization mechanisms to ensure proper coordination between philosophers.
* **Time Management:** Accurately tracking and managing time is crucial for simulating the philosophers' actions.

## Usage

1.  **Compile:**
    ```bash
    make
    ```
2.  **Run the simulation:**
    ```bash
    ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
    ```

    * `<number_of_philosophers>`: The number of philosophers (and forks).
    * `<time_to_die>`: The time in milliseconds a philosopher can go without eating before dying.
    * `<time_to_eat>`: The time in milliseconds it takes a philosopher to eat.
    * `<time_to_sleep>`: The time in milliseconds a philosopher sleeps.
    * `[number_of_times_each_philosopher_must_eat]` (optional): The number of times each philosopher must eat before the simulation ends.

## Notes

* This project provides a practical understanding of concurrency and thread synchronization.
* Experiment with different simulation parameters to observe how they affect the philosophers' behavior.
* The project highlights the importance of careful resource management in concurrent programming.
