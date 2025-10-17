# Operating Systems Assignment 
Abdelrhman Islam  

---

## Question 1 – Using fork() and pipe()

### Description  
In this task, a program was created to demonstrate **inter-process communication** using `fork()` and `pipe()` in Linux.  
The parent process sends a string and an integer value `n` to the child process through a pipe.  
The child process receives the data, repeats the string `n` times, and sends the result back to the parent process.  
Finally, the parent reads the modified string and displays it.

### Learning Objective  
- Understand process creation using `fork()`  
- Learn how to send and receive data between processes using `pipe()`  
- Manage two-way communication (Parent ↔ Child)

### Sample Output  
```
Child read <"hello" and n = 3> from Parent  
Parent read <"hellohellohello"> from Child
```

---

## Question 2 – Creating and Managing Multiple Child Processes

### Description  
This question required using `fork()` to create **exactly three child processes**.  
Each child process is responsible for displaying the content of a specific file:  
- file1.txt  
- file2.txt  
- file3.txt  

Each file contains the text:  
```
#File <number>, Abdelrhman Islam, RegNo: 2305152
```

The parent waits for all child processes to finish before printing a completion message.  
Each child uses an `exec()` function to execute the `cat` command and display its file content.

### Learning Objective  
- Practice using multiple forks to create separate child processes  
- Learn how to replace a process image using `exec()`  
- Synchronize parent and child processes using `wait()`

### Sample Output  
```
Child 1 displaying file1.txt:
Child 2 displaying file2.txt:
Child 3 displaying file3.txt:
#File 1, Abdelrhman Islam, RegNo: 2305152
#File 2, Abdelrhman Islam, RegNo: 2305152
#File 3, Abdelrhman Islam, RegNo: 2305152
All children have finished.
```

---

## Summary  
Both programs demonstrate key operating system concepts:
- **Process creation** using `fork()`  
- **Inter-process communication** using `pipe()`  
- **Process synchronization** using `wait()`  
- **Program execution** using `exec()`  

These exercises show how processes interact and exchange data in a Linux environment.

---

📍 *Developed by* **Abdelrhman Islam**  