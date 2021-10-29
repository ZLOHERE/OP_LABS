
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string file_format(string file_path_full) {
    int n;
    n=file_path_full.rfind(".");
    string str;
    for (int i = n; i < file_path_full.length() ; i++)
    {
        str = str + file_path_full[i];
    }
    return str;
}
string file_name(string file_path_full) {
    string str;
    for (int i = file_path_full.rfind("\\")+1; i < file_path_full.rfind("."); i++)
    {
        str = str + file_path_full[i];
    }
    return str;
}
string file_path(string file_path_full) {
    string str;
    for (int i = 0; i < file_path_full.rfind("\\")+1; i++)
    {
        str = str + file_path_full[i];
    }
    return str;
}
char file_disk(string file_path_full) {
    return file_path_full[0];
}
void file_rename(string* file_path_full, string file_path_ful) {
    string str, str2;
    cout << "Введите новое имя файла:";
    cin >> str;
    str2= file_path(file_path_ful) + str + file_format(file_path_ful);
    *file_path_full = str2;
    return;
}
bool file_copy(string file_path_full) {
    ifstream fin;
    fin.open(file_path_full);
    if (!fin.is_open()) {
        fin.close();
        return 0;
    }
    else {
        ofstream fout;
        fout.open(file_path(file_path_full) + file_name(file_path_full) + "_copy" + file_format(file_path_full));
        string temp;
        while (!fin.eof()) {
            getline(fin, temp);
            fout << temp<<endl;
        }
        fin.close();
        fout.close();
    }
}
int main()
{   
    setlocale(LC_ALL, "Russian");
    int choice;
    string path_name;
    cout << path_name;
    string path;
    while (true)
    {
        cout << "1. Получить расширение\n" <<
            "2. Получить название\n" <<
            "3. Получить расположение файла\n" <<
            "4. Получить название диска\n" <<
            "5. Переименовать файл\n" <<
            "6. Создать копию файла\n" <<
            "7. Выход\n" << endl;
        cin >> choice;
        if ((path_name != "")and(path=="")and(choice<7)) {
            cout << "Вы будете использовать один и тот же путь ? Yes/No"<<endl;
            cin >> path;
        }
        if ((path == "No") or (path == "")and(choice<7)) {
            cout << "Введите путь к расположению файла: ";
            cin >> path_name;
        }
        switch (choice)
        {
        case 1:
            system("cls");
            cout<<file_format(path_name)<<endl;
            break;
        case 2:
            system("cls");
            cout << file_name(path_name)<<endl;
            break;
        case 3:
            system("cls");
            cout << file_path(path_name)<<endl;
            break;
        case 4:
            system("cls");
            cout << file_disk(path_name) << endl;
            break;
        case 5:
            system("cls");
            file_rename(&path_name,path_name);
            cout << path_name<<endl;
            break;
        case 6:
            system("cls");
            if (file_copy(path_name)) {
                cout << "Файл скопирован.\n";
            }
            else
            {
                cout << "Произошла ошибка, файл не может быть открыт.\n";
            }
            break;
        case 7:
        default:
            return 0;
        }
    }
    
}
