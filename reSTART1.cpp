#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for Aadhar
typedef struct Aadhar {
    char name[MAX];
    char address[MAX];
    char aadharNumber[MAX];
    struct Aadhar* next;
} Aadhar;

// Structure for PAN
typedef struct PAN {
    char name[MAX];
    char address[MAX];
    char panNumber[MAX];
    char aadharNumber[MAX];
    struct PAN* next;
    Aadhar* linkedAadhar;
} PAN;

// Structure for Bank Account
typedef struct BankAccount {
    char name[MAX];
    char panNumber[MAX];
    char bank[MAX];
    char accountNumber[MAX];
    double depositedAmount;
    struct BankAccount* next;
    PAN* linkedPAN;
} BankAccount;

// Structure for LPG
typedef struct LPG {
    char name[MAX];
    char accountNumber[MAX];
    char subsidyStatus[4]; // "YES" or "NO"
    struct LPG* next;
    BankAccount* linkedBankAccount;
} LPG;

// Function to create and insert a new Aadhar node at the end of the list
Aadhar* insertAadhar(Aadhar* head, char* name, char* address, char* aadharNumber) {
    Aadhar* newAadhar = (Aadhar*)malloc(sizeof(Aadhar));
    strcpy(newAadhar->name, name);
    strcpy(newAadhar->address, address);
    strcpy(newAadhar->aadharNumber, aadharNumber);
    newAadhar->next = NULL;
    
    if (head == NULL) {
        return newAadhar;
    }
    
    Aadhar* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newAadhar;
    return head;
}

// Function to create and insert a new PAN node at the end of the list and link to Aadhar
PAN* insertPAN(PAN* head, Aadhar* aadharList, char* name, char* address, char* panNumber, char* aadharNumber) {
    PAN* newPAN = (PAN*)malloc(sizeof(PAN));
    strcpy(newPAN->name, name);
    strcpy(newPAN->address, address);
    strcpy(newPAN->panNumber, panNumber);
    strcpy(newPAN->aadharNumber, aadharNumber);
    newPAN->next = NULL;
    newPAN->linkedAadhar = NULL;
    
    Aadhar* tempAadhar = aadharList;
    while (tempAadhar != NULL) {
        if (strcmp(tempAadhar->aadharNumber, aadharNumber) == 0) {
            newPAN->linkedAadhar = tempAadhar;
            break;
        }
        tempAadhar = tempAadhar->next;
    }
    
    if (head == NULL) {
        return newPAN;
    }
    
    PAN* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newPAN;
    return head;
}

// Function to create and insert a new Bank Account node at the end of the list and link to PAN
BankAccount* insertBankAccount(BankAccount* head, PAN* panList, char* name, char* panNumber, char* bank, char* accountNumber, double depositedAmount) {
    BankAccount* newAccount = (BankAccount*)malloc(sizeof(BankAccount));
    strcpy(newAccount->name, name);
    strcpy(newAccount->panNumber, panNumber);
    strcpy(newAccount->bank, bank);
    strcpy(newAccount->accountNumber, accountNumber);
    newAccount->depositedAmount = depositedAmount;
    newAccount->next = NULL;
    newAccount->linkedPAN = NULL;
    
    PAN* tempPAN = panList;
    while (tempPAN != NULL) {
        if (strcmp(tempPAN->panNumber, panNumber) == 0) {
            newAccount->linkedPAN = tempPAN;
            break;
        }
        tempPAN = tempPAN->next;
    }
    
    if (head == NULL) {
        return newAccount;
    }
    
    BankAccount* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newAccount;
    return head;
}

// Function to create and insert a new LPG node at the end of the list and link to Bank Account
LPG* insertLPG(LPG* head, BankAccount* bankList, char* name, char* accountNumber, char* subsidyStatus) {
    LPG* newLPG = (LPG*)malloc(sizeof(LPG));
    strcpy(newLPG->name, name);
    strcpy(newLPG->accountNumber, accountNumber);
    strcpy(newLPG->subsidyStatus, subsidyStatus);
    newLPG->next = NULL;
    newLPG->linkedBankAccount = NULL;
    
    BankAccount* tempBank = bankList;
    while (tempBank != NULL) {
        if (strcmp(tempBank->accountNumber, accountNumber) == 0) {
            newLPG->linkedBankAccount = tempBank;
            break;
        }
        tempBank = tempBank->next;
    }
    
    if (head == NULL) {
        return newLPG;
    }
    
    LPG* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newLPG;
    return head;
}

// Function to print Aadhar numbers without PAN numbers
void printAadharWithoutPAN(Aadhar* aadharList, PAN* panList) {
    Aadhar* aadharTemp = aadharList;
    int found;
    while (aadharTemp != NULL) {
        found = 0;
        PAN* panTemp = panList;
        while (panTemp != NULL) {
            if (strcmp(aadharTemp->aadharNumber, panTemp->aadharNumber) == 0) {
                found = 1;
                break;
            }
            panTemp = panTemp->next;
        }
        if (!found) {
            printf("%s\n", aadharTemp->aadharNumber);
        }
        aadharTemp = aadharTemp->next;
    }
}

// Function to print people with multiple PAN numbers
void printPeopleWithMultiplePANs(PAN* panList) {
    PAN* panTemp1 = panList;
    while (panTemp1 != NULL) {
        PAN* panTemp2 = panTemp1->next;
        int count = 0;
        while (panTemp2 != NULL) {
            if (strcmp(panTemp1->aadharNumber, panTemp2->aadharNumber) == 0) {
                count++;
            }
            panTemp2 = panTemp2->next;
        }
        if (count > 0) {
            printf("%s\n", panTemp1->name);
        }
        panTemp1 = panTemp1->next;
    }
}

// Function to print people with multiple bank accounts under multiple PAN numbers
void printPeopleWithMultipleBankAccounts(PAN* panList, BankAccount* bankList) {
    PAN* panTemp1 = panList;
    while (panTemp1 != NULL) {
        PAN* panTemp2 = panTemp1->next;
        int count = 0;
        while (panTemp2 != NULL) {
            if (strcmp(panTemp1->aadharNumber, panTemp2->aadharNumber) == 0) {
                count++;
            }
            panTemp2 = panTemp2->next;
        }
        if (count > 0) {
            BankAccount* bankTemp = bankList;
            while (bankTemp != NULL) {
                if (strcmp(panTemp1->panNumber, bankTemp->panNumber) == 0) {
                    printf("%s\n", bankTemp->name);
                }
                bankTemp = bankTemp->next;
            }
        }
        panTemp1 = panTemp1->next;
    }
}

// Function to print details of person who has availed LPG subsidy
void printPersonWithLPGSubsidy(LPG* lpgList) {
    LPG* lpgTemp = lpgList;
    while (lpgTemp != NULL) {
        if (strcmp(lpgTemp->subsidyStatus, "YES") == 0) {
            printf("Name: %s\n", lpgTemp->name);
            printf("Account Number: %s\n", lpgTemp->accountNumber);
            BankAccount* linkedBankAccount = lpgTemp->linkedBankAccount;
            if (linkedBankAccount != NULL) {
                PAN* linkedPAN = linkedBankAccount->linkedPAN;
                if (linkedPAN != NULL) {
                    Aadhar* linkedAadhar = linkedPAN->linkedAadhar;
                    if (linkedAadhar != NULL) {
                        printf("Aadhar Number: %s\n", linkedAadhar->aadharNumber);
                    }
                }
            }
        }
        lpgTemp = lpgTemp->next;
    }
}

// Function to print people with total savings > X and availed LPG subsidy
void printPeopleWithSavingsAndLPG(LPG* lpgList, BankAccount* bankList, double amountX) {
    LPG* lpgTemp = lpgList;
    while (lpgTemp != NULL) {
        if (strcmp(lpgTemp->subsidyStatus, "YES") == 0) {
            BankAccount* bankTemp = bankList;
            while (bankTemp != NULL) {
                if (strcmp(lpgTemp->accountNumber, bankTemp->accountNumber) == 0 && bankTemp->depositedAmount > amountX) {
                    printf("Name: %s\n", lpgTemp->name);
                    printf("Account Number: %s\n", lpgTemp->accountNumber);
                    printf("Deposited Amount: %.2f\n", bankTemp->depositedAmount);
                }
                bankTemp = bankTemp->next;
            }
        }
        lpgTemp = lpgTemp->next;
    }
}

// Function to check for inconsistencies in names across different lists
void checkNameConsistency(Aadhar* aadharList, PAN* panList, BankAccount* bankList, LPG* lpgList) {
    Aadhar* aadharTemp = aadharList;
    while (aadharTemp != NULL) {
        PAN* panTemp = panList;
        while (panTemp != NULL) {
            if (strcmp(aadharTemp->aadharNumber, panTemp->aadharNumber) == 0) {
                if (strcmp(aadharTemp->name, panTemp->name) != 0) {
                    printf("Name mismatch between Aadhar and PAN: %s (Aadhar) vs %s (PAN)\n", aadharTemp->name, panTemp->name);
                }
            }
            panTemp = panTemp->next;
        }
        aadharTemp = aadharTemp->next;
    }

    PAN* panTemp = panList;
    while (panTemp != NULL) {
        BankAccount* bankTemp = bankList;
        while (bankTemp != NULL) {
            if (strcmp(panTemp->panNumber, bankTemp->panNumber) == 0) {
                if (strcmp(panTemp->name, bankTemp->name) != 0) {
                    printf("Name mismatch between PAN and Bank Account: %s (PAN) vs %s (Bank Account)\n", panTemp->name, bankTemp->name);
                }
            }
            bankTemp = bankTemp->next;
        }
        panTemp = panTemp->next;
    }

    BankAccount* bankTemp = bankList;
    while (bankTemp != NULL) {
        LPG* lpgTemp = lpgList;
        while (lpgTemp != NULL) {
            if (strcmp(bankTemp->accountNumber, lpgTemp->accountNumber) == 0) {
                if (strcmp(bankTemp->name, lpgTemp->name) != 0) {
                    printf("Name mismatch between Bank Account and LPG: %s (Bank Account) vs %s (LPG)\n", bankTemp->name, lpgTemp->name);
                }
            }
            lpgTemp = lpgTemp->next;
        }
        bankTemp = bankTemp->next;
    }
}

int main() {
    Aadhar* aadharList = NULL;
    PAN* panList = NULL;
    BankAccount* bankAccountList = NULL;
    LPG* lpgList = NULL;
    
    // Populate Aadhar list
    aadharList = insertAadhar(aadharList, "Aditi", "123 Main St", "A123");
    aadharList = insertAadhar(aadharList, "Arnav", "456 Elm St", "A456");
    aadharList = insertAadhar(aadharList, "Sarthak", "789 Oak St", "A789");
    aadharList = insertAadhar(aadharList, "Aleena", "101 Pine St", "A101");
    aadharList = insertAadhar(aadharList, "Mayank", "202 Maple St", "A202");
    aadharList = insertAadhar(aadharList, "Abhinav", "303 Cedar St", "A303");
    
    // Populate PAN list
    panList = insertPAN(panList, aadharList, "Aditi", "123 Main St", "P123", "A123");
    panList = insertPAN(panList, aadharList, "Aditi", "123 Main St", "P124", "A123"); // Multiple PAN for John Doe
    panList = insertPAN(panList, aadharList, "Sarthak", "789 Oak St", "P789", "A789");
    panList = insertPAN(panList, aadharList, "Aleena", "101 Pine St", "P101", "A101");
    panList = insertPAN(panList, aadharList, "Mayank", "202 Maple St", "P202", "A202");
    panList = insertPAN(panList, aadharList, "Abhinav", "303 Cedar St", "P303", "A303");
    panList = insertPAN(panList, aadharList, "Abhinav", "303 Cedar St", "P304", "A303"); // Multiple PAN for David Wilson
    
    // Populate Bank Account list
    bankAccountList = insertBankAccount(bankAccountList, panList, "Aditi", "P123", "Bank1", "B123", 5000);
    bankAccountList = insertBankAccount(bankAccountList, panList, "Aditi", "P124", "Bank2", "B124", 7000); // Multiple bank accounts for John Doe
    bankAccountList = insertBankAccount(bankAccountList, panList, "Sarthak", "P789", "Bank1", "B789", 12000);
    bankAccountList = insertBankAccount(bankAccountList, panList, "Aleena", "P101", "Bank2", "B101", 8000);
    bankAccountList = insertBankAccount(bankAccountList, panList, "Mayank", "P202", "Bank3", "B202", 15000);
    bankAccountList = insertBankAccount(bankAccountList, panList, "Abhinav", "P303", "Bank4", "B303", 6000);
    bankAccountList = insertBankAccount(bankAccountList, panList, "Abhinav", "P304", "Bank5", "B304", 9000); // Multiple bank accounts for David Wilson
    
    // Populate LPG list
    lpgList = insertLPG(lpgList, bankAccountList, "Aditi", "B123", "YES");
    lpgList = insertLPG(lpgList, bankAccountList, "Sarthak", "B789", "YES");
    lpgList = insertLPG(lpgList, bankAccountList, "Aleena", "B101", "NO");
    lpgList = insertLPG(lpgList, bankAccountList, "Mayank", "B202", "YES");
    lpgList = insertLPG(lpgList, bankAccountList, "Abhinav", "B303", "YES");
    lpgList = insertLPG(lpgList, bankAccountList, "Abhinav", "B304", "NO"); // Multiple accounts, some with subsidy, some without
    
    // Example function calls to demonstrate functionality
    printf("Aadhar numbers without PAN numbers:\n");
    printAadharWithoutPAN(aadharList, panList);
    
    printf("\nPeople with multiple PAN numbers:\n");
    printPeopleWithMultiplePANs(panList);
    
    printf("\nPeople with multiple bank accounts under multiple PAN numbers:\n");
    printPeopleWithMultipleBankAccounts(panList, bankAccountList);
    
    printf("\nDetails of person who has availed LPG subsidy:\n");
    printPersonWithLPGSubsidy(lpgList);
    
    printf("\nPeople with total savings > 10000 and availed LPG subsidy:\n");
    printPeopleWithSavingsAndLPG(lpgList, bankAccountList, 10000);
    
    printf("\nChecking name consistency across lists:\n");
    checkNameConsistency(aadharList, panList, bankAccountList, lpgList);
    
    return 0;
}
