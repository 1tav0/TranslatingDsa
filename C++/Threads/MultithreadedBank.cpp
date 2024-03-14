#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

//a program where multiple threads need to perform transactions on multiple bank accounts. Each thread represents a bank teller, and they need to perform transactions like deposits and withdrawals on accounts while ensuring that they don't deadlock and that the accounts are updated safely.
class BankAccount{
  private: 
    //private balance member variable to store the account balance and a std::mutex named BalanceMutex to protect access to the balance data.
    int Balance;
    std::vector<std::mutex> DepositMutexes;
    std::vector<std::mutex> WithdrawMutexes;

  public: 
    BankAccount(int initialBalance, int numMutexes){
      Balance = initialBalance;
      DepositMutexes.resize(numMutexes);
      WithdrawMutexes.resize(numMutexes);
    }
    //Mutexes are used to ensure that these operations are thread-safe. std::lock_guard is used to lock the BalanceMutex for the duration of the function. ensures exclusive access to the bank account during these operations, preventing data races and ensuring consistency.
    void deposit(int amount, int i){
      std::lock_guard<std::mutex> lock(DepositMutexes[i]);
      // No need for try_lock here because we have a dedicated mutex for deposits.
      Balance += amount;
    }

    void withDraw(int amount, int i){
      std::lock_guard<std::mutex> lock(WithdrawMutexes[i]);
      Balance -= amount;
    }

    int getBalance(){

      int totalBalance = 0;

      for (int i = 0; i < getDepositMutexesSize(); i++){
        std::lock_guard<std::mutex> depositLock(DepositMutexes[i]);
        totalBalance += Balance;
      }
      for (int i = 0; i < getWithdrawMutexesSize(); i++){
        std::lock_guard<std::mutex> withdrawLock(WithdrawMutexes[i]);
        totalBalance -= Balance;
      }
        return totalBalance;
    }

    std::mutex& getDepositMutex(int i){
      return DepositMutexes[i];
    }

    int getDepositMutexesSize(){
      return DepositMutexes.size();
    }

    int getWithdrawMutexesSize(){
      return WithdrawMutexes.size();
    }

    std::mutex& getWithDrawMutex(int i){
      return WithdrawMutexes[i];
    }
};
//The performTransactions function simulates bank tellers performing a sequence of deposit and withdrawal transactions on the BankAccount. It accepts a reference to a BankAccount and the number of transactions to perform.
void performTransactions(BankAccount &account, int numTransactions){
    for (int i = 0; i < numTransactions; ++i){
      //std::unique_lock is used with std::defer_lock to create a lock object without immediately locking the mutex. This allows you to attempt to lock it later using std::try_lock.
      std::unique_lock<std::mutex> depositLock(account.getDepositMutex(i), std::defer_lock);
      std::unique_lock<std::mutex> withdrawLock(account.getWithDrawMutex(i), std::defer_lock);
      if(std::try_lock(depositLock, withdrawLock) == -1){
        //successfully locked the balance mutex, can perform transaction
        int transactionAmount = rand() % 100;
        //to randomly deposit or withdraw
        if(rand()%2==0){
          account.deposit(transactionAmount, i);
          std::cout << "Deposited: " << transactionAmount << std::endl;
        }else{
          account.withDraw(transactionAmount, i);
          std::cout << "WithDrawn: " << transactionAmount << std::endl;
        }
        // Unlock the unique_locks explicitly when done using them.
        depositLock.unlock();
        withdrawLock.unlock();
      }else{
        //could not lock the BalanceMutex
        std::cout << i << " Contention detected, could not perform transaction." << std::endl;
      }
    }
}

int main(){
    BankAccount account(1000, 10);
    int numTellers = 5; // specify the number of tellers
    int numTransactionPerTeller = 10; //number of transactions each teller should perform 
    std::vector<std::thread> tellers; //A vector of std::thread objects to represent the bank tellers

    for (int i = 0; i < numTellers; i++){
      tellers.emplace_back(performTransactions, std::ref(account), numTransactionPerTeller);
    }

    for(std::thread &teller: tellers){
      teller.join();
    }

    std::cout << "Final balance: " << account.getBalance() << std::endl;

    return 0;
}