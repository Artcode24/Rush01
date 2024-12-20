#ifndef RUSH01_H
 #define RUSH01_H

int	ft_calcul_left(int **grid, int size_hor, int exp_left, int current_row);
int	ft_calcul_right(int **grid, int size_hor, int exp_right, int current_row);
int	ft_calcul_up(int **grid, int size_hor, int exp_up[], int current_row);
int	ft_calcul_down(int **grid, int size_hor, int exp_down[], int current_row);
int	ft_check_repeat(int **grid, int size_hor, int current_row);
int	ft_check_all(int **grid, int size_hor, int current_row, int exp_left, int exp_right, int exp_up[], int exp_down[]);
void	ft_swap(int *a, int *b);
int	ft_factorial(int nb);
void	ft_fill_poss(int charset[], int **poss, int *i, int l, int r);
int	**ft_malloc_poss(int size);
int	**ft_malloc_grid(int grid_size);
int	**ft_malloc_views(int argc);
int	ft_atoi(int nb);
int	**ft_get_views(int argc, char *argv[]);

#endif // RUSH01_H