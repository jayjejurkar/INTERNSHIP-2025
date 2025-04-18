#include <iostream>
#include <string>

using namespace std;

void menu();
void account(int);

string AccountType[] = {"", "CHECKINGS", "SAVINGS"};
string response;

int AccountDetails[] = {
  1234,
  100,
       600
};

bool validatePin(int pin)
{
 if (pin == AccountDetails[0])
 {
    return true;
 }
   else
 {
  return false;
 }
}

bool proceed(string response)
{
   if (response == "y" || response == "Y")
    {
     return true;
    }
    else if (response == "n" || response == "N")
 {
    string exit;
     cout << "\n\n\n\t Thank you for banking with us.";
       cin >> exit;
     return false;
 }
   return false;
}


class AccountSettings
{
private:
  int type;
      int balance;
public:
     AccountSettings(int type)
  {
    this->type = type;
    this->balance = AccountDetails[this->type];
  }

 int getWithdraw()
 {
     int withdrawAmount;
    cout << "Please enter amount to withdrawn:\n " << endl;
        cin >> withdrawAmount;

      if (withdrawAmount <= this->balance)
      {
          int AccountBalance = this->balance -= withdrawAmount;
            cout << "Dispensing... ";
          cout << "$" << withdrawAmount << endl;
         AccountDetails[this->type] = AccountBalance;
        getBalance();
       }
       else
         {
             cout << "Insufficent funds" << endl;
           getBalance();
         }

       return 0;
 }

 int getDeposit()
 {
     int depositAmount;
       cout << "Please enter an amount to deposit:\n" << endl;
      cin >> depositAmount;

    int AccountBalance = this->balance += depositAmount;
         AccountDetails[this->type] = AccountBalance;

        cout << "\t$" << depositAmount << " was deposited into your account";
         getBalance();

      return 0;
 }

  int getTransfer()
  {
     int AmountTransfer;
     int TransferTo = this->type == 1 ? 2 : 1;

      cout << "Enter amount to transfer to your " << AccountType[TransferTo] << " account." << endl;
        cin >> AmountTransfer;

        if (AmountTransfer <= AccountDetails[this->type])
        {
             int NewBalance = this->balance -= AmountTransfer;
              AccountDetails[this->type] = NewBalance;

             int TransferedAmount = AccountDetails[TransferTo] += AmountTransfer;
               AccountDetails[TransferTo] = TransferedAmount;

         cout << "$" << AmountTransfer << " has been transfered to your " << AccountType[TransferTo] << " account." << endl;
           getBalance();
        }
        else
        {
           cout << "Insuffient funds." << endl;
         getBalance();
        }

        return 0;
  }

 int getBalance()
 {
   string confirmBalance;
      cout << "Would you like to check your " << AccountType[this->type] << " account balance? (y/n)\n" << endl;
      cin >> confirmBalance;

     if (confirmBalance == "y" || confirmBalance == "Y")
       {
         cout << "Your account balance is: $" << this->balance << endl;
       }

        cout << "\n\nWould you like to continue (y/n)?\n";
        cin >> response;

     if (proceed(response))
     {
        account(this->type);
     }

     return 0;
 }

};

void account(int option)
{
    cout << "\n\n"
         << AccountType[option] << "--\n\t1. Check balance"
         << "\n\t2. Withdraw from " << AccountType[option]
         << "\n\t3. Deposit to " << AccountType[option]
         << "\n\t4. Transfer "
         << "\n\t5. --Return to Menu." << endl;

       AccountSettings Account(option);

   int selectMenu;
     cin >> selectMenu;

       switch (selectMenu)
       {
           case 1:
                cout << Account.getBalance();
                 break;
           case 2:
             cout << Account.getWithdraw();
               break;
          case 3:
              cout << Account.getDeposit();
               break;
          case 4:
              cout << Account.getTransfer();
              break;
          case 5:
              menu();
               break;
          default:
               cout << "Would you like to continue (y/n)\n";
               cin >> response;
                proceed(response);

                if (proceed(response))
                   {
                     menu();
                   }
             break;
       }
}

void menu()
{
     int option;
      cout << "\n\nMain Menu--" << endl;
   cout << "\tPlease make a selection. " << endl;
       cout << "\t1. Checkings \n\t2. Savings \n\t3. Exit" << endl;
         cin >> option;

      switch (option)
     {
          case 1:
              account(option);
               break;
          case 2:
              account(option);
                break;
          default:
               cout << "Would you like to continue (y/n)\n";
               cin >> response;
               proceed(response);

               if (proceed(response))
                   {
                    menu();
                   }
             break;
     }
}


int main()
{
       int pin;
     cout << "Welcome to Bank of Programming.\n\tPlease enter your pin number to access your account:" << endl;

     do
     {
         cin >> pin;

          if (validatePin(pin))
           {
              menu();
           }
           else
             {
               cout << "Invalid pin. Please enter pin number:" << endl;
             }
     } while (!validatePin(pin));

     return 0;
}
