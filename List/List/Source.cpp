
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <locale>
#include "Node.h"
#include "List.h"

using namespace std;

/* Обработка исключений */
enum Errors_and_Exceptions
{
    /* Для List */
    errorArraySizeLessZero,
    errorArrayAdressNotPassed,
    errorNumberOfListElementsWasPassedIncorrectly,
    errorElementIndexWasPassedIncorrectly,
};

//
//+ конструкторы (по умолчанию, с параметрами, конструктор из массива int, конструктор копирования);
//+деструктор;
//+ввод / вывод в консоль(потоковый);
//+поиск элемента по ключу(возвращает указатель на элемент или nullptr, если элемента нет в списке);
//+добавление элемента(в голову, хвост, на позицию, после ключа(после первого вхождения);
//+удаление элемента(из головы, хвоста, позиции, по ключу(первое вхождение);
//+поиск максимального / минимального элемента;
//+isEmpty() - возвращает true, если список пуст;
//+очистка списка;
//-сортировка списка;
//Необходимые перегрузки :
//+присваивание(= );
//+получение ссылки на ключ элемента([]);
//+сравнение(== , != );
//+сложение списков(+).



int main()
{
    try
    {
        setlocale(LC_ALL, "Rus");
        srand(unsigned(time(NULL)));
    
       
        cout << "Задайте размерность списка 0: ";
        int sizeList0;
        cin >> sizeList0;
        List lab_List_0;
        lab_List_0.inputList(sizeList0);
       
        cout << "[0]" <<" - " << lab_List_0[0] << endl;
        cout << "[2]" <<" - " << lab_List_0[2] << endl;
        cout << "[5]" <<" - " << lab_List_0[5] << endl;

        lab_List_0.clearList();

        /* Список 1*/
        cout << "Задайте голову списка 1: ";
        int newHeadList1;
        cin >> newHeadList1;

        cout << "Список 1: ";
        List lab_List_1;

        lab_List_1.addToHead(newHeadList1);
        lab_List_1.printList();

        cout << endl << endl;

        /* Список 2 */
        cout << "Задайте размерность списка 2: ";
        int sizeList2;
        cin >> sizeList2;

        List lab_List_2;

        lab_List_2.inputList(sizeList2);
        cout << "Список 2: ";
        lab_List_2.printList();

        cout << "\nСписок 2 после удаления хвоста: ";
        lab_List_2.deleteTail();
        lab_List_2.printList();

        cout << endl << endl;

        cout <<"Min element: " << lab_List_2.min() << endl;
        cout <<"Max element: " << lab_List_2.max() << endl;

        /* Список 3 */
        cout << "Задайте размерность списка 3: ";
        int sizeList3;
        cin >> sizeList3;

        List lab_List_3;

        lab_List_3.inputList(sizeList3);
        cout << "Список 3: ";
        lab_List_3.printList();

        List lab = lab_List_2 + lab_List_3;

        cout << "Сумма списка 2 и 3: " << lab  <<endl;

        cout << endl << endl << endl;

        cout << "\nСписок 3 после удаления хвоста: ";
        lab_List_3.deleteTail();
        lab_List_3.printList();

        cout << "\nЗадайте новую голову списка 3: ";
        int newHeadList3;
        cin >> newHeadList3;

        cout << "Список 3 после добавления элемента в голову: ";
        lab_List_3.addToHead(newHeadList3);
        lab_List_3.printList();
        
        cout << "\nВведите элемент, наличие которого в списке 3 необходимо проверить: ";
        int necessaryElement;
        cin >> necessaryElement;

        if (lab_List_3.searchKeyElement(necessaryElement) != nullptr )
        {
            cout << "Элемент " << necessaryElement << " присутствует в списке!";
        }

        else
        {
            cout << "Элемент " << necessaryElement << " отсутствует в списке!";
        }

        cout << "\nПроверка списка 3 на пустоту:\n";

        if (lab_List_3.isEmpty())
        {
            cout << "Список 3 пуст!\n";
        }

        else
        {
            cout << "Список 3 не пуст!\n";
        }

        cout << "Сравнение списка 2 и списка 3:\n";

        //if (lab_List_2 == lab_List_3)
        //{
        //    cout << "Списки равны!\n";
        //}

        //else
        //{
        //    cout << "Списки не равны!\n";
        //}
    }
    catch (Errors_and_Exceptions SomethingWentWrong)
    {
        return SomethingWentWrong;
    }

    cout << endl;
    system("pause");
}
