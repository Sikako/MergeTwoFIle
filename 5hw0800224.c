#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


/*------------------------------------------------------
Subject:System Engineering                             |
Subscrition:Merge two files and write it in a new file |
Author:Sikako                                          |
-------------------------------------------------------*/

// Function to get the index from =#=
int getIndex(FILE *fp){
  int index;
  char s[4];
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
 char stringData[20000] = "";                          // buffer
 int index_1, index_2 = 0;				// store the =#= of each file. -1 when 
 char cFrom1, cFrom2 = ' ';
 int printFrom1 = 0;				// bool to check which file to print
 int end1, end2 = 0;				// bool to check if file is end


 // open the files
 fp1 = processFile(filename1, "r");
 fp2 = processFile(filename2, "r");
 fp3 = processFile(filename3, "w");
 
// fscanf(fp1, "%s", stringData);
// fprintf(fp3, "%s", stringData);



 cFrom1 = getc(fp1);				// get rid of =
 cFrom2 = getc(fp2);				// get rid of =
 index_1 = getIndex(fp1);
 index_2 = getIndex(fp2);
 
 while(cFrom1 != EOF && cFrom2 != EOF){	
   // compare two index
   if(index_1 < index_2 || cFrom2 == EOF){
     printFrom1 = 1;
     if(fscanf(fp1, "%[^=]s", stringData))     // get line between =#=
      fprintf(fp3, "%s", stringData);
     cFrom1 = getc(fp1);					// get rid of =
     index_1 = getIndex(fp1);     
   }else if(index_2 < index_1 || cFrom1 == EOF){
     printFrom1 = 0;
     if(fscanf(fp2, "%[^=]s", stringData))
       fprintf(fp3, "%s", stringData);
     cFrom2 = getc(fp2);
     index_2 = getIndex(fp2);
   }
 }

 // close the files
 closeFile(fp1, filename1);
 closeFile(fp2, filename2);
 closeFile(fp3, filename3);

 return 0;
}
