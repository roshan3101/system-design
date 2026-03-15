# Chain of Responsibility – ATM Cash Dispenser (C++)

Models an ATM that breaks a withdrawal amount into available note denominations using a responsibility chain.

## Structure
- `CashHandler` – holds a `denomination` and `next` handler; dispenses as many notes as possible, passes remainder down the chain, errors if it can’t be served.
- Chain used: 2000 → 500 → 200 → 100.
- `main.cpp` – builds the chain and tests several withdrawal amounts.

## Running
From `ChainOfResponsibility_ATM/`:
```bash
g++ -std=c++17 main.cpp -o main
./main
```
Requests divisible by 100 print the notes dispensed; others surface an error.

## Extension ideas
- Add availability tracking per denomination and skip exhausted handlers.
- Support currency-specific minimum units (e.g., ₹50) by inserting more handlers.
- Add logging/auth checks before dispensing to combine with Proxy or Decorator examples.

