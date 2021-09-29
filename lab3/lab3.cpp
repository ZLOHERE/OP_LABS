#include <iostream>

using namespace std;
void sort1(int* mas,int num) {
    int helpnum;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num-i-1; j++)
        {
            if (mas[j] > mas[j + 1]) {
                helpnum = mas[j + 1];
                mas[j + 1] = mas[j];
                mas[j] = helpnum;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        cout << mas[i] << ' ';
    }
}
void sort2(char* mas, int num) {
    int mass[122] = {0};//подсчет кол-ва букв
    for (int i = 0; i < num; i++)
    {
        for (int j = 97; j <= 122; j++)
        {
            if (int(mas[i]) == j) {//подсчет кол-ва букв
                mass[j] += 1;
                break;
            }
        }

    }
    for (int i = 97; i < 122; i++)
    {
        for (int j = mass[i]; j>0 ; j--)
        {
            cout << char(i) << " ";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int sort_num;
    int ct_mas;
    cout << "Выберите сортировку: \n1.Сортировка пузырьком\n2.Сортировка подсчетом\n"<<endl;
    cin >> sort_num;
    switch (sort_num)
    {
    case 1:
    {cout << "Введите количество элементов целочисленного массива: ";
    cin >> ct_mas;
    int* arruk = new int[ct_mas]; //объявление динамического массива
    cout << "Введите значения для целочисленного массива: \n";
    for (int i = 0; i < ct_mas; i++)
    {
        cin >> arruk[i];
    }
    sort1(arruk, ct_mas); }
    break;
    case 2:
    {cout << "Введите количество элементов буквенного массива: ";
        cin >> ct_mas;
        char* arruk1 = new char[ct_mas]; //динамический массив только уже символьного типа
        cout << "Введите значения для буквенного массива: \n";
        for (int i = 0; i < ct_mas; i++)
        {
            cin >> arruk1[i];
        }
        sort2(arruk1, ct_mas); // передаю функции указатель на массив и число элементов массива
    }
            break;

        default:
            cout << "число за пределом))" << endl;
            break;


        
        
        
        
        
        
        
        
        
        
    }
    
    
    return 0;
            
}