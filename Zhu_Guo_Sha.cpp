#include <bits/stdc++.h>
const int STRENGTH_MAX = 4;
#define CARD(c) c##_Card

class Pig;
class MP;
class ZP;
class FP;
class Game;
class Card;

class P_Card;
class K_Card;
class D_Card;
class F_Card;
class N_Card;
class W_Card;
class J_Card;
class Z_Card;

char CardType(Card &c)
{
    const char *tp = typeid(c).name();
    if (!strcmp(tp, "class P_Card"))
        return 'P';
    else if (!strcmp(tp, "class K_Card"))
        return 'K';
    else if (!strcmp(tp, "class D_Card"))
        return 'D';
    else if (!strcmp(tp, "class F_Card"))
        return 'F';
    else if (!strcmp(tp, "class N_Card"))
        return 'N';
    else if (!strcmp(tp, "class W_Card"))
        return 'W';
    else if (!strcmp(tp, "class J_Card"))
        return 'J';
    else if (!strcmp(tp, "class Z_Card"))
        return 'Z';
    else
        return ' ';
}
char PigType(Pig &c)
{
    const char *tp = typeid(c).name();
    if (!strcmp(tp, "class MP"))
        return 'M';
    else if (!strcmp(tp, "class ZP"))
        return 'Z';
    else if (!strcmp(tp, "class FP"))
        return 'F';
    else
        return ' ';
}

void Basic_Hurt(Pig &subject, Pig &enemy)
{
    enemy.get_strength()--;
    enemy.Damage_source = &subject;
}

int Count_Card(std::vector<Card> vct, char code)
{
    int ret = 0;
    for (int i = 0; i < vct.size() - 1; i++)
    {
        if (code == CardType(vct[i]))
            ret++;
    }
    return ret;
}

/**
 * @brief Remove the current type of card.
 * @param vct The operated card vector.
 * @param code The type which you want to remove.
 * @param remove_all Should this function remove just one card or all. Default is false (remove just one card.)
*/
void Remove_Card(std::vector<Card> &vct, char code, bool remove_all = false)
{
    for (auto it = vct.begin(); it != vct.end(); it++)
    {
        if (CardType(*it) == code)
        {
            vct.erase(it);
            if (!remove_all)
                return;
        }
    }
}

class Card
{
public:
    virtual void Role(Pig &subject, Pig &enemy) = 0;
};
class P_Card : public Card
{
public:
    virtual void Role(Pig &subject, Pig &enemy) override
    {
        if (subject.get_strength() < STRENGTH_MAX)
            subject.get_strength()++;
    }
};

class K_Card : public Card
{
public:
    virtual void Role(Pig &subject, Pig &enemy) override
    {
        Basic_Hurt(subject, enemy);
    }
};

class D_Card : public Card
{
public:
    virtual void Role(Pig &subject, Pig &enemy) override
    {
        subject.get_strength()++;
    }
};

class F_Card : public Card
{
public:
    virtual void Role(Pig &subject, Pig &enemy) override
    {
        int card_of_subject = Count_Card(subject.get_card(), 'K');
        int card_of_enemy = Count_Card(enemy.get_card(), 'K');
        while (1)
        {
            Remove_Card(enemy.get_card(), 'K');
            card_of_enemy--;
            if (!card_of_enemy)
            {
                Basic_Hurt(subject, enemy);
                return;
            }
            Remove_Card(subject.get_card(), 'K');
            card_of_subject--;
            if (!card_of_subject)
            {
                Basic_Hurt(enemy, subject);
                return;
            }
        }
    }
};
class N_Card : public Card
{
public:
    virtual void Role(Pig &subject, Pig &enemy) override
    {
        int mod = Game::remain_player();
        int now = (subject.order + 1) % mod;
        while (now % mod != subject.order)
        {
            if (!Count_Card(Game::Player[now % mod].get_card(), 'K'))
                Basic_Hurt(subject, Game::Player[now % mod]);
            else
                Remove_Card(Game::Player[now % mod].get_card(), 'K');
        }
    }
};
class W_Card : public Card
{
public:
    virtual void Role(Pig &subject, Pig &enemy) override
    {
        int mod = Game::remain_player();
        int now = (subject.order + 1) % mod;
        while (now % mod != subject.order)
        {
            if (!Count_Card(Game::Player[now % mod].get_card(), 'D'))
                Basic_Hurt(subject, Game::Player[now % mod]);
            else
                Remove_Card(Game::Player[now % mod].get_card(), 'D');
        }
    }
};
class J_Card : public Card
{
};
class Z_Card : public Card
{
    virtual void Role(Pig &subject, Pig &enemy) override
    {
        subject.equipment = true;
    }
};
class Game
{
private:
    static void remake_order()
    {
        for (int i = 0; i < Player.size(); i++)
            Player[i].order = i;
    }

public:
    static std::vector<Card> Pool;
    static std::vector<Pig> Player;
    static int nowPlayer;
    static int remain_player() { return Player.size(); }
    static int get_dist(int x, int y) { return x < y ? y - x : remain_player() - (x - y); }
};

class Pig
{
protected:
    int Strength;
    std::vector<Card> Cards;

public:
    int order;
    bool equipment;
    Pig *Damage_source;
    Pig(int _order, char init_card[4])
    {
        order = _order;
        equipment = false;
        Strength = STRENGTH_MAX;
        Damage_source = nullptr;
        for (int i = 0; i < 4; i++)
        {
            switch (init_card[i])
            {
            case 'P':
                Cards.push_back(P_Card());
                break;

            default:
                break;
            }
        }
    }
    int &get_strength() { return Strength; }
    std::vector<Card> &get_card() { return Cards; }
};