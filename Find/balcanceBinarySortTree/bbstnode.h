//
//  bbstnode.h
//  Data
//
//  Created by PierreVon on 2019/5/25.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef bbstnode_h
#define bbstnode_h

class bbstnode {
    int val;
    int balanceval;
    bbstnode* l;
    bbstnode* r;
    
public:
    bbstnode(){
        this->l = NULL;
        this->r = NULL;
    }
    bbstnode(int val){
        this->val = val;
        this->l = NULL;
        this->r = NULL;
    }
    bbstnode* getl(){
        return l;
    }
    bbstnode* getr(){
        return r;
    }
    int getval(){
        return val;
    }
    int getbalanceval(){
        return balanceval;
    }
    void setval(int val){
        this->val = val;
    }
    void setbalanceval(int balanceval){
        this->balanceval = balanceval;
    }
    void setl(bbstnode* l){
        this->l = l;
    }
    void setr(bbstnode* r){
        this->r = r;
    }

    
};



#endif /* bbstnode_h */
