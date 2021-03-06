



//Arshdeep Singh
//December 2015
//TCSS 333 C Programming

/* Coding logic:
 
 This is the C file for Options.
 It has the necessary methods for adding, deleting, searching, updating, and writing to a cvs file.
 
 The extra credit feature here is that you can also kill an animal.
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "Options.h"



/* This writes the contents of the passed in file to an ascii cvs file.
 *
 */
void writeToFile(FILE *file) {
    int holes;
    struct animal an = {0, "", "", 0, 0.0}; //an animal
    
    fseek(file, 0, SEEK_SET); //reset to beginning.
    
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




/* This function finds the animal and then prompts the user for input
 * to update that animal.
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
int deleteFromFile(FILE* file, int idnum) {
    
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
        
        incrementHole(file);
        
        return 1;
    } else {
        
        return 0;
    }
}


/* This increases the number of available holes in the dat file.
 *
 */
void incrementHole(FILE* file) {
    
    fseek(file, 0, SEEK_SET);
    int hole = 0;
    fread (&hole, sizeof (int), 1, file);

    hole++;
    fseek(file, -sizeof(int), SEEK_CUR);
    fwrite(&hole, sizeof(int), 1, file);
    
    fseek(file, 0, SEEK_SET);
    fread (&hole, sizeof (int), 1, file);
}


/* This decrements the number of available holes in the dat file.
 *
 */
void decrementHole(FILE* file) {
    
    fseek(file, 0, SEEK_SET);
    int hole = 0;
    fread (&hole, sizeof (int), 1, file);

    hole--;
    fseek(file, -sizeof(int), SEEK_CUR);
    fwrite(&hole, sizeof(int), 1, file);
    
    fseek(file, 0, SEEK_SET);
    fread (&hole, sizeof (int), 1, file);
}





/* This function prompts the user to enter in information for a new animal.
 *
 */
void addToFile(FILE* file) {
    //first check number of holes
    fseek(file, 0, SEEK_SET);
    int hole = 0;
    fread (&hole, sizeof (int), 1, file);
    
    //find first hole if available
    if (hole > 0) {
        
        struct animal an = {0, "", "", 0, 0.0};
        int size = sizeof(struct animal);
        
        fseek(file, 0, SEEK_CUR);
        fread(&an, size, 1, file);
        
        while (!feof(file)) {
            if (an.age < 0) {
                //display id of hole
                printf("The id for this new animal is: %d\n", an.id);
                
                //prompt user
                char* spec = " %[^\n]%*c";
                
                printf("Please enter the name of this new animal: ");
                scanf("%s", an.name);
                
                printf("Please enter the species: ");
                scanf(spec, an.species);
                
                printf("Please enter the age: ");
                scanf("%hd", &an.age);
                
                printf("Please enter the weight: ");
                scanf("%lf", &an.weight);
                
                fseek(file, -sizeof(struct animal), SEEK_CUR);
                fwrite(&an, sizeof(struct animal), 1, file);

                //decrement hole number
                decrementHole(file);
                
                break;
            }
            
            fread(&an, size, 1, file);
        }
        
    } else {//add to the back
        
        printf ("there are no holes\n");
        
        struct animal an = {0, "", "", 0, 0.0};
        int size = sizeof(struct animal);
        
        fseek(file, 0, SEEK_CUR);
        fread(&an, size, 1, file);

        while (!feof(file)) {
            fread(&an, size, 1, file);
        }
        
        an.id++;
        printf("The id for this new animal is: %d\n", an.id);
        
        //prompt user
        char* spec = " %[^\n]%*c";
        
        printf("Please enter the name of this new animal: ");
        scanf("%s", an.name);
        
        printf("Please enter the species: ");
        scanf(spec, an.species);
        
        printf("Please enter the age: ");
        scanf("%hd", &an.age);
        
        printf("Please enter the weight: ");
        scanf("%lf", &an.weight);
        
        //fseek(file, -sizeof(struct animal), SEEK_CUR);
        fwrite(&an, sizeof(struct animal), 1, file);
        
        printf("Added in the new animal");

        
    }
}




/* This function kills an animal using the method specified by the user.
 *
 */
void killFromFile(FILE* file, int idnum, int choice) {
    
    if (choice == 1) {
        
        int b = deleteFromFile(file, idnum);
        if (b) {
            printf("\nYou gave animal # %d a delicious death.\n", idnum);
            printf("Good job!\n");
        } else {
             printf("This animal does not exist");
        }
        
    } else if (choice == 2 ) {
        int r = rand() % 3; //33% chance of hitting your target.
        
        if (r) { //fail
            int r2 = idnum;
            while (r2 == idnum) {
                r2 = rand() % 100;
            }
            
            int b = deleteFromFile(file, r2);
            if (b) {
                printf("\nYou MISSED! Animal #%d was killed instead.\n", r2);
            } else {
                printf("...you missed.\n");
            }
            
        } else { //success
            
            int b = deleteFromFile(file, idnum);
            if (b) {
                printf("\nYou successfully hit and killed animal # %d!\n", idnum);
            } else {
                printf("This animal does not exist\n");
            }
        }

    } else if (choice == 3) {
        
        int b = deleteFromFile(file, idnum);
        if (b) {
            printf("\nThe sound of Donald Trump's voice killed animal #%d.\n", idnum);
            
            int c = deleteFromFile(file, idnum + 1);
            if (c) {
                printf("Unfortunately it also killed animal #%d.\n", idnum + 1);
            }
        } else {
            printf("This animal does not exist");
        }
    }
}






