#include <iostream>
using namespace std;

int main() {
    int q[5], front = 0, rear = -1, ch, x;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
        cin >> ch;

        if (ch == 1) {                // Enqueue
            cin >> x;
            if (rear == 4)
                cout << "Queue Full";
            else
                q[++rear] = x;
        }

        else if (ch == 2) {           // Dequeue
            if (front > rear)
                cout << "Queue Empty";
            else
                front++;
        }

        else if (ch == 3) {           // Display
            if (front > rear)
                cout << "Queue Empty";
            else
                for (int i = front; i <= rear; i++)
                    cout << q[i] << " ";
        }

    } while (ch != 4);

    return 0;
}
