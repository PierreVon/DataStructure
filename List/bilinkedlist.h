//
//  bilinkedlist.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/2.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef bilinkedlist_h
#define bilinkedlist_h

#include <iostream>
#include "binode.h"


class biLinkedlist{
    binode *head;
    binode *end;
    
public:
    
    biLinkedlist(){
        head = new binode;
        end = head;
    }
    biLinkedlist(int val){
        head = new binode(val);
        end = head;
    }
    ~biLinkedlist(){
        end = head;
        while (end != NULL) {
            head = end->getnptr();
            delete end;
            end = head;
        }
        std::cout<<"ok"<<std::endl;
    }
    void insert(int val){
        binode* n = new binode(val);
        n->setnptr(head);
        head->setpptr(n);
        head = n;
    }
    void append(int val){
        binode* n = new binode(val);
        end->setnptr(n);
        n->setpptr(end);
        end = n;
    }
    void del_f(){
        binode* p = head;
        head->setnptr(head->getnptr());
        head->setpptr(NULL);
        std::cout<<"delete:"<<p->getval()<<std::endl;
        delete p;
    }
    void del(){
        binode* p = end;
        end = end->getpptr();
        end->setnptr(NULL);
        std::cout<<"delete:"<<p->getval()<<std::endl;
        delete p;
    }
    int find(int val){
        int i = 1;
        binode* p = head;
        while (p != NULL) {
            if(val == p->getval())
                return i;
            i++;
            p = p->getpptr();
        }
        return -1;
    }
    void all(){
        binode* p = head;
        while (p != NULL) {
            std::cout<<p->getval()<<" ";
            p = p->getnptr();
        }
        std::cout<<std::endl;
    }
};


#endif /* bilinkedlist_h */
