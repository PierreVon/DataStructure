//
//  vnode.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef vnode_h
#define vnode_h

#include <iostream>
#include "node.h"

class vnode {
    int val;
    node* firstnode;
    
public:
    vnode(){
        this->firstnode = NULL;
    }
    vnode(int val){
        this->val = val;
        this->firstnode = NULL;
    }
    int getval(){
        return val;
    };
    node* getfirstnode(){
        return firstnode;
    };
    void setval(int val){
        this->val = val;
    }
    void setfirstnode(node* firstnode){
        this->firstnode = firstnode;
    }
    void insert(node* p){
        p->setptr(firstnode->getptr());
        firstnode->setptr(p);
    }
};

#endif /* vnode_h */
