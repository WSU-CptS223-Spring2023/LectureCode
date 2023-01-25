#include "state.h" 

State::State()
{
	name = "";
	abbr = "";
}

State::State(string sname)
{
	name = sname;
    abbr = "";
}
State::State(string sname, string abbreviation)
{
	name = sname;
    abbr = abbreviation;
}

void State::setName(string sname) { name = sname; }

string State::getName() { return name; }

void State::setAbbr(string abbreviation) { abbr = abbreviation; }

string State::getAbbr(){ return abbr; }


// Operator implementations
std::ostream& operator<< (std::ostream& lhs, State rhs) 
{
	lhs << rhs.getName() << "; " << rhs.getAbbr() ;
    return lhs;
}

int operator == (State x, State y)
{
    return (x.getName() == y.getName());
}

