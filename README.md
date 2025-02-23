# 🛠️ CRUD en C++ con MySQL

## 📌 Descripción

Este proyecto es una aplicación **CRUD (Create, Read, Update, Delete)** en **C++** con integración de **MySQL**, permitiendo la gestión de usuarios en una base de datos. Se utiliza el conector de **MySQL Connector/C++** para la comunicación con la base de datos.

## 🎯 Funcionalidades

✅ **Crear** un usuario con `nombre`, `correo` y `edad`.  
✅ **Leer** todos los usuarios registrados en la base de datos.  
✅ **Actualizar** la información de un usuario existente mediante su `ID`.  
✅ **Eliminar** un usuario de la base de datos utilizando su `ID`.

## 🏗️ Estructura del Código

### 🔹 **1. `Conexion.h` y `Conexion.cpp`** (Manejo de la base de datos)

- Establece la conexión con MySQL.
- Utiliza `mysql_driver.h` y `mysql_connection.h` de **MySQL Connector/C++**.
- Proporciona el método `getConexion()` para acceder a la base de datos.

### 🔹 **2. `Usuario.h` y `Usuario.cpp`** (Operaciones CRUD)

- Define la clase `Usuario` con métodos estáticos para gestionar los registros:
  - `crearUsuario()`: Inserta un nuevo usuario en la base de datos.
  - `leerUsuario()`: Recupera y muestra todos los usuarios.
  - `actualizarUsuario()`: Modifica los datos de un usuario según su `ID`.
  - `eliminarUsuario()`: Elimina un usuario según su `ID`.

### 🔹 **3. `main.cpp`** (Interfaz del usuario)

- Implementa un menú interactivo para gestionar los usuarios.
- Captura la opción del usuario y ejecuta la acción correspondiente.
- Usa `switch-case` para manejar las operaciones CRUD.
- Permite ingresar datos desde la consola y ejecuta las funciones de `Usuario`.

## 📌 Instalación y ejecución

### **1. Requisitos previos**

🔹 **Instalar MySQL Server** y crear la base de datos `CRUD_DB`.  
🔹 **Instalar MySQL Connector/C++** para conectar C++ con MySQL.  
🔹 **Configurar las credenciales en `Conexion.cpp`**.

### **2. Configuración de la base de datos**

Ejecuta el siguiente SQL en MySQL para crear la base de datos y la tabla:

```sql
CREATE DATABASE CRUD_DB;
USE CRUD_DB;

CREATE TABLE usuarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100),
    correo VARCHAR(100),
    edad INT
);
```
