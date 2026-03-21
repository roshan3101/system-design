# Behavioral Patterns

Patterns that encapsulate algorithms, communication, or state-related behavior:
- Chain of Responsibility (ATM cash handler pipeline)
- Command (actions as objects)
- Iterator (custom collection traversal)
- Mediator (chat room)
- Memento (DB transaction snapshot)
- Null Object (logger that does nothing)
- Observer (publish/subscribe notifications)
- State (vending machine)
- Interpreter (mini arithmetic expression evaluator)
- Strategy (runtime-pluggable behaviors)
- Template Method (algorithm skeleton with hooks)
- Visitor (document reader with visitors)

Each subfolder contains its own `README.md` and `main.cpp` example. Build with `g++ -std=c++17 -Wall -Wextra -o demo main.cpp`.
