#include <stdio.h>

int calculatechecksum(int transactionid){
    if ((transactionid/10) == 0){
        return transactionid;
    } 
    return (transactionid%10) + calculatechecksum(transactionid/10);
}
int main(){
    int id;
    printf("Enter transaction ID: ");
    scanf("%d", &id);

    printf("%d", calculatechecksum(id));
    return 0;
}