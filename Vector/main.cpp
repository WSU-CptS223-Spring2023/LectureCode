// Standard libraries
#include <vector>
#include <iterator>

#include <fstream>
#include <sstream>
#include <algorithm>
#include "state.h"

using namespace std;

void readCSV(string filename, vector<State> &svector) 
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
            svector.push_back (State(sname, abbr));  //create the State object ; add to the svector
        }
		inFile.close();
	}
	else 
		cout << "Unable to open " << filename << endl;
}

// overladed << operator for vector<State>
std::ostream& operator << (std::ostream& os, const std::vector<State>& v) 
{
    os << endl;
    for (auto s: v)
    {
        os << s << endl;
    }
    return os;
}


int main()
{
    /* Vector of States */
	vector<State> state_vector;

    cout << "---------------------------------------------" << endl;
    /*Initially vector is empty*/
    if (state_vector.empty())
        cout << "Initially vector is empty!" << endl;
    else
        cout << "Vector is not empty! Its size is: " << state_vector.size() << endl;    

    cout << "---------------------------------------------" << endl;    
    /* Read the states data from the data.csv file and insert to the state_vector.*/
    readCSV("data.csv", state_vector); 

    cout << "---------------------------------------------" << endl;
    /* The basic interface of std::vector includes size(), push_back(const T&) method, operator[](size_t i), erase(std::vector<T>::iterator it), and clear() */
    

    /*  add 2 states to the vector. */
    state_vector.push_back (State("\"Washington\"", "\"WA\""));
    state_vector.push_back (State("\"West Virginia\"", "\"WV\""));
    
    /* state_vector.size() returns the size of the array */
    cout << "Size of the vector: " << state_vector.size() << endl;

    cout << "---------------------------------------------" << endl;    
    /* Use of "operator[](size_t ind)" operator ; can access the element at index 'ind' (no bounds checking)*/
    cout << "State at index 51: " << state_vector[51] << endl;   //Note that, in order to print a State object, you should implement the << operator for State object.

    /* Use of "at(int index)" operator ; can access the element at index 'ind' (with bounds checking) */
    cout << "State at index 52: " << state_vector.at(52) << endl;   //Note that, in order to print a State object, you should implement the << operator for State object.

    /* Overwrite the object at index 50. */
    state_vector[52] = State("\"New State\"", "\"NS\""); 
    cout << "State at index 52 (after update): " << state_vector[52] << endl;   

    cout << "---------------------------------------------" << endl;    
    /* Can remove the last element in the state_vector using "pop_back()" method;  
       pop_back() removes the object at the end of the list.  */
    state_vector.pop_back(); 

    /* Can remove elements from the state_vector using "erase()" method; removes the object the input iterator points to.
       state_vector.end() returns an iterator that points to the last element in the vector. */
       
    state_vector.erase(state_vector.end()); 

    cout << "Size of the vector (after removing the last 2 states): " << state_vector.size() << endl;
    
    cout << "---------------------------------------------" << endl;    
    /*Iterate over the elements and print them */
    for (size_t i = 0; i < state_vector.size(); i++) {
        cout << i << " - " << state_vector[i] << endl;
    }  
    cout << "---------------------------------------------" << endl;

    /* Alternative way to iterate over elements using range-based for loop and iterators
       The iterator methods enable you to use the range-based for loop. 
       The following code uses the range-based for loop to print the same thing as above. 
       Note the difference: instead of an index size_t i going from 0 to v.size() - 1, 
       the new code directly pulls values int x out of the vector. */
    for (State x : state_vector) {
        cout << x << endl;
    }
    cout << "---------------------------------------------" << endl;
    /* Internal capacity of the vector. */
    cout << "Vector capacity: " << state_vector.capacity() << endl;

    cout << "---------------------------------------------" << endl;
    /* Remove all elements from vector */
    state_vector.clear();
    cout << "Clearing the vector! \nSize of the vector (after clear): " << state_vector.size() << endl;

    cout << "---------------------------------------------" << endl;


    /* **********************************************************************
       ITERATORS
    *************************************************************************/

    /* Iterators are a generalization of pointers. Remember how pointer arithmetic works:*/

    int my_array[5] = {1, 4, 9, 16, 25};
    int* begin_ptr = my_array;    // points at value 1
    int* end_ptr = my_array + 5;  // points to one-past-the-end of my_array
    for (int* p = begin_ptr; p != end_ptr; p++) {
        cout << *p << endl;
    }  // prints 1, 4, 9, 16, 25 (on separate lines)

    cout << "---------------------------------------------" << endl;

    /* If we replace the above array by a vector, we can simply replace the pointers by iterators:*/

    vector<int> my_vec = {1, 4, 9, 16, 25};
    vector<int>::iterator begin = my_vec.begin();  // points at 1
    vector<int>::iterator end = begin + 5;         // one-past-the-end
    for (vector<int>::iterator p = begin; p != end; p++) {
        cout << *p << endl;
    }  // prints 1, 4, 9, 16, 25 (on separate lines)

    /* The type named std::vector<int>::iterator is just another class defined in the standard library. 
       It supports operators like ++ and -- (both postfix and prefix), == and !=, addition of an int, subtraction with another iterator 
       (which gives the distance between two iterators), and of course unary *, the dereference operator (i.e. read-a-value).*/

    /* Typing std::vector<int>::iterator is annoying and it doesn’t add much value for a human reading our code, so we often use auto instead, like for the variable p above. 
       The reason for typing the full name in the block above is for the sake of the example.*/
    
    /* Range-based for loop. These are all valid ways of writing a loop, albeit with slightly different effects: */

    cout << "---------------------------------------------" << endl;
    cout << "- Insert some data to the state_vector -----" << endl;


    /* We first insert some data to the state_vector.*/
    state_vector.push_back (State("\"Washington\"", "\"WA\""));
    state_vector.push_back (State("\"Idaho\"", "\"ID\""));
    state_vector.push_back (State("\"California\"", "\"CA\""));
    state_vector.push_back (State("\"Oregon\"", "\"OR\""));

    /* We also insert a State object to the mid index of the vector. */
    vector<State>::iterator it = state_vector.begin() + (state_vector.size()/2);  
    state_vector.insert(it, State("\"BEST STATE\"", "\"BS\""));
    cout << state_vector ;

    cout << "---------------------------------------------" << endl;
    cout << "- Updating state names and abbreviations-----" << endl;

    // Operate on independent copies of the elements of v. This may be
    // slower, but it allows you to safely modify the loop variable s
    // without affecting the vector.
    for (State s : state_vector) {
        s.setName("\"---\"");
    }
    for (auto s : state_vector) {
        s.setAbbr("\"****\"");
    }
    cout << "-----------\n-Updated only copies of objects-----" << endl;
    /* print all elements in the vector ; using the operator<< for vector<State>*/
    cout << state_vector ;

    cout << "---------------------------------------------" << endl;
    cout << "- Updating state names and abbreviations-----" << endl;

    /* Operate via mutable reference. No copies are made; changes affect the
     contents of the vector.*/
    for (State &s : state_vector) {
        if (s.getName() == "\"California\"")
                s.setAbbr("\"--\"");
    }
    for (vector<State>::iterator it = state_vector.begin();  it < state_vector.end(); it++) {
        if ((*it).getName() == "\"Idaho\"")
            (*it) = State("\"Nevada\"", "\"NV\"");
    }

    cout << "-----------\n-Updated the object values-----" << endl;
    /* print all elements in the vector*/
    cout << state_vector;

    cout << "---------------------------------------------" << endl;
    // Operate via const&. No copies needed, and no modifications allowed.
    for (const State &s : state_vector) {
        cout << s << endl;
    }
    cout << "---------------" << endl;
    for (const auto &s : state_vector) {
        cout << s << endl;
    }
    cout << "---------------------------------------------" << endl;


    /* Other uses of iterators */
    /* Several standard library functions take iterators as arguments. These fall mostly into two types: iterators as element pointers, and iterators as a range/collection.
     * We already saw one example of the first type of function. The erase() method on a vector takes an iterator as its argument, to indicate the element to erase. 
      Other containers like std::list and std::set have a similar erase() method.*/

    /* Iterators are also used as arguments to describe a collection or sub-collection. 
     * For example, consider the std::vector constructor that takes two iterators as arguments, or the version of erase() that takes two iterators. 
     * In this usage, there are almost always a pair of iterators, to indicate the first element and one-past-the-last element to act on. */
    //Examples
    vector<int> v1{0,10,20,30,40,50,60,70,80,90};
    vector<int> v2(v1.begin(), v1.end());
    // v2 = {0,10,20,30,40,50,60,70,80,90}
    
    vector<int> v3(v2.begin() + 2, v2.begin() + 6);
    // v3 == {20,30,40,50}
    
    v3.erase(v3.begin() + 1, v3.begin() + 3);
    // v3 == {20,50}
    
    reverse(v1.begin(), v1.end() - 2);
    // v1 == {70,60,50,40,30,20,10,0,80,90}
}