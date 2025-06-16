#include <iostream>
using namespace std;
class Tele;
class TV {
    int on_off;    // 控制电视开关 0：开 1：关
    int mode;       // 信号接收模式 0是TV模式，1是AV模式
    int channel;    // 频道
    int volume;     // 音量  
public:
    friend class Tele; //Tele是TV的友元类，所以，Tele类对象可以访问TV类的成员
    TV(int a, int b, int c, int d) : on_off(a), mode(b), channel(c), volume(d) {}
};
class Tele {
public:
    void Onoff(TV &t);      // 切换电视开关
    void Setmode(TV &t);    // 切换信号接收模式
    void VolumeDown(TV &t); // 音量下调1 音量范围1-60
    void VolumeUp(TV &t);   // 音量上调1
    void ChannelDown(TV &t);// 频道下调1 频道范围1-30
    void ChannelUp(TV &t);  // 频道上调1
    void Show(TV &t); // 按照格式输出相关信息
};

//以下补充完整类Tele定义
/********** Write your code here! **********/
void Tele::Onoff(TV &t){
	t.on_off=(t.on_off==1)?0:1;
}

void Tele::Setmode(TV &t){
	t.mode=(t.mode==1)?0:1;
} 

void Tele::VolumeDown(TV &t){
	t.volume--;
	t.volume=max(1,t.volume);
} 

void Tele::VolumeUp(TV &t){
	t.volume++;
	t.volume=min(60,t.volume);
} 

void Tele::ChannelDown(TV &t){
	t.channel--;
	t.channel=max(1,t.channel);
}

void Tele::ChannelUp(TV &t){
	t.channel++;
	t.channel=min(30,t.channel);
}

void Tele::Show(TV &t){
	if(t.on_off==1){
		cout<<"电视机处于关闭状态"<<endl;
	}else{
		string type=(t.mode==1)?"AV":"TV";
		cout<<"电视机处于开启状态"<<endl;
		cout<<"音量大小为："<<t.volume<<endl;
		cout<<"频道为："<<t.channel<<endl;
		cout<<"信号接收模式为："<<type<<endl;
	}
}
/*******************************************/
int main()
{ int on_off, mode, channel, volume;
    cin >> on_off >> mode >> channel >> volume;
    Tele t1;
    TV t2(on_off, mode, channel, volume);
    t1.Show(t2);
    cout << "--------------" << endl;
    t1.Onoff(t2);
    t1.Show(t2);
    cout << "--------------" << endl;
    t1.ChannelDown(t2);
    t1.Setmode(t2);
    t1.VolumeUp(t2);
    t1.Show(t2);
    cout << "--------------" << endl;
    t1.ChannelUp(t2);
    t1.VolumeDown(t2);
    t1.Setmode(t2);
    t1.Show(t2);
    return 0;
}
