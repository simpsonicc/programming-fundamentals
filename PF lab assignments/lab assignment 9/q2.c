#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("How many feedback entries? ");
    scanf("%d", &n);
    getchar(); // removes the leftover newline after scanf

    char **feedback = NULL; // array of strings, grows using realloc

    for (int i = 0; i<n; i++){
        feedback = (char **)realloc(feedback, (i+1)*sizeof(char *));
        feedback[i] = (char *)malloc(100 * sizeof(char)); // each feedback stored separately
        printf("Enter feedback %d: ", i+1);
        fgets(feedback[i], 100, stdin);
    }

    int total = 0;
    int longestlen = 0;
    int longestIndex = 0;

    for (int i = 0; i<n; i++){
        char *p = feedback[i]; // pointer traversal
        int len = 0;
        while (*p != '\0' && *p != '\n'){
            len++;
            p++;
        }
        total += len;
        if (len > longestlen){
            longestlen = len;
            longestIndex = i;
        }
    }

    printf("\nAll feedback:\n");
    for (int i = 0; i<n; i++){
        printf("%d: %s", i+1, feedback[i]);
    }

    printf("Total characters: %d\n", total);
    printf("Longest feedback: %s", feedback[longestIndex]);

    for (int i = 0; i<n; i++){
        free(feedback[i]);
    }
    free(feedback);
    return 0;
}