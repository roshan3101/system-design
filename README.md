# Design Patterns Repository

This repository collects implementations of the classic GoF design patterns plus a few larger system-design exercises.

## Organization
- `Creational_Patterns/` — object creation patterns (Factory, Abstract Factory, Builder, Prototype, Singleton).
- `Structural_Patterns/` — composition/interface patterns (Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy).
- `Behavioral_Patterns/` — interaction/algorithm patterns (Chain of Responsibility, Command, Iterator, Mediator, Memento, Observer, State, Strategy, Template Method, Visitor, Null Object, Interpreter).
- `Problems/` — larger case studies (e.g., Payment Gateway, Spotify-like player, Zomato clone, Document Editor, Notification System).

## How to Build Examples
Each pattern folder has its own `main.cpp` and `README.md` with commands. Typical build:
```bash
g++ -std=c++17 -Wall -Wextra -o demo main.cpp
./demo
```

## Coverage
All 23 GoF patterns are represented. Behavioral includes additional Null Object example.

## Contributing
- Add new examples under the appropriate group folder.
- Keep each example self-contained with a short README and build instructions.
- Prefer C++17 for consistency.
