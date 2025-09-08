// COMSC-210 | Lab 4A: Vector of Structs for Colors | Sunny Anand
// IDE used: Visual Studio Code

/*********************************************************************
* Importing C++ Built-in Library Functions
**********************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/*********************************************************************
* User defined data types (struct) are
* defined here before main().
**********************************************************************/
struct Color {
    int red;
    int green;
    int blue;
};

/*********************************************************************
* User Defined Function Prototypes are defined
* here as the actual functions are defined
* below main().
**********************************************************************/
void printIdentification();
void generateRandomColors(vector<Color>& colors);
void printColorTable(const vector<Color>& colors);

/*********************************************************************
* The main() function
**********************************************************************/
int main() {
    // Seed the random number generator.
    srand(static_cast<unsigned int>(time(0)));

    printIdentification();

    // Create an empty vector of Color structs.
    vector<Color> colorVec;

    // Generate and push random colors into the vector.
    generateRandomColors(colorVec);

    // Output the contents of the vector in a formatted table.
    printColorTable(colorVec);

    return 0;
}

/*********************************************************************
* User Defined Functions
**********************************************************************/

/*********************************************************************
* Function: generateRandomColors
*
* Generates a random number 'n' between 25 and 50. Then, it creates
* 'n' temporary Color structs, populates them with random integer
* values, and pushes each one into the vector.
*
* Parameters:
* colors: vector<Color>&. Passed by reference because the function
* will modify the vector by adding new elements.
*
* Why did I not use Pass-by-Value: This would create a complete copy of 
* --------------------------------
* the colors vector. Since the vector's size is random (between 25 and 50), 
* this could involve copying a significant amount of data. This creates 
* unnecessary overhead and is less efficient.
*
* Return: 
* None.
**********************************************************************/
void generateRandomColors(vector<Color>& colors) {
    // Generate a random number 'n' between 25 and 50.
    int n = rand() % 26 + 25;
    cout << "Generating " << n << " random colors...\n\n";

    // Loop n times to create and add colors to the vector.
    for (int i = 0; i < n; i++) {
        Color tempColor;
        tempColor.red = rand() % 256;
        tempColor.green = rand() % 256;
        tempColor.blue = rand() % 256;
        colors.push_back(tempColor);
    }
}

/*********************************************************************
* Function: printColorTable
*
* Outputs the contents of the vector in a well-formatted table.
* The vector is passed by constant reference to avoid making a
* copy, as per the conventions for passing large objects.
*
* Parameters:
* colors: const vector<Color>&. Passed by constant reference.
*
* Why did I use Pass-by-Constant-Reference?: It allows the function to 
* -----------------------------------------
* access the original vector without making a copy, which is highly efficient. 
* The const keyword is crucial because it guarantees that the function will 
* not accidentally modify the vector. This fulfills two of my coding conventions: 
* it's a mindful use of pass-by-reference for a large object, and the const keyword 
* ensures the variable is not changed by the function.
*
* Return:
* None.
**********************************************************************/
void printColorTable(const vector<Color>& colors) {
    // Print the table header using manipulators for alignment.
    cout << left;
    cout.width(9);
    cout << "Color#";
    cout.width(10);
    cout << "R value";
    cout.width(10);
    cout << "G value";
    cout.width(10);
    cout << "B value" << "\n";
    cout << "---------" << "----------" << "----------" << "----------" << "\n";

    // Iterate through the vector and print each color's RGB values.
    for (size_t i = 0; i < colors.size(); i++) {
        cout.width(9);
        cout << (i + 1);
        cout.width(10);
        cout << colors[i].red;
        cout.width(10);
        cout << colors[i].green;
        cout.width(10);
        cout << colors[i].blue << "\n";
    }
}

/*********************************************************************
* Function: printIdentification
*
* Prints identifying information for the program.
*
* Parameters:
* None.
*
* Return:
* None.
**********************************************************************/
void printIdentification() {
    cout << "######################################################################\n";
    cout << "\t\t\tIdentifying Information\n";
    cout << "######################################################################\n";
    cout << "Programmer: Sunny Anand\n";
    cout << "Course: COMSC-210-5470-F25, Prof. Mark Dietrich.\n";
    cout << "Lab Description: Lab 4A: Vector of Structs\n";
    cout << "Editor(s) used: Visual Studio Code\n";
    cout << "Compiler(s) used: G++\n";
    cout << "File: " << __FILE__ << "\n\n";
    cout << "______________________________________________________________________\n\n";
    cout << "\t\tNow the actual program execution\n";
    cout << "______________________________________________________________________\n\n";
}
