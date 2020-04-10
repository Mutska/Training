#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int  main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, command, num;
    bool s, q, p;
    while(cin >> n) {
        s = q = p = true;
        stack<int> st;
        queue<int> qu;
        priority_queue<int> pr;
        while(n--) {
            cin >> command >> num;
            if(command == 1)
                st.push(num), qu.push(num), pr.push(num);
            if(command == 2) {
                if(st.empty() || (st.top() != num)) 
                    s = false;
                else
                    st.pop();
                if(qu.empty() || (qu.front() != num))
                    q = false;
                else
                    qu.pop();
                if(pr.empty() || (pr.top() != num))
                    p = false;
                else
                    pr.pop();
            }
        }
        if(!s && !q && !p)
            cout << "impossible\n";
        else if(s && !q && !p)
            cout << "stack\n";
        else if(!s && q && !p)
            cout  << "queue\n";
        else if(!s && !q && p)
            cout << "priority queue\n";
        else
            cout << "not sure\n"; 

    }

    return 0;
}