#include "DoublyLinkedList.h"
#include <iostream>

void DoublyLinkedList::displayForward() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
void DoublyLinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    std::cout << "\n";
}