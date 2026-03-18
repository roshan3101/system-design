# Iterator Design Pattern - Linked List and Binary Tree

Provides a uniform way to traverse different aggregate structures (`LinkedList`, `BinaryTree`) through the `Iterator` interface instead of exposing internal links.

## Structure
- `Iterator<T>`: declares `hasNext()` and `next()`.
- `Iterable<T>`: factories that create iterators for a collection.
- `LinkedList` + `LinkedListIterator`: walks nodes sequentially using stored `next` pointers.
- `BinaryTree` + `BinaryTreeIterator`: pre-order depth-first traversal implemented with an explicit `stack`.

## Build and Run
```bash
cd Iterator_Design_Pattern
g++ -std=c++17 -Wall -Wextra -o iterator main.cpp
./iterator
```

## Expected Output
```
Linked List: 1 2 3 
Binary Tree: 1 2 3 
```

## Notes
- Accessors (`getNext`, `getLeft`, `getRight`) keep nodes encapsulated while allowing iterators to navigate.
- The tree iterator uses a stack to avoid recursion; order is root-left-right (pre-order).
- Swap raw pointers for `std::unique_ptr` and return smart-pointer-aware iterators if you want automatic memory management.
