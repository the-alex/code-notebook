#include <iostream>
#include <stack>
#include <queue>

using namespace std;



void gen_permutations(stack<int>& prefix, queue<int>& suffix) {
    if(suffix.empty()) {
        stack<int> tempStack(prefix);
        while (!tempStack.empty())
        {
            cout << tempStack.top();
            tempStack.pop();
        }
        cout <<  endl;
        return;
    }
    for(int i = 0; i < suffix.size(); ++i) {
        prefix.push(suffix.front());
        suffix.pop();
        gen_permutations(prefix, suffix);
        suffix.push(prefix.top());
        prefix.pop();
    }
}

int main(int argc, char* argv[]) {
    stack<int> prefix;
    queue<int> suffix;
    for (int i = 0; i < 3; ++i) {
        suffix.push(i);
    }

    gen_permutations(prefix, suffix);

}
