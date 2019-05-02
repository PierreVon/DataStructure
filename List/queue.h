//
//  queue.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/2.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <iostream>
#include "node.h"

class queue {
    node *head;
    node *end;
    
public:
    queue(){
        head = new node;
        end = head;
    }
    queue(int val){
        head = new node(val);
        end = head;
    }
    ~queue(){
        end = head;
        while (end != NULL) {
            head = end->getptr();
            delete end;
            end = head;
        }
        std::cout<<"ok"<<std::endl;
    }
    void enqueue(int val){
        node* n = new node(val);
        end->setptr(n);
        end = n;
    }
    void dequeue(){
        node* p = head;
        head = head->getptr();
        std::cout<<"delete:"<<p->getval()<<std::endl;
        delete p;
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


#endif /* queue_h */
