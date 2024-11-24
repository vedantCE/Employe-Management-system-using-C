# Employee Management System in C

This repository contains a **C-based Employee Management System** that manages employee records using **linked lists** and **file handling** for data persistence. The program is interactive, offering a menu-driven interface for various operations.

---

## Features
- **Admin Verification**: Secure access with username and password.
- **Add Employee**: Add new employee details with unique IDs.
- **View Employee Records**: Display all employee records.
- **Update Employee Data**: Modify an employee's name, department, or salary.
- **Delete Employee Record**: Remove employee details from the system.
- **Data Persistence**: Save and load employee data using file handling (`employees.txt`).
- **Linked List Implementation**: Dynamically manage employee records.

---

## Technologies Used
- **C Programming**
- **Linked Lists** for dynamic data management.
- **File Handling** for persistent storage.

---

## Files in this Repository
- **`main.c`**: The main program file containing all functionalities.
- **`employees.txt`**: The data file for storing employee records (created automatically).

---

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/employee-management-system.git
   

### Key Formatting Elements:
1. **Headings (`#`, `##`)**: Organize content hierarchically.
2. **Code blocks (` ``` `)**: Display commands and code snippets cleanly.
3. **Lists (`-` and `1.`)**: Enhance readability for features and steps.
4. **Bold (`**text**`)**: Highlight key terms.

## 🌟 Program Flow

### 🔑 Admin Login
Verifies credentials to ensure secure access.

### 📋 Menu Options
1. **➕ Add Employee**: Prompts for employee details (ID, name, department, salary). Checks for duplicate IDs.
2. **📂 Show Employee Records**: Displays a table of all employee records.
3. **✏️ Update Employee's Data**: Allows updates to name, department, or salary.
4. **❌ Delete Employee Record**: Deletes a specific employee based on their ID.
5. **🚪 Exit**: Exits the program.

### 📁 File Persistence
- Employee records are stored in **`employees.txt`** for data persistence.
- The program reads from **`employees.txt`** on startup to load previous records.

---

## ✨ Special Mentions

### 1️⃣ Linked Lists in C
This program demonstrates the use of **singly linked lists** to dynamically manage employee records. Each node in the list contains:
- 🆔 Employee ID
- 🧑‍💼 Name
- 🏢 Department
- 💰 Salary
- 🔗 Pointer to the next node

The linked list ensures efficient memory usage and dynamic record handling.

### 2️⃣ File Handling in C
File handling is used to save and load employee records:
- **`SaveToFile()`**: Writes all employee records to **`employees.txt`**.
- **`LoadFromFile()`**: Reads existing employee data from **`employees.txt`** on startup.

---

## 🚀 Future Enhancements
- 🔄 Add functionality for sorting employee records.
- 🗓️ Include more fields, such as `Date of Joining` or `Contact Number`.
- 🖥️ Implement a graphical user interface (GUI) using libraries like GTK.


