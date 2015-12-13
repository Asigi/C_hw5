
//Arshdeep Singh
//December 2015
//TCSS 333 C Programming

/* Coding logic:
 
 
 
 
 */

/* Extra Credit:
 
 You have the ability to kill an animal if you don't like it.
 
 */





#include <stdio.h>
#include "Options.h"


void prompt(FILE *file);
void writeToFile(FILE *file);
void promptSearch(FILE* file);




int main(void) {
    
    FILE *file;
    unsigned long fileLen;
    char* buffer;
    
    if ((file = fopen("animals.dat", "rb")) == NULL) {
        puts ("File could not be opened.");
        
    } else {
        prompt(file);
    }
    
    fclose(file);
    
    return 0;
}



void prompt (FILE *file) {
    //prompt user for input
    printf("\nPlease select an option:\n");
    printf("0 to quit.\n");
    printf("1 to add\n");
    printf("2 to delete\n");
    printf("3 to update\n");
    printf("4 to search\n");
    printf("5 to write to ASCII\n");
    
    //read input
    int input;
    scanf("%d", &input);
    
    
    if (input == 0) {
        
        //quit
        
    } else if (input == 1) {
        
   
        prompt(file);
        
    } else if (input == 2) {
        
  
        prompt(file);
        
    } else if (input == 3) {
        
        
        prompt(file);
        
    } else if (input == 4) { //search
        
        promptSearch(file);

        prompt(file);
        
    } else if (input == 5) {
        
        writeToFile(file);

        prompt(file);
        
    } else {
  
        prompt(file);
    }
}


void promptSearch(FILE* file) {
    
    printf("Type the id number of the animal you want: ");
    int id;
    scanf("%d", &id);
    printf("\n");
    
    if (id > 0) {
        searchFile(file, id);
    } else {
        printf("Error: this animal does not exist\n");
    }
    
}













