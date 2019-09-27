#include "resource.h"
#define KafClass     1
#define FacClass     2
#pragma once
#include <iostream>

using namespace std;

char *copyChar(const char *str) {
	if(str == NULL) return NULL;
	char *newstr = new char[strlen(str) + 2];
	strcpy_s(newstr, strlen(str) + 1, str);
	return newstr;
}

const char *showOrDefault(const char *str, const char *def = "") {
	if(str == NULL || strlen(str) == 0) {
		return def;
	}
	return str;
}


enum FacType {IU, CM};

enum TypeAddDel {tail, head, Number ,NumbAfter, NumbCurrent, NumbBefore,
                 AssbAfter, AssCurrent, AssBefore , createObj , nocreateObj , deleteObj, nodeleteObj
                };

class AbstrKaf: public CObject {
public:
    char *name;// ? Резерв Поисковое имя
    int no;// ? РезервНомер в списке
    virtual int classType() = 0;
    virtual char *className() = 0;
    virtual void printOn(ostream &) = 0; //функция печати свойств кафедр
    AbstrKaf() {
        name = (char *)NULL;
        no = NULL;
    };
    AbstrKaf(AbstrKaf &obj) {
    }
    ~AbstrKaf() {
        if( name != (char *)NULL)
            delete [] name;
    };
};

class AbstrFac {
public:
    char* name;
	char* nameD;
    int no;
    virtual int classType() = 0;
    virtual char *className() = 0;
    virtual void printOn(ostream &) = 0;
    AbstrFac() {
        name = (char *)NULL;
		nameD = (char*)NULL;
        no = NULL;
    };
    ~AbstrFac() {
        if( name != (char *)NULL)
            delete [] name;
	    if( nameD != (char *)NULL)
            delete [] nameD;
    };
};

class Kaf: public AbstrKaf { // Класс кафедр
public:
// Свойства кафедр
    char *KafNumber;// Символьный номер кафедры
    int GroupCount;// Число групп на кафедре
    int StudentCount;// Число студентов на кафедре
    int KafBorn ;// Год основания кафедры
    FacType TypeFac;// Тип кафедры
    char *KafHead;//Заведующий кафедрой

// Конструкторы:
    Kaf();
    Kaf( Kaf & K);
    Kaf( Kaf *pK);
    Kaf(const char* KafName, const char* KafNum);
    Kaf(FacType Type, const char* KafName, const char* KafNum, int Group, int Student, int Year, const char* Head);// конструктор со всеми параметрами

    ~Kaf();// Деструктор

	Kaf& operator =(Kaf & K) {
		no = 0;
		name = copyChar(K.getName());
		KafNumber = copyChar(K.KafNumber);
		GroupCount = K.GroupCount;
		StudentCount = K.StudentCount;
		KafBorn = K.KafBorn;
		KafHead = copyChar(K.KafHead);
		TypeFac  = K.TypeFac;
		return *this;
	};// Оператор присваивания для поддержки перегрузки "+"

    friend Kaf & operator +(Kaf & K1 , Kaf & K2);// Дружественная функция для перегрузки слияния кафедр
// Виртуальные методы:
    virtual int classType() {
        return KafClass;
    }
    virtual char *className() {
        return "Kaf";
    }
    virtual void printOn(ostream & out);
    virtual void printOn1(ostream & out);

    void setName(const char *KafName , const char *KafNum=NULL);//установка имени
    const char* getName() {
        return (const char *)name;
    };//получение имени
    int getNo() {
        return no;
    };
    void setParam(int Group, int Student, int Year, FacType & Type) {
        GroupCount = Group;
        StudentCount = Student, KafBorn = Year, TypeFac = Type;
    };
    void getParam(int & Group ,int & Student ,int & Year, FacType & Type) {
        Group = GroupCount;
        Student = StudentCount;
        Year = KafBorn;
    };
    void setAllParam(const char *KafName , const char *KafNum, int Group, int Student, int Year, char* Head, FacType Type);
};

class Fac: public AbstrFac, public CObArray {
public:
// Свойства факультетов
    char *FacName;// Название факультета
    int KafCount;// Число кафедр на факультете
    int StudentFacCount;// Число студентов на факультете
    int FacBorn ;// Год основания факультета
    char *Dekan;// Декан
    Fac();
    Fac( Fac & F);
    Fac(const char* FacName, const char * Dekan = "");
	//Fac(const char* FacName, int Year, char* Dekan);
    Fac(const char* FacName, int Kaf, int Student, int Year, char* Dekan);

    ~Fac() {}; //Деструктор

    Fac operator =(Fac & F);// Перегрузка присваивания
// Виртуальные методы:
    virtual int classType() {
        return FacClass;
    };
    virtual char *className() {
        return "Fac";
    };
    virtual void printOn(ostream & out);
	virtual void printOn1(ostream & out);
// Методы класса факультет Fac:
    int GetNumberStudent();
    int GetNumberKaf() {
		return (int) GetCount();};

    void add(Kaf *pK, TypeAddDel = tail , int Numb = 1 , TypeAddDel = createObj);
    void del( TypeAddDel = tail , int Numb = 1);
   void SetNameFac(const char * NameFac);
    char * GetNameFac() {
       return FacName;
    };
	void SetNameDekan(const char* NameDekan);
	char* GetNameDekan(){
		return Dekan;
	};
// Дружественные функции
    friend Fac & operator +( Fac & X , Fac & Y );//перегрузка сложения двух фак-ов
};


class Kaf;
Kaf::Kaf(): AbstrKaf() {
    KafNumber = NULL;
    GroupCount = NULL;
    StudentCount = NULL;
    KafBorn = NULL;
    KafHead = NULL;
};

Kaf::~Kaf( )
{
    if ( KafNumber != NULL) delete []KafNumber;
	if ( KafHead != NULL) delete []KafHead;
};

Kaf::Kaf( Kaf & K): AbstrKaf() {//Конструктор копирования
    no = 0;
	name = copyChar(K.getName());
	KafNumber = copyChar(K.KafNumber);
    GroupCount = K.GroupCount;
    StudentCount = K.StudentCount;
    KafBorn = K.KafBorn;
	KafHead = copyChar(K.KafHead);
    TypeFac  = K.TypeFac;
};


Kaf::Kaf(const char* KafName, const char* KafNum) { //С двумя пар-ами
	name = copyChar(KafName);
	KafNumber = copyChar(KafNum);
    GroupCount = NULL;
    StudentCount = NULL;
    KafBorn = NULL;
    KafHead = NULL;
};


Kaf::Kaf(FacType Type, const char* KafName, const char* KafNum,int Group, int Student, int Year, const char* Head) { //Конструктор со всеми пар-ами
// Имя
	name = copyChar(KafName);
// Номер
    KafNumber = copyChar(KafNum);
//KafNumb;
    GroupCount  = Group;
    StudentCount = Student;
    KafBorn = Year;
    KafHead = copyChar(Head);
    TypeFac  = Type;
};
void Kaf ::printOn1(ostream & out){
	out << endl << "Кафедра - " << showOrDefault(name, "не указана") << endl;
	out << "Номер кафедры - " << showOrDefault(KafNumber, "не указан") << endl;
}
void Kaf::printOn(ostream & out){
    out << endl << "Кафедра - " << showOrDefault(name, "не задано") << endl;
    out << "Номер кафедры - " << showOrDefault(KafNumber, "не задано") << endl;

	if (TypeFac == IU)
        out << "Факультет - Информационное управление ";
    if (TypeFac == CM)
        out << "Факультет - Спец.Машиностроение ";

    out << endl << "Групп на кафедре - " << GroupCount << endl << "Студентов на кафедре - " << StudentCount << endl << "Год основания кафедры - " << KafBorn << endl;
    out << "Заведующий кафедры - " << showOrDefault(KafHead,"Березин И.С.") << endl << endl;
};
void Kaf::setName(const char *KafName , const char *KafNum) {
// Имя из базового класса - резерв для приска
    if ( name != NULL)
        delete []name;
	name = copyChar(KafName);
// Имя кафедры
    if ( KafNumber != NULL)
        delete []KafNumber;
	KafNumber = copyChar(KafNum);
};


void Kaf::setAllParam(const char *KafName , const char *KafNum, int Group ,int Student ,int Year , char* Head, FacType Type) {
// Имя из базового класса - резерв для приска
    if ( name != NULL)
        delete []name;
	name = copyChar(KafName);
// Имя из базового класса - резерв для приска
    if ( KafNumber != NULL)
		delete []KafNumber;
	KafNumber = copyChar(KafNum);
//
    GroupCount= Group;
    StudentCount= Student;
    TypeFac = Type;
    KafBorn= Year;
    KafHead = copyChar(Head);
};

Kaf & operator +(Kaf & K1 , Kaf & K2) {
    Kaf *pTemp = new Kaf; // новый объект для сложения
//
    pTemp->no = K1.no;
    pTemp->name = new char[strlen(K1.name) + strlen(K2.name)+ 5 ]; // учтем пробелы!
    pTemp->name[0]='\0';
    if (K1.name != NULL)
        strcpy_s(pTemp->name, strlen(K1.name) + 1 , K1.name);
    if (K2.name != NULL)
    {
        strcat_s(pTemp->name, strlen(K1.name) + strlen(K2.name)+ 5 ," + ");
        strcat_s(pTemp->name, strlen(K1.name) + strlen(K2.name)+ 5 ,K2.name);
    };

// Имя = сумма имен KafNumber
    pTemp->KafNumber = new char[strlen(K1.KafNumber) + strlen(K2.KafNumber)+ 5];
    pTemp->KafNumber[0]='\0';
    if (K1.KafNumber != NULL)
        strcpy_s(pTemp->KafNumber, strlen( K1.KafNumber ) + 1 , K1.KafNumber);
    if (K2.KafNumber != NULL)
    {
        strcat_s(pTemp->KafNumber,strlen(K1.KafNumber) + strlen(K2.KafNumber)+ 5 ,"+");
        strcat_s(pTemp->KafNumber,strlen(K1.KafNumber) + strlen(K2.KafNumber)+ 5 ,K2.KafNumber);
    };
// Параметры
    pTemp-> GroupCount = K1.GroupCount + K2.GroupCount;
    pTemp-> StudentCount = K1.StudentCount + K2.StudentCount;
    pTemp-> TypeFac = IU;
    return *pTemp;
};



//****************************
Fac::Fac():AbstrFac() {
    no = NULL;
    name = (char *)NULL;
	nameD = (char*)NULL;
    FacName = (char*)NULL;
    KafCount = NULL;
    StudentFacCount = NULL;
    FacBorn = NULL;
    Dekan = (char*)NULL;
};

Fac::Fac(const char *sName,const char *sNameD):AbstrFac() {
    name = copyChar(sName);
    FacName = copyChar(sName);
	Dekan = copyChar(sNameD);
    no = NULL;
    KafCount = NULL;
    StudentFacCount = NULL;
    FacBorn = NULL;
    nameD = (char *)NULL;
};


Fac::Fac(Fac & F) :AbstrFac() {
// Имя для поиска
	name = copyChar(F.name);
// Имя фак-та
	FacName = copyChar(F.FacName);
	Dekan = copyChar(F.Dekan);
//
    no = F.no;
    KafCount = F.KafCount;
    StudentFacCount = F.StudentFacCount;
    FacBorn = F.FacBorn;
// Цикл формирования нового фак-тета
    int nRazm = 0;
    nRazm = (int ) F.GetCount() ;
    for ( int i = 0 ; i < nRazm ; i++)
    {
        Add( ((Kaf * ) F.GetAt(i)));
    };
};

void Fac::printOn1(ostream & out){
	out << "Факультет - " << showOrDefault(FacName, "не указан") << endl;
    out << "Число кафедр на факультете  = " << GetCount() << endl;
    out << "Число студентов на факультете = " << GetCount() << endl;
	 int nRazm = GetCount();
    for ( int i = 0 ;  i < nRazm ; i++)
    {
        ((Kaf * ) GetAt(i))->printOn1(cout);
    }
}

void Fac::printOn(ostream & out){
    out<<endl;
	out << "Факультет - " << showOrDefault(FacName, "не указан") << endl;
    out << "Число кафедр на факультете  = " << GetCount() << endl;
    out << "Число студентов на факультете = " << GetCount() << endl;
    out << "Год основания факультета - " << FacBorn << endl;
    out << "Декан факультета - " << showOrDefault(Dekan," Березин И.С.") << endl;
    //out<<"Свойства кафедр:"<<endl;
    int nRazm = GetCount();
    for ( int i = 0 ;  i < nRazm ; i++)
    {
        ((Kaf * ) GetAt(i))->printOn(cout);
    }
}


Fac Fac::operator = (Fac & F) {
	// Имя для поиска
	name = copyChar(F.name);
// Имя фак-та
	FacName = copyChar(F.FacName);
	Dekan = copyChar(F.Dekan);
//
    no = F.no;
    KafCount = F.KafCount;
    StudentFacCount = F.StudentFacCount;
    FacBorn = F.FacBorn;
// Цикл формирования нового фак-тета
    int nRazm = 0;
    nRazm = (int ) F.GetCount() ;
    for ( int i = 0 ; i < nRazm ; i++)
    {
        Add( ((Kaf * ) F.GetAt(i)));
    };
	return *this;
};

void Fac::add(Kaf *pK , TypeAddDel t , int Numb , TypeAddDel tcr ) {

    if ( t == tail)	Add((CObject *) pK); // в Хвост
    if ( t == head) InsertAt(0,(CObject *) pK); // в Голову
    if ( t == Number) InsertAt(Numb,(CObject *) pK); // По номеру
// Подсчитать число кафедр
    KafCount =  (int) GetCount() ;
};

void Fac::del( TypeAddDel t , int Numb) {
    if ( t == tail) RemoveAt(GetCount() - 1); // Из головы
    if ( t == head) RemoveAt(0); // Из хвоста
    if ( t == Number) RemoveAt(Numb); // По номеру
// Подсчитать число кафедр
    KafCount =  (int) GetCount() ;
};

Fac & operator +( Fac & X , Fac & Y )
{
    Fac *pTemp = new Fac;
    pTemp->name = new char[strlen(X.name) + strlen(Y.name) + 5 ];
    if (X.name != (char *)NULL )
    {
        strcpy_s(pTemp->name, strlen(X.name) + 1, X.name);
    }
    else
        pTemp->name[0]='\0';
    if (Y.name != (char *)NULL )
    {   strcat_s(pTemp->name, strlen(X.name) + strlen(Y.name) + 5 , " + ");
        strcat_s(pTemp->name, strlen(X.name) + strlen(Y.name) + 5 , Y.name);
    }
// FacName
    pTemp->FacName = new char[strlen(X.FacName) + strlen(Y.FacName) + 5];
    if (X.FacName != (char *)NULL )
    {
        strcpy_s(pTemp->FacName, strlen(X.FacName) + 1 , X.FacName);
    }
    else
        pTemp->FacName[0]='\0';
    if (Y.FacName != (char *)NULL )
    {
        strcat_s(pTemp->FacName,strlen(X.FacName) + strlen(Y.FacName) + 5 ," + ");
        strcat_s(pTemp->FacName,strlen(X.FacName) + strlen(Y.FacName) + 5
                 ,Y.FacName);
    };
// Параметры Fac
    pTemp->KafCount = NULL;
    pTemp->StudentFacCount = NULL;
// Массив
    int nRazm = 0;
    nRazm = (int ) X.GetCount() ;
    for ( int i = 0 ; i < nRazm ; i++)
    {
        pTemp->Add( ((Kaf * ) X.GetAt(i)));
    };
    nRazm = (int ) Y.GetCount() ;
    for ( int i = 0 ; i < nRazm ; i++)
    {
        pTemp->Add( ((Kaf * ) Y.GetAt(i)));
    };
    pTemp->KafCount = (int )(pTemp->GetCount());
    pTemp->StudentFacCount = (int)(pTemp->GetCount());
    return *pTemp;
};

int Fac::GetNumberStudent() {
    int Summ = 0;
// Цикл подсчета
    int nRazm = 0;
    nRazm = (int ) GetCount() ;
    for ( int i = 0 ; i < nRazm ; i++)
    {
        Summ = Summ + ((Kaf *)GetAt( i))->StudentCount ;
    };
    return Summ;
};

void Fac::SetNameFac(const char * NameFac)
{
    if (FacName != (char *) NULL)
        delete []FacName;
    if ( NameFac != (char *) NULL )
    {
        FacName= new char[strlen(NameFac) + 1];
        strcpy_s(FacName , strlen(NameFac) + 1, NameFac);
    }
    else
        FacName = (char *) NULL;
    return;
}

void Fac::SetNameDekan(const char* NameDekan)
{
	  if (Dekan != (char *) NULL)
        delete []Dekan;
    if ( NameDekan != (char *) NULL )
    {
        Dekan= new char[strlen(NameDekan) + 1];
        strcpy_s(Dekan , strlen(NameDekan) + 1, NameDekan);
    }
    else
        Dekan = (char *) NULL;
    return;
}
