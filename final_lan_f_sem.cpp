#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct to_do_list_manager {
    string title;
    string description;
};

void create_file(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "to do list manager\n";
        file << "add a new task\n";
        file << "display task\n";
        file << "delete task\n";
        file.close();
    } else {
        cout << "Unable to open file";
    }
}

void add_task(vector<to_do_list_manager>& tasks) {
    to_do_list_manager task;
    cout << "Enter task title: ";
    getline(cin, task.title);
    cout << "Enter task description: ";
    getline(cin, task.description);
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}

void display_tasks(const vector<to_do_list_manager>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }
    cout << "Tasks in your to-do list:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].title << " - " << tasks[i].description << endl;
    }
}

void delete_task(vector<to_do_list_manager>& tasks) {
    display_tasks(tasks);
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    cin.ignore();  
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<to_do_list_manager> tasks;
    create_file("createfile.txt");

    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add a new task\n";
        cout << "2. Display tasks\n";
        cout << "3. Delete a task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                add_task(tasks);
                break;
            case 2:
                display_tasks(tasks);
                break;
            case 3:
                delete_task(tasks);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

