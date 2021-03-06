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
#include <queue>
#include <stack>
#include "node.h"
#include "vnode.h"
#define maxnode 20
#define infinite 1000000

class graph {
	int kind; // 0 undigraph 1 digraph
	int **weight;
	vnode* v[maxnode];
	int nodenum, arcnum;

public:
	graph() {
		this->kind = 0;
		this->nodenum = this->arcnum = 0;
	}
	graph(int* vec, int **a, int vnum, int kind = 0) {
		this->kind = kind;
		this->nodenum = vnum;
		weight = a;
		if (vnum <= 0 || vnum > maxnode) {
			this->nodenum = this->arcnum = 0;
		}
		else if (vnum == 1) {
			v[0] = new vnode(*vec);
			this->arcnum = 0;
		}
		else {
			for (int i = 0; i<vnum; i++)
				v[i] = new vnode(*vec++);
			if (this->kind == 0) {
				int i = 0;
				while (i<vnum) {
					int j = 0;
					while (j<i) {
						if (a[i][j] != 0) {
							node* t = new node(i);
							t->setweight(a[i][j]);
							if (v[j]->getfirstnode() == NULL)
								v[j]->setfirstnode(t);
							else
								v[j]->insert(t);
							t = new node(j);
							t->setweight(a[i][j]);
							if (v[i]->getfirstnode() == NULL)
								v[i]->setfirstnode(t);
							else
								v[i]->insert(t);
						}
						j++;
					}
					i++;
				}
			}
			else {
				int i = 0;
				while (i<vnum) {
					int j = 0;
					while (j<vnum) {
						if (a[i][j] != 0) {
							node* t = new node(j);
							t->setweight(a[i][j]);
							if (v[i]->getfirstnode() == NULL)
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
	~graph() {
		node* p;
		node* q;
		for (int i = 0; i<nodenum; i++) {
			p = v[i]->getfirstnode();
			while (p) {
				q = p->getptr();
				delete p;
				p = q;
			}
			delete v[i];
		}
		for (int i = 0; i<nodenum; i++)
			delete[] weight[i];
		std::cout << "ok" << std::endl;
	}
	int getkind() {
		return kind;
	}
	void setkind(int k) {
		this->kind = k;
	}
	void getinfo() {
		for (int i = 0; i<nodenum; i++) {
			std::cout << v[i]->getval() << ": ";
			node* p = v[i]->getfirstnode();
			while (p) {
				std::cout << p->getval() + 1 << " ";
				p = p->getptr();
			}
			std::cout << std::endl;
		}
	}
	void BFS() {
		if (nodenum<1) {
			std::cout << "BFS is none";
		}
		else {
			std::cout << "BFS is: ";
			bool flag[maxnode];
			for (int i = 0; i<nodenum; i++)
				flag[i] = 0;
			std::queue<int> q;
			for (int i = 0; i<nodenum; i++) {
				if (!flag[i]) {
					q.push(i);
					while (!q.empty()) {
						if (!flag[q.front()]) {
							vnode* p = v[q.front()];
							flag[q.front()] = 1;
							q.pop();
							std::cout << p->getval() << " ";
							node* t = p->getfirstnode();
							while (t) {
								if (!flag[t->getval()]) {
									q.push(t->getval());
								}
								t = t->getptr();
							}
						}
						else
							q.pop();
					}
				}
			}
		}
		std::cout << std::endl;
	}
	void DFS() {
		if (nodenum<1) {
			std::cout << "DFS is none";
		}
		else {
			std::cout << "DFS is: ";
			bool flag[maxnode];
			for (int i = 0; i<nodenum; i++)
				flag[i] = 0;
			std::stack<int> s;
			for (int i = 0; i<nodenum; i++) {
				if (!flag[i]) {
					s.push(i);
					while (!s.empty()) {
						if (!flag[s.top()]) {
							vnode* p = v[s.top()];
							flag[s.top()] = 1;
							s.pop();
							std::cout << p->getval() << " ";
							node* t = p->getfirstnode();
							while (t) {
								s.push(t->getval());
								t = t->getptr();
							}
						}
						else
							s.pop();
					}
				}
			}
		}
		std::cout << std::endl;
	}
	void Dijkstra(int start) {
		bool flag[maxnode];
		int w[maxnode][maxnode];
		std::cout << "Dijkstra:" << std::endl;
		for (int i = 0; i<nodenum; i++)
			flag[i] = 0;
		for (int i = 0; i<nodenum; i++)
			for (int j = 0; j < nodenum; j++) {
				if (i != j && weight[i][j] == 0)
					w[i][j] = infinite;
				else
					w[i][j] = weight[i][j];
			}
		flag[start] = 1;
		int m;
		for (int i = 1; i < nodenum; i++) {
			int min = infinite;
			for (int k = 0; k < nodenum; k++) {
				if (flag[k] == 0) {
					if (w[start][k] < min) {
						min = w[start][k];
						m = k;
					}
				}
			}
			flag[m] = 1;
			std::cout << v[start]->getval() << " to " << v[m]->getval() << " is " << w[start][m] << std::endl;
			for (int k = 0; k < nodenum; k++) {
				if (flag[k] == 0) {
					if (w[start][m] + w[m][k] < w[start][k])
						w[start][k] = w[start][m] + w[m][k];
				}
			}
		}
	}
};

#endif /* graph_h */
