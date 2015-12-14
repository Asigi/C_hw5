
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



/* This function prompts the user by showing them the main menu.
 *
 */
void prompt(FILE *file);

/* This function prompts the user to input the id of the animal they want to search for.
 *
 */
void promptSearch(FILE* file);

/* This function prompts the user to input the id of the animal they want to update.
 *
 */
void promptUpdate(FILE* file);

/* This function prompts the user to input the id of the animal they want to delete.
 *
 */
void promptDelete(FILE* file);


/* Entry point of program.
 *
 */
int main(void) {
    
    FILE *file;
    unsigned long fileLen;
    char* buffer;
    
    if ((file = fopen("animals.dat", "rb+")) == NULL) {
        puts ("File could not be opened.");
        
    } else {
        prompt(file);
    }
    
    fclose(file);
    
    return 0;
}


/* This function prompts the user by showing them the main menu.
 *
 */
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
    
    
    if (input == 0) { //quit
        
        //do nothing
        
    } else if (input == 1) { //add
        
   
        prompt(file);
        
    } else if (input == 2) { //delete
        
        promptDelete(file);
        prompt(file);
        
    } else if (input == 3) { //update
        
        promptUpdate(file);
        
        prompt(file);
        
    } else if (input == 4) { //search
        
        promptSearch(file);

        prompt(file);
        
    } else if (input == 5) { //write
        
        writeToFile(file);

        prompt(file);
        
    } else {
  
        prompt(file);
    }
}


/** This function prompts the user to input the id of the animal they want to search for.
 *
 */
void promptSearch(FILE* file) {
    
    printf("Type the id number of the animal you want to see: ");
    int id;
    scanf("%d", &id);
    printf("\n");
    
    if (id > 0) {
        searchFile(file, id);
    } else {
        printf("Error: this animal does not exist\n");
    }
    
}


/* This function prompts the user to input the id of the animal they want to update.
 *
 */
void promptUpdate(FILE* file) {
    
    printf("Type the id number of the animal you want to update: ");
    int id;
    scanf("%d", &id);
    printf("\n");
    
    if (id > 0) {
        updateFile(file, id);
    } else {
        printf("Error: this animal does not exist\n");
    }

}



/* This function prompts the user to input the id of the animal they want to delete.
 *
 */
void promptDelete(FILE* file) {
    
    printf("Type the id number of the animal you want to delete: ");
    int id;
    scanf("%d", &id);
    printf("\n");
    
    if (id > 0) {
        deleteFromFile(file, id);
    } else {
        printf("Error: this animal does not exist\n");
    }
    
    
}









