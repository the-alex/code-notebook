#include <iostream>
#include <stack>
using namespace std;

// Eventually I'll get around to this.
//  Repeat after me: "I am not good at recursion".

void hanoi(int disks) {
    // Assume a game where all disks start on stack A.
    stack<int> A;
    stack<int> B;
    stack<int> C;

    for (int i = disks; i > 0; --i) {
        A.push(i);
    }

}



int main(int argc, char const *argv[])
{
    // hanoi(3);
    return 0;
}
