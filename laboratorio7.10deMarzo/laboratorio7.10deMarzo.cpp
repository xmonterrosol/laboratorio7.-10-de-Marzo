#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    bool activa;
    int intentosFallidos;
    int mesesInactivo;

public:
    CuentaBancaria(string _titular, double _saldo) {
        titular = _titular;
        saldo = _saldo;
        activa = true;
        intentosFallidos = 0;
        mesesInactivo = 0;
    }

    void depositar(double monto) {
        if (activa) {
            if (monto > 0) {
                saldo += monto;
                cout << "Deposito exitoso. Saldo actual: " << saldo << endl;
            }
            else {
                cout << "No se pueden hacer depositos con montos negativos o cero." << endl;
            }
        }
        else {
            cout << "No se pueden hacer depositos si la cuenta esta bloqueada." << endl;
        }
    }

    void retirar(double monto) {
        if (activa) {
            if (monto > 0) {
                if (saldo >= monto) {
                    saldo -= monto;
                    cout << "Retiro exitoso. Saldo actual: " << saldo << endl;
                }
                else {
                    intentosFallidos++;
                    cout << "Fondos insuficientes. Intentos fallidos: " << intentosFallidos << endl;
                    if (intentosFallidos >= 3) {
                        activa = false;
                        cout << "La cuenta ha sido bloqueada debido a intentos fallidos de retiro." << endl;
                    }
                }
            }
            else {
                cout << "No se pueden hacer retiros con montos negativos o cero." << endl;
            }
        }
        else {
            cout << "No se pueden hacer retiros si la cuenta esta bloqueada." << endl;
        }
    }

    void consultarSaldo() {
        if (activa) {
            cout << "Saldo actual: " << saldo << endl;
            if (saldo < 100) {
                cout << "Advertencia: Su saldo es bajo." << endl;
            }
        }
        else {
            cout << "La cuenta esta bloqueada." << endl;
        }
    }

    void simularMesesInactivo(int meses) {
        mesesInactivo += meses;
        if (mesesInactivo >= 6) {
            activa = false;
            cout << "La cuenta ha sido bloqueada automaticamente debido a inactividad prolongada." << endl;
        }
    }
};

int main() {
    // Creación de 30 cuentas 
    CuentaBancaria cuenta1("Cuenta_1", 0);
    CuentaBancaria cuenta2("Cuenta_2", 0);
    CuentaBancaria cuenta3("Cuenta_3", 0);
    CuentaBancaria cuenta4("Cuenta_4", 0);
    CuentaBancaria cuenta5("Cuenta_5", 0);
    CuentaBancaria cuenta6("Cuenta_6", 0);
    CuentaBancaria cuenta7("Cuenta_7", 0);
    CuentaBancaria cuenta8("Cuenta_8", 0);
    CuentaBancaria cuenta9("Cuenta_9", 0);
    CuentaBancaria cuenta10("Cuenta_10", 0);
    CuentaBancaria cuenta11("Cuenta_11", 0);
    CuentaBancaria cuenta12("Cuenta_12", 0);
    CuentaBancaria cuenta13("Cuenta_13", 0);
    CuentaBancaria cuenta14("Cuenta_14", 0);
    CuentaBancaria cuenta15("Cuenta_15", 0);
    CuentaBancaria cuenta16("Cuenta_16", 0);
    CuentaBancaria cuenta17("Cuenta_17", 0);
    CuentaBancaria cuenta18("Cuenta_18", 0);
    CuentaBancaria cuenta19("Cuenta_19", 0);
    CuentaBancaria cuenta20("Cuenta_20", 0);
    CuentaBancaria cuenta21("Cuenta_21", 0);
    CuentaBancaria cuenta22("Cuenta_22", 0);
    CuentaBancaria cuenta23("Cuenta_23", 0);
    CuentaBancaria cuenta24("Cuenta_24", 0);
    CuentaBancaria cuenta25("Cuenta_25", 0);
    CuentaBancaria cuenta26("Cuenta_26", 0);
    CuentaBancaria cuenta27("Cuenta_27", 0);
    CuentaBancaria cuenta28("Cuenta_28", 0);
    CuentaBancaria cuenta29("Cuenta_29", 0);
    CuentaBancaria cuenta30("Cuenta_30", 0);

    int opcion;
    double monto;
    int numCuenta;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Depositar" << endl;
        cout << "2. Retirar" << endl;
        cout << "3. Consultar saldo" << endl;
        cout << "4. Simular meses inactivo" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Por favor, ingrese numero de cuenta (1-30): " << endl;
            cin >> numCuenta;
            cout << "Ingrese monto a depositar: " << endl;
            cin >> monto;
            if (numCuenta == 1) cuenta1.depositar(monto);
            else if (numCuenta == 2) cuenta2.depositar(monto);
            // ...
            else if (numCuenta == 30) cuenta30.depositar(monto);
            break;
        case 2:
            cout << "Ingrese numero de cuenta (1-30): " << endl;
            cin >> numCuenta;
            cout << "Ingrese monto a retirar: " << endl;
            cin >> monto;
            if (numCuenta == 1) cuenta1.retirar(monto);
            else if (numCuenta == 2) cuenta2.retirar(monto);
            // ...
            else if (numCuenta == 30) cuenta30.retirar(monto);
            break;
        case 3:
            cout << "Ingrese numero de cuenta (1-30): " << endl;
            cin >> numCuenta;
            if (numCuenta == 1) cuenta1.consultarSaldo();
            else if (numCuenta == 2) cuenta2.consultarSaldo();
            // ...
            else if (numCuenta == 30) cuenta30.consultarSaldo();
            break;
        case 4:
            cout << "Ingrese numero de cuenta (1-30): " << endl;
            cin >> numCuenta;
            cout << "Ingrese meses inactivo: " << endl;
            cin >> monto;
            if (numCuenta == 1) cuenta1.simularMesesInactivo(monto);
            else if (numCuenta == 2) cuenta2.simularMesesInactivo(monto);
            // ...
            else if (numCuenta == 30) cuenta30.simularMesesInactivo(monto);
            break;
        case 5:
            break;
        default:
            cout << "Opcion invalida. Por favor, intentelo de nuevo." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
