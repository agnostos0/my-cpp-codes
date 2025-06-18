#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int>* s1 = new stack<int>(); // dynamically allocate

    s1->push(10);
    s1->push(20);
    cout << "Top element: " << s1->top() << endl; // 20

    delete s1; // manually free memory
    return 0;
}
