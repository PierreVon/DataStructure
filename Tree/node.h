//
//  node.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/3.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef node_h
#define node_h

class node {
    int val;
    node* l;
    node* r;
    
public:
    node(){
        this->l = NULL;
        this->r = NULL;
    }
    node(int val){
        this->val = val;
        this->l = NULL;
        this->r = NULL;
    }
    node* getl(){
        return l;
    }
    node* getr(){
        return r;
    }
    int getval(){
        return val;
    }
    void setval(int val){
        this->val = val;
    }
    void setl(node* l){
        this->l = l;
    }
    void setr(node* r){
        this->r = r;
    }
};

#endif /* node_h */
