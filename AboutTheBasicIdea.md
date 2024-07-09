# Statewide-Individuals-Data-Management-System-with-code
Data Structures, File Handling, C
• Implemented a data management system to handle information related to individuals in a state,
encompassing four separate linked lists: Aadhar list, PAN list, bank accounts list, and LPG subsidy list.
• Leveraged appropriate linked list structures to optimize efficiency and various operations like
highlighting inconsistencies in data, merging two distinct bank account lists into a single coherent list,
etc.

Assume that there are four separate lists containing data for people in a state. First list is Aadhar list, which contains names of people, their addresses and their corresponding Aadhar numbers. Second list is a PAN-list that contains in every node, name of a person, address, his/her PAN number and his/her Aadhar number. Third list is bank-accounts-list, which contains name of a person, his/her PAN number and the account details (bank, account number, deposited amount etc). Fourth list is LPG-list which contains name of a person, his/her bank-account-number and whether the person has taken LPG subsidy or not (YES or NO). Assume that Aadhar numbers are unique as they are derived from biometric data of a person that is assumed to be unique. Take as input, above four lists which are already populated. 

1. Print names, addresses and Aadhar numbers of all those people who have Aadhar numbers but no PAN numbers. 
2. Print names, addresses and Aadhar numbers of all those people who have multiple PAN numbers. Print all the PAN numbers for each such person. 
3. Print names, addresses and Aadhar numbers of all those people who have multiple bank accounts registered under multiple (more than 1) PAN numbers. (Note that registration of multiple bank accounts with the same PAN number is allowed.)
4. Print details (Aaadhar, PAN, all bank-account details) of a person who has availed LPG subsidy. 
5. Take amount X as input. Print names, addresses and Aadhar numbers of all those people who have their total savings (in all bank accounts of theirs) being greater than amount X and they have also availed LPG subsidy (YES). This may include people having one or more PAN numbers. 
6. Print inconsistent data, i.e. names, addresses and aadhar numbers of all those people who have different names mentioned in either of their Aadhar number, PAN number, bank account or LPG connection

Solution: 
Project structure. Here is a summary:
•	Aadhaar List: Contains nodes with names of people, their addresses, and their corresponding Aadhaar numbers.
•	PAN List: Contains nodes with names of people, their addresses, PAN numbers, and Aadhaar numbers.
•	Bank Accounts List: Contains nodes with names of people, their PAN numbers, and the account details (bank, account number, deposited amount, etc.).
•	LPG List: Contains nodes with names of people, their bank account numbers, and whether the person has taken LPG subsidy (YES or NO).
The lists are linked in such a way that:
•	Aadhaar List nodes are linked to PAN List nodes via Aadhaar numbers.
•	PAN List nodes are linked to Bank Accounts List nodes via PAN numbers.
•	Bank Accounts List nodes are linked to LPG List nodes via bank account numbers.
Description to Draw the Data Structure Illustration:
1.	Title: At the top, write "Aadhaar, PAN, Bank Account, and LPG Data Structure".
2.	Four Vertical Lists:
o	Aadhaar List:
	Draw a vertical list on the left side.
	Each node should contain three fields: Name, Address, Aadhaar Number.
	Connect the nodes with arrows pointing downwards to indicate the next node.
o	PAN List:
	Draw a vertical list to the right of the Aadhaar List.
	Each node should contain four fields: Name, Address, Aadhaar Number, PAN Number.
	Connect the nodes with arrows pointing downwards to indicate the next node.
	Additionally, draw arrows pointing upwards between nodes to indicate the previous node (backward link).
o	Bank Account List:
	Draw a vertical list to the right of the PAN List.
	Each node should contain six fields: Name, Address, Aadhaar Number, PAN Number, Bank Name, Account Number, Deposited Amount.
	Connect the nodes with arrows pointing downwards to indicate the next node.
	Additionally, draw arrows pointing upwards between nodes to indicate the previous node (backward link).
o	LPG List:
	Draw a vertical list to the right of the Bank Account List.
	Each node should contain eight fields: Name, Address, Aadhaar Number, PAN Number, Bank Name, Account Number, Deposited Amount, Subsidy Status.
	Connect the nodes with arrows pointing downwards to indicate the next node.
	Additionally, draw arrows pointing upwards between nodes to indicate the previous node (backward link).
