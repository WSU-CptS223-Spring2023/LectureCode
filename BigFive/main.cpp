#include "BigFive.h"
#include "TestBigFive.h"

// Note: lvalues refer to specific memory locations, i.e. variables. rvalues usually refer to temporary 
//       and short lived values that are not associated with an identifier/not addressable.

int main(int argc, char* argv[])
{
	BigFive bf1, // invokes default constructor
		bf2("test string", strlen("test string") + 1), // invokes constructor with arguments specified
		bf3(bf2); // invokes copy constructor

	std::cout << "Before move constructor: bf3 str: " << bf3.getString() << " bf3 length: " << 
		bf3.getLength() << std::endl;
	
	// move semantics allows for efficient transfer of resources!
	// moving bf3 resources to bf4; should not be able to *use* bf3 after the move
	BigFive bf4(std::move(bf3)); // invokes the move constructor - std::move ()

	std::cout << "bf3 resources moved to bf4 str: " << bf4.getString() << " bf4 length: " << 
		bf4.getLength() << std::endl;
	
	// what happens if you uncomment the line below? It could cause a serious problem! bf3 resources
	// have been moved!
	// std::cout << "After move constructor: bf3 str: " << bf3.getString() << " bf3 length: " << bf3.getLength() << std::endl;

	bf1 = bf2; // invokes copy assignment operator

	//bf3 = BigFive(); // invokes move assignment operator - rhs is an rvalue

	std::vector<BigFive> v;
	v.push_back(BigFive()); // the argument is an rvalue - BigFive move constructor will be invoked

	testBigFiveMoveAssignment(); // let's run one of our tests

	return 0;
}