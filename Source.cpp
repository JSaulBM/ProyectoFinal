#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <vector>

using namespace std;

//

void Alta();
void listas();
void archivos();
void eliminar();
void modificar();


int alta, * trat, * cant, * precun, * total, * cita;
string* nombre, * hora, * desc, * tratamiento;
int main()
{
	int opc;
	cout << "\t *Proyecto* \n";
	cout << "1.-Alta de una cita" << endl << "2.-Mostrar citas vigentes" << endl << "3.-Limpiar pantalla" << endl << "4.-Modificar Cita" << endl << "5.-Eliminar" << endl << "6.-Salir" << endl;
	cin >> opc;
	cout << endl;

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}

void Alta()
{
	cout << "Ingresa el numero de citas a dar de alta" << endl;
	cin >> alta;
	trat = new int[alta];
	total = new int[alta];
	cant = new int[alta];
	precun = new int[alta];
	nombre = new string[alta];
	hora = new string[alta];
	desc = new string[alta];
	tratamiento = new string[alta];

	for (int i = 0; i < alta; i++)
	{
		cout << "Numero de cita: " << i + 1 << endl;
		while (getchar() != '\n');
		cout << "Ingrese el nombre del paciente: ";
		getline(cin, nombre[i]);
		cout << "Ingrese la hora de la cita (formato 24hrs): ";
		cin >> hora[i];
		cout << "Nombre del tratamiento: ";
		cin >> tratamiento[i];
		while (getchar() != '\n');
		cout << "Descripcion del tratamiento: ";
		getline(cin, desc[i]);
		cout << "Precio unitario tratamiento: ";
		cin >> trat[i];
		cout << "Cantidad del tratamiento: ";
		cin >> cant[i];
		cout << "Precio unitario: ";
		cin >> precun[i];
		cout << "Total: $";
		total[i] = precun[i] + (trat[i] * cant[i]);
		cout << total[i];
		cout << endl << endl;

	}
}

void listas()
{
	for (int i = 0; i < alta; i++)
	{
		if (cant[i] == 0) {
			cout << "Registro eliminado" << endl << endl;
		}
		else {
			cout << "Numero de cita: " << i + 1 << endl;
			cout << "Nombre: " << nombre[i] << endl;
			cout << "Hora: " << hora[i] << endl;
			cout << "Tratamiento: " << tratamiento[i] << endl;
			cout << "Descripcion: " << desc[i] << endl;
			cout << "Precio unitario tratamiento: " << trat[i] << endl;
			cout << "Cantidad del tratamiento: " << cant[i] << endl;
			cout << "Precio unitario: " << precun[i] << endl;
			cout << "Total: $" << total[i] << endl << endl;
		}
		
	}
}

void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	string texto2;

	nombrearchivo = "CitasVigentes";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	

	for (int i = 0; i < alta; i++)
	{
		if (cant[i] == 0) {
			archivo << "Registro eliminado" << "\n"<<"\n";
		}
		else {
			texto = i + 1;
			archivo << "Numero de cita: " << texto << "\n";
			texto2 = nombre[i];
			archivo << "Nombre del paciente: " << texto2 << "\n";
			texto2 = hora[i];
			archivo << "Hora: " << texto2 << "\n ";
			texto2 = tratamiento[i];
			archivo << "Tratamiento: " << texto2 << "\n ";
			texto2 = desc[i];
			archivo << "Descripcion: " << texto2 << "\n";
			texto = trat[i];
			archivo << "Precio unitario tratamiento: " << texto << "\n";
			texto = cant[i];
			archivo << "Cantidad del tratamiento" << texto << "\n";
			texto = precun[i];
			archivo << "Precio unitario: " << texto << "\n";
			total[i] = precun[i] + (trat[i] * cant[i]);
			texto = total[i];
			archivo << "Total: " << texto << "\n" << "\n";
		}
	}


	archivo.close();
}

void eliminar()
{
	cout << "ingrese la cita a eliminar: \n";
	int j;
	cin >> j;
	j = j - 1;
	for (int i = j; i <= j; i++) {
		nombre[i] = " ";
		hora[i] = " ";
		tratamiento[i] = " ";
		desc[i] = " ";
		precun[i] = 0;
		cant[i] = 0;
		total[i] = 0;
		trat[i] = 0;
	}
}

void modificar()
{
	cout << "ingrese la cita a modificar \n";
	int j;
	cin >> j;
	j = j - 1;
	for (int i = j; i <= j; i++) {
		cout << "Numero de cita: " << i + 1 << endl;
		while (getchar() != '\n');
		cout << "Ingrese el nombre del paciente: ";
		getline(cin, nombre[i]);
		cout << "Ingrese la hora de la cita (formato 24hrs): ";
		cin >> hora[i];
		cout << "Nombre del tratamiento: ";
		cin >> tratamiento[i];
		while (getchar() != '\n');
		cout << "Descripcion del tratamiento: ";
		getline(cin, desc[i]);
		cout << "Precio unitario tratamiento: ";
		cin >> trat[i];
		cout << "Cantidad del tratamiento: ";
		cin >> cant[i];
		cout << "Precio unitario: ";
		cin >> precun[i];
		total[i] = precun[i] + (trat[i] * cant[i]);
		cout << "Total: $" << total[i];
		cout << endl << endl;
	}

}