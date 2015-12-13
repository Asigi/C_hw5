
//Arshdeep Singh
//December 2015
//TCSS 333 C Programming

/* Coding logic:
 
 
 
 
 */

/* Extra Credit:
 
 You have the ability to kill an animal if you don't like it.
 
 */





#include <stdio.h>


void prompt(FILE *cfPtr);
void writeToFile(FILE *cfPtr);



#pragma pack (2)
struct animal { //this is 72bytes in 64bit, 68bytes in 32bit. With pack, this is 68bytes in 64bit.
    
    short int id;
    char name[20];
    char species[35];
    short int age;
    double weight;
};
# pragma pack ()



int main(void) {
    
    FILE *cfPtr;
    unsigned long fileLen;
    char* buffer;
    
    if ((cfPtr = fopen("animals.dat", "rb")) == NULL) {
        puts ("File could not be opened.");
        
    } else {
        prompt(cfPtr);
    }
    
    fclose(cfPtr);
    
    return 0;
}



void prompt (FILE *cfPtr) {
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
        
    } else if (input == 2) {
        
    } else if (input == 3) {
        
    } else if (input == 4) {
        
    } else if (input == 5) {
        writeToFile(cfPtr);
    } else {
        //call prompt()?
    }
}





void writeToFile(FILE *cfPtr) {
    int holes;
    struct animal an = {0, "", "", 0, 0.0}; //an animal

    fread(&holes, sizeof(int), 1, cfPtr);
    
    //read in first animal
    fread(&an, sizeof(struct animal), 1, cfPtr);
    
    //create csv file for output
    FILE* outputFile = fopen("animals.csv", "w");
    
    
    while (!feof(cfPtr)) {
        
        if (an.age >= 0) {
            fprintf(outputFile, "%d,%s,%s,%d,%.2lf\n", an.id, an.name, an.species, an.age, an.weight);
        }
        
        fread(&an, sizeof(struct animal), 1, cfPtr);
        
    }
    

    fclose(outputFile);
    
    printf("Wrote to animals.csv\n");
    
    //return to menu
    prompt(cfPtr);
}









