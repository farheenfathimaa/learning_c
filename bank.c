/*Create a structure to specify data of customers in a bank. The data
to be stored is: Account number, Name, Balance in account.
Assume maximum of 200 customers in the bank.
(1) Write a function to print the Account number and name of
each customer with balance below Rs. 100.
(2) If a customer requests for withdrawal or deposit, the form
contains the fields:
Acct. no, amount, code (1 for deposit, 0 for withdrawal)
Write a program to give a message, “The balance is insufficient
for the specified withdrawal”, if on withdrawal the balance falls
below Rs. 100.*/
#include <stdio.h>
#include <string.h>

// Define a structure to store customer data
struct Customer {
    int accountNumber;
    char name[50];
    float balance;
};

// Function to print account numbers and names of customers with balances below Rs. 100
void printCustomersWithLowBalance(struct Customer customers[], int numCustomers) {
    printf("Customers with balance below Rs. 100:\n");
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].balance < 100) {
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: Rs. %.2f\n", customers[i].balance);
            printf("-------------------------\n");
        }
    }
}

// Function to handle customer withdrawal or deposit
void handleTransaction(struct Customer customers[], int accountNum, float amount, int code) {
    for (int i = 0; i < 200; i++) {
        if (customers[i].accountNumber == accountNum) {
            if (code == 1) { // Deposit
                customers[i].balance += amount;
                printf("Deposit successful. New balance: Rs. %.2f\n", customers[i].balance);
            } else if (code == 0) { // Withdrawal
                if (customers[i].balance >= amount + 100) {
                    customers[i].balance -= amount;
                    printf("Withdrawal successful. New balance: Rs. %.2f\n", customers[i].balance);
                } else {
                    printf("Insufficient balance for withdrawal.\n");
                }
            }
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    struct Customer customers[200];
    int numCustomers = 0;

    // Read and store customer data
    printf("Enter customer data (Account Number, Name, Balance):\n");
    while (numCustomers < 200) {
        printf("Customer %d:\n", numCustomers + 1);
        scanf("%d", &customers[numCustomers].accountNumber);
        if (customers[numCustomers].accountNumber == -1) {
            break; // Exit input loop if -1 is entered
        }
        scanf("%s", customers[numCustomers].name);
        scanf("%f", &customers[numCustomers].balance);
        numCustomers++;
    }

    // Print customers with balances below Rs. 100
    printCustomersWithLowBalance(customers, numCustomers);

    // Handle customer transactions
    int accountNum, code;
    float amount;
    printf("Enter account number (-1 to exit): ");
    scanf("%d", &accountNum);
    while (accountNum != -1) {
        printf("Enter transaction code (1 for deposit, 0 for withdrawal): ");
        scanf("%d", &code);
        printf("Enter amount: Rs. ");
        scanf("%f", &amount);
        handleTransaction(customers, accountNum, amount, code);
        printf("Enter account number (-1 to exit): ");
        scanf("%d", &accountNum);
    }

    return 0;
}