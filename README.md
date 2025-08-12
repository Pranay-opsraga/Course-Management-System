# Course-Management-System
My first c++ project .
📚 Course Management System (C++)
A simple C++ beginner project to manage course details across different platforms — YouTube, App, and Website.
It stores course information for students, displays their enrolled courses, and calculates overall statistics like total fees, enrollments, teachers, and average ratings.

✨ Features
Add multiple students and their courses

Enter details for YouTube, App, and Website versions of each course

View all student details with their course information

See overall statistics for all courses combined

🛠 Concepts Used
Classes & Objects

Constructors & Destructors

Dynamic Memory Allocation (new / delete)

Pointers to Objects

Encapsulation

📸 Example Output
yaml
Copy
Edit
-------------WELCOME TO COURSE MANAGEMENT SYSTEM-------------
Enter the number of the student : 
1
Name :
Pranay Sharma
Age :
18
In how many course have you enrolled in 
1
Enter the course 1 Name:
C++ Programming
Enter the course 1 Duration:
3
--- YouTube ---
Fees: 500
Students: 200
Teachers: 5
Rating: 4.5
--- App ---
Fees: 600
Students: 150
Teachers: 3
Rating: 4.3
--- Website ---
Fees: 700
Students: 180
Teachers: 4
Rating: 4.6

-----------Overall details----------------
Total Fees of the courses : Rs 1800
Total enrollment of the courses :530
Total teacher of the courses :12
Average rating of the courses : 4.46
▶️ How to Run
Clone the repo

bash
Copy
Edit
git clone https://github.com/yourusername/Course-Management-System.git
cd Course-Management-System
Compile

bash
Copy
Edit
g++ main.cpp -o cms
Run

bash
Copy
Edit
./cms
🚀 Future Improvements
Add file saving/loading

Search and filter courses

Replace global variables with a statistics class

Improve user interface

