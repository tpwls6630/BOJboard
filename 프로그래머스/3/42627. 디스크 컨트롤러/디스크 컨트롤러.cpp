#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int start;
    int end;
    int task;
    Job(int i, int s, int t) : id(i), start(s), end(-1), task(t) {}
    int turnaround() {
        if (end == -1) return -1;
        return end - start;
    }
};

struct comp {
    bool operator()(const Job &a, const Job &b) {
        if (a.task != b.task) return a.task > b.task;
        if (a.start != b.start) return a.start < b.start;
        return a.id < b.id;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });
    priority_queue<Job, vector<Job>, comp> q;
    int turnsum = 0;
    int curtime = 0;
    int i = 0;
    while(i < jobs.size()) {
        if (q.empty() || jobs[i][0] <= curtime) {
            Job j(i, jobs[i][0], jobs[i][1]);
            curtime = max(curtime, j.start);
            q.push(j);
            i++;
        }
        else {
            Job j = q.top();
            q.pop();
            curtime += j.task;
            j.end = curtime;
            turnsum += j.turnaround();
        }
    }
    
    while(!q.empty()) {
        Job j = q.top();
        q.pop();
        curtime += j.task;
        j.end = curtime;
        turnsum += j.turnaround();
    }

    return turnsum / jobs.size();
}