#ifndef CONEXION_H
#define CONEXION_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

using namespace std;
using namespace sql;

class Conexion {
private:
	Connection *con;
public:
	Conexion();
	~Conexion();

	Connection* getConexion();
};

#endif