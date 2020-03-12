/********************************************************************** 
* Archivo: Vida_2.cpp
* Fecha: 06-Marzo-2020 
* Autor: José Manuel Pérez Tovar
* Version 2.0
*
* Compilacion: g++ -Wall Vida_2.cpp -o Vida_2
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
const int MAXLISTA = 200;

enum estado {muerta, viva};

typedef estado rejilla[MAXRENGLONES][MAXCOLUMNAS];
typedef struct
		{
		 int x;
		 int y;
		} coordenada;

typedef struct
		{
		 int conteo;
		 coordenada entrada[MAXLISTA];
		} lista; 
		
rejilla mapa;
rejilla nuevoMapa;

int numeronvec[MAXRENGLONES][MAXCOLUMNAS]; 
lista vida, muerte, siguienteviva, siguientemuerta;
int i,j, generacion,ultimaGeneracion;
int numGeneraciones;

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
 *  EscribeMapa : Genera la salida gráfica del contenido en la rejilla
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
	void Vivifica()
		{
		 int k = 1;
		 while (k <= vida.conteo)
			{
			 if ((mapa[vida.entrada[k].x][vida.entrada[k].y] = muerta)
			      &&(numeronvec[vida.entrada[k].x][vida.entrada[k].y]== 3))
			      {
				   mapa[vida.entrada[k].x][vida.entrada[k].y] = viva;
				   k++;
				   }
			 else
				{
				 vida.entrada[k] = vida.entrada[vida.conteo];
				 vida.conteo--;
				 }	
			}
		 
		}
/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	void Destruye()
		{}

/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	void SumaVecinos()
		{}
/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	void SustraeVecinos()
		{}
/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	void CopiaViva()
		{
	     for (int  k = 1; k <= siguienteviva.conteo; k++)
			vida.entrada[k] = siguienteviva.entrada[k];
		 
		 vida.conteo = siguienteviva.conteo;
		 siguienteviva.conteo = 0;		 
		}
/********************************************************************** 
 * 
 * 
 * 
 * 
**********************************************************************/
	void CopiaMuerta()
		{}
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
 * Cuerpo principal del programa: Vida
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
		
		for (generacion = 1; generacion <= ultimaGeneracion; generacion++)
		{
		 Vivifica();
		 Destruye();
		 EscribeMapa();
		 SumaVecinos();
		 SustraeVecinos();
		 CopiaViva();
		 CopiaMuerta();
		 
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
					}
				}
			EscribeMapa();
			//limpiar_pantalla();
		}  
		cout << " Juego de la vida terminado "<< endl;
		return 0;

	}
