# 📚 Linked List Library – Node Class

### 🧑‍💻 Author
**Sohail Zoraibi**

### 📅 Date Created
**July 5, 2025**

---

## 📘 Overview
This project implements a simple **singly linked list** using a `Node` class in C++.  
It includes basic operations such as:

- Inserting nodes (at beginning, end, before/after a target)
- Deleting nodes (by name, first, or last)
- Searching for a node
- Printing nodes

The goal is to build a reusable, safe, and easy-to-read linked list module.

---

## 🗂️ File Structure

| File Name         | Description                              |
|------------------|------------------------------------------|
| `Node.h`          | Header file containing the `Node` class and all operations |
| `main.cpp` (Optional) | A file to demonstrate usage and test the library     |
| `README.md`       | This documentation file                 |

---

## 🛠️ Features and Functions

| Function                      | Description                                 |
|------------------------------|---------------------------------------------|
| `InsertInBeginning`          | Adds a node to the start of the list        |
| `InsertAtEnd`                | Adds a node to the end of the list          |
| `InsertBefore`               | Inserts a node before a specified name      |
| `InsertAfter`                | Inserts a node after a specified name       |
| `DeleteNode`                 | Deletes a node by first name                |
| `DeleteFirstNode`           | Deletes the first node in the list          |
| `DeleteLastNode`            | Deletes the last node in the list           |
| `Find`                       | Searches for a node by first name           |
| `PrintNode`                  | Prints a single node's data                 |
| `PrintNodes`                 | Prints the entire list                      |

---

## ⏳ Development Timeline

| Date       | Task                            | Status     |
|------------|----------------------------------|------------|
| 2025-07-04 | Created Node class               | ✅ Done     |
| 2025-07-04 | Added find and print methods     | ✅ Done     |
| 2025-07-04 | Implemented insert functions     | ✅ Done     |
| 2025-07-05 | Implemented delete functions     | ✅ Done     |
| TBD        | Add sorting or file I/O support  | 🔜 Planned  |

---

## 📌 Usage Example

```cpp
#include "Node.h"

int main() {
    Node* Head = nullptr;

    Node::InsertInBeginning(Head, "Ali", "Khan", 85);
    Node::InsertAtEnd(Head, "Sara", "Ahmed", 90);
    Node::InsertBefore(Head, "Sara", "John", "Doe", 78);
    
    Node::PrintNodes(Head);

    Node::DeleteNode(Head, "Ali");

    Node::PrintNodes(Head);
    return 0;
}
