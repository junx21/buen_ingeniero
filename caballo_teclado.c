#include <stdio.h>

// Definimos los movimientos válidos del caballo en un teclado numérico
int movements[10][3] = {
    {4, 6, -1},   // Movimientos válidos desde el 0
    {6, 8, -1},   // Movimientos válidos desde el 1
    {7, 9, -1},   // Movimientos válidos desde el 2
    {4, 8, -1},   // Movimientos válidos desde el 3
    {3, 9, 0},    // Movimientos válidos desde el 4
    {-1, -1, -1}, // 5 no tiene movimientos válidos
    {1, 7, 0},    // Movimientos válidos desde el 6
    {2, 6, -1},   // Movimientos válidos desde el 7
    {1, 3, -1},   // Movimientos válidos desde el 8
    {2, 4, -1}    // Movimientos válidos desde el 9
};

// Función que calcula el número de movimientos válidos recursivamente
int valid_moves(int start, int moves_remaining) {
    // Caso base: si no quedan más movimientos, hemos llegado a una posibilidad válida
    if (moves_remaining == 0) {
        return 1;
    }

    int total_moves = 0;

    // Recorremos los posibles movimientos desde la posición actual
    for (int i = 0; i < 3 && movements[start][i] != -1; i++) {
        total_moves += valid_moves(movements[start][i], moves_remaining - 1);
    }

    return total_moves;
}

int main() {
    int total_movements = 0;
    int moves = 18; // Cambia este valor para calcular diferentes movimientos

    // Sumamos los movimientos válidos desde todas las posiciones del teclado
    for (int i = 0; i < 10; i++) {
        total_movements += valid_moves(i, moves);
    }

    // Imprimimos el resultado total
    printf("Movimientos válidos con %d movimientos: %d\n", moves, total_movements);

    return 0;
}
