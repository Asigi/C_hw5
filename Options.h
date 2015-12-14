
//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 header file
 
 */

#ifndef OPTION_H
#define OPTION_H




/* This is the animal struct that will be needed in this project.
 *
 * This is 72bytes in 64bit, 68bytes in 32bit.
 * With pragma pack, this is 68bytes in 64bit.
 */
#pragma pack (2)
struct animal {
    short int id;
    char name[20];
    char species[35];
    short int age;
    double weight;
};
# pragma pack ()




/* This writes the contents of the passed in file to an ascii cvs file.
 *
 */
void writeToFile(FILE *file);

/* This searches the given file for a specific animal id.
 *
 */
void searchFile(FILE *file, int idnum);

/* This searches and updates the specified animal.
 *
 */
void updateFile(FILE *file, int idnum);

/* This searches and deleted the specified animal.
 *
 */
int deleteFromFile(FILE* file, int idnum);

/* This increments the number of available holes.
 *
 */
void incrementHole(FILE* file);

/* This decrements the number of available holes.
 *
 */
void decrementHole(FILE* file);

/* This function prompts the user to enter in information for a new animal.
 *
 */
void addToFile(FILE* file);

/* This function kills an animal using the method specified by the user.
 *
 */
void killFromFile(FILE* file, int idnum, int choice);

#endif











