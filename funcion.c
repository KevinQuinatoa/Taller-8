#include<stdio.h>
#include<string.h>
#include"funcion.h"
int leeropcionvalida (int min, int max) {
    int numero;
    while (1)
    {
        if (scanf("%d", &numero) ==1 && numero >= min && numero <= max)
        {
            while (getchar() != '\n');
            return numero;
            
        } else{
            printf("Error, dato invalido. Ingrese numeros validos: ");
            while(getchar() != '\n');
        }  
    }  
}

//borrar el salto de linea
void quitarsaltodelinea (char *cadena){
     int len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}

void cargarDatosIniciales(char nombres[][50], int recursos[][5], float tiempo[], int inventario[5]) {

    // Producto 0: Smartphone
    strcpy(nombres[0], "Smartphone");
    recursos[0][0] = 1;  // pantalla
    recursos[0][1] = 1;  // bateria
    recursos[0][2] = 1;  // carcasa
    recursos[0][3] = 1;  // chip
    recursos[0][4] = 1;  // sensor
    tiempo[0] = 10;

    // Producto 1: Computadora
    strcpy(nombres[1], "Computadora");
    recursos[1][0] = 1;
    recursos[1][1] = 1;
    recursos[1][2] = 2;
    recursos[1][3] = 2;
    recursos[1][4] = 1;
    tiempo[1] = 15;

    // Producto 2: Ipad Pro
    strcpy(nombres[2], "Ipad Pro");
    recursos[2][0] = 1;
    recursos[2][1] = 1;
    recursos[2][2] = 1;
    recursos[2][3] = 1;
    recursos[2][4] = 1;
    tiempo[2] = 8;

    // Producto 3: Smartwatch
    strcpy(nombres[3], "Smartwatch");
    recursos[3][0] = 1;
    recursos[3][1] = 1;
    recursos[3][2] = 1;
    recursos[3][3] = 1;
    recursos[3][4] = 1;
    tiempo[3] = 5;

    // Producto 4: GAFAS VR
    strcpy(nombres[4], "Gafas VR");
    recursos[4][0] = 2;
    recursos[4][1] = 1;
    recursos[4][2] = 1;
    recursos[4][3] = 2;
    recursos[4][4] = 1;
    tiempo[4] = 12;

    // Inventario general
    inventario[0] = 100;  // pantallas
    inventario[1] = 120;  // baterías
    inventario[2] = 150;  // carcasas
    inventario[3] = 200;  // chips
    inventario[4] = 180;  // sensores
}


void tablaproductos(char nombres[][50], int recursos[][5], float tiempo[], int *cantProductos) {

    printf("\n-------------------------------- CATALOGO ------------------------------\n");
    printf("Producto\tPantallas\tBateria\tCarcasas\tChips\tSensores\tTiempo\n");

    for (int i = 0; i < *cantProductos; i++) {
        printf("%s\t\t%d\t%d\t%d\t\t%d\t\t%d\t%.2f min\n",
               nombres[i],
               recursos[i][0], recursos[i][1], recursos[i][2],
               recursos[i][3], recursos[i][4], tiempo[i]);
    }
    
    
}

void hacerpedidos (char nombres [][50], int recursos [][5], int inventario[5], float tiempo[], int cantProductos, char nombrerecursos[][50]){

    char buscar [50];
    int encontrado= -1;
    int dias, cantidad;

    tablaproductos(nombres, recursos, tiempo, &cantProductos);
    mostrarstock(inventario, nombrerecursos);

    printf("Ingrese el nombre del producto a elegir: ");
    fgets(buscar, 50, stdin);
    quitarsaltodelinea (buscar);

    for (int i = 0; i < cantProductos; i++)
    {
        if (strcmp(buscar, nombres[i]) ==0 ){
            encontrado=i;
            break;
        }
    }
    if (encontrado == -1){
        printf("Producto no encontrado\n");
        return;
    }

    printf("Ingrese la cantidad que desea ordenar: ");
    cantidad=leeropcionvalida(1, 999);
    printf("Ingrese el plazo de dias para la entrega: ");
    dias=leeropcionvalida(1,999);
    

    for (int r = 0; r < 5; r++)
    {
        int necesario = recursos[encontrado][r]*cantidad;
        if (necesario>inventario[r])
        {
            printf("Inventario insuficiente, cargar stock\n");
            return;
        }
        if (inventario[r]>necesario)
        {
            inventario[r]-=recursos[encontrado][r]*cantidad;
        }  
    }    
    float horas = tiempo[encontrado]*cantidad;
    float diasnecesarios=horas/24;

    if (diasnecesarios>dias)
    {
        printf("No se puede realizar el pedido en el tiempo colocado\n");
        return;
    }
    
    printf("Pedido registrado\n");
    printf("Tiempo total: %.2f minutos (%.2f dias)\n", horas, diasnecesarios);
}


//se edita el nombre o le tiempo y recursos o todo el producto?
int buscarProducto(char nombres[][50], int cantProductos, char buscar[]) {
    for (int i = 0; i < cantProductos; i++) {
        if (strcmp(nombres[i], buscar) == 0)
            return i;
    }
    return -1;
}

int editarproducto(char nombres[][50], float tiempo[], int recursos[][5], int *cantProductos, char nombrerecursos [][50]){
    
    char buscar[50];
    
     tablaproductos(nombres, recursos, tiempo, cantProductos);
    

    printf("Ingrese el nombre del producto que desea editar: ");
    fgets(buscar, sizeof(buscar), stdin);
        quitarsaltodelinea(buscar);
    int pos = buscarProducto(nombres, *cantProductos, buscar);

        if (pos == -1) {
            printf("Producto no encontrado.\n");
            return 0;
        }

        printf("\nProducto encontrado: %s\n", nombres[pos]);
            
            
            printf("Que desea modificar\n");
            printf("1. Editar el nombre del producto\n");
            printf("2. Editar el tiempo de fabricacion\n");
            printf("3. Editar los recursos utilizados\n");
            printf("4. Todo el producto\n");
            printf("5. No editar nada\n");
            printf("Elija una opcion: ");
            int opc2 = leeropcionvalida (1, 5);

            switch (opc2)
            {
            case 1:{
            printf("Nuevo nombre: ");
            fgets(nombres[pos], 50, stdin);
            quitarsaltodelinea(nombres[pos]);
            printf("Nombre actualizado.\n");
            } 
                break;
            case 2:
                printf("Nuevo tiempo de fabricacion: ");
                tiempo[pos]=leeropcionvalida(1, 999);
                
                printf("Tiempo actualizado.\n");
                break;
            case 3:
                printf("Ingrese los nuevos valores de recursos:\n");

                for (int i = 0; i < 5; i++) {
                    printf("%s: ", nombrerecursos[i]);
                    recursos[pos][i]=leeropcionvalida(1, 999);
                }

                
                break;
            case 4:
                printf("Nuevo nombre: ");
                fgets(nombres[pos], 50, stdin);
                quitarsaltodelinea(nombres[pos]);

                printf("Nuevo tiempo: ");
                tiempo[pos]=leeropcionvalida(1, 999);

                printf("Ingrese los nuevos valores de recursos:\n");

                for (int i = 0; i < 5; i++) {
                    printf("%s: ", nombrerecursos[i]);
                    recursos[pos][i]=leeropcionvalida(1, 999);
                }

            printf("Producto actualizado completamente.\n");
            break;

                break;
            case 5:
                printf("No se editara nada");
                break;
            
            default:
                printf("Opcion no valida\n");    
            break;

        }
        return 1;
    
}

void buscarProductoManual(char nombres[][50], int recursos[][5], float tiempo[], int cantProductos) {
    char buscar[50];

    printf("Ingrese el nombre del producto a buscar: ");
    fgets(buscar, 50, stdin);
    quitarsaltodelinea(buscar);

    int pos = buscarProducto(nombres, cantProductos, buscar);

    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("\n================ PRODUCTO ENCONTRADO ================\n");
    printf("Nombre: %s\n", nombres[pos]);

    printf("Recursos necesarios:\n");
    printf("  Pantallas: %d\n", recursos[pos][0]);
    printf("  Baterias:  %d\n", recursos[pos][1]);
    printf("  Carcasas:  %d\n", recursos[pos][2]);
    printf("  Chips:     %d\n", recursos[pos][3]);
    printf("  Sensores:  %d\n", recursos[pos][4]);

    printf("Tiempo de fabricacion: %.2f horas\n", tiempo[pos]);
}

void eliminarproducto(char nombres[][50], int recursos[][5], float tiempo[], int *cantProductos){
    tablaproductos(nombres, recursos, tiempo, cantProductos);
    char buscar[50];
    printf("Ingrese el nombre del producto a Eliminar: ");
    fgets(buscar, 50, stdin);
    quitarsaltodelinea(buscar);
    int min=buscarProducto(nombres, *cantProductos, buscar);
    if (min==-1)
    {
        printf("Producto no encontrado\n");
        return;
    }
    for (int i = min; i < *cantProductos - 1; i++){
        strcpy(nombres[i], nombres[i + 1]);
        tiempo[i] = tiempo[i + 1];

        for (int j = 0; j < 5; j++)
            recursos[i][j] = recursos[i + 1][j];
    }

    (*cantProductos)--;

    printf("Producto eliminado.\n");
}

void Agregarproducto(char nombres[][50], int recursos [][5], float tiempo[], int *cantProductos, char nombrerecursos [][50]){
    if (*cantProductos >= 5){
        printf("No se puede ingresas mas productos, limite (5)\n");
        return;
    }
    char nuevoproducto [50];
    int existe;
    printf("Ingrese el nombre del producto: ");
    fgets(nuevoproducto, 50, stdin);
    quitarsaltodelinea(nuevoproducto);

    existe=buscarProducto(nombres, *cantProductos, nuevoproducto);

    if (existe!=-1)
    {
        printf("El producto ya existe\n");
        return;
    }

    strcpy(nombres[*cantProductos], nuevoproducto);

    printf("Ingrese el tiempo de elaboracion en minutos: ");
    tiempo[*cantProductos]= leeropcionvalida(1,999);

    printf("Ingrese los recursos que se necesitaran para la elaboracion\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: ", nombrerecursos[i]);
        recursos[*cantProductos][i]= leeropcionvalida(1, 999);
    }
    
    (*cantProductos)++;
    printf("Producto ingresado correctamente\n");
    

}

void agregarstock(int inventario[], char nombrerecursos[][50]){
    int aumentarI;
    printf("Ingrese la cantidad de stock que desea aumentar\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: ", nombrerecursos[i]);
        aumentarI=leeropcionvalida(1, 999);
        inventario[i]+=aumentarI;
    }
    printf("Stock actuializado correctamente........\n");
    mostrarstock(inventario, nombrerecursos);
}
void mostrarstock(int inventario[], char nombrerecursos[][50]) {
    printf("\n================ INVENTARIO ACTUAL ================\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d\n", nombrerecursos[i], inventario[i]);
    }
    printf("====================================================\n");
}
