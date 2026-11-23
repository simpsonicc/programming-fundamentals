#include <stdio.h>
#include <stdlib.h>

void showStats(int *ratings, int n){
    int total = 0;
    int highest = 0;
    for (int i = 0; i<n; i++){
        total += ratings[i];
        if (ratings[i] > ratings[highest]){
            highest = i;
        }
    }
    float average = (float)total/n;
    printf("Total ratings: %d\n", total);
    printf("Average ratings per category: %.2f\n", average);
    printf("Category with the highest rating count: %d\n", highest);
}

int main(){
    int n;
    printf("How many movie categories are there? ");
    scanf("%d", &n);

    int *ratings = (int *)calloc(n, sizeof(int)); // rating counts using DMA

    for (int i = 0; i<n; i++){
        printf("Enter rating count of category %d: ", i);
        scanf("%d", &ratings[i]);
    }

    showStats(ratings, n);

    int index, newCount;
    printf("Enter category index to update: ");
    scanf("%d", &index);
    printf("Enter new rating count: ");
    scanf("%d", &newCount);
    ratings[index] = newCount;

    printf("After update:\n");
    showStats(ratings, n);

    free(ratings);
    return 0;
}