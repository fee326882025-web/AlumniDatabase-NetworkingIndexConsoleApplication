#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct Alumni {
    string name;
    int graduationYear;
    string skill;
    string company;
    string phone;
};
vector <Alumni> alumniData;
Alumni b;
//check if user is first time user or not
bool isFirstTimeUser() {
    ifstream file("AlumniDatabase&NetworkingIndexData.txt");
    return !file.good();
}
//function to load data from file
void loadData() {
    ifstream file("AlumniDatabase&NetworkingIndexData.txt");
    if (!file.is_open())
     return;

    Alumni d;
    string label, x;

    // Correctly parsing the format: "Label: x"
    while (file >> label >> d.name) {
        file >> label >> label >> d.graduationYear; // "Graduation" "year:" x
        file >> label >> d.phone;                   // "Phonenumber:" x
        file >> label >> d.company;                 // "Company:" x
        file >> label >> d.skill;                   // "Skill:" x
        file >> x;                                 // Consume the "************************"
        alumniData.push_back(d);
    }
    file.close();
}
//function to save data to file
void saveData() {
    ofstream file("AlumniDatabase&NetworkingIndexData.txt");
    if (!file.is_open())
        return;

    for (const auto& d : alumniData) {
        file << "Name: " << d.name << endl;
        file << "Graduation year: " << d.graduationYear << endl;
        file << "Phonenumber: " << d.phone << endl;
        file << "Company: " << d.company << endl;
        file << "Skill: " << d.skill << endl;
        file << "************************" << endl;
    }
    file.close();
}
//function to create Alumni Profile
void profile(){
    cout << "Welcome to Alumni Profile Creation!" << endl;
    cout << "Please enter the following information:" << endl;
    int l;
    cout << "How many alumni profiles do you want to create? ";
    cin >> l;
    for (int m = 0; m < l; m++) { 
        cout << "Record " << m + 1 << ":" << endl;
    cout << "Name: ";
    cin >> b.name;
    cout << "Graduation Year: ";
    cin >> b.graduationYear;
    if (b.graduationYear < 2000 || b.graduationYear > 2099) {
        cout << "Invalid graduation year. Please enter a year between 2000 and 2099." << endl;
        return;
    }
    else {
        cout << "Phone Number: ";
        cin >> b.phone;
        cout << "Company: ";
        cin >> b.company;
        cout << "Skill: ";
        cin >> b.skill;
        alumniData.push_back(b);
        saveData();
        cout << "Profile created successfully!" << endl;
    }
}
}
//function to search for alumni
void search(){
    cout << "Welcome to search menu" << endl;
    cout << "Enter 1 to search by graduation year." << endl;
    cout << "Enter 2 to search by company." << endl;
    cout << "Enter 3 to search by skill." << endl;

    int l;
    cout << "Enter option ";
    cin >> l;

    bool found = false;

    if (l == 1) {
        int searchYear;
        cout << "Enter Graduation Year to search: ";
        cin >> searchYear;

        for (const auto& alumni : alumniData) {
            if (alumni.graduationYear == searchYear) {
                cout << "Alumni Found!"<<endl;
                cout << "Name: " << alumni.name << endl;
                cout << "Graduation year: " << alumni.graduationYear << endl;
                cout << "Phonenumber: " << alumni.phone << endl;
                cout << "Company: " << alumni.company << endl;
                cout << "Skill: " << alumni.skill << endl;
                cout << "************************" << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No alumni found with graduation year " << searchYear << "." << endl;
    }

    else if (l == 2) {
        string searchCompany;
        cout << "Enter Company to search: ";
        cin >> searchCompany;

        for (const auto& alumni : alumniData) {
            if (alumni.company == searchCompany) {
                cout << "Alumni Found!"<<endl;
                cout << "Name: " << alumni.name << endl;
                cout << "Graduation year: " << alumni.graduationYear << endl;
                cout << "Phonenumber: " << alumni.phone << endl;
                cout << "Company: " << alumni.company << endl;
                cout << "Skill: " << alumni.skill << endl;
                cout << "************************" << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No alumni found working at " << searchCompany << "." << endl;
    }

    else if (l == 3) {
        string searchSkill;
        cout << "Enter Skill to search: ";
        cin >> searchSkill;

        for (const auto& alumni : alumniData) {
            if (alumni.skill == searchSkill) {
                cout << "Alumni Found!"<<endl;
                cout << "Name: " << alumni.name << endl;
                cout << "Graduation year: " << alumni.graduationYear << endl;
                cout << "Phonenumber: " << alumni.phone << endl;
                cout << "Company: " << alumni.company << endl;
                cout << "Skill: " << alumni.skill << endl;
                cout << "************************" << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No alumni found with skill in " << searchSkill << "." << endl;
    }
}
//Display all stored data in file
void display(){
    cout << "Welcome to display window." << endl;
    cout << "Displaying all stored data: " << endl;
      cout << "Refer to Exported Alumni Contact Lists.txt for exported contact information." << endl;
        cout << "Stored Alumni information: " << endl;
        cout << "::::::************************::::::" << endl;

    for (int i = 0; i < (int)alumniData.size(); i++){
        ifstream outfile("Exported Alumni Contact Lists.txt", ios::app);
                cout << "Record number: " << i+1 << endl;
        cout << "Name: " << alumniData[i].name << endl;
        cout << "Graduation year: " << alumniData[i].graduationYear << endl;
        cout << "Phonenumber: " << alumniData[i].phone << endl;
        cout << "Company: " << alumniData[i].company << endl;
        cout << "Skill: " << alumniData[i].skill << endl;
        cout << "************************" << endl;
    }
}
//Contact information exportation to .txt file
// Export phone and view phone lists to file
void exportf(){
    cout << "Welcome to file exportation window." << endl;
      cout << "Refer to Exported Alumni Contact Lists.txt for exported contact information." << endl;
        cout << "Exported contact information: " << endl;
        cout << "::::::************************::::::" << endl;

    for (int i = 0; i < (int)alumniData.size(); i++){
        ofstream outfile("Exported Alumni Contact Lists.txt", ios::app);
        outfile << "Record number: " << i+1 << endl;
        outfile << "Name: " << alumniData[i].name << endl;
        outfile << "Phonenumber: " << alumniData[i].phone << endl;
        outfile << "************************" << endl;
        outfile.close();

        cout << "Record number: " << i+1 << endl;
        cout << "Name: " << alumniData[i].name << endl;
        cout << "Graduation year: " << alumniData[i].graduationYear << endl;
        cout << "Phonenumber: " << alumniData[i].phone << endl;
        cout << "Company: " << alumniData[i].company << endl;
        cout << "Skill: " << alumniData[i].skill << endl;
        cout << "************************" << endl;
    }
}
//Introduce the main program
int main(){
    loadData(); // Loads existing data into memory immediately

    cout << "Welcome to Alumni Database & Networking Index!" << endl;
    cout << "*********<<<<>>>************" << endl;

    if (isFirstTimeUser()){
        cout << "Appears to be you first time here!" << endl;
        cout << "Proceed to profile creation." << endl;
        profile();}

    while (true){
        cout << "Enter 1 to add profile." << endl;
        cout << "Enter 2 to search alumni by specific criteria." << endl;
        cout << "Enter 3 to export and view exported information." << endl;
        cout << "Enter 4 to display Alumni stored information." << endl;
        cout << "Enter 5 to exit." << endl;

        int j;
        cout << "Enter option: ";
        cin >> j;

        if (j == 1){
            profile();
        }
        else if (j == 2){
            search();
        }
        else if (j == 3){
            exportf();
        }
        else if (j == 4){
            display();
        }
        else if (j == 5){
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
}
