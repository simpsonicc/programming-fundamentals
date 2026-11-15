#include <stdio.h>

typedef struct product{ // typedef is to give the struct a new easier name, like p for product
    int id;
    char name[50];
    char category[50];
    float price;
    int stock;
} p; // so instead of writing struct product "variable name", you can write p "variable name"
// in declaration 

void displayProductDetails(p product){
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Category: %s\n", product.category);
    printf("price after 5%% discount: %.2f\n", (product.price)*0.95);
    printf("Stock: %d\n", product.stock);
}

int main(){
    p product1 = {67, "Cheesecake", "Sweets", 6.90, 10}; // p is the struct
    displayProductDetails(product1);

    return 0;
}