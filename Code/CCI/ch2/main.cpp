#include <iostream>
#include "List.h"

using namespace std;

template <typename T>
ostream& operator << (ostream& os, const List<T>& lst) {
    cout << "(";
    typename List<T>::Iterator i = lst.begin();
    while (i != lst.end()) {
        cout << *i;
        if (++i != lst.end()) {
            cout << ", ";
        }
    }
    cout << ")";
    return os;
}

int main(int argc, char const *argv[])
{

    List<int> lst;

    /*
     List Tests
     */

    //List Test 1
    lst.insertFront(3);
    lst.insertFront(2);
    lst.insertFront(1);
    lst.insertFront(0);
    assert(!lst.isEmpty());
    cout << lst << endl;

    for( int i = 0; i < 4; ++i )
    {
        int num = lst.removeFront();
        assert(i == num);
    }

    cout << "Passed List Test 1" << endl;
    cout << endl;
    //-------------------------------------------------------------

    //List Test 2
    lst.insertFront(3);
    lst.insertFront(2);
    lst.insertFront(1);
    lst.insertFront(0);
    assert(!lst.isEmpty());
    cout << lst << endl;

    for( int i = 3; i >= 0; --i )
    {
        int num = lst.removeBack();
        assert(i == num);
    }

    assert(lst.isEmpty());
    cout << "Passed List Test 2" << endl;
    cout << endl;
    //-------------------------------------------------------------

    //List Test 3
    lst.insertBack(3);
    lst.insertBack(2);
    lst.insertBack(1);
    lst.insertBack(0);
    assert(!lst.isEmpty());
    cout << lst << endl;


    for( int i = 3; i >= 0; --i )
    {
        int num = lst.removeFront();
        assert(i == num);
    }

    cout << "Passed List Test 3" << endl;
    cout << endl;
    //-------------------------------------------------------------

    //List Test 4
    lst.insertBack(3);
    lst.insertBack(2);
    lst.insertBack(1);
    lst.insertBack(0);
    assert(!lst.isEmpty());
    cout << lst << endl;


    for( int i = 0; i < 4; ++i )
    {
        int num = lst.removeBack();
        assert(i == num);
    }

    cout << "Passed Test 4" << endl;
    cout << endl;
    //-------------------------------------------------------------

    /*
        Iterator Tests
     */

    //-------------------------------------------------------------
    //This is created to compare an iterating int to
    //compare as if this were a normal loop.
    int intI = 0;


    //Iterator Test 1
    lst.insertFront(3);
    lst.insertFront(2);
    lst.insertFront(1);
    lst.insertFront(0);
    assert(!lst.isEmpty());
    cout << lst << endl;

    intI = 0;
    for (List<int>::Iterator i = lst.begin(); i != lst.end(); ++i)
    {
        assert(*i == intI);
        intI++;
    }
    //FIXME: Not removing each element. IE: Loop only iterates once.
    cout << lst << endl;
    cout << endl;

    cout << "Passed Iterator Test 1" << endl;
    cout << endl;
    //-------------------------------------------------------------


    //Iterator Test 2
    lst.insertBack(0);
    lst.insertBack(1);
    lst.insertBack(2);
    //Tests Copy Constructor
    List<int>::Iterator i = lst.begin();
    List<int>::Iterator j = i;
    assert(i == j);
    assert(i == i);
    assert(j == j);
    assert(j == i);
    cout << "Passed Iterator Test 2" << endl;
    cout << endl;

    //Iterator Test 3
    ++i;
    ++j;
    assert(i == j);
    cout << "Passed Iterator Test 3" << endl;
    cout << endl;
    //-------------------------------------------------------------

    //Iterator Test 4
    ++j;    //j is now pointing to a different node.
    assert(i != j);
    assert(j != i);
    cout << "Passed Iterator Test 4" << endl;
    cout << endl;
    //-------------------------------------------------------------


    //Iterator Test 5
    cout << "The value of i at this node: " << *i << endl;
    cout << "The value of j at this node: " << *j << endl;
    //Testing overloaded dereference operator.
    assert((*i) != (*j));
    cout << "Passed Iterator Test 5" << endl;
    cout << endl;
    //-------------------------------------------------------------

    //Iterator Test 6
    ++i;
    cout << "The value of i at this node: " << *i << endl;
    cout << "The value of j at this node: " << *j << endl;
    assert((*i) == (*j));
    cout << "Passed Iterator Test 6" << endl;
    cout << endl;
    //-------------------------------------------------------------

    /*
     Earase Tests   -   SUBJECT TO SCRUTINY
     */

    //-------------------------------------------------------------


    //Erase Test 1
    List<int> listOne;
    lst.insertFront(3);
    lst.insertFront(2);
    lst.insertFront(1);
    lst.insertFront(0);
    cout << listOne << endl;

    for (List<int>::Iterator i = listOne.begin(); i != listOne.end(); ++i)
    {
        listOne.erase(i);
    }
    assert(listOne.isEmpty());
    cout << "Passed Erase Test 1" << endl;
    //-------------------------------------------------------------


    //Erase Test 2
    listOne.insertFront(3);
    listOne.insertFront(2);
    listOne.insertFront(1);
    listOne.insertFront(0);
    cout << listOne << endl;

    //This is only here to provide a terminating stack frame
    // to prevent name reuse. In other words, I want this verible
    // to terminate, so I'm putting it in a new frame.
    if (true)
    {
        List<int> listTwo;
        List<int>::Iterator i = listOne.begin();
        List<int>::Iterator j = listTwo.begin();

        ++i;
        cout << listOne << endl;
        listOne.erase(i);
        cout << listOne << endl;
        listTwo.insertFront(3);
        listTwo.insertFront(2);
        listTwo.insertFront(0);
    }
    cout << "Passed Erase Test 2" << endl;
    //-------------------------------------------------------------

    /*
     Insert Tests   -   SUBJECT TO SCRUTINY
     */

    //-------------------------------------------------------------

     {
        List<int> listTwo;
        for (int i = 0; i < 300; ++i) {
            listTwo.insertFront(i);
        }
        int i = 300;
        while (!listTwo.isEmpty()) {
            int list_front = listTwo.removeFront();
            assert(--i == list_front);
        }
        cout << "Passed Insert Test 1" << endl;
        cout << endl;
     }

     {
        int SIZE = 1000;
        List<int> listTwo;
        for (int i = 0; i < SIZE; ++i) {
            if (i % 2) {
                listTwo.insertBack(i);
            }
            else {
                listTwo.insertFront(i);
            }
        }

        cout << listTwo << endl;

        int i = SIZE;
        while (!listTwo.isEmpty()) {
            if (i % 2) {
                int list_front = listTwo.removeFront();
                assert(--i == list_front);
            }
            else {
                int list_back = listTwo.removeBack();
                assert(--i == list_back);
            }
        }
     }


    cout << "ALL COMPLETE" << endl;
}
