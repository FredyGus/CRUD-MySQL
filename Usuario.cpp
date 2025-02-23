#include "Usuario.h"

void Usuario::crearUsuario(Connection* con, string nombre, string correo, int edad) {
	try
	{
		PreparedStatement* pstmt = con->prepareStatement("INSERT INTO usuarios(nombre, correo, edad) VALUES (?, ?, ?)");
		pstmt->setString(1, nombre);
		pstmt->setString(2, correo);
		pstmt->setInt(3, edad);
		pstmt->executeUpdate();
		delete pstmt;
		cout << "Usuario creado con exito.\n";
	}
	catch (SQLException &e)
	{
		cerr << "Error SQL: " << e.what() << endl;
	}

}

void Usuario::leerUsuario(Connection* con) {
	PreparedStatement* pstmt = con->prepareStatement("SELECT * FROM usuarios");
	ResultSet *res = pstmt->executeQuery();
	while (res->next()) {
		cout << "ID: " << res->getInt("id") << ", Nombre: " << res->getString("nombre")
			<< ", Correo: " << res->getString("correo") << ", Edad: " << res->getInt("edad") << endl;
	}

	delete res;
	delete pstmt;
}

void Usuario::actualizarUsuario(Connection* con, int id, string nombre, string correo, int edad) {
	PreparedStatement* pstmt = con->prepareStatement("UPDATE usuarios SET nombre = ?, correo = ?, edad = ? WHERE id = ?");
	pstmt->setString(1, nombre);
	pstmt->setString(2, correo);
	pstmt->setInt(3, edad);
	pstmt->setInt(4, id);
	pstmt->executeUpdate();
	delete pstmt;
	cout << "Usuario actualizado con exito.\n";
}

void Usuario::eliminarUsuario(Connection* con, int id) {
	PreparedStatement* pstmt = con->prepareStatement("DELETE FROM usuarios WHERE id = ?");
	pstmt->setInt(1, id);
	pstmt->executeUpdate();
	delete pstmt;
	cout << "Usuario eliminado con exito.\n";
}
