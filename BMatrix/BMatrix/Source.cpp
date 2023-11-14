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

        cout << "������� ���������� ������� �������:\n";
        cout << "1. ��������� ����\n";

        cout << endl;
        int selectFill;
        cout << "������� 1, ����� ������ ����������: ";
        cin >> selectFill;
        switch (selectFill)
        {
        case 1:
        {
            cin >> lab_BM_1;
            cout << "\n������ �������:\n" << lab_BM_1;

            break;
        }
        default: exit(0);
        }

        cout << "\n��������� �������:\n";
        cout << "2. ����������� ������ �� ������\n";
        cout << "3. ���������� �����\n";
        cout << "4. ���������� �����\n";
        cout << "5. ��������� ������\n";
        cout << "6. ���������� ������\n";
        cout << "0. ������� ���������\n";

        int selectFunction = -1;
        while (selectFunction != 0)
        {
            cout << "\n�������� �������: ";
            cin >> selectFunction;
            switch (selectFunction)
            {
            case 2:
            {
                int necessaryRow;
                cout << "�������, ����� ������ �������: ";
                cin >> necessaryRow;

                cout << lab_BM_1[necessaryRow - 1] << endl;

                break;
            }
            case 3:
            {
                BoolVector resultingVector = lab_BM_1.rowConjuction();
                cout << "�������������� ������: " << resultingVector;

                break;
            }
            case 4:
            {
                BoolVector resultingVector = lab_BM_1.rowDisjunction();
                cout << "�������������� ������: " << resultingVector;

                break;
            }
            case 5:
            {
                BoolMatrix lab_BM_2;
                cout << "������� ��������� ������ �������:\n";
                cin >> lab_BM_2;

                cout << "������ �������:\n" << lab_BM_1;
                cout << "������ �������:\n" << lab_BM_2;

                lab_BM_1 &= lab_BM_2;
                cout << "���������:\n" << lab_BM_1;

                break;
            }
            case 6:
            {
                BoolMatrix lab_BM_2;
                cout << "������� ��������� ������ �������:\n";
                cin >> lab_BM_2;

                cout << "������ �������:\n" << lab_BM_1;
                cout << "������ �������:\n" << lab_BM_2;

                lab_BM_1 |= lab_BM_2;
                cout << "���������:\n" << lab_BM_1;

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