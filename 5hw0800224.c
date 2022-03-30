#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "function.h"


/*------------------------------------------------------
Subject:System Engineering                             |
Subscrition:Merge two files and write it in a new file |
Author:Sikako                                          |
-------------------------------------------------------*/

// Function to print the result
void print_result(int value)
{
  
    // If pattern found
    if (value == 0) {
        printf("Pattern found.\n");
    }
  
    // If pattern not found
    else if (value == REG_NOMATCH) {
        printf("Pattern not found.\n");
    }
  
    // If error occured during Pattern
    // matching
    else {
        printf("An error occured.\n");
    }
}


// Function to get the index from =#=
int getIndex(FILE *fp){
  int index;
  char s[4];
  fgetc(fp);					// get rid of =
  fscanf(fp, "%[^=]s", s);
  index = atoi(s);
  fgetc(fp);					// get rid of =
  return index;
}

// main function
int main(){
 char filename1[20] = "ex33_1.txt";
 char filename2[20] = "ex33_2.txt";
 char filename3[20] = "ans33.txt";
 FILE *fp1, *fp2, *fp3;
 char stringData[601];                          // buffer
 int index_1, index_2 = 0;				// store the =#= of each file. -1 when 
 char cFrom1, cFrom2 = ' ';
 int printFrom1 = 0;				// bool to check which file to print
 int end1, end2 = 0;				// bool to check if file is end
 regex_t regex;


 // open the files
 fp1 = processFile(filename1, "r");
 fp2 = processFile(filename2, "r");
 fp3 = processFile(filename3, "w");
 
// fscanf(fp1, "%s", stringData);
// fprintf(fp3, "%s", stringData);



 index_1 = getIndex(fp1);
 index_2 = getIndex(fp2);

 if(index_1 < index_2){
   printFrom1 = 1;
   fscanf(fp1, "%[^=]s", stringData);		// get line between =#=
   printf("%s", stringData);
 }

 // close the files
 closeFile(fp1, filename1);
 closeFile(fp2, filename2);
 closeFile(fp3, filename3);

 return 0;
}
