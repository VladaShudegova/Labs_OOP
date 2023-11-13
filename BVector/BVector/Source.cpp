
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

        cout << "������� ���������� �������� �������:\n";
        cout << "1. ���������� �������\n";
        cout << "2. ��������� ����\n";

        cout << endl;
        int selectFill;
        cout << "�������� ������ ����������: ";
        cin >> selectFill;

        switch (selectFill)
        {
        case 1:
        {
            int lab_Lenght_BV;
            cout << "����� �������: ";
            cin >> lab_Lenght_BV;

            int fillingMethod;
            cout << "������� 0, ����� ��������� ������, 1 - ���������, ����� ������ ����� - ��������� �������: ";
            cin >> fillingMethod;

            BoolVector tmp(lab_Lenght_BV, fillingMethod);
            lab_BV_1 = tmp;
            cout << "\n����� ������:\n" << lab_BV_1;

            break;
        }
        case 2:
        {
            cin >> lab_BV_1;
            cout << "\n����� ������:\n" << lab_BV_1;

            break;
        }
        default: exit(0);
        }

        cout << endl;

        cout << "\n��������� �������:\n";
        cout << "3. ��������� 1 � �������� ������\n";
        cout << "4. ��������� 0 � �������� ������\n";
        cout << "5. �������� ��������� �������\n";
        cout << "6. �������� ���������� �������\n";
        cout << "7. ��������� ����� �����\n";
        cout << "8. ��������� ����� ������\n";
        cout << "9. ���������� ��������\n";
        cout << "10. ��������� ��������\n";
        cout << "11. ����������� ��� ��������\n";
        cout << "12. �������� �������\n";
        cout << "0. ������� ���������\n";

        int selectFunction = -1;
        while (selectFunction != 0)
        {
            cout << "\n�������� �������: ";
            cin >> selectFunction;
            switch (selectFunction)
            {
            case 3:
            {
                int necessaryBit;
                cout << "������, ���������� ���������: ";
                cin >> necessaryBit;

                int quanityBit;
                cout << "���������� �������� ��� ��������� (������ ������): ";
                cin >> quanityBit;

                lab_BV_1.setOne(necessaryBit, quanityBit);
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 4:
            {
                int necessaryBit;
                cout << "������, ���������� ���������: ";
                cin >> necessaryBit;

                int quanityBit;
                cout << "���������� �������� ��� ��������� (������ ������): ";
                cin >> quanityBit;

                lab_BV_1.setZero(necessaryBit, quanityBit);
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 5:
            {
                int necessaryBit;
                cout << "������, ���������� ���������: ";
                cin >> necessaryBit;

                int quanityBit;
                cout << "���������� �������� ��� ��������� (������ ������): ";

                cin >> quanityBit;
                lab_BV_1.inverseComponent(necessaryBit, quanityBit);
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 6:
            {
                int necessaryBit;
                cout << "������, ���������� ���������: ";
                cin >> necessaryBit;

                cout << lab_BV_1[necessaryBit];

                cout << endl;
                break;
            }
            case 7:
            {
                int quanityBit;
                cout << "���������� �������� ��� ������: ";
                cin >> quanityBit;

                lab_BV_1 <<= quanityBit;
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 8:
            {
                int quanityBit;
                cout << "���������� �������� ��� ������: ";
                cin >> quanityBit;

                lab_BV_1 >>= quanityBit;
                cout << lab_BV_1;

                cout << endl;
                break;
            }
            case 9:
            {
                BoolVector lab_BV_2;
                cout << "������� ��������� ������� �������:\n";
                cin >> lab_BV_2;

                cout << "������ ������:\n" << lab_BV_1 << endl;
                cout << "������ ������:\n" << lab_BV_2 << endl;

                lab_BV_1 |= lab_BV_2;
                cout << "�������������� ������:\n" << lab_BV_1;

                cout << endl;
                break;
            }
            case 10:
            {
                BoolVector lab_BV_2;
                cout << "������� ��������� ������� �������:\n";
                cin >> lab_BV_2;

                cout << "������ ������:\n" << lab_BV_1 << endl;
                cout << "������ ������:\n" << lab_BV_2 << endl;

                lab_BV_1 &= lab_BV_2;
                cout << "�������������� ������:\n" << lab_BV_1;

                cout << endl;
                break;
            }
            case 11:
            {
                BoolVector lab_BV_2;
                cout << "������� ��������� ������� �������:\n";
                cin >> lab_BV_2;

                cout << "������ ������:\n" << lab_BV_1 << endl;
                cout << "������ ������:\n" << lab_BV_2 << endl;

                lab_BV_1 ^= lab_BV_2;
                cout << "�������������� ������:\n" << lab_BV_1;

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


