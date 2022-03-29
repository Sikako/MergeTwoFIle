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
 char line[1024];
 int retval = 0;
 char address[256];
 regex_t re;
 
 
 // open the files
 fp1 = processFile(filename1, "r");
 fp2 = processFile(filename2, "r");
 fp3 = processFile(filename3, "w");
 
 
 if(regcomp(&re, toFind, REG_EXTENDED) != 0){
    fprintf(stderr, "Failed to compile regex '%s'\n", toFind);
    return -1;
 }

 while((fgets(line, 1024, fp1)) != NULL){
  line[strlen(line)-1] = '\0';
  if((retval = regexec(&re, line, 0, NULL, 0)) == 0)
	  printf("%s\n", line);
 }



 // close the files
 closeFile(fp1, filename1);
 closeFile(fp2, filename2);
 closeFile(fp3, filename3);

 return 0;
}
