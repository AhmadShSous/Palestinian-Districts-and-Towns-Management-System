# Palestinian-Districts-and-Towns-Management-System

Project Overview
This project is a C-language console application designed to manage Palestinian districts and their towns.
The system uses a doubly linked list structure where:

Each district is a node that contains a sublist of its towns.

Each town is a node linked within its district.

The project provides full functionality for adding, deleting, sorting, and updating districts and towns, with dynamic memory management and file handling.

Features
Dynamic Linked Lists:

Each district points to its towns.

Each town is connected to previous and next towns.

Radix Sort:

Districts are sorted alphabetically by name using Radix Sort.

Bubble Sort:

Towns within each district are sorted by population in ascending order.

File Handling:

Load data from an input file (districts.txt).

Save sorted data to an output file (sorted_districts.txt).

Interactive Menu (14 options):

Load input file.

Print loaded information.

Sort districts alphabetically.

Sort towns based on population.

Print full sorted information.

Add a new district.

Add a new town to a district.

Delete a town.

Delete a district (and all its towns).

Calculate total population, maximum, and minimum populated towns.

Print districts and their total population.

Update the population of a specific town.

Save to output file.

Exit the program.

Technologies Used
Language: C

Data Structures: Doubly Linked List

Algorithms: Radix Sort (for districts), Bubble Sort (for towns)

File Handling: Read/Write text files

Memory Management: Dynamic memory allocation (malloc, free)

