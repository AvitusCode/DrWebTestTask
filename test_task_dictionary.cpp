#include <iostream>
#include <string>
#include <vector>

#include "dictImpl.h"

void TestDictionary()
{
	dictionary<std::string, std::string>* dictData = new dictionaryImpl<std::string, std::string>();
	std::vector<std::string> keys = {"map", "string", "vector"};
	std::vector<std::string> values = {"cat", "dog", "cow"};
	
	bool good_tests = true;
	using error_t = not_found_exception<std::string>;
	
	for (size_t i = 0; i < keys.size(); i++){
		dictData->set(keys[i], values[i]);
	}
	
	for (size_t i = 0; i < keys.size(); i++){
		if (!dictData->is_set(keys[i])){
			std::cerr << "ERROR: " << keys[i] << " is not in dict!" << std::endl;
			good_tests = false;
		}
	}
	
	try{
		dictData->get("vostok");
		good_tests = false;
	} 
	catch (const error_t &e){
		std::cerr << "This key does not exsist: "  << e.get_key() << std::endl;
	}
	
	if (good_tests)
		std::cerr << "Tests Ok" << std::endl;
	else
		std::cerr << "Tests error" << std::endl;
	
	delete dictData;
}

int main(void)
{
	TestDictionary();
	
	return 0;
}
