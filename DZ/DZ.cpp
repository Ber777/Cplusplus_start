/ Ber.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DZ.h"

#include <iostream>

using namespace std;


int  main(void) {
    int iPunkt;
    system (" chcp 1251>nul ");
    while ( true ) {
        system (" CLS ");
        cout << endl << "Меню тестового примера системы классов кафедр и факультетов: ";

// Новое меню
        cout << endl << "1.  ТЗ - 5.1.1  Создание кафедр " <<  endl;
        cout <<  "2.  ТЗ - 5.1.2  Создание объектов для кафедр " <<  endl;
		cout <<  "4.  ТЗ - 5.1.3  Учет свойств кафедр(см. ТЗ) " <<  endl;
        cout <<  "5.  ТЗ - 5.1.4 Распечатка содержаний кафедр " <<  endl;
        cout <<  "6.  ТЗ - 5.1.5 Учет свойств факультетов(см.ТЗ) " <<  endl;
        cout <<  "7.  ТЗ - 5.1.6 Получение содержания факультета " <<  endl;
        cout <<  "8.  ТЗ - 5.1.7 Сложение двух кафедр " <<  endl;
        cout <<  "9.  ТЗ - 5.1.8 Сложение двух факультетов " <<  endl;
        cout <<  "10. ТЗ - 5.1.9 Добавление кафедры в факультет " <<  endl;
        cout <<  "11. ТЗ - 5.1.10 Удаление кафедры с факультета " <<  endl;
        cout << endl << "0.Выход " <<  endl;

        cin >> iPunkt;
        cout << "Ввели : " << iPunkt<< endl;
        switch(iPunkt) {
        case 1:
            cout << "ТЗ - 5.1.1  Создание кафедр " <<  endl;
            {
                Kaf K1("Системы управления летательными аппаратами", "ИУ-2");
                Kaf K2("Автоматизированные системы обработки информации и управления", "ИУ-5");
                Kaf K3("Программное обеспечение ЭВМ и информационные технологии", "ИУ-7");
				K1.printOn1(cout);
				K2.printOn1(cout);
				K3.printOn1(cout);
				
                Kaf K4("Аэрокосмические системы", "СМ-2");
                Kaf K5("Автономные информационные и управляющие системы", "СМ-5");
                Kaf K6("Технологии ракетно-космического машиностроения", "СМ-12");
				K4.printOn1(cout);
				K5.printOn1(cout);
				K6.printOn1(cout);
            }
            break;
        case 2:
            cout << "ТЗ - 5.1.2 Создание объектов для кафедр " << endl;
            {
                Kaf K2("Аэрокосмические системы", "СМ-2");
                Kaf K3(CM,"Аэрокосмические системы", "СМ-2", 3, 52, 1960, " Леонов А.Г.");
                Kaf K4("Автоматизированные системы обработки информации и управления", "ИУ-5");
                Kaf K5(IU,"Автоматизированные системы обработки информации и управления", "ИУ-5", 4, 108, 1936, "Черненький В.М.");
                K2.printOn1(cout);
                K3.printOn(cout);
                K4.printOn1(cout);
                K5.printOn(cout);
            }
            break;
        case 3:
            cout << "ТЗ - 5.1.3 Учет свойств кафедр(см. ТЗ) " <<  endl;
            {
                Kaf K3(CM,"Аэрокосмические системы", "СМ-2", 3, 52, 1960, " Леонов А.Г.");
                K3.printOn(cout);
                Kaf K5(IU,"Автоматизированные системы обработки информации и управления", "ИУ-5", 4, 108, 1936, "Черненький В.М.");
                K5.printOn(cout);
                system("pause");
            }
            break;
        case 4:
            cout << "ТЗ - 5.1.4 Распечатка содержания кафедр " <<  endl;
            {
                Kaf K1(IU,"Системы управления летательными аппаратами", "ИУ-2", 4, 102, 1930, "Коновалов С. Ф.");
                K1.printOn(cout);
                Kaf K2(IU,"Автоматизированные системы обработки информации и управления", "ИУ-5", 4, 108, 1936, "Черненький В.М.");
                K2.printOn(cout);
                Kaf K3(IU,"Программное обеспечение ЭВМ и информационные технологии", "ИУ-7", 2, 48, 1989, "Рудаков И.В.");
                K3.printOn(cout);
                Kaf K4(CM,"Аэрокосмические системы", "СМ-2", 3, 52, 1960, " Леонов А.Г.");
                K4.printOn(cout);
                Kaf K5(CM,"Автономные информационные и управляющие системы", "СМ-5", 2, 40, 1985, "Борзов А.Б.");
                K5.printOn(cout);
                Kaf K6(CM,"Технологии ракетно-космического машиностроения", "СМ-12", 2, 37, 1970, "Тарасов В.А.");
                K6.printOn(cout);
            }
            break;
        case 5:
            cout << "ТЗ - 5.1.5 Учет свойств факультета(см. ТЗ) " << endl;
            {
                Kaf K1(IU,"Системы управления летательными аппаратами", "ИУ-2", 4, 102, 1930, "Коновалов С. Ф.");
                Kaf K4(CM,"Аэрокосмические системы", "СМ-2", 3, 52, 1960, " Леонов А.Г.");
                Fac F1Fac("Информационное управлениe", "Пролетарский А.В.");
				F1Fac.FacBorn = 1832;
                F1Fac.add(&K1);
			    cout << "Факультет - " << F1Fac.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F1Fac.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F1Fac.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F1Fac.FacBorn << endl;
				cout << "Декан - " << F1Fac.GetNameDekan() << endl << endl;
                Fac F2Fac("Спец.Машиностроение", "Калугин В.Т.");
				F2Fac.FacBorn = 1830;
                F2Fac.add(&K4);
				cout << "Факультет - " << F2Fac.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F2Fac.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F2Fac.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F2Fac.FacBorn << endl;
				cout << "Декан - " << F2Fac.GetNameDekan() << endl << endl;
            }
            break;
        case 6:
            cout << "ТЗ - 5.1.6 Получение содержания факультета " << endl;
			{
				Kaf K1(IU,"Системы управления летательными аппаратами", "ИУ-2", 4, 102, 1930, "Коновалов С. Ф.");
                Kaf K2(IU,"Автоматизированные системы обработки информации и управления", "ИУ-5", 4, 108, 1936, "Черненький В.М.");
				Kaf K3(IU,"Программное обеспечение ЭВМ и информационные технологии", "ИУ-7", 2, 48, 1989, "Рудаков И.В.");
                Kaf K4(CM,"Аэрокосмические системы", "СМ-2", 3, 52, 1960, " Леонов А.Г.");
                Kaf K5(CM,"Автономные информационные и управляющие системы", "СМ-5", 2, 40, 1985, "Борзов А.Б.");
                Kaf K6(CM,"Технологии ракетно-космического машиностроения", "СМ-12", 2, 37, 1970, "Тарасов В.А.");
                Fac FFFac("Информационное управление ", "Пролетарский А.В.");
				Fac FFFac1("Спец.Машиностроение ", "Калугин В.Т.");
				FFFac.FacBorn = 1832;
				FFFac1.FacBorn = 1830;
				FFFac.add(&K1);
                FFFac.add(&K2);
				FFFac.add(&K3);
				FFFac1.add(&K4);
				FFFac1.add(&K5);
				FFFac1.add(&K6);
				cout << "Факультет - " << FFFac.GetNameFac() << endl;
                cout << "Число кафедр на факультете = " << FFFac.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << FFFac.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << FFFac.FacBorn << endl;
			    cout << "Декан - " << FFFac.GetNameDekan() << endl;
				K1.printOn(cout);
				K2.printOn(cout);
				K3.printOn(cout);
				cout << "Факультет - " << FFFac1.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << FFFac1.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << FFFac1.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << FFFac1.FacBorn << endl;
				cout << "Декан - " << FFFac1.GetNameDekan() << endl << endl;
				K4.printOn(cout);
				K5.printOn(cout);
				K6.printOn(cout);
            }
            break;
       case 7:
            cout << "ТЗ - 5.1.7 Сложение двух кафедр " << endl;
            {
                Kaf K1(IU,"Автоматизированные системы обработки информации и управления", "ИУ-5", 4, 108, 1936, "Черненький В.М.");
                Kaf K2(IU,"Программное обеспечение ЭВМ и информационные технологии", "ИУ-7", 2, 48, 1989, "Рудаков И.В.");
                Kaf Temp;
                Temp = K1 + K2;
				Temp.KafBorn = 2015;
                K1.printOn(cout);
                K2.printOn(cout);
                Temp.printOn(cout);
            }
            break;
            case 8:
            cout << "ТЗ - 5.1.8 Сложение двух факультетов " << endl;
            {
                Kaf K2(IU,"Автоматизированные системы обработки информации и управления", "901432", 4, 108, 1936, "Черненький В.М.");
                Fac F1("Информационное управление", "Пролетарский А.В.");
				F1.FacBorn = 1832;
                F1.add(&K2, head);
				cout << "Факультет - " << F1.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F1.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F1.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F1.FacBorn << endl;
				cout << "Декан - " << F1.GetNameDekan() << endl;
                K2.printOn(cout);
                Kaf K4(CM,"Аэрокосмические системы", "160400", 3, 52, 1960, " Леонов А.Г.");
                Fac F2("Спец.Машиностроения", "Калугин В.Т.");
				F2.FacBorn = 1830;
                F2.add(&K4, tail);
				cout << endl << "Факультет - " << F2.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F2.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F2.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F2.FacBorn << endl;
				cout << "Декан - " << F2.GetNameDekan() << endl;
                K4.printOn(cout);

                cout << endl << "******* Сложение *********" << endl;
                Fac SumFac(" ");
                SumFac = F1 + F2;
				SumFac.FacBorn = 2015;
				cout << "Название факультета - " << SumFac.GetNameFac() << endl;
                cout << "Число кафедр на факультете = " << SumFac.GetNumberKaf() << endl;
                cout << "Число студентов на факультете = " << SumFac.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << SumFac.FacBorn << endl;
				cout << "Декан - " << showOrDefault(SumFac.Dekan, "Березин И.С.") << endl;
				K2.printOn(cout);
				K4.printOn(cout);
				}
            break;
        case 9:
            cout << "ТЗ - 5.1.9 Добавление кафедры на факультет " << endl;
            {
                Kaf K2(IU,"Системы автоматического управления", "ИУ-1", 4, 104, 1948, "Микрин Е.А.");
                Fac F1("Информационное управление", "Пролетарский А.В.");
				F1.FacBorn = 1832;
				cout << "Факультет - " << F1.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F1.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F1.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F1.FacBorn << endl;
				cout << "Декан - " << F1.GetNameDekan() << endl << endl;
				cout << "Добавим кафедру ИУ-1" << endl << endl;
                F1.add(&K2);
				cout << "Факультет - " << F1.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F1.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F1.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F1.FacBorn << endl;
				cout << "Декан - " << F1.GetNameDekan() << endl << endl;
                K2.printOn(cout);
            }
            break;
        case 10:
            cout << "ТЗ - 5.1.10 Удаление кафедры с факультета " << endl;
            {
                Kaf K1(IU,"Системы управления летательными аппаратами", "ИУ-2", 4, 102, 1930, "Коновалов С. Ф.");
				Kaf K2(IU,"Автоматизированные системы обработки информации и управления", "ИУ-5", 4, 108, 1936, "Черненький В.М.");
                Fac F1("Информационное управление", "Пролетарский А.В.");
				F1.FacBorn = 1832;
				F1.add(&K1);
				F1.add(&K2);
				cout << "Факультет - " << F1.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F1.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F1.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F1.FacBorn << endl;
				cout << "Декан - " << F1.GetNameDekan() << endl << endl;
				K1.printOn(cout);
				K2.printOn(cout);
				cout << "Удалим кафедру ИУ-2" << endl << endl;
                F1.del(head);
				cout << "Факультет - " << F1.GetNameFac() << endl;
                cout << "Число кафедр на факульетете = " << F1.GetNumberKaf()<< endl;
                cout << "Число студентов на факультете = " << F1.GetNumberStudent() << endl;
				cout << "Год основания факультета - " << F1.FacBorn << endl;
				cout << "Декан - " << F1.GetNameDekan() << endl;
				K2.printOn(cout);
            }
            break;
        case 0:

            cout << endl << "Выход " <<  endl;
            system(" PAUSE");

            return 0;
        default:
            cout << endl << "Выбор функции не верен! " <<  endl;
            break;
/// При  выходе
            cout << endl << "Выход " <<  endl;
            system(" PAUSE");
            return 0;
        }
        system(" PAUSE");
    };

///
    system(" PAUSE");
    return 0;
}