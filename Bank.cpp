#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <direct.h>
#include <dos.h>
#include <stdlib.h>

using namespace std;


class banking{
	//Attributes
private:
	double deposit;
	double temp_deposit;
	double savings;
	double chequing;
	double balance{0};
	int acc_number;
	int temp_acc_number;
	string name;
	int user_input;
	string temp;
	int counter{0};
	//Methods
public:
	void user_deposit();
	void user_withdrawn();
	void user_create();
	void menu();
	void user_info();
};

void banking::menu(){
	cout<<endl<<"  Menus Options: "<<endl<<endl;
	cout<<"1.Create an account"<<endl<<endl
		<<"2.Deposit"<<endl<<endl
		<<"3.Account info"<<endl<<endl
		<<"4.Withdraw"<<endl;
	cin>>user_input;
	system("CLS");
	cout<<"-----------------------------"<<endl;
	cout<<"  Created by Brian Fu"<<endl<<endl<<"  Banking System"<<endl<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<endl<<endl<<endl<<"You have selected option "<<user_input<<endl;
	if (user_input==1){
		user_create();
		menu();
	}
	else if(user_input==2){
		user_deposit();
		menu();
	}
	else if(user_input==3){
		user_info();
		menu();
	}
	else if(user_input==4){
		user_withdrawn();
		menu();
	}
	else{
		cout<<"Invalid selction!"<<endl;
		menu();
	}
	 
	
} 	

void banking::user_create(){
	cout<<"Enter your desired account number: "<<endl;
	cin>>acc_number;
	cin.ignore();
	cout<<"Enter your full name: "<<endl;
	getline(cin,name);
	cout<<"Enter your initial deposit:"<<endl;
	cin>>deposit;
	balance = deposit;
	cout<<"Creating account......"<<endl<<endl;
	Sleep(500);
	system("CLS");
	for (int j = 0; j < 3; j++) {
		cout << "\rLoading   \rLoading"<<endl<<endl;
			for (int i = 0; i < 6; i++) {
				cout << ".";
				Sleep(300);
			}
		system("CLS");
	}
	system("CLS");
	cout<<"Accout created!"<<endl;	
}

void banking::user_deposit(){
	cout<<"How much would you like to deposit?"<<endl;
	cin>>temp_deposit;
	deposit=deposit + temp_deposit;
	balance = balance + deposit;
	cout<<"You have deposited: "<<"$"<<temp_deposit<<endl<<endl
		<<"Your current balance is: "<<"$"<<balance<<endl;
}

void banking::user_withdrawn(){
	double withdraw{0};
	cout<<"How much would you like to withdraw?"<<endl;
	cin>>withdraw;
	balance = balance - withdraw;
	if (balance < 0){
		cout<<"Insufficient funds!"<<endl;
		cout<<"Try again? (Yes or No): "<<endl;
		cin>>temp;
		if(temp=="Yes"){
			balance = balance + withdraw;
			user_withdrawn();
		}
		else{
			exit(0);
		}
	}
	else{
		cout<<"You have withdrawn: "<<"$"<<withdraw<<endl<<endl
		<<"Your current balance is: "<<"$"<<balance<<endl;
	}
}

void banking::user_info(){
	cout<<"Enter account number: "<<endl;
	cin>>temp_acc_number;
	if (temp_acc_number == acc_number){
		cout<<"Account number: "<<acc_number<<endl;
		cout<<"Holder's name: "<<name<<endl;
		cout<<"Balance: "<<"$"<<balance<<endl;
	}
	else{
		cout<<"Account does not exist!"<<endl
		<<"Try again!"<<endl;
		user_info();
	}
}







int main(){
	banking user;
	user.menu();
}
