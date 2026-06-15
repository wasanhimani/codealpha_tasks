#include<iostream>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

class Transaction{
public:
    string type;
    double amount;
    string date;

    Transaction(string t, double amt){
        type = t;
        amount = amt;
        time_t now = time(0);
        date = ctime(&now);
        date.pop_back();
    }

    void display(){
        cout << "Type: " << type << endl;
        cout << "Amount: " << amount << endl;
        cout << "Date: " << date << endl;
        cout << "*********" << endl;
    }
};

class Account{
public:
    int accNumber;
    double balance;
    vector<Transaction> transactions;

    Account(int no, double bal){
        accNumber = no;
        balance = bal;
    }

    void deposit(double amount){
        if(amount <= 0){
            cout << " please Enter a valid amount!" << endl;
            return;
        }
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful!" << endl;
    }

    bool withdraw(double amount){
        if(amount <= 0){
            cout << " please Enter a valid amount!" << endl;
            return false;
        }
        if(amount > balance){
            cout << "sorry!Not enough balance!" << endl;
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrawal successful!" << endl;
        return true;
    }

    bool transfer(Account &receiver, double amount){
        if(withdraw(amount)){
            receiver.balance += amount;
            transactions.push_back(Transaction("Transfer Sent", amount));
            receiver.transactions.push_back(Transaction("Transfer Received", amount));
            cout << "Transfer successful!" << endl;
            return true;
        }
        return false;
    }

    void showTransactions(){
        if(transactions.empty()){
            cout << "No transactions yet." << endl;
            return;
        }
        cout << "\n== Transaction History for Account " << accNumber << " ==" << endl;
        for(int i = 0; i < transactions.size(); i++){
            transactions[i].display();
        }
    }

    void displayInfo(){
        cout << "Account No: " << accNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Customer{
public:
    int customerId;
    string name;
    vector<Account> accounts;

    Customer(int id, string n){
        customerId = id;
        name = n;
    }

    void createAccount(int accno, double initialBalance){
        accounts.push_back(Account(accno, initialBalance));
        cout << "Account created successfully!" << endl;
    }

    Account* findAccount(int accno){
        for(int i = 0; i < accounts.size(); i++){
            if(accounts[i].accNumber == accno)
                return &accounts[i];
        }
        return nullptr;
    }

    void displayInfo(){
        cout << "\nCustomer ID: " << customerId << endl;
        cout << "Name: " << name << endl;
        cout << "Accounts:" << endl;
        for(int i = 0; i < accounts.size(); i++){
            accounts[i].displayInfo();
        }
    }
};

class Bank{
public:
    vector<Customer> customers;

    void createCustomer(int id, string name){
        customers.push_back(Customer(id, name));
        cout << "Customer added!" << endl;
    }

    Customer* findCustomer(int id){
        for(int i = 0; i < customers.size(); i++){
            if(customers[i].customerId == id)
                return &customers[i];
        }
        return nullptr;
    }
};

int main(){
    Bank bank;
    bank.createCustomer(1, "Himani");

    Customer* customer = bank.findCustomer(1);

    if(customer != nullptr){
        customer->createAccount(1001, 5000);
        customer->createAccount(1002, 3000);

        Account* acc1 = customer->findAccount(1001);
        Account* acc2 = customer->findAccount(1002);

        if(acc1 != nullptr && acc2 != nullptr){
            acc1->deposit(2000);
            acc1->withdraw(1000);
            acc1->transfer(*acc2, 1500);

            customer->displayInfo();

            cout << "Account 1001 Transactions:" << endl;
            acc1->showTransactions();

            cout << "Account 1002 Transactions:" << endl;
            acc2->showTransactions();
        }
    }

    return 0;
}