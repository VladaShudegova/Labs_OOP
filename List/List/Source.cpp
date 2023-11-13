
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <locale>
#include "Node.h"
#include "List.h"

using namespace std;

/* ��������� ���������� */
enum Errors_and_Exceptions
{
    /* ��� List */
    errorArraySizeLessZero,
    errorArrayAdressNotPassed,
    errorNumberOfListElementsWasPassedIncorrectly,
    errorElementIndexWasPassedIncorrectly,
};

//
//+ ������������ (�� ���������, � �����������, ����������� �� ������� int, ����������� �����������);
//+����������;
//+���� / ����� � �������(���������);
//+����� �������� �� �����(���������� ��������� �� ������� ��� nullptr, ���� �������� ��� � ������);
//+���������� ��������(� ������, �����, �� �������, ����� �����(����� ������� ���������);
//+�������� ��������(�� ������, ������, �������, �� �����(������ ���������);
//+����� ������������� / ������������ ��������;
//+isEmpty() - ���������� true, ���� ������ ����;
//+������� ������;
//-���������� ������;
//����������� ���������� :
//+������������(= );
//+��������� ������ �� ���� ��������([]);
//+���������(== , != );
//+�������� �������(+).



int main()
{
    try
    {
        setlocale(LC_ALL, "Rus");
        srand(unsigned(time(NULL)));
    
       
        cout << "������� ����������� ������ 0: ";
        int sizeList0;
        cin >> sizeList0;
        List lab_List_0;
        lab_List_0.inputList(sizeList0);
       
        cout << "[0]" <<" - " << lab_List_0[0] << endl;
        cout << "[2]" <<" - " << lab_List_0[2] << endl;
        cout << "[5]" <<" - " << lab_List_0[5] << endl;

        lab_List_0.clearList();

        /* ������ 1*/
        cout << "������� ������ ������ 1: ";
        int newHeadList1;
        cin >> newHeadList1;

        cout << "������ 1: ";
        List lab_List_1;

        lab_List_1.addToHead(newHeadList1);
        lab_List_1.printList();

        cout << endl << endl;

        /* ������ 2 */
        cout << "������� ����������� ������ 2: ";
        int sizeList2;
        cin >> sizeList2;

        List lab_List_2;

        lab_List_2.inputList(sizeList2);
        cout << "������ 2: ";
        lab_List_2.printList();

        cout << "\n������ 2 ����� �������� ������: ";
        lab_List_2.deleteTail();
        lab_List_2.printList();

        cout << endl << endl;

        cout <<"Min element: " << lab_List_2.min() << endl;
        cout <<"Max element: " << lab_List_2.max() << endl;

        /* ������ 3 */
        cout << "������� ����������� ������ 3: ";
        int sizeList3;
        cin >> sizeList3;

        List lab_List_3;

        lab_List_3.inputList(sizeList3);
        cout << "������ 3: ";
        lab_List_3.printList();

        List lab = lab_List_2 + lab_List_3;

        cout << "����� ������ 2 � 3: " << lab  <<endl;

        cout << endl << endl << endl;

        cout << "\n������ 3 ����� �������� ������: ";
        lab_List_3.deleteTail();
        lab_List_3.printList();

        cout << "\n������� ����� ������ ������ 3: ";
        int newHeadList3;
        cin >> newHeadList3;

        cout << "������ 3 ����� ���������� �������� � ������: ";
        lab_List_3.addToHead(newHeadList3);
        lab_List_3.printList();
        
        cout << "\n������� �������, ������� �������� � ������ 3 ���������� ���������: ";
        int necessaryElement;
        cin >> necessaryElement;

        if (lab_List_3.searchKeyElement(necessaryElement) != nullptr )
        {
            cout << "������� " << necessaryElement << " ������������ � ������!";
        }

        else
        {
            cout << "������� " << necessaryElement << " ����������� � ������!";
        }

        cout << "\n�������� ������ 3 �� �������:\n";

        if (lab_List_3.isEmpty())
        {
            cout << "������ 3 ����!\n";
        }

        else
        {
            cout << "������ 3 �� ����!\n";
        }

        cout << "��������� ������ 2 � ������ 3:\n";

        //if (lab_List_2 == lab_List_3)
        //{
        //    cout << "������ �����!\n";
        //}

        //else
        //{
        //    cout << "������ �� �����!\n";
        //}
    }
    catch (Errors_and_Exceptions SomethingWentWrong)
    {
        return SomethingWentWrong;
    }

    cout << endl;
    system("pause");
}
