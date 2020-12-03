#include <bits/stdc++.h>
#include <cstring>
const int STRENGTH_MAX = 4;
#define CARD(c) c##_Card
#define extends : public
#define MOD(x) (x % Game::remain_player())

#define NXT_PLAYER(x) Game::Player[MOD(x->order + 1)]
#define PRV_PLAYER(x) Game::Player[MOD(x->order - 1)]

#define ROLL(subject, mod, now)           \
    int mod = Game::remain_player();      \
    int now = (subject->order + 1) % mod; \
    while (now % mod != subject->order)

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
class Behavior;

void show_friend(Pig *subject, Pig *object)
{
    if (object->shown == true && PigType(*object) == 'P')
    {
    }
}

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

void Basic_Hurt(Pig *subject, Pig *enemy)
{
    enemy->get_strength()--;
    enemy->Damage_source = subject;
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
    virtual bool Role(Pig *subject, Pig *enemy) = 0;
};
class P_Card extends Card // Tao
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
        if (subject->get_strength() < STRENGTH_MAX)
        {
            subject->get_strength()++;
            return true;
        }
        else
            return false;
    }
};

class K_Card extends Card // Sha
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
        SHOW_ENEMY(subject);
        Basic_Hurt(subject, enemy);
        return true;
    }
};

class D_Card extends Card // Shan
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
        subject->get_strength()++;
        return true;
    }
};

class F_Card extends Card // Jue Dou
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
        if (PigType(*subject) == 'M')
        {
            Basic_Hurt(subject, enemy);
            return true;
        }
        int card_of_subject = Count_Card(subject->get_card(), 'K');
        int card_of_enemy = Count_Card(enemy->get_card(), 'K');
        while (1)
        {
            Remove_Card(enemy->get_card(), 'K');
            card_of_enemy--;
            if (!card_of_enemy)
            {
                Basic_Hurt(subject, enemy);
                return true;
            }
            Remove_Card(subject->get_card(), 'K');
            card_of_subject--;
            if (!card_of_subject)
            {
                Basic_Hurt(enemy, subject);
                return true;
            }
        }
    }
};
class N_Card extends Card
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
        ROLL(subject, mod, now)
        {
            Pig &Now = Game::Player[MOD(now)];
            if (!Count_Card(Now.get_card(), 'K'))
            {
                Basic_Hurt(subject, &Now);
                if (PigType(Now) == 'M')
                    subject->likely_shown = true;
            }
            else
                Remove_Card(Now.get_card(), 'K');
        }
    }
};
class W_Card extends Card
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
        ROLL(subject, mod, now)
        {
            Pig &Now = Game::Player[MOD(now)];
            if (!Count_Card(Now.get_card(), 'D'))
            {
                Basic_Hurt(subject, &Now);
                if (PigType(Now) == 'M')
                    subject->likely_shown = true;
            }
            else
                Remove_Card(Now.get_card(), 'D');
        }
        return true;
    }
};
class J_Card extends Card
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
    }
};
class Z_Card extends Card
{
public:
    virtual bool Role(Pig *subject, Pig *enemy) override
    {
        subject->equipment = true;
        return true;
    }
};
class Game
{
private:
    static void remake_code()
    {
        for (int i = 0; i < Player.size(); i++)
            Player[i].order = i;
    }
    static int n, m;
    static bool living[20];

public:
    static std::vector<Card> Pool;
    static std::vector<Pig> Player;
    static int nowPlayer;
    static int remain_player() { return Player.size(); }
    static int get_dist(int x, int y) { return x < y ? y - x : remain_player() - (x - y); }
    static void init()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            std::string cmd;
            std::getline(std::cin, cmd);
            std::vector<char> _init_card{cmd[3], cmd[5], cmd[7], cmd[9]};
            switch (cmd[0])
            {
            case 'M':
                Player.push_back(MP(i, _init_card));
                break;
            case 'F':
                Player.push_back(FP(i, _init_card));
                break;
            case 'Z':
                Player.push_back(ZP(i, _init_card));
                break;
            default:
                break;
            }
        }
        std::string cmd;
        std::getline(std::cin, cmd);
        for (int i = 0; i < cmd.length(); i += 2)
        {
            switch (cmd[i])
            {
            }
        }
    }
    static bool finished()
    {
        return false;
    }
    static std::string output()
    {
    }
    static void update()
    {
        Game::Player[nowPlayer].update();
        if (Game::Player[nowPlayer].get_strength() <= 0)
        {
            Game::Player.erase(Game::Player.begin() + nowPlayer);
            Game::remake_code();
        }
        nowPlayer++;
    }
};

class Pig
{
protected:
    int Strength;

    std::vector<Card> Cards; // 手牌。注意：从右边插入，从左边删除。

public:
    int code;           // 原来的编号
    int order;          // 死了一些猪以后的编号
    bool equipment;     // 是否装备猪哥连弩
    bool shown;         // 是否已经跳忠 / 跳反
    bool likely_shown;  // 是否是类反猪
    Pig *Damage_source; // 最后一个伤害来源处
    /**
     * @brief 猪的构造函数。
     * @param _code 一开始分配的次序。
     * @param init_card 一开始的四张牌。
    */
    Pig(int _code, std::vector<char> init_card) : code(_code), equipment(false), Strength(STRENGTH_MAX), Damage_source(nullptr)
    {

        for (int i = 0; i < 4; i++)
        {
            switch (init_card[i])
            {
            case 'P':
                Cards.push_back(P_Card());
                break;
            case 'K':
                Cards.push_back(K_Card());
                break;
            case 'D':
                Cards.push_back(D_Card());
                break;
            case 'F':
                Cards.push_back(F_Card());
                break;
            case 'N':
                Cards.push_back(N_Card());
                break;
            case 'W':
                Cards.push_back(W_Card());
                break;
            case 'J':
                Cards.push_back(J_Card());
                break;
            case 'Z':
                Cards.push_back(Z_Card());
                break;
            default:
                break;
            }
        }
    }
    /**
     * @brief 检查猪是否已经死亡。即体力是否小于等于0。
     * @return 死亡 -> true ，没死 -> false.
    */
    virtual bool died() const { return this->Strength <= 0; }
    /**
     * @brief 获取猪的体力。
     * @return 猪的体力的 @e 引用。
    */
    virtual int &get_strength() { return Strength; }
    /**
     * @brief 获取猪的卡牌。
     * @return 猪的卡牌的 @e 引用。
    */
    virtual std::vector<Card> &get_card() { return Cards; }
    /**
     * @brief 猪的出牌、摸排。
     * @todo 1.摸排（4张）
     * @todo 2.出牌。
    */
    virtual void update()
    {
        // 摸牌
        for (int i = 1; i <= 2; i++)
        {
            Cards.push_back(Game::Pool.back());
            Game::Pool.pop_back();
        }
        for (auto it = Cards.begin(); it != Cards.end(); it++)
        {
            if ((*it).Role(this))
            {
            }
        }
    }
    virtual int distanceTo(Pig &p) const { return Game::get_dist(this->order, p.order); }
};

class FP extends Pig // Fan Zhu
{
public:
    FP(int _code, std::vector<char> init_card) : Pig::Pig(_code, init_card) {}
};

class MP extends Pig // Zhu zhu
{
public:
    MP(int _code, std::vector<char> init_card) : Pig::Pig(_code, init_card) {}
};

class ZP extends Pig // Zhong zhu
{
public:
    ZP(int _code, std::vector<char> init_card) : Pig::Pig(_code, init_card) {}
};

int main()
{
    Game::init();
    while (!Game::finished())
    {
        Game::update();
    }
    Game::output();
    return 0;
}