# Flyweight Design Pattern - Asteroid Field

Shares heavy, intrinsic asteroid data (size, weight, color, type) across many logical objects, while keeping lightweight, extrinsic state (position) outside the flyweight so millions of asteroids can be represented efficiently.

## Structure
- `Asteriod` (flyweight): holds intrinsic attributes used by many asteroids.
- `AsteriodExtrensicContext`: stores per-instance data `x`/`y` for where an asteroid appears.
- `AsteroidFlyweightFactory`: caches flyweights keyed by intrinsic attributes and returns existing instances when requested.
- Client (`main`): requests flyweights for a million asteroids, pairing each with a fresh context before calling `display`.

## Build and Run
```bash
cd Flyweight_Design_pattern
g++ -std=c++17 -O2 -o flyweight main.cpp
./flyweight
```
Note: `main` currently iterates 1,000,000 times and prints every asteroid; lower `asteriodsCount` for quicker, quieter runs.

## Example Output (with a small count)
```
Asteriod of type Type A with color Red and weight 742 is at position (113,927)
Asteriod of type Type B with color Green and weight 58 is at position (441,12)
```

## Notes
- Intrinsic state is shared; only the context varies per asteroid, illustrating classic flyweight savings.
- The factory never deletes cached flyweights; add cleanup or smart pointers if long-lived reuse is not acceptable.
