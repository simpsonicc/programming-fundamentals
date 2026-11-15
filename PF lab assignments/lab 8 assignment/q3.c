#include <stdio.h>

typedef struct item{
    int id;
    char name[50];
    int quantity; 
    float unitprice;
}i;

int main(){
    i details[5];
    int id= 0;
    int total_price = 0;
    for (int i =0; i<5; i++){
        total_price = 0;
        printf("Enter productId: ");
        scanf("%d", &details[i].id);
        printf("Enter product name: ");
        // fgets(details[i].name, sizeof(details[i].name), stdin);
        scanf(" %[^\n]", details[i].name);
        printf("Enter quantity: ");
        scanf(" %d", &details[i].quantity);
        printf("Enter its price per unit: ");
        scanf("%f", &details[i].unitprice);

        printf("Total inventory Price: %.2f\n", details[i].quantity*details[i].unitprice);

    }

    printf("Enter Id of the item you wanna search for: ");
    scanf("%d", &id);

    for (int i =0; i<5; i++){
        if (details[i].id == id){
            printf("%d\n%s\n%d\n%.2f\n", details[i].id, details[i].name, details[i].quantity, details[i].unitprice);
        }
    }
}

// 3. A logistics manager needs to store, track, and search through multiple warehouse items dynamically.
//  Declare an Array of Structures of size 5 using an Item struct (containing ID, Name, Quantity,
// and UnitPrice).
//  Create a program that:
//  Accepts details for 5 items from the user.
//  Calculates the total inventory value of the warehouse sum of (Quantity,UnitPrice).
//  Searches for a specific item by its Item ID entered by the user and displays its record.