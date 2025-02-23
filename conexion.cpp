#include "Conexion.h"

const string SERVER = "tcp://127.0.0.1:3306";
const string USER = "root";
const string PASSWORD = "";
const string DATABASE = "CRUD_DB";

using namespace mysql;

Conexion::Conexion() {
	try
	{
		MySQL_Driver* driver = get_mysql_driver_instance();
		con = driver->connect(SERVER, USER, PASSWORD);
		con->setSchema(DATABASE);
	}
	catch (SQLException &e)
	{
		cout << "Error en la conexio: " << e.what() << endl;
		exit(1);
	}
}

Conexion::~Conexion() {
	delete con;
}

Connection *Conexion::getConexion() {
	return con;
}
