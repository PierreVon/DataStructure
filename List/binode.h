//
//  binode.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/2.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef binode_h
#define binode_h

class binode {
    int val;
    binode* prior;
    binode* next;
    
public:
    
    binode(){
        this->next = NULL;
        this->prior = NULL;
    };
    binode(int val){
        this->val = val;
        this->next = NULL;
        this->prior = NULL;
    };
    int getval(){
        return val;
    };
    binode* getnptr(){
        return next;
    };
    binode* getpptr(){
        return prior;
    };
    void setval(int val){
        this->val = val;
    }
    void setnptr(binode* ptr){
        this->next = ptr;
    }
    void setpptr(binode* ptr){
        this->prior = ptr;
    }
};

#endif /* binode_h */
