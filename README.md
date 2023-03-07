# Extended-Dining-Philosophers
The 42 Philosophers problem is a synchronization and concurrency challenge that extends the classic Dining Philosophers problem to a larger group of philosophers. The problem requires finding a solution that allows all the philosophers to eat without deadlock or starvation, even as the number of philosophers increases.

## Maybe you can handle 5 philosophers, but can you handle more?!

<div style="text-align:center;">

![image](https://user-images.githubusercontent.com/56733438/223171980-a4f1d2ee-2d39-4e01-ae6e-6e4e0494bc2e.png)

</div>

## Overview
```
Here are the things you need to know if you want to succeed this assignment:
- One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!
```
## Rules (Mandatory Part):

- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.




## Rules (Bonus Part):

The program of the bonus part takes the same arguments as the mandatory program.
It has to comply with the requirements of the Global rules chapter.
- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by
<b>a semaphore</b>.
- Each philosopher should be <b>a process</b>. But the main process should not be a
philosopher.
