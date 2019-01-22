/*
Yjang Wynter
COP3223C
Online
Program 5
shurikenjutsu.c
10/11/2018
*/
//pre-processor derivates
//This program requires you have a file with a set of numbers with the first one to be the amount of sets in the file.
#include <stdio.h>
#include <stdlib.h>

int main(){

char filename[20];

int i,sets=0,cur_val = 0, stu1, stu2, stu1_sum = 0, stu2_sum = 0, stu1_total = 0, stu2_total = 0;

    FILE *ifp = NULL, *ofp;

    ofp = fopen("filename[ ]", "w");

    //Get file with while loop
    while (ifp==0){
        printf("What is the name of the file?\n");

        scanf("%s",filename);

        ifp = fopen(filename, "r");
         //In case the file is not found.
            if (ifp==0)

                printf("FILE NOT FOUND\n");
        }
        //This reads the first value which correspondinds to the amount of sets in the file
        fscanf(ifp, "%d", &sets);

//The main logic
 fprintf(ofp,"\nShurikenjutsu Points\n\n");
//Loop for each set
    for (i=0; i < sets; i++){

 //Student 1 loop
        for (stu1=0; stu1 < sets; stu1++){

            fscanf(ifp, "%d", &cur_val);

            stu1_sum += cur_val;
                //I want to reset the cur_val, but I do not know how. Only bug I found
                cur_val = 0;

            }



//Student 2 loop
        for(stu2 = 0; stu2 < sets; stu2++){

                fscanf(ifp, "%d", &cur_val);

                stu2_sum += cur_val;
                   //I want to reset the cur_val, but I do not know how. Only bug I found
                cur_val = 0;

                }
    //For all the printing I put one set for console and another for file
    //SInce the discussion board had conflicting answers

            //One print for file
            fprintf(ofp,"\nSet #%d \n", i+1);
              //One print for console
            printf("\nSet #%d \n", i+1);

              //One print for file
            fprintf(ofp,"\nStudent 1: %d points\n", stu1_sum);
               //One print for console
            printf("\nStudent 1: %d points\n", stu1_sum);

            stu1_total += stu1_sum;

            fprintf(ofp,"Student 2: %d points\n\n", stu2_sum);

            printf("Student 2: %d points\n\n", stu2_sum);

            stu2_total += stu2_sum;

            stu1_sum =0;
            stu2_sum =0;

        }
        fprintf(ofp,"Final Scores\n");

         printf("Final Scores\n");


        fprintf(ofp,"\nStudent 1: %d points\n", stu1_total);

        printf("\nStudent 1: %d points\n", stu1_total);


        fprintf(ofp,"Student 2: %d points\n", stu2_total);

        printf("Student 2: %d points\n", stu2_total);

        //Seperator
        fprintf(ofp,"\n----------------------\n");
        printf("\n----------------------\n");

    if (stu1_total > stu2_total){

        fprintf(ofp,"\nStudent 1 will be advancing to the next round\n\n");

        printf("\nStudent 1 will be advancing to the next round\n\n");
        }

    if (stu2_total > stu1_total){

        fprintf(ofp,"\nStudent 2 will be advancing to the next round\n\n");

        printf("\nStudent 2 will be advancing to the next round\n\n");
        }

    if (stu2_total == stu1_total){

        fprintf(ofp,"\nThe students must break the tie in a showdown!\n\n");

        printf("\nThe students must break the tie in a showdown!\n\n");
        }



//Closing files
fclose(ifp);
fclose(ofp);

return 0;
}


