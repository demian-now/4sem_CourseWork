#include <iostream>
#include <vector>
#include "List.h"
#include "Graph.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Graph Test;
	Test.input("test.txt");
	cout << "Максимальный поток из S в T: " << Test.EdmondsKarp();
}
