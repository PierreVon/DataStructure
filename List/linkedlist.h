//
//  linkedlist.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include "node.h"

class linkedlist {
    node *head;
    node *end;
    
public:
    linkedlist(){
        head = new node;
        end = head;
    }
    linkedlist(int val){
        head = new node(val);
        end = head;
    }
    ~linkedlist(){
        end = head;
        while (end != NULL) {
            head = end->getptr();
            delete end;
            end = head;
        }
        std::cout<<"ok"<<std::endl;
    }
    void insert(int val){
        node* n = new node(val);
        n->setptr(head);
        head = n;
    }
    void append(int val){
        node* n = new node(val);
        end->setptr(n);
        end = n;
    }
    void del_f(){
        node* p = head;
        head = head->getptr();
        std::cout<<"delete:"<<p->getval()<<std::endl;
        delete p;
    }
    void del(){
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


#endif /* linkedlist_h */
