#include "List.cpp"
#include <iostream>
using namespace std;

template <typename T>
ostream& operator <<(ostream& os, const List<T>& list) {
    cout << "( ";
    for( typename List<T>::Iterator i = lst.begin(); i != lst.end(); ++i )
    {
        cout << *i << " ";
    }
    cout << ")";
    return os;
}


int main(int argc, char const *argv[]) {

    List<int> dat_list;

    for (int i = 0; i < 10; ++i)
    {
        dat_list.insert_front(i);
    }

    cout <<
    return 0;
}