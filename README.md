# Pipex

## Description
This project aims to reproduce the behavior of the shell pipe (`|`) command in C. It handles the execution of commands with arguments and redirects the output from one command to the input of another, simulating the functionality of pipes in Unix/Linux systems.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Implementation Details](#implementation-details)
- [Project Structure](#project-structure)
- [Bonus Features](#bonus-features)
- [Resources](#resources)

## Installation
```bash
# Clone the repository
git clone https://github.com/yasserbarhdadi/pipex.git

# Navigate to the project directory
cd pipex

# Compile the program
make
```

## Usage
The program takes 4 arguments:
```bash
./pipex file1 cmd1 cmd2 file2
```

This will execute the command: `< file1 cmd1 | cmd2 > file2`

### Example:
```bash
./pipex infile "ls -l" "wc -l" outfile
```
This is equivalent to: `< infile ls -l | wc -l > outfile`

## Features
- Execute commands with their arguments
- Handle input and output redirections
- Manage pipes between commands
- Error handling for various scenarios
- Memory management

## Implementation Details
- Uses `fork()` to create child processes
- Implements `dup2()` for file descriptor redirection
- Executes commands using `execve()`
- Manages file operations with appropriate permissions

## Project Structure
```
pipex/
├── Makefile
├── inc/
│   └── pipex.h
├── src/
│   ├── main.c
│   ├── pipex.c
│   ├── utils.c
│   ├── command.c
│   └── error.c
└── README.md
```

## Bonus Features
- Support for multiple pipes: `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`
- Support for here_doc: `./pipex here_doc LIMITER cmd1 cmd2 file2`

## Resources
- [Unix Pipes Explained](https://www.geeksforgeeks.org/piping-in-unix-or-linux/)
- [fork() System Call](https://www.geeksforgeeks.org/fork-system-call/)
- [execve() Function](https://man7.org/linux/man-pages/man2/execve.2.html)
- [dup2() Function](https://man7.org/linux/man-pages/man2/dup.2.html)

---
