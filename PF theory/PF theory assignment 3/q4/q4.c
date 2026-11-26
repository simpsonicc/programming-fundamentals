/* Programmer: Omer Aboya
Program: Pattern printing of pentagon
date: 26-11-26
difficulty: pretty high
*/

#include <stdio.h>

int main(){
    int N; 
    printf("Enter N: ");
    scanf("%d", &N);

    if ((N <= 0) || ((N % 2) == 0)){ // n needs to be a positive odd number 
        printf("Number must be greater than 0 and odd\n");
        return 0;
    }
    int middle = (N*2) -2; // the N is the no of cols for the top left, top right, bottom left and bottom right
    // we need middle col which is twice the size of n , then -1 (the other -1 cos indexing starts from 0)
    for (int i = 0; i<middle; i++){ // the rows equal to middle
        for (int j =0; j<=middle*2; j++){ // total cols is twice the size of middle 
            if (i<N){ // for upper half
                if ((j==middle -(2*i)) || (j==middle+(2*i))){  // *2 cos in the top half each col after one star being placed is left out 
                    printf("*");
                }
                else printf(" ");
            }
            else if ((i>=N) && (i<middle)){ // for lower half
                if ((j == middle + (3*(N-1)-i)) || j == middle - (3*(N-1)-i)) printf("*"); // starts at the furthest from middle and then shrink to the and increases/decreases by 1 each iteration
                else printf(" ");
            }
        }
        printf("\n");
    }
    int count = N-1;    
    for (int i = 0; i<middle; i++){ // left side of last line
            // if (count >= N) break; 
            if (i==middle-count){
                count -= 2; // a col is skipped in between so -2
                printf("*");
            }
            else printf(" ");
        }
    
    count =0;
    for (int j =middle; j<=middle*2; j++){ // left side of last line
            if (count >= N) break; // total bottom stars cannot be more than n
            if ((j==middle+count)){
                count += 2;
                printf("*");
            }
            else printf(" ");
    }

    return 0;
}