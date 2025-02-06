#include <iostream>
#include <stdio.h>
#define MAX 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

struct Articulo {
    int codigo;
    float precio;
    char nombre[50];
    int cantidad;
};

struct Articulo inventario[MAX];
int numArticulos = 0;

void agregarArticulo() {
    printf("\nAGREGAR ARTICULO\n");
    printf("Ingrese codigo: ");
    scanf("%d", &inventario[numArticulos].codigo);
    
    printf("Ingrese precio: ");
    scanf("%f", &inventario[numArticulos].precio);
    
    printf("Ingrese el nombre: ");
    scanf(" %[^\n]", inventario[numArticulos].nombre);
    
    printf("Cantidad: ");
    scanf("%d", &inventario[numArticulos].cantidad);
    
    numArticulos++;
}

void facturar() {
    int codigo, cantidad;
    float subtotal = 0, iva = 0, total = 0;
    
    printf("\nFACTURAR\n");
    printf("Ingrese codigo: ");
    scanf("%d", &codigo);
    
    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);
    
    // Buscar artículo y calcular factura
    for(int i = 0; i < numArticulos; i++) {
        if(inventario[i].codigo == codigo) {
            if(cantidad <= inventario[i].cantidad) {
                subtotal = cantidad * inventario[i].precio;
                iva = subtotal * 0.13;
                total = subtotal + iva;
                inventario[i].cantidad -= cantidad;
                
                printf("\nSubtotal: %.2f\n", subtotal);
                printf("IVA: %.2f\n", iva);
                printf("Total: %.2f\n", total);
            } else {
                printf("No hay suficiente cantidad disponible\n");
            }
            break;
        }
    }
}

void reporteFaltantes() {
    printf("\nREPORTE DE FALTANTES\n");
    for(int i = 0; i < numArticulos; i++) {
        printf("Codigo: %d, Cantidad disponible: %d\n", 
               inventario[i].codigo, 
               inventario[i].cantidad);
    }
}

int main() {
    int opcion;
    
    do {
        printf("\n1. Agregar articulo");
        printf("\n2. Facturar");
        printf("\n3. Reporte faltantes");
        printf("\n4. Salir");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1: agregarArticulo(); break;
            case 2: facturar(); break;
            case 3: reporteFaltantes(); break;
        }
    } while(opcion != 4);
    
    return 0;
}
}
