#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_MOBILE_LENGTH 15

// Structure to represent menu items
struct MenuItem {
    char type[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    float price;
    float discount;
};

// Structure to represent a customer
struct Customer {
    char name[MAX_NAME_LENGTH];
    char mobile[MAX_MOBILE_LENGTH];
    float amount_due;
    float amount_paid;
    char purchased_items[MAX_ITEMS][MAX_NAME_LENGTH];
    int num_items;
};

// Function to read menu from file
void read_menu(char *file_path, struct MenuItem *menu, int *num_items) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_path);
        exit(1);
    }

    *num_items = 0;
    while ((*num_items < MAX_ITEMS) && (fscanf(file, "%[^,],%[^,],%f,%f\n", 
           menu[*num_items].type, menu[*num_items].name, 
           &menu[*num_items].price, &menu[*num_items].discount) == 4)) {
        (*num_items)++;
    }

    fclose(file);
}

// Function to read customer records from file
void read_customers(char *file_path, struct Customer *customers, int *num_customers) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_path);
        exit(1);
    }

    *num_customers = 0;
    while ((*num_customers < MAX_ITEMS) && (fscanf(file, "%[^,],%[^,],%f,%f,", 
           customers[*num_customers].name, customers[*num_customers].mobile, 
           &customers[*num_customers].amount_due, &customers[*num_customers].amount_paid) == 4)) {
        
        // Read purchased items
        customers[*num_customers].num_items = 0;
        char item[MAX_NAME_LENGTH];
        while ((fscanf(file, "%[^,],", item) == 1)) {
            strcpy(customers[*num_customers].purchased_items[customers[*num_customers].num_items++], item);
        }

        (*num_customers)++;
    }

    fclose(file);
}

// Function to write customer records to file
void write_customers(char *file_path, struct Customer *customers, int num_customers) {
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", file_path);
        exit(1);
    }

    for (int i = 0; i < num_customers; i++) {
        fprintf(file, "%s,%s,%.2f,%.2f,", customers[i].name, customers[i].mobile, 
                customers[i].amount_due, customers[i].amount_paid);
        
        // Write purchased items
        for (int j = 0; j < customers[i].num_items; j++) {
            fprintf(file, "%s,", customers[i].purchased_items[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to calculate the total price
float calculate_total(struct MenuItem *menu, int num_items, char purchased_items[MAX_ITEMS][MAX_NAME_LENGTH], int num_purchased_items) {
    float total = 0;
    for (int i = 0; i < num_purchased_items; i++) {
        for (int j = 0; j < num_items; j++) {
            if (strcmp(menu[j].name, purchased_items[i]) == 0) {
                total += menu[j].price * (1 - menu[j].discount);
                break;
            }
        }
    }
    return total;
}

// Function to display the main menu
void display_main_menu() {
    printf("Welcome to the Coffee House Billing System\n");
    printf("1. Add Customer\n");
    printf("2. View Menu\n");
    printf("3. View Customer Records\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

// Function to add a customer
void add_customer(char *customers_file, char *menu_file) {
    struct MenuItem menu[MAX_ITEMS];
    struct Customer customers[MAX_ITEMS];
    int num_menu_items = 0;
    int num_customers = 0;

    read_menu(menu_file, menu, &num_menu_items);
    read_customers(customers_file, customers, &num_customers);

    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter mobile number: ");
    scanf("%s", customers[num_customers].mobile);

    printf("Enter purchased items (comma-separated, e.g., Sandwich,Coffee): ");
    char input[100];
    scanf("%s", input);
    char *token = strtok(input, ",");
    while (token != NULL) {
        strcpy(customers[num_customers].purchased_items[customers[num_customers].num_items++], token);
        token = strtok(NULL, ",");
    }

    customers[num_customers].amount_due = calculate_total(menu, num_menu_items, 
                                                         customers[num_customers].purchased_items, 
                                                         customers[num_customers].num_items);

    printf("Total amount to be paid: $%.2f\n", customers[num_customers].amount_due);

    printf("Enter amount paid: ");
    scanf("%f", &customers[num_customers].amount_paid);

    // Write customer record to file
    write_customers(customers_file, customers, num_customers + 1);

    printf("Billing complete. Thank you!\n");
}

// Function to view the menu
void view_menu(char *menu_file) {
    struct MenuItem menu[MAX_ITEMS];
    int num_menu_items = 0;

    read_menu(menu_file, menu, &num_menu_items);

    printf("Menu:\n");
    for (int i = 0; i < num_menu_items; i++) {
        printf("%s: %s - $%.2f (Discount: %.2f)\n", menu[i].type, menu[i].name, menu[i].price, menu[i].discount);
    }
}

// Function to view customer records
void view_customer_records(char *customers_file) {
    struct Customer customers[MAX_ITEMS];
    int num_customers = 0;

    read_customers(customers_file, customers, &num_customers);

    printf("Customer Records:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Name: %s, Mobile: %s, Amount Due: $%.2f, Amount Paid: $%.2f, Purchased Items: ", 
               customers[i].name, customers[i].mobile, customers[i].amount_due, customers[i].amount_paid);
        for (int j = 0; j < customers[i].num_items; j++) {
            printf("%s ", customers[i].purchased_items[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char menu_file[] = "menu.txt";
    char customers_file[] = "customers.txt";
    int choice;

    while (1) {
        display_main_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer(customers_file, menu_file);
                break;
            case 2:
                view_menu(menu_file);
                break;
            case 3:
                view_customer_records(customers_file);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
