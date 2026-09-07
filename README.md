# COS214_Practical-4 — TaskForge

Construction project management system using Composite, Iterator, State and Decorator.

## Build and run (Docker)

```
docker build -t taskforge .
docker run --rm taskforge
```

## Run Valgrind

```
docker run --rm taskforge valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./taskforge
```

## Run GDB

```
docker run --rm -it taskforge bash
gdb ./taskforge
```

## Build and run (native Linux/WSL/Git Bash)

```
make rebuild
./taskforge
```
