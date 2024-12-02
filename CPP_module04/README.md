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