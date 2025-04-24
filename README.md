# Inverted Search

## 📖 Overview
The **Inverted Search** project is a C-based implementation of an inverted index. It enables users to **create**, **update**, **search**, **display**, and **save** a database of words extracted from text files. This project utilizes hashing for efficient data organization and retrieval.

---

## 🚀 Features
- **Create Database**: Reads words from `.txt` files and builds a hash-based inverted index.
- **Display Database**: Shows all stored words along with filenames and word counts.
- **Search Database**: Searches for a word and displays its occurrences across files.
- **Save Database**: Saves the current database state to a file.
- **Update Database**: Adds new files and integrates their contents into the existing database.

---

## 🗂️ File Structure

### 🔑 Key Source Files
| File | Description |
|------|-------------|
| `main.c` | Entry point and menu-driven interface. |
| `main.h` | Common header with structure definitions and prototypes. |
| `create_database.c` | Logic for creating the initial database. |
| `update_database.c` | Handles adding new files to the database. |
| `search_database.c` | Implements the search feature. |
| `save_database.c` | Saves the database to a file. |
| `display_database.c` | Prints database contents in readable format. |
| `list_functions.c` | Linked list utility functions. |
| `createhashtable.c` | Initializes the hash table structure. |
| `colors.h` | Defines terminal color codes. |
| `makefile` | Automates the build process. |

---

## 🛠️ How to Build and Run

### 📋 Prerequisites
- GCC compiler
- Linux/Unix terminal or compatible command prompt

### ⚙️ Build
To compile the project, run:
```sh
make
```

### 🧹 Clean
To clean build files:
```sh
make clean
```

### ▶️ Run
To execute the program:
```sh
./inverted_search file1.txt file2.txt ...
```

---

## 📋 Menu Options
```text
1. Create Database   - Build database from input files
2. Display Database  - Print all stored words and data
3. Search Database   - Search for a specific word
4. Save Database     - Save the current database
5. Update Database   - Add new files to the database
6. Exit              - Exit the program
```

---

## 📂 File Requirements
- Files must have a `.txt` extension.
- Files must not be empty.

💡 **Example Run:**
```
Enter choice: 1
Info: Database created successfully
```

---

## 🧱 Data Structures Used

### 🔗 Linked Lists
Used to store file names and associated word counts.

### 🔢 Hash Table
Used to organize and access word entries efficiently.

### 🧩 Key Structures
- **`list`**: Linked list of filenames.
- **`main_node`**: Represents a word and associated files.
- **`sub_node`**: Represents a file and word count in that file.
- **`hash`**: Represents a hash table entry.

---

## 🤝 Contributing
Fork the repository, make your changes, and submit a pull request. All contributions are welcome!

---

## 📜 License
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

---

## 🙏 Acknowledgments
Special thanks to all contributors and developers who made this project possible.
