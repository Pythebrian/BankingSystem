#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

class Account{
	//Attributes
public:
	int acc_number;
	string name;
	double deposit;
	double balance{0};
	double withdraw;
	

	
};

class banking{
	//Attributes
private:
	vector <Account> stored_account = {};
	double temp_deposit;
	double savings;
	double chequing;
	int temp_acc_number;
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
	void animation();
	void test();
	void moretest();
    void user_close();
	bool is_acc_num_taken(int temp_acc_number);
};

void banking::menu(){
	cout<<endl<<"  Menus Options: "<<endl<<endl;
	cout<<"1.Create an account"<<endl<<endl
		<<"2.Deposit"<<endl<<endl
		<<"3.Account info"<<endl<<endl
		<<"4.Withdraw"<<endl<<endl
        <<"5.Close an account"<<endl<<endl;
	cin>>user_input;
	system("CLS");
	cout<<"-----------------------------"<<endl;
	cout<<"  Created by Brian Fu"<<endl<<endl<<"  Banking System"<<endl<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<endl<<endl<<endl<<"You have selected option "<<user_input<<endl;
	if (user_input == 1){
		user_create();
		menu();
	}
	else if(user_input == 2){
		user_deposit();
		menu();
	}
	else if(user_input == 3){
		user_info();
		menu();
	}
	else if(user_input == 4){
		user_withdrawn();
		menu();
	}
    else if(user_input == 5){
        user_close();
        menu();
    }
	else{
		cout<<"Invalid selction!"<<endl;
		menu();
	}
} 	

void banking::animation(){
	for (int j = 0; j < 3; j++) {
		cout << "\rLoading   \rLoading"<<endl<<endl;
			for (int i = 0; i < 6; i++) {
				cout << ".";
				Sleep(300);
			}
		system("CLS");
	}
}
void banking::user_deposit(){
	cout<<"Enter the account number: "<<endl;
	cin>>temp_acc_number;
	bool deposit_found=false;
	int deposit_counter = 0;
	while (deposit_counter <= stored_account.size() && deposit_found == false){
		if (temp_acc_number == stored_account[deposit_counter].acc_number){
			cout<<"How much would you like to deposit?"<<endl;
			cin>>temp_deposit;
			deposit_found = true;
			stored_account[deposit_counter].balance = temp_deposit + stored_account[deposit_counter].balance;
            break;
		}
		deposit_counter ++;
	}
	if (deposit_found == false){
		cout<<"Account does not exist!"<<endl
		<<"Try again? (Yes/No): "<<endl;
		cin>>temp;
	if (temp=="Yes"){
		system("CLS");
		user_deposit();
	}
	else{
		system("CLS");
		menu();
	}
	}
	else{
		system ("CLS");
		cout<<"You have deposited: "<<"$"<<temp_deposit<<endl<<endl
		<<"Your current balance is: "<<"$"<<stored_account[deposit_counter].balance<<endl;
		}
}
	
void banking::user_info(){
    int counter{0};
    cout<<"Enter accound number: "<<endl;
    cin>>temp_acc_number;
    bool found = false;
	while (counter <= stored_account.size() && !found)
	{
		if (temp_acc_number == stored_account[counter].acc_number)
		{
			cout<<"Account number: "<<stored_account[counter].acc_number<<endl;
			cout<<"Holder's name: "<<stored_account[counter].name<<endl;
			cout<<"Balance: "<<"$"<<stored_account[counter].balance<<endl;
			found = true;
			break;
		}
		counter ++;
	}
	if(found == false){
    cout<<"Account does not exist!"<<endl
        <<"Try again? (Yes/No): "<<endl;
        cin>>temp;
        if (temp=="Yes"){
			system ("CLS");
            user_info();
        }
        else{
            system("CLS");
            menu();
        }
		
	}
}

void banking::test(){
	for (int i=0; i<stored_account.size(); i++){
		cout<<stored_account[i].name<<endl;
	}
}

bool banking::is_acc_num_taken(int temp_acc_number){
	for (int i=0; i<stored_account.size(); i++){
		if (stored_account[i].acc_number == temp_acc_number)
			return true;
	}	
	return false;
}




void banking::user_withdrawn(){
	cout<<"Enter your account number: "<<endl;
	cin>>temp_acc_number;
	bool withdrawn_found = false;
	int withdrawn_counter = 0;
	while (withdrawn_counter <= stored_account.size() && withdrawn_found == false){
		if(temp_acc_number == stored_account[withdrawn_counter].acc_number){
			cout<<"How much would you like to withdraw? "<<endl;
			cin>>stored_account[withdrawn_counter].withdraw;
			withdrawn_found = true;
			stored_account[withdrawn_counter].balance = stored_account[withdrawn_counter].balance - stored_account[withdrawn_counter].withdraw;
			if(stored_account[withdrawn_counter].balance >= 0){
				system ("CLS");
				cout<<"You have withdrawn: "<<"$"<<stored_account[withdrawn_counter].withdraw<<endl<<endl
				<<"Your current balance is: "<<'$'<<stored_account[withdrawn_counter].balance<<endl;
			}
			if(stored_account[withdrawn_counter].balance < 0){
				cout<<"Insufficient funds!"<<endl
				<<"Try again? (Yes/No)"<<endl;
				cin>>temp;
				if(temp == "Yes"){
					system("CLS");
					stored_account[withdrawn_counter].balance = stored_account[withdrawn_counter].balance + stored_account[withdrawn_counter].withdraw;
					user_withdrawn();
				}
				else{
					system ("CLS");
					menu();
				}
			}
			
		}
		withdrawn_counter ++;
	}
	if (withdrawn_found == false){
		cout<<"Accont does not exist!"<<endl
			<<"Try again? (Yes/No)"<<endl;
		cin>>temp;
		if (temp == "Yes"){
			system ("CLS");
			user_withdrawn();
		}
		else{
			system ("CLS");
			menu();
		}
	}
}

void banking::user_close(){
    cout<<"Enter your account number: "<<endl;
    cin>>temp_acc_number;
    bool acc_found = false;
    int acc_counter = 0;
    while (acc_counter <= stored_account.size() && acc_found == false){
        if (temp_acc_number == stored_account[acc_counter].acc_number){
            stored_account.erase(stored_account.begin() + acc_counter);
            acc_found = true;
            break;
        }
        acc_counter ++;
    }
    if(acc_found == true){
        cout<<"Account removed!"<<endl;
    }
    if (acc_found == false){
        cout<<"Accont does not exist!"<<endl
		<<"Try again? (Yes/No)"<<endl;
		cin>>temp;
		if (temp == "Yes"){
			system ("CLS");
			user_close();
		}
		else{
			system ("CLS");
			menu();
		}
    }
}

int main(){
	banking user_1;
	user_1.menu();
}

void banking::user_create(){
	Account new_account;
	int create_counter{0};
	cout<<"Enter your account number: "<<endl;
	cin>>temp_acc_number;
	bool taken = is_acc_num_taken(temp_acc_number);
	string temp;
	while(taken)
	{
		cout<<"Account number not avaialble! "<<endl
		<<"Try again? (Yes/No)"<<endl;
		cin>>temp;
		
		if (temp == "Yes"){
			cout<<"Enter your account number: "<<endl;
			cin>>temp_acc_number;
			taken = is_acc_num_taken(temp_acc_number);
		}
		else{
			menu();
		}
	}
	if (!taken){
		new_account.acc_number = temp_acc_number;
	}
	cin.ignore();
	cout<<"Enter your full name: "<<endl;
	getline(cin,new_account.name);
	cout<<"Enter your initial deposit:"<<endl;
	cin>>new_account.deposit;
	new_account.balance = new_account.deposit;
	cout<<"Creating account......"<<endl<<endl;
	stored_account.push_back(new_account);
	Sleep(500);
	system("CLS");
	animation();
	system("CLS");
	cout<<"Accout created!"<<endl;
	Sleep(1000);
	system ("CLS");	
}

