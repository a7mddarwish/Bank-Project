# Bank Management System

## Overview

This is a simple **Bank Management System** developed in **C++**, utilizing **non-relational database storage (file-based storage)**. The system allows user authentication with a maximum of **three login attempts** before restricting access.

## User Roles

- **Admin**: Has full control over the system, can add users with specific permissions, but other users cannot delete the admin.
- **Users**: Have restricted permissions based on what the admin allows them to do.

## Main Features

### **1. Authentication System**

- Users must **log in** to access the system.
- Login attempts are limited to **three tries**.
- Authentication data is stored in files (non-relational DB).

---

### **2. Main Menu**

After successful login, users will see the following main menu:

```
===========================================
                Main Menu
===========================================
[1] Show Client List
[2] Add New Client
[3] Delete Client
[4] Update Client Info
[5] Find Client
[6] Transactions
[7] Manage Users
[8] Login Register
[9] Currency Exchange
[10] Logout
```

Below is a breakdown of each feature:

#### **1. Show Client List**

Displays all clients who have an open account in the bank.

#### **2. Add New Client**

- Adds a new client to the system.
- The user must have the required **permission** from the admin to add clients.

#### **3. Delete Client**

- Deletes an existing client.
- Requires **admin approval** before execution.

#### **4. Update Client Info**

- Updates a client's personal details.
- Only users with the **necessary permissions** can perform this action.

#### **5. Find Client**

- Searches for a client using their **account number**.

#### **6. Transactions**

This option opens another sub-menu for handling financial transactions:

```
[1] Deposit
[2] Withdraw
[3] Total Balances
[4] Transfer
[5] Transfer Log
[6] Main Menu
```

- **Deposit**: Allows depositing money into a client’s account.
- **Withdraw**: Withdraws money, ensuring sufficient balance.
- **Total Balances**: Displays the total amount available in the bank.
- **Transfer**: Transfers money from one account to another.
- **Transfer Log**: Shows a history of all transfers, including amounts, timestamps, and user details.
- **Main Menu**: Returns to the main menu.

#### **7. Manage Users (Admin Only)**

- Only **admins** (or users granted permission by the admin) can access this section.
- The menu contains the following options:

```
[1] List Users
[2] Add User
[3] Delete User
[4] Update User
[5] Find User
[6] Main Menu
```

- **List Users**: Displays all registered users in the system.
- **Add User**: Adds a new user and assigns permissions using **bitwise operations** to simulate role-based access control.
- **Delete User**: Removes a user from the system.
- **Update User**: Modifies user details and permissions.
- **Find User**: Searches for a user by their credentials.
- **Main Menu**: Returns to the main menu.

#### **8. Login Register**

- Logs all user **login attempts**, recording **username, timestamp, and assigned permissions**.

#### **9. Currency Exchange**

- Allows users to convert currency within the system (details can be expanded later).

#### **10. Logout**

- Logs out the current user and returns to the **login screen**.

---

## Screenshots

(Add screenshots of each feature here for better visualization.)

---

## How to Run

1. Compile the C++ code using any standard compiler (e.g., **g++**).
2. Run the executable file.
3. Log in as an admin or user.
4. Navigate the menu and use the features as needed.

---

## Future Enhancements

- **Database Integration**: Replace file-based storage with a relational database (e.g., MySQL, PostgreSQL).
- **GUI Implementation**: Develop a graphical interface for better usability.
- **Encryption**: Improve security by encrypting stored data.

---

## Author

Developed by **[A7mddarwish]**.

