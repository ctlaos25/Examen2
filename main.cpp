#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Gato.h"
#include "Evaluador.h"
#include "NodoTrinario.h"

using namespace std;
int BYTE_SIZE = 25;

//Escribe los datos del objeto gato (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios gatos en un solo archivo
void escribir(string nombre_archivo, Gato*gato, int posicion)
{
    ofstream out(nombre_archivo.c_str(), ios::in);
    out.seekp((posicion) * BYTE_SIZE);
    //edad, sexo, nombre, raza
    out.write((char*)&gato->edad, 4);
    out.write(&gato->sexo, 1);
    out.write(gato->nombre.c_str(), 10);
    out.write(gato->raza.c_str(), 10);

    out.close();

    /*
        int edad;
        char sexo;
        string nombre;
        string raza;
    */
}

//Devuelve un gato previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios gatos de un solo archivo
Gato* leer(string nombre_archivo, int posicion)
{
    Gato *gato = new Gato(0,' ',"","");

    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion * BYTE_SIZE);
    int edad;
    char sexo;
    char nombre[10];
    char raza[10];

    in.read((char*)&edad, 4);
    in.read(&sexo, 1);
    in.read(nombre, 10);
    in.read(raza, 10);

    gato->edad = edad;
    gato->sexo = sexo;
    gato->nombre = nombre;
    gato->raza = raza;

    return gato;
}

//Devuelve el promedio de la edad de todos los gatos guardados en el archivo con nombre dado
double getPromedioDeEdad(string nombre_archivo)
{
    int cont=0;
    int flag;
    double suma = 0;
    ifstream in(nombre_archivo.c_str());
    in.seekg(0, ios::end);
    int tamano = in.tellg()/25;
    for(int i = 0; i<tamano; i++)
    {
        in.seekg(i*25, ios::beg);
        in.read((char*)&flag, 4);
        suma+=flag;
        cont=(cont+1);
    }
    return suma/cont;
}

//Devuelve el numero mayor almacenado en mi_set (dado)
int getMayor(set<int> mi_set)
{
    int maxx=0;
    for(set<int>::iterator i=mi_set.begin();
        i!=mi_set.end();
        i++)
        if(*i>maxx){

            maxx=*i;

            }
        return maxx;
}

//Mezcla el contenido de a y b (dados) y lo devuelve en un set ordenado alfabeticamente
set<char> mezclarAlfabeticamente(queue<char> a, stack<char> b)
{
    set<char> resultado;
    while(!a.empty())
    {
        resultado.insert(a.front());
        a.pop();
    }
    while(!b.empty())
    {
        resultado.insert(b.top());
        b.pop();
    }
    return resultado;
}

//Devuelve true si buscada (dada) existe en mi_mapa (dado), de lo contrario devuelve false
//Se debe de buscar en las llaves y en los valores almacenados en cada vector del mapa
bool existe(map<string,vector<string> >mi_mapa, string buscada)
{
    for(map<string,vector<string> >::iterator i = mi_mapa.begin();
        i!=mi_mapa.end();
        i++)
    {
        if((*i).first.compare(buscada)==0)
            return true;
        for(int x=0;x<(*i).second.size();x++)
        {
            if((*i).second[x].compare(buscada)==0)
            return true;
        }
    }
    return false;
}

//Devuelve el valor mayor almacenado en el arbol con raiz dada
int getMayor(NodoTrinario* raiz)
{
    int num=0;


    return num;
}

//Busca y reemplaza dado los valores buscado y reemplazo en el arbol con raiz dada
void buscarYReemplazar(NodoTrinario* raiz,int buscado, int reemplazo)
{
    if(raiz != NULL)
        if(raiz->valor==buscado)
            raiz->valor=reemplazo;

    if(raiz->derecho != NULL){
        buscarYReemplazar(raiz->derecho, buscado, reemplazo);
        if(buscado==raiz->derecho->valor)
            raiz->derecho->valor=reemplazo;
    }

    if(raiz->izquierdo != NULL){
         buscarYReemplazar(raiz->izquierdo, buscado, reemplazo);
        if(buscado==raiz->izquierdo->valor)
            raiz->izquierdo->valor=reemplazo;

    }

    if(raiz->medio != NULL){
        buscarYReemplazar(raiz->medio, buscado, reemplazo);
        if(buscado==raiz->medio->valor)
            raiz->medio->valor=reemplazo;
    }

}

char retener3Bits(char byte)
{
    return 0;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
