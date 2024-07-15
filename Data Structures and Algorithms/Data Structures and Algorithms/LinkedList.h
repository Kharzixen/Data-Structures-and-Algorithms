#pragma once

#include <iostream>

template<typename T>
class node {
public:
	T data; 
	node* next; 
	node(T data) {
		this->data = data;
		next = nullptr; 
	};
};

template <typename T>
class linked_list {
	node<T>* head; 
	node<T>* tail;
	int size; 
public: 
	linked_list(); 
	~linked_list(); 
	void append(T data); 
	void prepend(T data); 
	void insert(T value, int position);
	void remove(int position); 
	int get_size(); 
	T get_first(); 
	T get_last(); 
	T get(int index);
	void clear(); 
	void print(); 
};


template<typename T>
linked_list<T>::linked_list() {
	this->head = nullptr; 
	this->tail = nullptr; 
	size = 0; 
}

template<typename T>
linked_list<T>::~linked_list() {
	this->clear();
}

template<typename T>
void linked_list<T>::append(T data) {
	node<T>* new_node = new node<T>(data);

	if (size == 0) {
		this->head = new_node; 
		this->tail = new_node; 
	}
	else {
		tail->next = new_node; 
		tail = new_node; 
	}
	size++; 
}

template<typename T>
void linked_list<T>::prepend(T value) {
	node<T>* new_node = new node<T>(value);
	if (!head) {
		head = tail = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;
	}
	++size;
}

template<typename T>
T linked_list<T>::get_first()  {
	if (!head) throw std::runtime_error("List is empty");
	return head->data;
}

template<typename T>
T linked_list<T>::get_last()  {
	if (!tail) throw std::runtime_error("List is empty");
	return tail->data;
}

template<typename T>
T linked_list<T>::get(int index)  {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of range");
	}
	node<T>* current = head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

template<typename T>
void linked_list<T>::clear() {
	node<T>* current = head;
	while (current) {
		node<T>* next = current->next;
		delete current;
		current = next;
	}
	head = tail = nullptr;
	size = 0;
}

template<typename T>
void linked_list<T>::print() {
	node<T>* current = head;
	while (current) {
		std::cout << current->data<<" ";
		current = current->next;
	}
}

template<typename T>
void linked_list<T>::insert(T value, int position) {
	if (position < 0 || position > size) {
		throw std::out_of_range("Invalid position");
	}

	if (position == 0) {
		prepend(value);
	}
	else if (position == size) {
		append(value);
	}
	else {
		node<T>* newNode = new node<T>(value);
		node<T>* current = head;
		for (int i = 0; i < position - 1; ++i) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		++size;
	}
}

template<typename T>
void linked_list<T>::remove(int position) {
	if (position < 0 || position >= size) {
		throw std::out_of_range("Invalid position");
	}

	if (position == 0) {
		node<T>* node_to_remove = head;
		this->head= node_to_remove->next; 
		delete node_to_remove;
	}
	else {
		node<T>* current = head;
		for (int i = 0; i < position - 1; ++i) {
			current = current->next;
		}
		node<T>* node_to_remove = current->next;
		current->next = node_to_remove->next;
		delete node_to_remove;
	}
		size--;
}

template<typename T>
int linked_list<T>::get_size() {
	return this->size; 
}