#include <stdio.h>

#define SIZE 4 // Taille de la grille

// Structure pour une cellule
typedef struct s_cell {
    int value; // Valeur de la case (0 si vide)
} t_cell;

// Déclaration de la grille
t_cell grid[SIZE][SIZE];

// Contraintes de visibilité
int col_up[SIZE], col_down[SIZE], row_left[SIZE], row_right[SIZE];

// Initialisation de la grille
void init_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j].value = 0; // Toutes les cases vides au départ
        }
    }
}

// Fonction pour afficher la grille
void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j].value);
        }
        printf("\n");
    }
}

// Vérifie si une valeur peut être placée dans une case
int is_valid(int row, int col, int value) {
    // Vérifier unicité dans la ligne
    for (int j = 0; j < SIZE; j++) {
        if (grid[row][j].value == value) {
            return 0; // La valeur existe déjà dans la ligne
        }
    }

    // Vérifier unicité dans la colonne
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col].value == value) {
            return 0; // La valeur existe déjà dans la colonne
        }
    }

    // Ajouter ici la vérification des contraintes de visibilité
    // Exemple : vérifier si le nombre de caisses visibles respecte col_up ou row_left
    // ...

    return 1; // La valeur est valide
}

// Backtracking pour remplir la grille
int solve(int row, int col) {
    // Si on atteint la fin de la grille, la solution est trouvée
    if (row == SIZE) return 1;

    // Passer à la ligne suivante si on dépasse la dernière colonne
    int next_row = (col == SIZE - 1) ? row + 1 : row;
    int next_col = (col == SIZE - 1) ? 0 : col + 1;

    // Si la case est déjà remplie, continuer
    if (grid[row][col].value != 0) {
        return solve(next_row, next_col);
    }

    // Essayer toutes les valeurs possibles (1 à 4)
    for (int value = 1; value <= SIZE; value++) {
        if (is_valid(row, col, value)) {
            grid[row][col].value = value; // Placer la valeur
            if (solve(next_row, next_col)) return 1; // Continuer
            grid[row][col].value = 0; // Annuler si ça ne fonctionne pas
        }
    }

    return 0; // Aucune solution trouvée
}

// Exemple d'exécution
int main() {
    // Initialiser la grille
    init_grid();

    // Définir des contraintes (par exemple)
    col_up[0] = 4; col_up[1] = 3; col_up[2] = 2; col_up[3] = 1;
    col_down[0] = 1; col_down[1] = 2; col_down[2] = 2; col_down[3] = 2;
    row_left[0] = 4; row_left[1] = 3; row_left[2] = 2; row_left[3] = 1;
    row_right[0] = 1; row_right[1] = 2; row_right[2] = 2; row_right[3] = 2;

    // Résoudre la grille
    if (solve(0, 0)) {
        print_grid(); // Afficher la solution
    } else {
        printf("Erreur : pas de solution trouvée\n");
    }

    return 0;
}
