#include <iostream>
using namespace std;

int main() {
    int s[5], top = -1, ch, x;

    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cin >> ch;

        if (ch == 1) {                 // Push
            cin >> x;
            if (top == 4)
                cout << "Overflow";
            else
                s[++top] = x;
        }

        else if (ch == 2) {            // Pop
            if (top == -1)
                cout << "Underflow";
            else
                top--;
        }

        else if (ch == 3) {            // Peek
            if (top == -1)
                cout << "Empty";
            else
                cout << s[top];
        }

        else if (ch == 4) {            // Display
            for (int i = top; i >= 0; i--)
                cout << s[i] << " ";
        }

    } while (ch != 5);

    return 0;
}
