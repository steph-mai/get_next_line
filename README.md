*This project has been created as part of the 42 curriculum by stmaire* 

# Get Next Line

## Description

The goal of the **Get Next Line** project is to write a function in C that returns a line read from a file descriptor. This project is a fundamental part of the 42 curriculum, designed to teach students how to manage file input/output, static variables, and dynamic memory allocation without memory leaks.

The function allows reading from both text files and standard input, one line at a time, regardless of the buffer size defined at compilation.

**Key Features:**
* Reads one line at a time until the end of the file.
* Handles variable buffer sizes (`BUFFER_SIZE`).
* **Bonus Implemented:** Supports multiple file descriptors simultaneously (e.g., reading from file A, then file B, then resuming file A) using a single static variable (array of pointers).

## Instructions

### Compilation

Because the function must read files with a specific buffer size, you should add the `-D BUFFER_SIZE=n` option to your compiler call. This defines the buffer size for `read()`.

The project compiles with or without this flag (a default value is set in the header). The value will be adjusted by peer evaluators and the Moulinette.

**Compilation command:**

* **Mandatory:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
* **Bonus:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Resources

### References

The following documentation was used to implement the core concepts of this project:

* **System Calls & File Descriptors**
    * [Man page: read(2)](https://man7.org/linux/man-pages/man2/read.2.html) - Official documentation for the `read` function.
    * [Man page: open(2)](https://man7.org/linux/man-pages/man2/open.2.html) - Understanding file flags (`O_RDONLY`).
    * [Wikipedia: File Descriptor](https://en.wikipedia.org/wiki/File_descriptor) - General concept of FDs in Unix.

* **Memory Management & C Concepts**
    * [Man page: malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html) - Dynamic memory allocation.
    * [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html) - Tool used to check for memory leaks.
    * [GeeksforGeeks: Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Explanation of how static variables persist between function calls.

### AI Utilization

An AI assistant was consulted for technical support during specific phases of development:

* **Debugging:** Assisted in analyzing segmentation faults and "double free" errors within `ft_join_and_free` function.
* **Testing Strategy:** Generated a `main.c` file to verify edge cases and validate the logic for the bonus part.
* **Documentation:** Assisted in structuring and drafting this README file to ensure clarity.

## Algorithm & Implementation

The project relies on a specific workflow to handle reading lines of arbitrary length using a fixed-size buffer.

### Core Logic
The algorithm follows a three-step cycle for each call to `get_next_line(fd)`:

1.  **Read and Accumulate (Buffering):**
    * The function reads `BUFFER_SIZE` bytes from the file descriptor into a temporary buffer.
    * This buffer is immediately concatenated with the **static reserve** (which holds data left over from previous calls).
    * This process repeats in a loop until a newline character (`\n`) is detected in the reserve or the End of File (EOF) is reached.

2.  **Line Extraction:**
    * Once a newline is found, the function calculates the exact length of the line (including the `\n`).
    * Memory is allocated, and the line is copied from the reserve to be returned to the user.

3.  **Reserve Update:**
    * The remaining characters (after the `\n`) are saved back into the static variable.
    * The old memory is freed to prevent leaks. This ensures the function picks up exactly where it left off during the next call.

### Justification of Choices

* **Static Variables:** A static variable is strictly necessary because the standard `read()` function does not maintain state between calls regarding incomplete lines. The static variable acts as a persistent buffer across the program's lifecycle.
* **Bonus Implementation (Static Array):**
    * To handle multiple file descriptors (Bonus), a **static array of pointers** (`static char *reserve[FD_MAX]`) was selected instead of a linked list.