#pragma once
#include "List.h"
#include <string>

using namespace std;

class Graph
{
private:
	int** matrix_c, **matrix_f, num_node;
	BiList<string> name_node, info;
	void create_matrix();

public:
	Graph();
	~Graph();
	void input(string name);
	int EdmondsKarp();
	void clear();
};