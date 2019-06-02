//
//  rbTree.h
//  Data
//
//  Created by PierreVon on 2019/5/29.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef rbTree_h
#define rbTree_h
#include "rbtnode.h"
#include <queue>

class rbTree {
    rbtnode* root;
    int num = 0;
    
public:
    rbTree(){
        root = NULL;
    }
    rbTree(int* a, int len){
        root = NULL;
        for(int i=0;i<len;i++){
            rbtnode* p = insert(a[i]);
            adjust(p);
            travel2();
            travel();
        }
    }
    ~rbTree(){
        if(root){
            std::queue<rbtnode*>q;
            q.push(root);
            while (!q.empty()) {
                rbtnode* p = q.front();
                q.pop();
                if(p->getl())
                    q.push(p->getl());
                if(p->getr())
                    q.push(p->getr());
                delete p;
            }
        }
    }
    rbtnode* insert(int val){
        if(root==NULL){
            root = new rbtnode(val);
            root->setrb(0);
            num++;
            return root;
        }
        else{
            rbtnode* p = new rbtnode(val);
            rbtnode* tmp = root;
            while (true) {
                if(tmp->getval()>p->getval()){
                    if(tmp->getl()!=NULL)
                        tmp = tmp->getl();
                    else{
                        tmp->setl(p);
                        p->setparent(tmp);
                        num++;
                        return p;
                    }
                    
                }
                else if(tmp->getval()<p->getval()){
                    if(tmp->getr()!=NULL)
                        tmp = tmp->getr();
                    else{
                        tmp->setr(p);
                        p->setparent(tmp);
                        num++;
                        return p;
                    }
                }
                else
                    return NULL;
            }
        }
    }
    void adjust(rbtnode* p){
        if(p->getparent()==NULL)
            return;
        else if(p->getparent()->getrb()==0)
            return;
        else{
            rbtnode* grandpa = p->getparent()->getparent();
            rbtnode* pa = p->getparent();
            rbtnode* sib;
            if(pa->getrb()==1){
                if(grandpa->getr()==pa)
                    sib=grandpa->getl();
                else
                    sib=grandpa->getr();
                if(sib!=NULL&&sib->getrb()==1){
                    pa->setrb(0);
                    sib->setrb(0);
                    grandpa->setrb(1);
                    if(grandpa->getparent()==NULL)
                        grandpa->setrb(0);
                    adjust(grandpa);
                }
                else{
                    if(grandpa->getl()==pa&&pa->getl()==p){
                        pa->setrb(0);
                        grandpa->setrb(1);
                        r_rotate(grandpa);
                    }
                    else if(grandpa->getr()==pa&&pa->getr()==p){
                        pa->setrb(0);
                        grandpa->setrb(1);
                        l_rotate(grandpa);
                    }
                    else if(grandpa->getl()==pa&&pa->getr()==p){
                        l_rotate(pa);
                    }
                    else{
                        r_rotate(pa);
                    }
                    if(pa->getrb()==1)
                        adjust(pa);
//                    if(p == pa->getl()){
//                        pa->setrb(0);
//                        grandpa->setrb(1);
//                        r_rotate(grandpa);
//                        if(grandpa->getr()!=NULL&&grandpa->getr()->getrb()==1)
//                            adjust(grandpa->getr());
//                        if(grandpa->getl()!=NULL&&grandpa->getl()->getrb()==1)
//                            adjust(grandpa->getl());
//
//                    }
//                    else{
//                        l_rotate(pa);
//                        adjust(pa);
//                    }
                }
            }
        }
    }
    void l_rotate(rbtnode* p){
        rbtnode* parent = p->getparent();
        rbtnode* next = p->getr();
        p->setr(next->getl());
        next->setl(p);
        p->setparent(next);
        next->setparent(parent);
        if(parent==NULL){
            root=next;
            next->setparent(NULL);
        }
        else if(parent->getl()==p)
            parent->setl(next);
        else
            parent->setr(next);
    }
    
    void r_rotate(rbtnode* p){
        rbtnode* parent = p->getparent();
        rbtnode* next = p->getl();
        p->setl(next->getr());
        p->setparent(next);
        next->setparent(parent);
        next->setr(p);
        if(parent==NULL){
            root=next;
            next->setparent(NULL);
        }      
        else if(parent->getl()==p)
            parent->setl(next);
        else
            parent->setr(next);
    }
    
    void travel(){
        if(root){
            std::queue<rbtnode*>q;
            q.push(root);
            while (!q.empty()) {
                rbtnode* p = q.front();
                q.pop();
                if(p->getl()!=NULL)
                    q.push(p->getl());
                if(p->getr()!=NULL)
                    q.push(p->getr());
                std::cout<<p->getrb()<<" ";
            }
        }
        std::cout<<std::endl;
    }
    void travel2(){
        if(root){
            std::queue<rbtnode*>q;
            q.push(root);
            while (!q.empty()) {
                rbtnode* p = q.front();
                q.pop();
                if(p->getl()!=NULL)
                    q.push(p->getl());
                if(p->getr()!=NULL)
                    q.push(p->getr());
                std::cout<<p->getval()<<" ";
            }
        }
        std::cout<<std::endl;
    }
};

#endif /* rbTree_h */
