# Extended-Dining-Philosophers
The 42 Philosophers problem is a synchronization and concurrency challenge that extends the classic Dining Philosophers problem to a larger group of philosophers. The problem requires finding a solution that allows all the philosophers to eat without deadlock or starvation, even as the number of philosophers increases.

## Maybe you can handle 5 philosophers, but can you handle more?!

<div style="text-align:center;">

![image](https://user-images.githubusercontent.com/56733438/223171980-a4f1d2ee-2d39-4e01-ae6e-6e4e0494bc2e.png)

</div>

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
