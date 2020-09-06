//by JiangXingchen
//源码较为混乱，请见谅 
#include<iostream>
#include<cstdio>
using namespace std;
void characterall();
void play();
void characterneed(char a)
{
	char b,c;
	if(a=='1')
	{
	    cout<<"住在东京中心的男高中生。每天和朋友们愉快地度日。"<<endl;
	    cout<<endl;
	    cout<<"在一家意式餐厅打工。"<<endl;
	    cout<<endl;
	    cout<<"对同僚奥寺前辈怀有好感。对建筑和美术很感兴趣。"<<endl;
	    cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl; 
    }
	if(a=='2')
	{
	    cout<<"住在深山乡间小町糸守町的女高中生。"<<endl;
	    cout<<endl;
		cout<<"身为糸守町长的父亲离家在外。"<<endl;
		cout<<endl;
		cout<<"和还是小学生的妹妹以及祖母三个人生活。"<<endl;
		cout<<endl;
		cout<<"性格直率，对家族神社的风俗和父亲的选举活动等事情感到反感。"<<endl;
		cout<<endl;
		cout<<"和朋友们对这狭小的城镇叹息，憧憬着东京的华丽生活。"<<endl;
		cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
		{
		    cout<<"拜拜咯"<<endl;
		    exit(0);
		}
	    
    }
	if(a=='3')
	{
		cout<<"三叶的同级生。青梅竹马般的好友。"<<endl;
		cout<<endl;
		cout<<"文静且有常识。对敕使河原有好感。"<<endl;
		cout<<endl;
		cout<<"姐姐在市政厅担当广播员。"<<endl;
		cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl;
	}
	if(a=='4')
	{
		cout<<"三叶的妹妹。"<<endl;
		cout<<endl;
		cout<<"可靠的时下小学四年生。与祖母和三叶一起帮忙神社的家业。"<<endl;
		cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl;
	}
	if(a=='5')
	{
		cout<<"泷的打工前辈。"<<endl;
		cout<<endl;
		cout<<"打扮漂亮的女大学生，包括泷在内的男性们的憧憬。"<<endl;
		cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl;
	}
	if(a=='6')
	{
		cout<<"三叶的祖母。宫水神社现任神主"<<endl;
		cout<<endl;
		cout<<"自己的女儿、三叶的母亲亡故，三叶的父亲离开家后"<<endl;
		cout<<endl;
		cout<<"独自一人抚养三叶和四叶长大。"<<endl;
		cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl;
	}
	if(a=='7')
	{
	    cout<<"三叶的同级生。神秘的机械宅。"<<endl;
		cout<<endl;
		cout<<"对在当地从事建筑业的父亲抱着复杂的心情。"<<endl;
		cout<<endl;
		cout<<"对三叶的事情很在意。对早耶香有好感"<<endl;
		cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl;
	}
	if(a=='8')
	{
	    cout<<"泷在高中的朋友。"<<endl;
	    cout<<endl;
		cout<<"虽然外表冷淡却意外地很爱照顾人。"<<endl;
	    cout<<endl;
		cout<<"和泷同样对建筑感兴趣。"<<endl;
	    cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl;
	}	
	if(a=='9')
	{
		cout<<"泷的同级生。"<<endl;
		cout<<endl;
		cout<<"身材高大却有直爽的性格。"<<endl;
		cout<<endl;
		cout<<"常与泷和司一起下课后到咖啡店去。"<<endl;
		cout<<endl;
	    cout<<"输入 c回到人物简介，输入 p开始游戏，输入 n退出"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"拜拜咯"<<endl;
	}
}
void characterall()
{
    system("cls");
	char a,b;
	cout<<"1.立花泷"<<endl;
	cout<<endl;	
	cout<<"2.宫水三叶"<<endl;
	cout<<endl;
	cout<<"3.名取早耶香"<<endl;
	cout<<endl;
	cout<<"4.宫水四叶"<<endl;
	cout<<endl;
	cout<<"5.奥寺美纪"<<endl;
	cout<<endl;
	cout<<"6.宫水一叶"<<endl;
	cout<<endl;
	cout<<"7.敕使河原克彦"<<endl;
	cout<<endl;
	cout<<"8.藤井司"<<endl;
	cout<<endl;
	cout<<"9.高木真太"<<endl;
	cout<<endl;
	cout<<"输入相应编号即可查看人物简介，输入 p退出到选择界面，输入 n退出"<<endl;
	b=getchar();a=getchar();
	if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')
	characterneed(a);
	if(a=='p')
	play();
	if(a=='n')
	{
		cout<<"拜拜咯"<<endl;
		exit(0);
	}
	else 
	characterall();
}
void outw();
void playw();
void playw2();
void playw2_5()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____“这是大人之间的问题！”"<<endl;
	cout<<"键入2____Emmmmmm...我红了脸"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"“这是大人之间的问题！”"<<endl;
	    cout<<endl;
		cout<<"我斩钉截铁地说道"<<endl;
		cout<<endl;
	}
	if(a=='2')
	{
		cout<<"我红了脸，但转念一想，哼！"<<endl;
		cout<<endl; 
		cout<<"“小孩子才不懂呢！”我斩钉截铁地说道"<<endl;
		cout<<endl;
	}
	if(a!='2'&&a!='1')
	{
		playw2_5();
	}
}
void findw1()
{
	system("cls");
	char b; 
	cout<<"要继续吗？还是结束？"<<endl;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"输入 c继续下一章游戏"<<endl; 
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"输入 p进入游戏主页面"<<endl; 
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"输入 r进入选择章节模式"<<endl;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"输入 n离开"<<endl;	
	b=getchar();
	if(b=='p')
	play();
	if(b=='c')
	playw2();
	if(b=='r')
	playw();
	if(b=='n')
	outw();
	if(b!='p'&&b!='c'&&b!='r'&&b!='n')
	findw1();
}
void playw1_1()
{
	char a,b;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____起床"<<endl;
	cout<<"键入2____再睡一会"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	b=getchar();
	if(b=='1')
	{
	    cout<<"清晨的阳光洒满整个屋子"<<endl;
		a=getchar();
	    if(a=='\n')
	    a=getchar();
	    if(a=='\n')
		cout<<"突然间我睁开双眼"<<endl;
	} 
	if(b=='2')
	{
		cout<<"还是先睡一会吧"<<endl;
	    a=getchar();
	    if(a=='\n')
	    a=getchar();
	    if(a=='\n')
	    cout<<"zzz(。-ω-)zzz"<<endl;
	    a=getchar();
     	if(a=='\n')
	    cout<<"“啊”~"<<endl;
	    a=getchar();
     	if(a=='\n')
	    cout<<"我睁开朦胧的双眼"<<endl;
	} 
	if(b!='2'&&b!='1')
	{
		playw1_1();
	}
}
void play();
void playw2_1()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____“明天我来做饭就好了呗”"<<endl;
	cout<<"键入2____“？就这？”"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	cout<<"“明天我来做饭就好了呗”，我没有道歉而是如是说道。"<<endl;
	if(a=='2')
	cout<<"“？就这？”，我没有道歉而是如是说道。" <<endl; 
	if(a!='2'&&a!='1')
	{
		playw2_1();
	}
}
void playw2_2()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____把饭倒回去一点"<<endl;
	cout<<"键入2____算了，吃多吃少都一样"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"那我把饭倒回去一点叭QAQ"<<endl;
	    cout<<endl;
		cout<<"好烫啊，盛到手上了，淦！"<<endl;
	    char b; 
		b=getchar();
	    if(b=='\n')
	    {
	        cout<<endl;
	        cout<<"气死了，哼╭(╯^╰)╮"<<endl;
	}
	}
	if(a=='2')
	{
		cout<<"多了又怎样，老娘都能吃！"<<endl;
		cout<<endl; 
	}
	if(a!='2'&&a!='1')
	{
		playw2_2();
	}
}
void outw()
{
	cout<<"~~再见三叶，下次再见咯~~"; 
}
void playw1()
{
	system("cls");
	char a;
	a=getchar();
	if(a=='\n') 
	cout<<"令人感怀的声音与味道，舒适治愈的光芒与温度"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"我正和某位重要的人紧紧挨在一起，仿佛永远不会分离"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"我就像个依偎在母亲胸前吃奶的婴孩，既无不安，也不会感到寂寞"<<endl; 
	a=getchar();
	if(a=='\n') 
	cout<<"我还不曾失去什么，可以随意撒娇，无比放松"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"应该是早上了吧？"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"是不是该起床了？"<<endl;
	playw1_1();
	a=getchar();
	if(a=='\n')
	cout<<"天花板"<<endl;
    a=getchar();
	if(a=='\n')  
	cout<<"房间，清晨"<<endl;
	a=getchar();
	if(a=='\n')  
	cout<<"形单影只"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"东京"<<endl;
	a=getchar();
	if(a=='\n')  
	cout<<"----原来如此"<<endl;
	a=getchar();
	if(a=='\n')  
	cout<<"刚才的一切只是场梦"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"我从床上坐起身来"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"短短两秒钟，刚才还包裹着我的温暖体感便消失了"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"消失得无影无踪，甚至没有残留半点余韵"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"因为一切来得太过突然，我甚至来不及做出任何思考"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"泪水便从眼角滑落"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"我时常会像这样一觉醒来时莫名地哭泣"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"我一边照镜子一遍扎头发，穿上春装"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"我推开公寓的门"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"眼前是一篇我终于见惯的东京风景"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"以前的我最为熟悉的是一座座山峰的名号"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"现如今也能叫出好几栋高层建筑的名字了"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"天空呈现出阴霾的灰白色"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"搭载着近百名乘客的车厢，运送着近千名乘客的列车，纵横交错的街道"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"突然意识到自己又在像往日般眺望这座城市"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"我----"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"在寻觅一个人"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"仅仅那一个人"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"（第一章结束）"<<endl;
	a=getchar();
	if(a=='\n')
	findw1();
}
void playw2_4()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____真酷！"<<endl;
	cout<<"键入2____就这？"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"“真酷！”，我一边想一边取过遥控器，如联动反应一般打开电视"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"“就这？”，我一边想一边取过遥控器，如联动反应一般打开电视" <<endl; 
        cout<<endl;
	}
	if(a!='2'&&a!='1')
	{
		playw2_4();
	}
} 
void playw2_3()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____莫不是我睡傻了？"<<endl;
	cout<<"键入2____我一定是睡傻了."<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"“莫不是我睡傻了？”，我暗自想道。"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"“我一定是睡傻了.”，我摇了摇头，在心里默默说。" <<endl; 
        cout<<endl;
	}
	if(a!='2'&&a!='1')
	{
		playw2_3();
	}
}
/*
void playw2_6()
{
	char a,b;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____是一名拥有一颗大脑的女高中生."<<endl;
	cout<<"键入2____是一名拥有一双美腿的女高中生."<<endl;
	cout<<"键入3____是一名拥有一名男友的女高中生."<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"谁没有啊喂！"<<endl;
	    cout<<endl;
	    cout<<"美腿你看不见吗略略略"<<endl;
	}
	if(a=='2')
	{
	    cout<<"耶耶耶！"<<endl; 
        cout<<endl;
	}
	if(a=='3')
	{
	    cout<<"才没有呢！"<<endl; 
        cout<<endl;
        cout<<"美腿你看不见吗略略略"<<endl;
	}
	if(a!='2'&&a!='1'&&a!='3')
	{
		playw2_6();
	}
}
*/
void playw2_7()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____像！"<<endl;
	cout<<"键入2____才不像呢！"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"嘿嘿！"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"怎么可能！"<<endl; 
        cout<<endl;
	}
	if(a!='2'&&a!='1')
	{
		playw2_7();
	}
}
void playw2_8()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"键入1____是早耶香"<<endl;
	cout<<"键入2____是外婆"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"猜对了！"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"外婆现在一定在神社呢"<<endl; 
        cout<<endl;
	}
	if(a!='2'&&a!='1')
	{
		playw2_8();
	}
}
void playw2()
{
	system("cls");
	char a;
	a=getchar();
	if(a=='\n') 
	cout<<"“姐姐，你太----慢咧！！~”"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"?"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"我刚拉开门走进起居室，四叶那充满攻击性的声音便飘了过来"<<endl;
	a=getchar();
	playw2_1();
	a=getchar();
	a=getchar();
	if(a=='\n')
	cout<<"四叶这妮子连乳牙都没换全，有时却比我这个做姐姐的还能干得多"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"不过就是不能道歉示弱！算什么嘛!"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"我一边如此打算一边打开电饭煲，往自己的碗里盛起饭来"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"啊？好像盛太多了"<<endl;
	playw2_2();
	a=getchar();
	if(a=='\n')
	cout<<"“我开动了----”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"我往滑溜溜的煎蛋上倒满酱汁，然后和米饭一起送入口中"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"啊啊啊，真好次，感觉好幸福..."<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"嗯？身边好像有人在盯着我看"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“今天......倒算是正常”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"呃？"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"我这才发现，外婆正一边咀嚼一边看着我："<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“昨天可糟糕着呢！”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"四叶笑嘻嘻的看着我说："<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“突然发出一声惨叫！”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"惨叫？"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"？"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"外婆对我投以狐疑的目光，四叶则是冷笑一声"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"（明显）把我当成了傻瓜"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“呃呃，啥情况？咋回事嘛？”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"她们这是什么意思嘛，你一言我一语的----"<<endl;
	playw2_3();
	a=getchar();
	if(a=='\n')
	cout<<"~~“噼里啪啦”~~"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"设置在门框横木上的扩音器突然传出震耳欲聋的声响"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“各位乡亲，早上好。”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"播音员是我的好姐妹----早耶香的姐姐"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"(她在镇政府的地域生活信息科工作)"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"我所居住的系守镇是个人口不过一千五百人的小镇"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"人们彼此之间基本都认识，要不便是熟人的熟人"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“以下是系守镇的晨间通知。”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"严格来说，扩音器里发出的声音是"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“以下是----系守镇的----晨间----通知.”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"一句话被切割成多个分句，读的真是慢慢悠悠"<<endl; 
	a=getchar();
	if(a=='\n')
	cout<<"由于家家户户都安装了扩音器，这段广播便如同合唱般在群山之间回荡."<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"这是每天早晚都会准时在整个小镇里响起的防灾无线广播"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"小镇的所有民宅都装设了接收器"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"而播报员每天便会通过广播告知大家运动会的日程安排、"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"执勤人员的联络方式、昨天谁家喜得贵子、今天谁家在举办葬礼"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"----总之都是一些发生在小镇里的日常琐事"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“关于下月二十日进行的系守镇镇长选举，镇选举管理委员会将----”"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"“卟”的一声"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"门框横木上的扩音器突然沉默了"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"因为够不到扩音器的话筒，外婆直接拔掉了插头"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"外婆已经年过八十，总是穿着一身雅致的老式和服，她正用这种无言的行动表达内心的愤怒"<<endl;
    playw2_4();
    a=getchar();
	if(a=='\n')
    cout<<"早耶香姐姐的声音消失之后，NHK的播音员大姐姐开始和颜悦色地说起话来"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"“千年一遇的彗星大约一个月后便会造访地球”"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"“据报道称，届时连续几天内都能通过肉眼观察到彗星的踪迹”"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"“在这场世纪天体秀到来之前,包括JAXA在内的科研机构也纷纷开始观测前的最后准备”"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"电视画面上显示出模糊的彗星影像"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"旁边配有“一个月后能以肉眼观察迪亚马特彗星”的文字描述"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"我们三人不再交谈，听着NHK的播报继续享用临时中断的早餐"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"但室外的广播声依旧像上课时的悄悄话一般断断续续地响个不停"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"“....我说你们也该和好了吧”"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"不懂得察言观色的四叶突兀地开口说道"<<endl;
    playw2_5(); 
    a=getchar();
	if(a=='\n')
    cout<<"没错，这是大人之间的问题。什么镇长选举嘛！"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"咕咕咕----此时，外头不知何时传来傻里傻气的鹰唳声"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"___________________________________________________________________"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"“我出门了。”我跟外婆打过招呼后，我与四叶走出玄关"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"时值盛夏，山间的鸟儿合唱的正欢"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"我们沿着倾斜的沥青路向下走去"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"踏过几级石阶后，两人来到山壁的阴影之外，感受那毫无遮拦的阳光"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"展现在我们面前的便是系守湖，此刻湖面风平浪静，在阳光的照耀下光彩夺目"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"绵延不断的深绿色群山，蓝天白云"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"扎着双马尾、背着红色的书包、在我身边兀自蹦蹦跳跳的小女孩"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"而我----"<<endl;
    a=getchar();
	//playw2_6
	if(a=='\n')
    cout<<"是一名拥有一双美腿的女高中生"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"我试着在脑海中走向雄壮的管弦乐BGM----"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"哦哦，这不就像日本电影的开篇一般嘛？"<<endl;
    playw2_7();
    a=getchar();
	if(a=='\n')
    cout<<"毕竟我们本来就住在乡下，而且是那种非常和风，带有昭和味道的乡下"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"“三叶----”"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"在小学门口和四叶分别后，有人从身后叫住了我"<<endl;
    playw2_8();
    a=getchar();
	if(a=='\n')
    cout<<"她正笑嘻嘻坐在自行车后座上，而前面蹬车的是一脸不爽的敕使"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"“你赶紧给我下来！”敕使嘟囔道"<<endl;
    
}
void playw3()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playw4()
{
	cout<<"这部分还没做好了"<<endl;
	play();
}
void playw5()
{
    cout<<"这部分还没做好呢"<<endl;
	play();
}
void playw6()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playw7()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playw8()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm1()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm2()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm3()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm4()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm5()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm6()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm7()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playm8()
{
	cout<<"这部分还没做好呢"<<endl;
	play();
}
void playw()
{
	system("cls");
	cout<<"可以选择章节"<<endl;
	char a; 
	cout<<"1           梦"<<endl;
	cout<<"2           线索"<<endl;
	cout<<"3           日常"<<endl;
	cout<<"4           探访"<<endl;
	cout<<"5           记忆"<<endl;
	cout<<"6           重现"<<endl;
	cout<<"7           美丽的挣扎"<<endl;
	cout<<"8           你的名字。"<<endl;
	cin>>a;
	if(a=='1')
	playw1();
	if(a=='2')
	playw2();
	if(a=='3')
	playw3();
	if(a=='4')
	playw4();
	if(a=='5')
	playw5();
	if(a=='6')
	playw6();
	if(a=='7')
	playw7();
	if(a=='8')
	playw8();
	if(a!='1'&&a!='2'&&a!='3'&&a!='4'&&a!='5'&&a!='6'&&a!='7'&&a!='8')
	playw();
}
void playm()
{
	system("cls");
	cout<<"可以选择章节"<<endl;
	char a; 
	cout<<"1           梦"<<endl;
	cout<<"2           线索"<<endl;
	cout<<"3           日常"<<endl;
	cout<<"4           探访"<<endl;
	cout<<"5           记忆"<<endl;
	cout<<"6           重现"<<endl;
	cout<<"7           美丽的挣扎"<<endl;
	cout<<"8           你的名字。"<<endl;
	cin>>a;
	if(a=='1')
	playm1();
	if(a=='2')
	playm2();
	if(a=='3')
	playm3();
	if(a=='4')
	playm4();
	if(a=='5')
	playm5();
	if(a=='6')
	playm6();
	if(a=='7')
	playm7();
	if(a=='8')
	playm8();
	if(a!='1'&&a!='2'&&a!='3'&&a!='4'&&a!='5'&&a!='6'&&a!='7'&&a!='8')
	playm();
}
void play()
{
	system("cls");
	char a,b; 
	cout<<"你可以在游戏开始时选择性别"<<endl;
    cout<<"男        请输入 m"<<endl;
    cout<<"女        请输入 w"<<endl;
	cin>>a;
	if(a=='m')
	playm();
	if(a=='w')
	playw(); 
	if(a!='m'&&a!='w')
	play();
}
int main()
{
	cout<<"                               君の名は                              "<<endl; 
	cout<<"                              Your  Name                              "<<endl;
	cout<<endl;
	cout<<"                           为了一个约定..."<<endl;
	cout<<endl;
	cout<<"                     无论发生什么事，哪怕星辰坠落"<<endl;
	cout<<endl;
	cout<<"                       为了你，我也一定要活下去"<<endl; 
	cout<<endl;
	cout<<"请注意放慢输入速度以保证不会引起字符误判"<<endl;
	cout<<endl;
	cout<<"注意剧情使用回车键进行继续,注意显示的分支剧情提示"<<endl;
	cout<<endl;
	cout<<"分支剧情需要输入1,2；请仔细键入，键入其他字符可能会发生错误"<<endl;
	cout<<endl;
	cout<<"墙裂建议每一章男女剧情都浏览完后再进行下一章，不然可能造成误解"<<endl;
	cout<<endl;
	cout<<"                      感谢游玩----Jiang Xingchen"<<endl;
	cout<<endl;
	cout<<"如果你想要开始请输入 y，离开请输入 n"<<endl;
	cout<<endl;
    cout<<"输入 c可以查看人物简介"<<endl;
	char s;
	cin>>s;
	if(s=='y')
	play();
	if(s=='n')
	{
	   cout<<"拜拜咯"<<endl;
	   return 0;
    }
    if(s=='c')
    	characterall();
	if(s!='y'&&s!='n'&&s!='c')
	{
		cout<<"没让你输入这个啊二货！"<<endl;
		return 0; 
	}
}
