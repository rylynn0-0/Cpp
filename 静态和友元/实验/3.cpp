#include <iostream>
using namespace std;
class Tele;
class TV {
    int on_off;    // ���Ƶ��ӿ��� 0���� 1����
    int mode;       // �źŽ���ģʽ 0��TVģʽ��1��AVģʽ
    int channel;    // Ƶ��
    int volume;     // ����  
public:
    friend class Tele; //Tele��TV����Ԫ�࣬���ԣ�Tele�������Է���TV��ĳ�Ա
    TV(int a, int b, int c, int d) : on_off(a), mode(b), channel(c), volume(d) {}
};
class Tele {
public:
    void Onoff(TV &t);      // �л����ӿ���
    void Setmode(TV &t);    // �л��źŽ���ģʽ
    void VolumeDown(TV &t); // �����µ�1 ������Χ1-60
    void VolumeUp(TV &t);   // �����ϵ�1
    void ChannelDown(TV &t);// Ƶ���µ�1 Ƶ����Χ1-30
    void ChannelUp(TV &t);  // Ƶ���ϵ�1
    void Show(TV &t); // ���ո�ʽ��������Ϣ
};

//���²���������Tele����
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
		cout<<"���ӻ����ڹر�״̬"<<endl;
	}else{
		string type=(t.mode==1)?"AV":"TV";
		cout<<"���ӻ����ڿ���״̬"<<endl;
		cout<<"������СΪ��"<<t.volume<<endl;
		cout<<"Ƶ��Ϊ��"<<t.channel<<endl;
		cout<<"�źŽ���ģʽΪ��"<<type<<endl;
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
