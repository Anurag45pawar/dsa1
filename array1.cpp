#include <iostream>
using namespace std;

int main() {
    int arr[100], n, ch, pos, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout << "\n1.Traversal  2.Insertion  3.Deletion  4.Search  5.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 1) {  // Traversal
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }

        else if (ch == 2) {  // Insertion
            cout << "Enter position & value: ";
            cin >> pos >> val;
            if (pos >= 0 && pos <= n) {
                for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
                arr[pos] = val;
                n++;
            } else cout << "Invalid position\n";
        }

        else if (ch == 3) {  // Deletion
            cout << "Enter position: ";
            cin >> pos;
            if (pos >= 0 && pos < n) {
                for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
                n--;
            } else cout << "Invalid position\n";
        }

        else if (ch == 4) {  // Searching
            cout << "Enter value to search: ";
            cin >> val;
            bool found = false;
            for (int i = 0; i < n; i++)
                if (arr[i] == val) {
                    cout << "Found at position " << i << endl;
                    found = true;
                    break;
                }
            if (!found) cout << "Not found\n";
        }

    } while (ch != 5);

    return 0;
}
