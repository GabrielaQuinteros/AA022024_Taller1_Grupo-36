#include <iostream>
using namespace std;

// Estructura para almacenar los datos de cada producto
struct Product {
    string name;
    int stock;
};

// Función para agregar productos al inventario
void addProduct(Product inventory[], int &count) {
    cout <<"Ingrese el nombre del producto: ";
    cin >> inventory[count].name;
    cout <<  "Ingrese la cantidad en stock: ";
    cin >> inventory[count].stock;
    count++;
}

// Función para eliminar un producto del inventario
void deleteProduct(Product inventory[], int &count) {
    if (count == 0) { //nuevo
        cout << "No hay productos para eliminar.\n"; //nuevo
        return; //nuevo
    }
    string nameToDelete;
    cout << "Ingrese el nombre del producto a eliminar: ";
    cin >> nameToDelete;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (inventory[i].name == nameToDelete) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            found = true;
            cout << "Producto eliminado del inventario.\n";
            break;
        }
    }

    if (!found) {
        cout << "No se encontro el producto.\n";
    }
}

// Función para modificar la cantidad de stock de un producto
void updateStock(Product inventory[], int count) {
    string nameToUpdate;
    cout << "Ingrese el nombre del producto a modificar: ";
    cin >> nameToUpdate;
    bool exists = false;

    for (int i = 0; i < count; i++) {
        if (inventory[i].name == nameToUpdate) {
            int newStock;
            cout << "Cantidad actual de stock: " << inventory[i].stock << endl;
            cout << "Ingrese la nueva cantidad de stock: ";
            cin >> newStock;

            // Verificar si es el mismo stock
            if (newStock == inventory[i].stock) {
                cout << "El nuevo valor es el mismo que el valor actual.\n";
                cout << "Ingrese un valor diferente: ";
                cin >> newStock;
            }

            // Actualizar el stock si el valor ingresado es diferente
            if (newStock != inventory[i].stock) {
                inventory[i].stock = newStock;
                cout << "Stock actualizado correctamente.\n";
            }
            exists = true;
            break;
        }
    }
    if (!exists) {
        cout << "No se encontro el producto.\n";
    }
}

// Función para ordenar los productos según el stock con BubbleSort
void sortByStock(Product inventory[], int count){
    for (int i = 0; i < count - 1; i++){
        for (int j = 0; j < count - i - 1; j++) {
            if (inventory[j].stock > inventory[j + 1].stock) {
                Product temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
}

// Función para mostrar los productos con menor stock (menor a 10 unidades)
void showLowStock(Product inventory[], int count, int n){
    if (count == 0){
        cout << "No hay productos.\n";
        return;
    }
    sortByStock(inventory, count);
    cout << "Productos con menor stock:\n";
    int shown = 0;

    for (int i = 0; i < count; i++){
        if (inventory[i].stock < 10) {
            cout << inventory[i].name << " - Stock: " << inventory[i].stock << endl;
            shown++;
            if (shown == n) break;
        }
    }
    if (shown == 0){
        cout << "No hay productos con stock menor a 10 unidades.\n";
    }
}

int main()
{
    Product inventory[100]; // Array para almacenar hasta 100 productos
    int productCount = 0;   // Número de productos actual
    int option;
    do
    {
        cout << "\n=== MENU ===\n";
        cout << "1. Agregar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Modificar cantidad de stock\n";
        cout << "4. Mostrar productos con stock bajo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            addProduct(inventory, productCount);
            break;
        case 2:
            deleteProduct(inventory, productCount);
            break;
        case 3:
            updateStock(inventory, productCount);
            break;
        case 4:
        {
            int toShow;
            cout << " Cuantos productos con menor stock desea ver: ";
            cin >> toShow;
            showLowStock(inventory, productCount, toShow);
            break;
        }
        case 5:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion inválida, intente nuevamente.\n";
        }
    } while (option != 5);

    return 0;
}