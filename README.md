# Monopoly Board - Circular Linked List Implementation

A lightweight C++ implementation of a Monopoly game board using a **Circular Linked List**. This structure allows for infinite traversal around the board, mimicking how players move from "Boardwalk" back to "Go."

## Features
* **Circular Logic:** The `tail` node automatically points back to the `head`, ensuring players never hit a "null" end.
* **Capacity Management:** Built-in constraints to mirror the standard 40-space Monopoly board layout.
* **Memory Efficient:** Uses dynamic node allocation for flexible board setup.

## Data Structure Overview

The project uses a custom `CircularLinkedList` class. Unlike a standard linked list, the last element points back to the first, creating a closed loop.



### Key Components:
- **CircularNode:** Stores the name of the space (`string`) and a pointer to the next location.
- **CircularLinkedList:** Manages the addition of spaces and ensures the circular integrity is maintained.

## How to Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/monopoly-linked-list.git](https://github.com/your-username/monopoly-linked-list.git)
    ```
2.  **Compile the code:**
    ```bash
    g++ -o monopoly main.cpp
    ```
3.  **Run the executable:**
    ```bash
    ./monopoly
    ```

## To-Do List
- [ ] Implement a **Destructor** to prevent memory leaks.
- [ ] Add a `movePlayer(int steps)` function.
- [ ] Include more property data (rent, color groups, etc.).

## License
This project is open-source and available under the MIT License.
