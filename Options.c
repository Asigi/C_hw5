



//Arshdeep Singh
//December 2015
//TCSS 333 C Programming

/* Coding logic:
 
 This is the C file for Options.
 It has the necessary methods for adding, deleting, searching, updating, and writing to a cvs file.
 
 
 */


#include <stdio.h>
#include "Options.h"



/* This writes the contents of the passed in file to an ascii cvs file.
 *
 */
void writeToFile(FILE *file) {
    int holes;
    struct animal an = {0, "", "", 0, 0.0}; //an animal
    
    fread(&holes, sizeof(int), 1, file);
    
    //read in first animal
    fread(&an, sizeof(struct animal), 1, file);
    
    //create csv file for output
    FILE* outputFile = fopen("animals.csv", "w");
    
    
    while (!feof(file)) {
        
        if (an.age >= 0) {
            fprintf(outputFile, "%d,%s,%s,%d,%.2lf\n", an.id, an.name, an.species, an.age, an.weight);
        }
        
        fread(&an, sizeof(struct animal), 1, file);
        
    }
    
    
    fclose(outputFile);
    
    printf("Wrote to animals.csv\n");
}




/* This searches the given file for a specific animal id.
 *
 */
void searchFile(FILE *file, int idnum) {
    
    fseek(file, 0, SEEK_SET);
    
    int hole = 0;
    fread (&hole, sizeof (int), 1, file);
    
    struct animal an = {0, "", "", 0, 0.0};
    
    int size = sizeof(struct animal);
    
    fseek(file, idnum * size - size, SEEK_CUR); //todo put -size in size?
    
    fread(&an, size, 1, file);
    
    if (an.age >= 0 && an.id > 0) {
        
        printf("id......... %d\n", an.id);
        printf("name....... %s\n", an.name);
        printf("species.... %s\n", an.species);
        printf("age........ %d\n", an.age);
        printf("weight..... %.2f\n\n", an.weight);
    } else {
        
        printf("Error: this animal does not exist\n");
    }
    
}

















