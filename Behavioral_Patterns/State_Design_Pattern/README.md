# State Design Pattern - Vending Machine

A vending machine switches behavior based on its internal state (no coin, has coin, dispensing, sold out). The pattern keeps state-specific logic inside separate classes instead of large conditionals.

## How it works
- `State` interface declares `insertCoin`, `selectProduct`, `dispense`.
- Concrete states: `NoCoinState`, `HasCoinState`, `DispensingState`, `SoldOutState`.
- `VendingMachine` (Context) holds a `unique_ptr<State>` and delegates actions to it.
- Each state decides the next state and actions (e.g., `DispensingState` releases item then moves to `NoCoinState` or `SoldOutState`).

## Build & Run
```bash
cd State_Design_Pattern
g++ -std=c++17 -Wall -Wextra -o vending main.cpp
./vending
```

## Expected Output
```
Insert coin first before selecting Soda.
Coin inserted.
Selected: Soda
Dispensing Soda...
Coin inserted.
Selected: Chips
Dispensing Chips...
Machine is now out of stock.
Cannot accept coin; sold out.
Sold out; cannot select Water.
```

## Why State Pattern
- Encapsulates state-specific rules in classes instead of `if/else` checks.
- Transitions are explicit (`setState`) and local to each state's logic.
- Adding a new state (e.g., `MaintenanceState`) does not change existing states.
