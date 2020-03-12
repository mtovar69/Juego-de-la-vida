/********************************************************************** 
* Archivo: Vida_1.cpp
* Fecha: 01-Marzo-2020 
* Autor: José Manuel Pérez Tovar
* Version 1.0
*
* Compilacion: g++ -Wall Vida_1.cpp -o Vida_1
*
* Programa de simulacion del juego de la vida de Conway
*
**********************************************************************/

#include <iostream>
#include <cmath>
#include <cstring> // memcpy
#include <vector>

#ifdef _WIN32
  #include<windows.h>
#endif  

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

using namespace std;

const int MAXRENGLONES = 50;
const int MAXCOLUMNAS = 80;

enum estado {muerta, viva};
typedef estado rejilla[MAXRENGLONES][MAXCOLUMNAS];

rejilla mapa;
rejilla nuevoMapa;

int numGeneraciones;
int i,j, generacion,ultimaGeneracion;

/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	 void Inicializa()
	{
		cout<< "Este programa es una simulación del juega de la Vida de Conway" << endl;
		cout << " Introduzca el numero de generacion a correr: ";
		cin >> ultimaGeneracion;
		
		if (ultimaGeneracion <= 0)
			cout << "No hay salida: corrida de 0 generaciones" << endl;
			
		for (i=0;i< MAXRENGLONES;i++)
		{
		  for(j=0; j< MAXCOLUMNAS;j ++)
			{
			  if (j%2)	
				mapa[i][j] = viva ;
			  else
				mapa[i][j] = muerta ;
				//cout << mapa[i][j];
			}
		  //cout << endl;
		}
	//cout << endl;	
	}
	 
/********************************************************************** 
 *  EscribeMapa : genera la salida gráfica de del contenido de la rejilla
 *  indicando con un '*' para la celdillas vivas y un ' ' para las muertas.
 * 
 * 
 * 
**********************************************************************/
	void EscribeMapa()
	{
	 cout << "El mapa de la generacion: " << generacion << " esta debajo" << endl;
	 for (i=0;i< MAXRENGLONES;i++)
		{
		  for(j=0; j< MAXCOLUMNAS;j ++)
			{
			 if (mapa[i][j] == viva)
				cout << '*';
			 else
				cout << ' ';
			}
		  cout << endl;
		}
	 cout << endl;	
	}
	
/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	int CuentaVecino(int i,int j)
	{
	 int x;	// Indice del ciclo de renglon
	 int xinferior, xsuperior;
	 int y; // indice del ciclo de columna
	 int yinferior, ysuperior;
	 int conteo = 1;
	 
	 if (i == 0)
		xinferior = 0;
	 else
		xinferior = i-1;
		
	 if (i == MAXRENGLONES)
		xsuperior = i;
	 else
		xsuperior = i+1;
		
	 if (j == 0)
		yinferior = 0;
	 else
		yinferior = j-1;
		
	 if (j == MAXCOLUMNAS)
		ysuperior = j;
	 else
		ysuperior = j+1;	
		
	 conteo = 0;
	 for (x = xinferior; x<=xsuperior; x++)
	 {
		 for (y = yinferior; y<=ysuperior; y++)
			 {
				 if (mapa[x][y] == viva)
					 ++conteo;
				 }	
	 }
	 if (mapa[i][j] == viva)
		 --conteo;	 
	 return conteo;
	 }

/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	int main ()
	{
		Inicializa();
		
		cout << " Mapa de generacion inicial juego de la vida "<< endl;	
		EscribeMapa();
		getchar();
		
		limpiar_pantalla();
		
		for (generacion = 0; generacion < ultimaGeneracion; generacion++)
		{
			for(i = 0; i < MAXRENGLONES; i++)
				{ 
					for(j = 0; j < MAXCOLUMNAS; j++)
						{
							switch (CuentaVecino(i,j))
							{
								 case 0:
								 case 1: nuevoMapa[i][j] = muerta;
								 break;
								 
								 case 2:   nuevoMapa[i][j] = mapa[i][j];
								 break;
								 
								 case 3:   nuevoMapa[i][j] = viva;
								 break;
								 
								 case 4:
								 case 5:
								 case 6:
								 case 7:
								 case 8: nuevoMapa[i][j] = muerta;
								 break;
							}
						}
				}

			//Se copia el mapa nuevo sobre el mapa original
			for (i=0;i< MAXRENGLONES;i++)
				{for(j=0; j< MAXCOLUMNAS;j ++)
					{
						mapa[i][j] = nuevoMapa[i][j];
					//	cout << mapa[i][j];
					}
				//  cout << endl;
				}
			
			
			EscribeMapa();
			//getchar();
			//limpiar_pantalla();
		}  

		//getchar();
		cout << " Juego de la vida terminado "<< endl;
		return 0;

	}
