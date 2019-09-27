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
    char *name;// ? ������ ��������� ���
    int no;// ? ����������� � ������
    virtual int classType() = 0;
    virtual char *className() = 0;
    virtual void printOn(ostream &) = 0; //������� ������ ������� ������
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

class Kaf: public AbstrKaf { // ����� ������
public:
// �������� ������
    char *KafNumber;// ���������� ����� �������
    int GroupCount;// ����� ����� �� �������
    int StudentCount;// ����� ��������� �� �������
    int KafBorn ;// ��� ��������� �������
    FacType TypeFac;// ��� �������
    char *KafHead;//���������� ��������

// ������������:
    Kaf();
    Kaf( Kaf & K);
    Kaf( Kaf *pK);
    Kaf(const char* KafName, const char* KafNum);
    Kaf(FacType Type, const char* KafName, const char* KafNum, int Group, int Student, int Year, const char* Head);// ����������� �� ����� �����������

    ~Kaf();// ����������

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
	};// �������� ������������ ��� ��������� ���������� "+"

    friend Kaf & operator +(Kaf & K1 , Kaf & K2);// ������������� ������� ��� ���������� ������� ������
// ����������� ������:
    virtual int classType() {
        return KafClass;
    }
    virtual char *className() {
        return "Kaf";
    }
    virtual void printOn(ostream & out);
    virtual void printOn1(ostream & out);

    void setName(const char *KafName , const char *KafNum=NULL);//��������� �����
    const char* getName() {
        return (const char *)name;
    };//��������� �����
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
// �������� �����������
    char *FacName;// �������� ����������
    int KafCount;// ����� ������ �� ����������
    int StudentFacCount;// ����� ��������� �� ����������
    int FacBorn ;// ��� ��������� ����������
    char *Dekan;// �����
    Fac();
    Fac( Fac & F);
    Fac(const char* FacName, const char * Dekan = "");
	//Fac(const char* FacName, int Year, char* Dekan);
    Fac(const char* FacName, int Kaf, int Student, int Year, char* Dekan);

    ~Fac() {}; //����������

    Fac operator =(Fac & F);// ���������� ������������
// ����������� ������:
    virtual int classType() {
        return FacClass;
    };
    virtual char *className() {
        return "Fac";
    };
    virtual void printOn(ostream & out);
	virtual void printOn1(ostream & out);
// ������ ������ ��������� Fac:
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
// ������������� �������
    friend Fac & operator +( Fac & X , Fac & Y );//���������� �������� ���� ���-��
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

Kaf::Kaf( Kaf & K): AbstrKaf() {//����������� �����������
    no = 0;
	name = copyChar(K.getName());
	KafNumber = copyChar(K.KafNumber);
    GroupCount = K.GroupCount;
    StudentCount = K.StudentCount;
    KafBorn = K.KafBorn;
	KafHead = copyChar(K.KafHead);
    TypeFac  = K.TypeFac;
};


Kaf::Kaf(const char* KafName, const char* KafNum) { //� ����� ���-���
	name = copyChar(KafName);
	KafNumber = copyChar(KafNum);
    GroupCount = NULL;
    StudentCount = NULL;
    KafBorn = NULL;
    KafHead = NULL;
};


Kaf::Kaf(FacType Type, const char* KafName, const char* KafNum,int Group, int Student, int Year, const char* Head) { //����������� �� ����� ���-���
// ���
	name = copyChar(KafName);
// �����
    KafNumber = copyChar(KafNum);
//KafNumb;
    GroupCount  = Group;
    StudentCount = Student;
    KafBorn = Year;
    KafHead = copyChar(Head);
    TypeFac  = Type;
};
void Kaf ::printOn1(ostream & out){
	out << endl << "������� - " << showOrDefault(name, "�� �������") << endl;
	out << "����� ������� - " << showOrDefault(KafNumber, "�� ������") << endl;
}
void Kaf::printOn(ostream & out){
    out << endl << "������� - " << showOrDefault(name, "�� ������") << endl;
    out << "����� ������� - " << showOrDefault(KafNumber, "�� ������") << endl;

	if (TypeFac == IU)
        out << "��������� - �������������� ���������� ";
    if (TypeFac == CM)
        out << "��������� - ����.�������������� ";

    out << endl << "����� �� ������� - " << GroupCount << endl << "��������� �� ������� - " << StudentCount << endl << "��� ��������� ������� - " << KafBorn << endl;
    out << "���������� ������� - " << showOrDefault(KafHead,"������� �.�.") << endl << endl;
};
void Kaf::setName(const char *KafName , const char *KafNum) {
// ��� �� �������� ������ - ������ ��� ������
    if ( name != NULL)
        delete []name;
	name = copyChar(KafName);
// ��� �������
    if ( KafNumber != NULL)
        delete []KafNumber;
	KafNumber = copyChar(KafNum);
};


void Kaf::setAllParam(const char *KafName , const char *KafNum, int Group ,int Student ,int Year , char* Head, FacType Type) {
// ��� �� �������� ������ - ������ ��� ������
    if ( name != NULL)
        delete []name;
	name = copyChar(KafName);
// ��� �� �������� ������ - ������ ��� ������
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
    Kaf *pTemp = new Kaf; // ����� ������ ��� ��������
//
    pTemp->no = K1.no;
    pTemp->name = new char[strlen(K1.name) + strlen(K2.name)+ 5 ]; // ����� �������!
    pTemp->name[0]='\0';
    if (K1.name != NULL)
        strcpy_s(pTemp->name, strlen(K1.name) + 1 , K1.name);
    if (K2.name != NULL)
    {
        strcat_s(pTemp->name, strlen(K1.name) + strlen(K2.name)+ 5 ," + ");
        strcat_s(pTemp->name, strlen(K1.name) + strlen(K2.name)+ 5 ,K2.name);
    };

// ��� = ����� ���� KafNumber
    pTemp->KafNumber = new char[strlen(K1.KafNumber) + strlen(K2.KafNumber)+ 5];
    pTemp->KafNumber[0]='\0';
    if (K1.KafNumber != NULL)
        strcpy_s(pTemp->KafNumber, strlen( K1.KafNumber ) + 1 , K1.KafNumber);
    if (K2.KafNumber != NULL)
    {
        strcat_s(pTemp->KafNumber,strlen(K1.KafNumber) + strlen(K2.KafNumber)+ 5 ,"+");
        strcat_s(pTemp->KafNumber,strlen(K1.KafNumber) + strlen(K2.KafNumber)+ 5 ,K2.KafNumber);
    };
// ���������
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
// ��� ��� ������
	name = copyChar(F.name);
// ��� ���-��
	FacName = copyChar(F.FacName);
	Dekan = copyChar(F.Dekan);
//
    no = F.no;
    KafCount = F.KafCount;
    StudentFacCount = F.StudentFacCount;
    FacBorn = F.FacBorn;
// ���� ������������ ������ ���-����
    int nRazm = 0;
    nRazm = (int ) F.GetCount() ;
    for ( int i = 0 ; i < nRazm ; i++)
    {
        Add( ((Kaf * ) F.GetAt(i)));
    };
};

void Fac::printOn1(ostream & out){
	out << "��������� - " << showOrDefault(FacName, "�� ������") << endl;
    out << "����� ������ �� ����������  = " << GetCount() << endl;
    out << "����� ��������� �� ���������� = " << GetCount() << endl;
	 int nRazm = GetCount();
    for ( int i = 0 ;  i < nRazm ; i++)
    {
        ((Kaf * ) GetAt(i))->printOn1(cout);
    }
}

void Fac::printOn(ostream & out){
    out<<endl;
	out << "��������� - " << showOrDefault(FacName, "�� ������") << endl;
    out << "����� ������ �� ����������  = " << GetCount() << endl;
    out << "����� ��������� �� ���������� = " << GetCount() << endl;
    out << "��� ��������� ���������� - " << FacBorn << endl;
    out << "����� ���������� - " << showOrDefault(Dekan," ������� �.�.") << endl;
    //out<<"�������� ������:"<<endl;
    int nRazm = GetCount();
    for ( int i = 0 ;  i < nRazm ; i++)
    {
        ((Kaf * ) GetAt(i))->printOn(cout);
    }
}


Fac Fac::operator = (Fac & F) {
	// ��� ��� ������
	name = copyChar(F.name);
// ��� ���-��
	FacName = copyChar(F.FacName);
	Dekan = copyChar(F.Dekan);
//
    no = F.no;
    KafCount = F.KafCount;
    StudentFacCount = F.StudentFacCount;
    FacBorn = F.FacBorn;
// ���� ������������ ������ ���-����
    int nRazm = 0;
    nRazm = (int ) F.GetCount() ;
    for ( int i = 0 ; i < nRazm ; i++)
    {
        Add( ((Kaf * ) F.GetAt(i)));
    };
	return *this;
};

void Fac::add(Kaf *pK , TypeAddDel t , int Numb , TypeAddDel tcr ) {

    if ( t == tail)	Add((CObject *) pK); // � �����
    if ( t == head) InsertAt(0,(CObject *) pK); // � ������
    if ( t == Number) InsertAt(Numb,(CObject *) pK); // �� ������
// ���������� ����� ������
    KafCount =  (int) GetCount() ;
};

void Fac::del( TypeAddDel t , int Numb) {
    if ( t == tail) RemoveAt(GetCount() - 1); // �� ������
    if ( t == head) RemoveAt(0); // �� ������
    if ( t == Number) RemoveAt(Numb); // �� ������
// ���������� ����� ������
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
// ��������� Fac
    pTemp->KafCount = NULL;
    pTemp->StudentFacCount = NULL;
// ������
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
// ���� ��������
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
