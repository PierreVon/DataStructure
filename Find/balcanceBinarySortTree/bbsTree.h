//
//  bbsTree.h
//  Data
//
//  Created by PierreVon on 2019/5/25.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef bbsTree_h
#define bbsTree_h
#include "bbstnode.h"
#include <queue>

class bbsTree {
    bbstnode* root;
    bbstnode* parent_l;
    bbstnode* parent_r;
    bbstnode* unbalancenode;
    int num;
    
public:
    bbsTree(int* a, int len){
        num=0;
        for(int i=0;i<len;i++){
            insert(a[i]);
            travel2();
            std::cout<<std::endl;
            parent_l = NULL;
            parent_r = NULL;
            unbalancenode = NULL;
            setallbalanceval(root);
            while (unbalancenode!=NULL) {
                travel();
                std::cout<<std::endl;
                if(unbalancenode!=NULL){
                    // left balance
                    if(unbalancenode->getbalanceval()==2){
                        // right rotate
                        if(unbalancenode->getl()->getbalanceval()==1){
                            r_rotate(unbalancenode);
                        }
                        // left rotate
                        else if(unbalancenode->getl()->getbalanceval()==-1){
                            parent_l=unbalancenode;
                            l_rotate(unbalancenode->getl());
                        }
                    }
                    // right balance
                    if(unbalancenode->getbalanceval()==-2){
                        // left rotate
                        if(unbalancenode->getr()->getbalanceval()==-1){
                            l_rotate(unbalancenode);
                        }
                        // right rotate
                        else if(unbalancenode->getr()->getbalanceval()==1){
                            parent_r=unbalancenode;
                            r_rotate(unbalancenode->getr());
                        }
                    }
                    parent_l = NULL;
                    parent_r = NULL;
                    unbalancenode = NULL;
                    setallbalanceval(root);
                }
            }
        }
    }
    ~bbsTree(){
        if(root!=NULL){
            std::queue<bbstnode*>q;
            q.push(root);
            while (!q.empty()) {
                bbstnode* p = q.front();
                q.pop();
                if(p->getl()!=NULL)
                    q.push(p->getl());
                if(p->getr()!=NULL)
                    q.push(p->getr());
                delete p;
            }
            std::cout<<"clear";
        }
    }
    
    void insert(int val){
        if(num == 0){
            root = new bbstnode(val);
            num++;
        }
        else{
            bbstnode* p = new bbstnode(val);
            bbstnode* tmp = root;
            while (true) {
                if(tmp->getval()>p->getval()){
                    if(tmp->getl()!=NULL)
                        tmp = tmp->getl();
                    else{
                        tmp->setl(p);
                        num++;
                        return;
                    }
                    
                }
                else if(tmp->getval()<p->getval()){
                    if(tmp->getr()!=NULL)
                        tmp = tmp->getr();
                    else{
                        tmp->setr(p);
                        num++;
                        return;
                    }
                }
                else
                    return;
            }
        }
    }
    
    // find the minimum subtree then operate the following operations
    void l_rotate(bbstnode* p){
        bbstnode* next = p->getr();
        p->setr(next->getl());
        next->setl(p);
        if(parent_r==NULL&&parent_l==NULL)
            root=next;
        else if(parent_r!=NULL&&parent_l==NULL)
            parent_r->setr(next);
        else
            parent_l->setl(next);
    }
    
    void r_rotate(bbstnode* p){
        bbstnode* next = p->getl();
        p->setl(next->getr());
        next->setr(p);
        if(parent_r==NULL&&parent_l==NULL)
            root=next;
        else if(parent_r!=NULL&&parent_l==NULL)
            parent_r->setr(next);
        else
            parent_l->setl(next);
    }
    
    void travel(){
        if(root!=NULL){
            std::queue<bbstnode*>q;
            q.push(root);
            while (!q.empty()) {
                bbstnode* p = q.front();
                q.pop();
                if(p->getl()!=NULL)
                    q.push(p->getl());
                if(p->getr()!=NULL)
                    q.push(p->getr());
                std::cout<<p->getbalanceval()<<" ";
            }
        }
        std::cout<<std::endl;
    }
    
    void travel2(){
        if(root!=NULL){
            std::queue<bbstnode*>q;
            q.push(root);
            while (!q.empty()) {
                bbstnode* p = q.front();
                q.pop();
                if(p->getl()!=NULL)
                    q.push(p->getl());
                if(p->getr()!=NULL)
                    q.push(p->getr());
                std::cout<<p->getval()<<" ";
            }
        }
    }
    
    int setallbalanceval(bbstnode* p){
        if(p!=NULL){
            p->setbalanceval(setallbalanceval(p->getl()) - setallbalanceval(p->getr()));
            if((p->getbalanceval()==2 || p->getbalanceval()==-2) && unbalancenode==NULL)
                unbalancenode=p;
            if(p->getl()==unbalancenode && unbalancenode!=NULL)
                parent_l = p;
            else if(p->getr()==unbalancenode && unbalancenode!=NULL)
                parent_r = p;
        }
            
        
        if(p==NULL)
            return 0;
        else if (p->getl()==NULL&&p->getr()==NULL)
            return 1;
        else if(p->getl()!=NULL&&p->getr()==NULL)
            return setallbalanceval(p->getl()) + 1;
        else if(p->getl()!=NULL&&p->getr()==NULL)
            return setallbalanceval(p->getl()) + 1;
        else{
            return setallbalanceval(p->getl())>setallbalanceval(p->getr())? setallbalanceval(p->getl())+1: setallbalanceval(p->getr())+1;
        }
    }
};

#endif /* bbsTree_h */
