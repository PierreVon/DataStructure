//
//  graph.h
//  DataStruct
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <iostream>
#include "node.h"
#include "vnode.h"
#define maxnode 20

class graph {
    int kind; // 0 undigraph 1 digraph
    vnode* v[maxnode];
    int nodenum, arcnum;
    
public:
    graph(){
        this->kind = 0;
        this->nodenum = this->arcnum = 0;
    }
    graph(int* vec, int a[][4], int vnum, int kind = 0){
        this->kind = kind;
        this->nodenum = vnum;
        if(vnum <= 0 || vnum > maxnode){
            this->nodenum = this->arcnum = 0;
        }
        else if(vnum == 1){
            v[0] = new vnode(*vec);
            this->arcnum = 0;
        }
        else{
            for(int i=0; i<vnum;i++)
                v[i] = new vnode(*vec++);
            if(this->kind == 0){
                int i = 0;
                while (i<vnum) {
                    int j = 0;
                    while (j<i) {
                        if(a[i][j] != 0){
                            node* t = new node(i+1);
                            if(v[j]->getfirstnode()==NULL)
                                v[j]->setfirstnode(t);
                            else
                                v[j]->insert(t);
                            t = new node(j+1);
                            if(v[i]->getfirstnode()==NULL)
                                v[i]->setfirstnode(t);
                            else
                                v[i]->insert(t);
                        }
                        j++;
                    }
                    i++;
                }
            }
            else{
                int i = 0;
                while (i<vnum) {
                    int j = 0;
                    while (j<vnum) {
                        if(a[i][j] != 0){
                            node* t = new node(j+1);
                            if(v[i]->getfirstnode()==NULL)
                                v[i]->setfirstnode(t);
                            else
                                v[i]->insert(t);
                        }
                        j++;
                    }
                    i++;
                }
            }
        }
    }
    ~graph(){
        node* p;
        node* q;
        for(int i=0; i<nodenum; i++) {
            p = v[i]->getfirstnode();
            while (p) {
                q = p->getptr();
                delete p;
                p = q;
            }
            delete v[i];
        }
        std::cout<<"ok"<<std::endl;
    }
    int getkind(){
        return kind;
    }
    void setkind(int k){
        this->kind = k;
    }
    void get(){
        for(int i=0; i<nodenum;i++){
            std::cout<<v[i]->getval()<<": ";
            node* p = v[i]->getfirstnode();
            while (p) {
                std::cout<<p->getval()<<" ";
                p = p->getptr();
            }
            std::cout<<std::endl;
        }
    }
};

#endif /* graph_h */
