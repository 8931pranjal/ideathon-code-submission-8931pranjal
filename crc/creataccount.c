#include "header.h"


void insertAccount(struct Account** root, struct Account* newAccount) {
    if (*root == NULL) {
        *root = newAccount;
    } else {
        if (newAccount->accountNumber < (*root)->accountNumber) {
            insertAccount(&(*root)->left, newAccount);
        } else {
            insertAccount(&(*root)->right, newAccount);
        }
    }
}

struct Account* searchAccount(struct Account* root, int accountNumber) {
    if (root == NULL || root->accountNumber == accountNumber) {
        return root;
    }

    if (accountNumber < root->accountNumber) {
        return searchAccount(root->left, accountNumber);
    }

    return searchAccount(root->right, accountNumber);
}




void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
    struct Customer newCustomer;

    
    printf("Enter customer name: ");
    scanf(" %[^\n]", newCustomer.name); 

    
    for (int i = 0; newCustomer.name[i] != '\0'; i++) {
        if (!isalpha(newCustomer.name[i]) && newCustomer.name[i] != ' ') {
            printf("Invalid name! Please enter alphabetic characters and spaces only.\n");
            free(newAccount); 
            return;
        }
    }

    printf("Enter customer address: ");
    scanf(" %[^\n]", newCustomer.address);

    printf("Enter customer contact number: ");
    scanf("%s", newCustomer.contact);

    
    if (strlen(newCustomer.contact) != 10) {
        printf("Invalid contact number! Please enter exactly 10 digits.\n");
        free(newAccount); 
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if (!isdigit(newCustomer.contact[i])) {
            printf("Invalid contact number! Please enter numeric digits only.\n");
            free(newAccount); 
            return;
        }
    }

    
    printf("Set up PIN (4 digits): ");
    scanf("%d", &newAccount->pin);

    
    if (newAccount->pin < 1000 || newAccount->pin > 9999) {
        printf("Invalid PIN! Please enter a 4-digit PIN.\n");
        free(newAccount); 
        return;
    }
    newAccount->accountNumber = 1000 + numAccounts;

    
    newAccount->balance = 0;

    
    strcpy(newAccount->type, "Savings");

    
    newAccount->customer = newCustomer;

    
    insertAccount(&root, newAccount);

    ++numAccounts;
    printf("Account created successfully. Account number: %d\n", newAccount->accountNumber);
    
}
