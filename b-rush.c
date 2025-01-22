#include <stdio.h>
#include <stdlib.h>

#define SIZE 4 // Taille de la grille

// Contraintes de visibilité
int col_up[SIZE], col_down[SIZE], row_left[SIZE], row_right[SIZE];

void init_grid(int **grid) 
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void print_grid(int **grid) 
{
	for (int i = 0; i < SIZE; i++)
	{
		
		for (int j = 0; j < SIZE; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

int	calcul_left(int **grid, int row)
{
	int temp = grid[row][0];
	int view_count;

	if (temp > 0)
		view_count = 1;
	else
		view_count = 0;

	for (int i = 1; i < SIZE; i++)
	{
		if ((temp < grid[row][i]))
		{
			view_count++;
			temp = grid[row][i];
		}
	}

	if (view_count > row_left[row])
		return (0);
	if ((view_count != row_left[row]) && (row == SIZE - 1))
		return (0);
	return (1);
}

int	calcul_right(int **grid, int row)
{
	int temp = grid[row][SIZE - 1];
	int view_count;

	if (temp > 0)
		view_count = 1;
	else
		view_count = 0;

	for (int i = SIZE - 2; i <= 0; i--)
	{
		if ((temp < grid[row][i]))
		{
			view_count++;
			temp = grid[row][i];
		}
	}

	if ((view_count != row_right[row]) && (row == SIZE - 1))
		return (0);
	return (1);
}

int is_valid(int **grid, int row, int col, int value) 
{
	// Vérifier unicité dans la ligne
	for (int j = 0; j < SIZE; j++) 
	{
		if (grid[row][j] == value)
			return (0);
	}

	// Vérifier unicité dans la colonne
	for (int i = 0; i < SIZE; i++) 
	{
		if (grid[i][col] == value)
			return (0);
	}

	return (1);
}

// Backtracking pour remplir la grille
int solve(int **grid, int row, int col) 
{
	// Si on atteint la fin de la grille, la solution est trouvée
	if (row == SIZE) 
		return (1);

	// Passer à la ligne suivante si on dépasse la dernière colonne
	int next_row = (col == SIZE - 1) ? row + 1 : row;
	int next_col = (col == SIZE - 1) ? 0 : col + 1;

	// Si la case est déjà remplie, continuer
	if (grid[row][col] != 0)
		return solve(grid, next_row, next_col);

	// Essayer toutes les valeurs possibles (1 à 4)
	for (int value = 1; value <= SIZE; value++) 
	{
		if (is_valid(grid, row, col, value)) 
		{
			grid[row][col] = value; // Placer la valeur
			if (solve(grid, next_row, next_col)) 
				return (1); // Continuer
			grid[row][col] = 0; // Annuler si ça ne fonctionne pas
		}
	}

	return (0); // Aucune solution trouvée
}

// Exemple d'exécution
int main() 
{
	int **grid;

	grid = malloc(sizeof(int *) * 4);

	for (int i = 0; i < 4; i++)
	{
		grid[i] = malloc(sizeof(int) * 4);
	}

	// Initialiser la grille
	init_grid(grid);

	// Définir des contraintes (par exemple)
	col_up[0] = 4; col_up[1] = 3; col_up[2] = 2; col_up[3] = 1;
	col_down[0] = 1; col_down[1] = 2; col_down[2] = 2; col_down[3] = 2;
	row_left[0] = 4; row_left[1] = 3; row_left[2] = 2; row_left[3] = 1;
	row_right[0] = 1; row_right[1] = 2; row_right[2] = 2; row_right[3] = 2;

	if (solve(grid, 0, 0))
		print_grid(grid);
	else
		printf("Erreur : pas de solution trouvée\n");

	return (0);
}