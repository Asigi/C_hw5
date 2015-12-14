
//Arshdeep Singh
//December 2015
//TCSS 333 C Programming

/* Coding logic:
 
 This file prompts the user to choose an option.
 Depending on the option selected one of the following will be done:
 add, delete, update, search, write to csv file, or kill.
 
 Once an option has been selected, a function in Options.h will be called.
 
 */




/* Extra Credit:
 
 You have the ability to kill an animal if you don't like it.
 You are given three options for how to kill this animal.
 Choose one of the options to see the outcome.
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

/* This function prompts the user to input a killing method.
 *
 */
void promptKill(FILE* file);









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
    printf("6 to kill\n");
    
    //read input
    int input;
    scanf("%d", &input);
    
    
    if (input == 0) { //quit
        //do nothing
    } else if (input == 1) { //add
        addToFile(file);
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
    } else if (input == 6) {
        promptKill(file);
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
        int b = deleteFromFile(file, id);
        
        if (b) {
            printf("The animal was deleted");
        } else {
             printf("This animal does not exist");
        }
        
    } else {
        printf("Error: this animal does not exist\n");
    }
}


/* This function prompts the user to input a killing method.
 *
 */
void promptKill(FILE* file) {
    
    printf("Type the id number of the animal you want to delete: \n");
    int id;
    scanf("%d", &id);
    printf("\n");
    
    if (id > 0) {
        
        printf("Choose a kill method from one of the following:\n");
        printf("1) Feed this animal too many Hot Cheetos.\n");
        printf("2) Close your eyes and shoot a cannon.\n");
        printf("3) Force this animal to listen to Donald Trump speeches.\n");
        
        int choice;
        scanf("%d", &choice);
        
        killFromFile(file, id, choice);
        
    } else {
        printf("Error: this animal does not exist\n");
    }
}





