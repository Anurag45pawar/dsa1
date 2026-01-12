#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *head = NULL, *tail = NULL, *temp, *newnode;
    int ch, val;

    do {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\n";
        cin >> ch;

        if (ch == 1) {               // Insert at end
            cin >> val;
            newnode = new Node();
            newnode->data = val;
            if (head == NULL) {
                head = tail = newnode;
                tail->next = head;
            } else {
                tail->next = newnode;
                tail = newnode;
                tail->next = head;
            }
        }

        else if (ch == 2) {          // Delete from beginning
            if (head == NULL)
                cout << "Empty";
            else if (head == tail) {
                delete head;
                head = tail = NULL;
            } else {
                temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
        }

        else if (ch == 3) {          // Display
            if (head != NULL) {
                temp = head;
                do {
                    cout << temp->data << " ";
                    temp = temp->next;
                } while (temp != head);
            }
        }

    } while (ch != 4);

    return 0;
}
