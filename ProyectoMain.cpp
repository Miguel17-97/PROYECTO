#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "FuncionesProyectoTienda.h"
#include "FuncionesProyectoV2.h"

using namespace std;


int main(int argc, char** argv)
{
	int opc;
	Nodo *producto = new Nodo();
	Cola *empleado = new Cola();
	
	do
	{
		system("cls");
		cout << "\a";
		cout << "\t_________________________________" << endl;
		cout << "\t|----------MENU TIENDA----------|" << endl;
		cout << "\t|-------------------------------|" << endl;
		cout << "\t| (1)Agregar productos          |" << endl;
		cout << "\t| (2)Ver precios y productos    |" << endl;
		cout << "\t| (3)Buscar producto            |" << endl;
		cout << "\t| (4)Actualizar Precios         |" << endl;
		cout << "\t| (5)Eliminar Producto          |" << endl;
		cout << "\t| (6)Hacer lista empleados      |" << endl;
		cout << "\t| (7)Mostrar empleados          |" << endl;
		cout << "\t| (8)Buscar empleado            |" << endl;
		cout << "\t| (9)Despedir empleado          |" << endl;
		cout << "\t| (10)Realizar venta            |" << endl;
		cout << "\t| (11)Realizar inventario       |" << endl;
		cout << "\t| (12)Ver hora local            |" << endl;
		cout << "\t| (13)Acabar turno de trabajo   |" << endl;
		cout << "\t|*******************************|" << endl;
		cout << "\tIngrese la opcion que desee: "; 
		cin >> opc;
		switch(opc)
		{
			case 1: producto->agregarproductos();
					cout << "\n\t";
					system ("pause");
			break;
					
			case 2: cout << "\n\t Mostrando lista de precios y productos" << "\n\t";
					producto->verPreciosProductos();
					cout << "\n\t";
					system ("pause");
			break;

			case 3: producto->buscarProducto();
					cout << "\n\t";
					system ("pause");
			break;
					
			case 4: producto->actualizarPrecio();
					cout << "\n\t";
					system ("pause");
			break;
					
			case 5: producto->eliminarProducto();
					cout << "\n\t";
					system ("pause");
			break;
					
			case 6: empleado->contratarEmpleado();
					cout << "\n\t";
					system ("pause");
			break;
					
			case 7: empleado->mostrarEmpleado();	
					cout << "\n\t";
					system ("pause");
			break;
			
			case 8: empleado->buscarEmpleado();	
					cout << "\n\t";
					system ("pause");					
			break;
			
			case 9: empleado->despedirEmpleado();
					cout << "\n\t";
					system ("pause");					
			break;
			case 13: opc = 14;
					break;		
		}
	}while(opc < 14);
	
	return 0;
}


