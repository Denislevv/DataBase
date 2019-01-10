#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <clocale>

using namespace std;

struct UNI
{
	string numberst;
	string sername;
	string name;
	string male;

};
UNI *stud, *copstud;
int kolvo=0;

void vivod()
{
	for (int i=0; i<kolvo; i++)
	{
			cout<<"Номер студенческого: "<<stud[i].numberst<<"   "<<"Фамилия: "<<stud[i].sername<<"   "<<"Имя: "<<stud[i].name<<"   "<<"Пол: "<<stud[i].male<<" "<<endl;
	}
}


void dobavit()
{
	for (int i=0; i<kolvo; i++)
	{
		
		copstud[i].numberst=stud[i].numberst;
		copstud[i].sername=stud[i].sername;
		copstud[i].name=stud[i].name;
		copstud[i].male=stud[i].male;
	}
	
	kolvo++;
	stud = new UNI [kolvo];
	
		for(int i=0; i<kolvo-1;i++)
		{
			stud[i].numberst=copstud[i].numberst;
			stud[i].sername=copstud[i].sername;
			stud[i].name=copstud[i].name;
			stud[i].male=copstud[i].male;	
		}
		
	cin>> stud[kolvo-1].numberst>> stud[kolvo-1].sername>> stud[kolvo-1].name>>stud[kolvo-1].male;
	
	copstud= new UNI[kolvo];	 	
}




 void delstd()
 {
 	string namest;
 	cin>> namest;
 	for(int i=0;i<kolvo;i++)
 	{
 		copstud[i].numberst=stud[i].numberst;
		copstud[i].sername=stud[i].sername;
		copstud[i].name=stud[i].name;
		copstud[i].male=stud[i].male;
 	}
 	kolvo--;
 	stud = new UNI [kolvo];
 	
 	int m=0;
 	
 	for (int i=0; i<kolvo+1; i++)
	 {
	 	if (copstud[i].numberst!=namest)
	 	{
	 		stud[m].numberst=copstud[i].numberst;
			stud[m].sername=copstud[i].sername;
			stud[m].name=copstud[i].name;
			stud[m].male=copstud[i].male;
			m++;
	 	}
	 } 
	 
	 copstud=new UNI [kolvo];
	
 }

void sortingminys()
{
	string temp;
	string temp2;
	for (int m=0; m<kolvo; m++)
	{
		for (int i=0; i<kolvo-1; i++)
		{
			if (stud[i].sername<stud[i+1].sername)
			{
				temp=stud[i].sername;
				stud[i].sername=stud[i+1].sername;
				stud[i+1].sername=temp;
				
				temp=stud[i].name;
				stud[i].name=stud[i+1].name;
				stud[i+1].name=temp;
				
				temp=stud[i].numberst;
				stud[i].numberst=stud[i+1].numberst;
				stud[i+1].numberst=temp;
				
				temp=stud[i].male;
				stud[i].male=stud[i+1].male;
				stud[i+1].male=temp;
			}
		}
	}
}
void sortingpluse()
{
	string temp;
	string temp2;
	for (int m=0; m<kolvo; m++)
	{
		for (int i=0; i<kolvo-1; i++)
		{
			if (stud[i].sername>stud[i+1].sername)
			{
				temp=stud[i].sername;
				stud[i].sername=stud[i+1].sername;
				stud[i+1].sername=temp;
				
				temp=stud[i].name;
				stud[i].name=stud[i+1].name;
				stud[i+1].name=temp;
				
				temp=stud[i].numberst;
				stud[i].numberst=stud[i+1].numberst;
				stud[i+1].numberst=temp;
				
				temp=stud[i].male;
				stud[i].male=stud[i+1].male;
				stud[i+1].male=temp;
			}
		}
	}
}

void thinkfile()
{
	ifstream fin("bd.txt");
	for ( int i=0; i<kolvo; i++)
	{
		fin>> stud[i].numberst>> stud[i].sername>> stud[i].name>> stud[i].male;
	}
}
void save()
{
	ofstream fout("bd.txt");
	for ( int i=0; i<kolvo; i++)
	{
		fout<< stud[i].numberst<<" "<< stud[i].sername<<" "<< stud[i].name<<" "<< stud[i].male<<endl;
	}
}




int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	stud = new UNI[kolvo];
	copstud = new UNI[kolvo];
	
	int g;
	
	while (true)
	{
		
		cout<<"Нажмите 0 для завершения"<<endl;
		cout<<"Нажмите 1 для открытия списка студентов"<<endl;
		cout<<"Нажмите 2 для добавления студента в список"<<endl;
		cout <<"Нажмите 3 для удаления студента из списка"<<endl;
		cout<<"Нажмите 4 для сортировки списка по убыванию"<<endl;
		cout<<"Нажмите 5 для сортировки списка по возрастанию"<<endl;
		cout<<"Нажмите 6 для загрузки списка из файла"<<endl;
		cout<<"Нажмите 7 для сохранения списка в файл"<<endl;
					
	cin>>g;
	
	if (g==0)
	{
		break;
	}
		switch (g)
		{
			case(1):
				vivod();
				break;
			case(2):
				dobavit();
				break;
			case(3):
				delstd();
				break;
			case(4):
				sortingminys();
				break;
			case(5):
				sortingpluse();
				break;
			case(6):
				thinkfile();
				break;
			case(7):
				save();
				break;
				
			default:
				cout<<"Ошибка"<<endl;
				break;
				
				
		}
	}
	
	
		
	return 0;
}

