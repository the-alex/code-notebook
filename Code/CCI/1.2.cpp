// Implement a function void reverse(char* str) that
// reverses a given null terminating string.


#include <iostream>
using namespace std;

void reverse(char* str) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }

    int endIndex = i - 1;
    for (i = 0; i < endIndex; ++i, --endIndex) {
        // swap(i, endIndex - i);
        char temp = str[i];
        str[i] = str[endIndex];
        str[endIndex] = temp;
    }
}


int main(int argc, char const *argv[])
{
    char test1[] = "rawr";
    char test2[] = "reverse";
    char test3[] =  "SeePlusPlus";

    char* tests[] = {test1, test2, test3};
    int sizeOfTests = 3;

    for(int i = 0; i < sizeOfTests; ++i) {
        cout << "Testing input: ";
        cout << tests[i] << endl;
        reverse(tests[i]);
        cout << "\t" << tests[i] << endl;
    }
    return 0;
}
