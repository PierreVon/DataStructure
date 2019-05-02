//
//  stack.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/2.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <iostream>
#include "node.h"

class stack {
    node *head;
    node *end;
    
public:
    stack(){
        head = new node;
        end = head;
    }
    stack(int val){
        head = new node(val);
        end = head;
    }
    ~stack(){
        end = head;
        while (end != NULL) {
            head = end->getptr();
            delete end;
            end = head;
        }
        std::cout<<"ok"<<std::endl;
    }
    void push(int val){
        node* n = new node(val);
        end->setptr(n);
        end = n;
    }
    void pop(){
        node* p = head;
        while (p->getptr() != end) {
            p = p->getptr();
        }
        p->setptr(NULL);
        std::cout<<"delete:"<<end->getval()<<std::endl;
        delete end;
        end = p;
    }
    void all(){
        node* p = head;
        while (p != NULL) {
            std::cout<<p->getval()<<" ";
            p = p->getptr();
        }
        std::cout<<std::endl;
    }
};

#endif /* stack_h */
