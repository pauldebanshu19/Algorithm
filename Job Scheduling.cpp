#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job 
{
    int id, deadline, profit;
};
bool compare(Job a, Job b) 
{
    return a.profit > b.profit;
}
int jobScheduling(vector<Job> &jobs) 
{
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    
    vector<int> schedule(maxDeadline + 1, -1); 
    int totalProfit = 0;

    for (auto job : jobs) {
        
        for (int t = job.deadline; t > 0; t--) {
            if (schedule[t] == -1) { 
                schedule[t] = job.id; 
                totalProfit += job.profit;
                break;
            }
        }
    }
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i] != -1) {
            cout << "Job" << schedule[i] << " ";
        }
    }
    cout << endl;

    return totalProfit;
}
int main() 
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    cout << "Enter job details (ID, Deadline, Profit):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    int maxProfit = jobScheduling(jobs);
    cout << "Maximum Profit: " << maxProfit << endl;
    return 0;
}
