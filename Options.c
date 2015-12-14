



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
    
    fseek(file, 0, SEEK_SET);
    
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
    
    fseek(file, idnum * size - size, SEEK_CUR);
    
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




/* This function finds the animal and then prompts the user for input to update that animal.
 *
 */
void updateFile(FILE *file, int idnum) {
    
    printf("The following is the information stored for this animal:\n");
    
    fseek(file, 0, SEEK_SET);
    int hole = 0;
    fread (&hole, sizeof (int), 1, file);
    struct animal an = {0, "", "", 0, 0.0};
    int size = sizeof(struct animal);
    fseek(file, idnum * size - size, SEEK_CUR);
    fread(&an, size, 1, file);
    
    if (an.age >= 0 && an.id > 0) {
        
        printf("id......... %d\n", an.id);
        printf("name....... %s\n", an.name);
        printf("species.... %s\n", an.species);
        printf("age........ %d\n", an.age);
        printf("weight..... %.2f\n\n", an.weight);
        
        
        
        char* spec = " %[^\n]%*c";
        
        printf("Please enter the updated name: ");
        scanf("%s", an.name);
        
        printf("Please enter the updated species: ");
        scanf(spec, an.species);
        
        printf("Please enter the updated age: ");
        scanf("%hd", &an.age);
        
        printf("Please enter the updated weight: ");
        scanf("%lf", &an.weight);
        
        fseek(file, -sizeof(struct animal), SEEK_CUR);
        fwrite(&an, sizeof(struct animal), 1, file);
        
        
    } else {
        
        printf("Error: this animal does not exist\n");
    }
    
}


/* This searches and deleted the specified animal.
 *
 */
void deleteFromFile(FILE* file, int idnum) {
    
    fseek(file, 0, SEEK_SET);
    int hole = 0;
    fread (&hole, sizeof (int), 1, file);
    struct animal an = {0, "", "", 0, 0.0};
    int size = sizeof(struct animal);
    fseek(file, idnum * size - size, SEEK_CUR);
    fread(&an, size, 1, file);
    
    if (an.age >= 0 && an.id > 0) {
        
        an.age = -1;
        
        fseek(file, -sizeof(struct animal), SEEK_CUR);
        fwrite(&an, sizeof(struct animal), 1, file);

        printf("The animal was deleted");
        
        incrementHole(file);
        
        
    } else {
        printf("This animal does not exist");
    }

    
    
}


/* This increases the number of available holes in the dat file.
 *
 */
void incrementHole(FILE* file) {
    
    fseek(file, 0, SEEK_SET);
    int hole = 0;
    fread (&hole, sizeof (int), 1, file);
    printf("# of holes before changing: %d\n", hole);
    hole ++;
    fseek(file, -sizeof(int), SEEK_CUR);
    fwrite(&hole, sizeof(int), 1, file);
    
    fseek(file, 0, SEEK_SET);
    fread (&hole, sizeof (int), 1, file);
    printf("# of holes after changing: %d\n", hole);
}






















