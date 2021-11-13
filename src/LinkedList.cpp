/*
 * LinkedList.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = head;
	size = 0;

}

template<class T>
void LinkedList<T>::enqueue(T* pData) {
	Node* toAdd = new Node();
	toAdd->data = pData;

	if (size > 0){
		//Adding to the tail
		toAdd->next = tail->next;

		tail->next = toAdd;
		tail = toAdd;
	}else {
		//List is empty, have to add to head
		toAdd->next = NULL;
		head = toAdd;
		tail = toAdd;
	}

	size++;

}

template<class T>
T* LinkedList<T>::get(int index) {
	if (index > (size-1) || index < -1){
		return NULL;
	} else if (index == -1){
		return tail->data;
	} else {
		Node* currentNode = head;

		for(int i = 0; i < index; i++){
			currentNode = currentNode->next;
		}

		return currentNode->data;
	}
}

