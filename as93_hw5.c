
#include <stdio.h>


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
        
        int holes = 0; //this is the number of holes in the program
        
        fread(&holes, sizeof(int), 1, cfPtr);
        
        printf ("# of holes: %d\n", holes);
        
        struct animal an = {0, "", "", 0, 0.0};
        
        
        //read in first animal
        fread(&an, sizeof(struct animal), 1, cfPtr);
        
        
        while (!feof(cfPtr)) {
            
            printf("ID...........: %d\n", an.id);
            printf("Name.........: %s\n", an.name);
            printf("Species......: %s\n", an.species);
            printf("Age..........: %d\n", an.age);
            printf("Weight.......: %.2lf\n\n", an.weight);
            
            fread(&an, sizeof(struct animal), 1, cfPtr);
            
        }
        
        fclose(cfPtr);
    }
    
    
    return 0;
    
}