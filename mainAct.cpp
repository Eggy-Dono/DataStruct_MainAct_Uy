#include <iostream>

using namespace std;

// Node class represents each customer in the queue
class Node {
public:
    int data;     // Ticket number of the customer
    Node* next;   // Pointer to the next customer in the queue

    // Constructor to initialize a new customer node
    Node(int value) : data(value), next(nullptr) {}
};

// Queue class manages the queue of customers
class Queue {
private:
    Node* front;   // Pointer front (head) of the queue
    Node* rear;    // Pointer rear (tail) of the queue

public:
    // Constructor to initialize empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Method to add a new customer to the end of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);  // Create a new node for the customer

        // If the queue is empty, set both front and rear to the new node
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;   // Link new node after the current rear
            rear = newNode;         // Update rear to the new node
        }

        // Print notification message on customer arrival
        cout << "\n[INFO] Customer with ticket number " << value << " has arrived." << endl;
    }

    // Method to remove and serve the customer at the front of the queue
    void dequeue() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "\n[WARNING] No customers in the queue to serve." << endl;
            return;
        }

        Node* temp = front;     // Temporarily store the front node
        front = front->next;    // Move front to the next node

        // If dequeueing the last customer, update rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        // Print notification message on customer service
        cout << "\n[INFO] Serving customer with ticket number " << temp->data << "." << endl;
        delete temp;   // Deallocate memory for the served customer node
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Method to display the ticket number of the next customer to be served
    void peek() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "\n[INFO] No customers in the queue." << endl;
            return;
        }

        // Print the ticket number of the next customer without removing them from the queue
        cout << "\n[INFO] Next customer to be served has ticket number " << front->data << "." << endl;
    }

    // Method to display all customers currently in the queue
    void display() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "\n[INFO] No customers in the queue." << endl;
            return;
        }

        // Print all ticket numbers of customers in the queue
        cout << "\n[INFO] Customers in the queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Function to display the menu of options for the ticket counter simulation
void displayMenu() {
    cout << "\n****************************************" << endl;
    cout << "*      Ticket Counter Simulation       *" << endl;
    cout << "****************************************" << endl;
    cout << "1. New Customer (Enqueue)" << endl;
    cout << "2. Serve Customer (Dequeue)" << endl;
    cout << "3. Next Customer (Peek)" << endl;
    cout << "4. Display All Customers" << endl;
    cout << "5. Exit" << endl;
    cout << "****************************************" << endl;
}

// Main function where the program starts execution
int main() {
    Queue q;       // Create an instance of the Queue class
    int choice, value;

    // Loop to continuously display the menu and process user commands
    while (true) {
        displayMenu();   // Display the menu
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                //Add a new customer to the queue
                cout << "Enter ticket number for new customer: ";
                cin >> value;   // Read ticket number from user input
                q.enqueue(value);   // Call enqueue method to add customer to the queue
                break;
            case 2:
                // Serve the next customer in line
                q.dequeue();   // Call dequeue method to serve customer
                break;
            case 3:
                // Display the ticket number of the next customer to be served
                q.peek();   // Call peek method to display next customer
                break;
            case 4:
                // Display all customers currently waiting in the queue
                q.display();   // Call display method to show all customers
                break;
            case 5:
                // Exit the program
                cout << "\n[INFO] Closing ticket counter. Have a Good Day!" << endl;
                return 0;
            default:
                // Handle invalid menu choice
                cout << "\n[ERROR] Invalid choice. Please select a valid option (1-5)." << endl;
        }
    }

    return 0;
}
