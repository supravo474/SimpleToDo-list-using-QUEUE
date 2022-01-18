
#include <iostream>
#include <queue>

using namespace std;

int showMenu(string menuItens[], const int N)
{
    cout << endl;
    cout << "----- MENU -----" << endl;
    for (int i = 0; i < N; i++)
        cout << "[" << i << "] " << menuItens[i] << endl;
    cout << "Option: ";
    int option = 0;
    cin >> option;
    cin.ignore();
    cout << endl;

    return option;
}

void printQueue(queue<string> queue)
{
    if (queue.empty())
    {
        cout << "No Tasks" << endl;
        return;
    }
    cout << "Tasks:" << endl;
    while (!queue.empty())
    {
        cout << queue.front() << endl;
        queue.pop();
    }
}

int main()
{
    const int N = 4;
    string menuItens[] = { // "Exit" must be the last option
        "Show tasks",
        "Add task",
        "Delete task",
        "Exit"
    };
    queue<string> myTasks;
    int option;
    do {
        string newTask;
        option = showMenu(menuItens, N);
        switch (option)
        {
            case 0 :
                printQueue(myTasks);
                break;
            case 1 :
                cout << "Enter a new task: ";
                getline(cin, newTask);
                myTasks.push(newTask);
                break;
            case 2:
                if (!myTasks.empty())
                {
                    cout << "Deleting " << myTasks.front() << "..." << endl;
                    myTasks.pop();
                }
                else
                    cout << "No tasks found!" << endl;
                break;
        }
    } while (option != (N-1)); // "Exit" must be the last option
    return 0;
}