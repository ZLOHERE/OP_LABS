#include <iostream>
using namespace std;

void task1() {
    int n,num;
    cout << "Введите число: ";
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            cout << k;
        }
        cout << "\n";
    }

}
void task2() {
    int n, k,res=1;
    cout << "введите n: ";
    cin >> n;
    cout << "введите k: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
        res = res * (n - i) / (i+1);    
    }
    cout << "результат: " << res << endl;
}
void task3(){
    int sim;
    int sum=0, num=0;
    cout << "Среднее арифметическое чисел, введите 0 чтобы остановиться\n";
    while (true) {
        cin >> sim;

        if (sim == 0) {
            double sr_znach = double(sum) / num;
            cout << sr_znach << endl;
            break;
        }
        else {
            sum += sim;
            num += 1;

        }
    }
}
void task4(){

}
int main()
{
    int choice = 0;
    setlocale(LC_ALL, "Russian");
    while (true) {
        cout << "Что вы хотите выполнить ?\n" << "1.задание 1\n" << "2.задание 2\n" << "3.задание 3\n" << "4.выход\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            cout << "Выход";
            break;
        default:
            cout << "Вы вышли за предел\n";
            break;
            return 0;
        }
        if (choice == 4) {
            break;
        }
    }

}
