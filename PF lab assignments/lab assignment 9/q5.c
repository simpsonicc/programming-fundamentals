#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n; 
    char *pattern = (char *)calloc(50, sizeof(char));
    printf("how many students are there?");
    scanf("%d", &n);
    getchar(); // extra line so fegets read it intead of the actual thing
    printf("Enter password pattern:");
    fgets(pattern, 50, stdin);

    char **passwords = (char **)calloc(n, sizeof(char *)); // 1d array of string

    for (int i =0; i<n; i++){
        passwords[i] = (char *)calloc(50, sizeof(char)); // 49 characters space
    }
    int len = strlen(pattern);

    int pattern_count = 0;
    for (int i =0; i<len; i++){
        pattern_count += pattern[i];
    }

    float *count = (float *)calloc(n, sizeof(float));

        for (int i = 0; i<n; i++){
            printf("Enter your password: ");
            fgets(passwords[i], 50, stdin);
            for (int j =0; j<50; j++){
                count[i] += (float)passwords[i][j];
            }
            count[i] = (float)(count[i]/pattern_count)*100;
            printf("Password: %sSimilarity: %.2f\n", passwords[i], count[i]);
        }

        float max = count[0];
        int index = 0;
        for (int i =0; i<n; i++){
            if (count[i]>max){
                max = count[i];
                index = i;
            }
    }

    printf("password with the most similarity: %s", passwords[index]);

    free(count);
    for (int i = 0; i<n; i++){
        free(passwords[i]);
    }
    free(passwords);
    free(pattern);

    return 0;
}