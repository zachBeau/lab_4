#include <iostream>
#include <string>

using namespace std;
/**
 * Create the Stack Class (Survival Backpack)
 * Define a class Stack to represent a stack. The stack will act as your survival backpack, where you can store and retrieve items (e.g., weapons, food, tools).
 * The class should have the following private attributes:
 * capacity (int): The maximum number of items the stack can hold.
 * top (int): The index of the top item in the stack.
 * arr (dynamic array of type string): The array that stores the stack items.
 * Implement a constructor that accepts a size param to initialize the capacity, top, and arr.
 * Implement a deconstructor that deletes the arr.
 * Implement the following public methods:
 * push(string item): Adds an item to the top of the stack.
 * pop(): Removes the top item from the stack and returns it.
 * peek(): Returns the top item without removing it.
 * isEmpty(): Returns true if the stack is empty, otherwise false.
 * isFull(): Returns true if the stack is full, otherwise false.
 */
class Stack
{
    int capacity;
    int top;
    string* arr;
public:
    Stack() {
    }
    Stack(int size) : capacity(size){
        arr = new string[size];
        top = -1; 
    }
    
    ~Stack() {
        delete[] arr;
        cout << "array has been deleted" << endl; 
    }
    
    void push(string item) {
        if (isFull()) {
            cout << "Survival Backpack full" << endl; 
        } else {
            top++;
            arr[top] = item; 
            cout << item << " has been added to Survival Backpack in item slot: " << top + 1 << endl; 
        }
        if (top + 1 == capacity) {
            cout << "Max capacity of Survival Backpack has been reached." << endl; 
        }
    }
   
    void pop() {
        if (isEmpty()) {
            cout << "Survival backpack is empty" << endl; 
        } else {
            arr[top] = " ";
            top--; 
        }
    }
   
    void peek() {
        if (arr[top] == "") {
            cout << "Empty item slot" << endl; 
        } else {
            cout << "Item " << top + 1 << ": " << arr[top] << endl; 
        }
    }
    
    //overload peek()
    void peek(int n) {
        if ((n - 1) > capacity || n < 0) { 
            cout << "n out of range" << endl;
        } else if (arr[n - 1] == "") {
            cout << "Empty item slot" << endl; 
        } else {
            cout << "Item " << n << ": " << arr[n - 1] << endl; 
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }
};


int main() {
    Stack sB(10); 
    sB.pop(); 
    
    sB.push("knife");
    sB.push("sword");
    sB.push("rifle");
    sB.push("bat");
    sB.push("knife");
    sB.push("knife");
    sB.push("sword");
    sB.push("rifle");
    sB.push("bat");
    sB.push("Battle Axe");
    sB.push("Sheild");
    cout << sB.isEmpty() << endl; 
    cout << sB.isFull() << endl;     
    sB.peek();
    sB.peek(2);
    sB.peek(8);
    sB.peek(12);
    sB.peek(10);
    sB.peek(1);
    sB.peek(-1);



    return 0; 
}