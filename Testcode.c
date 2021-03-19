#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_data(int (*data)[40], int size1, int j, int value){
    for (int i=0; i<size1; i++) {
        

         data[j][i]  = value; 
        
    }
}




int main(){
    int bw_from_csv[60][40];
    int i = 0;
    int j = 0;
    FILE *bw_array = fopen("data.csv", "r");
    if(!bw_array){

        printf("Error!");
        return 0;
    }
    char buff[1024];

    while (fgets(buff, sizeof(buff), bw_array)){

        char *token;

        token = strtok(buff, ",");

        while (token != NULL)
        {
            int itoken = atoi(token);
            input_data((bw_from_csv)[j][i], sizeof(bw_from_csv)[0], sizeof(bw_from_csv)[1], itoken);
            i = i+1;
            printf("Adding stuff %i", itoken);
            token = strtok(NULL, ",");
        }
        printf("\n");
        j = j+1;

        i = 0;

    }


    

    return 0;

}