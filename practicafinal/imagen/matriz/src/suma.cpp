#include <iostream>
#include <imagen.h>

using namespace std;

int main (int numero_argumentos, char **argument){
	if(numero_argumentos == 5){
		cout << "PRUEBA PARA EL OPERADOR+ LISTA" << endl;
		Lista hola("hola");
		hola.insertar("que");
		hola.insertar("tal");
		hola = hola + "estas";
		hola = hola + "tu";
		for(int i = 0; i < hola.longitud(); i++)
			cout << hola.getCelda(i) << " ";
		cout << endl << endl;
	
	
		cout << "SUMA DE IMAGENES" << endl;
		Imagen caller, callee, resultado;
	
		if(caller.leerImagen(argument[1]))
			cout << argument[1] << " leido Correctamente" << endl;
		else{
			cerr << argument[1] << " no se pudo leer." << endl;
			return 1;
		}

		if(callee.leerImagen(argument[2]))
			cout << argument[2] << " leido Correctamente" << endl;
		else{
			cerr << argument[2] << " no se pudo leer." << endl;
			return 1;
		}
	
	
		resultado = caller + callee;
		bool formato = (argument[4][0] == 't') ? false : true;
	
		if(resultado.escribirImagen(argument[3],formato))
			cout << argument[3] << " creado Correctamente" << endl;
		else{
			cerr << argument[3] << " no se pudo escribir." << endl;
			return 1;
		}
	}
	else
		cerr << "Introduzca imagen1.pgm imagen2.pgm destino.pgm (b para binario o t para texto)." << endl;
	
	return 0;
}
