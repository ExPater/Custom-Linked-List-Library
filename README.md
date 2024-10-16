# Custom-Linked-List-Library

# List Class Template - README

This `List` class template is a singly linked list implementation in C++. The class supports a variety of functionalities, including adding, removing, finding, and manipulating elements. The class is designed to be flexible and can be used with any data type.

## Table of Contents

1. [Class Structure](#class-structure)
2. [Member Functions](#member-functions)
   - [Constructor and Destructor](#constructor-and-destructor)
   - [Basic Operations](#basic-operations)
   - [Advanced Operations](#advanced-operations)
3. [Node Class](#node-class)
4. [Contact](#contact)

## Class Structure

The `List` class is a template class, meaning it can be instantiated for any data type, `T`. The list is implemented as a singly linked list, where each node contains data and a pointer to the next node in the list.

## Member Functions

### Constructor and Destructor

- **`List()`**  
  Initializes an empty list.

- **`List(const List<T>& value)`**  
  Copy constructor. Initializes the list as a deep copy of another `List` object.

- **`~List()`**  
  Destructor. Frees the memory used by the list nodes.

- **`List(T value)`**  
  Initializes the list with a single element, `value`.

### Basic Operations

- **`void push_back(T data)`**  
  Adds an element to the end of the list.

- **`void pop_front()`**  
  Removes the first element from the list.

- **`void clear()`**  
  Removes all elements from the list.

- **`void delete_last_number()`**  
  Removes the last element from the list.

- **`int GetSize()`**  
  Returns the number of elements in the list.

- **`T& operator[](const int index)`**  
  Overloads the subscript operator to allow access to list elements by index.

- **`bool operator==(List<T>& other)`**  
  Overloads the equality operator to compare two lists for equality.

- **`void operator=(List<T>& other)`**  
  Assigns one list to another by making a deep copy of `other`.

### Advanced Operations

- **`void insert_at(int index, T value)`**  
  Inserts a value at a specific index in the list.

- **`void reverse()`**  
  Reverses the order of elements in the list.

- **`void write_to_file(const std::string& filename)`**  
  Writes the contents of the list to a file.

- **`void load_from_file(const std::string& filename)`**  
  Loads data from a file into the list.

- **`int find(T value)`**  
  Searches for the value in the list and returns its position. Returns `-1` if not found.

- **`T* to_array()`**  
  Converts the list into a dynamic array and returns the array.

- **`void from_array(T* array, int length)`**  
  Populates the list from a given array of specified length.

- **`void merge(List<T>& other)`**  
  Merges another list into the current list.

- **`void sort(bool ascending)`**  
  Sorts the list in ascending or descending order based on the `ascending` flag.

- **`T& front()`**  
  Returns the first element of the list.

- **`T& back()`**  
  Returns the last element of the list.

- **`T& middle()`**  
  Returns the middle element of the list. Only works for lists with an odd number of elements.

- **`void remove_duplicates()`**  
  Removes duplicate values from the list.

- **`void remove_all(T value)`**  
  Removes all instances of a specific value from the list.

- **`T sum()`**  
  Returns the sum of all elements in the list. This function is only available for `int` and `double` types.

### Helper Functions

- **`void swap(int firstnumber, int secondnumber)`**  
  Swaps two elements in the list at the specified positions.

- **`void random(int count)`**  
  Populates the list with random values (0-9) and adds `count` number of elements.

- **`void random(int count, const int maxnumber)`**  
  Populates the list with random values up to `maxnumber` and adds `count` number of elements.

## Node Class

Each node in the list is represented by a `Node` object. The `Node` class stores the data and a pointer to the next node.

```cpp
template<typename T>
class Node {
public:
    Node* pNext;
    T data;
    Node(T data = T(), Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
    }
};
```
For further questions or support, feel free to reach out via Telegram: @ExPat_all.
This `README.md` provides a structured overview of the class, its features, and how to use them. Let me know if you need any additional changes!
