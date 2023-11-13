
#include "BoolVector.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main() {

    BoolVector t1 = BoolVector(10, 0);
    BoolVector t2 = BoolVector(10, 1);
    cout << t1<<endl;
    cout << t2<<endl;
    BoolVector t3;
    BoolVector t4;
    t3 = t1;
    t4 = t2;
    cout << t3.weight() << endl;
    cout << t4.weight() << endl;

    try
    {
        setlocale(LC_ALL, "Rus");
        srand(unsigned(time(NULL)));

        BoolVector lab_BV_1;

        cout << "Способы заполнения булевого вектора:\n";
        cout << "1. Случайными числами\n";
        cout << "2. Потоковый ввод\n";

        cout << endl;
        int selectFill;
        cout << "Выберите способ заполнения: ";
        cin >> selectFill;

        switch (selectFill)
        {
        case 1:
        {
            int lab_Lenght_BV;
            cout << "Длина вектора: ";
            cin >> lab_Lenght_BV;

            int fillingMethod;
            cout << "Введите 0, чтобы заполнить нулями, 1 - единицами, любое другое число - случайным образом: ";
            cin >> fillingMethod;

            BoolVector tmp(lab_Lenght_BV, fillingMethod);
            lab_BV_1 = tmp;
            cout << "\nБулев вектор:\n" << lab_BV_1;

            break;
        }
        case 2:
        {
            cin >> lab_BV_1;
            cout << "\nБулев вектор:\n" << lab_BV_1;

            break;
        }
        default: exit(0);
        }

        cout << endl;

        cout << "\nДоступные функции:\n";
        cout << "3. Установка 1 в заданный разряд\n";
        cout << "4. Установка 0 в заданный разряд\n";
        cout << "5. Инверсия заданного разряда\n";
        cout << "6. Значение выбранного разряда\n";
        cout << "7. Побитовый сдвиг влево\n";
        cout << "8. Побитовый сдвиг вправо\n";
        cout << "9. Дизъюнкция векторов\n";
        cout << "10. Конъюкция векторов\n";
        cout << "11. Исключающее ИЛИ векторов\n";
        cout << "12. Инверсия вектора\n";
        cout << "0. Закрыть программу\n";

        int selectFunction = -1;
        while (selectFunction != 0)
        {
            cout << "\nВыберите функцию: ";
            cin >> selectFunction;
            switch (selectFunction)
            {
            case 3:
            {
                int necessaryBit;
                cout << "Разряд, подлежащий изменению: ";
                cin >> necessaryBit;

                int quanityBit;
                cout << "Количество разрядов для изменения (справа налево): ";
                cin >> quanityBit;

                lab_BV_1.setOne(necessaryBit, quanityBit);
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 4:
            {
                int necessaryBit;
                cout << "Разряд, подлежащий изменению: ";
                cin >> necessaryBit;

                int quanityBit;
                cout << "Количество разрядов для изменения (справа налево): ";
                cin >> quanityBit;

                lab_BV_1.setZero(necessaryBit, quanityBit);
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 5:
            {
                int necessaryBit;
                cout << "Разряд, подлежащий изменению: ";
                cin >> necessaryBit;

                int quanityBit;
                cout << "Количество разрядов для изменения (справа налево): ";

                cin >> quanityBit;
                lab_BV_1.inverseComponent(necessaryBit, quanityBit);
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 6:
            {
                int necessaryBit;
                cout << "Разряд, подлежащий изменению: ";
                cin >> necessaryBit;

                cout << lab_BV_1[necessaryBit];

                cout << endl;
                break;
            }
            case 7:
            {
                int quanityBit;
                cout << "Количество разрядов для сдвига: ";
                cin >> quanityBit;

                lab_BV_1 <<= quanityBit;
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 8:
            {
                int quanityBit;
                cout << "Количество разрядов для сдвига: ";
                cin >> quanityBit;

                lab_BV_1 >>= quanityBit;
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 9:
            {
                BoolVector lab_BV_2;
                cout << "Задайте параметры второго вектора:\n";
                cin >> lab_BV_2;

                cout << "Первый вектор:\n" << lab_BV_1 << endl;
                cout << "Второй вектор:\n" << lab_BV_2 << endl;

                lab_BV_1 |= lab_BV_2;
                cout << "Результирующий вектор:\n" << lab_BV_1;

                cout << endl;
                break;
            }
            case 10:
            {
                BoolVector lab_BV_2;
                cout << "Задайте параметры второго вектора:\n";
                cin >> lab_BV_2;

                cout << "Первый вектор:\n" << lab_BV_1 << endl;
                cout << "Второй вектор:\n" << lab_BV_2 << endl;

                lab_BV_1 &= lab_BV_2;
                cout << "Результирующий вектор:\n" << lab_BV_1;

                cout << endl;
                break;
            }
            case 11:
            {
                BoolVector lab_BV_2;
                cout << "Задайте параметры второго вектора:\n";
                cin >> lab_BV_2;

                cout << "Первый вектор:\n" << lab_BV_1 << endl;
                cout << "Второй вектор:\n" << lab_BV_2 << endl;

                lab_BV_1 ^= lab_BV_2;
                cout << "Результирующий вектор:\n" << lab_BV_1;

                cout << endl;
                break;
            }
            case 12:
            {
                cout << ~lab_BV_1;

                cout << endl;
                break;
            }
            default: exit(0);
            }
        }
    }
    catch (Errors_and_Exceprions SomethingWentWrong)
    {
        return SomethingWentWrong;
    }

    return 0;
}


