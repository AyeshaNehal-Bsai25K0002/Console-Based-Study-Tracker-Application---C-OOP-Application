# Study Tracker Application (C++ OOP Project)

## Overview
This is a console-based Study Tracker System developed in C++ using Object-Oriented Programming (OOP) principles.

It helps students track:
- Their Study sessions
- Their Study hours
- Their Subject details
- Their Student records

The project demonstrates core OOP concepts such as encapsulation, composition, static members, and arrays of objects.


## Features

- Add study sessions for students
- View student details
- View all study sessions
- Track total number of students
- Menu-driven system for user interaction

---

## Classes Used

## Subject Class
Stores information about a subject.

### Attributes:
- Subject name
- Credit hours
- Teacher name

### Methods:
- Constructor to initialize subject data
- displaysubjectdetails() to display subject information

---

## studysession Class
Represents a study session record.

### Attributes:
- Duration
- Topic
- Date (DD/MM/YY format)

### Methods:
- Default constructor
- Parameterized constructor
- displaysession()
- getduration()

---

## Student Class
Handles student data and study tracking.

### Attributes:
- Student ID (auto-generated)
- Static student counter
- Name
- Total study hours
- Subject object (composition)
- Array of study sessions (maximum 10)
- Session counter

---

### Key Functions

- displaystudentdetails() → Displays student information  
- settotalstudyhours(int) → Sets study hours  
- addstudyhours(int) → Adds study hours  
- getstudyhours() → Returns total study hours  
- addstudysession() → Adds a new study session  
- viewallstudysession() → Displays all stored sessions  
- getttotalstudents() → Returns total number of students  

---

## Static Member

```cpp
static int studentcount;
