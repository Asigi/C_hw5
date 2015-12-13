
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




#endif