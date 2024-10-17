#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> stocks = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stocks.size());
    stack<int> s;

    span[0] = 1;
    s.push(0);

    for (int i = 1; i < stocks.size(); i++) {
        while (!s.empty() && stocks[i] >= stocks[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }

    return 0;
}
