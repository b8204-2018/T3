#include <iostream>
#include "Src\Stack.h "

using namespace std;
int main() {
    Stack Stack1;
    int elem;
    int call=-1;
    while (call != 3) {
        cout << "input 1 if you want to push element in stack\n"
                "input 2 if you want to pop element from stack\n"
                "input 3 if you want to close program\n"
                "input 4 if you want to see your stack\n"
                "At the end of the day rascal may not dream of zachet, but dear lord i fucking do. Also dont use char";
        cin >> call;
        switch(call) {
            case 1 :
                cout << " Input element that you want to add to stack\n";
                cin >> elem;
                Stack1.Push(elem);

                break;
            case 2 :
                Stack1.Pop();
                break;
            case 4 :
                Stack1.show();

                break;
        }
    }
    return 0;
}
