/ Ber.cpp: ���������� ����� ����� ��� ����������� ����������.
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
        cout << endl << "���� ��������� ������� ������� ������� ������ � �����������: ";

// ����� ����
        cout << endl << "1.  �� - 5.1.1  �������� ������ " <<  endl;
        cout <<  "2.  �� - 5.1.2  �������� �������� ��� ������ " <<  endl;
		cout <<  "4.  �� - 5.1.3  ���� ������� ������(��. ��) " <<  endl;
        cout <<  "5.  �� - 5.1.4 ���������� ���������� ������ " <<  endl;
        cout <<  "6.  �� - 5.1.5 ���� ������� �����������(��.��) " <<  endl;
        cout <<  "7.  �� - 5.1.6 ��������� ���������� ���������� " <<  endl;
        cout <<  "8.  �� - 5.1.7 �������� ���� ������ " <<  endl;
        cout <<  "9.  �� - 5.1.8 �������� ���� ����������� " <<  endl;
        cout <<  "10. �� - 5.1.9 ���������� ������� � ��������� " <<  endl;
        cout <<  "11. �� - 5.1.10 �������� ������� � ���������� " <<  endl;
        cout << endl << "0.����� " <<  endl;

        cin >> iPunkt;
        cout << "����� : " << iPunkt<< endl;
        switch(iPunkt) {
        case 1:
            cout << "�� - 5.1.1  �������� ������ " <<  endl;
            {
                Kaf K1("������� ���������� ������������ ����������", "��-2");
                Kaf K2("������������������ ������� ��������� ���������� � ����������", "��-5");
                Kaf K3("����������� ����������� ��� � �������������� ����������", "��-7");
				K1.printOn1(cout);
				K2.printOn1(cout);
				K3.printOn1(cout);
				
                Kaf K4("��������������� �������", "��-2");
                Kaf K5("���������� �������������� � ����������� �������", "��-5");
                Kaf K6("���������� �������-������������ ��������������", "��-12");
				K4.printOn1(cout);
				K5.printOn1(cout);
				K6.printOn1(cout);
            }
            break;
        case 2:
            cout << "�� - 5.1.2 �������� �������� ��� ������ " << endl;
            {
                Kaf K2("��������������� �������", "��-2");
                Kaf K3(CM,"��������������� �������", "��-2", 3, 52, 1960, " ������ �.�.");
                Kaf K4("������������������ ������� ��������� ���������� � ����������", "��-5");
                Kaf K5(IU,"������������������ ������� ��������� ���������� � ����������", "��-5", 4, 108, 1936, "���������� �.�.");
                K2.printOn1(cout);
                K3.printOn(cout);
                K4.printOn1(cout);
                K5.printOn(cout);
            }
            break;
        case 3:
            cout << "�� - 5.1.3 ���� ������� ������(��. ��) " <<  endl;
            {
                Kaf K3(CM,"��������������� �������", "��-2", 3, 52, 1960, " ������ �.�.");
                K3.printOn(cout);
                Kaf K5(IU,"������������������ ������� ��������� ���������� � ����������", "��-5", 4, 108, 1936, "���������� �.�.");
                K5.printOn(cout);
                system("pause");
            }
            break;
        case 4:
            cout << "�� - 5.1.4 ���������� ���������� ������ " <<  endl;
            {
                Kaf K1(IU,"������� ���������� ������������ ����������", "��-2", 4, 102, 1930, "��������� �. �.");
                K1.printOn(cout);
                Kaf K2(IU,"������������������ ������� ��������� ���������� � ����������", "��-5", 4, 108, 1936, "���������� �.�.");
                K2.printOn(cout);
                Kaf K3(IU,"����������� ����������� ��� � �������������� ����������", "��-7", 2, 48, 1989, "������� �.�.");
                K3.printOn(cout);
                Kaf K4(CM,"��������������� �������", "��-2", 3, 52, 1960, " ������ �.�.");
                K4.printOn(cout);
                Kaf K5(CM,"���������� �������������� � ����������� �������", "��-5", 2, 40, 1985, "������ �.�.");
                K5.printOn(cout);
                Kaf K6(CM,"���������� �������-������������ ��������������", "��-12", 2, 37, 1970, "������� �.�.");
                K6.printOn(cout);
            }
            break;
        case 5:
            cout << "�� - 5.1.5 ���� ������� ����������(��. ��) " << endl;
            {
                Kaf K1(IU,"������� ���������� ������������ ����������", "��-2", 4, 102, 1930, "��������� �. �.");
                Kaf K4(CM,"��������������� �������", "��-2", 3, 52, 1960, " ������ �.�.");
                Fac F1Fac("�������������� ���������e", "������������ �.�.");
				F1Fac.FacBorn = 1832;
                F1Fac.add(&K1);
			    cout << "��������� - " << F1Fac.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F1Fac.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F1Fac.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F1Fac.FacBorn << endl;
				cout << "����� - " << F1Fac.GetNameDekan() << endl << endl;
                Fac F2Fac("����.��������������", "������� �.�.");
				F2Fac.FacBorn = 1830;
                F2Fac.add(&K4);
				cout << "��������� - " << F2Fac.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F2Fac.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F2Fac.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F2Fac.FacBorn << endl;
				cout << "����� - " << F2Fac.GetNameDekan() << endl << endl;
            }
            break;
        case 6:
            cout << "�� - 5.1.6 ��������� ���������� ���������� " << endl;
			{
				Kaf K1(IU,"������� ���������� ������������ ����������", "��-2", 4, 102, 1930, "��������� �. �.");
                Kaf K2(IU,"������������������ ������� ��������� ���������� � ����������", "��-5", 4, 108, 1936, "���������� �.�.");
				Kaf K3(IU,"����������� ����������� ��� � �������������� ����������", "��-7", 2, 48, 1989, "������� �.�.");
                Kaf K4(CM,"��������������� �������", "��-2", 3, 52, 1960, " ������ �.�.");
                Kaf K5(CM,"���������� �������������� � ����������� �������", "��-5", 2, 40, 1985, "������ �.�.");
                Kaf K6(CM,"���������� �������-������������ ��������������", "��-12", 2, 37, 1970, "������� �.�.");
                Fac FFFac("�������������� ���������� ", "������������ �.�.");
				Fac FFFac1("����.�������������� ", "������� �.�.");
				FFFac.FacBorn = 1832;
				FFFac1.FacBorn = 1830;
				FFFac.add(&K1);
                FFFac.add(&K2);
				FFFac.add(&K3);
				FFFac1.add(&K4);
				FFFac1.add(&K5);
				FFFac1.add(&K6);
				cout << "��������� - " << FFFac.GetNameFac() << endl;
                cout << "����� ������ �� ���������� = " << FFFac.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << FFFac.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << FFFac.FacBorn << endl;
			    cout << "����� - " << FFFac.GetNameDekan() << endl;
				K1.printOn(cout);
				K2.printOn(cout);
				K3.printOn(cout);
				cout << "��������� - " << FFFac1.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << FFFac1.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << FFFac1.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << FFFac1.FacBorn << endl;
				cout << "����� - " << FFFac1.GetNameDekan() << endl << endl;
				K4.printOn(cout);
				K5.printOn(cout);
				K6.printOn(cout);
            }
            break;
       case 7:
            cout << "�� - 5.1.7 �������� ���� ������ " << endl;
            {
                Kaf K1(IU,"������������������ ������� ��������� ���������� � ����������", "��-5", 4, 108, 1936, "���������� �.�.");
                Kaf K2(IU,"����������� ����������� ��� � �������������� ����������", "��-7", 2, 48, 1989, "������� �.�.");
                Kaf Temp;
                Temp = K1 + K2;
				Temp.KafBorn = 2015;
                K1.printOn(cout);
                K2.printOn(cout);
                Temp.printOn(cout);
            }
            break;
            case 8:
            cout << "�� - 5.1.8 �������� ���� ����������� " << endl;
            {
                Kaf K2(IU,"������������������ ������� ��������� ���������� � ����������", "901432", 4, 108, 1936, "���������� �.�.");
                Fac F1("�������������� ����������", "������������ �.�.");
				F1.FacBorn = 1832;
                F1.add(&K2, head);
				cout << "��������� - " << F1.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F1.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F1.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F1.FacBorn << endl;
				cout << "����� - " << F1.GetNameDekan() << endl;
                K2.printOn(cout);
                Kaf K4(CM,"��������������� �������", "160400", 3, 52, 1960, " ������ �.�.");
                Fac F2("����.��������������", "������� �.�.");
				F2.FacBorn = 1830;
                F2.add(&K4, tail);
				cout << endl << "��������� - " << F2.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F2.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F2.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F2.FacBorn << endl;
				cout << "����� - " << F2.GetNameDekan() << endl;
                K4.printOn(cout);

                cout << endl << "******* �������� *********" << endl;
                Fac SumFac(" ");
                SumFac = F1 + F2;
				SumFac.FacBorn = 2015;
				cout << "�������� ���������� - " << SumFac.GetNameFac() << endl;
                cout << "����� ������ �� ���������� = " << SumFac.GetNumberKaf() << endl;
                cout << "����� ��������� �� ���������� = " << SumFac.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << SumFac.FacBorn << endl;
				cout << "����� - " << showOrDefault(SumFac.Dekan, "������� �.�.") << endl;
				K2.printOn(cout);
				K4.printOn(cout);
				}
            break;
        case 9:
            cout << "�� - 5.1.9 ���������� ������� �� ��������� " << endl;
            {
                Kaf K2(IU,"������� ��������������� ����������", "��-1", 4, 104, 1948, "������ �.�.");
                Fac F1("�������������� ����������", "������������ �.�.");
				F1.FacBorn = 1832;
				cout << "��������� - " << F1.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F1.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F1.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F1.FacBorn << endl;
				cout << "����� - " << F1.GetNameDekan() << endl << endl;
				cout << "������� ������� ��-1" << endl << endl;
                F1.add(&K2);
				cout << "��������� - " << F1.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F1.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F1.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F1.FacBorn << endl;
				cout << "����� - " << F1.GetNameDekan() << endl << endl;
                K2.printOn(cout);
            }
            break;
        case 10:
            cout << "�� - 5.1.10 �������� ������� � ���������� " << endl;
            {
                Kaf K1(IU,"������� ���������� ������������ ����������", "��-2", 4, 102, 1930, "��������� �. �.");
				Kaf K2(IU,"������������������ ������� ��������� ���������� � ����������", "��-5", 4, 108, 1936, "���������� �.�.");
                Fac F1("�������������� ����������", "������������ �.�.");
				F1.FacBorn = 1832;
				F1.add(&K1);
				F1.add(&K2);
				cout << "��������� - " << F1.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F1.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F1.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F1.FacBorn << endl;
				cout << "����� - " << F1.GetNameDekan() << endl << endl;
				K1.printOn(cout);
				K2.printOn(cout);
				cout << "������ ������� ��-2" << endl << endl;
                F1.del(head);
				cout << "��������� - " << F1.GetNameFac() << endl;
                cout << "����� ������ �� ����������� = " << F1.GetNumberKaf()<< endl;
                cout << "����� ��������� �� ���������� = " << F1.GetNumberStudent() << endl;
				cout << "��� ��������� ���������� - " << F1.FacBorn << endl;
				cout << "����� - " << F1.GetNameDekan() << endl;
				K2.printOn(cout);
            }
            break;
        case 0:

            cout << endl << "����� " <<  endl;
            system(" PAUSE");

            return 0;
        default:
            cout << endl << "����� ������� �� �����! " <<  endl;
            break;
/// ���  ������
            cout << endl << "����� " <<  endl;
            system(" PAUSE");
            return 0;
        }
        system(" PAUSE");
    };

///
    system(" PAUSE");
    return 0;
}