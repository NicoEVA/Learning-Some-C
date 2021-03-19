#include <stdio.h>


// void printArray(int arr[],int size) 
// { 
//     int i =0; 
 
//     printf("\nElements are : "); 
 
//     for(i=0; i<size; i++) 
//     { 
//         printf("\n\tarr[%d] : %d",i,arr[i]); 
//     } 
//     printf("\n"); 
// } 



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
            sum += black_array[i][j];       //sum of all elements in sector line/row
            p       = black_array[i][j];    //check-value of current sector
            pnew    = black_array[i][j+1];  //cehck-value of following sector
            
            if (p - pnew < 0 && j<3){       //activate on white-to-black step, accounting for counter

                // wb[j+1]=1;
                obs_1[count1][1]=j+1;
                obs_1[count1][0]=i;
                count1 +=1;
                
            }
            if (p - pnew == 1 &&            //activate on black-to-white
                j<3 &&                      //accounting for counter   
                j+1 >=  obs_1[count2][1] && //make sure bw happens afer wb
                obs_1[count2][1]!=0){       //needed if bw before wb, forbids writing to empty lines

                // bw[j+1]=1;
                obs_1[count2][2]=j+1;
                count2 +=1;
            }
        }
        printf("sum line %d %d \n",i,sum);
        sum = 0;
        printf("i %d \n",i);       



    }


    for(i=0;i<39;i++){
        
        // printf("obstacle %d %d %d \n",obs_1[i][0],obs_1[i][1],obs_1[i][2]);
        if  (obs_1[i+1][0]>obs_1[i][0]){
            obs_1[i][0] = obs_1[i+1][0];
                
            if (obs_1[i+1][1]>=obs_1[i][1] && obs_1[i+1][1]<=obs_1[i][2]){
                if (obs_1[i+1][2]>=obs_1[i][2] && obs_1[i+1][1]==obs_1[i][1]){
                    // obs_1[i][2] = obs_1[i+1][2];
                    obs_1[i][0]=0;
                    obs_1[i][1]=0;
                    obs_1[i][2]=0;

                }else{
                    obs_1[i+1][0]=obs_1[i][0];
                    obs_1[i+1][1]=obs_1[i][1];
                    obs_1[i+1][2]=obs_1[i][2];

                    obs_1[i][0]=0;
                    obs_1[i][1]=0;
                    obs_1[i][2]=0;


                }

            }

            if (obs_1[i+1][2]>=obs_1[i][1] && obs_1[i+1][2]<=obs_1[i][2]){
                if (obs_1[i+1][1]<=obs_1[i][1] && obs_1[i+1][2]==obs_1[i][2]){
                    // obs_1[i][1] = obs_1[i+1][1];
                    obs_1[i][0]=0;
                    obs_1[i][1]=0;
                    obs_1[i][2]=0;
                    

                }else{
                    obs_1[i+1][0]=obs_1[i][0];
                    obs_1[i+1][1]=obs_1[i][1];
                    obs_1[i+1][2]=obs_1[i][2];

                    obs_1[i][0]=0;
                    obs_1[i][1]=0;
                    obs_1[i][2]=0;


                }

            }
        }
    }
     for(i=0;i<40;i++){
        
        printf("obstacle %d %d %d \n",obs_1[i][0],obs_1[i][1],obs_1[i][2]);
     }



return 0;

}