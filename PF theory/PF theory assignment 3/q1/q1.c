#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("No file found\n");
        return 0;
    }

    FILE *fptr; // fptr is a pointer to a file in the memory

    fptr = fopen(argv[1], "r"); // open file if it exists else make a new one
    // second parameter tells it which mode it is. in this case its read mode

    if (fptr == NULL){
    printf("File not found\n");
    return 0;
    }

    int N;
    fscanf(fptr, "%d", &N);// reads a line from the file into N, 1st parameter is a pointer to that file
    int G;
    fscanf(fptr, "%d", &G);

    int **curr_grid = (int **)calloc(N, sizeof(int *));
    int **next_grid = (int **)calloc(N, sizeof(int *));

    for (int i =0; i<N; i++){
        curr_grid[i] = (int *)calloc(N, sizeof(int));
        next_grid[i] = (int *)calloc(N, sizeof(int));
    }

    for (int i = 0; i<N; i++){
        for (int j =0; j<N; j++){
            fscanf(fptr, "%d", &curr_grid[i][j]); // reads each number from file to the array
        }
    }
    fclose(fptr); // no need of file now

    printf("Generation 0\n");
    for (int i = 0; i<N; i++){
        for (int j =0; j<N; j++){
            printf("%d ", curr_grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int g =0; g<G; g++){    
        int count = 0;
        int neighbour_r = 0;
        int neighbour_c =0;
        for (int i =0; i<N; i++){
            for (int j =0; j<N; j++){
                // if (i == 0){ // no up neighbours 
                //  if (j == 0){ // no left neighbours either
                // if (((curr_grid[i][j+1] == 1) && (curr_grid[i+1][j] == 1) && (curr_grid[i+1][j+1] == 1)) || ((curr_grid[i][j+1] == 1) && 
                // (curr_grid[i+1][j] == 1)) || ((curr_grid[i][j+1] == 1) && (curr_grid[i+1][j+1] == 1)) || ((curr_grid[i+1][j] == 1) && 
                //   (curr_grid[i+1][j+1] == 1)) ){ //it survives
                count = 0;
                for (int row = -1; row<=1; row++){ //using second loop to keep track of all neighbours of a cell
                    for (int col = -1; col<=1; col++){
                        neighbour_r = i+row;
                        neighbour_c = j+col;

                        if ((neighbour_c<0) || (neighbour_r<0) || (neighbour_r>=N) || (neighbour_c>=N)) continue; //new r, c must be within bound

                        if (curr_grid[neighbour_r][neighbour_c] == 1){
                            count +=1; // for each valid neighbour it keeps the count 
                        }
                    }
                }
                if (curr_grid[i][j] == 1) count -= 1; // if the element itself was 1, it counts it too while we only need its neigbours count

                if ((curr_grid[i][j] == 1) && (count<2)) next_grid[i][j] = 0; // lives
                else if ((curr_grid[i][j] == 1) && (count>=2 && count<=3)) next_grid[i][j] = 1; // lives
                else if ((curr_grid[i][j] == 1) && (count>3)) next_grid[i][j] = 0; // dies cos more than 3 neighbours
                else if ((curr_grid[i][j] == 0) && (count==3)) next_grid[i][j] =1; // reproduction
                else next_grid[i][j] = 0;
            }
        }

        printf("Generation %d\n", g+1);
        for (int i =0; i<N; i++){
            for (int j =0; j<N; j++){
                printf("%d ", next_grid[i][j]);
                curr_grid[i][j] = next_grid[i][j]; // copies the new grid into original for simulating next gen
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++){
        free(curr_grid[i]);
        free(next_grid[i]);
    }
    free(next_grid);
    free(curr_grid);

    return 0;
}
