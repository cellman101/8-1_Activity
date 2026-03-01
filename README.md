# 🛒 Corner Grocer Item-Tracking Program (C++)

**Course:** CS 210 – Programming Languages  
**Language:** C++  
**Developer:** Ty Yahraus  

---

## 📌 Project Overview

The Corner Grocer Item-Tracking Program analyzes daily purchase records to determine how frequently each item is purchased. The goal of the project was to help store management reorganize the produce section based on purchasing patterns and customer demand.

The program reads a text file containing purchased items, calculates item frequencies, creates a backup data file (`frequency.dat`), and provides a user-friendly menu that allows users to:

- Look up the frequency of a specific item
- Print all item frequencies
- Display a histogram visualization
- Exit the program

---

## 🚀 Features

- Reads data from `CS210_Project_Three_Input_File.txt`
- Automatically generates backup file `frequency.dat`
- Uses `std::map` to store and calculate item frequencies
- Case-insensitive item lookup
- Menu-driven console interface
- Input validation for user selections
- Histogram visualization using asterisks

---

## 🛠 Technologies Used

- C++
- Standard Template Library (STL)
- `std::map`
- File I/O (`ifstream`, `ofstream`)
- Object-Oriented Programming principles

---

## 🧠 What I Did Well

- Designed a dedicated `GroceryTracker` class with proper encapsulation
- Used clear and descriptive naming conventions
- Implemented input validation to prevent runtime errors
- Applied best practices for readability and maintainability
- Structured the program to separate data processing from user interaction

---

## 🔧 Potential Improvements

- Sort output by highest frequency instead of alphabetical order
- Add enhanced file validation and error handling
- Support multi-word item names
- Expand visualization formatting for improved readability

These enhancements would improve efficiency, robustness, and scalability.

---

## 🧩 Challenges & Solutions

The most challenging aspect was managing file input/output and properly structuring frequency tracking using `std::map`. Implementing case-insensitive functionality also required careful handling of string transformations.

I overcame these challenges by:

- Reviewing STL documentation
- Testing incrementally
- Using structured debugging methods
- Refining logic through multiple iterations

---

## 📈 Transferable Skills Developed

- File handling and data parsing
- Use of C++ STL containers
- Object-oriented design
- Input validation and error handling
- Writing modular, maintainable code
- Designing menu-driven applications

These skills directly transfer to larger-scale software development and cybersecurity-related projects.

---

## 📚 Maintainability & Design

This program was designed to be:

- Modular
- Readable
- Adaptable for future enhancements
- Easy to debug and extend

Encapsulation through classes ensures that additional features (such as database storage or GUI integration) could be implemented with minimal restructuring.

---

## ▶️ How to Build & Run

Using Visual Studio Developer Command Prompt:

```bash
cl /EHsc /std:c++17 main.cpp
.\main.exe
