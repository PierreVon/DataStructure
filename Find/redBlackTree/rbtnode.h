//
//  rbtnode.h
//  Data
//
//  Created by PierreVon on 2019/5/29.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef rbtnode_h
#define rbtnode_h

class rbtnode {
    int val;
    // r=1,b=0
    int rb;
    rbtnode* l;
    rbtnode* r;
    rbtnode* parent;
    
public:
    rbtnode(){
        this->l = NULL;
        this->r = NULL;
        this->parent = NULL;
        this->rb = 1;
    }
    rbtnode(int val){
        this->val = val;
        this->l = NULL;
        this->r = NULL;
        this->parent = NULL;
        this->rb = 1;
    }
    rbtnode* getl(){
        return l;
    }
    rbtnode* getr(){
        return r;
    }
    rbtnode* getparent(){
        return parent;
    }
    int getval(){
        return val;
    }
    int getrb(){
        return rb;
    }
    void setval(int val){
        this->val = val;
    }
    void setrb(int rb){
        this->rb = rb;
    }
    void setl(rbtnode* l){
        this->l = l;
    }
    void setr(rbtnode* r){
        this->r = r;
    }
    void setparent(rbtnode* parent){
        this->parent = parent;
    }
    
    
};

#endif /* rbtnode_h */
