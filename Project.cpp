#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

bool compareByArrival(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

bool compareByBurst(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

bool compareByPriority(Process a, Process b) {
    return a.priority < b.priority;
}

void roundRobin(vector<Process>& processes, int quantum) {
    queue<Process> q;
    int time = 0;
    for (auto& p : processes)
        p.remainingTime = p.burstTime;

    int i = 0;
    while (true) {
        bool done = true;
        for (auto& p : processes) {
            if (p.remainingTime > 0) {
                done = false;
                if (p.remainingTime > quantum) {
                    time += quantum;
                    p.remainingTime -= quantum;
                } else {
                    time += p.remainingTime;
                    p.waitingTime = time - p.burstTime;
                    p.remainingTime = 0;
                    p.turnaroundTime = time;
                }
            }
        }
        if (done) break;
    }

    cout << "\nRound Robin Results:\n";
    for (auto p : processes) {
        cout << "P" << p.pid << " WT: " << p.waitingTime
             << " TT: " << p.turnaroundTime << "\n";
    }
}

void priorityScheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareByPriority);
    int time = 0;
    for (auto& p : processes) {
        p.waitingTime = time;
        time += p.burstTime;
        p.turnaroundTime = time;
    }

    cout << "\nPriority Scheduling Results:\n";
    for (auto p : processes) {
        cout << "P" << p.pid << " WT: " << p.waitingTime
             << " TT: " << p.turnaroundTime << "\n";
    }
}

void shortestJobNext(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareByBurst);
    int time = 0;
    for (auto& p : processes) {
        p.waitingTime = time;
        time += p.burstTime;
        p.turnaroundTime = time;
    }

    cout << "\nShortest Job Next Results:\n";
    for (auto p : processes) {
        cout << "P" << p.pid << " WT: " << p.waitingTime
             << " TT: " << p.turnaroundTime << "\n";
    }
}

bool isSafe(vector<int> alloc[], vector<int> max[], vector<int> avail, int n, int m) {
    vector<bool> finish(n, false);
    vector<int> work = avail;
    vector<int> safeSeq;

    while (safeSeq.size() < n) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!finish[i]) {
                bool canFinish = true;
                for (int j = 0; j < m; ++j) {
                    if (max[i][j] - alloc[i][j] > work[j]) {
                        canFinish = false;
                        break;
                    }
                }
                if (canFinish) {
                    for (int j = 0; j < m; ++j)
                        work[j] += alloc[i][j];
                    finish[i] = true;
                    safeSeq.push_back(i);
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is not in a safe state!\n";
            return false;
        }
    }

    cout << "\nSafe sequence: ";
    for (auto i : safeSeq)
        cout << "P" << i << " ";
    cout << "\n";
    return true;
}

int main() {
    vector<Process> processes = {
        {0, 0, 6, 2}, {1, 0, 8, 1}, {2, 0, 7, 3}, {3, 0, 3, 2}
    };

    cout << "--- Hybrid Scheduling Simulation ---\n";
    roundRobin(processes, 2);
    priorityScheduling(processes);
    shortestJobNext(processes);

    // Example for Banker's Algorithm
    const int n = 3, m = 3;
    vector<int> avail = {3, 3, 2};
    vector<int> alloc[n] = {
        {0, 1, 0}, {2, 0, 0}, {3, 0, 2}
    };
    vector<int> max[n] = {
        {7, 5, 3}, {3, 2, 2}, {9, 0, 2}
    };

    cout << "\n--- Banker's Algorithm ---\n";
    isSafe(alloc, max, avail, n, m);

    return 0;
}
