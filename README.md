# AdmissionPortal
Student Admission Portal Management System in C++
This project is designed to manage student data during the admission process for educational institutions or industries. It utilizes various C++ features to create a functional system.
System Modules:
1.
Admin Login: This module allows authorized administrators to access the system and perform various tasks like:
2.
1.Adding new student records
2.Editing existing student information
3.Deleting student data (if necessary)
4.Viewing all student records
5.Generating reports (optional)
3.
Student Login: This module allows students (after successful registration) to:
4.
1. View their admission status
2. Download application forms (optional)
3. Update contact information (optional)
5. Object-Oriented Programming (OOP) Features:
6. The project leverages several OOP concepts to structure the code effectively and improve maintainability.

Here's a breakdown of some key features used:
  * **Classes and Objects:** The system likely defines classes like `Student`, `Admin`, and potentially others to represent entities with their attributes (data) and methods (functions). 
  * **Data Abstraction and Encapsulation:** Student data (e.g., name, roll number) is likely encapsulated within the `Student` class, restricting direct access and promoting data integrity.
  * **Polymorphism (Function Overloading):** Overloaded functions might exist to handle different data types or perform actions specific to student or admin roles.
  * **Constructors and Destructors:** These special member functions likely manage object creation and destruction, ensuring proper memory allocation and deallocation.
  * **Single Inheritance:** A class might inherit properties from another class (e.g., `User` class with common attributes for students and admins).
  * **File Handling:** The system might use file I/O operations to store and retrieve student data persistently, allowing data to survive program termination.
Additional Features (mentioned briefly):
**Function Overriding: This could be used to define specific functionalities for different classes (e.g., displayInfo() for students displaying basic details versus admins displaying full records).
**Friend Function: A function outside a class might be granted access to its private members for specific purposes.
**Template: This could be used to create generic functions or classes that work with different data types (less likely in this specific context).

Overall, this project demonstrates the application of C++ features to build a functional student admission portal management system. The specific implementation details would depend on the developer's choices and the desired functionalities of the system.
