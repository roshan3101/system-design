# Decorator Design Pattern – Mario Power‑Ups

This example wraps a `Character` (Mario) with dynamic power‑ups using the Decorator pattern.

## Structure
- `Character` – abstract component with `getAbilities()`.
- `Mario` – concrete component.
- `CharacterDecorator` – inherits `Character`, holds a `Character*` (the wrapped object).
- `Heightup`, `Gunpower`, `Starpower` – concrete decorators appending abilities.

## Key Points
- Decorators **must inherit** from `Character` so they can replace the wrapped object transparently.
- Give `CharacterDecorator` a virtual destructor that deletes `character`, or use smart pointers to avoid leaks.
- Composition chain example: `Mario -> Heightup -> Gunpower -> Starpower`.

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra -o decorator main.cpp
./decorator
```

Expected output:
```
Basic Mario Mario
Height up Mario with height
GUn Power Mario with height with gunpower
Star POwer Mario with height with gunpower with Star Power
```
