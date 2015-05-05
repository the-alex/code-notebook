#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>

template <typename T>
class List {
    //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

    //EFFECTS:  returns true if the list is empty
    bool isEmpty() const;

    //MODIFIES: this
    //EFFECTS:  inserts datum into the front of the list
    void insertFront(const T &datum);

    //MODIFIES: this
    //EFFECTS:  inserts datum into the back of the list
    void insertBack(const T &datum);

    //REQUIRES: list is not empty
    //MODIFIES: this
    //EFFECTS:  removes the item at the front of the list, and returns the item being removed
    T removeFront();

    //REQUIRES: list is not empty
    //MODIFIES: this
    //EFFECTS:  removes the item at the back of the list, and returns the item being removed
    T removeBack();

    List();
    List(const List &l);
    ~List();
    List &operator =(const List &l);


private:
    // a private type
    struct Node {
        Node *next;
        Node *prev;
        T datum;
    };

    //MODIFIES: this
    //EFFECTS:  copies all nodes from l to this
    void copyAll(const List &l);

    //MODIFIES: this
    //EFFECTS:  removes all nodes
    void removeAll();

    Node *first;   // points to first Node in list, or 0 if list is empty
    Node *last;    // points to last Node in list, or 0 if list is empty

public:
    class Iterator {

    public:
        Iterator() : node_ptr(0) {} //default constructor

        //constructor at a node pointer
        T& operator* () const {
            assert(node_ptr);
            return (node_ptr->datum);
        }


        //operator overloading for ++
        Iterator& operator++ () {
            assert(node_ptr);
            Iterator temp(node_ptr);
            node_ptr = node_ptr->next;
            return *this;
        }


        //operator overloading for ==
        bool operator== (Iterator rhs) const{
            return (node_ptr == rhs.node_ptr);
        }


        //operator overloading for !=
        bool operator!= (Iterator rhs) const{
            return (node_ptr != rhs.node_ptr);
        }



    private:
        Node *node_ptr;
        friend class List;

        // construct an Iterator at a specific position
        Iterator(Node *p) :node_ptr(p) {}

    };

    // return an Iterator pointing to the first node
    Iterator begin() const {
        return Iterator(first);
    }

    // return an Iterator pointing to "past the end"
    Iterator end() const{
        return Iterator();
    }

    //REQUIRES: i is a valid iterator associated with this list and points to an element (i.e., it is not at end).
    //MODIFIES: this, may invalidate all list iterators, including this one. Using any prior iterator after this
    // operation should be considered unsafe.
    //EFFECTS: Removes a single element from the list container
    void erase(Iterator i);

    //REQUIRES: i is a valid iterator associated with this list
    //EFFECTS: inserts datum before the element at the specified position. Note: this can be used
    // to insert anywhere in the list, including at the beginning or at the end. If i is at the end of the
    // list (list.end()), then it will cause an insertion at the back of the list. It does not modify
    // the element that the existing iterators, including this iterator, point to.
    void insert(Iterator i, const T &datum);

};

template <typename T>
bool List<T>::isEmpty() const {
    return !first;
}





template <typename T>
void List<T>::insertFront(const T &datum){
    Node* thisNode = new Node;
    thisNode->datum = datum;
    thisNode->next = first;

    if (isEmpty())
    {
        thisNode->prev = NULL;
        first = last = thisNode;
    }
    else
    {
        first->prev = thisNode;
        first = thisNode;
        thisNode->prev = NULL;
    }
}


template <typename T>
void List<T>::insertBack(const T &datum) {
    Node *thisNode = new Node;
    thisNode->next = NULL;
    thisNode->datum = datum;

    if (isEmpty())
    {
        first = last = thisNode;
        thisNode->prev = NULL;
    }
    else
    {
        thisNode->prev = last;
        last->next = thisNode;
        last = thisNode;
    }
}


template <typename T>
T List<T>::removeFront() {
    assert (!isEmpty());
    Node *victim = first;
    first = first->next;

    if(!isEmpty())
        first->prev = NULL;
    T result = victim->datum;
    if(isEmpty())
        first = last = NULL;

    delete victim;
    victim = 0;
    return result;
}


template <typename T>
T List<T>::removeBack() {
    assert (!isEmpty());
    Node *victim = last;
    last = last->prev;

    if(last == NULL)
        first =NULL;
    else
        last->next = NULL;
    T result = victim->datum;

    delete victim;
    victim = 0;
    return result;
}




//constructor
template <typename T>
List<T>::List()
:first (0), last(0) {}





template <typename T>
void List<T>::copyAll(const List &l){
    for(Node *np =l.first; np; np=np->next)
        insertBack(np->datum);
}



template <typename T>
void List<T>::removeAll(){
    while (!isEmpty())
        removeFront();
    first = NULL;
    last = NULL;
}



//copy constructor
template <typename T>
List<T>::List(const List &l)
:first(0), last(0){
    copyAll(l);
}



//operator overloading for =
template <typename T>
List<T>& List<T>::operator= (const List &l){
    if (this == &l) return *this;
    removeAll();
    copyAll(l);
    return *this;
}



//deconstructor
template <typename T>
List<T>::~List(){
    removeAll();
}



template<typename T>
void List<T>::erase(Iterator i){
    Node* np = i.node_ptr;
    assert(i.node_ptr);
    if(np == last)
    {
        removeBack();
        return;
    }

    if (np == first)
    {
        removeFront();
        return;
    }
    //else do this
    Iterator nextnode(i.node_ptr->next);
    Iterator prevnode(i.node_ptr->prev);
    prevnode.node_ptr->next = nextnode.node_ptr;
    nextnode.node_ptr->prev = prevnode.node_ptr;
    delete np;
}



template<typename T>
void List<T>::insert(Iterator i, const T &datum){
    assert(i.node_ptr);

    if(i.node_ptr == first) // node is at the first element
    {
        insertFront(&datum);
    }

    if(i.node_ptr == last)// node is at the last element
    {
        insertBack(&datum);
    }
    else //in the middle
    {
        Node *thisNode = new Node;
        thisNode = i.node_ptr;
        Iterator prevnode(i.node_ptr->prev);
        Iterator mid(i.node_ptr);
        prevnode.node_ptr->next = thisNode;
        thisNode->prev = prevnode;
        thisNode->next = mid;
        mid->prev = thisNode;
        thisNode->datum = datum;
    }
}

#endif
