#pragma once
#define interface class
#include <vector>

namespace StoryViewer
{
	class Attribute;
	class Object;
	class Story;
	class StoryLine;
	class StoryEvent;
	class Character;
	class CharacterGroup;
	class Link;

	interface Attributable;
	interface Linkable;
	enum TYPE
	{
		ROOT = 0,
		STORY,
		STORY_LINE,
		STORY_EVENT,
		CHARACTER,
		CHARACTER_GROUP,
		ATTRIBUTE,
		LINK
	};

	unsigned int _identifier_pool = 0U;
	std::vector<Object*> _object_pool = std::vector<Object*>();

	class Object
	{
	private:
		unsigned int _New();
		virtual Object* _Push(); // IT MUST BE VIRTUAL!!!
		virtual void _Delete();
	public:
		unsigned int _identifier;
		TYPE type;
		Object();
		Object(TYPE);
		virtual ~Object();
	};

	interface Attributable
	{
	protected:
		std::vector<Attribute> attributes;
	public:
		Attributable();
		Attributable(std::vector<Attribute>&);
		Attributable(std::vector<Attribute>*);
		void Push(std::string&, std::string&);
		Attribute* Find(std::string&);
		void Delete(std::string&, bool);
	};
	class Story : public Object, public Attributable
	{
	protected:
		std::vector<Link> link;

	public:
		Story(std::vector<Link>, std::vector<Attribute>);
	};

	class StoryLine : public Object
	{
	protected:
		std::vector<Story> stories;
		std::vector<Attribute> attributes;

	public:
		StoryLine(std::vector<Story>, std::vector<Attribute>);
	};


	class Link : public Object
	{
	protected:
		Object* X, * Y;

	public:
		Link(Object*, Object*);
		virtual ~Link();
	};
	class Attribute : public Object
	{
	protected:
		std::string key, value;

	public:
		Attribute(std::string, std::string);
		virtual ~Attribute();
		std::string& Key();
		std::string& Value();
	};

}