//by JiangXingchen
//Դ���Ϊ���ң������ 
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
	    cout<<"ס�ڶ������ĵ��и�������ÿ������������ض��ա�"<<endl;
	    cout<<endl;
	    cout<<"��һ����ʽ�����򹤡�"<<endl;
	    cout<<endl;
	    cout<<"��ͬ�Ű���ǰ�����кøС��Խ����������ܸ���Ȥ��"<<endl;
	    cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl; 
    }
	if(a=='2')
	{
	    cout<<"ס����ɽ���С������Ů��������"<<endl;
	    cout<<endl;
		cout<<"��Ϊ������ĸ���������⡣"<<endl;
		cout<<endl;
		cout<<"�ͻ���Сѧ���������Լ���ĸ���������"<<endl;
		cout<<endl;
		cout<<"�Ը�ֱ�ʣ��Լ�������ķ��׺͸��׵�ѡ�ٻ������е����С�"<<endl;
		cout<<endl;
		cout<<"�������Ƕ�����С�ĳ���̾Ϣ�����Ŷ����Ļ������"<<endl;
		cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
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
		    cout<<"�ݰݿ�"<<endl;
		    exit(0);
		}
	    
    }
	if(a=='3')
	{
		cout<<"��Ҷ��ͬ��������÷�����ĺ��ѡ�"<<endl;
		cout<<endl;
		cout<<"�ľ����г�ʶ�����ʹ��ԭ�кøС�"<<endl;
		cout<<endl;
		cout<<"����������������㲥Ա��"<<endl;
		cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl;
	}
	if(a=='4')
	{
		cout<<"��Ҷ�����á�"<<endl;
		cout<<endl;
		cout<<"�ɿ���ʱ��Сѧ������������ĸ����Ҷһ���æ����ļ�ҵ��"<<endl;
		cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl;
	}
	if(a=='5')
	{
		cout<<"��Ĵ�ǰ����"<<endl;
		cout<<endl;
		cout<<"���Ư����Ů��ѧ�������������ڵ������ǵ��㽡�"<<endl;
		cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl;
	}
	if(a=='6')
	{
		cout<<"��Ҷ����ĸ����ˮ������������"<<endl;
		cout<<endl;
		cout<<"�Լ���Ů������Ҷ��ĸ�����ʣ���Ҷ�ĸ����뿪�Һ�"<<endl;
		cout<<endl;
		cout<<"����һ�˸�����Ҷ����Ҷ����"<<endl;
		cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl;
	}
	if(a=='7')
	{
	    cout<<"��Ҷ��ͬ���������صĻ�еլ��"<<endl;
		cout<<endl;
		cout<<"���ڵ��ش��½���ҵ�ĸ��ױ��Ÿ��ӵ����顣"<<endl;
		cout<<endl;
		cout<<"����Ҷ����������⡣����Ү���кø�"<<endl;
		cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl;
	}
	if(a=='8')
	{
	    cout<<"���ڸ��е����ѡ�"<<endl;
	    cout<<endl;
		cout<<"��Ȼ����䵭ȴ����غܰ��չ��ˡ�"<<endl;
	    cout<<endl;
		cout<<"����ͬ���Խ�������Ȥ��"<<endl;
	    cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl;
	}	
	if(a=='9')
	{
		cout<<"���ͬ������"<<endl;
		cout<<endl;
		cout<<"��ĸߴ�ȴ��ֱˬ���Ը�"<<endl;
		cout<<endl;
		cout<<"�������˾һ���¿κ󵽿��ȵ�ȥ��"<<endl;
		cout<<endl;
	    cout<<"���� c�ص������飬���� p��ʼ��Ϸ������ n�˳�"<<endl;
	    c=getchar();b=getchar();
	    if(b=='c')
		{
	    	system("cls");
	    	characterall();
		}
	    if(b=='p')
	    play();
	    if(b=='n')
	    cout<<"�ݰݿ�"<<endl;
	}
}
void characterall()
{
    system("cls");
	char a,b;
	cout<<"1.������"<<endl;
	cout<<endl;	
	cout<<"2.��ˮ��Ҷ"<<endl;
	cout<<endl;
	cout<<"3.��ȡ��Ү��"<<endl;
	cout<<endl;
	cout<<"4.��ˮ��Ҷ"<<endl;
	cout<<endl;
	cout<<"5.��������"<<endl;
	cout<<endl;
	cout<<"6.��ˮһҶ"<<endl;
	cout<<endl;
	cout<<"7.�ʹ��ԭ����"<<endl;
	cout<<endl;
	cout<<"8.�پ�˾"<<endl;
	cout<<endl;
	cout<<"9.��ľ��̫"<<endl;
	cout<<endl;
	cout<<"������Ӧ��ż��ɲ鿴�����飬���� p�˳���ѡ����棬���� n�˳�"<<endl;
	b=getchar();a=getchar();
	if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')
	characterneed(a);
	if(a=='p')
	play();
	if(a=='n')
	{
		cout<<"�ݰݿ�"<<endl;
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
	cout<<"����1____�����Ǵ���֮������⣡��"<<endl;
	cout<<"����2____Emmmmmm...�Һ�����"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"�����Ǵ���֮������⣡��"<<endl;
	    cout<<endl;
		cout<<"��ն��������˵��"<<endl;
		cout<<endl;
	}
	if(a=='2')
	{
		cout<<"�Һ���������ת��һ�룬�ߣ�"<<endl;
		cout<<endl; 
		cout<<"��С���ӲŲ����أ�����ն��������˵��"<<endl;
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
	cout<<"Ҫ�����𣿻��ǽ�����"<<endl;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"���� c������һ����Ϸ"<<endl; 
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"���� p������Ϸ��ҳ��"<<endl; 
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"���� r����ѡ���½�ģʽ"<<endl;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"���� n�뿪"<<endl;	
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
	cout<<"����1____��"<<endl;
	cout<<"����2____��˯һ��"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	b=getchar();
	if(b=='1')
	{
	    cout<<"�峿������������������"<<endl;
		a=getchar();
	    if(a=='\n')
	    a=getchar();
	    if(a=='\n')
		cout<<"ͻȻ��������˫��"<<endl;
	} 
	if(b=='2')
	{
		cout<<"������˯һ���"<<endl;
	    a=getchar();
	    if(a=='\n')
	    a=getchar();
	    if(a=='\n')
	    cout<<"zzz(��-��-)zzz"<<endl;
	    a=getchar();
     	if(a=='\n')
	    cout<<"������~"<<endl;
	    a=getchar();
     	if(a=='\n')
	    cout<<"���������ʵ�˫��"<<endl;
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
	cout<<"����1____���������������ͺ����¡�"<<endl;
	cout<<"����2____�������⣿��"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	cout<<"���������������ͺ����¡�����û�е�Ǹ��������˵����"<<endl;
	if(a=='2')
	cout<<"�������⣿������û�е�Ǹ��������˵����" <<endl; 
	if(a!='2'&&a!='1')
	{
		playw2_1();
	}
}
void playw2_2()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"����1____�ѷ�����ȥһ��"<<endl;
	cout<<"����2____���ˣ��Զ���ٶ�һ��"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"���Ұѷ�����ȥһ���QAQ"<<endl;
	    cout<<endl;
		cout<<"���̰���ʢ�������ˣ��ƣ�"<<endl;
	    char b; 
		b=getchar();
	    if(b=='\n')
	    {
	        cout<<endl;
	        cout<<"�����ˣ��ߨq(�s^�t)�r"<<endl;
	}
	}
	if(a=='2')
	{
		cout<<"���������������ﶼ�ܳԣ�"<<endl;
		cout<<endl; 
	}
	if(a!='2'&&a!='1')
	{
		playw2_2();
	}
}
void outw()
{
	cout<<"~~�ټ���Ҷ���´��ټ���~~"; 
}
void playw1()
{
	system("cls");
	char a;
	a=getchar();
	if(a=='\n') 
	cout<<"���˸л���������ζ�������������Ĺ�â���¶�"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"������ĳλ��Ҫ���˽�������һ�𣬷·���Զ�������"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"�Ҿ����������ĸ����ǰ���̵�Ӥ�������޲�����Ҳ����е���į"<<endl; 
	a=getchar();
	if(a=='\n') 
	cout<<"�һ�����ʧȥʲô�����������������ޱȷ���"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"Ӧ���������˰ɣ�"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�ǲ��Ǹ����ˣ�"<<endl;
	playw1_1();
	a=getchar();
	if(a=='\n')
	cout<<"�컨��"<<endl;
    a=getchar();
	if(a=='\n')  
	cout<<"���䣬�峿"<<endl;
	a=getchar();
	if(a=='\n')  
	cout<<"�ε�Ӱֻ"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"����"<<endl;
	a=getchar();
	if(a=='\n')  
	cout<<"----ԭ�����"<<endl;
	a=getchar();
	if(a=='\n')  
	cout<<"�ղŵ�һ��ֻ�ǳ���"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"�ҴӴ�����������"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"�̶������ӣ��ղŻ��������ҵ���ů��б���ʧ��"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��ʧ����Ӱ���٣�����û�в����������"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��Ϊһ������̫��ͻȻ�������������������κ�˼��"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��ˮ����۽ǻ���"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��ʱ����������һ������ʱĪ���ؿ���"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��һ���վ���һ����ͷ�������ϴ�װ"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"���ƿ���Ԣ����"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��ǰ��һƪ�����ڼ��ߵĶ����羰"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��ǰ������Ϊ��Ϥ����һ����ɽ�������"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"�����Ҳ�ܽг��ü����߲㽨����������"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��ճ��ֳ������ĻҰ�ɫ"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"�����Ž������˿͵ĳ��ᣬ�����Ž�ǧ���˿͵��г����ݺύ��Ľֵ�"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"ͻȻ��ʶ���Լ����������հ�������������"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��----"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"��Ѱ��һ����"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"������һ����"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"����һ�½�����"<<endl;
	a=getchar();
	if(a=='\n')
	findw1();
}
void playw2_4()
{
	char a;
	cout<<"___________________________________________________________________"<<endl; 
	cout<<"����1____��ᣡ"<<endl;
	cout<<"����2____���⣿"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"����ᣡ������һ����һ��ȡ��ң��������������Ӧһ��򿪵���"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"�����⣿������һ����һ��ȡ��ң��������������Ӧһ��򿪵���" <<endl; 
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
	cout<<"����1____Ī������˯ɵ�ˣ�"<<endl;
	cout<<"����2____��һ����˯ɵ��."<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"��Ī������˯ɵ�ˣ������Ұ��������"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"����һ����˯ɵ��.������ҡ��ҡͷ��������ĬĬ˵��" <<endl; 
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
	cout<<"����1____��һ��ӵ��һ�Ŵ��Ե�Ů������."<<endl;
	cout<<"����2____��һ��ӵ��һ˫���ȵ�Ů������."<<endl;
	cout<<"����3____��һ��ӵ��һ�����ѵ�Ů������."<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"˭û�а�ι��"<<endl;
	    cout<<endl;
	    cout<<"�����㿴������������"<<endl;
	}
	if(a=='2')
	{
	    cout<<"ҮҮҮ��"<<endl; 
        cout<<endl;
	}
	if(a=='3')
	{
	    cout<<"��û���أ�"<<endl; 
        cout<<endl;
        cout<<"�����㿴������������"<<endl;
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
	cout<<"����1____��"<<endl;
	cout<<"����2____�Ų����أ�"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"�ٺ٣�"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"��ô���ܣ�"<<endl; 
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
	cout<<"����1____����Ү��"<<endl;
	cout<<"����2____������"<<endl;
	cout<<"___________________________________________________________________"<<endl;	  
	a=getchar();
	if(a=='1')
	{
	    cout<<"�¶��ˣ�"<<endl;
	    cout<<endl;
	}
	if(a=='2')
	{
	    cout<<"��������һ����������"<<endl; 
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
	cout<<"����㣬��̫----���֣���~��"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"?"<<endl;
	a=getchar();
	if(a=='\n') 
	cout<<"�Ҹ��������߽�����ң���Ҷ�ǳ��������Ե�������Ʈ�˹���"<<endl;
	a=getchar();
	playw2_1();
	a=getchar();
	a=getchar();
	if(a=='\n')
	cout<<"��Ҷ��������������û��ȫ����ʱȴ������������Ļ��ܸɵö�"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�������ǲ��ܵ�Ǹʾ������ʲô��!"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��һ����˴���һ�ߴ򿪵緹�ң����Լ�������ʢ����"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��������ʢ̫����"<<endl;
	playw2_2();
	a=getchar();
	if(a=='\n')
	cout<<"���ҿ�����----��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"����������ļ嵰�ϵ�����֭��Ȼ����׷�һ���������"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"����������ôΣ��о����Ҹ�..."<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�ţ���ߺ��������ڶ����ҿ�"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"������......������������"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"����"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"����ŷ��֣�������һ�߾׽�һ�߿����ң�"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�������������أ���"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��ҶЦ�����Ŀ�����˵��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��ͻȻ����һ���ҽУ���"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�ҽУ�"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"���Ŷ���Ͷ�Ժ��ɵ�Ŀ�⣬��Ҷ������Цһ��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�����ԣ����ҵ�����ɵ��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��������ɶ�����զ�������"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��������ʲô��˼���һ����һ���----"<<endl;
	playw2_3();
	a=getchar();
	if(a=='\n')
	cout<<"~~������ž����~~"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�������ſ��ľ�ϵ�������ͻȻ�����������������"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"����λ���ף����Ϻá���"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"����Ա���ҵĺý���----��Ү��Ľ��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"(�����������ĵ���������Ϣ�ƹ���)"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"������ס��ϵ�����Ǹ��˿ڲ���һǧ����˵�С��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"���Ǳ˴�֮���������ʶ��Ҫ���������˵�����"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��������ϵ����ĳ���֪ͨ����"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�ϸ���˵���������﷢����������"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��������----ϵ�����----����----֪ͨ.��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"һ�仰���и�ɶ���־䣬����������������"<<endl; 
	a=getchar();
	if(a=='\n')
	cout<<"���ڼҼһ�������װ������������ι㲥����ͬ�ϳ�����Ⱥɽ֮��ص�."<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"����ÿ��������׼ʱ������С��������ķ������߹㲥"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"С���������լ��װ���˽�����"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"������Աÿ����ͨ���㲥��֪����˶�����ճ̰��š�"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"ִ����Ա�����緽ʽ������˭��ϲ�ù��ӡ�����˭���ھٰ�����"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"----��֮����һЩ������С������ճ�����"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"���������¶�ʮ�ս��е�ϵ������ѡ�٣���ѡ�ٹ���ίԱ�Ὣ----��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��߲����һ��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�ſ��ľ�ϵ�������ͻȻ��Ĭ��"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"��Ϊ�������������Ļ�Ͳ������ֱ�Ӱε��˲�ͷ"<<endl;
	a=getchar();
	if(a=='\n')
	cout<<"�����Ѿ������ʮ�����Ǵ���һ�����µ���ʽ�ͷ����������������Ե��ж�������ĵķ�ŭ"<<endl;
    playw2_4();
    a=getchar();
	if(a=='\n')
    cout<<"��Ү�����������ʧ֮��NHK�Ĳ���Ա���㿪ʼ������ɫ��˵����"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"��ǧ��һ�������Ǵ�Լһ���º�����õ���"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"���ݱ����ƣ���ʱ���������ڶ���ͨ�����۹۲쵽���ǵ��ټ���"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"�����ⳡ���������㵽��֮ǰ,����JAXA���ڵĿ��л���Ҳ�׷׿�ʼ�۲�ǰ�����׼����"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"���ӻ�������ʾ��ģ��������Ӱ��"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"�Ա����С�һ���º��������۹۲�����������ǡ�����������"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"�������˲��ٽ�̸������NHK�Ĳ�������������ʱ�жϵ����"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"������Ĺ㲥���������Ͽ�ʱ�����Ļ�һ��϶������������ͣ"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"��....��˵����Ҳ�úͺ��˰ɡ�"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"�����ò��Թ�ɫ����Ҷͻأ�ؿ���˵��"<<endl;
    playw2_5(); 
    a=getchar();
	if(a=='\n')
    cout<<"û�����Ǵ���֮������⡣ʲô��ѡ���"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"������----��ʱ����ͷ��֪��ʱ����ɵ��ɵ����ӥ���"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"___________________________________________________________________"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"���ҳ����ˡ����Ҹ����Ŵ���к���������Ҷ�߳�����"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"ʱֵʢ�ģ�ɽ�������ϳ�������"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"����������б������·������ȥ"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"̤������ʯ�׺���������ɽ�ڵ���Ӱ֮�⣬�����Ǻ�������������"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"չ����������ǰ�ı���ϵ�غ����˿̺����ƽ�˾������������ҫ�¹�ʶ�Ŀ"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"���Ӳ��ϵ�����ɫȺɽ���������"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"����˫��β�����ź�ɫ��������������أ�Աı�������СŮ��"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"����----"<<endl;
    a=getchar();
	//playw2_6
	if(a=='\n')
    cout<<"��һ��ӵ��һ˫���ȵ�Ů������"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"���������Ժ���������׳�Ĺ�����BGM----"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"ŶŶ���ⲻ�����ձ���Ӱ�Ŀ�ƪһ���"<<endl;
    playw2_7();
    a=getchar();
	if(a=='\n')
    cout<<"�Ͼ����Ǳ�����ס�����£����������ַǳ��ͷ磬�����Ѻ�ζ��������"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"����Ҷ----��"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"��Сѧ�ſں���Ҷ�ֱ�����˴�����ס����"<<endl;
    playw2_8();
    a=getchar();
	if(a=='\n')
    cout<<"����Ц�����������г������ϣ���ǰ��ų�����һ����ˬ���ʹ"<<endl;
    a=getchar();
	if(a=='\n')
    cout<<"����Ͻ��������������ʹ����"<<endl;
    
}
void playw3()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playw4()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playw5()
{
    cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playw6()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playw7()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playw8()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm1()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm2()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm3()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm4()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm5()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm6()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm7()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playm8()
{
	cout<<"�ⲿ�ֻ�û������"<<endl;
	play();
}
void playw()
{
	system("cls");
	cout<<"����ѡ���½�"<<endl;
	char a; 
	cout<<"1           ��"<<endl;
	cout<<"2           ����"<<endl;
	cout<<"3           �ճ�"<<endl;
	cout<<"4           ̽��"<<endl;
	cout<<"5           ����"<<endl;
	cout<<"6           ����"<<endl;
	cout<<"7           ����������"<<endl;
	cout<<"8           ������֡�"<<endl;
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
	cout<<"����ѡ���½�"<<endl;
	char a; 
	cout<<"1           ��"<<endl;
	cout<<"2           ����"<<endl;
	cout<<"3           �ճ�"<<endl;
	cout<<"4           ̽��"<<endl;
	cout<<"5           ����"<<endl;
	cout<<"6           ����"<<endl;
	cout<<"7           ����������"<<endl;
	cout<<"8           ������֡�"<<endl;
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
	cout<<"���������Ϸ��ʼʱѡ���Ա�"<<endl;
    cout<<"��        ������ m"<<endl;
    cout<<"Ů        ������ w"<<endl;
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
	cout<<"                               ��������                              "<<endl; 
	cout<<"                              Your  Name                              "<<endl;
	cout<<endl;
	cout<<"                           Ϊ��һ��Լ��..."<<endl;
	cout<<endl;
	cout<<"                     ���۷���ʲô�£������ǳ�׹��"<<endl;
	cout<<endl;
	cout<<"                       Ϊ���㣬��Ҳһ��Ҫ����ȥ"<<endl; 
	cout<<endl;
	cout<<"��ע����������ٶ��Ա�֤���������ַ�����"<<endl;
	cout<<endl;
	cout<<"ע�����ʹ�ûس������м���,ע����ʾ�ķ�֧������ʾ"<<endl;
	cout<<endl;
	cout<<"��֧������Ҫ����1,2������ϸ���룬���������ַ����ܻᷢ������"<<endl;
	cout<<endl;
	cout<<"ǽ�ѽ���ÿһ����Ů���鶼�������ٽ�����һ�£���Ȼ����������"<<endl;
	cout<<endl;
	cout<<"                      ��л����----Jiang Xingchen"<<endl;
	cout<<endl;
	cout<<"�������Ҫ��ʼ������ y���뿪������ n"<<endl;
	cout<<endl;
    cout<<"���� c���Բ鿴������"<<endl;
	char s;
	cin>>s;
	if(s=='y')
	play();
	if(s=='n')
	{
	   cout<<"�ݰݿ�"<<endl;
	   return 0;
    }
    if(s=='c')
    	characterall();
	if(s!='y'&&s!='n'&&s!='c')
	{
		cout<<"û�������������������"<<endl;
		return 0; 
	}
}
