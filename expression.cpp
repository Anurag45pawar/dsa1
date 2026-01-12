#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char infix[50], postfix[50], stack[50];
    int top = -1, k = 0;

    cout << "Enter infix expression: ";
    cin >> infix;

    // Infix to Postfix
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            stack[++top] = ch;
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--;
        }
        else {
            while (top != -1 && prec(stack[top]) >= prec(ch))
                postfix[k++] = stack[top--];
            stack[++top] = ch;
        }
    }

    while (top != -1)
        postfix[k++] = stack[top--];

    postfix[k] = '\0';

    cout << "Postfix expression: " << postfix << endl;

    // Postfix Evaluation
    int valStack[50];
    top = -1;

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            valStack[++top] = ch - '0';
        }
        else {
            int b = valStack[top--];
            int a = valStack[top--];
            valStack[++top] = applyOp(a, b, ch);
        }
    }

    cout << "Result = " << valStack[top];
    return 0;
}
