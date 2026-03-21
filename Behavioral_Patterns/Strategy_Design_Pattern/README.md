# Strategy Design Pattern

## What is the Strategy Pattern?
The Strategy pattern is a behavioral design pattern that defines a family of algorithms (or behaviors), puts each one in a separate class, and makes them interchangeable at runtime.

Instead of hard-coding behavior inside one large class, you compose the class with small behavior objects. This keeps code flexible and follows composition over inheritance.

## How it is implemented in this folder
This implementation models robot abilities as independent strategies:

1. Strategy interfaces:
   - `Talkable` with `talk()`
   - `Walkable` with `walk()`
   - `Flyable` with `fly()`

2. Concrete strategies:
   - Talking:
     - `NormalTalk` -> prints a normal greeting
     - `NoTalk` -> prints `...`
   - Walking:
     - `NormalWalk` -> prints normal walking behavior
     - `NoWalk` -> prints cannot walk
   - Flying:
     - `NormalFly` -> prints flying behavior
     - `NoFly` -> prints cannot fly

3. Context class:
   - `Robot` stores pointers to `Talkable`, `Walkable`, and `Flyable`.
   - Its methods `talk()`, `walk()`, and `fly()` delegate to the injected strategy objects.
   - `projection()` is kept abstract for robot-specific behavior.

4. Concrete robot:
   - `CompositionRobot` extends `Robot` and implements `projection()`.

5. Runtime composition (in `main()`):
   - `CompositionRobot(new NormalTalk(), new NormalWalk(), new NormalFly())`
   - This shows how behavior is selected by composition.

## Why this is Strategy Pattern
- Behaviors are separated from the `Robot` class.
- Behavior classes share common interfaces and are interchangeable.
- The `Robot` can use different behavior combinations without changing its own code.

## Quick extension example
To add a new behavior, create another class implementing one of the interfaces and inject it while creating the robot.  
Example: add `SilentFly : public Flyable` and pass `new SilentFly()` to the `Robot` constructor.
