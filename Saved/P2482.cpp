#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
#define IS_K_CARD(a) (!strcmp(typeid(**a).name(), "6K_Card"))
#define IS_D_CARD(a) (!strcmp(typeid(**a).name(), "6D_Card"))

#define IS_WHAT_CARD(a, c) (!strcmp(typeid(**a).name(), ((string)"6"+(string)c).c_str())
class Pig;    //abstract,interface
class Game;   //main game,root
class Card;   //abstract,interface
class ZP;     //publique Pig
class MP;     //publique Pig
class FP;     //publique Pig
class P_Card; //Peach Card,publique Card
class K_Card; //Kill Card,publique Card
class D_Card; //Defense Card,publique Card
class F_Card; //Fight Card,publique Card
class N_Card; //Nan_Pig_Invasion Card,publique Card
class W_Card; //Wan_Arrow_together Card,publique Card

typedef vector<Card *> Card_Pool;
typedef vector<Pig *> Pig_Pool;

class Card //interface
{
public:
    virtual void Role(Game *g, Pig *user, Pig *enemy) = 0;
};
//杀
class K_Card : public Card // enemy is necessary.
{
public:
    virtual void Role(Game *g, Pig *user, Pig *enemy) override
    //!"virtual" is necessary.Without "virtual","typeid().name()" cannot work normally.
    {
        enemy->get_hurt(user);
        enemy->upperHurt = user;
    }
};
//桃
class P_Card : public Card
{
public:
    virtual void Role(Game *g, Pig *user, Pig *enemy) override
    {
        user->get_heal();
    }
};
//决斗
class F_Card : public Card
{
private:
    bool find_K(Pig *p)
    {
        for (Card_Pool::iterator playerIterator = p->Cards.begin();
             playerIterator != p->Cards.end();
             playerIterator++)
        {
            if (IS_K_CARD(playerIterator))
            {
                p->Cards.erase(playerIterator);
                return true;
            }
        }
        return false;
    }

public:
    virtual void Role(Game *g, Pig *user, Pig *enemy) override
    {
        while (true)
        {
            if (!find_K(user))
            {
                user->get_hurt(enemy);
                break;
            }
            if (!find_K(enemy))
            {
                enemy->get_hurt(user);
                break;
            }
        }
    }
};
//南猪入侵
class N_Card : public Card
{
private:
    bool find_K(Pig *p)
    {
        for (Card_Pool::iterator cardIterator = p->Cards.begin();
             cardIterator != p->Cards.end();
             cardIterator++)
        {
            if (IS_K_CARD(cardIterator))
            {
                p->Cards.erase(cardIterator);
                return true;
            }
        }
        return false;
    }

public:
    virtual void Role(Game *g, Pig *user, Pig *enemy) override
    {
        for (Pig_Pool::iterator playerIterator = g->Players.begin();
             playerIterator != g->Players.end();
             playerIterator++)
        {
            if (*playerIterator == user)
                continue;
            if (!find_K(*playerIterator))
            {
                (*playerIterator)->get_hurt(user);
            }
        }
    }
};
//万箭齐发
class W_Card : public Card
{
private:
    bool find_D(Pig *p)
    {
        for (Card_Pool::iterator cardIterator = p->Cards.begin();
             cardIterator != p->Cards.end();
             cardIterator++)
        {
            if (IS_D_CARD(cardIterator))
            {
                p->Cards.erase(cardIterator);
                return true;
            }
        }
        return false;
    }

public:
    virtual void Role(Game *g, Pig *user, Pig *enemy) override
    {
        for (Pig_Pool::iterator playerIterator = g->Players.begin();
             playerIterator != g->Players.end();
             playerIterator++)
        {
            if (*playerIterator == user)
                continue;
            if (!find_D(*playerIterator))
            {
                (*playerIterator)->get_hurt(user);
            }
        }
    }
};
//猪哥连弩
class Z_Card : public Card
{
public:
    virtual void Role(Game *g, Pig *user, Pig *enemy) override
    {
        user->getEquipment();
    }
};

class Game
{
private:
    Card_Pool Cards;

public:
    Pig_Pool Players;
    Game() {}
    ~Game()
    {
        for (Pig_Pool::iterator playerIterator = Players.begin();
             playerIterator != Players.end();
             playerIterator++)
        {
            delete *playerIterator;
        }
        for (Card_Pool::iterator cardIterator = Cards.begin();
             cardIterator != Cards.end();
             cardIterator++)
        {
            delete *cardIterator;
        }
    }
};

class Pig
{
protected:
    bool died;
    int strength;
    bool withEquipment;

public:
    Card_Pool Cards;
    Pig *upperHurt;
    virtual void show_friend(Pig *p) = 0;
    virtual void show_enemy(Pig *p) = 0;

    Pig() : died(false), strength(4), withEquipment(false)
    {
        Cards = Card_Pool();
    }
    Pig(Card_Pool &_Cards) : died(false), strength(4), withEquipment(false)
    {
        Cards = _Cards;
    }
    void getEquipment()
    {
        this->withEquipment = true;
    }
    virtual void get_hurt(Pig *source)
    {
        strength--;
        this->upperHurt = source;
        if (!strength)
        {
            for (Card_Pool::iterator playerIterator = Cards.begin();
                 playerIterator != Cards.end();
                 playerIterator++)
            {
                if (!strcmp(typeid(**playerIterator).name(), "6P_Card") && strength != 4)
                {
                    (*playerIterator)->Role(nullptr, this, nullptr);
                    Cards.erase(playerIterator);
                }
            }
        }
    }
    virtual void get_heal()
    {
        if (strength != 4)
            strength++;
    }
    virtual void getCard(Card_Pool &_Card_Pool)
    {
        if (!_Card_Pool.empty())
        {
            this->Cards.push_back(_Card_Pool.back());
            _Card_Pool.pop_back();
        }
        if (!_Card_Pool.empty())
        {
            this->Cards.push_back(_Card_Pool.back());
            _Card_Pool.pop_back();
        }
    }
};

class ZP : public Pig
{
public:
};

class MP : public Pig
{
public:
};

class FP : public Pig
{
public:
};