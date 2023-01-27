#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<string> svector;


void insert2Vector(vector<svector> &v);
void printVector(const vector<svector> &vec);


// overladed << operator for vector<int>
std::ostream& operator << (std::ostream& os, const std::vector<int>& v);