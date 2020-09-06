#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 51;
const int A = 1,B = 2,C = 3;
int n, m;
struct hotel{
    string name;
    int bed_size;
    int people_each_room;
    int room_total;
    int prize_each_room;
    int bed_type;
}h[MAXN];
struct tour{
    int type;
    int total_people;
    int people_each;
};
bool ok(tour& t,hotel& h){
    int a=t.total_people,b=min(t.people_each,h.people_each_room);
    int p=(a%b==0)?a/b:a/b+1;
    if(t.type==h.bed_type && p<=h.room_total) return true;
    else return false;
}
int main(){
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>h[i].bed_size>>h[i].people_each_room>>h[i].room_total>>h[i].prize_each_room>>h[i].name;
        if(h[i].bed_size>=20&&h[i].bed_size<=35) h[i].bed_type=A;
        else if(h[i].bed_size>=36&&h[i].bed_size<=48) h[i].bed_type=B;
        else h[i].bed_type=C;
    }
    for(int i=1;i<=m;i++){
        tour now;
        int ansprize=0x7fffffff;
        int ans_bed_size;
        string ansname;
        bool flag=false;
        char temp;
        cin>>temp>>now.total_people>>now.people_each;
        now.type=temp-'A'+1;
        for(int j=1;j<=n;j++){
            if(ok(now,h[j])){
                flag=true;
                int a=now.total_people,b=min(h[j].people_each_room,now.people_each),v=h[j].prize_each_room;
                int prize=(a%b==0)?(a/b)*v:(a/b+1)*v;
                if(ansprize>prize){
                    ansprize=prize;
                    ansname=h[j].name;
                    ans_bed_size=h[j].bed_size;
                }
                else if(ansprize==prize){
                    if(ans_bed_size>h[j].bed_size){
                        ansname=h[j].name;
                    }
                }
            }
        }
        if(flag) cout<<ansprize<<" "<<ansname<<endl;
        else cout<<"no-hotel"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}