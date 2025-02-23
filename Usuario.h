#ifndef USUARIO_H
#define USUARIO_H

#include "Conexion.h"

class Usuario {
public:
	static void crearUsuario(Connection* con, string nombre, string correo, int edad);
	static void leerUsuario(Connection* con);
	static void actualizarUsuario(Connection* con, int id, string nombre, string correo, int edad);
	static void eliminarUsuario(Connection* con, int id);

};

#endif 
