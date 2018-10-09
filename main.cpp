/*
    Author: Omar AbdelFattah
    University: Cairo University School of Computers and Information
    Major: IS
    Minor: General
    Supervision: phD Mohamed Al-Ramly
    Problem: Searching and File Manipulation
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string capitalize(string);

int main()
{
    string searchName;
    int position;
    bool  gender;
    vector <int> repeats;               //In case name is repeated for more than one gender, maximum repetitions will be Two
    vector <string> differentGenders;   //Two identify the gender of the name in case it is repeated only

    cout<<"Enter Name: ";
    cin>>searchName;
    searchName = capitalize(searchName);

    fstream myFile;
    myFile.open("babynames2012.txt");

    char man[15], woman[15], nameRank[7];   //an offset more than or equal the possible inputs for the three records
    int i = 1;

    while(myFile >> nameRank >> man >> woman){
        if(searchName == man || searchName == woman){       //Name Found
            if(searchName == man){
                gender = 0;
                differentGenders.push_back("boys");
            }
            if(searchName == woman){
                gender = 1;
                differentGenders.push_back("girls");
            }

            position = i;
            repeats.push_back(i);
        }
        i++;
    }
    if(repeats.size() == 1){
        if(gender){
            cout << searchName << " is ranked " << position << " at the side of girls" <<endl;
        }
        else{
            cout << searchName << " is ranked " << position << " in popularity among boys" <<endl;
        }
    }
    else if(repeats.size() > 1){
        //if(gender){
            cout << searchName << " is ranked " << repeats[0] << " in popularity among " << differentGenders[0] << "\n" << searchName << " is ranked " << repeats[1] << " in popularity among " << differentGenders[1] <<endl;
        //}
        //else{
          //  cout << searchName << " exists at " << repeats[0] <<" and " << repeats[1] << " at side of " << differentGenders <<endl;
        //}


    }
    else{
        cout<<searchName<<" Not Found!"<<endl;
    }
    return 0;
}

string capitalize(string s){        //Find it on Github on https://github.com/OmarAbdAlFattah/A.-Word-Capitalization-CodeForces
    int value;
    if(int(s[0]) >= 97 && int(s[0] <= 122)){    //if low case
        value = int(s[0]) - 32;
        s[0] = char(value);
    }
    return s;
}
