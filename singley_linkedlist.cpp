#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *head = NULL, *temp, *newnode;
    int ch, pos, i, val;

    do {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertPos 4.Display 5.Exit\n";
        cin >> ch;

        if (ch == 1) {                     // Insert at beginning
            cin >> val;
            newnode = new Node();
            newnode->data = val;
            newnode->next = head;
            head = newnode;
        }

        else if (ch == 2) {                // Insert at end
            cin >> val;
            newnode = new Node();
            newnode->data = val;
            newnode->next = NULL;
            if (head == NULL)
                head = newnode;
            else {
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newnode;
            }
        }

        else if (ch == 3) {                // Insert at position
            cin >> pos >> val;
            newnode = new Node();
            newnode->data = val;
            temp = head;
            for (i = 1; i < pos - 1; i++)
                temp = temp->next;
            newnode->next = temp->next;
            temp->next = newnode;
        }

        else if (ch == 4) {                // Display
            temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

    } while (ch != 5);

    return 0;
}
