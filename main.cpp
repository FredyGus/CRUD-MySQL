#include "Conexion.h"
#include "Usuario.h"

const void menu() {
	cout << "CRUD en C++ y MySQL" << endl;
	cout << "\n1. Crear ususario\n";
	cout << "2. Leer ususario\n";
	cout << "3. Actualizar ususario\n";
	cout << "4. Eliminar usuario\n";
	cout << "5. Salir\n";
	cout << "Elige una opcion: ";
}

int main() {
	Conexion conexion;
	Connection* con = conexion.getConexion();
	int opcion, id, edad;
	string nombre, correo;

	do {
		menu();
		cin >> opcion;
		cin.ignore();

		switch (opcion) {
		case 1:
			cout << "Nombre: "; getline(cin, nombre);
			cout << "Correo: "; getline(cin, correo);
			cout << "Edad: "; cin >> edad;
			Usuario::crearUsuario(con, nombre, correo, edad);
			break;
		case 2:
			Usuario::leerUsuario(con);
			break;
		case 3: 
			cout << "ID a actualizar: "; cin >> id;
			cin.ignore();
			cout << "Nuevo nombre: "; getline(cin, nombre);
			cout << "Nuevo correo: "; getline(cin, correo);
			cout << "Nueva edad: "; cin >> edad;
			Usuario::actualizarUsuario(con, id, nombre, correo, edad);
			break;
		case 4:
			cout << "ID a eliminar: "; cin >> id;
			Usuario::eliminarUsuario(con, id);
			break;
		case 5:
			cout << "Saliendo...\n";
			system("pause");
			return 0;
			break;
		default:
			cout << "Opcion invalida.\n";
		}
	} while (opcion != 5);
}