#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stdexcept>

using namespace std;

/**
 * @brief Parsea una línea de entrada para extraer el objetivo de las luces y los esquemas de los botones.
 * @param line La línea completa del manual.
 * @param target Vector de 0s y 1s para el estado objetivo de las luces.
 * @param buttons Matriz de índices de luces controladas por cada botón.
 */
void parse_line(const string& line, vector<int>& target, vector<vector<int>>& buttons) {
    // 1. Parsear el diagrama de luces [...]
    size_t start_lights = line.find('[');
    size_t end_lights = line.find(']');
    if (start_lights == string::npos || end_lights == string::npos || end_lights <= start_lights) {
        throw runtime_error("Error de parseo: No se encontró el diagrama de luces.");
    }
    string lights_str = line.substr(start_lights + 1, end_lights - start_lights - 1);
    
    target.clear();
    for (char c : lights_str) {
        if (c == '#') target.push_back(1);
        else if (c == '.') target.push_back(0);
    }

    // 2. Parsear los esquemas de botones (...)
    buttons.clear();
    size_t current_pos = end_lights + 1;
    while (current_pos < line.length()) {
        size_t start_button = line.find('(', current_pos);
        if (start_button == string::npos) break;
        
        // CORRECCIÓN: Usar size_t en lugar de sizeize_t
        size_t end_button = line.find(')', start_button);
        
        if (end_button == string::npos) break;
        
        string button_str = line.substr(start_button + 1, end_button - start_button - 1);
        
        vector<int> current_button;
        stringstream ss(button_str);
        string segment;
        
        while (getline(ss, segment, ',')) {
            // Eliminar espacios en blanco y parsear el índice
            segment.erase(remove(segment.begin(), segment.end(), ' '), segment.end());
            if (!segment.empty()) {
                try {
                    current_button.push_back(stoi(segment)); 
                } catch (...) {
                    // Ignorar errores de conversión si el segmento es basura
                }
            }
        }
        buttons.push_back(current_button);
        current_pos = end_button + 1;
    }
}

/**
 * @brief Resuelve el sistema Ax = T sobre F_2 y encuentra la solución con el mínimo peso de Hamming.
 * @param target El vector T (estado objetivo).
 * @param buttons La lista de botones para construir la matriz A.
 * @return El número mínimo de pulsaciones, o -1 si no hay solución.
 */
int solve_machine(const vector<int>& target, const vector<vector<int>>& buttons) {
    int N = target.size(); // Número de luces (filas)
    int M = buttons.size(); // Número de botones (variables, columnas)

    // Si no hay luces o botones, la respuesta es 0
    if (N == 0) {
        return 0;
    }
    if (M == 0 && any_of(target.begin(), target.end(), [](int x){ return x != 0; })) {
        // Si hay luces encendidas requeridas, pero no hay botones, es imposible.
        return -1;
    }

    // Construir la matriz aumentada [A | T]
    vector<vector<int>> augmented_matrix(N, vector<int>(M + 1, 0));

    for (int i = 0; i < N; ++i) { // Luces (filas)
        augmented_matrix[i][M] = target[i]; // Columna de destino T
        
        for (int j = 0; j < M; ++j) { // Botones (columnas)
            for (int light_index : buttons[j]) {
                if (light_index >= 0 && light_index < N && light_index == i) {
                    augmented_matrix[i][j] = 1; 
                    break;
                }
            }
        }
    }
    
    // 

    // --- Eliminación Gaussiana (sobre F_2) ---

    int pivot_row = 0;
    vector<int> pivot_col_to_row(M, -1); 

    for (int j = 0; j < M && pivot_row < N; ++j) { // Iterar sobre columnas (botones/variables)
        
        // 1. Encontrar un pivote (un '1' debajo o en la fila del pivote actual)
        int pivot_i = -1;
        for (int i = pivot_row; i < N; ++i) {
            if (augmented_matrix[i][j] == 1) {
                pivot_i = i;
                break;
            }
        }

        if (pivot_i != -1) {
            // 2. Intercambiar filas para llevar el pivote a la posición (pivot_row, j)
            if (pivot_i != pivot_row) {
                swap(augmented_matrix[pivot_row], augmented_matrix[pivot_i]);
            }

            pivot_col_to_row[j] = pivot_row;
            
            // 3. Eliminar otros unos en la columna (XOR, tanto arriba como abajo)
            for (int i = 0; i < N; ++i) {
                if (i != pivot_row && augmented_matrix[i][j] == 1) {
                    // F_i = F_i XOR F_pivot_row
                    for (int k = j; k <= M; ++k) {
                        augmented_matrix[i][k] ^= augmented_matrix[pivot_row][k];
                    }
                }
            }
            
            pivot_row++;
        }
    }

    // --- Verificar Consistencia y Variables Libres ---

    // 1. Verificar inconsistencia (0 0 ... 0 | 1)
    for (int i = pivot_row; i < N; ++i) {
        // Solo necesitamos verificar la columna T, ya que la EG garantiza que A[i][0..M-1] es cero.
        if (augmented_matrix[i][M] == 1) {
            return -1; // No hay solución
        }
    }
    
    // 2. Identificar variables libres (columnas sin pivote)
    vector<int> free_vars;
    vector<int> pivot_vars;
    for (int j = 0; j < M; ++j) {
        if (pivot_col_to_row[j] == -1) {
            free_vars.push_back(j);
        } else {
            pivot_vars.push_back(j);
        }
    }

    int V = free_vars.size(); // Número de variables libres
    int min_presses = M + 1; 
    
    // Advertencia de rendimiento si V es muy grande (ej. > 25)
    if (V > 25) {
        cerr << "ADVERTENCIA: Alto número de variables libres (V=" << V << "). El cálculo puede ser extremadamente lento (O(2^V))." << endl;
    }

    // --- Encontrar la Solución con Mínimo Peso de Hamming (Iteración 2^V) ---
    
    // Solución particular (x_p): todas las variables libres son 0
    vector<int> x_p(M, 0);
    for(int j : pivot_vars) {
        x_p[j] = augmented_matrix[pivot_col_to_row[j]][M];
    }
    
    // Vectores base del espacio nulo (h_k)
    vector<vector<int>> null_space_bases(V, vector<int>(M, 0));
    for (int k = 0; k < V; ++k) {
        int free_j = free_vars[k];
        null_space_bases[k][free_j] = 1; 
        
        // Calcular el valor de las variables pivote
        for (int j : pivot_vars) {
            int i = pivot_col_to_row[j];
            int sum = 0;
            // La fila de pivote i establece x_j + sum(A[i][l] * x_l) = 0 (para bases nulas)
            for (int l : free_vars) {
                // A[i][l] es el coeficiente del libre 'l' en la ecuación del pivote 'j'
                sum ^= (augmented_matrix[i][l] * null_space_bases[k][l]);
            }
            null_space_bases[k][j] = sum;
        }
    }
    
    // Iterar sobre las 2^V combinaciones de coeficientes (c_k)
    // x = x_p + sum(c_k * h_k) mod 2
    for (int i = 0; i < (1 << V); ++i) {
        vector<int> current_x = x_p; 

        // Sumar la combinación lineal de los vectores base
        for (int k = 0; k < V; ++k) {
            if ((i >> k) & 1) { // Si el k-ésimo bit es 1 (c_k = 1)
                for (int j = 0; j < M; ++j) {
                    current_x[j] ^= null_space_bases[k][j]; // Suma mod 2 (XOR)
                }
            }
        }
        
        // Calcular el peso de Hamming (mínimo número de pulsaciones)
        int current_presses = 0;
        for (int val : current_x) {
            current_presses += val;
        }

        min_presses = min(min_presses, current_presses);
    }
    
    return min_presses;
}

/**
 * @brief Función principal para procesar todas las máquinas.
 */
int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total_min_presses = 0;
    int machine_count = 0;

    cout << "--- Solucionador de Inicialización de Máquinas ---" << endl;

    // Leer la entrada línea por línea (redirigida desde un archivo .txt)
    while (getline(cin, line)) {
        if (line.empty() || line.find('[') == string::npos) continue; // Ignorar líneas vacías o sin diagrama

        vector<int> target;
        vector<vector<int>> buttons;

        try {
            machine_count++;
            
            // 1. Parsear la línea
            parse_line(line, target, buttons);
            
            if (target.empty()) {
                cerr << "Error: Máquina " << machine_count << " no tiene luces definidas." << endl;
                continue;
            }

            // 2. Resolver la máquina individual
            int min_presses = solve_machine(target, buttons);

            // 3. Acumular el resultado
            if (min_presses == -1) {
                cerr << "Máquina " << machine_count << ": Objetivo imposible de alcanzar. Ignorando." << endl;
            } else {
                total_min_presses += min_presses;
                // Si quieres ver los resultados intermedios, descomenta la siguiente línea:
                /*
                cout << "Máquina " << machine_count << " (Luces: " << target.size() 
                     << ", Botones: " << buttons.size() << "): " 
                     << min_presses << " pulsaciones." << endl;
                */
            }

        } catch (const runtime_error& e) {
            cerr << "Error al procesar línea de máquina " << machine_count << ": " << line.substr(0, min(line.length(), 60UL)) << "..." << endl;
            cerr << "Detalle: " << e.what() << endl;
        } catch (...) {
             cerr << "Error desconocido al procesar la máquina " << machine_count << "." << endl;
        }
    }

    cout << "\n--- Resultado Final ---" << endl;
    cout << "Máquinas procesadas: " << machine_count << endl;
    cout << "El total mínimo de pulsaciones requerido para todas las máquinas es: " << total_min_presses << endl;

    return 0;
}