#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<string> svector;


void insert2Vector(vector<svector> &v)
{
    for (auto s : {"A", "B", "C", "D", "E", "F", "G", "H"}){
        vector<string> vstr {s};
        v.push_back(vstr);
    }
}


void printVector(const vector<svector> &vec){
    for (auto v : vec) {
        cout << " [";
        for (auto s : v)
            cout << s ;
        cout << "] ";
    } 
    cout << endl;
}

// overladed << operator for vector<int>
std::ostream& operator << (std::ostream& os, const std::vector<int>& v) 
{
    os << "[";
    for (auto s: v)
    {
        os << s << ", ";
    }
    os << "]";
    return os;
}