#include "testdata.hpp"

// Returns the vector with max size in the given 2 dimensional vector, 
// Assume vec includes at least one vector
svector findMaxSize1(const vector<svector> &vec)
{

    int max_vector = 0; //index of the max size vector in vec
    for (int i=1 ; i<(int)vec.size(); i++){
        if (vec[i].size() > vec[max_vector].size())
            max_vector = i;
    }
    return vec[max_vector];
}

// Returns the vector with max size in the given 2 dimensional vector, 
// Assume vec includes at least one vector
svector & findMaxSize2( vector<svector> &vec)
{
    int max_vector = 0; //index of the max size vector in vec
    for (int i=1 ; i<(int)vec.size(); i++){
        if (vec[i].size() > vec[max_vector].size())
            max_vector = i;
    }
    return (vec[max_vector]);
}

int main()
{
// -------------------------------------------------------
// lvalue reference examples
// -------------------------------------------------------
    string str = "hell";
    string &rstr = str;          // rstr is another name for str
    rstr += 'o';                 // changes str to "hello"
    bool cond = (&str == &rstr); // true; str and rstr are same object

    // The following assignments are ILLEGAL
    // string & bad1 = "hello"; // illegal: "hello" is not a modifiable lvalue
    // string & bad2 = str + ""; // illegal: str+"" is not an lvalue
    // string & sub = str.substr( 0, 4 ); // illegal: str.substr( 0, 4 ) is not an lvalue

    // rvalue reference examples
    string &&bad1 = "hello";         // Legal
    string &&bad2 = str + "";        // Legal
    string &&sub = str.substr(0, 4); // Legal
    
// ------------------------------------------------------
// Uses of lvalue references
// ------------------------------------------------------
    cout << endl << "Uses of lvalue references: "<< endl;
    
// *1* lvalue references use #1: aliasing complicated names

    cout <<" lvalue references use #1: aliasing complicated names:" << endl;

    vector<svector> big_data;
    insert2Vector(big_data);
    srand((unsigned) time(NULL));

    // Assume big_data[rand() % big_data.size()] is a "complex" expression
    // Compare the below two versions: whichVector2 is a reference variable in the second version. 
    
    // version1 -- X is added to the copy of the vector
    auto  whichVector1 = big_data[rand() % big_data.size()];
    if (whichVector1.size() == 1) 
        whichVector1.push_back("X");
    
    printVector(big_data);
    big_data.clear();
    insert2Vector(big_data);

    // version2 -- X is added to the actual vector
     auto & whichVector2 = big_data[rand() % big_data.size()];
    if (whichVector2.size() == 1) 
        whichVector2.push_back("X");

    printVector(big_data);
    
// --------------------------------------------------------
// lvalue references use #2 ; range for loops

    cout <<"*2* lvalue references use #2 ; range for loops:" << endl;

    vector<int> arr {{1,2,3,4,5,6,7,8,9,10}};

    // for loop ; increments all values in arr by 1
    for( int i = 0; i < (int)arr.size( ); ++i )
        ++arr[ i ]; 

    cout << "After first for loop: " << arr << endl;
    // a range for loop would be more elegant. The below won't work, because x assumes a copy of each value in the vector.
    for( auto x : arr ) // broken
        ++x;

    cout << "After second for loop: "<< arr << endl;

    // What we really want is for x to be another name for each value in the vector, which is easy to do if x is a reference:
    for( auto & x : arr ) // works
        ++x;
    
    cout << "After third for loop: "<< arr << endl;

// --------------------------------------------------------
// lvalue references use #2 ; avoiding a copy

    //Assume big_data vector stores large objects (i.e., svector objects are large)

    //findMaxSize1 will return a copy of the max size vector in big_data
    svector copyvector = findMaxSize1(big_data);
    // The value will be added to the copy of the vector
    copyvector.push_back("Y");

    printVector(big_data);

    //findMaxSize1 will return a reference of the max size vector in big_data
    svector & refvector = findMaxSize2(big_data);
    // The value will be added to the actual vector (i.e., the max size vector in big_data)
    refvector.push_back("Y");

    printVector(big_data);


}