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
            cout << "PUSH: Attempted to add " << item << ", Survival Backpack is full!" << endl; 
        } else {
            top++;
            arr[top] = item; 
            cout << "PUSH: " << item << " has been added" << endl; 
        }
    }
   
    void pop() {
        if (isEmpty()) {
            cout << "Survival backpack is empty, there's nothing left to use!" << endl; 
        } else {
            cout << "POP: You have used " << arr[top] << "!" << endl; 
            arr[top] = "";
            top--;
        }
    }
   
    void peek() {
        if (arr[top] == "") {
            cout << "Empty item slot" << endl; 
        } else {
            cout << "PEEK: " << "Item " << top + 1 << " " << arr[top] << endl; 
        }
    }
    
    //overload peek() to look at a specific item number. 
    void peek(int n) {
        if ((n - 1) > capacity || n < 0) { 
            cout << "Input n out of range" << endl;
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

/**
 * Create the InfiniteStack Class (Magic Backpack)
 * Define a new class InfiniteStack that simulates an infinite-sized stack. This stack will dynamically grow as more items are added, representing your magic backpack.
 * The class should have the following private attributes:
 * top (int): The index of the top item in the stack.
 * capacity (int): The current capacity of the stack, which will double each time it fills up.
 * arr (dynamic array of type string): The array that stores the stack items.
 * Implement the following public methods:
 * push(string item): Adds an item to the top of the stack. If the stack is full, it should dynamically resize (double its capacity).
 * currentCapacity(): Returns the current capacity of the stack.
 * pop(), peek(), isEmpty(): Same functionality as the fixed-size stack.
 * Implement a private method resize() that can be used to double the capacity of the stack when needed.
 * Implement a constructor that accepts an initialSize param to initialize the capacity, top, and arr.
 * Implement a deconstructor that deletes the arr.
 */
class InfiniteStack
{
    int capacity;
    int top;
    string* arr;
public:
    InfiniteStack() {
    }
    InfiniteStack(int size) : capacity(size){
        arr = new string[size];
        top = -1; 
    }

    //copy constructor
    InfiniteStack(const InfiniteStack& right) {
        capacity = right.capacity;
        top = right.top; 
        arr = new string[capacity];
        for (int i = 0; i < right.capacity; i++) {
            arr[i] = right.arr[i];
        }
    }

    //assignment operator
    InfiniteStack& operator=(const InfiniteStack& right) {
        if (this == &right) {
            return *this; 
        }
        string* temp = new string[right.capacity];       
        for (int i = 0; i < right.capacity; i++) {
            temp[i] = right.arr[i];
        }
        delete[] arr; 
        arr = temp; 
        capacity = right.capacity;
        top = right.top;
        return *this;
    }

    void push(string item) {
        if (isFull()) {
            string* temp = new string[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp; 
            capacity *= 2;
            cout << "PUSH: Magic Backpack has doubled in size. New Capacity is: " << capacity << endl; 
        }
        top++;
        arr[top] = item; 
        cout << "PUSH: " << item << " has been added" << endl; 
    }

    void currentCapacity() {
        cout << "Current Magic Backpack capacity is: " << capacity << endl; 
    }

    void pop() {
        if (isEmpty()) {
            cout << "Magic backpack is empty, theres nothing left to use." << endl; 
        } else {
            cout << "POP: You have used " << arr[top] << "!" << endl; 
            arr[top] = "";
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
    
    //overload peek() to look at a specific item number.
    void peek(int n) {
        if ((n - 1) > capacity || n < 0) { 
            cout << "Input n out of range" << endl;
        } else if (arr[n - 1] == "") {
            cout << "Empty item slot" << endl; 
        } else {
            cout << "PEEK: " << arr[n - 1] << endl; 
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }
};

int main()
{
    /**
     * Push Items onto the Stack (Stocking Up)
     * Create a Stack of strings with a capacity of 5 to represent your survival backpack.
     * Push the following items onto the stack: "Shotgun," "Medkit," "Ammo," "Water," and "Food."
     * Print a message each time you add an item, indicating what you've added to your backpack.
     */
    Stack sB(5);
    sB.push("Shotgun");
    sB.push("Medkit");
    sB.push("Ammo");
    sB.push("Water");
    sB.push("Food");
 

    /**
     * Handle Overflow (Backpack Overload)
     * Attempt to add another item, "Knife," to the stack, and handle the case where the stack is full by printing an appropriate message.
     */
    sB.push("Knife"); 

    /**
     * Pop Items from the Stack (Using Resources)
     * You're now facing a wave of zombies! Pop the 3 items from the stack
     * starting with the most recent item you added. Print a message each time you use an item,
     * indicating what you're using.
     */
    sB.pop();
    sB.pop();
    sB.pop();

    /**
     * Peek at the Top Item (Checking Supplies)
     * Before facing another wave of zombies, check what the top item in your backpack is without removing it.
     * Print the item that’s on top of the stack
     */
    sB.peek();

    /**
     * Handle Underflow (Running Out of Resources)
     * After using all items, try to pop one more item from the stack, and handle the case where the
     * stack is empty by printing an appropriate message.
     */
    sB.pop();
    sB.pop();
    sB.pop();

    /**
     * Using the InfiniteStack (Gathering Unlimited Resources)
     * Create an instance of InfiniteStack with an initial capacity of 5.
     * Push 12 items onto the stack (e.g., "Shotgun," "Medkit," "Ammo," "Water," "Food," "Grenade," "Axe," etc.).
     * Print a message after each time you add an item using peek(), indicating what you've added to your magic backpack.
     */
    InfiniteStack mB(5);

    mB.push("Shotgun");
    mB.peek();
    mB.push("Medkit");
    mB.peek();
    mB.push("Ammo");
    mB.peek();
    mB.push("Water");
    mB.peek();
    mB.push("Food");
    mB.peek();
    mB.push("Grenade");
    mB.peek();
    mB.push("Axe");
    mB.peek();
    mB.push("Snack");
    mB.peek();
    mB.push("Blanket");
    mB.peek();
    mB.push("Hat");
    mB.peek();
    mB.push("Jacket");
    mB.peek();
    mB.push("Pants");
    mB.peek();



    /**
     * Pop Items from the Magic Backpack (Using Resources)
     * As you face waves of zombies, pop three items from the stack to use them.
     * Print a message each time you use an item, indicating what you're using.
     */
    mB.pop();
    mB.pop();
    mB.pop();

    /**
     * Testing the InfiniteStack (Incredible Hoarding)
     * Test the InfiniteStack by continuously adding items to it and verifying that it properly resizes without any issues.
     * Create a for loop to add 40 more items to the magicBackpack (e.g., "Item1," "Item2," "Item3," etc.).
     * Print out the item added and the current capacity each time an item is added to show that the stack is expanding correctly
     */
    for (int i = 0; i < 40; i++) {
        mB.push("item");
        mB.peek(); 
        mB.currentCapacity(); 
    }
}
