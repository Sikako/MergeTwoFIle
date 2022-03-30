#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "function.h"
#define toFind "/=\\d{1,}=/"


/*------------------------------------------------------
Subject:System Engineering                             |
Subscrition:Merge two files and write it in a new file |
Author:Sikako                                          |
-------------------------------------------------------*/


int main(){
 char filename1[20] = "ex33_1.txt";
 char filename2[20] = "ex33_2.txt";
 char filename3[20] = "ans33.txt";
 FILE *fp1, *fp2, *fp3;
 char stringData[601];                          // buffer
 int index_1, index_2;				// store the =#= of each file
 char cFrom1, cFrom2;
 int printFrom1 = 0;				// bool to check which file to print
 int end1, end2 = 0				// bool to check if file is end


 // open the files
 fp1 = processFile(filename1, "r");
 fp2 = processFile(filename2, "r");
 fp3 = processFile(filename3, "w");
 
// fscanf(fp1, "%s", stringData);
// fprintf(fp3, "%s", stringData);

while (1) {
  cFrom1 = fgetc(fp1);

  if(c== '=') putchar(c);   
} 





 // close the files
 closeFile(fp1, filename1);
 closeFile(fp2, filename2);
 closeFile(fp3, filename3);

 return 0;
}
