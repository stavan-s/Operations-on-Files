#include<bits/stdc++.h>

using namespace std;

char to_lowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }

    return c;
}

int main() {

    bool terminate_condition = true;
    string str;
    int choice;
    bool check = true;
    string check_string;
    int c = 0;
    string name_string, surname_string, inp_string;
    bool name_exists = false;
    int name_length, surname_length;
    string check_name, check_surname;
    int i = 0;

    while(terminate_condition) {

        system("cls");

        ofstream MyWriteFile;
        MyWriteFile.open("file.txt", ios :: app);
        
        ifstream MyReadFile;
        MyReadFile.open("file.txt", ios :: in);

        cout<<"1. Read from file"<<endl;
        cout<<"2. Write into file"<<endl;
        cout<<"3. Delete all the contents from the file"<<endl;
        cout<<"4. Check whether a name exists in the file"<<endl;
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
                    else {
                        for(char &c : str) {
                            c = to_lowercase(c);
                        }
                        MyWriteFile << str << "\n";
                    }
                }
                check = true;
                break;

            case 3:
                MyWriteFile.close();
                MyWriteFile.open("file.txt", ios :: trunc);
                MyWriteFile.close();
                MyWriteFile.open("file.txt", ios :: app);
                c = 0;

                cout<<"\nFile erased successfully!"<<endl;

                break;

            case 4:

                cout<<"\nEnter the name you want to search -> ";
                cin>>name_string;
                name_length = name_string.length();

                for(char &c : name_string) {
                    c = to_lowercase(c);
                }
                

                cout<<"\nEnter the surname -> ";
                cin>>surname_string;
                surname_length = surname_string.length();

                for(char &c : surname_string) {
                    c = to_lowercase(c);
                }
                

                while(getline(MyReadFile, inp_string)) {
                    if (inp_string.length() >= name_length + surname_length) {

                        check_name = inp_string.substr(0, name_length);
                        check_surname = inp_string.substr(name_length+1, (name_length + surname_length)+1);

                        if(check_name == name_string && check_surname == surname_string)
                            name_exists = true;
                    }
                }
                if(name_exists) cout<<"\nExists"<<endl;
                else cout<<"\nDoes not exist"<<endl;

                name_exists = false;

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
