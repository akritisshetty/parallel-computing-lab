# Parallel Computing Lab
---
1. Write a OpenMP program to sort an array on n elements using both sequential and parallel mergesort(using Section). Record the difference in execution time. <br>
2. Write an OpenMP program that divides the Iterations into chunks containing 2 iterations, respectively (OMP_SCHEDULE=static,2). Its input should be the number of iterations, and its output should be which iterations of a parallelized for loop are executed by which thread. <br>
For example, if there are two threads and four iterations, the output might be the following: <br>
a. Thread 0 : Iterations 0 −− 1 <br>
b. Thread 1 : Iterations 2 −− 3 <br>
3. Write a OpenMP program to calculate n Fibonacci numbers using tasks. <br>
4. Write a OpenMP program to find the prime numbers from 1 to n employing parallel for directive. Record both serial and parallel execution times. <br>
5. Write a MPI Program for demonstration of MPI_Send and MPI_Recv.
