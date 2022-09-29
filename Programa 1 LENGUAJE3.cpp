#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//DEFINIR CONSTANTES
const int MAX_CPUS=5;
const int NO_EXISTE=-1;

//1)DEFINIMOS NUESTRA CLASE
class Computadora {
	public:
		//ATRIBUTOS
		int id;
		int disco;
		bool conectado;
		bool encendido;
		//CONSTRUCTOR POR DEFECTO
		Computadora() {
			//ASIGNAR LOS VALORES POR DEFECTO
			id=-1;
			disco=1024;
			conectado=false;
			encendido=false;
		}

		void mostrarinformacion() {
			string estaEncendida="APAGADA";
			string estaConectado="Sin Conexion";

			if (encendido)
				estaEncendida = "ENCENDIDA";

			if (conectado)
				estaConectado = "CONECTADO";

			cout<< setw(10) << id << " "
			    << setw(10) << disco << " "
			    << setw(15) << estaEncendida << " "
			    << setw(15) << estaConectado << endl;


		}
};

//CLASE CONTROLADOR
class Red {
	public:
		//ARREGLO DE OBJETOS
		Computadora cpus[MAX_CPUS];
		//CONSTRUCTOR POR DEFECTO
		Red() {
			for (int i=0; i<MAX_CPUS; i++) {
				cpus[i].id=1000+i;
			}
		}

		void mostrarRed() {
			for (int i=0; i<MAX_CPUS; i++) {
				cpus[i].mostrarinformacion();
			}
		}

		void encenderPC() {
			//PEDIR ID DE LA CPMPUTADORA
			int idPC;
			cout <<"Ingrese el id de la PC: ";
			cin >> idPC;
			//BUSCAR EN EL ARREGLO
			int indice=NO_EXISTE;
			for (int i=0; i<MAX_CPUS; i++) {
				if (cpus[i].id==idPC) {
					indice=i; //SALVAMOS EL INDICE
					break;
				}
			}

			//SE ENCONTRO EL ID?
			if (indice==NO_EXISTE) {
				cout << "ERROR-NO SE ENCUENTRA EL ID."<<endl;

			} else { //SI EXISTE ENCENDER LA PC
				if (cpus[indice].encendido==true) {
					cout<<"La PC ya estaba encendida"<<endl;
				} else {
					cpus[indice].encendido=true;
					cout<<"EXITO-Computadora Encendida. " <<endl;

				}

			}
		}

		void apagarPC() {
			//PEDIR ID DE LA CPMPUTADORA
			int idPC;
			cout <<"Ingrese el id de la PC: ";
			cin >> idPC;
			//BUSCAR EN EL ARREGLO
			int indice=NO_EXISTE;
			for (int i=0; i<MAX_CPUS; i++) {
				if (cpus[i].id==idPC) {
					indice=i; //SALVAMOS EL INDICE
					break;
				}
			}

			//SE ENCONTRO EL ID?
			if (indice==NO_EXISTE) {
				cout << "ERROR-NO SE ENCUENTRA EL ID."<<endl;

			} else { //SI EXISTE ENCENDER LA PC
				if (cpus[indice].encendido==true) {

					cpus[indice].encendido=false;
					cout<<"EXITO-Computadora Apagada. " <<endl;
				} else {
					cout<<"La PC ya estaba Apagada"<<endl;

				}

			}
		}

		void conectarRed() {
			//PEDIR ID DE LA CPMPUTADORA
			int idPC;
			cout <<"Ingrese el id de la PC: ";
			cin >> idPC;
			//BUSCAR EN EL ARREGLO
			int indice=NO_EXISTE;
			for (int i=0; i<MAX_CPUS; i++) {
				if (cpus[i].id==idPC) {
					indice=i; //SALVAMOS EL INDICE
					break;
				}
			}

			//SE ENCONTRO EL ID?
			if (indice==NO_EXISTE) {
				cout << "ERROR-NO SE ENCUENTRA EL ID."<<endl;

			} else { //SI EXISTE ENCENDER LA PC
				if (cpus[indice].encendido==true) {
					if (cpus[indice].conectado==false) {
						cpus[indice].conectado=true;
						cout << "EXITO-Computadora conectada a red. " <<endl;
					} else {
						cout << "Ya esta conectada. " <<endl;
					}

				} else {
					cout<<"Para conectarla a la red debe de estar encendida. "<<endl;

				}

			}
		}

		void desconectarRed() {
			//PEDIR ID DE LA CPMPUTADORA
			int idPC;
			cout <<"Ingrese el id de la PC: ";
			cin >> idPC;
			//BUSCAR EN EL ARREGLO
			int indice=NO_EXISTE;
			for (int i=0; i<MAX_CPUS; i++) {
				if (cpus[i].id==idPC) {
					indice=i; //SALVAMOS EL INDICE
					break;
				}
			}

			//SE ENCONTRO EL ID?
			if (indice==NO_EXISTE) {
				cout << "ERROR-NO SE ENCUENTRA EL ID."<<endl;

			} else { //SI EXISTE ENCENDER LA PC
				if (cpus[indice].encendido==true) {
					if (cpus[indice].conectado==true) {
						cpus[indice].conectado=false;
						cout << "EXITO-Computadora desconectada a red. " <<endl;
					} else {
						cout << "Ya esta desconectada. " <<endl;
					}

				} else {
					cout<<"Para desconectarla a la red debe de estar encendida. "<<endl;

				}

			}
		}
};


//FUNCION PRINCIPAL-PUNTO DE INICIO

int main(int argc, const char* argv[]) {
	//CREAR EL OBJETO PRINCIPAL
	Red red;
	int opcionSeleccionada=-1;
	//DECLARANDO CONSTANTES
	enum OPCIONES {MOSTRAR_RED=1, ENCENDER_PC, APAGAR_PC, CONECTAR_RED, DESCONECTAR_RED, SALIR};

	//CREAR MENU
	do {
		system("cls");
		cout << "MENU PRINCIPAL"<<endl
		     << "--------------"<<endl
		     << "1- Mostrar estado de la red"<<endl
		     << "2- Encender computadora"<<endl
		     << "3- Apagar computadora"<<endl
		     << "4- Conectar a red"<<endl
		     << "5- Desconectar a red"<<endl
		     << "6- Salir"<<endl
		     << "---------------"<<endl
		     << "Ingrese su opcion [1-6]";

		cin>>opcionSeleccionada;
		switch(opcionSeleccionada) {
			case MOSTRAR_RED:
				red.mostrarRed();
				break;
			case ENCENDER_PC:
				red.encenderPC();
				break;
			case APAGAR_PC:
				red.apagarPC();
				break;
			case CONECTAR_RED:
				red.conectarRed();
				break;
			case DESCONECTAR_RED:
				red.desconectarRed();
				break;
			case SALIR:
				cout<<"NOS VEMOS"<<endl;
				break;
			default:
				cout<<"Opcion esta fuera de rango...."<<endl;
				break;

		}
		system("pause");

	} while (opcionSeleccionada!=SALIR);
	return 0;



}
