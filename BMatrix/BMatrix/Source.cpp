#include <iostream>
#include "BoolMatrix.h"

using std::cin;
using std::cout;
using std::endl;




int main() {

    try
    {
        setlocale(LC_ALL, "Rus");
        srand(unsigned(time(NULL)));

        BoolMatrix lab_BM_1;

        cout << "Способы заполнения булевой матрицы:\n";
        cout << "1. Потоковый ввод\n";

        cout << endl;
        int selectFill;
        cout << "Нажмите 1, чтобы начать заполнение: ";
        cin >> selectFill;
        switch (selectFill)
        {
        case 1:
        {
            cin >> lab_BM_1;
            cout << "\nБулева матрица:\n" << lab_BM_1;

            break;
        }
        default: exit(0);
        }

        cout << "\nДоступные функции:\n";
        cout << "2. Возвращение ссылки на строку\n";
        cout << "3. Конъюнкция строк\n";
        cout << "4. Дизъюнкция строк\n";
        cout << "5. Конъюкция матриц\n";
        cout << "6. Дизъюнкция матриц\n";
        cout << "0. Закрыть программу\n";

        int selectFunction = -1;
        while (selectFunction != 0)
        {
            cout << "\nВыберите функцию: ";
            cin >> selectFunction;
            switch (selectFunction)
            {
            case 2:
            {
                int necessaryRow;
                cout << "Укажите, какую строку вывести: ";
                cin >> necessaryRow;

                cout << lab_BM_1[necessaryRow - 1] << endl;

                break;
            }
            case 3:
            {
                BoolVector resultingVector = lab_BM_1.rowConjuction();
                cout << "Результирующий вектор: " << resultingVector;

                break;
            }
            case 4:
            {
                BoolVector resultingVector = lab_BM_1.rowDisjunction();
                cout << "Результирующий вектор: " << resultingVector;

                break;
            }
            case 5:
            {
                BoolMatrix lab_BM_2;
                cout << "Задайте параметры второй матрицы:\n";
                cin >> lab_BM_2;

                cout << "Первая матрица:\n" << lab_BM_1;
                cout << "Вторая матрица:\n" << lab_BM_2;

                lab_BM_1 &= lab_BM_2;
                cout << "Результат:\n" << lab_BM_1;

                break;
            }
            case 6:
            {
                BoolMatrix lab_BM_2;
                cout << "Задайте параметры второй матрицы:\n";
                cin >> lab_BM_2;

                cout << "Первая матрица:\n" << lab_BM_1;
                cout << "Вторая матрица:\n" << lab_BM_2;

                lab_BM_1 |= lab_BM_2;
                cout << "Результат:\n" << lab_BM_1;

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