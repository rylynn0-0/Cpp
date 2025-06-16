#include<iostream> 
using namespace std;
#define double float
class CPerson{
	protected:
		string name;
		string id;
	public:
		CPerson(string id,string name):name(name),id(id){}
		
};

class CInternetUser: public CPerson{
	protected:
	string  password;
	public:
		CInternetUser(string id,string name,string passwold):CPerson(id,name),password(password){}
		CInternetUser():CPerson("",""){
			password="";
		}
		void registerUser(string name,string id,string password){
			this->id=id;
			this->name=name;
			this->password=password;
		}
		
		bool login(string str){
			return str==password;
		}
};

class CBankCustomer: public CPerson{
	protected :
		double balance;
	public:
		CBankCustomer(string id,string name,double balance):CPerson(id,name),balance(balance){}
		void openAccount(string name,string id){
			this->id=id;
			this->name=name;
		}
		
		void deposit(double m){
			balance+=m;
		}
		int withdraw(double m){
			if(balance-m>=0){
			
			balance-=m;
			return 1;
		}
			else return 0;
		}
		CBankCustomer():CPerson("",""){
			balance=0;
		}
};

class CInternetBankCustomer:public CInternetUser,public CBankCustomer{
	private:
		double balance;
		double last_balance;
		double in;
		double today_w_in;
		double last_w_in;
	public:
		CInternetBankCustomer(){
			balance=0;
		last_balance=0;
		today_w_in=0;
		}
		
		int deposit(double m){
			if(CBankCustomer::withdraw(m)!=0){
			
			balance+=m;
			return 1;}
			else return 0;
		}
		
		int withdraw(double m){
			if(balance-m>=0){
			balance-=m;
			CBankCustomer::deposit(m); 
			return 1;
		}
			else return 0;
		}
		
		void setInterest(double m){
			last_w_in=today_w_in;
			today_w_in=m;
		}
		
		void calculateProfit(){
			in=last_balance*last_w_in/10000;
			last_balance=balance;
			balance=balance+in;
		}
		
		int login(string i,string mm){
			if(i!=CInternetUser::id){
			return 0;}
			else if(i!=CBankCustomer::id){
			return 0;}
			else if(CInternetUser::name!=CBankCustomer::name){
			return 0;}
			else if(mm!=password){
			return 0;}
			else return 1;
		}
		
		void print(){
			cout<<"Name: "<<CBankCustomer::name<<" ID: "<<CBankCustomer::id<<endl;
			cout<<"Bank balance: "<<CBankCustomer::balance<<endl;
			cout<<"Internet bank balance: "<<balance<<endl;
			cout<<endl;
		}
		
};



/*******************************************/
int main()
{
    int t, no_of_days, i;
    string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
    double money, interest;
    char op_code;

    // ������԰�����t
    cin >> t;
    while (t--)
    {
        // ���뻥�����û�ע��ʱ���û���,id,��½����
        cin >> i_xm >> i_id >> i_mm;

        // �������п����û���,id
        cin >> b_xm >> b_id;

        // ���뻥�����û���½ʱ��id,��½����
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0) // �������û���½,��id�����벻��;�Լ����п���������id�뻥��������������id��ͬ
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        // ��������
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++)
        {
            // �����������, ���, ������Ԫ����
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
            case 'S': // �����������������ʻ�����
            case 's':
                if (ib_user.deposit(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T': // �ӻ���������ת�������ʻ�
            case 't':
                if (ib_user.withdraw(money) == 0)
                {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D': // ֱ���������ʻ����
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W': // ֱ�Ӵ������ʻ�ȡ��
            case 'w':
                if (ib_user.CBankCustomer::withdraw(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            // ����û���,id
            // ����������
            // ��������������˻����
            ib_user.print();
        }
    }
}


