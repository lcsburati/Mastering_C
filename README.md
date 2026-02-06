# Core Utils

[Leia em Português](README.pt-br.md)

**Objective:** To show my knowledge about the C language and its particularities.

This project is a collection of my own implementations of standard C library functions. I am building this to understand how things work under the hood.

## How to Run

You can compile the project using `gcc`:

```bash
gcc main.c -I./include -o main.out
./main.out
```

## Functions

### String Utils

*my_strlen*: 
    - Args: char array (String).
    - Return: integer (String lenght).
    - Process: 
        I start by declaring a `lenght` variable outside the loop to prevent it from resetting. A while loop was choosen because i prefer to work with pointer arithmetic. (But a `for` loop with a control variable `i` could also be used).
        Inside the while loop, we increment both the `length` counter and the pointer itself. Since `*str` starts by pointing to the first element (`str[0]`), incrementing the pointer allows us to step through each memory address until we hit the `\0` which has a value of 0 (`false`). Finally, we return the length.
*my_tolower:
    - Args: char array (String).
    - Return: char array (String).
    - Process:
        I start by declaring the variable that will serve to define the size of the string (using the previously created function) and allocating a new string with malloc. Although characters are always 1 byte, I chose to make sizeof(char) explicit for better readability. Then, I ensure that the allocation was successful (otherwise, the function returns NULL). Next, I declare the pointer *ptr, which will serve as a cursor, while *new_string will function as our anchor (base pointer). After that, I define the distance between 'a' and 'A' to facilitate the conversion, since this value is constant in the ASCII table. I then start the while loop, chosen to work with pointer arithmetic. The first step of the conversion is to know if the element of *str is in uppercase; to do this, we just need to check if it is within the range ['A', 'Z'] (which the compiler will understand as integers due to ASCII encoding). If it is, I define that the cursor pointer *ptr will receive the value of *str plus the calculated distance, converting the character to lowercase. Then, we increment the cursor pointer and the base array to move to the next character in both. We don't do this increment in *new_string, as we need this pointer to continue pointing to the first element of the array for the final return. If the character is already lowercase or a symbol, *ptr simply receives the original value of *str. Finally, we point the last element of *ptr as the null terminator \0 and return new_str.

### Math Utils
(Coming soon...)
