#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<typename T>
class List {
public:
	List();

	List(const List<T>& value);

	~List();

	List(T value);

	void pop_front();

	void push_back(T data);

	int GetSize() { return Size; }

	void COUT();

	T& operator[](const int index);

	void clear();

	void random(int count);

	void random(int count, const int maxnumber);

	void delete_last_number();

	void swap(int firstnumber, int secondnumber);

	bool operator==(List<T>& other);

	void operator=(List<T>& other);

	void insert_at(int index, T value);

	void reverse();

	void write_to_file(const string& filename);

	void load_from_file(const string& filename);
	
	int find(T value);

	T* to_array();

	void from_array(T* array, int length);

	void merge(List<T>& other);

	void sort(bool ascending);

	T& front();

	T& back();

	T& middle();

	void remove_duplicates();

	void remove_all(T value);

	T sum();

protected:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size = 0;
	Node<T>* head;
};
template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::List(const List<T>& value)
{

	if (value.Size == 0) {
		this->head = nullptr;
		return;
	}
	if (value.Size == 1) {
		this->head = new Node<T>(value.head->data);
		Size++;
		return;
	}
	Node<T>* current = value.head;
	while (current->pNext != nullptr) {
		push_back(current->data);
		current = current->pNext;
	}
	push_back(current->data);
}
template<typename T>
List<T>::~List() {

	clear();

}

template<typename T>
List<T>::List(T value)
{
	head = new Node<T>(value);
	head->pNext = nullptr;
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	if (Size == 0) {
		cout << "Error" << endl;
		return;
	}
	if (Size == 1) {
		delete head;
		head = nullptr;
		Size = 0;
		return;
	}
	else {


		Node<T>* temp = head;

		head = head->pNext;

		delete temp;

		Size--;
	}
}
template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;

		}

		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::COUT()
{
	if (Size == 0) {
		cout << "You dont have a data!" << endl;
		return;
	}
	Node<T>* current = this->head;
	while (current != nullptr) {
		cout << current->data << endl;

		current = current->pNext;
	}
	cout << endl;
}

template<typename T>
T& List<T>::operator[](const int index) {
	if (index < 0 || index >= Size) {
		throw out_of_range("Index is out of range");
	}
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;

	}
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();

	}
}

template<typename T>
void List<T>::random(int count)
{
	while (count) {
		push_back(rand() % 10);
		count--;
	}
}

template<typename T>
void List<T>::random(int count, const int maxnumber)
{
	while (count) {
		push_back(rand() % maxnumber);
		count--;

	}
}

template<typename T>

void List<T>::delete_last_number()
{
	if (Size == 0) {
		cout << "Error" << endl;
		return;
	}
	if (Size == 1) {
		delete head;
		head = nullptr;
		Size--;
		return;
	}
	Node<T>* temp = head;
	while (temp->pNext->pNext != nullptr) {
		temp = temp->pNext;
	}
	delete temp->pNext;
	temp->pNext = nullptr;
	Size--;
}


template<typename T>
void List<T>::swap(int firstnumber, int secondnumber)
{
	if (firstnumber > Size || secondnumber > Size) {
		cout << "Error" << endl;
		return;
	}
	if (firstnumber < 0 || secondnumber < 0) {
		cout << "You can't write a number lower than 0" << endl;
		return;
	}
	Node<T>* temp_first = head;

	Node<T>* temp_second = head;

	while (firstnumber) {
		temp_first = temp_first->pNext;
		firstnumber--;
	}
	while (secondnumber) {
		temp_second = temp_second->pNext;
		secondnumber--;
	}
	T help = temp_second->data;
	temp_second->data = temp_first->data;
	temp_first->data = help;
	return;

}

template<typename T>
bool List<T>::operator==(List<T>& other)
{
	Node<T>* current_first = this->head;
	Node<T>* current_second = other.head;


	if (other.Size != this->Size) {
		return false;
	}


	while (current_first->pNext != nullptr) {
		if (current_second->data != current_first->data) {
			return false;
		}
		current_second = current_second->pNext;
		current_first = current_first->pNext;
	}
	if (current_second->data != current_first->data) {
		return false;
	}
	return true;

}

template<typename T>
void List<T>::operator=(List<T>& other)
{
	clear();
	if (other.Size == 0) {
		head = nullptr;
		return;
	}
	if (other.Size == 1) {
		head = new Node<T>(other.head->data);
		head->pNext = nullptr;
		Size++;
		return;
	}
	Node<T>* current = other.head;
	while (current->pNext != nullptr) {
		push_back(current->data);
		current = current->pNext;
	}
	push_back(current->data);
	return;


}

template<typename T>
void List<T>::insert_at(int index, T value) {
	if (index < 0 || index > Size) {
		cout << "Index out of range" << endl;
		return;
	}
	if (index == 0) {
		Node<T>* newNode = new Node<T>(value);
		newNode->pNext = head;
		head = newNode;
	}
	else {
		Node<T>* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->pNext;
		}
		Node<T>* newNode = new Node<T>(value);
		newNode->pNext = current->pNext;
		current->pNext = newNode;
	}
	Size++;
}

template<typename T>
void List<T>::reverse() {
	if (Size <= 1) return;

	Node<T>* prev = nullptr;
	Node<T>* current = head;
	Node<T>* next = nullptr;

	while (current != nullptr) {
		next = current->pNext;
		current->pNext = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

template<typename T>
void List<T>::write_to_file(const string& filename) {
	ofstream outFile(filename);

	if (!outFile.is_open()) {
		cout << "Error: Cannot open file!" << endl;
		return;
	}
	Node<T>* current = this->head;
	if (Size == 0) {
		outFile << "Error: The list is empty." << std::endl;
	}
	else {
		while (current != nullptr) {
			outFile << current->data << std::endl;
			current = current->pNext;
		}
	}
	outFile.close();
}

template<typename T>
void List<T>::load_from_file(const string& filename)
{
	ifstream inFIle(filename);
	if (!inFIle.is_open()) {
		cout << "Error: Cannot open file!" << endl;
		return;
	}
	T value;
	clear();
	while (inFIle >> value) {
		push_back(value);
	}
	inFIle.close();
}

template<typename T>
int List<T>::find(T value)
{
	Node<T>* current = head;
	int index = 1;
	while (current != nullptr) {
		if(current->data == value){
			return index;
		}
		current = current->pNext;
		index++;
	}
	return -1;

}

template<typename T>
T* List<T>::to_array() {
	if (Size == 0) return nullptr;

	T* array = new T[Size];
	Node<T>* current = head;
	int i = 0;

	while (current != nullptr) {
		array[i++] = current->data;
		current = current->pNext;
	}

	return array;
}

template<typename T>
void List<T>::from_array(T* array, int length) {
	clear();
	for (int i = 0; i < length; i++) {
		push_back(array[i]);
	}
}

template<typename T>
inline void List<T>::merge(List<T>& other)
{
	if (other.Size == 0) {
		return;
	}
	Node<T>* current = other.head;
	while (current != nullptr) {
		push_back(current->data);
		current = current->pNext;
	}

}

template<typename T>
void List<T>::sort(bool ascending) {
	if (head == nullptr || head->pNext == nullptr) return;
	bool swapped;
	do {
		swapped = false;
		Node<T>* current = head;
		while (current->pNext != nullptr) {
			if ((ascending && current->data > current->pNext->data) ||
				(!ascending && current->data < current->pNext->data)) {
				T temp = current->data;
				current->data = current->pNext->data;
				current->pNext->data = temp;
				swapped = true;
			}
			current = current->pNext;
		}
	} while (swapped);
}

template<typename T>
inline T& List<T>::front()
{
	return head->data;
}

template<typename T>
inline T& List<T>::back()
{
	Node<T>* temp = head;
	while (temp->pNext != nullptr) {
		temp = temp->pNext;
	}
	return temp->data;
}

template<typename T>
inline T& List<T>::middle()
{
	try
	{
		if (Size == 0) {
			throw "Error";
		}
		if (Size % 2 == 0) {
			throw "Error";
		}
		Node<T>* current = head;
		if (Size == 1) {
			return head->data;
		}
		int temp = Size / 2;

		for (int i = 0; i < temp; ++i) {
			current = current->pNext;
		}
		return current->data;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
	catch (...) {
		cout << "";
	}
}

template<typename T>
void List<T>::remove_duplicates() {
	if (head == nullptr || head->pNext == nullptr) return;
	Node<T>* current = head;
	while (current != nullptr && current->pNext != nullptr) {
		Node<T>* runner = current;
		while (runner->pNext != nullptr) {
			if (runner->pNext->data == current->data) {
				Node<T>* duplicate = runner->pNext;
				runner->pNext = runner->pNext->pNext;
				delete duplicate;
				Size--;
			}
			else {
				runner = runner->pNext;
			}
		}

		current = current->pNext;
	}
}

template<typename T>
void List<T>::remove_all(T value) {
	while (head != nullptr && head->data == value) {
		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}
	if (head == nullptr) {
		return;
	}
	Node<T>* current = head;
	while (current->pNext != nullptr) {
		if (current->pNext->data == value) {
			Node<T>* temp = current->pNext;
			current->pNext = current->pNext->pNext;
			delete temp;
			Size--;
		}
		else {
			current = current->pNext;
		}
	}
}

template<typename T>
inline T List<T>::sum()
{
	static_assert(is_same<T, int>::value || is_same<T, double>::value, "Sum is only available for int and double types.");
	if (Size == 0) {
		return 0;
	}
	else if (Size == 1) {
		return head->data;
	}
	T total = 0;
	Node<T>* current = head;
	while (current != nullptr) {
		total += current->data;	
		current = current->pNext;
	}
	return total;
}



template<typename T>
class List<T[]> {
	virtual void check1() = 0;
};

