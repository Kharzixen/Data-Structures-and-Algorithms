#pragma once

template<typename T>
class node {
public:
	T data;
	node* next;
	node* prev; 
	node(T data) {
		this->data = data;
		next = nullptr;
		prev = nullptr; 
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