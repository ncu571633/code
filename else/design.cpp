/*
Question 1:

Let's say we're developing a vector graphics application. It will allow the user to create lines, rectangles, circles, text, etc. and manipulate them independently - move them, re-size them, etc. Design an object model for this application.

• How would you model the representation of the document in an object oriented language?
• What classes would you define?
• What methods would you have? What would your API look like?

Once you're finished - select "Submit Solution" to solve question 2.
   */

1. extract common shared methods and make them virtual; 
try to use class composition


2. 
base class: shape
virtual methods: 
void move(direction, distance);
void resize(double size);

derived class:
class lines
class rectangles: contains 3 line class member
class circles:
class text

These classes rewrite the virtual methods declared in the base class.
