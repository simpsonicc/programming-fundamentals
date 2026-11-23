#include <stdio.h>
#include <stdlib.h>

void showStats(int *stock, int n){
    int total = 0;
    int lowest = 0;
    for (int i = 0; i<n; i++){
        total += stock[i];
        if (stock[i] < stock[lowest]){
            lowest = i;
        }
    }
    float average = (float)total/n;
    printf("Total stock: %d\n", total);
    printf("Average stock: %.2f\n", average);
    printf("Category index with the lowest stock: %d\n", lowest);
}

int main(){
    int n;
    printf("How many book categories are there? ");
    scanf("%d", &n);

    int *stock = (int *)calloc(n, sizeof(int)); 

    for (int i = 0; i<n; i++){
        printf("Enter stock of category %d: ", i);
        scanf("%d", &stock[i]);
    }

    showStats(stock, n);

    int index, newStock;
    printf("Enter category to update: ");
    scanf("%d", &index);
    printf("Enter new stock: ");
    scanf("%d", &newStock);
    stock[index] = newStock;

    printf("After update:\n");
    showStats(stock, n);

    free(stock);
    return 0;
}