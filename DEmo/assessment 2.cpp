#include <stdio.h>
#include <string.h>

struct FoodItem {
    char name[50];   
    double price;    
};

struct Order {
    struct FoodItem food; 
    int quantity;         
};

void displayMenu() {
    printf("\n----- Food Menu -----\n");
    printf("1. Pizza - Rs260\n");
    printf("2. Burger - $Rs80\n");
    printf("3. Pasta - Rs150\n");
    printf("4. Salad - Rs40\n");
    printf("5. Ice Cream - Rs30\n");
}
void placeOrder(struct Order *order) {
    int choice, quantity;
    double price;

    printf("Enter the number of the food item you want to order: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(order->food.name, "Pizza");
            price = 260;
            break;
        case 2:
            strcpy(order->food.name, "Burger");
            price = 80;
            break;
        case 3:
            strcpy(order->food.name, "Pasta");
            price = 150;
            break;
        case 4:
            strcpy(order->food.name, "Salad");
            price = 40;
            break;
        case 5:
            strcpy(order->food.name, "Ice Cream");
            price = 30;
            break;
        default:
            printf("Invalid choice! Please select a valid item from the menu.\n");
            return;
    }

    order->food.price = price;

    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    order->quantity = quantity;

    printf("You have ordered %d %s(s).\n", order->quantity, order->food.name);
}

void generateBill(struct Order order) {
    double total = order.food.price * order.quantity;
    printf("\n----- Your Bill -----\n");
    printf("%s x %d = $%.2f\n", order.food.name, order.quantity, total);
    printf("\nTotal amount: $%.2f\n", total);
}

int main() {
    char customerName[50];
    char continueOrdering;
    struct Order currentOrder;

    printf("Enter your name: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = '\0';  

    printf("Hello, %s! Welcome to the Flaming Cafe!.\n", customerName);

    do {

        displayMenu();

        placeOrder(&currentOrder);

        generateBill(currentOrder);

        printf("Do you want to continue ordering? (y/n): ");
        scanf(" %c", &continueOrdering);  

    } while (continueOrdering == 'y' || continueOrdering == 'Y'); 

    printf("\nThank you for your order, %s! Have a great day!\n", customerName);

    return 0;
}


