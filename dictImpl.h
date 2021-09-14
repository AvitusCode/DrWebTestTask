#pragma once
#include "dictInterface.h"
#include <map>
#include <string>
#include <vector>

template<typename Key, typename Value>
class dictionaryImpl : public dictionary<Key, Value>
{
public:
	dictionaryImpl() = default;
	
	const Value& get(const Key &key) const override
	{
		if (this->is_set(key)){
			return dict.at(key);
		} 
		else{
			throw KeyException(key);
		}
	}
	void set(const Key &key, const Value &value) override
	{
		if (!this->is_set(key)){
			dict[key] = value;
		} 
		else{
			throw KeyException(key);
		}
	}
	bool is_set(const Key &key) const override{
		return dict.count(key) > 0;
	}
	
	//We don't know anything about the data that the dictionary can accept. Therefore, there will be a default destructor
	~dictionaryImpl() = default;
	
class KeyException : public not_found_exception<Key>
{
public:
	KeyException(const Key& key) : _key(key) {};
	const Key& get_key() const noexcept override{
		return _key;
	}
	
private:
	Key _key;
};
	
private:
	std::map<Key, Value> dict;
};
