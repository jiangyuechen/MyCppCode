#include <cstdio>

namespace Maker
{
    typedef unsigned int uit;
    bool __sp;
    uit __x, __y, __z;
    int __type, __k, __m;
    const int L = 1 << 21;
    char buf[L], *front = buf, *end = buf;
    char GetChar()
    {
        if (front == end)
        {
            end = buf + fread(front = buf, 1, L, stdin);
            if (front == end)
                return -1;
        }
        return *(front++);
    }
    template <typename T>
    inline void qr(T &x)
    {
        char ch = GetChar(), lst = ' ';
        while ((ch > '9') || (ch < '0'))
            lst = ch, ch = GetChar();
        while ((ch >= '0') && (ch <= '9'))
            x = (x << 1) + (x << 3) + (ch ^ 48), ch = GetChar();
        if (lst == '-')
            x = -x;
    }
    template <typename T>
    inline void Begin(const T &x)
    {
        __type = x % 10;
        qr(__x);
        qr(__y);
        qr(__z);
        qr(__m);
        __sp = (__type == 3) || (__type == 4);
        __type &= 1;
    }
    inline uit __Next_Integer()
    {
        __x ^= __y << (__z & 31);
        __y ^= __z >> (__x & 31);
        __z ^= __x << (__y & 31);
        __x ^= __x >> 5;
        __y ^= __y << 13;
        __z ^= __z >> 6;
        return __x;
    }
    inline uit Rand() { return __Next_Integer(); }
    template <typename Tx, typename Ty, typename Tz>
    inline void Get_Nextline(Tx &x, Ty &y, Tz &z)
    {
        if (__m)
        {
            --__m;
            x = 0;
            y = 0;
            z = 0;
            qr(x);
            qr(y);
            qr(z);
            if (x == 0)
                ++__k;
        }
        else
        {
            x = Rand() & 1;
            y = Rand() & 1;
            if (__k == 0)
                x = 0;
            if (x == 0)
            {
                ++__k;
                if (__sp)
                    z = __type;
                else
                    z = Rand() & 1;
            }
            else
            {
                int dk = __k >> 1;
                if (dk == 0)
                    z = 1;
                else
                    z = Rand() % dk + dk;
            }
        }
    }
} // namespace Maker