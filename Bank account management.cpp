#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Account {
    int act_number;
    char customer_name[50];
    float bal;
    int act_type; 
};


void createAccount(struct Account accounts[], int *num_accounts) {
    struct Account new_account;
    
    printf("Enter customer name: ");
    scanf(" %[^\n]s", new_account.customer_name);
    
    printf("Enter account number: ");
    scanf("%d", &new_account.act_number);
    
    printf("Enter initial balance: ");
    scanf("%f", &new_account.bal);
    
    printf("Enter account type (Enter 1 for Savings and 2 for Current): ");
    scanf("%d", &new_account.act_type);
    
    accounts[*num_accounts] = new_account;
    (*num_accounts)++;
    
    printf("Account created successfully!\n");
}


void deposit(struct Account accounts[], int num_accounts) {
    int acc_num;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].act_number == acc_num) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            
            accounts[i].bal += amount;
            printf("Deposit successful! Current balance: %.2f\n", accounts[i].bal);
            return;
        }
    }
    
    printf("Account not found!\n");
}


void withdraw(struct Account accounts[], int num_accounts) {
    int acc_num;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].act_number == acc_num) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            
            if (accounts[i].bal >= amount) {
                accounts[i].bal -= amount;
                printf("Withdrawal successful! Current balance: %.2f\n", accounts[i].bal);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    
    printf("Account not found!\n");
}


void checkBalance(struct Account accounts[], int num_accounts) {
    int acc_num;
    
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].act_number == acc_num) {
            printf("Current balance for account %d: %.2f\n", acc_num, accounts[i].bal);
            return;
        }
    }
    
    printf("Account not found!\n");
}


void calculateInterest(struct Account accounts[], int num_accounts) {
    float interest_rate_savings = 0.05; 
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].act_type == 1) { // Savings account
            float interest = accounts[i].bal * interest_rate_savings;
            accounts[i].bal += interest;
            printf("Interest calculated for account %d. New balance: %.2f\n", accounts[i].act_number, accounts[i].bal);
        }
    }
}

int main() {
    struct Account accounts[50];
    int num_accounts = 0;
    int choice;
    
    do {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest (for Savings Accounts)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount(accounts, &num_accounts);
                break;
            case 2:
                deposit(accounts, num_accounts);
                break;
            case 3:
                withdraw(accounts, num_accounts);
                break;
            case 4:
                checkBalance(accounts, num_accounts);
                break;
            case 5:
                calculateInterest(accounts, num_accounts);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
