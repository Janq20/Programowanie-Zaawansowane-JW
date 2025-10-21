#pragma once
#include <iostream>
#include "Node.h"

struct Node {
    int data;
    Node* prev;
    Node* next;
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();

    void displayForward();
};