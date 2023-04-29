#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Nodo{
    int position;
    int llegada;
    int atencion;
    int espera;
    Nodo *siguiente;
};

Nodo *frente = NULL;
Nodo *fin = NULL;
int pos, lle = 0, esp = 0, at =0, suma = 0, mayor = 0;

void menu();
bool ColaVacia(Nodo *&frente);
void MostrarCola(Nodo *&frente);
void IngresarNodo(Nodo *&frente, Nodo *&fin, int pos, int lle, int esp, int at);

int main(){
    menu();
    MostrarCola(frente);
    
    cout<<"\nEl tiempo de espera mas largo fue de "<<mayor<<" minutos"<<endl;
}

void menu(){
    
    srand(time(NULL));
    cout<<"Numero de Cliente \t Minuto de llegada \t Tiempo de espera \t Tiempo de atencion";
    for(;lle <720;){
    	pos++;
        if(lle == 0){
            lle += 1+(rand()%4); //4 Llegada del primer cliente
            at = 1+(rand()%4);  //4
            suma = lle + at;   // = 8
          //  cout<<"\n["<<pos<<"]\t\t\t["<<lle<<"]\t\t\t["<<esp<<"]\t\t\t["<<at<<"]"<<endl;
        }else{
            lle += 1+(rand()%4); //8
            if(lle>suma){
                esp = 0;
                at = 1+(rand()%4); //3
                suma = lle + at; //11
            }else{
                esp = suma - lle;  //8-6=2   //11-9=2
                at = 1+(rand()%4); //3        //2
                suma = suma + at; // 8 + 3 = 11 //11+2=13
            }
            if(esp > mayor){
            mayor = esp;
        	}
            //cout<<"\n["<<pos<<"]\t\t\t["<<lle<<"]\t\t\t["<<esp<<"]\t\t\t["<<at<<"]"<<endl;
        }
        IngresarNodo(frente, fin, pos, lle, esp, at);
	}
}

void MostrarCola(Nodo *&frente){
    Nodo *imprimir = new Nodo;
    imprimir = frente;
    while(imprimir != NULL){
        if(imprimir != NULL){
            cout<<"\n["<<imprimir->position<<"]\t\t\t["<<imprimir->llegada<<"]\t\t\t["
				<<imprimir->espera<<"]\t\t\t["<<imprimir->atencion<<"]"<<endl;
            imprimir = imprimir ->siguiente;
        }
        else{
            cout<<"\nCola vacia\n";
        }
    }
}

void IngresarNodo(Nodo *&frente, Nodo *&fin, int pos, int lle, int esp, int at){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> position = pos;
    nuevo_nodo -> llegada = lle;
    nuevo_nodo -> espera = esp;
    nuevo_nodo -> atencion = at;

    if(ColaVacia(frente)){
        frente = nuevo_nodo;
    }else{
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

bool ColaVacia(Nodo *&frente){
    return (frente == NULL)? true: false;
}

void EliminarNodo(Nodo *&frente, Nodo *&fin, int &pos, int &lle, int &esp, int &at){
    Nodo *aux = frente;
    pos = frente -> position;
    lle = frente -> llegada;
    esp = frente -> espera;
    at = frente -> atencion;
    if(frente == fin){
        frente=NULL;
        fin=NULL;
    }
    else{
        frente=frente->siguiente;
    }
    delete aux;
}
