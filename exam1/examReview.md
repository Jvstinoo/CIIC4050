# Exam 1 Review

## Lecture 1 - Introduction to Operating Systems

### POSIX Systems
Provides a standardized set of APIs and command-line utilities, which allows for software developed for one POSIX system to be available for others. Such as: Linux, macOS, FreeBSD. 

### Computer system organization
- CPU and IO devices can execute concurrently.
    - Concurrency: Simulatenous execution of multiple tasks or operations. With a single processor, this is achieved by switching between tasks quickly, making it seem like they are executing at the same time.


## Lecture 2 - Operating system structures

### Command line interface
- Shell: executes command from user.
- Terminal: wrapper program which runs shell.

### Standard streams
A process can use the following streams:
    - 0 - stdin (input from keyboard)
    - 1 - stdout
    - 2 - stderr

### Monolithic Structure - Original UNIX
- Simple, fast, and efficient OS with a single kernel that manages all of its core services.
- The original UNIX had limited structuring due to limited hardware functionality. The UNIX OS consists of:
    - System programs
    - Kernel. Provides:
        - File system
        - CPU scheduling
        - Memory management


## Lecture 3 - Introduction to processes

### Process
- An OS executes various programs that run as processes.
    - Process: program in execution, progresses sequentially.
- Program: passive entity stored on disk (executable file)
- Process: is active
- A single program can be several processes: the same program run multiple times.

### States for a process
- New: process is being created
- Running: instructions are being executed
- Waiting: process is waiting for event (e.g I/O)
- Ready: process waits to be assigned to processor
- Terminated: process no longer executing

### Process Control Block (PCB)
- Includes information associated with each process and allows for the OS to switch between processes

## Lecture 4 - IPC: Message Queues

### What are message queues
- Form of IPC (Inter-process communication) that allow processes to exchange structured messages asynchronously.
- Messages are stored in a queue which receiver must retrieve.

### Asynchronously sending
- No wait, message is sent immediately and requires a message queue so that messages are not overwritten.

### Synchrounous sending
- Sender waits for receiver acknowledgement and does not require message queue.

### Message queues in POSIX
- Message queues are viewed as files.
    - These have write/read permissions.
- Default message queue size is 10.
- Default message size is 8192 bytes.

### Example: message queues
```C
#include <stdio.h>

int main() {
    mqd_t queue = mq_open("/my_queue", O_CREAT | O_WRONLY, 0666, NULL);
    mq_send(queue, "cat", )

}
```

