#pragma once
#include <iostream>

#define __ABSOLUTE_VIRTUAL_FUNCTION 0
#define __ABSTRACT_CLASS
#define __ENUM_DEFAULT_VALUE 0
#define __IDENTIFIER__
#define __BASIC_ATTRIB__
#define __BASIC_FUNC__
#define __SPECIAL_VALUE 0x3f
#define _MAKE_OBJECT_WITH_NAME(str) Object *str = new Object("str")

class __ABSTRACT_CLASS Object
{
protected:
    __BASIC_ATTRIB__ std::string Name;

public:
    explicit Object();
    virtual ~Object();
    Object(const Object &);
    Object(Object &&);
    virtual void Role() = 0;
};
