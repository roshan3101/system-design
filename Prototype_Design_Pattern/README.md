# Prototype Design Pattern - Character Loadouts

Create new character builds by cloning a prototype instead of re-constructing from scratch.

## Components
- `Prototype` interface exposes `clone()` and `print()`.
- `CharacterLoadout` holds `name`, `level`, and a list of `items`. `clone()` deep-copies the vector so each clone can diverge.

## Build & Run
```bash
cd Prototype_Design_Pattern
g++ -std=c++17 -Wall -Wextra -o prototype main.cpp
./prototype
```

## Expected Output
```
Base Mage (lvl 10) with items: Staff, Robe, Health Potion
Fire Mage (lvl 10) with items: Staff, Robe, Health Potion, Fire Tome
Ice Mage (lvl 12) with items: Staff, Robe, Health Potion, Frost Wand
Base Mage (lvl 10) with items: Staff, Robe, Health Potion
```

## Why Prototype
- Fast creation of similar objects with minor tweaks (no repetitive initialization).
- Ensures clones start from a consistent base configuration.
- Deep copy keeps clones independent (mutating one does not affect others).
