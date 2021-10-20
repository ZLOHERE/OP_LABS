#include <iostream>
#include <cstring>
using namespace std;
bool palindrom(char* stroka, int len) {
    for (int i = 0, j = len - 1; i <= j; i++, j--)
    {
        while (stroka[i] == ' ')
        {
            i++;
        }
        while (stroka[j] == ' ')
        {
            j--;
        }
        if (stroka[i] < 'a')
        {
            stroka[i] = char(stroka[i] + ('a' - 'A'));
        }
        if (stroka[j] < 'a')
        {
            stroka[j] = char(stroka[j] + ('a' - 'A'));
        }
        if (stroka[i] != stroka[j]) {
            return false;
        }
    }
    return true;
}
int find_substring1(char* str_for_search_in, char* substring, int start) {

    char* newstr = strstr(&str_for_search_in[start], substring);
    if (newstr == nullptr)
        return 257;
    return ((strlen(str_for_search_in) - 1) - (strlen(newstr) - 1));
}
void encrypt(char* str_input, int key, char*& str_encrypt, int enc_shift) {
    if (str_encrypt != nullptr)
        delete[] str_encrypt;
    str_encrypt = new char[key];
    for (int i = 0; i < key; i++)
    {
        if ((str_input[i]) + enc_shift>'z') {
            str_encrypt[i] = char(str_input[i]-26 + enc_shift);
        }
        else
        {
            if (((str_input[i]) +enc_shift> 'Z') and(str_input[i]<'a')) {
                str_encrypt[i] = char(str_input[i] - 26 + enc_shift);
            }
            else
            {
                str_encrypt[i] = char(str_input[i] + enc_shift);
            }
        }
    }
}
void text_from_quotes(char* str_text, int len) {
    int count_quotes = 0;
    for (int i = 0; i < len; i++)
    {
        if ((str_text[i] == '"') or (str_text[i] == '«') or (str_text[i] == '»'))
        {
            count_quotes++;
        }
    }
    if ((count_quotes % 2 == 1))
    {
        count_quotes--;
    }
    for (int i = 0; i < len; i++)
    {
        if ((str_text[i] == '"') or (str_text[i] == '«') or (str_text[i] == '»'))
        {
            if ((count_quotes % 2 == 1) and (count_quotes - 1 != 0))
                cout << " " << "|" << " ";
            i++;
            count_quotes--;
        }
        if (count_quotes % 2 == 1)
        {
            cout << str_text[i];
        }
        if (count_quotes == 0) {
            cout << "\n";
            break;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    while (true) {
        int choise;
        char text[255] = { 0 };
        cout << "1)Проверка на полиндром\n" <<
            "2)Поиск подстроки в строке\n" <<
            "3)Шифрование сдвигами(Шифр Цезаря)\n" <<
            "4)Вывод названий из строки\n" <<
            "5)Выход" << endl;
        cin >> skipws >> choise;
        switch (choise)
        {
        case 1: {
            int i = 0;
            cout << "Введите С строку, '.' чтобы завершить ввод:\n";
            cin >> text[i];
            while (text[i] != '.')
            {
                i++;
                cin >> text[i];
            }
            system("cls");
            if (palindrom(text, i) == true) {
                cout << "Это палиндром\n";
            }
            else
            {
                cout << "Это не палиндром\n";
            }
        }

              break;
        case 2: {
            char text1[255] = { 0 };
            int i = 0;
            cout << "Введите С строку, '.' чтобы завершить ввод:\n";
            cin >> text[i];
            while (text[i] != '.')
            {
                i++;
                cin >> text[i];
            }
            int j = 0;
            cout << "Введите подстроку, '.' чтобы завершить ввод:\n";
            cin >> text1[j];
            while (text1[j] != '.')
            {
                j++;
                cin >> text1[j];
            }
            int mas[255] = { 0 };
            int mascol = 0;
            char newstr1[255] = { 0 };
            strncpy_s(newstr1, text1, j);
            int t = 0;
            while (find_substring1(text, newstr1, t) != 257)
            {
                mas[mascol] = find_substring1(text, newstr1, t);
                t = mas[mascol++] + 1;
            }
            system("cls");
            for (int iter = 0; iter < mascol; iter++)
            {
                cout << mas[iter] << " ";
            }
            cout << "\n";
        }
              break;
        case 3: {
            char text[255] = { 0 };
            int i = 0;
            cout << "Введите С строку, '.' чтобы завершить ввод:\n";
            cin >> text[i];
            while (text[i] != '.')
            {
                i++;
                cin >> text[i];
            }
            char* str_for_encrypt = nullptr;
            int znach_for_sdvig;
            cout << "Введите значение сдвига:\n";
            cin >> znach_for_sdvig;
            encrypt(text, i, str_for_encrypt, znach_for_sdvig);
            system("cls");
            for (int l = 0; l < i; l++)
            {
                cout << str_for_encrypt[l];
            }
            cout << "\n";
        }
              break;
        case 4:
        {
            char text[255] = { 0 };
            int i = 0;
            cout << "Введите С строку, '.' чтобы завершить ввод:\n";
            cin >> text[i];
            while (text[i] != '.')
            {
                i++;
                cin >> noskipws >> text[i];
            }
            system("cls");
            text_from_quotes(text, i);
        }
        break;
        case 5:
        default:
            return 0;
        }
    }

}
