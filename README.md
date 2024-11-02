# Multi-threaded Logger in C++

## Overview

This repository contains a multi-threaded logging utility implemented in C++. The Logger class is designed to handle concurrent logging from multiple threads while ensuring thread safety and maintaining consistent log file access.

## Features

- **Thread-safe Logging**: Ensures that logs from different threads do not interfere with each other.
- **File Handling**: Appends log messages to a specified log file.
- **Automatic Resource Management**: Manage file resources and mutex locks.

## Getting Started

### Prerequisites

To compile and run the code, ensure you have the following installed:

- A C++ compiler (e.g., g++, clang++)
- C++11 or later

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/OmarNasserr/Task2-C-Logger.git

2. Run the compiled file:
   ```bash
   cd Task2-C-Logger
   ./main
