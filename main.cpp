#include<iostream>
#include "quetype.cpp"

using namespace std;

struct state{
    int val, count;
    state(int v=0, int c=0){
        val =v;
        count = c;
    }
};

int main(){
    int n, final;
    cin>>n;
    int coins[n];
    for(int i=0; i<n; i++) cin>>coins[i]; cin>>final;
    bool visited[final+1] = {false};
    QueType<state> q;
    q.Enqueue(state(0,0));
    visited[0] = true;
    while(!q.IsEmpty()){
        state cur;
        q.Dequeue(cur);
        if(cur.val == final){
            cout<<cur.count<<endl; return 0;
        }
        for(int i=0; i<n; i++){
            int next = cur.val + coins[i];
            if(next <= final && !visited[next]){
                visited[next] = true;
                q.Enqueue(state(next, cur.count+1));
            }
        }
    }
    return 0;
}
