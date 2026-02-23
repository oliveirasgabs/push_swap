*This project has been created as part of the 42 curriculum by Gabrioli*

# **Description**:

# Push_swap

The goal of this project is to implement a program called `push_swap`, which sorts a linked list in ascending order. The implementation must adhere to specific constraints: first, it can only utilize two stacks; second, it must sort the entire list using the minimum number of operations possible.
This project is essential for understanding how **sorting algorithms** work, requiring a high-level grasp of **memory management and allocation**, as well as the manipulation of **doubly linked lists** (the core data structure of this project).

### The Algorithm

The chosen approach for this project was the **Turk Algorithm**. At first glance, it can be quite complex and frustrating because each node in the linked list is assigned several attributes. However, it operates efficiently by **pre-calculating** the cost of each move before executing it, ensuring high efficiency and a reduced number of operations.

# **Instructions**:

### Requirements
To compile and run this project, you will need:
* A `cc` compiler (such as **gcc** or **clang**).
* Standard C libraries (available by default on most Unix-based systems).
* **Make** build tool.

### Testing
The project includes a `Makefile` that automates the entire build process. It handles the compilation of the `push_swap` executable and ensures that the auxiliary library, `libft`, is properly compiled and linked.

To compile the project, navigate to the root directory and run:
```bash
make
```
Once compiled, you can run the program by passing a list of integers as arguments. The program will output the shortest sequence of instructions to sort the stack.
You can provide the numbers as a single quoted string or as individual arguments:

**Option 1: Single string**
```bash
./push_swap "5 2 3 1 4"
```

**Option 2: Separate arguments**
```bash
./push_swap 5 2 3 1 4
```

### Makefile Rules

Compiles the `push_swap` mandatory part:
```bash
make
```

Removes object files:
```bash
make clean
```

Removes object files and the `push_swap` executable.
```bash
make fclean
```

Recompiles the entire project from scratch.
```bash
make re
```

# **Explanation and Justification of Data Structure**:

For this project, a **Doubly Linked List** was chosen as the primary data structure to represent stacks `A` and `B`. This decision was driven by the specific operational requirements of the `push_swap` problem and the mechanics of the **Turk Algorithm**.

### 1. Efficient Bidirectional Traversal
The Turk Algorithm relies heavily on finding the "target node" and calculating the cheapest move. To do this efficiently, the program must traverse the stack in both directions (forward and backward) to determine whether a node is above or below the median. A doubly linked list allows each node to point to both its successor (`next`) and its predecessor (`prev`), enabling $O(1)$ access to adjacent nodes and efficient rotation logic.

### 2. Node Metadata Storage
The Turk Algorithm requires each node to carry multiple attributes beyond the integer value itself, such as:
* **Index:** Current position in the stack.
* **Push Cost:** Total operations needed to move the node.
* **Target Node:** Pointer to the matching node in the destination stack.
* **Above Median:** A boolean flag to optimize rotation direction (`ra` vs `rra`).

Using a `struct` within a linked list structure allows us to store all this metadata directly within the node, making the algorithm's logic cleaner and more performant than using primitive arrays.

### 3. Dynamic Memory and Flexibility
Since the size of the input list can vary significantly (e.g., 100 vs. 500 numbers), a linked list provides the necessary flexibility for dynamic memory allocation. It allows for seamless "push" (`pa`, `pb`) operations—which involve moving nodes between stacks—by simply updating pointers rather than shifting elements in an array, which would be an $O(n)$ operation.

### 4. Circular Simulation
While the list is technically linear, the implementation of `rotate` (`ra`/`rb`) and `reverse rotate` (`rra`/`rrb`) operations is logically simplified by the doubly linked nature. Moving the head pointer to `head->next` or `head->prev` effectively simulates a circular buffer with minimal computational overhead.

# **Resources**

* [Push Swap Guide](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
* [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
* [Push Swap Tutorial by Thuggonaut](https://www.youtube.com/watch?v=wRvipSG4Mmk)
* [push_swap : a performant sorting algorithm using 2 stacks by Oceano](https://www.youtube.com/watch?v=OaG81sDEpVk)
