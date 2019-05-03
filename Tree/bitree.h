//
//  bitree.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/3.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef bitree_h
#define bitree_h

#include <iostream>
#include "node.h"
#include <stack>
#include <queue>

class bitree {
    node* root;
    
public:
    bitree(){
        root = new node;
    }
    bitree(int val){
        root = new node(val);
    }
    bitree(int* vals, int len){
        if(len>0){
            root = new node(*vals);
            node* p;
            std::queue<node*>q;
            q.push(root);
            vals++;
            int i = 1;
            bool left = true;
            while (i<len && !q.empty()) {
                p = q.front();
                if(p->getl()==NULL && left){
                    if(*vals != -1){
                        node* n = new node(*vals);
                        p->setl(n);
                        q.push(p->getl());
                    }
                }
                else if(p->getr()==NULL && !left){
                    if(*vals != -1){
                        node* n = new node(*vals);
                        p->setr(n);
                        q.push(p->getr());
                    }
                }
                left = !left;
                if(left)
                    q.pop();
                ++vals;
                ++i;
            }
        }
        
    }
    ~bitree(){
        std::queue<node*>q;
        node* p;
        if(root)
            q.push(root);
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if(p->getl() != NULL)
                q.push(p->getl());
            if(p->getr() != NULL)
                q.push(p->getr());
            delete p;
        }
        std::cout<<"ok";
    }
    void travel(){
        std::queue<node*>q;
        node* p;
        if(root)
            q.push(root);
        std::cout<<"level travel is: ";
        while (!q.empty()) {
            p = q.front();
            std::cout<<p->getval()<<" ";
            q.pop();
            if(p->getl() != NULL)
                q.push(p->getl());
            if(p->getr() != NULL)
                q.push(p->getr());
        }
        std::cout<<std::endl;
    }
    void ptravel(){
        // first print node value
        // go the left side, if node has right side, push into stack
        // when left is null, take top of stack and repeat above
        std::stack<node*>s;
        node*p = root;
        std::cout<<"privious travel is: ";
        while (p!=NULL || !s.empty()) {
            while (p) {
                if(p->getr()!=NULL)
                    s.push(p->getr());
                std::cout<<p->getval()<<" ";
                p = p->getl();
            }
            if(!s.empty()){
                p = s.top();
                s.pop();
            }
        }
        std::cout<<std::endl;
    }
    void mtravel(){
        std::stack<node*>s;
        node* p = root;
        std::cout<<"middle travel is: ";
        while (p!=NULL || !s.empty()) {
            while (p!=NULL){
                s.push(p);
                p = p->getl();
            }
            if(!s.empty()){
                p = s.top();
                std::cout<<p->getval()<<" ";
                s.pop();
                p = p->getr();
            }
        }
        std::cout<<std::endl;
    }
    void btravel(){
        std::stack<node*>s;
        node* p = root;
        node* t = root;
        std::cout<<"back travel is: ";
        bool right = false;
        while(p!=NULL || !s.empty()){
            right = false;
            while (p->getl()!=NULL) {
                s.push(p);
                p = p->getl();
            }
            s.push(p);
            while (!right) {
                if(!s.empty()){
                    p = s.top();
                    if(p->getr()==t){
                        t = p;
                        s.pop();
                        std::cout<<p->getval()<<" ";
                        if(s.empty()){
                            p = NULL;
                            right = !right;
                        }
                    }
                    else if(p->getr()==NULL){
                        t = p;
                        s.pop();
                        std::cout<<p->getval()<<" ";
                    }
                    else{
                        p = p->getr();
                        right = !right;
                    }
                }
            }
        }
        std::cout<<std::endl;
    }
};

#endif /* bitree_h */
