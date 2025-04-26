# Palestinian-Districts-and-Towns-Management-System

--Project Overview:-
This project is a C-language console application developed to manage Palestinian districts and their towns.
The system uses a doubly linked list structure, where:
Each district node contains a sublist of towns.
Each town is linked to previous and next towns within its district.
The application provides full functionality for adding, deleting, sorting, and updating districts and towns, with dynamic memory management and file handling.
----------------------------------------------------------------------------------------------------

--Features:-
#Dynamic Linked Lists:
Each district points to its towns.
Each town is linked to previous and next towns.
#Radix Sort:
Districts are sorted alphabetically using Radix Sort.
#Bubble Sort:
Towns within each district are sorted based on population in ascending order.
#File Handling:
Load data from an input file (districts.txt).
Save sorted results to an output file (sorted_districts.txt).
-------------------------------------------------------------------------------------------------------

--Interactive Menu (14 Options):-
#Load the input file (Palestinian districts and their towns with population).
#Print the loaded information before sorting (as in the input file format).
#Sort the districts alphabetically using Radix Sort.
#Sort the towns within each district based on population (ascending order).
#Print the full sorted information (districts and towns).
#Add a new district to the list (and sort the list).
#Add a new town to a certain district.
#Delete a town from a specific district.
#Delete an entire district and its towns.
#Calculate the total population, and find the town with maximum and minimum population.
#Print districts and their total population (without town details).
#Change the population of a specific town.
#Save the sorted data into an output file.
#Exit the program.
-------------------------------------------------------------------------------------------------------

--Technologies Used:-
Language: C
Data Structures: Doubly Linked List
Algorithms: Radix Sort (for districts), Bubble Sort (for towns)
File Handling: Read/Write text files
Memory Management: Dynamic memory allocation (malloc, free)
--------------------------------------------------------------------------------------------------------

--How to Run:-
#1 Compile the project using a C compiler:
 gcc main.c -o districts_manager
#2 Ensure the districts.txt input file is available in the same directory.
#3 Run the executable:
 ./districts_manager
#4 Follow the interactive menu to manage districts and towns.
1)Example of districts.txt Input File Format:
  Hebron | Dura | 35000
  Hebron | Yatta | 60000
  Nablus | Asira | 20000
  Jenin | Qabatiya | 25000
2)Example of sorted_districts.txt Output File Format
  Hebron District, Population = 95000
  Dura, 35000
  Yatta, 60000
  Jenin District, Population = 25000
  Qabatiya, 25000
  Nablus District, Population = 20000
  Asira, 20000
--------------------------------------------------------------------------------------------------------
