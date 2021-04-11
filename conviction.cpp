#include <windows.h>

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
template <typename TResult>
class Func {
   private:
    TResult (*f)();

   public:
    Func() { f = nullptr; }
    Func(TResult (*_f)()) : f(_f) {}
    TResult operator()() { return f(); }
};

template <typename TResult, typename T1>
class Func {
   private:
    TResult (*f)(T1);

   public:
    Func() { f = nullptr; }
    Func(TResult (*_f)(T1)) : f(_f) {}
    TResult operator()(T1 _1) { return f(_1); }
};

template <typename TResult, typename T1, typename T2>
class Func {
   private:
    TResult (*f)(T1, T2);

   public:
    Func() { f = nullptr; }
    Func(TResult (*_f)(T1, T2)) : f(_f) {}
    TResult operator()(T1 _1, T2 _2) { return f(_1, _2); }
};

class Action {
   private:
    void (*f)();

   public:
    Action() { f = nullptr; }
    Action(void (*_f)()) : f(_f) {}
    void operator()() { f(); }
};

int x() { return 1; }

int main(void) { (Func<int>(x))(); }