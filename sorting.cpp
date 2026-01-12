#include <iostream>
using namespace std;

/* Bubble Sort */
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

/* Selection Sort */
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
}

/* Insertion Sort */
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

/* Merge Sort */
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[20];

    while (i <= m && j <= r)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

/* Quick Sort */
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

/* Display */
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main() {
    int a[20], n, ch;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1.Bubble 2.Selection 3.Insertion 4.Merge 5.Quick\n";
    cout << "Enter choice: ";
    cin >> ch;

    if (ch == 1) bubbleSort(a, n);
    else if (ch == 2) selectionSort(a, n);
    else if (ch == 3) insertionSort(a, n);
    else if (ch == 4) mergeSort(a, 0, n - 1);
    else if (ch == 5) quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    display(a, n);

    return 0;
}
