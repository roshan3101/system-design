# Singleton Design Pattern

## What is Singleton?
Singleton is a creational design pattern that ensures:
1. Only one instance of a class exists.
2. A global access point is provided to that instance.

## How it is implemented in this folder
In [main.cpp](C:\Users\hp\Documents\GitHub\system_design\Singleton_Design_Pattern\main.cpp):

1. `Singleton` has a private constructor, so objects cannot be created directly from outside.
2. `getInstance()` returns the same object every time.
3. A local static object is used inside `getInstance()`:
   - `static Singleton instance;`
   - This is thread-safe in C++11 and later.
4. Copy constructor and copy assignment are deleted to prevent duplication.

## Flow in `main()`
1. `s1 = Singleton::getInstance()`
2. `s2 = Singleton::getInstance()`
3. `s1 == s2` is true, proving both pointers refer to the same instance.

## Why this approach is good
1. Simple and safe implementation (Meyers Singleton).
2. No manual memory management for the singleton instance.
3. No explicit mutex handling needed for initialization in modern C++.
