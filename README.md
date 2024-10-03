# Cálculo de Movimientos Válidos del Caballo en un Teclado Numérico

Para encontrar una fórmula matemática que calcule el número de movimientos válidos del caballo en un teclado numérico, primero debemos reconocer que el problema es más adecuado para resolverse usando técnicas de programación dinámica o recursión. Sin embargo, podemos aproximarnos a una **relación de recurrencia**, que es una expresión matemática que define una secuencia en función de términos anteriores.

Dado que los movimientos del caballo dependen de la posición actual y el número de movimientos restantes, es difícil encontrar una fórmula cerrada que calcule el número exacto de movimientos válidos sin recurrir a un proceso iterativo o recursivo. Sin embargo, podemos definir el problema como sigue:

## Relación de recurrencia

Sea `M(i, k)` la cantidad de trayectorias válidas comenzando desde el número `i` y con `k` movimientos restantes.

- **Condición base**: Si `k = 0`, es decir, si no quedan movimientos por hacer, entonces hay exactamente 1 camino válido (el que no se mueve):

  \[
  M(i, 0) = 1
  \]

- **Relación recursiva**: Si quedan `k > 0` movimientos, la cantidad de trayectorias válidas desde `i` con `k` movimientos restantes es la suma de todas las trayectorias posibles desde los números a los que el caballo puede moverse, con `k-1` movimientos restantes. Esto se expresa como:

  \[
  M(i, k) = \sum_{j \in vecinos(i)} M(j, k - 1)
  \]

  donde `vecinos(i)` representa los números a los que el caballo puede moverse desde `i`.

## Definición de vecinos

Los vecinos de cada número en el teclado numérico están predefinidos como:

- `vecinos(1) = [6, 8]`
- `vecinos(2) = [7, 9]`
- `vecinos(3) = [4, 8]`
- `vecinos(4) = [3, 9, 0]`
- `vecinos(5) = []`
- `vecinos(6) = [1, 7, 0]`
- `vecinos(7) = [2, 6]`
- `vecinos(8) = [1, 3]`
- `vecinos(9) = [2, 4]`
- `vecinos(0) = [4, 6]`

## Cálculo total de movimientos válidos

La cantidad total de movimientos válidos para `k` movimientos es la suma de todas las trayectorias posibles comenzando desde cualquier número del teclado:

\[
T(k) = \sum_{i = 0}^{9} M(i, k)
\]

### Ejemplo con 1 movimiento:

Para `k = 1`:

\[
T(1) = M(0, 1) + M(1, 1) + ⋯ + M(9, 1)
\]

Ya que cada `M(i, 1)` es simplemente el número de vecinos de `i`, la suma da un total de 20 trayectorias válidas.

## Conclusión

No existe una fórmula cerrada simple para este problema porque el número de trayectorias válidas depende de las posiciones y movimientos del caballo, que forman una red interconectada. Sin embargo, la relación de recurrencia:

\[
M(i, k) = \sum_{j \in vecinos(i)} M(j, k - 1)
\]

es la clave para calcular el número de trayectorias válidas para cualquier cantidad de movimientos `k`.

Para resolver el problema de manera eficiente, es necesario implementar esta recurrencia utilizando **programación dinámica** o recursión con **memoización**.