
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Expense
{
    int id;
    string category;
    string description;
    float amount;
};

Expense expenses[100];
int totalExpenses = 0;
float budget = 0;

// User Registration
void registration()
{
    string username, password;

    cout << "Create Username: ";
    cin >> username;

    cout << "Create Password: ";
    cin >> password;

    ofstream file("user.txt");
    file << username << endl << password;
    file.close();

    cout << "Registration Successful!\n";
}

// Login System
void login()
{
    string username, password;
    string savedUser, savedPass;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("user.txt");
    file >> savedUser >> savedPass;
    file.close();

    if(username == savedUser && password == savedPass)
        cout << "Login Successful!\n";
    else
        cout << "Invalid Login Details!\n";
}

// Add Daily Expense
void addExpense()
{
    if(totalExpenses >= 100)
    {
        cout << "Expense limit reached!\n";
        return;
    }

    expenses[totalExpenses].id = totalExpenses + 1;

    cout << "Enter Category: ";
    cin >> expenses[totalExpenses].category;

    cout << "Enter Description: ";
    cin.ignore();
    getline(cin, expenses[totalExpenses].description);

    cout << "Enter Amount: ";
    cin >> expenses[totalExpenses].amount;

    totalExpenses++;

    cout << "Expense Added Successfully!\n";
}

// View Expense History
void viewHistory()
{
    for(int i = 0; i < totalExpenses; i++)
    {
        cout << "\nID: " << expenses[i].id;
        cout << "\nCategory: " << expenses[i].category;
        cout << "\nDescription: " << expenses[i].description;
        cout << "\nAmount: " << expenses[i].amount << endl;
    }

    if(totalExpenses == 0)
        cout << "No Expenses Found!\n";
}

// Category Wise Expense
void categoryExpense()
{
    string category;
    float sum = 0;

    cout << "Enter Category: ";
    cin >> category;

    for(int i = 0; i < totalExpenses; i++)
    {
        if(expenses[i].category == category)
            sum += expenses[i].amount;
    }

    cout << "Total " << category << " Expense: " << sum << endl;
}

// Monthly Expense Report
void monthlyReport()
{
    float total = 0;

    for(int i = 0; i < totalExpenses; i++)
        total += expenses[i].amount;

    cout << "Total Monthly Expense: " << total << endl;
}

// Set Monthly Budget
void setBudget()
{
    cout << "Enter Monthly Budget: ";
    cin >> budget;

    cout << "Budget Set Successfully!\n";
}

// Budget Warning
void budgetWarning()
{
    float total = 0;

    for(int i = 0; i < totalExpenses; i++)
        total += expenses[i].amount;

    if(budget <= 0)
    {
        cout << "Please set your budget first!\n";
    }
    else if(total > budget)
    {
        cout << "Warning! Budget Exceeded!\n";
    }
    else
    {
        cout << "Budget is Under Control!\n";
    }
}

// Expense Prediction
void prediction()
{
    float total = 0;

    for(int i = 0; i < totalExpenses; i++)
        total += expenses[i].amount;

    // Simple prediction based on average daily spending
    float predicted = total * 30 / 15;

    cout << "Predicted Monthly Expense: "
         << predicted << endl;

    if(budget > 0 && predicted > budget)
        cout << "Alert! Monthly Budget May Be Exceeded!\n";
    else
        cout << "Monthly Budget is Within Limit.\n";
}

// Search Expense
void searchExpense()
{
    int id;
    bool found = false;

    cout << "Enter Expense ID: ";
    cin >> id;

    for(int i = 0; i < totalExpenses; i++)
    {
        if(expenses[i].id == id)
        {
            cout << "Category: " << expenses[i].category << endl;
            cout << "Description: " << expenses[i].description << endl;
            cout << "Amount: " << expenses[i].amount << endl;

            found = true;
        }
    }

    if(!found)
        cout << "Expense Not Found!\n";
}

// Delete Expense
void deleteExpense()
{
    int id;

    cout << "Enter Expense ID to Delete: ";
    cin >> id;

    for(int i = 0; i < totalExpenses; i++)
    {
        if(expenses[i].id == id)
        {
            for(int j = i; j < totalExpenses - 1; j++)
                expenses[j] = expenses[j + 1];

            totalExpenses--;

            cout << "Expense Deleted Successfully!\n";
            return;
        }
    }

    cout << "Expense Not Found!\n";
}

// File Saving
void saveFile()
{
    ofstream file("expenses.txt");

    for(int i = 0; i < totalExpenses; i++)
    {
        file << expenses[i].id << endl;
        file << expenses[i].category << endl;
        file << expenses[i].description << endl;
        file << expenses[i].amount << endl;
    }

    file.close();

    cout << "Expenses Saved Successfully!\n";
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== DIGITAL EXPENSE TRACKER =====\n";
        cout << "1. Registration\n";
        cout << "2. Login\n";
        cout << "3. Add Daily Expense\n";
        cout << "4. View Expense History\n";
        cout << "5. Category Wise Expense\n";
        cout << "6. Monthly Expense Report\n";
        cout << "7. Set Monthly Budget\n";
        cout << "8. Budget Warning\n";
        cout << "9. Expense Prediction\n";
        cout << "10. Search Expense\n";
        cout << "11. Delete Expense\n";
        cout << "12. Save File\n";
        cout << "13. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: registration(); break;
            case 2: login(); break;
            case 3: addExpense(); break;
            case 4: viewHistory(); break;
            case 5: categoryExpense(); break;
            case 6: monthlyReport(); break;
            case 7: setBudget(); break;
            case 8: budgetWarning(); break;
            case 9: prediction(); break;
            case 10: searchExpense(); break;
            case 11: deleteExpense(); break;
            case 12: saveFile(); break;
            case 13: cout << "Thank You!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while(choice != 13);

    return 0;
}
