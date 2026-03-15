# Composite Design Pattern (C++ file system demo)

Small console demo that models a file system using the Composite pattern: `File` and `Folder` both implement the `IComponentItem` interface so callers can treat individual files and folder composites uniformly.

## Structure
- `IComponentItem` – interface with `ls`, `openAll`, `getSize`, `cd`, `getName`, `isFolder`.
- `File` – leaf node storing `name` and `size`; prints itself and returns its size.
- `Folder` – composite node holding children; can list, recursively print (`openAll`), sum sizes, and navigate to a named child folder via `cd`.
- `main.cpp` – builds a sample tree (`root` → `docs`, `desktop`) and exercises listing, recursion, navigation, and aggregate sizing.

## Running
From `Composite_Design_Pattern/`:
```bash
g++ -std=c++17 main.cpp -o main
./main
```
Expected output (abridged): a flat `ls` of root, `ls` of docs, a recursive tree via `openAll`, `ls` of `docs` reached by `cd`, and total size `11`.

## Extending
- Add new item types (e.g., shortcuts) by implementing `IComponentItem`.
- Add behaviors (rename, delete) by extending the interface and updating both `File` and `Folder`.
- Swap recursion depth/indentation rules inside `openAll` to change visualization without touching client code.

