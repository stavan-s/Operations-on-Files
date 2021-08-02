#include<bits/stdc++.h>

using namespace std;

int main() {

    bool terminate_condition = true;
    string str;
    int choice;
    bool check = true;
    string check_string;
    int c = 0;

    while(terminate_condition) {

        system("cls");

        ofstream MyWriteFile;
        MyWriteFile.open("file.txt", ios :: in | ios :: out | ios :: app);
        
        ifstream MyReadFile;
        MyReadFile.open("file.txt", ios :: in);

        cout<<"1. Read from file"<<endl;
        cout<<"2. Write into file"<<endl;
        cout<<"3. Delete all the contents from the file"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"\nEnter your choice -> ";
        cin>>choice;

        switch (choice) {
            
            case 0:
                return 0;
            
            case 1:
                cout<<"\nThe contents of the file are: "<<endl;
                while(getline(MyReadFile, str)) {
                    cout<<str<<endl;
                    c++;
                }
                if(c == 0) cout<<"\nFile is empty"<<endl;
                
                break;

            case 2:
                
                cout<<"\nStart typing from below (type quit to exit the writing mode):"<<endl;
                while(true) {
                    getline(cin, str);
                    if(str == "quit" || str == "q")  {
                        break;
                    }
                    else
                        MyWriteFile << str <<endl;
                }
                check = true;
                break;

            case 3:
                MyWriteFile.close();
                MyWriteFile.open("file.txt", ios :: out | ios :: trunc);
                MyWriteFile.close();
                MyWriteFile.open("file.txt", ios :: in | ios :: out | ios :: app);
                c = 0;

                cout<<"\nFile erased successfully!"<<endl;

                break;

            default:
                break;
            
        }

        cout<<"\nDo you want to continue? Enter yes or no -> ";
        cin>>check_string;

        terminate_condition = (check_string == "y" || check_string == "yes" || check_string == "Yes" || check_string == "YES") ? true : false; 
        cout<<endl;  

        MyReadFile.close();
        MyWriteFile.close(); 
    }

    return 0;
}
