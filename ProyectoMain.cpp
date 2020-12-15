#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include "FuncionesProyectoTienda.h"
#include "FuncionesProyectoV2.h"

using namespace std;


int main(int argc, char** argv)
{
	
	int opc,i;
	Nodo *producto = new Nodo();
	Cola *empleado = new Cola();
	setlocale(LC_ALL, "spanish");
	
	do
	{
		system("cls");
		cout << "\a";
		cout << "\t_________________________________" << endl;
		cout << "\t|----------MENU TIENDA----------|" << endl;
		cout << "\t|-------------------------------|" << endl;
		cout << "\t| (1)Agregar productos          |" << endl;
		cout << "\t| (2)Ver precios y productos    |" << endl;
		cout << "\t| (3)Buscar producto            |" << endl;		//este es el menu
		cout << "\t| (4)Actualizar Precios         |" << endl;
		cout << "\t| (5)Eliminar Producto          |" << endl;
		cout << "\t| (6)Hacer lista empleados      |" << endl;
		cout << "\t| (7)Mostrar empleados          |" << endl;
		cout << "\t| (8)Buscar empleado            |" << endl;
		cout << "\t| (9)Despedir empleado          |" << endl;
		cout << "\t| (10)Realizar venta            |" << endl;
		cout << "\t| (11)Realizar inventario       |" << endl;
		cout << "\t| (12)Acabar turno de trabajo   |" << endl;
		cout << "\t|*******************************|" << endl;
		cout << "\tIngrese la opcion que desee: "; 
		cin >> opc;
		switch(opc)
		{
			case 1: system("cls");
					producto->agregarproductos();
					cout << "\n\t";
					system ("pause");
					break;
					
			case 2: system("cls");
					cout << "\n\t Mostrando lista de precios y productos";
					for(i=0; i<5; i++)
					{
						sleep(1);
						cout << ".";
					}
					cout << "\n\t";
					producto->verPreciosProductos();
					cout << "\n\t";
					system ("pause");
					break;

			case 3: system("cls");
					cout << "\n\t Mostrando productos";
					for(i=0; i<5; i++)
					{
						sleep(1);
						cout << ".";
					}
					cout << "\n\t";
					producto->buscarProducto();
					cout << "\n\t";
					system ("pause");
					break;
					
			case 4: system("cls");
					producto->actualizarPrecio();
					cout << "\n\t";
					system ("pause");
					break;
					
			case 5: system("cls");
					producto->eliminarProducto();
					cout << "\n\t";
					system ("pause");
					break;
					
			case 6: system("cls");
					empleado->contratarEmpleado();
					cout << "\n\t";
					system ("pause");
					break;
					
			case 7: system("cls");
					cout << "\n\t Mostrando lista de empleados";
					for(i=0; i<5; i++)
					{
						sleep(1);
						cout << ".";
					}
					cout << "\n\t";
					empleado->mostrarEmpleado();	
					cout << "\n\t";
					system ("pause");
					break;
			
			case 8: system("cls");
					cout << "\n\t Buscando empleado, espere";
					for(i=0; i<5; i++)
					{
						sleep(1);
						cout << ".";
					}
					cout << "\n\t";
					empleado->buscarEmpleado();	
					cout << "\n\t";
					system ("pause");					
					break;
			
			case 9: system("cls");
					empleado->despedirEmpleado();
					cout << "\n\t";
					system ("pause");					
					break;
					
			case 10:system("cls");
					producto->realizarVenta();
					cout << "\n\t";
					system("pause");
					break;
			
			case 11:system("cls");
					cout << "\n\t Realizando inventario, un momento por favor";
					for(i=0; i<5; i++)
					{
						sleep(1);
						cout << ".";
					}
					producto->realizarInventario();
					cout << "\n";
					system("pause");
					break;
					 
			case 12:system("cls");
					opc = 13;
					break;		
		}
	}while(opc < 13);
	
	return 0;
	//aca acaba
}


