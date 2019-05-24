//
//  bnode.h
//  Data
//
//  Created by PierreVon on 2019/5/14.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef bnode_h
#define bnode_h
#define rank 3

class bnode {
    int num;
    int value[rank-1];
    bnode* parent;
    bnode* ptr[rank];
    
public:
    int r=rank;
    
    bnode(){
        this->num = 0;
        this->parent = NULL;
        for(int i = 0; i<rank-1; i++)
            value[i] = -1;
        for(int i = 0; i<rank; i++)
            ptr[i] = NULL;
    }
    bnode(int val){
        this->num = 1;
        for(int i = 0; i<rank-1; i++)
            value[i] = -1;
        this->value[0] = val;
        this->parent = NULL;
        for(int i = 0; i<rank; i++)
            ptr[i] = NULL;
    }
    bnode(bnode* parent){
        this->num = 0;
        for(int i = 0; i<rank-1; i++)
            value[i] = -1;
        this->parent = parent;
        for(int i = 0; i<rank; i++)
            ptr[i] = NULL;
    }
    int getval(int i){
        return value[i];
    }
    void setval(int i,int val){
        value[i]=val;
        num++;
    }
    void setadjustval(int val){
        if(num<r-1){
            if(num==0)
                value[0]=val;
            else{
                int i = num-1;
                for(;i>=0;i--)
                    if(val<value[i]){
                        value[i+1] = value[i];
                        ptr[i+1] = ptr[i];
                    }
                value[i+1] = val;
            }
        }
        num++;
    }
    void setadjustnode(bnode* p){
        int i = num-1;
        for(;i>=0&&p->getval(0)<value[i];i--){
            value[i+1] = value[i];
            ptr[i+1] = ptr[i];
        }
        value[i+1] = p->getval(0);
        ptr[i+1] = p->getsubtree(0);
        ptr[i+2] = p->getsubtree(1);
        if(p->getsubtree(0)!=NULL){
            p->getsubtree(0)->setparent(this);
        }
        if(p->getsubtree(1)!=NULL){
            p->getsubtree(1)->setparent(this);
        }
        num++;
    }
    bnode* getsubtree(int i){
        return ptr[i];
    }
    void setsubtree(int i,bnode* p){
        ptr[i]=p;
    }
    int getnum(){
        return num;
    }
    bnode* getparent(){
        return parent;
    }
    void addnum(){
        num++;
    }
    void setnum(int num){
        this->num = num;
    }
    void setparent(bnode* p){
        this->parent = p;
    }
};

#endif /* bnode_h */
