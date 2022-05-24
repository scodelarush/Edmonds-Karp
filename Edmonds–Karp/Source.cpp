#include <iostream>
#include <string>
#include <fstream>
#include "AdjMatrix.h"
#include "AdjList.h"
#include "List.h"
#include "List.cpp"
#include "Map.h"
#include "Map.cpp"
#include "IntQueue.h"

using namespace std;

List<string> text;
Map <char, int> translator;
AdjMatrix g;
AdjList adj;

void read(string path) { 
	ifstream input(path);
	if (!input.is_open()) {
		return;
	}
	while (!input.eof()) {
		string temp;
		getline(input, temp);
		text.push_back(temp);
	}
}

void countVertex() { 
	int counter = 0;
	int n = text.getSize();
	for (int i = 0; i < n; i++) {
		string x = text.front();
		text.pop_front();
		text.push_back(x);
		if (!translator.exist(x[0])) {
			translator.insert(x[0],counter);
			counter++;
		}
		if (!translator.exist(x[2])) {
			translator.insert(x[2],counter);
			counter++;
		}
	}
}

void separate(char& cityA, char& cityB, string& dist, string temp) { 
	int count = 1;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == ' ') {
			count++;
			continue;
		}
		switch (count) {
		case 1:
			cityA = temp[i];
			break;
		case 2:
			cityB = temp[i];
			break;
		case 3:
			dist += temp[i];
			break;
		default:
			break;
		}
	}
}

void init() {  
	countVertex();
	g.resize(translator.getSize());
	adj.resize(translator.getSize());
	for (int i = 0; i < g.getSize(); i++)for (int j = 0; j < g.getSize(); j++)g[i][j] = 0;
	while (text.getSize()) {
		string temp = text.front();
		text.pop_front();
		char cityA, cityB;
		string dist;
		separate(cityA, cityB, dist, temp);
		g[translator[cityA]][translator[cityB]] = stoi(dist);
		adj.insert(translator[cityA], translator[cityB]);
	}
}

bool widthSearch(int s, int t, int& flow) { 
	int n = translator.getSize();
	bool* used = new bool[n];
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		used[i] = 0;
		p[i] = 0;
	}
	for (int i = 0; i < n; i++)used[i] = 0;
	IntQueue q;
	q.push(s);
	used[s] = 1;
	p[s] = s;
	bool flag = false;
	while (q.getSize()) {
		int cur = q.front();
		q.pop();
		if (cur == t) {
			flag = true;
			break;
		}
		for (int i = 0; i < n;i++) {
			if (adj.exist(cur,i) && !used[i]) {
				q.push(i);
				used[i] = true;
				p[i] = cur;
			}
		}
	}
	int cur = t;
	while (cur != s && flag) {
		if (cur == t) {
			flow = g[p[cur]][cur];
		}
		flow = min(flow, g[p[cur]][cur]);
		cur = p[cur];
	}
	cur = t;
	while (cur != s && flag) {
		g[p[cur]][cur] -= flow;
		if (g[p[cur]][cur] == 0)adj.remove(p[cur], cur);
		cur = p[cur];
	}
	delete[] used;
	delete[] p;
	return flag;
}

int algEdmondsKarp(int s, int t) {
	int flow = 0, temp;
	while (widthSearch(s,t,temp)) flow += temp;
	return flow;
}

int main() {
	read("info.txt");
	init();
	cout << algEdmondsKarp(translator['S'], translator['T']);
} 