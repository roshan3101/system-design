# Null Object Pattern - Logger

Use a do-nothing logger to avoid null checks when logging is optional.

## Components
- `Logger` interface with `info` and `error`.
- `ConsoleLogger` writes to stdout/stderr.
- `NullLogger` implements the same interface but performs no work.
- `PaymentService` depends on `Logger&` and never checks for null; behavior changes by injecting a different logger.

## Build & Run
```bash
cd Null_Object_Pattern
g++ -std=c++17 -Wall -Wextra -o null_logger main.cpp
./null_logger
```

## Expected Output
```
-- With logging --
[INFO] Processing payment of $100
[INFO] Payment successful
[ERROR] Invalid amount
-- No logging (Null Object) --
```
(Second block produces no log lines because `NullLogger` swallows calls.)

## Why Null Object
- Removes repetitive `if (logger)` checks.
- Safe default object avoids `nullptr` crashes while keeping polymorphism.
