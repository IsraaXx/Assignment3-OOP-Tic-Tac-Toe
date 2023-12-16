// File name: A3_SheetPb1_20221026.cpp
// Purpose: label generator that allows the client to define arbitrary sequences of labels and number the figure and allow to read the caption of labels from file
// Author: Amany Mohamed Hussien Mohamed
// ID: 20221026
// Section: S1,S2
// Date: 2/12/2023
// Version: version1
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class LabelGenerator
{
    protected:
    string prefix_string;
    int index;

public:
    LabelGenerator(string s,int i)
    //parameterzed constructor
{
    prefix_string=s;
    index=i;

}

    virtual string nextLabel()
{
    string label= prefix_string + to_string(index); //combination between string and string( number of figure (index))
    index++;
    return label;
}
};
class FileLabelGenerator:public LabelGenerator  //inheritance from base class
{
    private:
    ifstream inputFile;
    public:
    FileLabelGenerator(string s, int i, string f):LabelGenerator(s,i),inputFile(f){} //parameterized constructor for child class 

    string nextLabel()
    //override nextLabel function in base class in child class
{
    string label = LabelGenerator::nextLabel(); //call the base class function to implement in child class
        string caption; //what I will read from file

        if (getline(inputFile, caption)) {
            label += " : " + caption;
        }

        return label;
}
};
int main()
{

   LabelGenerator figureNumbers("Figure ", 1);
   LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
for (int i = 0; i < 3; i++) {
cout << figureNumbers.nextLabel();
if (i<2) //to make the output as the question need 
cout<<",";
}
cout << endl << "Point numbers: ";
for (int i = 0; i < 5; i++) {
cout << pointNumbers.nextLabel();
if (i<4) //to make the output as the question need 
cout<<",";
}
cout << endl << "More figures: ";
for (int i = 0; i < 3; i++) {
cout << figureNumbers.nextLabel();
if (i<2) //to make the output as the question need 
cout<<",";
}
cout<<endl;
FileLabelGenerator figureLabels("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 4; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
cout << endl;
    return 0;
}
