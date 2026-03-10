# Observer Design Pattern

## What is the Observer Pattern?
Observer is a behavioral design pattern where one object (the **Subject/Observable**) maintains a list of dependent objects (the **Observers**) and notifies them automatically when its state changes.

This creates loose coupling:
- Subject does not need to know concrete observer implementations.
- Observers can be added or removed at runtime.

## How it is implemented in this folder
In `main.cpp`:

1. `IObservable` interface defines:
   - `add(IObserver*)`
   - `remove(IObserver*)`
   - `notify()`

2. `IObserver` interface defines:
   - `update(const string& channelName, const string& videoTitle)`

3. `Channel` (Concrete Observable):
   - Stores a list of subscribers (`vector<IObserver*>`)
   - Stores latest uploaded video title
   - On `uploadVideo(title)`, updates internal state and calls `notify()`

4. Concrete observers:
   - `MobileSubscriber`
   - `EmailSubscriber`
   - Both implement `update(...)` in their own way.

## Flow in `main()`
1. Create one channel: `CodeWithCPP`
2. Create three subscribers (2 mobile, 1 email)
3. Subscribe all to channel
4. Upload first video -> all subscribers receive notification
5. Unsubscribe one mobile subscriber
6. Upload second video -> only remaining subscribers are notified

## Why this is Observer Pattern
- One-to-many dependency between channel and subscribers
- Dynamic subscription management (`add/remove`)
- Automatic broadcast on state change (`uploadVideo -> notify -> update`)
