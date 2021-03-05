#include <iostream>
#include <cstring>
//

// class Cat {
// public:
//     Cat() {
//         cat_age = 3;
//     }

//     Cat(int other_cat_age) {
//         this->cat_age = other_cat_age;
//     }

//     void setCatAge(int other_cat_age) {
//         this->cat_age = other_cat_age;
//     }

//     int getCatAge() const {
//         return cat_age;
//     }

//     void printCatAge() const {
//         std::cout << cat_age;
//     }
    
// private:    
//     int cat_age;
//     int cat_height;
//     int cat_widht;
// };

class BankAccount { 
public:
    BankAccount() {
        strcpy_s(this->account_name,8,"traicho");
        strcpy_s(this->account_number,6,"BG666");
        account_cash = 0;
    }
   
    BankAccount(const char* other_account_name, const char* other_account_number, double other_account_cash) {
        strcpy_s(this->account_name, strlen(other_account_name) + 1, other_account_name);
        strcpy_s(this->account_number,strlen(other_account_number) + 1, other_account_number); // Да започва с BG ДОМАШНА
        account_cash = other_account_cash;  
    }

    void printBankAccount() const {
        std::cout << account_name << std::endl;
        std::cout << account_number << std::endl;
		std::cout << account_cash << std::endl;
	}

    void withdrawCash(double other_account_cash) {
        if(other_account_cash > this->account_cash) {
			std::cout << "Not enough cash!" << std::endl;
			return;
		}
		this->account_cash -= other_account_cash;
    }

    void depositCash(double deposit) {
		account_cash += deposit;
	}

    void setAccountName(const char * other_account_name) {
        strcpy_s(this->account_name, strlen(other_account_name) + 1, other_account_name);
    }

    void setAccountNumber(const char * other_account_number) {
        strcpy_s(this->account_number, strlen(other_account_number) + 1, other_account_number);
    }

    void setAccountCash(double other_account_cash) {
		this->account_cash = other_account_cash;
	}

    const char* getAccountName() const {
		return account_name;
	}

    const char* getAccountNumber() const {
		return account_number;
	}

    double getAccountCash() const {
		return account_cash;
	}

private:
    char account_name[21];
    char account_number[11];
    double account_cash;
};
//450 za semestrialnata
//*beray left the chat* roflz 
int main () {
	BankAccount bank_acc1;
    bank_acc1.depositCash(1000);
    bank_acc1.withdrawCash(500);
    bank_acc1.printBankAccount();
}