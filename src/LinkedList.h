/*
 * LinkedList.h
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdio.h>

template<class T>
class LinkedList {
public:
	LinkedList();

	int size;

	struct Node {
		Node* next;
		T *data;
	};

	Node* head;
	Node* tail;

	void enqueue(T* pData);
	T* get(int index);
};

#endif /* LINKEDLIST_H_ */
