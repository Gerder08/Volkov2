#include <stdio.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <locale.h>
#include <fstream>
#include <cstring>

using namespace std;

struct cpu{
	char brend[30];
	char model[30];
	int frequency;
	int price;
	cpu *next;
};

int main(){
	char choice,name[30];
	int x;
	cpu *beg=NULL;
	cpu *adr;



start:
	do{
		system("cls");
		cout<<"Choose variant 1-4\n"
		<<"1. Get list\n"
		<<"2. New record\n"
		<<"3. Search\n"
		<<"4. Exit\n";

		switch(choice=getch()){
			case '1':{
				cout<<"Get list\n";
				ifstream fp("proc.dat",ios::binary | ios::in);
				if (fp.peek() == EOF){
                    cout<<"Data not found";
                    getch();
                    break;
				}
				//cout<<'2';
				adr=new cpu;
                //cout<<'3';
				while(fp.read((char*)&adr,sizeof(adr))){
                    //cout<<'4';
                    cout<<adr->brend<<endl;
                    cout<<adr->model<<endl;
                    cout<<adr->frequency<<endl;
                    cout<<adr->price<<endl<<endl;


                }
                //adr->next=beg;
                //beg=adr;

                //delete adr;

                fp.close();
      			getch();
				break;

            }


				// ifstream fp("proc.txt",ios::binary|ios::in); //Открываем файл в двоичном режиме только для чтения
 //   in.read((char*)&x,sizeof x); //Читаем оттуда информацию и запоминаем её в X
 //in.close(); //Закрываем файл



			case '2':{
				cout<<"New record\n";

                ofstream f("proc.dat",ios::app | ios::binary);
                adr=new cpu;
                cout<<"brend = "; cin>>adr->brend;
                cout<<"model = "; cin>>adr->model;
                cout<<"frequency = "; cin>>adr->frequency;
                cout<<"price = "; cin>>adr->price;

                adr->next=beg;
                beg=adr;

                f.write((char*)&adr,sizeof(adr));

                //delete adr;
                f.close();
                getch();
                break;
            }
			case '3':{
                system("cls");
                cout<<"Search\n";
                cout<<"Choose variant 1-5\n"
                <<"1. brend\n"
                <<"2. model\n"
                <<"3. frequency\n"
                <<"4. price\n"
                <<"5. Exit\n";
                switch(choice=getch()){
                    case '1':{
                        cout<<"Enter a brend name = ";cin>>name;

                        ifstream fp("proc.dat",ios::binary | ios::in);
                        if (fp.peek() == EOF){
                    cout<<"Data not found";
                    getch();
                    break;
				}
                        adr=new cpu;
                        while(fp.read((char*)&adr,sizeof(adr))){
                                if(!strcmp(adr->brend,name)){
                                    cout<<adr->brend<<endl;
                                    cout<<adr->model<<endl;
                                    cout<<adr->frequency<<endl;
                                    cout<<adr->price<<endl<<endl;
                                }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '2':{
                        ifstream fp("proc.dat",ios::binary | ios::in);
                       if (fp.peek() == EOF){
                    cout<<"Data not found";
                    getch();
                    break;
				}
                        cout<<"Enter a model name = ";cin>>name;
                        adr=new cpu;
                        while(fp.read((char*)&adr,sizeof(adr))){
                                if(!strcmp(adr->brend,name)){
                                    cout<<adr->brend<<endl;
                                    cout<<adr->model<<endl;
                                    cout<<adr->frequency<<endl;
                                    cout<<adr->price<<endl<<endl;
                                }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '3':{
                        ifstream fp("proc.dat",ios::binary | ios::in);
                        if (fp.peek() == EOF){
                    cout<<"Data not found";
                    getch();
                    break;
				}
                        adr=new cpu;
                        cout<<"Enter >/</=frequency";choice=getch();cin>>x;
                        switch(choice){
                            case '>':{
                                while(fp.read((char*)&adr,sizeof(adr))){
                                    if(adr->frequency>x){
                                        cout<<adr->brend<<endl;
                                        cout<<adr->model<<endl;
                                        cout<<adr->frequency<<endl;
                                        cout<<adr->price<<endl<<endl;
                                    }
                                }
                            }
                            case '<':{
                                while(fp.read((char*)&adr,sizeof(adr))){
                                    if(adr->frequency<x){
                                        cout<<adr->brend<<endl;
                                        cout<<adr->model<<endl;
                                        cout<<adr->frequency<<endl;
                                        cout<<adr->price<<endl<<endl;
                                    }
                                }
                            }
                            case '=':{
                                while(fp.read((char*)&adr,sizeof(adr))){
                                    if(adr->frequency==x){
                                        cout<<adr->brend<<endl;
                                        cout<<adr->model<<endl;
                                        cout<<adr->frequency<<endl;
                                        cout<<adr->price<<endl<<endl;
                                    }
                                }
                            }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '4':{
                        ifstream fp("proc.dat",ios::binary | ios::in);
                        if (fp.peek() == EOF){
                    cout<<"Data not found";
                    getch();
                    break;
				}
                        adr=new cpu;
                        cout<<"Enter >/</=price ";choice=getch();cin>>x;
                        switch(choice){
                            case '>':{
                                while(fp.read((char*)&adr,sizeof(adr))){
                                    if(adr->price>x){
                                        cout<<adr->brend<<endl;
                                        cout<<adr->model<<endl;
                                        cout<<adr->frequency<<endl;
                                        cout<<adr->price<<endl<<endl;
                                    }
                                }
                            }
                            case '<':{
                                while(fp.read((char*)&adr,sizeof(adr))){
                                    if(adr->price<x){
                                        cout<<adr->brend<<endl;
                                        cout<<adr->model<<endl;
                                        cout<<adr->frequency<<endl;
                                        cout<<adr->price<<endl<<endl;
                                    }
                                }
                            }
                            case '=':{
                                while(fp.read((char*)&adr,sizeof(adr))){
                                    if(adr->price==x){
                                        cout<<adr->brend<<endl;
                                        cout<<adr->model<<endl;
                                        cout<<adr->frequency<<endl;
                                        cout<<adr->price<<endl<<endl;
                                    }
                                }
                            }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '5':{
                        goto start;
                    }
                }
            }
			case '4':{
				while (beg!=NULL){
					adr = beg;
					beg = beg->next;
					free(adr);
				}
                delete adr;
				return 0;
			}
		}
	}while(choice!='9');
return 0;
}
