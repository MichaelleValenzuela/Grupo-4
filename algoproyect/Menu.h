#pragma once
int menu()
{
	int op;
	cout << " 1.- INGRESE EL NOMBRE DEL DOCENTE" << endl;
	cout << " 2.- INGRESE EL NOMBRE DE LA MATERIA" << endl;
	cout << " 3.- INGRESE EL NUMERO DE ALUMNOS Y NOTAS A INGRESAR" << endl;
	cout << " 4.- INGRESAR NOTAS DE CADA ESTUDIANTE" << endl;
	cout << " 5.- ALMACENAR DATOS EN UN ARCHIVO" << endl;
	cout << " 6.- ORDENAR LAS CALIFICACIONES" << endl;
	cout << " 7.- ALMACENAR DATOS EN UN ARCHIVO LLAMADO ORDENAMIENTO" << endl;
	cout << " 8.- BUSCAR CALIFICACION" << endl;
	cout << " 9.- ALMACENAR DATOS EN UN ARCHIVO LLAMADO BUSQUEDA " << endl;
	cout << " 0.- Salir" << endl;
	cout << "ESCOGA UNA OPCION: ";
	cin >> op;
	system("cls");
	while (op < 0 || op > 9)
	{
		cout << "INGRESE UNA OPCION VALIDA" << endl;
		cin >> op;
	}
	return op;

}
int ordenar()
{
	int op = 0;
	cout << "ESCOJA EL METODO PARA ORDENAR LA LISTA" << endl;
	cout << endl;
	cout << "1.- BURBUJA" << endl;
	cout << "2.- SELECCION" << endl;
	cout << "3.- INSERCCION" << endl;
	cout << "4.- RAPIDO O QUICKSORT" << endl;
	cout << "5.- MEZCLA O MERGESORT" << endl;
	cout << "6.- HEAPSORT" << endl;
	cout << "ESCOJA UNA OPCION: ";
	cin >> op;
	system("cls");
	while (op < 1 || op >6)
	{
		cout << "ESCOJA UNA OPCION VALIDA";
		cin >> op;
	}
	return op;
}
int buscar()
{
	int op = 0;
	cout << "ESCOJA EL METODO PARA BUSCAR" << endl;
	cout << endl;
	cout << "1.- LINEAL" << endl;
	cout << "2.- BINARIA" << endl;
	cout << "3.- INTERPOLACION" << endl;
	cout << "ESCOJA UNA OPCION: ";
	cin >> op;
	system("cls");
	while (op < 1 || op >3)
	{
		cout << "ESCOJA UNA OPCION VALIDA";
		cin >> op;
	}
	return op;
}
