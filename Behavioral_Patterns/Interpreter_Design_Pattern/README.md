# Interpreter Design Pattern - Mini Expression Evaluator

Parses and evaluates simple arithmetic expressions with variables using an AST of expression objects.

## Components
- `Expression` interface with `interpret(Context&)`.
- Terminal expressions: `NumberExpression`, `VariableExpression`.
- Nonterminal expressions: `AddExpression`, `SubtractExpression` compose expressions recursively.
- `Context` stores variable bindings (`a`, `b`, etc.).

## Build & Run
```bash
cd Behavioral_Patterns/Interpreter_Design_Pattern
g++ -std=c++17 -Wall -Wextra -o interpreter main.cpp
./interpreter
```

## Expected Output
```
Expression: a + 3 - b
a = 10, b = 4
Result: 9
```

## Why Interpreter
- Encapsulates grammar rules in classes, enabling new operations (e.g., multiply/divide) by adding new expression nodes.
- Separates parsing/tokenizing from evaluation via the `Context` and AST.

## UML
```mermaid
classDiagram
    class Context {
        -vars
        +set(name, value)
        +get(name)
    }
    class Expression {
        <<interface>>
        +interpret(Context)
    }
    class NumberExpression
    class VariableExpression
    class AddExpression
    class SubtractExpression

    Expression <|.. NumberExpression
    Expression <|.. VariableExpression
    Expression <|.. AddExpression
    Expression <|.. SubtractExpression
    AddExpression --> Expression : left/right
    SubtractExpression --> Expression : left/right
    Expression --> Context : reads
```
