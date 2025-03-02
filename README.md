# philosophers

This project simulates a classic concurrency problem.

## Description

This project simulates a scenario involving a group of entities that require shared resources. It focuses on preventing deadlocks and race conditions using threads and synchronization mechanisms.

## Key Concepts

* **Threads:** Each entity is represented by a separate thread.
* **Mutexes:** Mutexes are used to protect access to shared resources, preventing race conditions.
* **Deadlock Prevention:** The project implements a strategy to prevent deadlocks.
* **Synchronization:** The simulation uses synchronization mechanisms to ensure proper coordination.
* **Time Management:** Accurately tracking and managing time is crucial for simulating actions.

## Usage

1.  **Compile:**
    ```bash
    make
    ```
2.  **Run the simulation:**
    ```bash
    ./philo <number_of_entities> <time_to_death> <time_to_action> <time_to_rest> [number_of_actions_each_entity_must_perform]
    ```

    * `<number_of_entities>`: The number of entities.
    * `<time_to_death>`: The time in milliseconds an entity can go without action before death.
    * `<time_to_action>`: The time in milliseconds it takes an entity to perform an action.
    * `<time_to_rest>`: The time in milliseconds an entity rests.
    * `[number_of_actions_each_entity_must_perform]` (optional): The number of actions each entity must perform before the simulation ends.

## Notes

* This project provides a practical understanding of concurrency and thread synchronization.
* Experiment with different simulation parameters to observe how they affect the entities' behavior.
* The project highlights the importance of careful resource management in concurrent programming.
