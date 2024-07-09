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









//*****************************create nodes**********************************

// Function to create a new Aadhar node
Aadhar* createAadhar(char* name, char* address, char* aadharNumber) {
    Aadhar* newAadhar = (Aadhar*)malloc(sizeof(Aadhar));
    strcpy(newAadhar->name, name);
    strcpy(newAadhar->address, address);
    strcpy(newAadhar->aadharNumber, aadharNumber);
    newAadhar->next = NULL;
    return newAadhar;
}

// Function to create a new PAN node
PAN* createPAN(char* name, char* address, char* panNumber, char* aadharNumber) {
    PAN* newPAN = (PAN*)malloc(sizeof(PAN));
    strcpy(newPAN->name, name);
    strcpy(newPAN->address, address);
    strcpy(newPAN->panNumber, panNumber);
    strcpy(newPAN->aadharNumber, aadharNumber);
    newPAN->next = NULL;
    newPAN->linkedAadhar = NULL;
    return newPAN;
}

// Function to create a new Bank Account node
BankAccount* createBankAccount(char* name, char* panNumber, char* bank, char* accountNumber, double depositedAmount) {
    BankAccount* newAccount = (BankAccount*)malloc(sizeof(BankAccount));
    strcpy(newAccount->name, name);
    strcpy(newAccount->panNumber, panNumber);
    strcpy(newAccount->bank, bank);
    strcpy(newAccount->accountNumber, accountNumber);
    newAccount->depositedAmount = depositedAmount;
    newAccount->next = NULL;
    newAccount->linkedPAN = NULL;
    return newAccount;
}

// Function to create a new LPG node
LPG* createLPG(char* name, char* accountNumber, char* subsidyStatus) {
    LPG* newLPG = (LPG*)malloc(sizeof(LPG));
    strcpy(newLPG->name, name);
    strcpy(newLPG->accountNumber, accountNumber);
    strcpy(newLPG->subsidyStatus, subsidyStatus);
    newLPG->next = NULL;
    newLPG->linkedBankAccount = NULL;
    return newLPG;
}


//*************************linking of lists**************************************

// Function to link PAN node to Aadhar node
void linkPANToAadhar(PAN* panNode, Aadhar* aadharList) {
    while (aadharList != NULL) {
        if (strcmp(panNode->aadharNumber, aadharList->aadharNumber) == 0) {
            panNode->linkedAadhar = aadharList;
            return;
        }
        aadharList = aadharList->next;
    }
}

// Function to link Bank Account node to PAN node
void linkBankAccountToPAN(BankAccount* bankAccountNode, PAN* panList) {
    while (panList != NULL) {
        if (strcmp(bankAccountNode->panNumber, panList->panNumber) == 0) {
            bankAccountNode->linkedPAN = panList;
            return;
        }
        panList = panList->next;
    }
}

// Function to link LPG node to Bank Account node
void linkLPGToBankAccount(LPG* lpgNode, BankAccount* bankList) {
    while (bankList != NULL) {
        if (strcmp(lpgNode->accountNumber, bankList->accountNumber) == 0) {
            lpgNode->linkedBankAccount = bankList;
            return;
        }
        bankList = bankList->next;
    }
}




//********************print functions**************************

void printAadharList(Aadhar* aadharList) {
    while (aadharList != NULL) {
        printf("Name: %s\n", aadharList->name);
        printf("Address: %s\n", aadharList->address);
        printf("Aadhar Number: %s\n", aadharList->aadharNumber);
        printf("\n");
        aadharList = aadharList->next;
    }
}

void printPANList(PAN* panList) {
    while (panList != NULL) {
        printf("Name: %s\n", panList->name);
        printf("Address: %s\n", panList->address);
        printf("PAN Number: %s\n", panList->panNumber);
        printf("Aadhar Number: %s\n", panList->aadharNumber);
        if (panList->linkedAadhar != NULL) {
            printf("Linked Aadhar: %s\n", panList->linkedAadhar->aadharNumber);
        } else {
            printf("Linked Aadhar: None\n");
        }
        printf("\n");
        panList = panList->next;
    }
}

// Function to print the details of Bank Account nodes
void printBankAccountList(BankAccount* bankList) {
    while (bankList != NULL) {
        printf("Name: %s\n", bankList->name);
        printf("PAN Number: %s\n", bankList->panNumber);
        printf("Bank: %s\n", bankList->bank);
        printf("Account Number: %s\n", bankList->accountNumber);
        printf("Deposited Amount: %.2f\n", bankList->depositedAmount);
        if (bankList->linkedPAN != NULL) {
            printf("Linked PAN: %s\n", bankList->linkedPAN->panNumber);
        } else {
            printf("Linked PAN: None\n");
        }
        printf("\n");
        bankList = bankList->next;
    }
}

// Function to print the details of LPG nodes
void printLPGList(LPG* lpgList) {
    while (lpgList != NULL) {
        printf("Name: %s\n", lpgList->name);
        printf("Account Number: %s\n", lpgList->accountNumber);
        printf("Subsidy Status: %s\n", lpgList->subsidyStatus);
        if (lpgList->linkedBankAccount != NULL) {
            printf("Linked Bank Account: %s\n", lpgList->linkedBankAccount->accountNumber);
        } else {
            printf("Linked Bank Account: None\n");
        }
        printf("\n");
        lpgList = lpgList->next;
    }
}

//***********************************QUESTIONS*************************************

// Function to print names, addresses, and Aadhar numbers of people with Aadhar but no PAN
void printAadharWithoutPAN(Aadhar* aadharList, PAN* panList) {
    while (aadharList != NULL) {
        PAN* temp = panList;
        int found = 0;
        while (temp != NULL) {
            if (strcmp(aadharList->aadharNumber, temp->aadharNumber) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            printf("Name: %s\n", aadharList->name);
            printf("Address: %s\n", aadharList->address);
            printf("Aadhar Number: %s\n", aadharList->aadharNumber);
            printf("\n");
        }
        aadharList = aadharList->next;
    }
}

void printPeopleWithMultiplePANs(PAN* panList) {
    PAN* current = panList;
    while (current != NULL) {
        int count = 0;
        PAN* temp = panList;
        while (temp != NULL) {
            if (strcmp(current->aadharNumber, temp->aadharNumber) == 0) {
                count++;
            }
            temp = temp->next;
        }
        if (count > 1) {
            printf("Name: %s\n", current->name);
            printf("Address: %s\n", current->address);
            printf("Aadhar Number: %s\n", current->aadharNumber);
            printf("PAN Numbers: ");
            temp = panList;
            while (temp != NULL) {
                if (strcmp(current->aadharNumber, temp->aadharNumber) == 0) {
                    printf("%s ", temp->panNumber);
                }
                temp = temp->next;
            }
            printf("\n\n");
        }
        // Move to the next unique Aadhar number to avoid duplicate printing
        char uniqueAadharNumber[MAX];
        strcpy(uniqueAadharNumber, current->aadharNumber);
        while (current != NULL && strcmp(current->aadharNumber, uniqueAadharNumber) == 0) {
            current = current->next;
        }
    }
}

void printPeopleWithMultipleBankAccounts(PAN* panList, BankAccount* bankList) {
    PAN* currentPAN = panList;

    // Traverse the PAN list
    while (currentPAN != NULL) {
        int panCount = 0;
        BankAccount* currentBank = bankList;

        // Count how many bank accounts are associated with the current PAN
        while (currentBank != NULL) {
            if (strcmp(currentBank->panNumber, currentPAN->panNumber) == 0) {
                panCount++;
            }
            currentBank = currentBank->next;
        }

        // If the PAN has more than one bank account associated, print details
        if (panCount > 1) {
            // Print details from linked Aadhar
            Aadhar* linkedAadhar = currentPAN->linkedAadhar;
            if (linkedAadhar != NULL) {
                printf("Name: %s\n", linkedAadhar->name);
                printf("Address: %s\n", linkedAadhar->address);
                printf("Aadhar Number: %s\n", linkedAadhar->aadharNumber);
                printf("Bank Account: %s, PAN Count: %d\n\n", currentPAN->panNumber, panCount);
            }
        }

        // Move to the next PAN node
        currentPAN = currentPAN->next;
    }
}

void printPersonWithLPGSubsidy(LPG* lpgList) {
    LPG* currentLPG = lpgList;

    while (currentLPG != NULL) {
        if (strcmp(currentLPG->subsidyStatus, "YES") == 0) {
            // Assuming you have pointers to Aadhar, PAN, and BankAccount nodes within LPG
            BankAccount* linkedBank = currentLPG->linkedBankAccount;
            PAN* linkedPAN = linkedBank->linkedPAN;
			Aadhar* linkedAadhar = linkedPAN->linkedAadhar;
          

            // Print details if all necessary details are found
            if (linkedAadhar != NULL && linkedPAN != NULL && linkedBank != NULL) {
                printf("Name: %s\n", linkedAadhar->name);
                printf("Address: %s\n", linkedAadhar->address);
                printf("Aadhar Number: %s\n", linkedAadhar->aadharNumber);
                printf("PAN Number: %s\n", linkedPAN->panNumber);
                printf("Bank Name: %s\n", linkedBank->bank);
                printf("Bank Account Number: %s\n", linkedBank->accountNumber);
                printf("Deposited Amount: %.2f\n\n", linkedBank->depositedAmount);
            }
        }

        currentLPG = currentLPG->next;
    }

}

// Function to calculate total savings in all bank accounts for a given PAN number
double calculateTotalSavings(BankAccount* bankList, char* panNumber) {
    double totalSavings = 0.0;
    BankAccount* currentBank = bankList;

    while (currentBank != NULL) {
        if (strcmp(currentBank->panNumber, panNumber) == 0) {
            totalSavings += currentBank->depositedAmount;
        }
        currentBank = currentBank->next;
    }

    return totalSavings;
}

// Function to print details of people meeting the criteria
void printPeopleWithSavingsAndLPG(LPG* lpgList, BankAccount* bankList, double amountX) {
    LPG* currentLPG = lpgList;

    while (currentLPG != NULL) {
        if (strcmp(currentLPG->subsidyStatus, "YES") == 0) {
            // Assuming each LPG node has pointers to Aadhar and PAN nodes
           BankAccount* linkedBank = currentLPG->linkedBankAccount;
            PAN* linkedPAN = linkedBank->linkedPAN;
			Aadhar* linkedAadhar = linkedPAN->linkedAadhar;

                double totalSavings = calculateTotalSavings(bankList, linkedPAN->panNumber);
                if (totalSavings > amountX) {
                    printf("Name: %s\n", linkedAadhar->name);
                    printf("Address: %s\n", linkedAadhar->address);
                    printf("Aadhar Number: %s\n", linkedAadhar->aadharNumber);
                    printf("Total Savings: %.2f\n", totalSavings);
                    printf("Bank Name: %s\n\n",linkedBank->bank);
                }
        }
        currentLPG = currentLPG->next;
    }
}

// Function to print inconsistent data
void printInconsistentData(Aadhar* aadharList, PAN* panList, BankAccount* bankList, LPG* lpgList) {
    // Traverse through Aadhar list and compare names
    Aadhar* currentAadhar = aadharList;
//    while (currentAadhar != NULL) {
        PAN* currentPAN = panList;
        BankAccount* currentBank = bankList;
        LPG* currentLPG = lpgList;

        // Compare name with PAN list
        while (currentPAN != NULL) {
            if (strcmp(currentAadhar->aadharNumber, currentPAN->aadharNumber) == 0 &&
                strcmp(currentAadhar->name, currentPAN->name) != 0) {
                printf("Inconsistent data found for Aadhar Number due to PAN: %s\n", currentAadhar->aadharNumber);
                printf("Aadhar Name: %s\n", currentAadhar->name);
                printf("PAN Name: %s\n\n", currentPAN->name);
            }
            else{
            	currentAadhar=currentAadhar->next;
			}
            currentPAN = currentPAN->next;
        }
		currentAadhar = aadharList;
        // Compare name with Bank Account list
        while (currentBank != NULL) {
            if (strcmp(currentPAN->panNumber, currentPAN->panNumber) == 0 &&strcmp(currentAadhar->name, currentBank->name) != 0) {
                printf("Inconsistent data found for Aadhar Number due to BANK: %s\n", currentAadhar->aadharNumber);
                printf("Aadhar Name: %s\n", currentAadhar->name);
                printf("Bank Account Name: %s\n\n", currentBank->name);
            }
            else{
            	currentAadhar=currentAadhar->next;
			}
            currentBank = currentBank->next;
        }
		currentAadhar = aadharList;
        // Compare name with LPG list
        while (currentLPG != NULL) {
            if (strcmp(currentAadhar->name, currentLPG->name) != 0) {
                printf("Inconsistent data found for Aadhar Number due to LPG: %s\n", currentAadhar->aadharNumber);
                printf("Aadhar Name: %s\n", currentAadhar->name);
                printf("LPG Name: %s\n\n", currentLPG->name);
            }
            else{
			
           currentAadhar=currentAadhar->next;
       }
        currentLPG = currentLPG->next;
		}

    
    //}
}











int main() {
    // Creating Aadhar nodes
    Aadhar* aadhar1 = createAadhar("Alice", "123 Main St", "Aadhar123");
    Aadhar* aadhar2 = createAadhar("Bob", "456 Oak St", "Aadhar456");
    Aadhar* aadhar3 = createAadhar("John", "123 Main Street", "Aadhar789");
    aadhar1->next = aadhar2;
    aadhar2->next = aadhar3;
//    printAadharList(aadhar1);
    
    // Creating PAN nodes
    PAN* pan1 = createPAN("Ali1", "123 Main St", "PAN123", "Aadhar123");
	//bob does not have pan
    PAN* pan2 = createPAN("Ali2","123 Main St", "PAN321" ,"Aadhar123");
    pan1->next=pan2;
	PAN* pan3 = createPAN("John", "123 Main Street", "PAN879", "Aadhar789");
	pan2->next=pan3;
    // Linking PAN nodes to Aadhar nodes
    linkPANToAadhar(pan1, aadhar1);
    linkPANToAadhar(pan2, aadhar1);
    linkPANToAadhar(pan3, aadhar3);
    
//    printf("Aadhar List:\n");
//    printAadharList(aadhar1);
//
//    printf("PAN List:\n");
//    printPANList(pan1);
    
    // Printing Aadhar numbers without PAN numbers
    printf("Aadhar numbers without PAN numbers:\n");
    printAadharWithoutPAN(aadhar1, pan1);
    
    // Print names, addresses, and Aadhar numbers of people with multiple PAN numbers
    printf("People with multiple PAN numbers:\n");
    printPeopleWithMultiplePANs(pan1);
    
    // Creating Bank Account nodes
    BankAccount* bank1 = createBankAccount("Alice", "PAN123", "Bank A", "12345", 1000.0);
    BankAccount* bank2 = createBankAccount("Alice", "PAN123", "Bank Q", "67892", 5000.0);
    BankAccount* bank3 = createBankAccount("Alice", "PAN321", "Bank B", "67890", 2000.0);
    BankAccount* bank4 = createBankAccount("Alice", "PAN321", "Bank P", "67881", 3000.0);
    BankAccount* bank5 = createBankAccount("John", "PAN879", "Bank B", "67891", 2000.0);
    bank1->next = bank2;
    bank2->next = bank3;
    bank3->next=bank4;
	bank4->next=bank5;
	// Linking Bank Account nodes to PAN nodes
    linkBankAccountToPAN(bank1, pan1);
    linkBankAccountToPAN(bank2, pan1);
    linkBankAccountToPAN(bank3, pan2);
    linkBankAccountToPAN(bank4, pan2);
    linkBankAccountToPAN(bank5, pan3);
    
    // Print names, addresses, and Aadhar numbers of people with multiple bank accounts under multiple PAN numbers
    printf("People with multiple bank accounts under multiple PAN numbers:\n");
    printPeopleWithMultipleBankAccounts(pan1, bank1);

    // Creating LPG nodes
    LPG* lpg1 = createLPG("Alice", "12345", "YES");//bank A
    LPG* lpg2 = createLPG("Alice", "67892", "NO");
    LPG* lpg3 = createLPG("Alice", "67890", "NO");
    LPG* lpg4 = createLPG("alice", "67881", "NO");
    LPG* lpg5 = createLPG("John", "67891", "YES");
    lpg1->next = lpg2;
	lpg2->next = lpg3;
	lpg3->next = lpg4;
	lpg4->next = lpg5;
    // Linking LPG nodes to Bank Account nodes
    linkLPGToBankAccount(lpg1, bank1);
    linkLPGToBankAccount(lpg2, bank2);
    linkLPGToBankAccount(lpg3, bank3);
    linkLPGToBankAccount(lpg4, bank4);
    linkLPGToBankAccount(lpg5, bank5);
    
    printf("Details of person who has availed LPG subsidy:\n");
    printPersonWithLPGSubsidy(lpg1);
    
    double amountX;
    printf("Enter the amount X: ");
    scanf("%lf", &amountX);

    // Call the function to print details of people meeting the criteria
    printf("People with total savings > %.2f and availed LPG subsidy:\n", amountX);
    printPeopleWithSavingsAndLPG(lpg1, bank1, amountX);
    
    printf("Inconsistent data:\n");
    printInconsistentData(aadhar1, pan1, bank1, lpg1);

//    // Printing lists
//    printf("Aadhar List:\n");
//    printAadharList(aadhar1);
//
//    printf("PAN List:\n");
//    printPANList(pan1);
//
//    printf("Bank Account List:\n");
//    printBankAccountList(bank1);
//
//    printf("LPG List:\n");
//    printLPGList(lpg1);
//
//    // Freeing allocated memory
//    free(aadhar1);
//    free(aadhar2);
//    free(pan1);
//    free(pan2);
//    free(bank1);
//    free(bank2);
//    free(lpg1);
//    free(lpg2);
    
    return 0;
}

//Aadhar* aadharList = NULL;       // Initialize with actual data
//PAN* panList = NULL;             // Initialize with actual data
//BankAccount* bankList = NULL; 















