# Inheritance and visibility

- A member that is redefined in a sub class will hide the corresponding member from the base class. All the alternatives for a function with a specific name from the base class will be hidden in the sub class if one or more of them is redefined in the sub class.

- A hidden member of a base class can be reached in the sub class by `baseClass::member`

- Members of a class can (as known) be `public`, `private` or `protected`. 
   - `private` members are never visible in a sub-class, while `public` and `protected` are.
   However, `protected` are only visible in a sub-class (not in other classes or top-level code).
   - The visibility of the members inherited from a base class to a sub class can be stated/modified in the sub class using the reserved words `public`, `private` or `protected` when declaring the class. (`public` in the previous example). It is only possible to make each member of a base class less visible in the sub class.
   
- A class may be a sub class to several base classes (multiple inheritance), and this is used to combine features from several classes. Watch out for ambigous members!