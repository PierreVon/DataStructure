//
//  biSortTree.h
//  Data
//
//  Created by PierreVon on 2019/5/23.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef biSortTree_h
#define biSortTree_h
#include "../../Tree/node.h"
#include <queue>

class biSortTree{
    node* root;
    int num;
public:
    biSortTree(){
        root=NULL;
    }
    biSortTree(int* a, int len){
        num=0;
        if(len>0){
            for(int i=0;i<len;i++)
                insert(a[i]);
        }
    }
    ~biSortTree(){
        if(root!=NULL){
            std::queue<node*>q;
            q.push(root);
            while (!q.empty()) {
                node* p = q.front();
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
            root = new node(val);
            num++;
        }
        else{
            node* p = new node(val);
            node* tmp = root;
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
    
    void del(int val){
        if(num<=0)
            return;
        else{
            node* pre = root;
            node* tmp = root;
            char direction = ' ';
            while (true) {
                if(tmp->getval()>val){
                    if(tmp->getl()!=NULL){
                        pre = tmp;
                        tmp = tmp->getl();
                        direction = 'l';
                    }
                    else{
                        return;
                    }
                    
                }
                else if(tmp->getval()<val){
                    if(tmp->getr()!=NULL){
                        pre = tmp;
                        tmp = tmp->getl();
                        direction = 'r';
                    }
                    else{
                        return;
                    }
                }
                else
                    break;
            }
            if(tmp->getl()==NULL&&tmp->getr()==NULL){
                if(direction=='l'){
                    pre->setl(NULL);
                    delete tmp;
                }
                if(direction=='r'){
                    pre->setr(NULL);
                    delete tmp;
                }
            }
            else if(tmp->getl()!=NULL&&tmp->getr()==NULL){
                if(direction=='l'){
                    pre->setl(tmp->getl());
                    delete tmp;
                }
                if(direction=='r'){
                    pre->setr(tmp->getl());
                    delete tmp;
                }
            }
            else if(tmp->getl()==NULL&&tmp->getr()!=NULL){
                if(direction=='l'){
                    pre->setl(tmp->getr());
                    delete tmp;
                }
                if(direction=='r'){
                    pre->setr(tmp->getr());
                    delete tmp;
                }
            }
            else{
                if(direction=='l'){
                    // method 1, left: put tmp bigger side into lower side's end of bigger side, right on the contrary.
                    node* p = tmp->getl();
                    while (p->getr()!=NULL)
                        p=p->getr();
                    p->setr(tmp->getr());
                    pre->setl(tmp->getl());
                    delete tmp;
                    
                }
                if(direction=='r'){
                    // method 2, less robust, right: put tmp bigger side's end of lower side p as tmp and delete p, left on the contrary.
                    node* p = tmp->getr();
                    if(p->getl()==NULL){
                        pre->setr(p);
                        delete tmp;
                    }
                    else{
                        node*prep = p;
                        while (p->getl()!=NULL){
                            prep = p;
                            p=p->getl();
                        }
                        prep->setl(p->getr());
                        tmp->setval(p->getval());
                        delete p;
                    }
                }
            }
            num--;
        }
    }
    
    node* find(int val){
        if(num<=0)
            return NULL;
        else{
            node* tmp = root;
            while (true) {
                if(tmp->getval()>val){
                    if(tmp->getl()!=NULL)
                        tmp = tmp->getl();
                    else{
                        return NULL;
                    }
                    
                }
                else if(tmp->getval()<val){
                    if(tmp->getr()!=NULL)
                        tmp = tmp->getr();
                    else{
                        return NULL;
                    }
                }
                else
                    return tmp;
            }
        }
    }
    
    void travel(){
        if(root!=NULL){
            std::queue<node*>q;
            q.push(root);
            while (!q.empty()) {
                node* p = q.front();
                q.pop();
                if(p->getl()!=NULL)
                    q.push(p->getl());
                if(p->getr()!=NULL)
                    q.push(p->getr());
                std::cout<<p->getval()<<" ";
            }
        }
    }
};


#endif /* biSortTree_h */
