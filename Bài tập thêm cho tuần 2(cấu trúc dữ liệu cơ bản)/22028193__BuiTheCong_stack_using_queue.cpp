#include<bits/stdc++.h>

using namespace std;
struct Stack {
    queue<int> q1, q2;
    void pop() {
        if(q1.empty()) {
            return;
        }
        else{
            q1.pop();
        }
    }
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void print() {
        vector<int> temp;
        while(!q1.empty()) {
            temp.push_back(q1.front());
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        reverse(temp.begin(), temp.end());
        for(int x : temp) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.push(5);
    st.print();
    st.push(6);
    st.print();
    return 0;
}
