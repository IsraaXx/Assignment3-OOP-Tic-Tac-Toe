// File name: A3_SheetPb5_20221184.cpp.
// Purpose: problem 5 assignment 3, Task Manager.
// Author: Nour Ahmed Abd El Aziz.
// ID: 20221184.
// Section: S1.
//======================================================================================================================

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Process {
private:
    string name;
    int PID;
    string sessionName;
    int sessionNum;
    string memory;
public:
    Process(string n, int pid, string sName, int sNum, string m);
    string getName() const {
        return name;
    }
    int getPid() const {
        return PID;
    }
    string getSessionName() const {
        return sessionName;
    }
    int getSessionNum() const {
        return sessionNum;
    }
    string getMemoryUsage() const {
        return memory;
    }
};


class TaskManager {
private:
    vector <Process> tasks;
public:
    TaskManager() {}
    void addProcess(const Process& process);
    void sortByName();
    void sortByPID();
    void sortByMemory();
    void display();
    void loadFromOS();
};

//======================================================================================================================
Process :: Process (string n, int pid, string sName, int sNum, string m) : name(n),
                    PID(pid), sessionName(sName), sessionNum(sNum), memory(m) {};

void TaskManager :: sortByName() {
    sort(tasks.begin(), tasks.end(),
                  [](const Process& p1, const Process& p2) {
                      return p1.getName() < p2.getName();
                  });
}

void TaskManager :: sortByPID() {
    sort(tasks.begin(), tasks.end(),
                  [](const Process& p1, const Process& p2) {
                      return p1.getPid() < p2.getPid();
                  });
}

void TaskManager :: sortByMemory() {
     sort(tasks.begin(), tasks.end(),
                  [](const Process& p1, const Process& p2) {
                      return p1.getMemoryUsage() > p2.getMemoryUsage();
                  });
}
void TaskManager :: addProcess(const Process& process) {
    tasks.push_back(process);
}

void TaskManager :: display() {
    for (const auto &process: tasks) {
        cout << process.getName() << "\t\t" << process.getPid()
             << "\t\t" << process.getSessionName() << "\t\t" << process.getSessionNum()
             << "\t\t" << process.getMemoryUsage() << "\n";
    }
}

void TaskManager :: loadFromOS() {
    system("tasklist>tasklist.txt");
}
//======================================================================================================================

int main() {

    TaskManager process_list;
    Process p1("chrome.exe\t", 227756, "Running", 10100, "32-bit");
    Process p2("cmd.exe\t\t", 512, "Running", 48, "64-bit");
    Process p3("explorer.exe\t", 7108, "Running", 29529, "64-bit");
    Process p4("skype.exe\t", 22456, "Running", 656, "64-bit");
    process_list.addProcess(p1);
    process_list.addProcess(p2);
    process_list.addProcess(p3);
    process_list.addProcess(p4);


    process_list.loadFromOS();
    ifstream f ("tasklist.txt");

    cout << "Image Name                         PID     Session Name       Session#       Mem Usage\n";
    cout << "=========================     ======== ================    ===========    ============\n";


    process_list.sortByName();
    process_list.display();

    cout << "--------------------------------------------------------------------------------------\n";

    process_list.sortByPID();
    process_list.display();

    cout << "--------------------------------------------------------------------------------------\n";


    process_list.sortByMemory();
    process_list.display();
    return 0;
}
