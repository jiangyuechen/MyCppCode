#include <iostream>
#include <vector>
#include "classes.h"

using namespace StoryViewer;

// Object START

unsigned int Object::_New()
{
	return ++_identifier_pool;
}
Object* Object::_Push() // IT MUST BE VIRTUAL!!!
{
	_object_pool.push_back(this);
	return this;
}

Object::Object()
{ // Invoked ONLY ONCE!!!
	type = TYPE::ROOT;
}
Object::Object(TYPE _type_)
{ // When creating new object
	this->_New();
	_Push();
	type = _type_;
}
Object::~Object() {}
// Object STOP


// Attributable START
Attributable::Attributable() : attributes() {}
Attributable::Attributable(std::vector<Attribute>& _attrib_) : attributes(_attrib_) {}
Attributable::Attributable(std::vector<Attribute>* _p_attrib_) : attributes(*_p_attrib_) {}
void Attributable::Push(std::string& _key_, std::string& _value_)
{
	attributes.push_back(Attribute(_key_, _value_));
}
Attribute* Attributable::Find(std::string& _key_)
{
	for (std::vector<Attribute>::iterator __atr = attributes.begin(); __atr != attributes.end(); ++__atr)
	{
		if (__atr->Key() == _key_)
		{
			return &(*__atr);
		}
	}
	return nullptr;
}
void Attributable::Delete(std::string& _key_, bool _multiple_ = false)
{
	for (std::vector<Attribute>::iterator __atr = attributes.begin(); __atr != attributes.end();)
	{
		if (__atr->Key() == _key_)
		{
			__atr = attributes.erase(__atr);
			if (!_multiple_)
				break;
		}
		else
		{
			__atr++;
		}
	}
}
// Attributable STOP


// Story START
Story::Story(std::vector<Link> _link_ = std::vector<Link>(), std::vector<Attribute> _attributes_ = std::vector<Attribute>()) : Object(TYPE::STORY) {}
// Story STOP

StoryLine::StoryLine(std::vector<Story> _stories_ = std::vector<Story>(), std::vector<Attribute> _attributes_ = std::vector<Attribute>()) : Object(TYPE::STORY_LINE),
stories(_stories_),
attributes(_attributes_)
{}


Link::Link(Object* _x_ = nullptr, Object* _y_ = nullptr) : Object(TYPE::LINK),
X(_x_),
Y(_y_)
{}
Link::~Link()
{
	X = nullptr;
	Y = nullptr;
	delete X, Y;
	/* Don't delete pointer X and Y!!!*/
}
Attribute::Attribute(std::string _key_ = "", std::string _value_ = "") : Object(TYPE::ATTRIBUTE),
key(_key_),
value(_value_)
{}
Attribute::~Attribute() {}
std::string& Attribute::Key() { return key; }
std::string& Attribute::Value() { return value; }
