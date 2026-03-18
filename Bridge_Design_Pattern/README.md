# Bridge Design Pattern - Vehicles & Engines

Decouples the vehicle hierarchy from engine implementations so either side can vary independently while collaborating through the `Engine` interface.

## Structure
- `Engine` (implementor interface) with `start`/`stop`.
- `PetrolEngine`, `DieselEngine`, `CNGEngine` (concrete implementors).
- `Vehicle` (abstraction) holds an `Engine*` and exposes `start`/`stop`.
- `SUV`, `Sedan`, `Bolero` (refined abstractions) delegate to the engine, then add vehicle-specific messaging.
- `VehicleFactory` wires any vehicle type to any engine type at runtime.
- `VehicleController` demonstrates client use without knowing concrete classes.

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra -o bridge main.cpp
./bridge
```

## Expected Output
```
Petrol Engine Started
SUV Started
Petrol Engine Stopped
SUV Stopped
-----------------------------
Diesel Engine Started
Sedan Started
Diesel Engine Stopped
Sedan Stopped
-----------------------------
CNG Engine Started
Bolero Started
CNG Engine Stopped
Bolero Stopped
```

## Notes
- Extend by adding a new `Engine` subtype or a new `Vehicle` subclass; `VehicleFactory` is the only place needing an update to wire combinations.
- Uses raw pointers for clarity; swap to `std::unique_ptr` to avoid manual deletes in production code.
