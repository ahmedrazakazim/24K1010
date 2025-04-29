#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

const int FIXED_CAPACITY = 5;

template <typename T>
class Stack {
private:
    T data[FIXED_CAPACITY];
    int top_index;

public:
    Stack() : top_index(0) {}

    bool isEmpty() const {
        return top_index == 0;
    }

    bool isFull() const {
        return top_index == FIXED_CAPACITY;
    }

    void push(const T& value) {
        if (isFull()) {
            throw StackOverflowException();
        }
        data[top_index++] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        top_index--;
    }

    T& top() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        return data[top_index - 1];
    }

    const T& top() const {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        return data[top_index - 1];
    }
};

int main() {
    Stack<int> intStack;

    try {
        cout << "Pushing 5 elements..." << endl;
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);
        intStack.push(4);
        intStack.push(5);
        cout << "Stack is now full. Attempting to push one more..." << endl;
        intStack.push(6);
    } catch (const StackOverflowException& e) {
        cout << "Pushing to a full stack: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Caught unexpected exception during push: " << e.what() << endl;
    }

    cout << endl;

    try {
        cout << "Popping all 5 elements..." << endl;
        intStack.pop();
        intStack.pop();
        intStack.pop();
        intStack.pop();
        intStack.pop();
        cout << "Stack is now empty. Attempting to pop one more..." << endl;
        intStack.pop();
    } catch (const StackUnderflowException& e) {
        cout << "Popping from an empty stack: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Caught unexpected exception during pop: " << e.what() << endl;
    }

    return 0;
}
