#include "Task.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
using namespace Task_Class;

void add_task(vector<Task>& tasks, int& ID);  //Add task function
void edit_task(vector<Task>& tasks, int ID);  //Add task function
void delete_task(vector<Task>& task_list, int ID);  //Delete task function
void view_tasks(vector<Task> task_list);   //Print list function

void ct_delay(int seconds);   //Delay function (ctime)
void end_program(int delay);   //End the program function (delay in seconds)

void show_menu()
{
    cout << "=================================" << "\n";
    cout << "What would you like to do?" << "\n";
    cout << "---------------------------------" << "\n";
    cout << "1. Add Task" << "\n";
    cout << "2. Edit Task" << "\n";
    cout << "3. Delete Task" << "\n";
    cout << "4. View Your Tasks" << "\n";
    cout << "5. Exit" << "\n";
    cout << "=================================" << "\n";
    cout << "Enter your choice: ";
}

int main()
{
    cout << "\033[30;47m";
    cout << "\033[2J\033[H";

    std::string title_in = "UnTitled", content_in = "No Content";
    int status_in = 0, priority_in = 2, ID = 0;

    int choice;

    vector<Task> task_list;

    cout << "By: Nassary =====================" << "\n";
    cout << "---WELCOME TO THE TASK MANAGER---" << "\n";

    while (true)
    {
        show_menu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();

            cout << "=================================" << "\n";
            cout << "Invalid Input!" << "\n";
        }
        else {
            switch (choice)
            {
                case 1:
                    add_task(task_list, ID);

                    break;
                case 2:
                    edit_task(task_list, ID);

                    break;
                case 3:
                    delete_task(task_list, ID);

                    break;
                case 4:
                    view_tasks(task_list);

                    break;
                case 5:
                    end_program(3);

                    break;
                default:
                    cout << "=================================" << "\n";
                    cout << "Invalid choice!" << "\n";
            }
        }
    }

    cout << "\033[0m";
}

void add_task(vector<Task>& tasks, int& ID) {
    std::string title_in, content_in;
    int priority_in;

    cin.ignore();

    cout << "=================================" << "\n";
    cout << "Enter the task title: ";
    getline(cin, title_in);
    cout << "---------------------------------" << "\n";
    cout << "Enter the task content:" << "\n";
    getline(cin, content_in);
    cout << "---------------------------------" << "\n";
    cout << "Choose the task priority:" << "\n";

    do
    {
    cout << "1. Low" << "\n" << "2. Medium" << "\n" << "3. High" << "\n";
    cout << "Enter your choice: ";
    cin >> priority_in;
    } while (priority_in < 1 || priority_in > 3);

    Task new_task;
    new_task.set_title(title_in);
    new_task.set_content(content_in);
    new_task.set_status(0);
    new_task.set_priority(priority_in);
    new_task.set_id(ID++);

    tasks.push_back(new_task);

    cout << "=================================" << "\n";
    cout << "Task added successfully!" << "\n";
}

void edit_task(vector<Task>& task_list, int ID)
{
    std::string title, content, status_in, priority_in;
    int status, priority;

    bool found = false;

    cout << "=================================" << "\n";
    cout << "Enter the ID for the task you want to edit:";
    cin >> ID;

    for (int i = 0; i < task_list.size(); i++)
    {
        if (task_list[i].get_id() == ID)
        {
            found = true;
            int choice = 0;

            ostringstream format;
            format << setfill('0') << setw(3) << task_list[i].get_id();
            std::string ID = format.str();

            status = task_list[i].get_status();
            priority = task_list[i].get_priority();

            cout << "=================================" << "\n";
            cout << "ID:" << ID << "\t" << "|" << "\t" <<task_list[i].get_title() << "\n";
            cout << "---------------------------------" << "\n";
            cout << "Description:" << "\n" << task_list[i].get_content() << "\n";
            cout << "---------------------------------" << "\n";
            cout << "Status  :" << "\t \t" << (status == 0 ? "Pending" : "Done" ) << "\n";
            cout << "Priority:" << "\t \t" << (priority == 1 ? "Low" : priority == 2 ? "Medium" : "High") << "\n";
            cout << "=================================" << "\n";
            cout << "What would you like to edit?" << "\n";
            cout << "1. Title" << "\n";
            cout << "2. Description" << "\n";
            cout << "3. Status" << "\n";
            cout << "4. Priority" << "\n";
            cout << "Enter your choice:";
            cin >> choice;

            switch (choice) {
              case 1:
                    cout << "---------------------------------" << "\n";
                    cout << "Enter the new title:";

                    cin.ignore();
                    getline(cin, title);
                    task_list[i].set_title(title);

                    cout << "=================================" << "\n";
                    cout << "Title changed successfully!" << "\n";

                    break;
                case 2:
                    cout << "---------------------------------" << "\n";
                    cout << "Enter the new description:" << "\n";

                    cin.ignore();
                    getline(cin, content);
                    task_list[i].set_content(content);

                    cout << "=================================" << "\n";
                    cout << "Description changed successfully!" << "\n";

                    break;
                case 3:
                    cout << "---------------------------------" << "\n";
                    cout << "Enter the new status:";
                    cin >> status_in;
                    if (status_in == "Done" || status_in == "done" || status_in == "DONE")
                    {
                        task_list[i].set_status(1);

                        cout << "=================================" << "\n";
                        cout << "Status changed successfully!" << "\n";

                        break;
                    }
                    if (status_in == "Pending" || status_in == "pending" || status_in == "PENDING")
                    {
                        task_list[i].set_status(0);

                        cout << "=================================" << "\n";
                        cout << "Status changed successfully!" << "\n";

                        break;
                    }
                    else
                    {
                        cout << "Invalid Input!" << "\n";

                        break;
                    }
                case 4:
                    cout << "---------------------------------" << "\n";
                    cin >> priority_in;
                    if (priority_in == "Low" || priority_in == "Medium" || priority_in == "High" ||
                    priority_in == "LOW" || priority_in == "MEDIUM" || priority_in == "HIGH" ||
                    priority_in == "low" || priority_in == "medium" || priority_in == "high")
                    {
                        if (priority_in == "Low" || priority_in == "low" || priority_in == "LOW")
                         {
                            task_list[i].set_priority(1);

                             cout << "=================================" << "\n";
                             cout << "Priority changed successfully!" << "\n";
                         }
                        if (priority_in == "Medium" || priority_in == "medium" || priority_in == "MEDIUM")
                        {
                            task_list[i].set_priority(2);

                            cout << "=================================" << "\n";
                            cout << "Priority changed successfully!" << "\n";
                        }
                        if (priority_in == "High" || priority_in == "high" || priority_in == "HIGH")
                        {
                            task_list[i].set_priority(3);

                            cout << "=================================" << "\n";
                            cout << "Priority changed successfully!" << "\n";
                        }
                    }
                    else
                    {
                        cout << "Invalid Input!" << "\n";
                    }
                default:
                    cout << "=================================" << "\n";
                    cout << "Invalid choice!" << "\n";

                    break;
            }
        }
    }

    if (!found)
    {
        cout << "=================================" << "\n";
        cout << "Invalid ID!" << "\n";
    }
}

void delete_task(vector<Task>& task_list, int ID)
{
    char choice;
    bool deleted = false;

    cout << "=================================" << "\n";
    cout << "Enter the ID for the task you want to delete:";
    cin >> ID;

    for (int i = 0; i < task_list.size(); i++)
    {
        if (task_list[i].get_id() == ID)
        {
            cout << "---------------------------------" << "\n";
            cout << "Are you sure you want to delete the task \"" << task_list[i].get_title() << "\" (y/n)" << "\n";
            cout << ">>";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                task_list.erase(task_list.begin() + i);
                deleted = true;
            }
            else if (choice == 'n' || choice == 'N')
            {
                break;
            }
            else
            {
                cout << "=================================" << "\n";
                cout << "Invalid Input!" << "\n";
            }
        }
        else
        {
            cout << "=================================" << "\n";
            cout << "Invalid ID!" << "\n";

            break;
        }

        break;
    }

    if (deleted)
    {
        cout << "=================================" << "\n";
        cout << "Task deleted successfully!" << "\n";
    }
}

void view_tasks(vector<Task> task_list) {
    std::string title, content, ID;
    int status, priority;
    int choice;

    cout << "=================================" << "\n";
    cout << "What would you like to view?" << "\n";
    cout << "1. All Tasks" << "\n";
    cout << "2. Specific Task" << "\n";
    cout << "Enter your choice:";
    cin >> choice;

    switch (choice)
    {
        case 1:
            for (int i = 0; i < task_list.size(); i++)   //Loop that prints the array elements
            {
                ostringstream format;
                format << setfill('0') << setw(3) << task_list[i].get_id();
                ID = format.str();

                status = task_list[i].get_status();
                priority = task_list[i].get_priority();

                cout << "=================================" << "\n";
                cout << "ID:" << ID << "\t" << "|" << "\t" <<task_list[i].get_title() << "\n";
                cout << "---------------------------------" << "\n";
                cout << "Description:" << "\n" << task_list[i].get_content() << "\n";
                cout << "---------------------------------" << "\n";
                cout << "Status  :" << "\t \t" << (status == 0 ? "Pending" : "Done" ) << "\n";
                cout << "Priority:" << "\t \t" << (priority == 1 ? "Low" : priority == 2 ? "Medium" : "High") << "\n";
            }

            break;
        case 2:
            int ID;

            cout << "---------------------------------" << "\n";
            cout << "Enter the ID for the task you want to view:";
            cin >> ID;

            for (int i = 0; i < task_list.size(); i++)
            {
                if (task_list[i].get_id() == ID)
                {
                    ostringstream format;
                    format << setfill('0') << setw(3) << task_list[i].get_id();
                    std::string ID = format.str();

                    status = task_list[i].get_status();
                    priority = task_list[i].get_priority();

                    cout << "=================================" << "\n";
                    cout << "ID:" << ID << "\t" << "|" << "\t" << task_list[i].get_title() << "\n";
                    cout << "---------------------------------" << "\n";
                    cout << "Description:" << "\n" << task_list[i].get_content() << "\n";
                    cout << "---------------------------------" << "\n";
                    cout << "Status  :" << "\t \t" << (status == 0 ? "Pending" : "Done" ) << "\n";
                    cout << "Priority:" << "\t \t" << (priority == 1 ? "Low" : priority == 2 ? "Medium" : "High") << "\n";
                }
            }

            break;
        default:
            cout << "Invalid Choice!" << "\n";

            break;
    }
}

//Delay function (ctime)
void ct_delay(int seconds)
{
    time_t start_time = time(0);   //Variables

    while (time(0) - start_time < seconds){}   //Busy loop, does nothing till the time is up
}

//End the program function
void end_program(int delay)
{
    char choice;

    cout << "=================================" << "\n";
    cout << "Are you sure you want to exit the program? (y/n)" << "\n";
    cout << ">>";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cin.ignore();   //Ignore the newline left in the input
        cout << "---------------------------------" << "\n";

        for (int i = delay; i >= 0; i--)   //Loop that counts down the delay time
        {
            cout << "\r" << "Exiting in " << i << "..." << flush;
            ct_delay(1);
        }

        exit(0);   //Exit the program
    }
    else if (choice == 'n' || choice == 'N')
    {
        return;
    }
    else
    {
        cout << "=================================" << "\n";
        cout << "Invalid Input!" << "\n";
    }
}