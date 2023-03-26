#ifndef STATE_H
#define STATE_H

#include <string> 
#include <iostream> 

using std::string;

class State
{
private:
	string name;
	string abbr;

public:
	explicit State();
	explicit State(string sname);
    State(string sname, string abbreviation);
	
    void printState();
	void setName(string sname);
	string getName();
	void setAbbr(string abbreviation);
	string getAbbr();
	
    void operator = (const State data) {
		name = data.name;
        abbr = data.abbr;
    }
};

std::ostream& operator<< (std::ostream& lhs, State rhs);
int operator == (State x, State y);

#endif //STATE_H