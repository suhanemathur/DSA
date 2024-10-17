#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Tree {
private:
    int n;
    vector<int> salaries;
    vector<vector<int>> adjList;

    // Helper function to perform DFS and check salary condition
    pair<long long, int> dfs(int node) {
        long long sumSalaries = salaries[node];
        int count = 1;

        cout << "Visiting node " << node << ", salary: " << salaries[node] << endl;

        for (int subordinate : adjList[node]) {
            pair<long long, int> result = dfs(subordinate);
            long long subSum = result.first;
            int subCount = result.second;
            sumSalaries += subSum;
            count += subCount;
        }

        if (count > 1) { // If the node has subordinates
            double average = static_cast<double>(sumSalaries - salaries[node]) / (count - 1);
            cout << "Node " << node << ", total salary sum: " << sumSalaries 
                 << ", subordinate count: " << count - 1 
                 << ", average subordinate salary: " << average << endl;
            if (salaries[node] < average) {
                cout << "Manager at node " << node << " is underpaid." << endl;
            }
        }

        return {sumSalaries, count};
    }

public:
    Tree(int n, const vector<int>& salaries) : n(n), salaries(salaries) {
        adjList.resize(n);
    }

    void addEdge(int parent, int child) {
        adjList[parent].push_back(child);
    }

    void checkSalaries() {
        dfs(0); // Assuming node 0 is the root
    }
};

int main() {
    int n = 6;
    vector<int> salaries = {100, 80, 90, 70, 60, 50};

    Tree tree(n, salaries);
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);

    tree.checkSalaries();

    return 0;
}
