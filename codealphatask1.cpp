#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
private:
    string task_name;
    bool completed;

public:
    Task(string name) : task_name(name), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    string getStatus() const {
        return completed ? "Completed" : "Not Completed";
    }

    string getTaskName() const {
        return task_name;
    }

    void displayTask(int index) const {
        cout << index + 1 << ". " << task_name << " - " << getStatus() << endl;
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& task_name) {
        tasks.push_back(Task(task_name));
        cout << "Task '" << task_name << "' has been added." << endl;
    }

    void markTaskCompleted(int task_index) {
        if (task_index >= 0 && task_index < tasks.size()) {
            tasks[task_index].markCompleted();
            cout << "Task '" << tasks[task_index].getTaskName() << "' marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            cout << "Your tasks:" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                tasks[i].displayTask(i);
            }
        }
    }
};

void displayMenu() {
    cout << "\nTodo List Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Mark Task as Completed" << endl;
    cout << "3. View Tasks" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    TodoList todo_list;

    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To clear the input buffer

        switch (choice) {
            case 1: {
                string task_name;
                cout << "Enter the task: ";
                getline(cin, task_name);
                todo_list.addTask(task_name);
                break;
            }
            case 2: {
                todo_list.viewTasks();
                int task_number;
                cout << "Enter the task number to mark as completed: ";
                cin >> task_number;
                cin.ignore();  // Clear input buffer
                todo_list.markTaskCompleted(task_number - 1);
                break;
            }
            case 3:
                todo_list.viewTasks();
                break;
            case 4:
                cout << "Exiting the application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

