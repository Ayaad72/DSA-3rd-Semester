#include <iostream>
#include <iomanip> // For using setw to center the text
using namespace std;

// Node structure for Linked List Implementation
struct Node {
    int data;
    Node* next;
};

// Stack Implementation using Linked List
class StackLL {
    Node* top;

public:
    StackLL() { top = nullptr; }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek operation (top element)
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Queue Implementation using Linked List
class QueueLL {
    Node* front;
    Node* rear;

public:
    QueueLL() {
        front = rear = nullptr;
    }

    // Enqueue operation (add element to the rear)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation (remove element from the front)
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

// Stack Implementation using Array
class StackArray {
    int arr[100];
    int top;

public:
    StackArray() { top = -1; }

    // Push operation
    void push(int value) {
        if (top >= 100 - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = value;
        }
    }

    // Pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    // Peek operation (top element)
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Queue Implementation using Array
class QueueArray {
    int arr[100];
    int front, rear;

public:
    QueueArray() { front = rear = -1; }

    // Enqueue operation
    void enqueue(int value) {
        if (rear >= 100 - 1) {
            cout << "Queue Overflow!" << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
        }
    }

    // Dequeue operation
    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front++];
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

// Function to get precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Function to check if a character is a digit (no cctype)
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to convert infix to postfix
string infixToPostfix(const char* infix) {
    StackArray stack;
    string postfix = "";
    
    int i = 0;
    while (infix[i] != '\0') {
        char c = infix[i];

        // If character is an operand, add to the result
        if (isDigit(c)) {
            postfix += c;
        }
        // If character is '(', push to stack
        else if (c == '(') {
            stack.push(c);
        }
        // If character is ')', pop and output until '(' is found
        else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop();  // Pop '(' from the stack
        }
        // If character is an operator
        else {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char* postfix) {
    StackArray stack;
    
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];

        // If the character is a digit, push to stack
        if (isDigit(c)) {
            stack.push(c - '0');  // Convert char to integer
        } else {
            int val2 = stack.pop();
            int val1 = stack.pop();

            switch (c) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
            }
        }
        i++;
    }
    return stack.pop();
}

// Function to print the output in table form with borders
void printTableHeader() {
    cout << "+-------------------------+-----------------------+" << endl;
    cout << "|         Operation       |         Result        |" << endl;
    cout << "+-------------------------+-----------------------+" << endl;
}

void printTableRow(string operation, string result) {
    cout << "| " << setw(23) << left << operation << " | " << setw(21) << left << result << " |" << endl;
}

void printTableFooter() {
    cout << "+-------------------------+-----------------------+" << endl;
}

int main() {
    // Creative Display for Testing Stack and Queue with Linked List
    printTableHeader();
    printTableRow("Testing Stack and Queue (LL)", "");
    
    StackLL stackLL;
    stackLL.push(10);
    stackLL.push(20);
    cout << "| Top of Stack (LL): " << setw(17) << left << stackLL.peek() << " |" << endl;
    cout << "| Pop from Stack (LL): " << setw(14) << left << stackLL.pop() << " |" << endl;

    QueueLL queueLL;
    queueLL.enqueue(10);
    queueLL.enqueue(20);
    cout << "| Dequeue from Queue (LL): " << setw(8) << left << queueLL.dequeue() << " |" << endl;

    // Testing Stack and Queue with Array
    printTableRow("Testing Stack and Queue (Array)", "");
    
    StackArray stackArray;
    stackArray.push(10);
    stackArray.push(20);
    cout << "| Top of Stack (Array): " << setw(17) << left << stackArray.peek() << " |" << endl;
    cout << "| Pop from Stack (Array): " << setw(14) << left << stackArray.pop() << " |" << endl;

    QueueArray queueArray;
    queueArray.enqueue(10);
    queueArray.enqueue(20);
    cout << "| Dequeue from Queue (Array): " << setw(8) << left << queueArray.dequeue() << " |" << endl;

    // Infix to Postfix Conversion
    printTableRow("Infix to Postfix Conversion", "");
    const char* infix = "3+(2*2)";
    string postfix = infixToPostfix(infix);
    cout << "| Postfix: " << setw(21) << left << postfix << " |" << endl;

    int result = evaluatePostfix(postfix.c_str());
    cout << "| Evaluated Postfix Result: " << setw(5) << left << result << " |" << endl;

    printTableFooter();

    return 0;
}
