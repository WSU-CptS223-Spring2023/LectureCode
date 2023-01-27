#include "testdata.hpp"


// x and y are passed by value
void swap1( int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

// x and y are passed by reference
void swap2( int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

// x and y are passed by reference
// swapping by three copies
void swap( vector<string> & x, vector<string> & y )
{
    vector<string> tmp = x;
    x = y;
    y = tmp;
}

// Overloaded function where argument arr is an lvalue. 
// returns random item in lvalue arr
// arr is passed by constant reference 
string randomItem( const vector<string> & arr ){
    cout << "Called randomItem with lvalue."<<endl;
    return arr[rand() % arr.size()];
}

// Overloaded function where argument arr is an rvalue. 
// returns random item in rvalue arr
string randomItem( vector<string> && arr ){
    cout << "Called randomItem with rvalue."<<endl;
    return arr[rand() % arr.size()];
}


// Returns the vector with max size in the given 2 dimensional vector.  Assume vec includes at least one vector
// vec is passed by constant-reference 
// returns a copy of the max length vector in vec
svector findMaxSize1(const vector<svector> &vec)
{

    int max_vector = 0; //index of the max size vector in vec
    for (int i=1 ; i<(int)vec.size(); i++){
        if (vec[i].size() > vec[max_vector].size())
            max_vector = i;
    }
    return vec[max_vector];
}

// Returns the vector with max size in the given 2 dimensional vector. Assume vec includes at least one vector
// vec is passed by constant-reference 
// returns a reference of max length vector in vec
svector & findMaxSize2( vector<svector> &vec)
{
    int max_vector = 0; //index of the max size vector in vec
    for (int i=1 ; i<(int)vec.size(); i++){
        if (vec[i].size() > vec[max_vector].size())
            max_vector = i;
    }
    return (vec[max_vector]);
}

// Returns the vector with max size in the given 2 dimensional vector. Assume vec includes at least one vector
// vec is passed by constant-reference 
// returns a constant reference of max length vector in vec
const svector & findMaxSize3( const vector<svector> &vec)
{
    int max_vector = 0; //index of the max size vector in vec
    for (int i=1 ; i<(int)vec.size(); i++){
        if (vec[i].size() > vec[max_vector].size())
            max_vector = i;
    }
    return (vec[max_vector]);
}


vector<int> partialSum( const vector<int> & arr )
{
    vector<int> result( arr.size( ) );

    result[ 0 ] = arr[ 0 ];
    for( int i = 1; i < arr.size( ); ++i )
        result[ i ] = result[ i - 1 ] + arr[ i ];

    return result;
}

int main()
{
   
// ------------------------------------------------------
// Parameter Passing
// ------------------------------------------------------
    cout << endl << "Parameter passing: "<< endl;
    
    cout <<" Pass-by-value" << endl;
    
    int x = 10, y = 30;
//------------
    cout << "Initial values: x: "<< x << " - y: " << y << endl;
    swap1 (x,y);
    cout << "After first swap: x: "<< x << " - y: " << y << endl;

//------------
    cout <<" Pass-by-reference" << endl;
    swap2 (x,y);
    cout << "After second swap: x: "<< x << " - y: "  <<y << endl;

//------------
    cout <<" Pass-by-rvalue-reference" << endl;
    srand((unsigned) time(NULL));
    vector<string> v { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
    // invokes lvalue method. v is passed by constant reference. 
    cout << randomItem( v ) << endl; 
    // invokes rvalue method. The passed vector rvalue is moved to arr (not copied). 
    cout << randomItem( { "a", "b", "c", "d", "e", "f", "g"} ) << endl; 

// ------------------------------------------------------
// Return Passing
// ------------------------------------------------------
    cout << "-----------------------------------------------------"<<endl;
    cout << endl << "Return passing: "<< endl;

    vector<svector> big_data;
    insert2Vector(big_data);
    
   
    //Assume big_data vector stores large objects (i.e., svector objects are large)

    //findMaxSize1 will return a copy of the max size vector in big_data
    svector copyvector = findMaxSize1(big_data);
    // The value will be added to the copy of the vector
    copyvector.push_back("Y");

    printVector(big_data);

    //findMaxSize2 will return a reference of the max size vector in big_data
    svector & refvector = findMaxSize2(big_data);
    // The value will be added to the actual vector (i.e., the max size vector in big_data)
    refvector.push_back("Y");

    printVector(big_data);

    //findMaxSize3 will return a const reference of the max size vector in big_data
    const svector & constrefvector = findMaxSize3(big_data);
    // constrefvector is a constant reference; we can't insert a value. The following won't work. 
    // constrefvector.push_back("Y"); //illegal


    vector<int> vec {{1,2,3,4,5,6,7,8,9,10}};

    vector<int> sums = partialSum( vec ); // Copy in old C++; move in C++11
    cout << endl << "Result of partialSum : " << sums << endl; 
    /* In C++11, objects can define move semantics that can be employed when return-by-value is seen; 
      in effect, the result vector will be moved to sums, and the vector implementation is optimized 
      to allow this to be done with little more than a pointer change.*/
      

}