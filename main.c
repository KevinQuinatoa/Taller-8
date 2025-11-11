#include<stdio.h>
#include<string.h>

int leeropcionvalida();
int datosdeentrada (char nombreP [][50], float tiempoC [], int recursos [], int cantidad);
void tablaproductos (char nombreP[][50], float tiempoC [], int recursos [], int cantidad);
int editarproducto(char nombreP[][50], float tiempoC [], int recursos [], int cantidad);

int main(int argc, char const *argv[])
{
    char nombreP [5][50];
    int recursos[5];
    float tiempoC[5];
    int opcion;
    int cantidad=0;

do {
    printf("-------- menu ---------\n");
    printf("1. Ingrese los datos del producto\n");
    printf("2. Editar el producto\n");
    printf("3. Buscar el producto\n");
    printf("4. eliminar producto\n");
    printf("5. Agregar mas productos\n");
    printf("6. Tabla de productos\n");
    printf("7. Salir del programa\n");
    printf("Selecciones una opcion: ");
    opcion = leeropcionvalida();
    
    // controlador de las opciones
    if (opcion != 1 && opcion !=7 && cantidad ==0)
    {
        printf("Ingrese al menos un producto para poder seguir con esta opcion.\n");
        continue;
    }
    
    switch (opcion)
    {
    case 1:
        if (cantidad == 10) {
                printf("Ya se alcanzo el maximo de 5 productos.\n");
            } else {
                cantidad=datosdeentrada(nombreP, tiempoC, recursos, cantidad);
            }
        break;
    case 2:
        editarproducto(nombreP, tiempoC, recursos , cantidad);
        break;
    case 3:
        tablaproductos(nombreP, tiempoC, recursos , cantidad);
        
        break;
    case 4:
        
        break;
    case 5:
    if (cantidad < 10) {
                    cantidad=datosdeentrada(nombreP, tiempoC, recursos, cantidad);
                } else {
                    printf("Ya tiene el maximo de 5 productos.\n");
                }
                break;
        break;
    case 6:
        break;
    case 7:
        printf("saliendo del programa.....");
        return 0;
    default:
        break;
    }

} while(1);
    

    
    return 0;
}

int leeropcionvalida () {
    int numero;
    while (1)
    {
        if (scanf("%d", &numero) ==1 && numero>0 && numero<8)
        {
            while (getchar() != '\n');
            return numero;
            
        } else{
            printf("Error, dato invalido. Ingrese numeros mayor a 0 y menor que 8: ");
            while(getchar() != '\n');
        }  
    }  
}

int leeropcionvalida2 (){
    int numero2;
    while (1)
    {
        if (scanf("%d", &numero2) ==1 && numero2>0 && numero2<4)
        {
            while(getchar() != '\n');
            return numero2;
        } else {
            printf("Error, ingrese una opcion valida: ");
            while(getchar() != '\n');
        }
        
    }
    
}

int datosdeentrada (char nombreP [][50], float tiempoC [], int recursos [], int cantidad){
    int cantidadN;
    printf("Cuantos productos desea ingresar (maximo %d): ", 5-cantidad);
    
    while(scanf("%d", &cantidadN) !=1 || cantidadN<=0 || cantidadN>5 - cantidad){
        printf("Error, Ingrese un numero valido entre el 1 y %d: ", 5-cantidad);
        while(getchar() != '\n');
    }
    
    for (int i = cantidad; i < cantidad+cantidadN; i++)
    {
        int repetido;
        do {
            repetido=0;
            printf("Producto %d:\n", i+1);
            printf("Nombre: ");
            getchar();
            fgets(nombreP[i], sizeof(nombreP[i]), stdin);
            nombreP[i][strcspn(nombreP[i], "\n")] = '\0';
            for (int j = 0; j < i; j++)
            {
                if (strcmp(nombreP[i], nombreP[j]) ==0)
                {
                    printf("Error, el producto %s ya esta registrado\n", nombreP[i]);
                    repetido=1;
                    break;
                }
                
            }
            
        } while(repetido);
    printf ("Tiempo de fabricacion: ");
        while(scanf("%f", &tiempoC[i]) !=1 || tiempoC[i]<=0){
            printf("Tiempo invalido, ingrese un tiempo superior a 0: ");
            while(getchar() != '\n');
        }
    printf("Recursos de fabricacion: ");
        while (scanf("%d", &recursos[i]) !=1 || recursos[i]<0){
            printf("Error. ingrese un numero valido superior a 0: ");
            while(getchar() != '\n');
        }
    
    }
    printf("Productos registrados........\n");
    return cantidad + cantidadN;
}
void tablaproductos(char nombreP[][50], float tiempoC [], int recursos [], int cantidad){
    printf("--------------tabla de productos--------------\n");
    printf("nombre del producto\ttiempo de fabricacion\trecurso\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s\t\t%2.f\t\t\t%d\n", nombreP[i], tiempoC[i], recursos[i]);
    }
    
}
//se edita el nombre o le tiempo y recursos o todo el producto?
int editarproducto(char nombreP[][50], float tiempoC [], int recursos [], int cantidad){
    
    char buscar[50];
    int encontrado=0;
    tablaproductos(nombreP, tiempoC, recursos , cantidad);
    

    printf("Ingrese el nombre del producto que desea editar: ");
    fgets(buscar, sizeof(buscar), stdin);
            buscar[strcspn(buscar, "\n")] = '\0';
    for (int i = 0; i < cantidad; i++)
    {
        if (stricmp(nombreP[i], buscar) == 0)
        {
            printf("Producto %s encontrado\n", nombreP[i]);
            encontrado=1;
            int opcion2;
            
            
            printf("Que desea modificar\n");
            printf("1. Editar el nombre del producto\n");
            printf("2. Editar el tiempo de fabricacion\n");
            printf("3. Editar los recursos utilizados\n");
            printf("4. Todo el producto\n");
            printf("5. No editar nada\n");
            printf("Elija una opcion: ");
            opcion2 = leeropcionvalida2 ();

            switch (opcion2)
            {
            case 1:
                int repetido2;
                do{
                    repetido2=0;

                    printf("Nuevo nombre: ");
                    
                    fgets(nombreP[i], sizeof(nombreP[i]), stdin);
                    nombreP[i][strcspn(nombreP[i], "\n")] = '\0';

                    for (int j = 0; j < cantidad; j++){
                    if (strcmp(nombreP[i], nombreP[j]) ==0)
                    {
                        printf("Error, el producto %s ya esta registrado\n", nombreP[i]);
                        repetido2=1;
                        break;
                    }
                    
                }
                
                } while(repetido2);
                printf("Nombre actualizado correctamente");

                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("No se editara nada");
                break;
            
            default:
                printf("Opcion no valida\n");    
            break;
            }
        break;
        }
        
    }
    
    
    if (!encontrado)
    {
        printf("producto no encontrado.\n");
    }
    
}
