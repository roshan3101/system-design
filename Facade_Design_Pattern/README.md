# Facade Design Pattern – Home Theater

Provides a simple interface (`HomeTheaterFacade`) to orchestrate multiple subsystems (amplifier, DVD player, projector, lights, screen) for starting and ending a movie.

## Structure
- Subsystems: `Amplifier`, `DvdPlayer`, `Projector`, `TheaterLights`, `Screen`.
- Facade: `HomeTheaterFacade` exposes `watchMovie()` and `endMovie()` to hide setup/teardown details.
- Client: `main()` uses only the facade.

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra -o facade main.cpp
./facade
```

## Expected Output
```
Get ready to watch a movie...
Theater lights dimmed to 20%
Screen going down
Projector on
Projector in widescreen mode
Amplifier on
Amplifier volume set to 7
DVD Player on
Playing "The Matrix"

Shutting movie theater down...
DVD Player stopped
DVD Player off
Amplifier off
Projector off
Screen going up
Theater lights on
```

## Notes
- Facade keeps client code minimal and readable.
- Subsystems stay decoupled and reusable outside the facade if needed.
