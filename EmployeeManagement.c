
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


struct Employee
{
    int id;
    char name[20];
    char department[10];
    float salary;
    struct Employee *ptr;
};
struct Employee  *j = NULL , *y , *temp;

 int EmployeeCount = 0;

void VerifyAdmin()
{
    char userName[10];

    int attempts = 0;
    char password[20];
    char ch;
    int i = 0;

    while (attempts < 3)
    {
        i=0;
    admin:
        printf("\nUsername: ");
        scanf("%s", userName);
        fflush(stdin);
        printf("Enter password : ");

        while (1)
        {
            ch = getch(); // Get a character without echoing it to the screen

            if (ch == '\r')
            {                       // Enter key pressed
                password[i] = '\0'; // Null-terminate the password string
                break;
            }
            else if (ch == '\b' && i > 0 )
            {                    // Backspace key pressed
                printf("\b \b"); // Move back, overwrite with space, and move back again
                i--;             // Remove the last character from the password
            }
            else if (ch != '\b')
            { // Normal character input
                if (i < sizeof(password) - 1)
                {
                    printf("*");
                    password[i] = ch; // Store the character in the array
                    i++;
                }
            }
        }
        if (strcmp(userName, "admin") == 0 && strcmp(password, "cspitce") == 0)
        {
            printf("\nAccess Granted!\n");
            return;
        }
        else
        {
            printf("\nInvalid Username or Password.\n");
            attempts++;
        }
        if (attempts == 3)
        {
            printf("Too Many failed attempt.Please wait 10 second before retrying.\n");
            for (int i = 10; i >= 0; i--)
            {
                printf("\rRetrying in %d seconds...", i); // Overwrite the same line
                fflush(stdout);
                Sleep(1000);
            }
            attempts = 0;
            goto admin;
        }
    }
}

int Menu()
{
    int choice;
    printf("\n:: Employee Management System ::\n");
    printf("1. Add Employee\n2. Show Employee Records\n3. Update Employee's Data\n4. Delete Employee Record\n0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    system("CLS");
    return choice;
}

void SaveToFile() {
    temp = j;
    FILE *file = fopen("employees.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Loop through the linked list and write each employee's data to the file
    while (temp != NULL) {
        fprintf(file, "%d %s %s %.2f\n", temp->id, temp->name, temp->department, temp->salary);
        temp = temp->ptr;  // Move to the next employee
    }

    fclose(file);
}

int ID_check(int EMPID)
{
    temp = j;
    do
    {
        if ((temp->id == EMPID))
        {
            printf("\nERROR : ID ALREADY EXISTS PLEASE RETRY\n");
            return 0;
        }
        temp  = temp -> ptr;
    }while(temp != NULL);
    return 1;
}

void AddEmployee()
{
    int choice ;
    do
    {
        if( j == NULL)
        {
            j = (struct Employee *)malloc(sizeof(struct Employee));
            printf("\nEmployee:%d\n",EmployeeCount+1);
            printf("Employee ID : ");
            scanf("%d" , &j -> id);
            printf("Name : ");
            fflush(stdin);
            scanf("%s", j -> name);
            printf("Department : ");
            scanf("%s", j -> department);
            fflush(stdin);
            printf("Salary : ");
            scanf("%f", &j -> salary);
            fflush(stdin);
            j -> ptr = NULL;
            EmployeeCount++;
        }
        else
        {
            y = (struct Employee *)malloc(sizeof(struct Employee));
            printf("\nEmployee:%d\n",EmployeeCount+1);
            printf("Employee ID : ");
            scanf("%d" , &y -> id);
            if(ID_check(y -> id) == 0)
            {
                continue;
            }
            printf("Name : ");
            fflush(stdin);
            scanf("%s", y -> name);
            printf("Department : ");
            scanf("%s", y -> department);
            fflush(stdin);
            printf("Salary : ");
            scanf("%f", &y -> salary);
            fflush(stdin);
            y -> ptr = NULL;
            temp = j;
                while(temp ->ptr != NULL)
                {
                    temp = temp -> ptr;
                }
                temp -> ptr = y ;
            EmployeeCount++;
        }
        printf("\nPress 1 to add another employee\n");
        printf("Enter 0 to exit\n");
        printf("Your choice : ");
        scanf("%d" , &choice);
    }while(choice == 1);
    SaveToFile();
    system("CLS");
}

void ShowEmployees() {
    temp = j;  // Start from the head of the list
    if (temp == NULL) {
        printf("No employee records found.\n");
        return;
    }

    // Loop through the linked list
    printf("\n\t:: All Employee Records ::\n");
    printf("ID\t|Name\t\t|Department\t|Salary\n|");
    printf("-----------------------------------------------\n");
    do {
       printf("%d\t%s\t\t%s\t\t%0.2f\n", temp->id, temp->name, temp->department, temp->salary);
        temp = temp->ptr;  // Move to the next employee in the list
    } while (temp != NULL); // Stop when reaching the end of the list
    Sleep(10000);
    system("cls");
}

void UpdateEmployee()
{
    int EmpId;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &EmpId);
    fflush(stdin);
    temp = j;
    while(temp != NULL)
    {
        if (temp -> id == EmpId)
        {
            printf("Select details to update (you can choose multiple):\n");
            printf("1. Name\n");
            printf("2. Department\n");
            printf("3. Salary\n");
            printf("Enter your choices (e.g., 1 3 for Name and Salary): ");
            char choices[10];
            fgets(choices, 10, stdin);

            if (strchr(choices, '1'))
            {
                printf("Enter new name : ");
                scanf("%s", &temp -> name);
                fflush(stdin);
            }
            if (strchr(choices, '2'))
            {
                printf("Enter new department : ");
                scanf("%s", &temp -> department);
                fflush(stdin);
            }
            if (strchr(choices, '3'))
            {
                printf("Enter new salary : ");
                scanf("%f", &temp ->salary);
                fflush(stdin);
            }
        }
        temp = temp -> ptr;
    }
    printf("Employee details updated successfully.\n");
    SaveToFile();
    Sleep(2000);
    system("CLS");
    return;
}

void DeleteEmployee()
{
    int EmpId;
    struct Employee *pervious = NULL , *current = j ;
    printf("\nEnter Employee ID to delete : ");
    scanf("%d", &EmpId);
    if(current->id == EmpId)
    {
        if(current->ptr == NULL)
        {
            j=NULL;
            current=NULL;
            printf("\nEmployee record deleted successfully\n");
            EmployeeCount--;
            SaveToFile();
            Sleep(2000);
            system("CLS");
            return;
        }

        j = current->ptr;
        current = current->ptr;
        printf("\nEmployee record deleted successfully\n");
        EmployeeCount--;
        SaveToFile();
        Sleep(2000);
        system("CLS");
        return;
    }
    // fflush(stdin); // Clear input buffer
    do
    {
        if(current->ptr == NULL)
        {
            printf("\nNO RECORD FOUND\n");
            return;
        }
        pervious = current;
        current = current->ptr;
    }while(current->ptr != NULL);
    pervious->ptr = current->ptr;
    free(current);
    printf("\nEmployee record deleted successfully\n");
    EmployeeCount--;
    Sleep(2000);
    system("CLS");
    SaveToFile();
}

void LoadFromFile() {
    FILE *file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("No previous records found.\n");
        return;
    }

    struct Employee *temp = NULL;
    while (1) {
        struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
        if (fscanf(file, "%d %s %s %f", &newEmployee->id, &newEmployee->name, &newEmployee->department, &newEmployee->salary) != 4) {
            free(newEmployee);  // Free the memory if not enough data was read
            break;  // End of file or invalid data
        }
        newEmployee->ptr = NULL;

        // If the list is empty, initialize it with the first employee
        if (j == NULL) {
            j = newEmployee;
        } else {
            // Otherwise, add to the end of the list
            temp = j;
            while (temp->ptr != NULL) {
                temp = temp->ptr;
            }
            temp->ptr = newEmployee;
        }

        EmployeeCount++;  // Increase the employee count
    }

    fclose(file);
}


int main()
{
    // Load previous data
   LoadFromFile();

    // Verify admin
    VerifyAdmin();

    // Main program loop
    while (1) {
        switch (Menu()) {
            case 1:
                AddEmployee();
                break;
            case 2:
                ShowEmployees();
                break;
            case 3:
                UpdateEmployee();
                break;
            case 4:
                DeleteEmployee();
                break;
            case 0:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}
