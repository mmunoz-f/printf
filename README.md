<h1>Printf</h1>

The objective of this project is to recreate one of the most used standard utils in C, it is a basic reimplementation of printf from scratch.

<h3>How to use it</h3>

Compile the library by using `make`, it will generate a '.a' file, then you can add it to your project as any other external library

```bash
gcc main.c -L. -lftprintf
```

After the -L flag you are supposed to add the path to the static library file (the .a file), in the example above the static library, is located on the root.
