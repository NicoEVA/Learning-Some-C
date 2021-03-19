#include <stdio.h>


void printArray(int arr[],int size) 
{ 
    int i =0; 
 
    printf("\nElements are : "); 
 
    for(i=0; i<size; i++) 
    { 
        printf("\n\tarr[%d] : %d",i,arr[i]); 
    } 
    printf("\n"); 
} 



int main(){
    int black_array[4][4] = {
    {1,1,1,1},
    {1,1,1,1},
    {1,0,1,0},
    {0,0,1,0}
    };


    int wb[4]={0};
    int bw[4]={0};
    
    int obs_counter = 0;
    int obs_1[40][4]={0};
    int i,j,p,pnew,o,count1,count2;
    int sum = 0;

    for (i=0; i<4;i++)
    {
        for (j=0; j<4;j++){
            sum += black_array[i][j];
            p       = black_array[i][j];
            pnew    = black_array[i][j+1];
            
            if (p - pnew < 0 && j<3){

                // wb[j+1]=1;
                obs_1[count1][1]=j+1;
                obs_1[count1][0]=i;
                count1 +=1;
                
            }
            if (p - pnew == 1 && j<3 && j+1 >=  obs_1[count2][1]){

                // bw[j+1]=1;
                obs_1[count2][2]=j+1;
                count2 +=1;
            }
        }
        printf("sum line %d %d \n",i,sum);
        sum = 0;
        printf("i %d",i);



        // printArray(bw,4);
        // printArray(wb,4);
        
        // for(o = 0; o < 4; o++)
        // {
        //     wb[o] = 0;
        //     bw[o] = 0;
        // }
        // if(sum<4){
        //     printf("I detect white in line %d \n",i);
            


        // }
        



    }


    for(i=0;i<40;i++){
        
        printf("obstacle %d %d %d \n",obs_1[i][0],obs_1[i][1],obs_1[i][2]);
        
    }





}