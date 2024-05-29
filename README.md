## Description

The task manager program is designed to manage tasks for a user, including the ability to add tasks, mark tasks as complete, display tasks, and view predefined tasks. Here's a detailed description of the program:

### Overview

The program features four main classes: Task, Eventclass, TaskList, and User. Each class serves a specific purpose in managing tasks and events for a user.

### Classes and Their Responsibilities

1. **Task**
   - **Attributes**:
     - `title`: The title of the task.
     - `deadline`: The deadline of the task.
     - `priority`: The priority of the task.
     - `completed`: A boolean to track if the task is completed.
   - **Methods**:
     - **Constructors**:
       - Default constructor initializing the task with default values.
       - Parameterized constructor initializing the task with given values.
     - `complete()`: Marks the task as completed.
     - `display()`: Displays the details of the task.

2. **Eventclass**
   - Inherits from Task.
   - **Additional Attribute**:
     - `eventDetails`: Specific details about the event.
   - **Methods**:
     - **Constructor**: Parameterized constructor initializing the event with task details and additional event details.
     - `display()`: Overrides the display method to include event-specific details.

3. **TaskList**
   - **Methods**:
     - `displayTasks()`: Displays a list of predefined tasks.

4. **User**
   - **Attributes**:
     - `name`: The name of the user.
     - `tasks`: An array to store tasks.
     - `taskCount`: A counter to keep track of the number of tasks.
   - **Methods**:
     - **Constructor**: Initializes the user with a name.
     - `getName()`: Returns the name of the user.
     - `addTask()`: Adds a task to the user's task list, ensuring it doesn't exceed the maximum limit.
     - `completeTask()`: Marks a specified task as completed based on its index.
     - `displayTasks()`: Displays all tasks for the user.

### Main Function

The main function serves as the entry point of the program and manages user interaction:
1. Prompts the user to enter their name and creates a User object.
2. Displays a menu with options to:
   - Add a task.
   - Complete a task.
   - Display all tasks.
   - View predefined tasks.
   - Exit the program.
3. Based on the user's choice, it performs the corresponding actions using methods from the User and TaskList classes.
4. Ensures the program runs in a loop until the user chooses to exit.

### Error Handling

The program includes basic error handling to catch and display a message for any unexpected errors.

### Example Usage

- The user can add a task by providing a title, deadline, and priority.
- Tasks can be marked as completed by specifying their index.
- All tasks or predefined tasks can be displayed based on user input.
