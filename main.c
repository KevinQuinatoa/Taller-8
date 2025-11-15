#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcion.h"

int main(void) {
    char nombres[5][50];
    int recursos[5][5];
    float tiempo[5];
    int inventario[5];
    int cantProductos = 5;    // tienes 5 productos precargados
    int opcion;
    char nombrerecursos[5][50] = {
    "Pantallas",
    "Baterias",
    "Carcasas",
    "Chips",
    "Sensores"
    };

    // Carga los datos iniciales (nombres, recursos por producto, tiempos e inventario)
    cargarDatosIniciales(nombres, recursos, tiempo, inventario);

    do {
        printf("\n-------- menu ---------\n");
        printf("1. Ingrese los datos del pedido\n");
        printf("2. Editar el producto\n");
        printf("3. Buscar el producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Agregar producto\n");
        printf("6. Agregar mas Stock\n");
        printf("7. Tabla de productos\n");
        printf("8. Salir del programa\n");
        printf("Seleccione una opcion: ");
        opcion = leeropcionvalida(1, 8);

        // Control: algunas opciones requieren que haya productos cargados
        if (opcion != 5 && opcion != 8 && cantProductos == 0) {
            printf("Ingrese al menos un producto para poder seguir con esta opcion.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                hacerpedidos (nombres, recursos, inventario, tiempo, cantProductos, nombrerecursos);
                break;

            case 2:
                // Editar producto (nombre / recursos / tiempo)
                editarproducto(nombres, tiempo, recursos, &cantProductos, nombrerecursos);
                break;

            case 3:
                // Buscar producto
                buscarProductoManual(nombres, recursos, tiempo, cantProductos);
                break;

            case 4:
                // Eliminar producto 
                eliminarproducto(nombres, recursos, tiempo, &cantProductos);
                break;

            case 5:
                // Agregar mas productos
                Agregarproducto(nombres, recursos, tiempo, &cantProductos, nombrerecursos);
                break;

            case 6:
                // Agregar stock
                agregarstock(inventario, nombrerecursos);
                break;

            case 7:
                // Mostrar tabla de productos
                tablaproductos(nombres, recursos, tiempo, &cantProductos);
                break;

            case 8:
                printf("Saliendo del programa.....\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }

    } while (opcion != 8);
    return 0;
}

