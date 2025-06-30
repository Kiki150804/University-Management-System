
# University Management System
A simple console-based University Management System built in C++ that allows you to manage student records efficiently. The system provides functionality to add, search, and update student information with persistent file storage.

## Features
- Add Student Records: Register new students with their details
- Search Student: Find student information using roll number
- Update Student Data: Modify existing student address information
- File-based Storage: Persistent data storage using text files
- User-friendly Interface: Clean console-based menu system

## File Structure
University Management System  
 - student.cpp                 # Main source code
 - university.txt              # Student data storage file (auto-generated)
 - university_temp.txt         # Temporary file for updates (auto-generated)

## Class Structure
- Name: University Class  
  The University class serves as the data model for student information.

- Private Members:  
  string RollNo - Student's roll number  
  string Name - Student's full name  
  string Subject - Student's subject/course  
  string Address - Student's address

- Public Methods:
  Constructor: Initializes all fields to empty strings  
  Setter methods: setRollNo(), setName(), setSubject(), setAddress()  
  Getter methods: getRollNo(), getName(), getSubject(), getAddress()

## Core Functions
### 1. add(University stud)
Purpose: Adds a new student record to the system

Process:
  - Prompts user for student details (Roll No, Name, Subject, Address)
  - Sets the data using setter methods
  - Appends the record to university.txt file
  - Displays success confirmation

File Operation: Uses ofstream with ios::app flag for appending data
### 2. search()
Purpose: Searches for a student using roll number

Process:
  - Prompts user for roll number
  - Reads through university.txt line by line
  - Uses string::find() to locate matching roll number
  - Displays matching record or "not found" message

File Operation: Uses ifstream for reading file content
### 3. update(University stud)
Purpose: Updates student address information

Process:
  - Prompts user for roll number and new address
  - Reads original file and writes to temporary file
  - Locates student record and updates address field
  - Replaces original file with updated temporary file
Uses string::find_last_of(':') to locate address field

File Operation: Uses both ifstream and ofstream with file replacement technique

## File Handling Implementation
### Storage Format
- Student data is stored in the following format:  
[Roll Number] : [Name] : [Subject] : [Address]

**Note: Update the file path in the code to match your system directory before compilation.**

## How to Use
1. Setup   
#Clone or download the source code   
#Update file paths in the code to match your directory  
#Compile the program  
bash: g++ -o university_management student.cpp  
2. Running the Program  
bash: ./university_management
