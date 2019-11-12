//
//  bfs&dfs.cpp
//  Labs
//
//  Created by Rahul Krishna on 11/11/19.
//  Copyright © 2019 Rahul Krishna. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<int> adj[], int n, int a, int b){
    if(a>=n || b>=n){
        cout<<"Error! please type valid nodes...\n";
        return;
    }
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void pbfs(vector<int> adj[], int n, int a, int b,bool s){
    int arr[n], prev[n],k;
    for(int i=0;i<n;i++){ arr[i]=0;}
    queue<int> q;
    q.push(a);
    arr[a]=1;
    if(!s) cout<<"BFS is: ";
    while(!q.empty()){
        k = q.front();
        if(!s) cout<<k<<" ";
        q.pop();
        for(int i=0;i<adj[k].size();i++){
            if(arr[adj[k].at(i)]==0){
                q.push(adj[k].at(i));
                arr[adj[k].at(i)]=1;
                prev[adj[k].at(i)]=k;
            }
        }
    }
    if(s){
        vector<int> j;
        k=b;j.push_back(k);
        cout<<"Shortest path is : "<<a<<" ";
        while(prev[k]!=a){
            j.push_back(prev[k]);
            k=prev[k];
        }
        for (int i=0; i<j.size(); i++) {
            cout<<j.back()<<" ";
            j.pop_back();
        }
        cout<<b<<endl;
    }
}

void pdfs(vector<int> adj[], int n, int a){
    int arr[n], k,t=0;
    for(int i=0;i<n;i++){ arr[i]=0;}
    stack<int> q;
    q.push(a);
    arr[a]=1;
    
    k=a;
    cout<<"DFS is: ";
    cout<<a<<" ";
    while(!q.empty()){
        t=0;
        k=q.top();
        for(int i=0;i<adj[k].size();i++){
        if(arr[adj[k].at(i)]==0){
            cout<<adj[k].at(i)<<" ";t=1;
            q.push(adj[k].at(i));
            arr[adj[k].at(i)]=1;break;}}
        if(t!=1){
            q.pop();
        }
    }
}


int main(int argc, const char * argv[]) {
    cout<<"OM\nNo. of node : ";
    int n,a,b;
    cin>>n;
    vector<int> adj[n];
    //Enter e a b to add edge a,b
    //b a to print bfs from a
    //d a to print dfs from a
    //s a b to print shortest path from a to b
    //else 0 to discontinue
    char c='e';
    while(c!='0'){
        cout<<"Entry: ";
        cin>>c;
        if(c=='b'){cin>>a; pbfs(adj, n,a, 0,false);}
        if(c=='e'){cin>>a>>b;addEdge(adj, n, a, b);}
        if(c=='s'){cin>>a>>b;pbfs(adj,n,a,b,true);}
        if(c=='d'){cin>>a; pdfs(adj,n,a);}
        
    }
    return 0;
}
