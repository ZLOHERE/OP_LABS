
#include <iostream>
using namespace std;
void sum_sort(int* mas, int len);
void input(int*& mas, int* len);
void output(int* mas, int len);
void sor_last_num(int* mas, int len);

int main()
{
    setlocale(LC_ALL, "Russian");
    int choize;
    int size;
    int* arr = nullptr;
    while (true) {
        cout << "1.Ввод массива\n" <<
            "2.Вывод массива в консоль\n" <<
            "3.Сортировка по сумме цифр, стоящих на четных местах\n" <<
            "4.Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию\n" <<
            "5.Выход" << endl;
        cin >> choize;
        switch (choize)
        {
        case 1:
            input(arr,&size);
            break;
        case 2:
            output(arr, size);
            break;
        case 3:
            sum_sort(arr, size);
            break;
        case 4:
            sor_last_num(arr,size);
            break;
        case 5:
        default:
            return 0;
        }
    }

}
void input(int*& mas, int* len) {
    if (mas != nullptr) delete[] mas;
    cout << "Введите количество элементов массива\n";
    cin >> *len;
    mas = new int[*len];
    cout << "Введите значения элементов массива\n";
    for (int i = 0; i < *len; i++)
    {
        cin >> mas[i];

    }
}
void output(int* mas, int len) {
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << " ";
    }
    cout << "\n";
}
void sor_last_num(int* mas, int len) {
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if ((mas[j] % 10) > (mas[j + 1] % 10))
            {
                int t = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if ((mas[j] % 10) == (mas[j + 1] % 10))
            {
                if (mas[j] < mas[j + 1])
                {
                    int t = mas[j];
                    mas[j] = mas[j + 1];
                    mas[j + 1] = t;
                }
            }
        }
    }
}
void sum_sort(int* mas, int len) {
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            int sum, t_mas, cnt;
            sum = cnt = 0;
            t_mas = mas[j];
            while (t_mas > 0) {
                cnt += 1;
                t_mas /= 10;
            }
            t_mas = mas[j];
            if (cnt % 2 == 1) {
                while (t_mas > 0) {
                    t_mas /= 10;
                    sum += t_mas % 10;
                    t_mas /= 10;
                }
            }
            else {
                while (t_mas > 0) {
                    sum += t_mas % 10;
                    t_mas /= 100;
                }
            }
            int sum2, t, t_mas2;
            t_mas2 = mas[j + 1];
            sum2 = 0;
            cnt = 0;
            while (t_mas2 > 0) {
                cnt += 1;
                t_mas2 /= 10;
            }
            t_mas2 = mas[j + 1];
            if (cnt % 2 == 1) {
                while (t_mas2 > 0) {
                    t_mas2 /= 10;
                    sum2 += t_mas2 % 10;
                    t_mas2 /= 10;
                }
            }
            else {
                while (t_mas2 > 0) {
                    sum2 += t_mas2 % 10;
                    t_mas2 /= 100;
                }
            }
            if (sum > sum2) {
                t = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = t;
            }
            sum = sum2;
        }
    }
}