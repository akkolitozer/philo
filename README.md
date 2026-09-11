*This project has been created as part of the 42 curriculum by hulescur.*

# Philosophers

## Description

Philosophers is a 42 project based on the classic Dining Philosophers problem.

The program simulates philosophers sitting around a table. Each philosopher
needs two forks to eat, then sleeps and thinks. The goal is to manage several
threads correctly so that the simulation runs without data races or deadlocks.

## Instructions

Go to the project directory:

```sh
cd philo
```

Compile the program:

```sh
make
```

Run it with:

```sh
./philo number_of_philosophers time_to_die tte tts [number_of_meals_required]
```

Example:

```sh
./philo 5 800 200 200
```

The arguments are expressed in milliseconds, except for the number of
philosophers and the optional number of meals.

To clean the project:

```sh
make clean
make fclean
```

## Resources

- 42 Philosophers subject
- Dining Philosophers problem
- POSIX threads documentation
- `pthread_create`, `pthread_join`, and mutex manual pages

AI usage:

AI was used to help write and organize this README.
