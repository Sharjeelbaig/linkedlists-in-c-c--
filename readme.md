# Linked List Implementation

This project provides implementations of various types of linked lists in C++: Singly Linked List, Doubly Linked List, Circular Linked List, and Circular Doubly Linked List.

## Features

- Insertion of elements at the end of the list
- Searching for an element in the list
- Removal of an element from the list
- Deletion of an element at a specific index
- Sorting the elements of the list

## Usage

1. Initialize a linked list of your choice (Singly Linked List, Doubly Linked List, Circular Linked List, or Circular Doubly Linked List).  

2. Use the provided methods to interact with the linked list:
   - `insert(value)`: Inserts a new element at the end of the list.
   - `search(key)`: Searches for a specified element in the list and returns the node if found.
   - `remove(value)`: Removes the first occurrence of the specified element from the list.
   - `deleteByIndex(index)`: Deletes the element at the specified index.
   - `sort()`: Sorts the elements of the list in ascending order.

## Example Usage

```cpp
// Create a new Singly Linked List
SinglyLinkedList sll;

// Insert elements
sll.insert(3);
sll.insert(1);
sll.insert(2);

// Display the list
sll.display(); // Output: 3 1 2

// Search for an element
Node* searchNode = sll.search(2);
if (searchNode != nullptr) {
    cout << "Key found: " << searchNode->data << endl;
} else {
    cout << "Key not found" << endl;
}

// Remove an element
sll.remove(1);
sll.display(); // Output: 3 2

// Delete an element by index
sll.deleteByIndex(0);
sll.display(); // Output: 2

// Sort the list
sll.sort();
sll.display(); // Output: 2
```

## Contribution

Contributions to this project are welcome! If you have any ideas or suggestions, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.