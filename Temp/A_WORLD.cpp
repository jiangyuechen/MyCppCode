//Ce n'est pas un programme,C'est un monde.
#include <cstdio>
#include <cstring>
#include <iostream>
#pragma region DEFINITIONS
#define __ABSOLUTE_VIRTUAL_FUNCTION 0
#define __ABSTRACT_CLASS
#define __ENUM_DEFAULT_VALUE 0
#define __IDENTIFIER__
#define __BASIC_ATTRIB__
#define __BASIC_FUNC__
#define __SPECIAL_VALUE 0x3f
#define _MAKE_OBJECT_WITH_NAME(str) Object *str = new Object("str")
#pragma endregion
#pragma region CLASSES_DEF
class Object;
class Reference;
class Being;
class Animal;
class Plant;
class Person;
class Virtual_Person;
class Real_Person;
class Person;
class Virtual_Person;
class Real_Person;
class Element;
class Event;
class Word;
#pragma endregion

namespace STD_ENUM
{
    enum Reference_Type __IDENTIFIER__
    {
        _DEFAULT = __ENUM_DEFAULT_VALUE,
        _OBVIOUS_REF,
        _HIDDEN_REF,
        _VIRTUAL_REF
    };
    enum Basic_Sex
    {
        _MALE = __ENUM_DEFAULT_VALUE,
        _FEMALE
    };

} // namespace STD_ENUM

class Object /* __ABSTRACT_CLASS */
{
protected:
    __BASIC_ATTRIB__ std::string Name;

public:
    Object() {}
    virtual ~Object() {}
    Object(std::string _Name)
    {
        Name = _Name;
    }
    __BASIC_FUNC__ std::string getName() const
    {
        return this->Name;
    }
};
class Reference : public Object
{
protected:
    Object *Ref;
    STD_ENUM::Reference_Type T;

public:
    Reference(bool setDefaultObject = false)
    {
        if (setDefaultObject)
            Ref = new Object();
        else
            Ref = nullptr;
    }
    Reference(std::string _Name, Object *_Ref, STD_ENUM::Reference_Type _T)
    {
    }
    ~Reference()
    {
        delete Ref;
        Ref = nullptr;
    }
    virtual Object *getRef() const
    {
        return Ref;
    }
    void setRef(Object *_Obj)
    {
        Ref = _Obj;
    }
    virtual void clearRef()
    {
        Ref = nullptr;
    }
};

class MainProgram : Object
{
private:
    long long a, b;

public:
    MainProgram() : a(0), b(0) {}
    ~MainProgram() {}
    void input()
    {
        std::cin >> a >> b;
    }
    void output() const
    {
        std::cout << a + b << std::endl;
        system("pause");
    }
};

int main()
{
    /*
    Reference *Amiya = new Reference(std::string("Amiya"), new Object("Amida"), STD_ENUM::_HIDDEN_REF);
    std::cout << Amiya->getRef()->getName() << std::endl;
    delete Amiya;
    system("pause");
    return 0;
    MainProgram *J_IGNITE = new MainProgram();
    J_IGNITE->input();
    J_IGNITE->output();
    delete J_IGNITE;
    return EXIT_SUCCESS;
    */
    _MAKE_OBJECT_WITH_NAME(Conviction);
    printf("%s\n", Conviction->getName().c_str());
    system("pause");
    return 0;
}