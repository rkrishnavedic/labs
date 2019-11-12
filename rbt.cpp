//
//  rbt.cpp
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
    node* p;
    char c;
};

node* newNode(int k){
    node* s=new node;
    s->k=k;
    s->l=NULL;
    s->r=NULL;
    s->p=NULL;
    s->c='r';
    return s;
}

void rightrotate(node* n,node* pt){
    node* pl=pt->l;
    pt->l=pl->r;
    if(pt->l!=NULL){
        pt->l->p=pt;
    }
    pl->p=pt->p;
    if(pt->p==NULL){
        n=pl;
    }
    else {
        if(pt->p->l==pt){pt->p->l=pl;}
        else{
            pt->p->r=pl;
        }
    }
    pl->r=pt;
    pt->p=pl;

}

void leftrotate(node* n,node* pt){

    node* pr=pt->r;
       pt->r=pr->l;
       if(pt->r!=NULL){
           pt->r->p=pt;
       }
       pr->p=pt->p;
       if(pt->p==NULL){
           n=pr;
       }
       else {
           if(pt->p->r==pt){pt->p->r=pr;}
           else{
               pt->p->l=pr;
           }
       }
       pr->l=pt;
       pt->p=pr;

}

node* BSTinsert(node* n, node* z){
    if(n==NULL){return z;}
    if(z->k<n->k){
        n->l=BSTinsert(n->l, z);
        n->l->p=n;
    }
    if(z->k>n->k){
        n->r=BSTinsert(n->r, z);
        n->r->p=n;
    }
    return n;
}

void preOrder(node* root){
    if(root!=NULL){
        cout<<root->k<<root->c<<" ";
        preOrder(root->l);
        preOrder(root->r);
    }
}

void fix(node* n, node* z){
    node* pz=NULL;
    node* gpz=NULL;
    
    while(z!=n && z->c!='b' && z->p->c=='r'){
        pz=z->p;
        gpz=pz->p;
        
        if(pz==gpz->l){
          node* uz=NULL;
            uz=gpz->r;
            if(uz!=NULL && uz->c=='r'){
                gpz->c='r';
                uz->c='b';
                pz->c='b';
                z=gpz;
            }
            else{
                if(z==pz->r){
                    leftrotate(n,pz);
                    z=pz;
                    pz=z->p;
                    
                }
                rightrotate(n, gpz);
                swap(pz->c, gpz->c);
                z=pz;
            }
        }
        else{
            node* uz=NULL;
            uz=gpz->l;
            if(uz!=NULL && uz->c=='r'){
                gpz->c='r';
                uz->c='b';
                pz->c='b';
                z=gpz;
            }
            else{
                if(z==pz->l){
                    rightrotate(n, pz);
                    z=pz;
                    pz=z->p;
                }
                leftrotate(n, gpz);
                swap(pz->c, gpz->c);
                z=pz;
            }
        }
    }
    n->c='b';
}

node* addNode(node* n, int k){
    node* z=NULL;
    z=newNode(k);
    n=BSTinsert(n, z);
    fix(n,z);
    return n;
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
