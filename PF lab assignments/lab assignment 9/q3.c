#include <stdio.h>
#include <stdlib.h>

int containsDigit(char *str){
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("How many usernames? ");
    scanf("%d", &n);

    char **usernames = (char **)calloc(n, sizeof(char *)); // 1d array of string

    for (int i = 0; i<n; i++){
        usernames[i] = (char *)calloc(50, sizeof(char)); // 49 characters space
        printf("Enter username %d: ", i+1);
        scanf("%49s", usernames[i]);
    }

    // remove usernames that contain a digit
    for (int i = 0; i<n; i++){
        if (containsDigit(usernames[i])){
            free(usernames[i]);
            for (int j = i; j<n-1; j++){
                usernames[j] = usernames[j+1]; // shifting
            }
            n--;
            i--; // check the same position again
        }
    }

    printf("Valid usernames:\n");
    for (int i = 0; i<n; i++){
        printf("%s\n", usernames[i]);
    }

    for (int i = 0; i<n; i++){
        free(usernames[i]);
    }
    free(usernames);
    return 0;
}