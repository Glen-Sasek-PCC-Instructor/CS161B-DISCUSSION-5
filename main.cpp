
//*****************************************************************************
// Author: Glen
// Assignment:
// Date:
// Description:
// Sources:
//*****************************************************************************

// RUN
// g++ -o main main.cpp && ./main && rm main

/*
STEM Analysis

What percentage of men and women pursue STEM (Science, Technology, Engineering, Math) degrees?
With your programming partner, you will complete a program that reads from a file called stem.txt&nbsp;and
 writes to an output file called stemout.txt.
 It does not store any data.

 But it uses loops and functions to read from the file and do some analysis.

 It calculates the percentage of
 men in each major
 and
 women in each major

 and writes the
    name of the major,
    percentage men,
    percentage women to the output file.

Percentages should be printed to two decimal places.

You must ignore the first line in stem.txt, which is a header line.

The function openFile() has been written for you. You must write the ratioCalc() function.

What other statistics can you calculate and add to the output file?
Add another function to calculate one other statistic from the given data.

Task:

Open this starter&nbsp;Replit&nbsp;and make a copy.
Click on the Files icon -&gt; design.doc and plan the steps of your algorithm.
Start with the end - design what the user will see when they run your program.
Design first, then write your C++ program.
Update the program header with both partner names and other information, and post a link to your Replit on this discussion topic.
Percentages should be printed to two decimal places.
Must have another function (other than the 2 given functions - openFile and ratioCalc) to calculate any other statistic for the given data.
You will not be using that String variable anymore in the rest of your CS classes here at PCC. So, use char arrays (C-strings).


*/

#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;




const char DATA_IN_FILE[] = "stem.txt";
const char DATA_OUT_FILE[] = "stemout.txt";

const int MAX_CHARS = 100;

class Row
{
public:
    int majorCode = 0;
    char major[MAX_CHARS + 1] = {0};
    char majorCategory[MAX_CHARS + 1] = {0};
    int total = 0;
    int men = 0;
    int women = 0;
    int annualSalary = 0;

    Row(istream &in)
    {
        in >> majorCode;
        in >> major;
        in >> majorCategory;
        in >> total;
        in >> men;
        in >> women;
        in >> annualSalary;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void print(ostream &out)
    {
        out << setw(6) <<  majorCode;
        out << setw(2) <<  " ";
        out << setw(45) << left << major;
        out << setw(25) << majorCategory;
        out << setw(10) << right << total;
        out << setw(10) << men;
        out << setw(10) << women;
        out << setw(10) << annualSalary << endl;
    }
};

void ratioCalc(Row row, ostream &out = cout);

void printRatioHeader(ostream &out = cout);

int main()
{
    int exit_status = 0;
    ifstream fin(DATA_IN_FILE);
    ofstream fout(DATA_OUT_FILE);

    if (!fin)
    {
        cerr << "ERROR: unable to open source datafile: " << DATA_IN_FILE << endl;
        exit_status = 1;
    }

    if (!fout)
    {
        cerr << "ERROR: unable to open destination datafile: " << DATA_OUT_FILE << endl;
        exit_status = 1;
    }

    // Remove datafile header row
    fin.ignore(numeric_limits<streamsize>::max(), '\n');


    printRatioHeader(fout);

    while (fin && fin.peek() != fin.eof())
    {
        Row row(fin);
        //row.print(cout);
        ratioCalc(row, fout);
    }

    fin.close();
    fout.close();

    return exit_status;
}


void printRatioHeader(ostream &out) {
    out << setw(45) << left << "MAJOR";
    out << fixed << setprecision(2) << right;
    out << setw(10) << "% MEN";
    out << setw(10) << "% WOMEN";
    out << endl;
}

//  and writes the
//     name of the major,
//     percentage men,
//     percentage women to the output file.
void ratioCalc(Row row, ostream &out) {
    double pctMen = 100.0 * row.men / row.total;
    double pctWomen = 100.0 * row.women / row.total; 
    out << setw(45) << left << row.major;
    out << fixed << setprecision(2) << right;
    out << setw(10) << pctMen;
    out << setw(10) << pctWomen;
    out << endl;
}
