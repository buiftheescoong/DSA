#include<bits/stdc++.h>

using namespace std;
struct Queue {
    stack<int> st1, st2;
    void dequeue() {
        if(st1.empty()){
            return;
        }
        else{
            st1.pop();
        }
    }
    void enqueue(int x) {
        while(!st1.empty()){
            int temp = st1.top();
            st1.pop();
            st2.push(temp);
        }
        st1.push(x);
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

    }
    void print(){
        while(!st1.empty()) {
            cout << st1.top() << " ";
            st1.pop();
        }
    }
};
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.enqueue(5);
    q.print();
    return 0;

}
