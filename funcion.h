int leeropcionvalida (int min, int max);
void quitarsaltodelinea (char *cadena);\
void cargarDatosIniciales(char nombres[][50], int recursos[][5], float tiempo[], int inventario[5]);
void tablaproductos(char nombres[][50], int recursos[][5], float tiempo[], int *cantProductos);
void hacerpedidos (char nombres [][50], int recursos [][5], int inventario[5], float tiempo[], int cantProductos, char nombrerecursos[][50]);
int buscarProducto(char nombres[][50], int cantProductos, char buscar[]);
int editarproducto(char nombres[][50], float tiempo[], int recursos[][5], int *cantProductos, char nombrerecursos [][50]);
void buscarProductoManual(char nombres[][50], int recursos[][5], float tiempo[], int cantProductos);
void eliminarproducto(char nombres[][50], int recursos[][5], float tiempo[], int *cantProductos);
void Agregarproducto(char nombres[][50], int recursos [][5], float tiempo[], int *cantProductos, char nombrerecursos [][50]);
void agregarstock(int inventario[], char nombrerecursos[][50]);
void mostrarstock(int inventario[], char nombrerecursos[][50]);







