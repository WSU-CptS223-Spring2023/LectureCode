// Standard libraries
#include <map>
#include <iterator>

#include <fstream>
#include <sstream>
#include <algorithm>
#include "state.h"

using namespace std;

void readCSV(string filename, map<string,State> &smap) 
{
	fstream inFile;
	string tempDest = "", sname, abbr, temp;
	
	//Open file
	inFile.open(filename, ios::in);
	if (inFile.is_open()){
		//Read actual line with getline up to n
		while (getline(inFile,tempDest)) 
        {
            stringstream str(tempDest);
            getline(str, sname, ',');  // get the state name
            getline(str, temp, ',');  // skip the second column
            getline(str, abbr);  // skip the second column
            smap.insert (pair<string,State>(abbr,State(sname, abbr)));  //create the State object ; add <abbr,State object> pair to the smap
            //alternative
            // smap[abbr] = State(sname, abbr);
        }
		inFile.close();
	}
	else 
		cout << "Unable to open " << filename << endl;
}

// overladed << operator for map<string,State>
// will write all pairs in the given map object to "os"  ostream sorted according to the keys (state abbreviations)
std::ostream& operator << (std::ostream& os, const std::map<string,State>& v) 
{
    os << endl;
    for (auto s: v)
    {
        os << s.first << " - " <<  s.second << endl;
    }
    return os;
}

int main()
{
    /* Vector of States */
	map<string,State> states_map;

    cout << "---------------------------------------------" << endl;
    /*Initially map is empty*/
    if (states_map.empty())
        cout << "Initially state map is empty!" << endl;
    else
        cout << "Map is not empty! Its size is: " << states_map.size() << endl;    

    cout << "---------------------------------------------" << endl;    

    /* Read the states data from the data.csv file and insert to the states_map.*/
    readCSV("data.csv", states_map); 
    // print using the <<operator for states_map (see lines 37-47)
    cout << states_map;
    cout << "---------------------------------------------" << endl;
   
    /* **********************************************************************
    /* MODIFIERS : add , update, remove pairs */
    /*************************************************************************/

    /*  add 2 <abbr,state> pairs to the map. If these abbreviations (keys) already exist in the map, overwrite them. */
    states_map["NS"] =  State("New State", "NS");
    states_map["AS"] =  State("Another New State", "AS");
    
    /* states_map.size() returns the size of the map */
    cout << "Size of the vector (after adding 2 states): " << states_map.size() << endl;

    cout << "---------------------------------------------" << endl;    
    /* Use of "ValueType & operator[] (const KeyType & key)" operator ; can access the element for key "key"*/
    cout << "State with key NS: " << states_map["NS"] << endl;   //Note that, in order to print a State object, you should implement the << operator for State object.
    cout << "State with key CA: " << states_map["CA"] << endl;    

    /* Overwrite the object with key NY. */
    states_map["NY"] = State("*** NEW YORK ***", "NY"); 
    cout << "State NY - after update: " << states_map["NY"] << endl;   

    cout << "---------------------------------------------" << endl;    
    
    /* USE of ITERATORS */
    
    map<string, State>::iterator first = states_map.begin();  //  iterator pointing to the first pair
    map<string, State>::iterator last = states_map.end();  //  iterator pointing one past the last pair. (Caution!!)
   
    /* Remove the pair with key KS */
    cout << "Removing Kansas!" << endl;
    states_map.erase("KS"); 

    /* Remove the last pair in the states_map  */
    cout << "Removing last state!" << endl;
    states_map.erase(--last); 

    /* Remove the first pair in the states_map  */
    cout << "Removing first state!" << endl;
    states_map.erase(first); 

    map<string, State>::iterator cur1 = states_map.find("OH");  //  iterator pointing to the pair having key "OH"
    /* Remove the pair where cur iterator points to  */
    if (cur1 != states_map.end()) // found the pair with key "OH"
    {
        cout << "Removing the state "  << cur1->first << " (using iterator)!" << endl;
        states_map.erase(cur1); 
    } else 
        cout << "Could not find the state!" << endl;
    

    map<string, State>::iterator cur2 = states_map.find("OH");  //  we already deleted OH
    /* Remove the pair where cur iterator points to  */
    if (cur2 != states_map.end()) // found 
    {
        cout << "Removing the state "  << cur2->first << " (using iterator)!" << endl;
        states_map.erase(cur2); 
    } else 
        cout << "Could not find the state!" << endl;


    cout << "Size of the vector (after removing 4 states): " << states_map.size() << endl;
    
    cout << "---------------------------------------------" << endl;   

    /* **********************************************************************
    /* PRINT :  print the pairs in a map container*/ 
    /*************************************************************************/

    // approach-1
    /* Iterate over elements using range-based for loop and iterators
       The iterator methods enable you to use the range-based for loop.  */
    for (pair<string,State> x : states_map) {
        cout << x.first << " ; " << x.second << endl;
    }

    cout << "---------------------------------------------" << endl;

    // approach-2
    /* Iterate over elements using iterator */
    // for (auto it = states_map.begin ();  it != states_map.end (); ++it) {
    //     cout << (*it).first << " ; " << (*it).second << endl;
    // }

    // approach-3
    // cout << "---------------------------------------------" << endl;
    //print using the <<operator for states_map (see lines 37-47)
    // cout << states_map;

    
    cout << "---------------------------------------------" << endl;
    /* Remove all elements from vector */
    states_map.clear();
    cout << "Clearing the map container! \nSize of the map (after clear): " << states_map.size() << endl;

    cout << "---------------------------------------------" << endl;


}