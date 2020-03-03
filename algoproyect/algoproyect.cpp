#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Menu.h";

ofstream archivo, archivo1, archivo2;
int const MAX = 100;
typedef struct
{
    string nombre;
    int nota;
}tAlumnos;
typedef tAlumnos tArray[MAX];
typedef struct
{
    tArray elementos;
    int contador;
}tLista;

int binaria(tLista lista, int bus, int alumnos);
int lineal(tLista lista, int bus, int alumnos);
int interpolar(tLista lista, int bus, int alumnos);
void burbuja(tLista& lista, tAlumnos& alum, int alumnos);
void seleccion(tLista& lista, tAlumnos& alum, int alumnos);
void inserccion(tLista& lista, tAlumnos& alum, int alumnos);
void rapida(tLista &arr, int pinicial, int pfinal);
void Fusionar(tLista &a, int pinicial, int pfinal, int medio);
void dividir(tLista a, int inicial, int final);
double promedio(int alumnos, tLista lista);
void calificaciones(int alumnos, tLista lista, string materia, string docente, int cedula);
void ordenamiento(int alumnos, tLista lista, string materia, string docente, int cedula, int orden);
void resulbusca(int alumnos, tLista lista, string materia, string docente, int cedula, int num,int busca);
void ingresar(int alumnos, tAlumnos& alumn, tLista& lista);
void mostrar(int alumnos, tLista lista);
void heapsort(tLista &lista,int alumnos);
int main()
{
    tAlumnos alumn;
    tLista lista;
    int op = -1, orden, cedula, alumnos, bus, num;
    string docente, materia;
    cout << setw(40) << right << "GESTION DE CALIFICACIONES COLEGIO MEJIA" << endl;
    cout << endl;
    op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
        {
            cout << "INGRESE EL NUMERO DE CEDULA: ";
            cin >> cedula;
            while (cedula < 0)
            {
                cout << "INGRESE EL NUMERO DE CEDULA: ";
                cin >> cedula;

            }
            cin.ignore();
            cout << "INGRESE EL NOMBRE DEL DOCENTE: ";
            getline(cin, docente);
            cout << endl;
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
            cin.ignore();
            cout << "INGRESE EL NOMBRE DE LA MATERIA: ";
            getline(cin, materia);
            cout << endl;
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            cout << "INGRESE EL NUMERO DE ESTUDIANTES: ";
            cin >> alumnos;
            while (alumnos < 0)
            {
                cout << "INGRESE EL NUMERO DE ESTUDIANTES: ";
                cin >> alumnos;
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        break;
        case 4:
        {
            cout << "INGRESAR LOS NOMBRES Y NOTAS DE CADA ALUMNO" << endl;
            cout << endl;
            ingresar(alumnos, alumn, lista);
            cout << endl;
            system("pause");
            system("cls");
        }
        break;
        case 5:
        {
            cout << "A CONTINUACION SE ALMACERADA LOS DATOS EN UN ARCHIVO" << endl;
            calificaciones(alumnos, lista, materia, docente, cedula);
            cout << endl;
            system("pause");
            system("cls");
        }
        break;
        case 6:
        {
            cout << "ORDENAR LAS NOTAS" << endl;
            cout << endl;
            orden = ordenar();
            switch (orden)
            {
            case 1:
            {
                cout << setw(30) << right << "ORDENAMIENTO BURBUJA" << endl;
                cout << endl;
                burbuja(lista, alumn, alumnos);
                mostrar(alumnos, lista);
                cout << endl;
                system("pause");
                system("cls");
            }
            break;
            case 2:
            {
                cout << setw(30) << right << "ORDENAMIENTO SELECCION" << endl;
                cout << endl;
                seleccion(lista, alumn, alumnos);
                mostrar(alumnos, lista);
                cout << endl;
                system("pause");
                system("cls");
            }
            break;
            case 3:
            {
                cout << setw(30) << right << "ORDENAMIENTO INSERCION" << endl;
                cout << endl;
                inserccion(lista, alumn, alumnos);
                mostrar(alumnos, lista);
                cout << endl;
                system("pause");
                system("cls");
            }
            break;
            case 4:
            {
                cout << setw(30) << right << "ORDENAMIENTO RAPIDO O QUICKSORT" << endl;
                cout << endl;
                rapida(lista, 0, alumnos-1);
                mostrar(alumnos, lista);
                cout << endl;
                system("pause");
                system("cls");
            }
            break;
            case 5:
            {
                cout << setw(30) << right << "ORDENAMIENTO DIVISION O MERGESORT" << endl;
                cout << endl;
                dividir(lista, 0, alumnos);
                mostrar(alumnos, lista);
                cout << endl;
                system("pause");
                system("cls");
            }
			break;
			case 6:
			{
				cout << setw(30) << right << "ORDENAMIENTO HEAPSORT" << endl;
				cout << endl;
				heapsort(lista, alumnos);
				mostrar(alumnos, lista);
				cout << endl;
				system("pause");
				system("cls");
			}
			
            }

        }

        break;
		
        case 7:
        {
            cout << "A CONTINUACION VAMOS A ALMACENAR LOS RESULTADOS EN UN ARCHIVO" << endl;
            ordenamiento(alumnos, lista, materia, docente, cedula, orden);
            cout << endl;
            system("pause");
            system("cls");
        }
        break;
        case 8:
        {
            cout << "INGRESE EL NUMERO A BUSCAR: ";
            cin >> num;
            cout << endl;
            bus = buscar();
            switch (bus)
            {
            case 1:
            {
                
                cout << "BUSQUEDA LINEAL" << endl;
                cout << endl;
                if (lineal(lista, num, alumnos) != -1)
                {
                    
                    cout << "LA NOTA  " << num << " ES DEL ALUMNO " <<lista.elementos[ lineal(lista, num, alumnos)].nombre << endl;
                }
                else
                {
                    cout << "NO SE A ENCONTRADO EL ELEMENTO" << endl;
                }
                cout << endl;
                system("pause");
                system("cls");
            }
            break;
            case 2:
            {
                cout << "BUSQUEDA BINARIA" << endl;
                cout << endl;
                if (binaria(lista, num, alumnos) != -1)
                {
                    cout << "LA NOTA  " << num << " ES DEL ALUMNO " << lista.elementos[binaria(lista, num, alumnos)].nombre << endl;
                }
                else
                {
                    cout << "NO SE HA ENCONTRADO EL NUMERO BUSCADO" << endl;
                }
                cout << endl;
                system("pause");
                system("cls");
            }
            break;
            case 3:
            {
                cout << "BUSQUEDA INTERPOLAR" << endl;
                cout << endl;
                if (interpolar(lista, num, alumnos) != -1)
                {
                    cout << "LA NOTA  " << num << " ES DEL ALUMNO " << lista.elementos[interpolar(lista, num, alumnos)].nombre << endl;
                }
                else
                {
                    cout << "EL ELMENTO NO SE ENCUENTRA EN EL ARREGLO" << endl;
                }
                cout << endl;
                system("pause");
                system("cls");
            }
            }
        }
        break;
        case 9:
        {
            cout << "A CONTINUCACION SE ALMACENA EL RESULTADO DE LA BUSQUEDA EN UN ARCHIVO" << endl;
            resulbusca(alumnos, lista, materia, docente, cedula, num,bus);
            cout << endl;
            system("pause");
            system("cls");
        }
        }
        op = menu();
    }
    return 0;
}
void ingresar(int alumnos, tAlumnos& alumn, tLista& lista)
{
    lista.contador = 0;
    for (int i = 0; i < alumnos; i++)
    {
        cin.ignore();
        cout << "INGRESE EL NOMBRE DEL ALUMNO " << i + 1 << ": ";
        getline(cin, alumn.nombre);
        cout << "INGRESE LA NOTA DEL ALUMNO: ";
        cin >> alumn.nota;
        while (alumn.nota > 20|| alumn.nota < 0)
        {
            cout << "INGRESE LA NOTA DEL ALUMNO: ";
            cin >> alumn.nota;
        }
        
        lista.elementos[lista.contador] = alumn;
        lista.contador++;
    }
}
double promedio(int alumnos, tLista lista)
{
    double prom = 0;
    for (int i = 0; i < alumnos; i++)
    {
        prom = prom + lista.elementos[i].nota;
    }
    return prom / alumnos;
}

void calificaciones(int alumnos, tLista lista, string materia, string docente, int cedula)
{
    archivo.open("./colegio/calificaciones.txt");
    
    if (!archivo.is_open())
    {
        cout << "NO SE PUDO ABRIR EL DOCUMENTO";
    }
    else
    {
        int aprob = 0, repro = 0, sus = 0;
        archivo << setw(70) << "COLEGIO MEJIA " << endl;
        archivo << setw(60) << "REPORTE DE CALIFICACIONES " << endl;
        archivo << "AÑO LECTIVO 2019-2020" << endl;
        archivo << "MATERIA: " << materia << endl;
        archivo << setw(4) << "N° " << setw(15) << right << "NOMBRE " << " " << setw(3) << "NOTA" << endl;
        for (int i = 0; i < alumnos; i++)
        {
            archivo << setw(4) << i + 1 << setw(15) << right << lista.elementos[i].nombre << " " << setw(3) << lista.elementos[i].nota << endl;
        }
        archivo << "RESUMEN" << endl;

        archivo << "PROMEDIO: " << promedio(alumnos, lista) << endl;
        for (int i = 0; i < alumnos; i++)
        {
            if (lista.elementos[i].nota < 21 && lista.elementos[i].nota > 13)
            {
                aprob++;
            }
            if (lista.elementos[i].nota < 15 && lista.elementos[i].nota > 8)
            {
                sus++;
            }
            if (lista.elementos[i].nota < 10 && lista.elementos[i].nota > 0)
            {
                repro++;
            }
        }
        archivo << "APROBADO:   " << aprob << endl;
        archivo << "SUSPENDIDO: " << sus << endl;
        archivo << "REPROBADO:  " << repro << endl;
        archivo << endl << endl;
        archivo << setw(50) << right << "________________________________________" << endl;
        archivo << endl;
        archivo << setw(50) << right << docente << endl;
        archivo << setw(50) << right << cedula << endl;
    }
}
void ordenamiento(int alumnos, tLista lista, string materia, string docente, int cedula,int orden)
{
    archivo1.open("./colegio/ordenamiento.txt");
    if (!archivo1.is_open())
    {
        cout << "NO SE PUDO ABRIR EL DOCUMENTO";
    }
    else
    {
        archivo1 << setw(70) << "COLEGIO MEJIA " << endl;
        archivo1 << setw(60) << "REPORTE DE CALIFICACIONES " << endl;
        archivo1 << "CALIFICACIONES ORDENADAS" << endl;
        archivo1 << "ALGORITMO: " << endl;
        if (orden == 1)
            archivo1 << " BURBUJA" << endl;
        if (orden == 2)
            archivo1 << " SELECCION" << endl;
        if (orden == 3)
            archivo1 << "INSERCION " << endl;
        if (orden == 4)
            archivo1 << "MERGE SORT" << endl;
		if (orden == 5)
			archivo1 << "QUICKSORT" << endl;
		if (orden == 6)
			archivo1 << "HEAPSORT" << endl;


        for (int i = 0; i < alumnos; i++)
        {
            archivo1 << " | " << lista.elementos[i].nota;
        }
        archivo1 << endl;
        archivo1 << setw(50) << right << "________________________________________" << endl;
        archivo1 << endl;
        archivo1 << setw(50) << right << docente << endl;
        archivo1 << setw(50) << right << cedula << endl;
    }
}
void mostrar(int alumnos, tLista lista)
{
    for (int i = 0; i < alumnos; i++)
    {
        cout << " | " << lista.elementos[i].nota;
    }
    cout << endl;
}
void resulbusca(int alumnos, tLista lista, string materia, string docente, int cedula, int num,int bus)
{
    archivo2.open("./colegio/busqueda.txt");
    if (!archivo2.is_open())
    {
        cout << "NO SE PUDO ABRIR EL DOCUMENTO";
    }
    else
    {
        archivo2 << setw(70) << "COLEGIO MEJIA " << endl;
        archivo2 << setw(60) << "REPORTE DE CALIFICACIONES " << endl;
        archivo2 << "RESULTADO DE BUSQUEDA" << endl;
        archivo2 << "ALGORITMO: ";
        if (bus == 1)
            archivo2 << " LINEAL" << endl;
        if (bus == 2)
            archivo2 << " BINARIA" << endl;
        if (bus == 3)
            archivo2 << " INTERPOLAR" << endl;
        archivo2 << endl;
        if (lineal(lista, num, alumnos) != -1)
        {
            archivo2 << "LA NOTA  " << num << " ES DEL ALUMNO " << lista.elementos[lineal(lista, num, alumnos)].nombre << endl;
        }
        else
        {
            archivo2 << "EL NUMERO A BUSCAR NO EXISTE" << endl;

        }
        archivo2 << endl;
        archivo2 << setw(50) << right << "________________________________________" << endl;
        archivo2 << endl;
        archivo2 << setw(50) << right << docente << endl;
        archivo2 << setw(50) << right << cedula << endl;
    }
}
void burbuja(tLista& lista, tAlumnos& alum, int alumnos)
{
    tAlumnos a;
    for (int i = 0; i < alumnos; i++)
    {
        for (int j = i + 1; j < alumnos; j++)
        {
            if (lista.elementos[j].nota < lista.elementos[i].nota)
            {
                a = lista.elementos[i];
                lista.elementos[i] = lista.elementos[j];
                lista.elementos[j] = a;
            }
        }
    }
}
void seleccion(tLista& lista, tAlumnos& alum, int alumnos)
{
    int i, j, min;
    tAlumnos aux;
    for (i = 0; i < alumnos; i++)
    {
        min = i;
        for (j = i + 1; j < alumnos; j++)
        {
            if (lista.elementos[j].nota < lista.elementos[min].nota)
            {
                min = j;
            }
        }
        aux = lista.elementos[i];
        lista.elementos[i] = lista.elementos[min];
        lista.elementos[min] = aux;
    }
}
void inserccion(tLista& lista, tAlumnos& alum, int alumnos)
{
    int pos;
    tAlumnos aux;
    for (int i = 0; i < alumnos; i++)
    {
        pos = i;
        aux.nota = lista.elementos[i].nota;
        while ((pos > 0) && (lista.elementos[pos - 1].nota > aux.nota))
        {
            lista.elementos[pos] = lista.elementos[pos - 1];
            pos--;
        }
        lista.elementos[pos] = aux;
    }
}
void dividir(tLista a, int inicial, int final)
{
    int mitad;
    if (inicial < final)
    {
        mitad = (inicial + final) / 2;

        dividir(a, inicial, mitad);
        dividir(a, mitad + 1, final);
        Fusionar(a, inicial, final, mitad);
    }
}
void Fusionar(tLista &a, int pinicial, int pfinal, int medio)
{
    tLista temp;
    temp.elementos[pfinal - pinicial + 1];
    int i, j, k;
    i = pinicial;
    k = 0;
    j = medio + 1;
    while (i <= medio && j <= pfinal)
    {
        if (a.elementos[i].nota < a.elementos[j].nota)
        {
            temp.elementos[k] = a.elementos[i];
            k++;
            i++;
        }
        else
        {
            temp.elementos[k] = a.elementos[j];
            k++;
            j++;
        }
    }
    while (i <= medio)
    {
        temp.elementos[k] = a.elementos[i];
        k++;
        i++;
    }
    while (j <= pfinal)
    {
        temp.elementos[k] = a.elementos[j];
        k++;
        j++;
    }
    for (i = pinicial; i <= pfinal; i++)
    {
        a.elementos[i] = temp.elementos[i - pinicial];
    }
}
int mitad(tLista& arr, int pinicial, int pfinal)
{
    return arr.elementos[(pinicial + pfinal) / 2].nota;
}
void rapida(tLista &arr, int pinicial, int pfinal)
{
    int i = pinicial;
    int j = pfinal;
    tAlumnos temp;
    int piv;
    piv = mitad(arr, pinicial, pfinal);
    do
    {
        while (arr.elementos[i].nota < piv)
        {
            i++;
        }
        while (arr.elementos[j].nota > piv)
        {
            j--;
        }

        if (i <= j)
        {
            temp = arr.elementos[i];
            arr.elementos[i] = arr.elementos[j];
            arr.elementos[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (pinicial < j)
        rapida(arr, pinicial, j);
    if (i < pfinal)
        rapida(arr, i, pfinal);
}
int binaria(tLista lista, int bus, int alumnos)
{
    int  i, j, k;
    i = 0;
    j = alumnos - 1;
    do
    {
        k = (i + j) / 2;
        if (lista.elementos[k].nota <= bus)
            i = k + 1;
        if (lista.elementos[k].nota >= bus)
            j = k - 1;
    } while (i <= j);
    if(lista.elementos[k].nota!=bus)
    {
        k = -1;
    }
    return k;
}
int lineal(tLista lista, int bus, int alumnos)
{
    int pos = -1;
    bool c=false;
    for (int i = 0; i < alumnos; i++)
    {
        if (lista.elementos[i].nota == bus)
        {
            c = true;
            pos = i;
        }
    }
    if (c == false)
    {
        pos = -1;
    }
    return pos;
}
int interpolar(tLista lista, int bus, int alumnos)
{
    int primero = 0;
    int ultimo = alumnos - 1;
    int medio;
    int cont = 0;
    int buscado = bus;
    int pos = -1;
    while ((lista.elementos[primero].nota != buscado) && (cont <= alumnos)) {
        medio = primero + ((buscado - lista.elementos[primero].nota) * (ultimo - primero)) / (lista.elementos[ultimo].nota - lista.elementos[primero].nota);
        if (lista.elementos[medio].nota < buscado) {
            primero = medio + 1;
        }
        else if (lista.elementos[medio].nota > buscado) {
            ultimo = medio - 1;
        }
        else {
            primero = medio;
        }
        cont++;
    }
    if (lista.elementos[primero].nota == buscado)
    {
        pos = primero;
        return pos;
    }
    if (lista.elementos[primero].nota != buscado)
    {

        return -1;
    }
}

void heapsort(tLista &lista, int alumnos)
{
	int  a;

	tAlumnos valor,temp;

	for (int i = alumnos; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			valor = lista.elementos[j];
			a = j / 2;
			while (a > 0 && lista.elementos[a].nota < valor.nota)
			{
				lista.elementos[j] = lista.elementos[a];
				j = a;
				a = a / 2;
			}
			lista.elementos[j] = valor;
		}
		temp = lista.elementos[1];
		lista.elementos[1] = lista.elementos[i];
		lista.elementos[i] = temp;
	}
}
