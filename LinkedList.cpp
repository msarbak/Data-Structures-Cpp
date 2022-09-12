#include "LinkedList.hpp"
#include <cstdlib>

int main(){
    LinkedList<string> *names = new LinkedList<string>();
    int choice = 0;
    string name;
    int position;
    do{//secenekli menu yapmak icin dongu
        system("CLS"); //her calismada ekran temizligi
        cout<<"[1]\tAdd Name"<<endl;
        cout<<"[2]\tRemove Name"<<endl;
        cout<<"[3]\tRemove From Posiiton"<<endl;
        cout<<"[4]\tInsert Name"<<endl;
        cout<<"[5]\tFind Poisiton"<<endl;
        cout<<"[6]\tNumber of Names"<<endl;
        cout<<"[7]\tFirst Name"<<endl;
        cout<<"[8]\tLast Name"<<endl;
        cout<<"[9]\tList Names"<<endl;
        cout<<"[10]\tClear Names"<<endl;
        cout<<"[11]\tExit"<<endl;
        cin>>choice;
        system("CLS");

        switch(choice){
            case 1:
                cout<<"Name: ";
                cin.ignore();
                getline(cin,name); //ikiden fazla kelime girebilir isim icin
                names->add(name);
            break;
            case 2:
                cout<<"Name: ";
                cin.ignore();
                getline(cin,name); //ikiden fazla kelime girebilir isim icin
                names->remove(name);
            break;
            case 3:
                cout<<"Position: ";
                cin>>position;
                names->removeAt(position);
            break;
            case 4:
                cout<<"Position: ";
                cin>>position;
                cout<<"Name: ";
                cin.ignore();
                getline(cin,name);
                names->insert(position,name);
            break;
            case 5:
                cout<<"Name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Position: "<<names->indexOf(name);
                cin.get(); //ekran dondugu icin sürekli durudurup konumu gorememiz gerekiyor
            break;
            case 6:
                cout<<"Number of names: "<<names->count();
                cin.ignore();
                cin.get(); // bazen karaktersonlandırma calıstaıabiliyor onun icin gormezden gel func. ignore var
            break; 
            case 7:
                cout<<"First name: "<<names->first();
                cin.ignore();
                cin.get();
            break;
            case 8:
                cout<<"Last name: "<<names->last();
                cin.ignore();
                cin.get();
            break;
            case 9:
                cout<<"Names: "<<endl;
                cout<<*names<<endl;//ekrana yazma operatounu tanımaldıgım icin direkt bu sekilde yazabilirim
                cin.ignore();
                cin.get();
            break;
            case 10:
                names->clear();
            break;
            case 11:
            break;
            default:
                cout<<endl<<"Wrong choice!!"<<endl<<endl;
                cin.ignore();
                cin.get();
            break;
        }
        system("CLS");
    }while(choice != 11);
    delete names;
    return 0;
}