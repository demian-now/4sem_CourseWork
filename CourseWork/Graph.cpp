#include "Graph.h"
#include "List.h"
#include "List.cpp"
#include <cstddef>
#include <iomanip>
#include <fstream>

#define inf INT_MAX/2-1

Graph::Graph()
{
	matrix_c = NULL;
	matrix_f = NULL;
	num_node = 0;
}

Graph::~Graph()
{
	clear();
}

void Graph::input(string filename)
{
	if (filename == "")
		filename = "test.txt";
	string temp;
	ifstream filereader; 
	filereader.open(filename.c_str(), ios::in);
	if (filereader.bad())
		throw "Bad File Name";
	while (!filereader.eof())
	{
		getline(filereader, temp);
		info.push_back(temp);
	}	
	create_matrix();
	int n = num_node;
}

int Graph::EdmondsKarp()
{
	while(1)
	{
		int* from = new int[num_node];
		int* temp = new int[num_node];
		for (size_t i = 0; i < num_node; i++)
			from[i] = -1;
		int h = 0, t = 0;
		temp[t++] = 0;
		from[0] = 0;
		for (int cur; h < t;)
		{
			cur = temp[h++];
			for (size_t v = 0; v < num_node; v++)
				if (from[v] == -1 && (matrix_c[cur][v] - matrix_f[cur][v]) > 0)
				{
					temp[t++] = v;
					from[v] = cur;
				}
		}
		if (from[num_node-1] == -1)
			break;
		int cf = inf;
		for (int cur = num_node - 1; cur != 0; )
		{
			int prev = from[cur];
			cf = min(cf, matrix_c[prev][cur] - matrix_f[prev][cur]);
			cur = prev;
		}
		for (int cur = num_node - 1; cur != 0; )
		{
			int prev = from[cur];
			matrix_f[prev][cur] += cf;
			matrix_f[cur][prev] -= cf;
			cur = prev;
		}
	}
	int flow = 0;
	for (int i = 0; i < num_node; i++)
		if (matrix_c[0][i])
			flow += matrix_f[0][i];
	return flow;
}

void Graph::clear()
{
	for (size_t i = 0; i < num_node; i++)
	{
		delete[] matrix_c[i];
		delete[] matrix_f[i];
	}
	delete matrix_c;
	delete matrix_f;
}

void Graph::create_matrix()
{
	BiList<string*> all_data;
	for (size_t i = 0; i < info.get_size(); i++)
	{
		string temp = info.at(i);
		string* tmp = new string[3];
		size_t cur = 0;
		for (size_t j = 0; j < 3; j++)
		{
			while (cur< temp.size() && temp[cur]!= ' ')
			{
				tmp[j] += temp[cur];
				cur++;
			}
			cur++;
		}
		all_data.push_back(tmp);
		for (size_t j = 0; j < 2; j++)
			if (name_node.find(tmp[j]) == -1)
				name_node.push_back(tmp[j]);
	}
	try {
		name_node.swap(name_node.find("S"), 0);
		name_node.swap(name_node.find("T"), name_node.get_size()-1);
	}
	catch(char*)
	{
		throw "Bad Data Error";
	}
	num_node = name_node.get_size();
	matrix_c = new int* [num_node];
	matrix_f = new int* [num_node];
	for (size_t i = 0; i < num_node; i++)
	{
		matrix_c[i] = new int[num_node];
		matrix_f[i] = new int[num_node];
		for (size_t j = 0; j < num_node; j++)
		{
			matrix_c[i][j] = 0;
			matrix_f[i][j] = 0;
		}
	}
	for (size_t i = 0; i < all_data.get_size(); i++)
	{
		string* temp = all_data.at(i);
		matrix_c[name_node.find(temp[0])][name_node.find(temp[1])] = stoi(temp[2]);
	}
}
