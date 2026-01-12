#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

int main() {
    Node *head = NULL, *tail = NULL, *temp, *newnode;
    int ch, val;

    do {
        cout << "\n1.Insert 2.Delete 3.Forward 4.Backward 5.Exit\n";
        cin >> ch;

        if (ch == 1) {                // Insert at end
            cin >> val;
            newnode = new Node();
            newnode->data = val;
            newnode->next = NULL;
            newnode->prev = tail;
            if (head == NULL)
                head = tail = newnode;
            else {
                tail->next = newnode;
                tail = newnode;
            }
        }

        else if (ch == 2) {           // Delete from end
            if (tail == NULL)
                cout << "Empty";
            else {
                temp = tail;
                tail = tail->prev;
                if (tail != NULL)
                    tail->next = NULL;
                else
                    head = NULL;
                delete temp;
            }
        }

        else if (ch == 3) {           // Forward traversal
            temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        else if (ch == 4) {           // Backward traversal
            temp = tail;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
        }

    } while (ch != 5);

    return 0;
}
