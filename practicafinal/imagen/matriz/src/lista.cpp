#include <string>
#include <fstream>
#include "lista.h"

using namespace std;

/////////////////////////////////////////////////////////////////
// PRACTICA 6

Lista::Lista(const Lista & copia){
	int taman = copia.longitud();

	cabecera = 0;
	
	for(int i = 0; i < taman; i++)
		insertar(copia.getCelda(i));
	
}

Lista::~Lista(){
	destruir();
}

Lista::Lista(){
	cabecera = 0;
}
   
Lista::Lista(string valor){
	cabecera = 0;
	insertar(valor);
}

Lista &Lista::operator= (const Lista &referencia){
	if (this != &referencia){
		destruir();
		for(int i = 0; i < referencia.longitud(); i++)
			insertar(referencia.getCelda(i));
	}
	
	return *this;
}

Lista Lista::operator+(const string & suma) const{
	Lista nueva;
	int tamanio = longitud();
	
	for(int i = 0; i < tamanio; i++)
		nueva.insertar(this->getCelda(i));
	
	nueva.insertar(suma);
	return nueva;
}

/////////////////////////////////////////////////////////////////

void Lista::destruir(){
	if(cabecera != 0){
		while(cabecera != 0){
			Celda *temp = cabecera->siguiente;
			delete cabecera;
			cabecera = temp;
		}
		cabecera = 0;
	}
}  

void Lista::insertar(string valor){
	Celda *puntero = new Celda;
	puntero->datos = valor;
	
	if(cabecera != 0){
		Celda *temp = cabecera;
		bool controlador = true;
		
		while(controlador)
			if(temp->siguiente == 0){
				temp->siguiente = puntero;
				controlador = false;
			}
			else
				temp = temp->siguiente;
	}
	else
		cabecera = puntero;
	
	puntero->siguiente = 0;
}

string Lista::getCelda(int pos) const{
	Celda *temp = cabecera;
	bool controlador = true;
	string adevolver; 
	for(int i = 0; i <= pos && temp != 0 && controlador; i++)
		if(i == pos){
			adevolver = temp->datos;
			controlador = false;
		}
		else
			temp = temp->siguiente;

	return adevolver;
}

int Lista::longitud() const{
	int contador = 0;
	
	for(Celda *temp = cabecera; temp != 0; temp = temp->siguiente)
		contador++;

	return contador;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}
