#ifndef CTRLSISTEMA_H
#define CTRLSISTEMA_H
#include "ISistema.h"
#include "EstadoReserva.h"
#include "TipoCargo.h"
#include "Usuario.h"
#include "Empleado.h"
#include "Huesped.h"
#include "DTHuesped.h"
#include "DTFecha.h"
#include "DTEmpleado.h"
#include "Reserva.h"
#include "Estadia.h"
#include "Hostal.h"
#include "Reloj.h"
#include "DTHostal.h"
#include "DTEstadia.h"
#include "DTHabitacion.h"
#include "Habitacion.h"
#include <string>
#include <map>
#include <iostream>
#include <istream>
#include <ios>

using namespace std;
class CtrlSistema : public ISistema
{
public:
    static CtrlSistema *getInstancia();
    void confirmarAltaHostal(string nombre, string direccion, string telefono); //
    void imprimirHabitaciones(Hostal *h);                                       //
    bool existeEstadia(string email);                                           //
    bool existeHostal(string nombre);                                           //
    bool existeHostalThrow(string nombre);
    void finalizarEstadia(string email);                                      //
    bool estadiaValida(string email);                                         //
    void obtenerHostales();                                                   //
    void seleccionarHostal(string nomHostal);                                 //
    void imprimirEstadias(string nomHostal);                                  //
    Habitacion *seleccionarHabitacion(int numero);                            //
    Hostal *getHostal();                                                      //
    void asignarEmpHostal();                                                  //
    Habitacion *getHabitacion(Hostal *hos, int num);                          //
    void imprimirlnfoEstadia(string nomHostal, string emailestadia, int cod); //
    Estadia *getEstadia();                                                    //
    void seleccionarEstadia(int cod, string email);                           //
    void confirmarAltaHabitacion();                                           //
    void ingresaristarEstadiasFinalizadas(string emailUsuario);               //
    void ingresarInformacionHabitacion(int num, float precio, int capacidad); //
    void listarEstadiasFinalizadas(string email);                             //
    void imprimirInfoBasicaHostal(Hostal *hos);                               //
    void agregarEstadia(string key, Estadia *est);                            //
    void setContadorReserva();
    void obtenerReservas(Hostal *hos);       //
    Reserva *seleccionarReserva(int codigo); //
    Reserva *getReserva();                   //
    void cancelarReserva();                  //
    void confirmarReserva(Hostal *h, DTFecha *fechaCheckIn, DTFecha *fechaCheckOut, int tipoDeReserva, Habitacion *hab, Huesped *hue, std::map<std::string, Huesped *> coleccionHuespedReserva);
    void ingresarInformacionReserva(DTFecha checkIN, DTFecha checkOUT, DTReserva *tipoReserva); //
    void obtenerReserva();                                                                      //
    void obtenerReservasPorHostal(string nomHostal);                                            //
    void habitacionDisponible(DTFecha *checkIn, DTFecha *checkOut, Hostal *h);                  //
    void imprimirReservasHuesped(Huesped *hues);                                                //
    void seleccionarEmpleado(string email);                                                     //
    Usuario *seleccionarUsuario(string email);                                                  //
    Huesped *seleccionarHuesped(string nombre);                                                 //
    void imprimirUsuarios();                                                                    //
    void cancelarAltaIngreso();                                                                 //
    Huesped *getHuesped();                                                                      //
    void asignarCargo(string nombre, tipoCargo cargo);                                          //
    void setCargo(tipoCargo);                                                                   //
    Empleado *findEmpleado(string email);                                                       //
    Huesped *findHuesped(string nombre);                                                        //
    bool existeUsuario();                                                                       //
    void ingresarDatosUsuario();                                                                //
    void actualizarEmailUsuario(string email);                                                  //
    void confirmarAltaUsuario();                                                                //
    void setHostalTrabaja(Hostal *hos);                                                         //
    set<DTEmpleado *> obtenerEmpleadosNoRegistrados(Hostal *hos);                               //
    void imprimirReservasHuesped(string emailHuesped);                                          //
    void setNombre(string nombre);                                                              //
    void setEmail(string email);                                                                //
    void setContrasenia(string contrasenia);                                                    //
    void setEsFinger(bool finger);                                                              //
    Empleado *getEmpleado();                                                                    //
    void obtenerInfoUsuario(string rol, string email);                                          //
    bool obtenerEsFinger();                                                                     //
    void obtenerInfoEmpleado();                                                                 //
    Empleado *obtenerEmpleado();                                                                //
    void obtenerEmpleados(string nomHostal);                                                    //
    void obtenerEmpleados();                                                                    //
    void obtenerReservasHuesped(string email);                                                  //
    void obtenerHuespedes();                                                                    //
    void obtenerUsuarios();                                                                     //
    void imprimirTodaLaInfoDeUsuarios();                                                        //
private:
    CtrlSistema();
    static CtrlSistema *instancia;
    // colecciones
    map<int, Reserva *> coleccionReservas;
    map<string, Hostal *> coleccionHostales;
    map<string, Usuario *> coleccionUsuarios;
    // Memoria del sistema
    int numeroHabitacion;
    float precioHabitacion;
    int capacidadHabitacion;
    Hostal *hostalSeleccionado;
    Habitacion *habitacionSeleccionada;
    Estadia *estadiaSeleccionada;
    string nombre;
    string email;
    string password;
    bool esFinger;
    tipoCargo cargo;
    Hostal *hostalTrabaja;
    Huesped *huespedSeleccionado;
    Empleado *empleadoSeleccionado;
    int contadorReserva;
};
#endif
