#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
class file{
    private :
    string text;
    string name;
public:
    file(string file_text ,string file_name){
        text=file_text;
        name=file_name;
    }
    string get_text(){
        return text;
    }
    string get_name(){
        return name;
    }
};
class folder{
    private:
    string name_folder;
    vector<string> fold;
public:
    folder(vector<string> papka, string namefold){
        fold=papka;
        name_folder=namefold;
    }
    string get_name_folder(){
        return name_folder;
    }
    void set_fold_cont(vector<string> papka){
        fold=papka;
    }
    vector<string> get_fold_cont(){
        	return fold;
      	}
    void print(){
        cout << "Content of papka: " << endl;
        for (int i=0; i<fold.size(); i++){
            cout << fold[i] << endl;
        }
    }
};
class directory{
private:
    string name_direct;
    vector<string> direct;
public:
    directory(vector<string> dir, string name_dir){
        direct=dir;
        name_direct=name_dir;
    }
    string get_name_direct(){
        return name_direct;
    }
    vector<string> get_direct_cont(){
        return direct;
    }
    void print(){
        cout << "Content of directory: " << endl;
        for (int i=0; i<direct.size(); i++){
            cout << direct[i];
        }
    }
};


int main() {
    vector<string> pdirect;
    vector<string> pname;
    vector<string> ptext;
    string name_d;
    vector<string> pfold;
    vector<string> pfoldname;
    string name_f;
    string nam,contet;
    int n;
    string command;
    cout << "Enter size of commands: "<< endl;
    cin >> n;
    file failil(contet,nam);
    folder papkil(pfold,name_f);
    directory direx(pdirect,name_d);
    for (int i=0; i<n; i++){
    cout << "Enter command: "<< endl;
    cin >> command;
        if (command=="create_file"){
            cout << "Enter name of file: "<< endl;
            cin >> nam;
            cout << "Enter content of file: "<< endl;
            cin >> contet;
            pname.push_back(nam);
            ptext.push_back(contet);
            cout << failil.get_name();
        }
        if (command=="create_folder"){
            cout << "Enter name of folder: "<< endl;
            cin >> name_f;
            pfoldname.push_back(name_f);
            cout << papkil.get_name_folder();
        
        }
        if (command=="create_directory"){
            cout << "Enter name of folder: "<< endl;
            cin >> name_d;
            cout << direx.get_name_direct();
        }
        if (command=="add_folder"){
            string folder_name , folder_file;
            cout << "Enter name of folder to addid: "<< endl;
            cin >> folder_name;
            cout << "Enter name of file to addid: "<< endl;
            cin >> folder_file;
            for(int i=0; i<pfoldname.size(); i++){
                if (pfoldname[i]==folder_name){
                    for(int j=0; j<pname.size(); j++){
                        if(folder_file==pname[j]){
                        pfold[i].push_back(folder_file);
                        }
                    }
            }
            for(int j=0; j<pname.size(); j++){
                pfold.push_back(pname[j]);
                papkil.set_fold_cont(pfold);
            }
            }
        }
        if (command=="list_folder"){
            papkil.print();
        }
    }
    return 0;
}
