//
//  bst check.cpp
//  Labs
//
//  Created by Rahul Krishna on 16/11/19.
//  Copyright © 2019 Rahul Krishna. All rights reserved.
//

/*Please use bits/stdc++.h as library if your IDE supports else make file total.h and include all libraries manually.*/
#include "total.h"
//#include <bits/stdc++.h>

using namespace std;

struct node{
    int d;
    node* l;
    node* r;
};
vector<int> in;

void inOrder(node* n){
    if(n==NULL){return;}
    inOrder(n->l);
    in.push_back(n->d);
    inOrder(n->r);
}

node* nodify(int d){
    node* x=new node;
    x->d=d;
    x->l=NULL;
    x->r=NULL;
    return x;
}

node* searchN(node* n,int k){
    node *t;
    if(n==NULL){return NULL;}
    if(n->d==k){return n;}
    t=searchN(n->l, k);
    if(t!=NULL){return t;}
    t=searchN(n->r, k);
    if(t!=NULL){return t;}
    return NULL;
}
void levelOrder(node* n){
    if(n==NULL) return;
    queue<int> q;
    node* t;
    cout<<"Level Traversal:";
    q.push(n->d);
    int i;
    while(!q.empty()){
        i=q.front();
        cout<<i<<" ";
        q.pop();
        t=searchN(n, i);
        if(t->l!=NULL){
            q.push(t->l->d);
        }
        if(t->r!=NULL){
            q.push(t->r->d);
        }
    }
    cout<<endl;
}

node* adde(node* n,int k){
    node* x,*t;
    x=nodify(k);
    t=searchN(n, k);
    if(t!=NULL){
        t=x;return n;
    }
    else{
        if(n==NULL){return nodify(k);}
    }
    return n;
}

void pri(node * n){
    if(n==NULL) return;
    cout<<n->d<<" ";
    pri(n->l);
    pri(n->r);
}

void cbst(node* root){
    inOrder(root);
    for(int i=1;i<in.size();i++){
        if(in.at(i-1)>=in.at(i)){cout<<"not bst\n";return;}
    }
    cout<<"yes bst\n";
}

int main(){
    cout<<"Om\n";
    int a,b,c;
    node* n=NULL,*t=NULL;
    char ct='1';
    while(ct!='0'){
        cout<<"p/+/0: ";
        cin>>ct;
        if(ct=='+'){
        cin>>a>>b>>c;
        n=adde(n, b);
        t=searchN(n, b);
            if(t!=NULL){
        if(a!=-1){
            t->l=nodify(a);
        }
        if(c!=-1){
            t->r=nodify(c);
        }}
            else{cout<<"No node found with key \""<<b<<"\"\n";}}
        if(ct=='p'){cout<<"Inorder: ";pri(n);cout<<endl;levelOrder(n);}
    }
    
    cbst(n);
    return 0;
}
