#include <iostream>
using namespace std;


// Implementation of a singly linked list.
// TODOs: Turns out you MUST have a tail. Otherwise removes 
// must take worst case 2n. This is because the Node can 
// only look forward by one. So once you find the last 
// element, you need to traverse the list again until you're
// runner->next == last. Trying to look two spaces ahead 
// will give you last->next->NULL.
template <typename T>
class List {
public:

    List() {
        head = nullptr;
    }

    ~List() {
        while (!isEmpty()) {
            // remove_back();
        }
    }


    bool isEmpty() {
        return !head;
    }

    T insert_front(T inDatum) {
        Node* new_node = new Node(inDatum);
        new_node->next = head;
        Node* old_head = head;
        return inDatum;
    }

    T insert_back(T inDatum) {
        Node* new_node = new Node(inDatum);
        new_node->next = nullptr;
        if (!isEmpty()) {
            head = new_node;
        }
        else {
            Node* runner = head;
            while (runner) {
                if (!runner->next) {
                    runner->next = new_node;
                    return inDatum;
                }
            }
        }
    }

    // T remove_back() {
    //     Node* runner = head;
    //     while (runner) {
    //         if (!runner->next) {
    //             // 
    //         }
    //     }
    // }

private:
    struct Node {
        Node(T inDatum) {
            datum = inDatum;
        }

        T datum;
        Node* next;

    };


    Node* head;
    Node* tail;
};