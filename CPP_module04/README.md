This module aims to learn about subtype polymorphism, abstract classes, interfaces

## What is polymorphism?

Polymorphism, in Object Oriented Programming (OOP), refers to the ability to use the same name for methods in related classes, but with different behaviors. In C++, polymorphism is divided into two main types:

    **Overloading Polymorphism:**
        Multiple functions or operators with the same name but different signatures (distinct parameters).
        Example: Overloading operators or constructors.

    **Subtype Polymorphism (or Overriding):**
        A method in a base class is redefined in a derived class to change its behavior.
        Allows generic code to treat different derived types the same.
        
Polymorphism allows a function in the base class to be overridden in derived classes and still be called correctly through a pointer or reference to the base class. Indicate that the function is **virtual** is essential to enable this behavior, because it allows dynamic binding (runtime) and consequently polymorphism.

## What is Deep Copy?

A deep copy means that, when copying an object, all its attributes (including those that point to other objects) are also copied recursively, so that the two resulting objects are completely independent.

Example:
    Shallow copy: Only copies pointers or references to internal objects. The two objects share the same data in memory.
    Deep copy: Creates separate copies of all data. Each object has its own independent copy of the internal attributes.

## What is an abstract class?

An abstract class is a class that:
    It cannot be instantiated directly.
    Serves as a basis for other classes.
    It has at least one purely virtual function (declared with = 0), which must be implemented by derived classes.


- Playlist about [oop theories](https://www.youtube.com/watch?v=KlIL63MeyMY&list=PL6qsRzBhn4BlSiDHoGWLj6Op4Ika8zjIC) (in PT)
