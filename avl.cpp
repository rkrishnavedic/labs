//
//  avl.cpp
//  Labs
//
//  Created by Rahul Krishna on 12/11/19.
//  Copyright © 2019 Rahul Krishna. All rights reserved.
//

#include "total.h"

using namespace std;

struct node{
    int k;
    node* l;
    node* r;
    int h;
};

int height(node* t){
    if(t==NULL) return 0;
    return t->h;
}

int maxu(int a,int b){
    if(a>b) return a;
    return b;
}

node* newNode(int k){
    node* s=new node;
    s->k=k;
    s->l=NULL;
    s->r=NULL;
    s->h=1;
    return s;
}

node* rightrotate(node* pi){
    node* t1=pi -> l;
    node* t2=t1 -> r;
    t1->r=pi;
    pi->l=t2;
    
    pi->h=maxu(height(pi->l), height(pi->r)) +1;
    t1->h=maxu(height(t1->l), height(t1->r)) +1;
    
    return t1;
}

node* leftrotate(node* pi){
    node* t2=pi -> r;
    node* t1=t2 -> l;
    
    t2->l=pi;
    pi->r=t1;
    
    pi->h=maxu(height(pi->l), height(pi->r)) +1;
    t2->h=maxu(height(t2->l), height(t2->r)) +1;
    
    return t2;
}

int blns(node* s){
    if(s==NULL) return 0;
    return height(s->l)-height(s->r);
}

node* addNode(node* n, int k){
    
    if(n==NULL) return newNode(k);
    if(k<n->k){
        n->l=addNode(n->l, k);
    }
    else {if(k>n->k){n->r=addNode(n->r, k);}
        else{return n;}
        }
    n->h=maxu(height(n->l), height(n->r))+1;
    int b=blns(n);
    
    if(b>1){
        if(k < n->l->k){
            return rightrotate(n);
        }
        if(k > n->l->k){
            n->r=leftrotate(n->r);
            return rightrotate(n);
        }
    }
    if(b<-1){
        if(k > n->r->k){
            return leftrotate(n);
        }
        if(k < n->r->k){
            n->r=rightrotate(n->r);
            return leftrotate(n);
        }
    }
    return n;
}

void preOrder(node* root){
    if(root!=NULL){
        cout<<root->k<<" ";
        preOrder(root->l);
        preOrder(root->r);
    }
}

int main(){
    cout<<"Om\n";
    node* n=NULL;
    cout<<"Enter i to inset, p to preorder, 0 to exit\n";
    int x;
    char c='1';
    while(c!='0'){
        cin>>c;
        if(c!='i' && c!='p' && c!='0'){
            cout<<"Error! Press a valid key\n";
        }
        if(c=='p'){
            cout<<"preorder: ";
            preOrder(n);cout<<endl;
        }
        if(c=='i'){
            cin>>x;
            n=addNode(n, x);
        }
    }
    
    return 0;
}
