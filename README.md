# Minitalk Project Guide

## Introduction

The "minitalk" project is a 42 Roma LUISS Unix-based project focusing on interprocess communication. It involves signal-based message transmission from a client to a server, providing hands-on experience with signal handling and process communication. It's implemented in C and it serves as an educational project that demonstrates interprocess communication (IPC) using custom signals.
This guide provides an overview of the project, its purpose and how to get started.

## Overview

In the "minitalk" project, there are two main components: a server and a client. The client sends a message to the server by encoding characters as sequences of custom signals (`SIGUSR1` and `SIGUSR2`). The server decodes these signals to reconstruct and print on the display the message.
You must create a communication program in the form of a client and a server:
-  The server must be started first. After its launch, it has to print its PID (Process ID).
-  The client takes two parameters: the server PID and the string to send.
-  The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
-  If you want to insert spaces in the message then you have to put the string between two quotes.
-  The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long (1 second for displaying 100 characters is way too much!).
-  Your server should be able to receive strings from several clients in a row without needing to restart.
-  The communication between your client and your server has to be done only using UNIX signals.
-  You can only use these two signals: SIGUSR1 and SIGUSR2.
-  You can use your projects "libft" and "ft_printf".

## Prerequisites

To run the "minitalk" project, you'll need the following prerequisites:

-  Unix-like operating system (Linux, macOS, or similar).
-  C compiler (e.g., GCC).

## Functions Allowed

You are allowed to use the following functions:
-  write
-  ft_printf (only if you coded it and/or any equivalent of ft_printf that YOU coded)
-  signal
-  sigemptyset
-  sigaddset
-  getpid
-  malloc
-  free
-  pause
-  sigaction
-  kill
-  sleep
-  usleep
-  exit

## Installation

1. Clone the GitHub repository to your local machine:

   ```bash
   git@github.com:99shandhokhan88/minitalk.git
   ```

2. Navigate to the project directory:

   ```bash
   cd minitalk
   ```

3. Compile the server and client:

   ```bash
   make
   ```

## Server

1. Start the server by running the following command:

   ```bash
   ./server
   ```

   The server will display its PID (Process ID).

## Client

1. Start the client by running the following command:

   ```bash
   ./client [server_pid] ["message"]
   ```

   Replace `[server_pid]` with the actual PID of the server (you can find it when the server starts), and `[message]` with the message you want to send.

2. The client will encode the message into signals and transmit them to the server.

3. The server will decode the signals and display the received message.


## Overall Architecture:

The project consists of two main components: a server and a client. The client sends a message to the server by encoding characters as sequences of SIGUSR1 and SIGUSR2 signals. The server decodes these signals to reconstruct and display the message.

## Signal Transmission:

Signal transmission between the client and server is achieved by using kill to send signals from the client to the server. SIGUSR1 signals represent binary 1, while SIGUSR2 signals represent binary 0.

## SIGUSR1 and SIGUSR2:

SIGUSR1 and SIGUSR2 are custom signals used to transmit binary data. In this project, they are used to send 1s and 0s, respectively, to represent characters in the message.

## struct sigaction:

The struct sigaction data structure is used to specify how signals should be handled. It allows you to define a signal handler function, such as ft_btoa, which is called when the specified signal is received.

## Message Reconstruction:

The server reconstructs the message by accumulating bits received from the client and converting them into characters. When a character is complete (8 bits), it is displayed, and the process continues for the next character.

## Challenges and Solutions:

Some challenges might include signal synchronization between client and server, ensuring reliable signal transmission, and handling edge cases. These can be overcome through careful signal handling and error checking.

## siginfo_t Structure:

siginfo_t is a structure that provides additional information about signals. In "minitalk," it can be used to access the PID of the client process, among other details.

## Error Handling:

Error handling might involve checking for lost signals or corrupted data. To enhance reliability, you can implement acknowledgment mechanisms between the client and server.

## Optimizations and Improvements:

Some potential improvements include adding acknowledgment signals for reliable communication, optimizing for speed or efficiency, and enhancing error checking and recovery mechanisms for robustness.

## Used Functions

### `signal()`
- **Description:** The `signal()` function is used to set up signal handlers for specific signals. It associates a specified function (`funct`) with a particular signal (`signum`).
- **Usage in Minitalk:** In the project, `signal()` could be used to set up signal handlers for `SIGUSR1` and `SIGUSR2` to handle the received signals. However, the project uses `sigaction()` instead of `signal()` for more precise control over signal handling.

### `sigaction()`
- **Description:** The `sigaction()` function is used to examine or specify the action to be taken when a specific signal is delivered. It provides more control and flexibility for signal handling compared to `signal()`.
- **Usage in Minitalk:** In the project, `sigaction()` is used to set up signal handlers for `SIGUSR1` and `SIGUSR2`. It allows the program to capture additional information, such as the sender's PID, using `info->si_pid`.

### `kill()`
- **Description:** The `kill()` function is used to send signals to a specified process or process group. It can be used to send various signals to processes.
- **Usage in Minitalk:** Both the client and server in the Minitalk project use `kill()` to send signals to each other. The client sends signals representing bits of the string, and the server sends signals confirming the receipt of bits.

### `getpid()`
- **Description:** The `getpid()` function returns the Process ID (PID) of the calling process.
- **Usage in Minitalk:** The server in the Minitalk project uses `getpid()` to retrieve its own PID, which is useful for displaying it when the server is executed.

### `pause()`
- **Description:** The `pause()` function causes the calling process to sleep until a signal is delivered that either terminates the process or invokes a signal-catching function.
- **Usage in Minitalk:** While `pause()` is mentioned in the description, it's not used in the Minitalk project code. It's typically used in scenarios where a process needs to wait for signals indefinitely.

### `usleep()`
- **Description:** The `usleep()` function suspends the calling thread for a specified number of microseconds.
- **Usage in Minitalk:** It could be used for microsecond-level delays if necessary.

In summary, these functions play essential roles in handling signals, obtaining process information, and controlling timing within the Minitalk project. However, the project primarily relies on `sigaction()` and `kill()` for signal handling and communication between the client and server processes.


## Customization

Feel free to customize the "minitalk" project to suit your needs. You can modify the server or client code to add additional features, error handling, or signal processing logic.

## Bonus Features:
-  Unicode characters like 🦁 are already supported in the mandatory part and it depends on your terminal.
-  Sending back a read receipt can be achieved by using the sigaction structure, that allows to access metadata about signal transmission.
-  The client then displays a message on the console for each bit acknowledged. It prints “Received bit 1” for SIGUSR1and "Received bit 0" for SIGUSR2. This can help visualize the communication process.

### Signal Reliability

Ensuring signal reliability is essential in the "minitalk" project. Consider implementing techniques such as acknowledgment mechanisms, error checking, and retransmission to enhance signal reliability.

### Error Handling and Recovery

Robust error handling and recovery are crucial. Strategies include checksums, timeouts, logging, and signal quality monitoring to detect and recover from errors in signal transmission.

### Performance Optimization

Optimizing performance can involve buffering, parallel processing, signal compression, batch processing, and system-level optimizations to handle large volumes of data efficiently.

## Contributing

Contributions to the "minitalk" project are welcome. Feel free to open issues, suggest improvements, or submit pull requests.
