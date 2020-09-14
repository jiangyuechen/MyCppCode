#include <Windows.h>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

#ifndef ARKNIGHTS_CARD_PLAY
#define ARKNIGNTS_CARD_PLAY

#define THREE_STAR 16
#define FOUR_STAR 29
#define FIVE_STAR 41
#define SIX_STAR 22

#define ALL (THREE_STAR + FOUR_STAR + FIVE_STAR + SIX_STAR)

enum Type
{
	Vanguard = 1,
	Sniper,
	Guard,
	Caster,
	Defender,
	Medic,
	Specialist,
	Supporter
};
//若class不可使用，请改为struct，并去掉“public:”。
class agent
{
public:
	int star;
	const char *name;
	Type type;
	agent(const char *, Type, int);
	void output();
};

//“干员”初始化
agent a[ALL] = {
	/*先锋00*/ agent("翎羽", Vanguard, 3), agent("芬", Vanguard, 3), agent("香草", Vanguard, 3), agent("清道夫", Vanguard, 4), agent("红豆", Vanguard, 4), /* agent("讯使",Vanguard,4),*/ agent("桃金娘", Vanguard, 4), agent("凛冬", Vanguard, 5), agent("德克萨斯", Vanguard, 5), /*agent("格拉尼",Vanguard,5),*/ agent("苇草", Vanguard, 5), agent("推进之王", Vanguard, 6), agent("风笛", Vanguard, 6),
	/*狙击11*/ agent("克洛丝", Sniper, 3), /*agent("安德切尔",Sniper,3),*/ agent("空爆", Sniper, 3), agent("杰西卡", Sniper, 4), agent("梅", Sniper, 4), agent("流星", Sniper, 4), agent("白雪", Sniper, 4), agent("红云", Sniper, 4), agent("安比尔", Sniper, 4), agent("送葬人", Sniper, 5), agent("守林人", Sniper, 5), agent("普罗旺斯", Sniper, 5), agent("白金", Sniper, 5), agent("蓝毒", Sniper, 5), agent("陨星", Sniper, 5), agent("灰喉", Sniper, 5), agent("慑砂", Sniper, 5), agent("能天使", Sniper, 6), agent("黑", Sniper, 6),
	/*近卫29*/ agent("玫兰莎", Guard, 3), agent("月见夜", Guard, 3), agent("泡普卡", Guard, 3), agent("慕斯", Guard, 4), agent("杜宾", Guard, 4), agent("猎蜂", Guard, 4), agent("缠丸", Guard, 4), /*agent("艾丝黛尔",Guard,4),*/ agent("霜叶", Guard, 4), agent("宴", Guard, 4), /* agent("因陀罗",Guard,5),*/ agent("幽灵鲨", Guard, 5), agent("拉普兰德", Guard, 5), /* agent("暴行",Guard,5),*/ agent("芙兰卡", Guard, 5), agent("诗怀雅", Guard, 5), agent("星极", Guard, 5), /*agent("炎客",Guard,5),*/ agent("布洛卡", Guard, 5), /*agent("柏喙",Guard,5),*/ agent("陈", Guard, 6), agent("银灰", Guard, 6), agent("斯卡蒂", Guard, 6), agent("赫拉格", Guard, 6), agent("煌", Guard, 6),
	/*术师49*/ agent("史都华德", Caster, 3), agent("炎熔", Caster, 3), agent("夜烟", Caster, 4), agent("远山", Caster, 4), agent("格雷伊", Caster, 4), agent("夜魔", Caster, 5), agent("天火", Caster, 5), agent("惊蛰", Caster, 5), /*agent("阿米娅",Caster,5),*/ agent("伊芙利特", Caster, 6), agent("艾雅法拉", Caster, 6), agent("莫斯提马", Caster, 6), agent("刻俄柏", Caster, 6),
	/*重装61*/ agent("卡缇", Defender, 3), agent("米格鲁", Defender, 3), agent("斑点", Defender, 3), agent("古米", Defender, 4), agent("蛇屠箱", Defender, 4), /*agent("坚雷",Defender,4),*/ agent("角峰", Defender, 4), agent("临光", Defender, 5), agent("可颂", Defender, 5), /* agent("火神",Defender,5),*/ /*agent("拜松",Defender,5),*/ agent("雷蛇", Defender, 5), agent("吽", Defender, 5), agent("石棉", Defender, 5), agent("塞雷娅", Defender, 6), agent("星熊", Defender, 6), /*agent("年",Defender,6),*/
	/*医疗73*/ agent("安赛尔", Medic, 3), agent("芙蓉", Medic, 3), /*agent("嘉维尔",Medic,4),*/ agent("末药", Medic, 4), agent("调香师", Medic, 4), agent("苏苏洛", Medic, 4), /*agent("清流",Medic,4),*/ /*agent("微风",Medic,5),*/ agent("华法琳", Medic, 5), agent("白面鸮", Medic, 5), agent("赫默", Medic, 5), /*agent("锡兰",Medic,5),*/ agent("夜莺", Medic, 6), agent("闪灵", Medic, 6),																						  /*agent("凯尔希",Medic,6),*/
	/*特种83*/ agent("暗索", Specialist, 4), agent("砾", Specialist, 4), agent("阿消", Specialist, 4), /* agent("伊桑",Specialist,4),*/ /* agent("断罪者",Specialist,4),*/ agent("崖心", Specialist, 5), agent("狮蝎", Specialist, 5), agent("红", Specialist, 5), agent("槐琥", Specialist, 5), agent("食铁兽", Specialist, 5), /*agent("雪雉",Specialist,5),*/ agent("阿", Specialist, 6), agent("傀影", Specialist, 6), agent("温蒂", Specialist, 6),
	/*辅助92*/ agent("梓兰", Supporter, 3), agent("地灵", Supporter, 4), agent("深海色", Supporter, 4), agent("初雪", Supporter, 5), agent("梅尔", Supporter, 5), agent("真理", Supporter, 5), agent("空", Supporter, 5), agent("格劳克斯", Supporter, 5), agent("巫恋", Supporter, 5), agent("月禾", Supporter, 5), agent("稀音", Supporter, 5), agent("麦哲伦", Supporter, 6), agent("安洁莉娜", Supporter, 6)};
int main()
{
	srand(time(0));
start:
	int total, p;
	int n_3 = 0, n_4 = 0, n_5 = 0, n_6 = 0;
	cout << "想要多少个？" << endl;
	cin >> total;
	int r = total + 1;
	while (total != 0)
	{
		Sleep(10);
		p = rand() % 100;
		cout << r - total;
		if (p >= 0 && p < 40)
		{
			int k = rand() % THREE_STAR;
			for (int i = 0; i < 105; i++)
			{
				if (a[i].star == 3)
					k--;
				if (k == -1)
				{
					a[i].output();
					break;
				}
			}
			n_3++;
		}
		else if (p >= 40 && p < 90)
		{
			int k = rand() % FOUR_STAR;
			for (int i = 0; i < 105; i++)
			{
				if (a[i].star == 4)
					k--;
				if (k == -1)
				{
					a[i].output();
					break;
				}
			}
			n_4++;
		}
		else if (p >= 90 && p < 98)
		{
			int k = rand() % FIVE_STAR;
			for (int i = 0; i < 105; i++)
			{
				if (a[i].star == 5)
					k--;
				if (k == -1)
				{
					a[i].output();
					break;
				}
			}
			n_5++;
		}
		else if (p >= 98 && p <= 99)
		{
			int k = rand() % SIX_STAR;
			for (int i = 0; i < 105; i++)
			{
				if (a[i].star == 6)
					k--;
				if (k == -1)
				{
					a[i].output();
					break;
				}
			}
			n_6++;
		}
		total--;
	}
	r--;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	printf("三星爆率：%.4lf（%d个）\n四星爆率：%.4lf（%d个）\n五星爆率：%.4lf（%d个）\n六星爆率：%.4lf（%d个）\n", (double)n_3 / r, n_3, (double)n_4 / r, n_4, (double)n_5 / r, n_5, (double)n_6 / r, n_6);
	if (n_5 == 0 && n_6 == 0 && r == 10)
	{
		cout << "@ 紫气东来 @" << endl;
	}
	else if (n_6 == 1 && r == 1)
	{
		cout << "@ 单抽之王 @" << endl;
	}
	else if (n_5 == 1 && r == 10 && n_6 == 0)
	{
		cout << "@ 完美保底 @" << endl;
	}
	else if (n_6 == 2 && r == 10)
	{
		cout << "@ 双黄蛋 @" << endl;
	}
	else if (n_6 > 2 && r == 10)
	{
		cout << "@ 超级欧皇 @" << endl;
	}
	cout << "还来吗？(输入0退出）" << endl;
	int isNext;
	cin >> isNext;
	if (isNext)
	{
		system("cls");
		goto start;
	}
	else
	{
		return 0;
	}
}

agent::agent(const char *n, Type t, int s)
{
	this->star = s;
	this->name = n;
	this->type = t;
}

void agent::output()
{
	switch (star)
	{
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED);
		break;
	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 6:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		break;
	}
	cout << this->name;
	cout << " ";
	for (int i = 0; i < this->star; i++)
	{
		cout << "★";
	}
	cout << " ";
	switch (this->type)
	{
	case 1:
		cout << "先锋";
		break;
	case 2:
		cout << "狙击";
		break;
	case 3:
		cout << "近卫";
		break;
	case 4:
		cout << "术师";
		break;
	case 5:
		cout << "重装";
		break;
	case 6:
		cout << "医疗";
		break;
	case 7:
		cout << "特种";
		break;
	case 8:
		cout << "辅助";
		break;
	default:
		break;
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	return;
}

#endif