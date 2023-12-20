#include<iostream>
#include<iomanip>
using namespace std;
class function 
{
    int choice;
public:
    int stackandqueue() 
    {
        cout << endl << endl;
        cout << " 1. Queue with Array " << endl;
        cout << " 2. Stack with Array " << endl;
        cout << " 3. Queue with Linklist " << endl;
        cout << " 4. Stack with LinkList " << endl << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice && choice >= 1 && choice <= 4))
        {
            cout << endl << "Invalid Input !  Enter Again.......  : ";
            cin.clear();
            cin.ignore();
        }
        return choice;
    }
    int queueandstack(int choic) 
    {
        if (choic == 2 || choic == 4) 
        {
            cout << endl << endl;
            cout << setw(20) << "1. Push" << endl;
            cout << setw(19) << "2. Pop" << endl;
            cout << setw(20) << "3. peek" << endl;
            cout << setw(27) << "4. Empty check" << endl;
            cout << setw(26) << "5. full check" << endl;
            cout << setw(40) << "6. Check Balance Paratheses" << endl;
            cout << setw(34) << "7. infinix to postfix" << endl;
            cout << setw(32) << "8. Go to main list " << endl << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice && choice >= 1 && choice <= 7))
            {
                cin.clear();
                cin.ignore();
                cout << endl << "Invalid Input !  Enter Again.......  : ";
            }
        }
        else if (choic == 1 || choic == 3) 
        {
            cout << endl << endl;
            cout << setw(20) << "1. Enqueue" << endl;
            cout << setw(20) << "2. Dequeue" << endl;
            cout << setw(21) << "3. getFirst" << endl;
            cout << setw(20) << "4. getRear" << endl;
            cout << setw(25) << "5. reverseQueue" << endl;
            cout << setw(20) << "6. isEmpty" << endl;
            cout << setw(20) << "7. Display" << endl;
            cout << setw(29) << "8. Go to main list " << endl << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice && choice >= 1 && choice <= 7))
            {
                cin.clear();
                cin.ignore();
                cout << endl << "Invalid Input !  Enter Again.......  : ";
            }

        }
        return choice;
    }
};
class StackwithArray
{
    int* A;
    int top;
    int capacity;
public:
    StackwithArray() 
    {
    }
    StackwithArray(int size)
    {
        A = new int[size];
        top = -1;
        capacity = size;
    }
    ~StackwithArray()
    {
        delete[] A;
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack overflow\n";
            return;
        }
        top++;
        A[top] = x;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return -1;
        }
        int x = A[top];
        top--;
        return x;
    }
    bool isFull()
    {
        return top == capacity - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return A[top];
    }
    int size()
    {
        return top + 1;
    }
   
    int pre(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
    }
};
class Nodeforstacklisnlist
{
public:
    int data;
    Nodeforstacklisnlist* next;
    Nodeforstacklisnlist(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class StackLinkedList
{
private:
    Nodeforstacklisnlist* top;
    int size;
public:
    StackLinkedList()
    {
        top = NULL;
        size = 0;
    }
    void push(int data)
    {
        Nodeforstacklisnlist* newNode = new Nodeforstacklisnlist(data);
        newNode->next = top;
        top = newNode;
        size++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int data = top->data;
        Nodeforstacklisnlist* temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    // stack implementation using linked list is never full
    bool isFull()
    {

        return false;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    int getSize()
    {
        return size;
    }
};
class QueuewithArray 
{
private:
    int front;
    int rear;
    static const int Size = 10;
    int Arr[Size];
    int count;

public:
    QueuewithArray() 
    {
        front = -1;
        rear = -1;
        count = 0;
    }
    void Enqueue(int x) 
    {
        if (IsFull()) 
        {
            cout << "Queue is full." << endl;
        }
        else 
        {
            rear = rear + 1;
            Arr[rear] = x;
            count++;  // Increment count when enqueuing an element
            cout << "Enqueued: " << x << endl;
        }
    }
    void Dequeue() 
    {
        if (IsEmpty()) 
        {
            cout << "Queue is empty." << endl;
        }
        else 
        {
            int dequeuedElement = Arr[front];
            front = front + 1;
            count--;  // Decrement count when dequeuing an element
            cout << "Dequeued: " << dequeuedElement << endl;
        }
    }
    int getFront() 
    {
        if (IsEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else 
        {
            return Arr[front];
        }
    }
    int getRear() 
    {
        if (IsEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else 
        {
            return Arr[rear];
        }
    }
    bool IsFull() 
    {
        return rear == Size - 1;
    }
    int size() 
    {
        return count;
    }
    bool IsEmpty() 
    {
        return rear == -1 && front == -1;
    }
    void reverseQueue() 
    {
        if (IsEmpty()) 
        {
            cout << "Empty...." << endl;
            return;
        }
        for (int i = count; i > 0; i--) 
        {
            cout << Arr[i] << " ";
        }
    }
    void display() 
    {

        if (IsEmpty()) 
        {
            cout << "Empty...." << endl;
            return;
        }
        for (int i = 0; i < count; i++) 
        {
            cout << Arr[i] << " ";
        }
    }
};



class Nodeforqueuelinklist
{
public:
    int data;
    Nodeforqueuelinklist* next;

    Nodeforqueuelinklist(int value)
    {
        data = value;
        next = NULL;
    }
};

class linkedQueue
{
private:
    Nodeforqueuelinklist* front;
    Nodeforqueuelinklist* rear;

public:
    linkedQueue()
    {
        front = NULL;
        rear = NULL;
    }
    StackwithArray s1;
    void enqueue(int value)
    {
        Nodeforqueuelinklist* newNode = new Nodeforqueuelinklist(value);
        if (rear == NULL)
        {
            rear = front = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue already empty" << endl;
            return;
        }
        Nodeforqueuelinklist* t = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete t;
    }
    void getFront()
    {
        if (front == NULL)
        {
            cout << "Queue empty";
            return;
        }
        else
        {
            cout << "Front is: " << front->data << endl;
        }
    }
    void getRear()
    {
        if (rear == NULL)
        {
            cout << "Queue empty";
            return;
        }
        else
        {
            cout << "Rear is: " << rear->data << endl;
        }
    }
    bool isEmpty()
    {
        return (front == NULL);
    }
   
    void display()
    {
        Nodeforqueuelinklist* t = front;
        if (t == NULL)
        {
            cout << "Nothing in the queue" << endl;
        }
        else
        {
            while (t != NULL)
            {
                cout << t->data << " ";
                t = t->next;
            }
            cout << endl;
        }
    }

};
int main()
{
    system("cls");


    int choice;
    int innerChoice;
    int value;
    function f1;
    QueuewithArray Q1;
    StackwithArray S1(10);

    linkedQueue LQ1;
    StackwithArray SA1;
firstloop:
    cout << endl << " (()).....................................Stack and Queue............................................(())" << endl;

    choice = f1.stackandqueue();

    switch (choice) {
    case 1:
        system("cls");
        cout << endl << " ............................... Queue with Array .........................................." << endl;
        while (true) {
            innerChoice = f1.queueandstack(choice);
            switch (innerChoice) {
            case 1:
                cout << "Enter a value to enter in the queue: ";
                cin >> value;
                Q1.Enqueue(value);

                system("pause");
                break;

            case 2:
                Q1.Dequeue();
                cout << "Dequeued!";
                system("pause");
                break;

            case 3:
                Q1.getFront();
                system("pause");
                break;
            case 4:
                Q1.getRear();
                system("pause");
                break;
            case 5:
                Q1.reverseQueue();
                system("pause");
                break;
            case 6:
                Q1.IsEmpty();
                system("pause");
                break;
            case 7:
                Q1.display();
                system("pause");
                break;

            case 8:
                goto firstloop;
                break;
            }
        }
        break;
    case 2:
        system("cls");
        cout << endl << " ...............................Stack with Array.........................................." << endl;
        while (true) {
            innerChoice = f1.queueandstack(choice);
            switch (innerChoice) {
            case 1:
                cout << endl << "Enter the value you want to add :";
                cin >> value;
                S1.push(value);
                system("pause");
                cout << endl;
                break;
            case 2:
                S1.pop();
                cout << "Poped.." << endl;
                system("pause");
                cout << endl;
                break;
            case 3:
                S1.peek();
                system("pause");
                cout << endl;
                break;
            case 4:
                S1.isEmpty();
                system("pause");
                break;
            case 5:
                S1.isFull();
                system("pause");
                break;
            case 6:
                //////////////////////////////////
                system("pause");
                break;
            case 7:
                ///////////////////////////////
                system("pause");
                break;

            case 8:
                goto firstloop;
                break;
            }
        }
        break;
    case 3:
        system("cls");
        cout << endl << " ............................... Queue with LinkList.........................................." << endl;
        while (true) {
            innerChoice = f1.queueandstack(choice);
            switch (innerChoice) {
            case 1:
                cout << endl << "Enter the value you want to add  : ";
                cin >> value;
                LQ1.enqueue(value);
                system("pause");
                cout << endl;
                break;
            case 2:
                LQ1.dequeue();
                system("pause");
                cout << endl;
                break;
            case 3:
                LQ1.getFront();
                system("pause");
                cout << endl;
                break;
            case 4:
                LQ1.getRear();
                system("pause");
                cout << endl;
                break;
            case 5:
                //LQ1.reverseQueue();
                system("pause");
                break;
            case 6:
                LQ1.isEmpty();
                system("pause");
                break;
            case 7:
                LQ1.display();
                system("pause");
                break;
            case 8:
                goto firstloop;
                break;
            }
        }
        break;
    case 4:
        system("cls");
        cout << endl << " ...............................Stack with LinkList.........................................." << endl;
        while (true) {
            innerChoice = f1.queueandstack(choice);
            switch (innerChoice) {
            case 1:
                cout << endl << "Enter the value you want to add : ";
                cin >> value;
                SA1.push(value);
                system("pause");
                cout << endl;
                break;
            case 2:
                SA1.pop();
                system("pause");
                cout << endl;
                break;
            case 3:
                SA1.peek();
                system("pause");
                cout << endl;
                break;
            case 4:
                SA1.isEmpty();
                system("pause");
                cout << endl;
                break;
            case 5:
                SA1.isFull();
                system("pause");
                break;
            case 6:
                ////////////////////////////////////
                system("pause");
                break;
            case 7:
                ///////////////////////////////
                system("pause");
                break;

                break;
            case 8:
                goto firstloop;
                break;
            }
        }
        break;
    }

    return 0;
}
