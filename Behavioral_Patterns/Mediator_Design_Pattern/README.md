# Mediator Design Pattern - Chat Room

Users communicate through a `ChatRoom` mediator instead of directly messaging each other. The mediator centralizes message routing and joins/leaves.

## Components
- `ChatMediator` interface defines `broadcast` and `addUser`.
- `ChatRoom` keeps a list of users and forwards messages to everyone except the sender.
- `User` holds a reference to the mediator and calls `send`/`receive`.

## Build & Run
```bash
cd Mediator_Design_Pattern
g++ -std=c++17 -Wall -Wextra -o chat main.cpp
./chat
```

## Expected Output
```
Alice joined the room.
Bob joined the room.
Carol joined the room.
-- Alice says: Hi all! --
[Bob receives] Alice: Hi all!
[Carol receives] Alice: Hi all!
-- Bob says: Hey Alice! --
[Alice receives] Bob: Hey Alice!
[Carol receives] Bob: Hey Alice!
-- Carol says: Ready for the meeting? --
[Alice receives] Carol: Ready for the meeting?
[Bob receives] Carol: Ready for the meeting?
```

## Why Mediator
- Removes tight coupling between users; adding filters/logging in the mediator does not change `User`.
- Simplifies many-to-many communication into one-to-many via the mediator hub.
