#include <iostream>
using namespace std;

const int MAX_TASKS = 10; // Maximum number of tasks a user can have

class Task {
private:
    string title;            // Declare a private member variable to store the title of the task
    string deadline;         // Declare a private member variable to store the deadline of the task
    int priority;            // Declare a private member variable to store the priority of the task
    bool completed;          // Declare a private member variable to track if the task is completed
public:
    Task() : title(""), deadline(""), priority(0), completed(false) {}  // Default constructor initializing member variables
    Task(string t, string d, int p) : title(t), deadline(d), priority(p), completed(false) {}  // Constructor initializing member variables with parameters

    void complete() { completed = true; }  // Method to mark the task as completed

    void display()  {  // Method to display details of the task
        cout << "Title: " << title << ", Deadline: " << deadline
             << ", Priority: " << priority << ", Completed: " << (completed ? "Yes" : "No") << endl;
    }
};

class Eventclass : public Task {
private:
    string eventDetails; // Additional details specific to EventTask
public:
    Eventclass(string t, string d, int p, string details)
        : Task(t, d, p),
        eventDetails(details) {}

    void display() {  // Override display method
        Task::display();
        cout << "Event Details: " << eventDetails << endl;
    }
};

class TaskList {  // Define a class to manage a list of predefined tasks
public:
    void displayTasks() {  // Method to display predefined tasks
        cout << "Predefined tasks:" << endl;
        cout << "- Event Manager" << endl;
        cout << "- Poster Designer" << endl;
        cout << "- Catering Manager" << endl;
        cout << "- Decoration Manager" << endl;
    }
};

class User {  // Define a class to manage user-related tasks
private:
    string name;          // Declare a private member variable to store the name of the user
    Task tasks[MAX_TASKS];  // Declare a private array to store user's tasks
    int taskCount;        // Declare a private member variable to store the count of user's tasks
public:
    User(string n) : name(n), taskCount(0) {}  // Constructor initializing member variables with parameter

    string getName()  {  // Method to get the name of the user
        return name;
    }

    void addTask(const Task &task) {  // Method to using Pointers add a task to the user's task list
        if (taskCount <= MAX_TASKS) {
            tasks[taskCount++] = task;
            cout << "Task added successfully." << endl;
        } else {
            cout << "Task limit reached. Cannot add more tasks." << endl;
        }
    }

    void completeTask(int index) {  // Method to mark a task as completed
        if (index >= 0 && index < taskCount) {
            tasks[index].complete();
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index. No task marked as completed." << endl;
        }
    }

    void displayTasks() {  // Method to display user's tasks
        if (taskCount == 0) {
            cout << "No tasks available for " << name << "." << endl;
        } else {
            cout << "Tasks for " << name << ":" << endl;
            for (int i = 0; i < taskCount; ++i) {
                cout << i + 1 << ".";
                tasks[i].display();
            }
        }
    }
};

int main() {
    string userName;  // Declare a variable to store the user's name
    cout << "Enter user name: ";  // Prompt the user to enter their name
    cin >> userName;  // Read the user's name from input

    User user(userName);  // Create a User object with the entered name
    TaskList predefinedTasks;  // Create a TaskList object to manage predefined tasks

    int choice;  // Declare a variable to store the user's choice
    try {
        do {
            cout << "\n1. Add Task \n2. Complete Task \n3. Display Tasks \n4. View Predefined Tasks \n5. Exit " << endl;  // Display menu options
            cout << "Enter your choice: ";  // Prompt the user to enter their choice
            cin >> choice;  // Read the user's choice from input
            cin.ignore();  // To consume the newline character left by cin

            if (choice == 1) {  // If the user chooses to add a task
                string title, deadline;  // Declare variables to store task title and deadline
                int priority;  // Declare a variable to store task priority
                cout << "Enter task title: ";  // Prompt the user to enter task title
                cin >> title;  // Read the task title from input
                cout << "Enter task deadline: ";  // Prompt the user to enter task deadline
                cin >> deadline;  // Read the task deadline from input
                cout << "Enter task priority: ";  // Prompt the user to enter task priority
                cin >> priority;  // Read the task priority from input
                cin.ignore();  // To consume the newline character left by cin

                user.addTask(Task(title, deadline, priority)); // Add a new task to the user's task list
            } else if (choice == 2) {  // If the user chooses to complete a task
                int taskIndex;  // Declare a variable to store the index of the task to complete
                cout << "Enter task number to complete: ";  // Prompt the user to enter task number
                cin >> taskIndex;  // Read the task number from input
                cin.ignore();  // To consume the newline character left by cin
                user.completeTask(taskIndex - 1);  // Mark the selected task as completed
            } else if (choice == 3) {  // If the user chooses to display their tasks
                user.displayTasks();  // Display the user's tasks
            } else if (choice == 4) {  // If the user chooses to view predefined tasks
                predefinedTasks.displayTasks();  // Display the predefined tasks
            }

        } while (choice != 5);  // Repeat the loop until the user chooses to exit
    } catch (...) {  // Catch any unexpected errors
        cout << "An unexpected error occurred." << endl;  // Display an error message
    }

    return 0;  // Return 0 to indicate
}
