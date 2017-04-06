#include <bits/stdc++.h>
using namespace std;

map<char, int> priority {
    { '(', -1 },
    { '*', 1 },
    { '/', 1 },
    { '+', 0 },
    { '-', 0 }
};

int main() {
    string in;
    cin >> in; // Input is for example "5*5-4/4+3"

    string output;
    stack<char> stk;
    for (int i = 0; i < in.size(); i++) {
        switch (in[i]) {
            case '(':
                stk.push('(');
                break;
            case ')': // Output everything between the parentheses
                while (stk.top() != '(') {
                    output.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/': // Output operands which are of equal or higher priority
                while (!stk.empty() && priority[stk.top()] >= priority[in[i]]) {
                    output.push_back(stk.top());
                    stk.pop();
                }
                stk.push(in[i]);
                break;
            default: // Output operand immediately
                output.push_back(in[i]);
                break;
        }

    }

    while (!stk.empty()) {
        output.push_back(stk.top());
        stk.pop();
    }

    cout << output << endl;
}

