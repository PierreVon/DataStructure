//
//  btree.h
//  Data
//
//  Created by PierreVon on 2019/5/14.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef btree_h
#define btree_h
#include "bnode.h"
#include <queue>

class btree {
    bnode* root;
    
public:
    btree(){
        // root = new bnode;
    }
    btree(int list[],int len){
        root = new bnode;
        for(int i=0;i<len;i++){
            insert(list[i]);
        }
    }
    ~btree(){
        if(root){
            std::queue<bnode*>q;
            q.push(root);
            while (!q.empty()) {
                bnode* node = q.front();
                q.pop();
                int i;
                for(i=0;i<node->getnum();i++)
                    if(node->getsubtree(i)!=NULL)
                        q.push(node->getsubtree(i));
                if(node->getsubtree(i)!=NULL)
                    q.push(node->getsubtree(i));
                delete node;
            }
        }
    }
    void insert(int val){
        if(root->getval(0)==-1)
            root->setadjustval(val);
        else{
            bnode* p=root;
            // parent node
            bnode* q;
            // up node
            bnode* s = NULL;
            int up;
            // find leaf node
            while (p->getsubtree(0)!=NULL) {
                int i =0;
                while (i<p->getnum()&&val>p->getval(i)) i++;
                if(i+1==p->getnum())
                    p=p->getsubtree(i+1);
                else
                    p=p->getsubtree(i);
            }
            // insert without split
            if(p->getnum()<p->r-1){
                if(s)
                    p->setadjustnode(s);
                else{
                    s = new bnode(val);
                    p->setadjustnode(s);
                }
            }
            
            // insert with split
            else{
                // until insertable
                bool flag = false;
                while(!flag){
                    q = p->getparent();
                    int mid = p->getnum()/2;
                    bnode* new1 = new bnode;
                    bnode* new2 = new bnode;
                    up = val;
                    if(s == NULL)
                        s = new bnode(val);
                    // split by mid, up > mid
                    if(up>p->getval(mid)){
                        int i,j;
                        for(i=0;i<mid;i++){
                            new1->setval(i,p->getval(i));
                            new1->setsubtree(i, p->getsubtree(i));
                        }
                        new1->setsubtree(i, p->getsubtree(i));
                        new1->setnum(i);
                        
                        for(i=mid+1,j=0;i<p->getnum();i++,j++){
                            new2->setval(j,p->getval(i));
                            new2->setsubtree(j, p->getsubtree(i));
                        }
                        new2->setsubtree(j, p->getsubtree(i));
                        new2->setnum(j);
                        new2->setadjustnode(s);

                        up = p->getval(mid);
                    }
                    // split by mid, up < mid
                    else if(up<p->getval(mid-1)){
                        int i,j;
                        for(i=0;i<mid;i++){
                            new1->setval(i,p->getval(i));
                            new1->setsubtree(i, p->getsubtree(i));
                        }
                        new1->setsubtree(i, p->getsubtree(i));
                        new1->setnum(i);
                        new1->setadjustnode(s);
                

                        for(i=mid+1,j=0;i<p->getnum();i++,j++){
                            new2->setval(j,p->getval(i));
                            new2->setsubtree(j, p->getsubtree(i));
                        }
                        new2->setsubtree(j, p->getsubtree(i));
                        new2->setnum(j);
                    
                        up = p->getval(mid);
                    }
                    // split by up
                    else{
                        int i,j;
                        for(i=0;i<mid;i++){
                            new1->setval(i,p->getval(i));
                            new1->setsubtree(i, p->getsubtree(i));
                        }
                        new1->setnum(i);
                        if(s!=NULL)
                            new1->setsubtree(i, s->getsubtree(0));
                        
                        if(mid == p->getnum()-1)
                            i = p->getnum()-1;
                        for(j=0;i<p->getnum();i++,j++){
                            new2->setval(j,p->getval(i));
                            new2->setsubtree(j, p->getsubtree(i));
                        }
                        new2->setnum(j);
                        if(s!=NULL)
                            new2->setsubtree(0, s->getsubtree(1));
                        up = val;
                    }
                    s = new bnode(up);
                    s->setsubtree(0, new1);
                    s->setsubtree(1, new2);
                    new1->setparent(s);
                    new2->setparent(s);
                    // new root
                    if(q==NULL){
                        root = s;
                        flag = true;
                    }
                    //insert in parent node
                    else if(q->getnum()<q->r-1){
                        q->setadjustnode(s);
                        flag = true;
                    }
                    else
                        p=q;
                }
            }
        }
    }
    void pi(){
        for(int i=0;i<root->getnum();i++)
            std::cout<<root->getval(i)<<" ";
    }
    void travel(){
        if(root){
            std::queue<bnode*>q;
            q.push(root);
            while (!q.empty()) {
                bnode* node = q.front();
                q.pop();
                int i;
                for(i=0;i<node->getnum();i++)
                    std::cout<<node->getval(i)<<" ";
                for(i=0;i<=node->getnum();i++)
                    if(node->getsubtree(i)!=NULL)
                        q.push(node->getsubtree(i));
                std::cout<<std::endl;
            }
        }
    }
};

#endif /* btree_h */
