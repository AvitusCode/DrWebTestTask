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
		auto result = dict.find(key);
		
		if (result == dict.end()){
			throw KeyException(key);
		}
		
		return result->second;
	}
	void set(const Key &key, const Value &value) override
	{
		dict[key] = value;
	}
	bool is_set(const Key &key) const override{
		return dict.count(key) > 0;
	}
	
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
