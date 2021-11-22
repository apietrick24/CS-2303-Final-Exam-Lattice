# CS 2023 Systems Programming Concepts - Final Exam: Lines in a Lattice

## The Task

This assignment was the final project in WPI's Systems Programming Concepts course in the Fall of 2021 and served as the course's final exam. It consisted of two parts: 1) a programming problem that was the capstone of everything covered in the course technically and 2) a set of conceptual questions to test our understanding of the course's themes. In this repository, you can find my solution to the assignment's programming problem.

The programming problem consisted of creating and running functions on a lattice. We were given a text file consisting of point locations and values and were told to produce code that would be able to find the line with the largest accumulated value through a given point. A line was defined by a point and a slope, which consisted of the change of y and z in respect to one unit of change in x (hence dx was always 1 for any line (specifically, (0, 0, 0)). Other than a few requirements about documenting the progress of development, all of the elements of the implementation were left for me to figure out. No files were given to me at all for this project. 

## My Approach

I took the traditional Object-Oriented approach and started by going to the smallest possible part of the problem, that of defining and holding points, and start to create classes as I worked my up through the scope. My solution hinges on the interactions between four classes: Point, Space, Line, and LinkedList. 

The Point class is more or less just a structure that holds the location of a point and its value. I decided to make it its own class just to make accessing its information easier and in case I needed to later scale elements of my implementation. 

The Space class is easily the most important class of the four. It houses a three-dimensional vector of Points and accesses those points to create lines. The Space class is the only class that production needs to create to find the line with the largest accumulated value.

As stated earlier, a line is defined by a point and a slope (dx = 1, dy, and dz). In addition to these variables, the Line class also has a linked list of all points there are on the line. Because a line cannot exist in a void, only the Space class can actually create a Line object.

Both the Line class and the code in production need to be able to hold objects (Points and Lines respectively), I decided to implement a generic linked list that could add and get objects. I had no purpose for a remove function, so I skipped writing one for this implementation. 

The production file handles actually solving the given problem with a few simple steps:e pipeline:
- Reading the passed command line arguments and making sure they are all valid. If any of these arguments were not valid, the program will ask the user for valid ones
- Using the given text file to create the lattice and define every point and its corresponding value
- Getting every possible* line through the passed point and calculating their accumulated value 
- Printing out the line that has the largest accumulated value 

Most of my time was spent coding and implementing the Point, Space, Line, and LinkedList classes.

Like all of the previous assignments for this course, I had to create a comprehensive sequence diagram of my solution's design. This diagram had to be as detailed as possible, showing how all objects, classes, and functions interacted in my project. You can find my sequence diagram detailing all of the inner working systems of my implementation [here](https://raw.githubusercontent.com/apietrick24/CS-2303-Final-Exam-Lattice/main/Updated%20Final%20Sequence%20Diagram.png). 

To encourage the use of test-driven development, I had to create tests for every function and class I wrote to make sure they were working as I intended before I even implemented them. Learning from my previous mistake on my [last homework assignemnt](https://github.com/apietrick24/CS-2303-Homework-5-Checkers), I got into a good habit of writing these tests and then producing the code for the functions/classes. By the end of my time on this project, I had ended up writing more than 50 subtests for my solution's implementation. While they were tedious to create, I actually found these tests really helpful and would like to use them more in my future projects.

## Obstacles 
- I decided to use the generic data type in my linked list class as a way to reduce repeated and to increase its functionality. While the concept of generics was covered in lectures, I had had no previous experience using and implementing generic in C++ before setting out to create this linked list. Luckily, with my Java knowledge and some helpful resource online, I was able to figure out a way to correctly apply generics in my linked list class. While a small stepping-stone, this challenge, and its resolution really boosted my spirit and confidence as I when to tackle the rest of the project.
- The biggest issue I ran into during this project was creating and accessing a three-dimensional space of objects. In previous assignments, we had only used two-dimensional spaces and were taught to do so through allocating memory chunks and accessing them through raw locations. I tried to adapt this approach to work with a three-dimensional space; however, I ran into a lot of issues with pointers and memory locations, which I didn't know how to properly handle by myself. Specifically, while no errors or exceptions were being raised, I was somehow not setting and accessing the memory chunk correctly. After trying my best effort to work through these issues, I realized that continuing to use this implementation of a three-dimensional space was bound to lead to even more issues that I didn't feel like I had the technical skills in C++ to handle correctly. So I decided to switch my approach and to instead learn and use C++ vector class. While there were still a few growing pains while learning how to use this class, I am very glad for this decision as it ended up saving me a lot of time and frustration later in the project. 

## Result

I am very happy with how my solution turned out. I was able to finish my implementation for this problem in just three days, about half of the time allotted for it, and ended up scoring a perfect on both parts. I'm quite proud of the technical skills I learned and used for this project. While it isn't the most technical or elegant code I have ever written, this project serves as a good showcase of all of the computer science and problem-solving skills I have accumulated over the last few years. I see both this project and this course as the end of a chapter in my progress as a computer scientist. Now that I have a good selection of the fundamental and intermediate skills in my computer scientist toolkit, I'm excited to look forward and to start to tackle more advanced and specialized topics. 
