#include <iostream>
using namespace std;

#define MAX 5

int main() {
    int q[MAX], front = -1, rear = -1, ch, x;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
        cin >> ch;

        if (ch == 1) {                    // Enqueue
            cin >> x;
            if ((rear + 1) % MAX == front)
                cout << "Queue Full";
            else {
                if (front == -1)
                    front = 0;
                rear = (rear + 1) % MAX;
                q[rear] = x;
            }
        }

        else if (ch == 2) {               // Dequeue
            if (front == -1)
                cout << "Queue Empty";
            else {
                if (front == rear)
                    front = rear = -1;
                else
                    front = (front + 1) % MAX;
            }
        }

        else if (ch == 3) {               // Display
            if (front == -1)
                cout << "Queue Empty";
            else {
                int i = front;
                while (true) {
                    cout << q[i] << " ";
                    if (i == rear) break;
                    i = (i + 1) % MAX;
                }
            }
        }

    } while (ch != 4);

    return 0;
}
