// This example illustrates how to work with sets, pairs, tuples, and maps

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <utility>
#include <iterator>

int main(int argc, char* argv[])
{
	std::pair<int, std::string> p1 (5, "test string" );
	std::pair<int, std::string> p2 = { 5, "test string" };
	std::set<int> s1;

	for (int i = 100; i > 0; --i)
	{
		std::pair<std::set<int>::iterator, bool> result = s1.insert(i);
		std::cout << "i: " << i << " " << *(s1.find(i)) << std::endl;
		std::cout << "res: " << *(std::get<0>(result)) << std::endl;
		std::cout << "res bool: " << std::get<1>(result) << std::endl;
	}

	std::pair<std::set<int>::iterator, bool> result = s1.insert(66);
	//std::cout << "i: " << i << " " << *(s1.find(i)) << std::endl;
	std::cout << "res: " << *(std::get<0>(result)) << std::endl;
	std::cout << "res bool: " << std::get<1>(result) << std::endl;

	for (auto it = s1.begin ();  it != s1.end (); ++it)
	{
		std::cout << "e: " << *it << std::endl;
	}

	std::cout << p1.first << " " << p1.second << std::endl;
	std::cout << p2.first << " " << p2.second << std::endl;

	std::tuple<int, std::pair<int, std::string>> t1 = { 122, {121, "andy"} };
	std::cout << "1st element " << std::get<0>(t1) << std::endl;
	std::cout << "2nd element " << std::get<1>(t1).first << std::endl;
	std::cout << "3rd element " << std::get<1>(t1).second << std::endl;

	std::tuple<int, int, std::string> t2 = {1, 2, "bill rodgers"};
	std::cout << "1st element " << std::get<0>(t2) << std::endl;
	std::cout << "2nd element " << std::get<1>(t2) << std::endl;
	std::cout << "3rd element " << std::get<2>(t2) << std::endl;

	auto t3 = std::make_tuple("CptS", 355, 3 , "Fall", 2022);
	auto t4 = std::make_tuple("CptS", 223, 3 , "Spring", 2023);
	
	std::string major, semester; 
	int coursenum, credits, year;
	std::tie (major, coursenum, credits, semester, year) = t3;     // unpack elements
	std::cout << major << " - " << coursenum << " - " << credits << " - " << semester << " - " << year << std::endl;

  	std::tie (major, coursenum, std::ignore, std::ignore, year) = t4;  // unpack (with ignore)
	std::cout << major << " - " << coursenum << " - " << credits << " - " << semester << " - " << year << std::endl;


	std::map<std::string, double> salaries;
	
	salaries["Pat"] = 75000.00;
	std::cout << salaries["Pat"] << std::endl;
	std::cout << salaries["Jan"] << std::endl;
	
	std::map<std::string, double>::const_iterator itr;
	itr = salaries.find("Chris");
	if (itr == salaries.end())
		std::cout << "Not an employee of this company!" << std::endl;
	else
		std::cout << itr->second << std::endl;

	//t2.

	//std::set<


	return 0;
}