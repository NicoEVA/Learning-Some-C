#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void input_data(int (*data)[40], int size1, int value){
//     for (int i=0; i<size1; i++) {
        

//          data[i]  = value; 
        
//     }
// }




int main(){
    int bw_from_csv[60][40];
    int i;
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
            for (int i=0; i<sizeof(bw_from_csv)[0]; i++) {

                

                    scanf("%d", &bw_from_csv[i][j]);


                

            }
            
            printf("Adding stuff %i", itoken);
            token = strtok(NULL, ",");
        }
        printf("\n");
        

    }


    

    return 0;

}