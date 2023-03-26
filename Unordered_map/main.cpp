// Standard libraries
#include <unordered_map>
#include <iterator>

#include <fstream>
#include <sstream>
#include <algorithm>
#include "state.h"

using namespace std;

void readCSV(string filename, unordered_map<string,State> &smap) 
{
	fstream inFile;
	string tempDest = "", sname, abbr, temp;
	
	//Open file
	inFile.open(filename, ios::in);
	if (inFile.is_open()){
		//Read actual line with getline up to n
        int count = 0;
		while (getline(inFile,tempDest)) 
        {
            stringstream str(tempDest);
            getline(str, sname, ',');  // get the state name
            getline(str, temp, ',');  // skip the second column
            getline(str, abbr);  // skip the second column
            smap.insert (pair<string,State>(abbr,State(sname, abbr)));  //create the State object ; add <abbr,State object> pair to the smap
            //alternative
            // smap[abbr] = State(sname, abbr);

            //print the inserted state and the number of buckets. 
            cout << ++count << " - " <<smap[abbr] << "\t\t# of buckets: " << smap.bucket_count() << std::endl;
        }
		inFile.close();
	}
	else 
		cout << "Unable to open " << filename << endl;
}

// overladed << operator for unordered_map<string,State>
// will write all pairs in the given unordered_map object to "os"  ostream sorted according to the keys (state abbreviations)
std::ostream& operator << (std::ostream& os, const std::unordered_map<string,State>& v) 
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
	unordered_map<string,State> states_map;

    cout << "---------------------------------------------" << endl;
    /*Initially unordered_map is empty*/
    if (states_map.empty())
        cout << "Initially state unordered_map is empty!" << endl;
    else
        cout << "unordered_map is not empty! Its size is: " << states_map.size() << endl;    

    cout << "---------------------------------------------" << endl;    

    /* Read the states data from the data.csv file and insert to the states_map.*/
    readCSV("data.csv", states_map); 
    // print using the <<operator for states_map (see lines 37-47)
    cout << states_map;
    cout << "---------------------------------------------" << endl;
   
    /* **********************************************************************
    /* MODIFIERS : add , update, remove pairs */
    /*************************************************************************/

    /*  add 2 <abbr,state> pairs to the unordered_map. If these abbreviations (keys) already exist in the unordered_map, overwrite them. */
    states_map["NS"] =  State("New State", "NS");
    states_map["AS"] =  State("Another New State", "AS");
    
    /* states_map.size() returns the number of elements in the unordered_map */
    cout << "Size of the vector (after adding 2 states): " << states_map.size() << endl;

    //states_map.bucket_count() returns the number of buckets in the container 
	std::cout << endl << "Number of buckets: " << states_map.bucket_count() << std::endl; 
	
	//states_map.max_size() returns the max number of possible elements that can be stored in the container
	std::cout << "Max number of possible elements: " << states_map.max_size() << std::endl; 

    cout << "---------------------------------------------" << endl;    
    /* Use of "ValueType & operator[] (const KeyType & key)" operator ; can access the element for key "key"*/
    cout << "State with key NS: " << states_map["NS"] << endl;   //Note that, in order to print a State object, you should implement the << operator for State object.
    cout << "State with key CA: " << states_map["CA"] << endl;    

    /* Overwrite the object with key NY. */
    states_map["NY"] = State("*** NEW YORK ***", "NY"); 
    cout << "State NY - after update: " << states_map["NY"] << endl;   

    cout << "---------------------------------------------" << endl;    
    
    /* USE of ITERATORS */
    
    unordered_map<string, State>::iterator first = states_map.begin();  //  iterator pointing to the first pair
    unordered_map<string, State>::iterator last = states_map.end();  //  iterator pointing one past the last pair. (Caution!!)
   
    /* Remove the pair with key KS */
    cout << "Removing Kansas!" << endl;
    states_map.erase("KS"); 

    /*Note: unordered_map iterator are forward iterators. Thatmeans they can only move one step at a time, only forward. 
     So, can't decrement the iterator position.  */

    /* Remove the first pair in the states_map  */
    cout << "Removing first state!" << endl;
    states_map.erase(first); 

    unordered_map<string, State>::iterator cur1 = states_map.find("OH");  //  iterator pointing to the pair having key "OH"
    /* Remove the pair where cur iterator points to  */
    if (cur1 != states_map.end()) // found the pair with key "OH"
    {
        cout << "Removing the state "  << cur1->first << " (using iterator)!" << endl;
        states_map.erase(cur1); 
    } else 
        cout << "Could not find the state!" << endl;
    

    unordered_map<string, State>::iterator cur2 = states_map.find("OH");  //  we already deleted OH
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
    /* PRINT :  print the pairs in a unordered_map container*/ 
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
    // // print using the <<operator for states_map (see lines 37-47)
    // cout << states_map;

    
    cout << "---------------------------------------------" << endl;
    /* Remove all elements from vector */
    states_map.clear();
    cout << "Clearing the unordered_map container! \nSize of the unordered_map (after clear): " << states_map.size() << endl;

    cout << "---------------------------------------------" << endl;


}