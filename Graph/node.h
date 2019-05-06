//
//  node.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef node_h
#define node_h

class node {
    int val;
    int weight;
    node *next;
    
public:
    
    node(){
        this->next = NULL;
    };
    node(int val){
        this->val = val;
        this->next = NULL;
    };
    int getval(){
        return val;
    };
    node* getptr(){
        return next;
    };
    int getweight(){
        return weight;
    };
    void setval(int val){
        this->val = val;
    }
    void setptr(node* ptr){
        this->next = ptr;
    }
    void setweight(int weight){
        this->weight = weight;
    }
};

#endif /* node_h */
