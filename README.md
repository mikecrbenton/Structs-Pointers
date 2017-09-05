# Structs-Pointers
CSC 250 - Structs and Passing Pointers to Functions, 

## Assignment Overview:
Your assignment is to create a program that uses structures, malloc, and passing pointers to functions. 
You will create a structure that holds info for a student file. 
It must have:
-	2 character arrays (50 characters) to hold the first name and last name. 
-	A short character array to hold the letter grade for the course (A, C, A+…)
-	An int array that holds the scores of 5 tests for the student 
-	Add <time.h> header to your file, and create a timestamp for entry time  
### Part 1
In main() create a pointer to your structure, malloc memory for the structure.  
Do NOT prompt/read in data about your Structure in main(), and do NOT print out the file info in main()
These must be functions in which your structure is passed as a parameter(pointer).
### Part 2
Write a function that takes user input to your structure and a separate function that prints out the 
contents of this file structure. 
### Extra Credit
Instead of a single Structure, create a Struct[] array of multiple students, with a menu that 
allows the user to input new students into the array, and to print out the array of structs.
