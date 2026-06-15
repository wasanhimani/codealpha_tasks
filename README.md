# codealpha_tasks
This repository contains the tasks of the internship.
During my internship at CodeAlpha, I completed three C++ projects demonstrating core programming concepts including OOP, algorithms, and data structures.

The three tasks which i performed are:
1:CGPA CALCULATOR-A simple C++ program that helps students calculate their Semester GPA and Overall CGPA automatically instead of doing it manually.
How it works — Step by Step:

Enter your details — your name and program/degree name
Enter your courses — for each course you provide:

Course name
Grade you received (e.g. 4.0, 3.5, 3.0)
Credit hours (e.g. 3, 4)


It calculates your GPA — by multiplying each grade with its credit hours and dividing by total credits
Add previous semesters — if you have past semester data, you can add it to get your overall CGPA
Displays your results — shows your name, program, semester GPA, and cumulative CGPA neatly

2:SUDOKU SOLVER-A C++ program that automatically solves a 9×9 Sudoku puzzle using a smart trial-and-error technique called backtracking.
How it works — Step by Step:

A puzzle is loaded — a 9×9 grid is pre-filled with some numbers, and empty cells are represented as 0
Finds an empty cell — the program scans the grid to locate the next unfilled cell
Tries numbers 1–9 — for each empty cell it tries placing numbers one by one
Checks if it's safe by verifying three rules:

The number doesn't already exist in that row
The number doesn't already exist in that column
The number doesn't already exist in that 3×3 box


If safe → place it and move to the next empty cell
If stuck → backtrack — go back and try a different number
Repeats until solved — displays the completed grid at the end

3.BANKING MANAGEMENT SYSTEM-This is a simple console-based banking system built using Object-Oriented Programming in C++. It has four classes — Transaction, Account, Customer, and Bank — each handling a specific part of the system.
A Bank holds multiple customers, each customer can have multiple accounts, and every account keeps a history of transactions. The system supports basic banking operations like deposit, withdrawal, and fund transfer between accounts, with basic validation (no negative amounts, no overdraft). Every operation gets recorded as a Transaction with a timestamp using C's ctime.
The main() function demonstrates the whole flow — creating a customer, opening two accounts, performing transactions, and printing the account details and history.

