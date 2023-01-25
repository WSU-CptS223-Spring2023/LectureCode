// Standard libraries
#include <list>
#include <iterator>

#include <fstream>
#include <sstream>
#include <algorithm>
#include "state.h"

using namespace std;

void readCSV(string filename, list<State> &slist) 
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
            slist.push_back (State(sname, abbr));  //create the State object ; add to the slist
        }
		inFile.close();
	}
	else 
		cout << "Unable to open " << filename << endl;
}

int main()
{
    /* List of States */
	list<State> state_list;

    cout << "---------------------------------------------" << endl;
    /*Initially list is empty*/
    if (state_list.empty())
        cout << "Initially list is empty!" << endl;
    else
        cout << "list is not empty! Its size is: " << state_list.size() << endl;    

    /* Read the states data from the data.csv file and insert to the state_list.*/
    readCSV("data.csv", state_list); 

    cout << "---------------------------------------------" << endl;
    /* The basic interface of std::list includes 
     * size(), push_back(const T&) method, pop_back(const T&), push_front(const T&), pop_front(const T&), 
     * erase(std::list<T>::iterator it), and clear() */
    
    /*  add 2 states to the list: one to the front and one to the back of the list */
    state_list.push_front (State("\"First State\"", "\"FS\""));
    state_list.push_back (State("\"Last State\"", "\"LS\""));
    
    /* state_list.size() returns the size of the array */
    cout << "Size of the list: " << state_list.size() << endl;

    cout << "---------------------------------------------" << endl;    
    /* Use of  "insert()" operator ; can insert a new element at the position iterator points to */
    list<State>::iterator it = state_list.begin();
    // Move the iterator by 10 elements
    advance(it, 10);
    state_list.insert(it, State("\"Tenth State\"", "\"10\""));
    cout << "New state inserted at index 10: " << *(--it) << endl;   //Note that, in order to print a State object, you should implement the << operator for State object.

    cout << "---------------------------------------------" << endl;    
    /* The below won't work */
    // for (size_t i = 0; i < state_list.size(); i++) {
    //     cout << i << " - " << state_list[i] << endl;
    // }  

    /* However, you can iterate over elements using range-based for loop and iterators
       The iterator methods enable you to use the range-based for loop. 
       The following code uses the range-based for loop to print the same thing as above. */
    for (State x : state_list) {
        cout << x << endl;
    }
    cout << "---------------------------------------------" << endl;    
    /* Can remove the last element in the state_list using "pop_back()" and "pop_front()" methods;  
    *  pop_front() removes the object at the front of the list.  
    *  pop_back() removes the object at the end of the list.  */
    state_list.pop_front();
    state_list.pop_back(); 

    /* Can remove elements from the state_list using "erase()" method; removes the object the input iterator points to.
       state_list.end() returns an iterator referring to the **past-the-end** element in the list container. So we need to decrement it before we pass it to erase. */
    it =state_list.end();  
    it--;
    state_list.erase(it);  // will erase "Wyoming"
    cout << "Size of the list (after removing 3 states ): " << state_list.size() << endl;
      
    cout << "---------------------------------------------" << endl;    
    /* After states are removed*/
    for (State x : state_list) {
        cout << x << endl;
    }

    cout << "---------------------------------------------" << endl;
    /* Remove all elements from list */
    state_list.clear();
    cout << "Clearing the list! \nSize of the list (after clear): " << state_list.size() << endl;

    cout << "---------------------------------------------" << endl;


 
}