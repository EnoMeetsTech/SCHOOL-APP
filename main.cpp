#include <iostream>
#include <fstream>

using namespace std;

void createData();
void findData();
void deleteData();
string name;


int main()
{
    cout << "Welcome! What is your name?" << endl;
    cin >> name;

    int perform;

    startpoint:
    cout << "What do you want to do? To create data enter 1. To find data enter 2. To delete data enter 3" << endl;
    cin >> perform;

    if(perform == 1){
        createData();
    }

    if (perform == 2){
        findData();
        }

    if (perform == 3){
        deleteData();
    }

    cout << "Do you want to carry out another function? Enter 1 to do so, 2 to terminate program." << endl;
    cin >> perform;

    if (perform == 1){
        goto startpoint;
    }
}


void createData(){
    ofstream writeData;

    string FirstName;
    string SecondName;
    string MathsScore;
    string EnglishScore;
    string ScienceScore;
    string Position;

    int perform;

    writeData.open("studentDataFile.txt", ios::app);
    if(writeData.is_open() == true){

      enteringPoint:

         cout << "What is the student's first name?" << endl;
         cin >> FirstName;

         cout << "What is the student's second name?" << endl;
         cin >> SecondName;

         cout << "What is the student's Maths score?" <<endl;
         cin >> MathsScore;

         cout << "What is the student's English score?" <<endl;
         cin >> EnglishScore;

         cout << "What is the student's Science score?" <<endl;
         cin >> ScienceScore;

         cout << "What is the student's position?" <<endl;
         cin >> Position;

         writeData << FirstName << "  " << SecondName << "  " << MathsScore  << "  " << EnglishScore << "  " <<
         ScienceScore << "  " << Position << "  " << endl;

         cout << "Do you want to save another report? Enter 1 to carry out another operation or 2 to end operation" << endl;
         cin >> perform;

         if (perform == 1){
            goto enteringPoint;
         }



    }else {
        cout << "The file is invalid." << endl;
    }

    writeData.close();
};

void findData(){
    ifstream readData;
    string FirstName;
    string SecondName;
    string MathsScore;
    string EnglishScore;
    string ScienceScore;
    string Position;

    int perform;

    string FirstNameFind;
    string SecondNameFind;

    bool found = false;

    findPoint:
    found = false;
    readData.seekg(0);

    readData.open("studentDataFile.txt");
    if (readData.is_open ()== true){
        cout << "What is the first name of the student whose data you seek?" << endl;
        cin >> FirstNameFind;

        cout << "What is the second name of the student whose data you seek?" << endl;
        cin >> SecondNameFind;

        while(readData >> FirstName >> SecondName >> MathsScore >> EnglishScore >> ScienceScore >> Position){
                if (FirstNameFind == FirstName && SecondNameFind == SecondName){

                    cout << "The student name is : " << FirstName << "  " << SecondName << endl;
                    cout << "The student Math score is : " << MathsScore << endl;
                    cout << "The student English score is : " << EnglishScore << endl;
                    cout << "The student Science score is : " << ScienceScore << endl;
                    cout << "The student Position is : " << Position << endl;
                        found =  true;
                }
        }
            if(found== false){
        cout << "The student data you seek is not found." << endl;
            }

            cout << "Do you want to save another report? Enter 1 to carry out another operation or 2 to end operation" << endl;
            cin >> perform;



    }else {
        cout << "The file is invalid." << endl;
    }

    readData.close();
    if (perform == 1){
    goto findPoint;
    }



};

void deleteData(){
    ifstream findInfo;
    ofstream copyInfo;

    string FirstName;
    string SecondName;
    string MathScore;
    string EnglishScore;
    string ScienceScore;
    string Position;

    int perform;

    string FirstNameDelete;
    string SecondNameDelete;

    cancelpoint:

    findInfo.open("studentDataFile.txt");
    copyInfo.open("copyingData.txt");

    if(findInfo.is_open()){

            cout << "Enter the first name of the student whose data you want to delete." << endl;
            cin >> FirstNameDelete;

            cout << "Enter the second name of the student whose data you want to delete." << endl;
            cin >> SecondNameDelete;



        while(findInfo >> FirstName >> SecondName >> MathScore >> EnglishScore >> ScienceScore >> Position){

                    if (FirstNameDelete != FirstName && SecondNameDelete != SecondName){

                     copyInfo << FirstName << "  " << SecondName << "  " << MathScore << "  " << EnglishScore << "  " << ScienceScore << "  " << Position << endl;
                    }
                }

                findInfo.close();
                copyInfo.close();

                remove("studentDataFile.txt");
                rename ("copyingData.txt", "studentDataFIle.txt");

                cout << "Do you want to carry out another operation? Enter 1 to do so, 2 to end program. " << endl;
                cin >> perform;

                if (perform == 1){
                goto cancelpoint;
                }



        }else{
            cout << "File is not open" << endl;
        }





};
