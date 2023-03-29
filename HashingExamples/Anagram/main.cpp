#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if `X` and `Y` are anagrams or not
bool isAnagram(string X, string Y)
{
	// if X's length is not the same as Y's, they can't be an anagram
	if (X.length() != Y.length()) {
		return false;
	}

	// create an empty map
	unordered_map<int, int> freq;

	// maintain a count of each character of `X` on the map
	for (char x: X) {
		freq[x]++;
	}

	// do for each character `y` of `Y`
	for (char y: Y)
	{
		// if `y` is not found in the map, i.e., either `y` is not present
		// in string `X` or has more occurrences in string `Y`
		if (freq.find(y) == freq.end()) {
			return false;
		}

		// decrease the frequency of `y` on the map
		freq[y]--;

		// if its frequency becomes 0, erase it from the map
		if (!freq[y]) {
			freq.erase(y);
		}
	}

	// return true if the map becomes empty
	return !freq.size();
}

void test_anagram(string X, string Y){
	if (isAnagram(X, Y)) {
		cout << X << " - " << Y << ":  Anagram" << endl;
	}
	else {
		cout << "Not an Anagram" << endl;
	}
}

int main()
{
	string X = "tommarvoloriddle";		// Tom Marvolo Riddle
	string Y = "iamlordvoldemort";		// I am Lord Voldemort

	test_anagram(X,Y);

	X = "The meaning of life ";		
	Y = "The fine game of nil";		

	test_anagram(X,Y);

	return 0;
}