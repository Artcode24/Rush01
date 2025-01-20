#include <stdio.h>
#include <stdlib.h>

int	ft_calcul_left(int **grid, int size, int exp_left, int current_row)
{
	int	i;
	int	temp;
	int	view_count;

	i = 0;
	temp = grid[current_row][0];
	view_count = 1;
	while (i < size)
	{
		if (temp < grid[current_row][i])
		{
			view_count++;
			temp = grid[current_row][i];
		}
		i++;
		
	}
	
	if (view_count == exp_left)
	{
		// printf("OK : Ligne %d, attendu %d, trouvé %d - at poss %d \n", current_row, exp_left, view_count, k);
		return (1);
	}
	else
	{
		// printf("Rejeté : Ligne %d, attendu %d, trouvé %d\n", current_row, exp_left, view_count);
		return(0);
	}
}

int	ft_calcul_right(int **grid, int size, int exp_right, int current_row)
{
	int	i;
	int	temp;
	int	view_count;

	i = size - 1;
	temp = grid[current_row][size - 1];
	view_count = 1;
	while (i >= 0)
	{
		if (temp < grid[current_row][i])
		{
			view_count++;
			temp = grid[current_row][i];
		}
		i--;
	}
	
	if (view_count == exp_right)	
	{
		// printf("OK : Ligne %d, attendu %d, trouvé %d - at poss %d \n", current_row, exp_right, view_count, k);
		return (1);
	}
	else
		return(0);
}

int	ft_calcul_up(int **grid, int size, int exp_up[], int current_row)
{
	int	temp;
	int	view_count;

	for (int col = 0; col < size; col++)
	{
		view_count = 1;
		temp = grid[0][col];
		for (int row = 0; row <= current_row; row++)
		{
			if (temp < grid[row][col])
			{
				view_count++;
				temp = grid[row][col];
			}
		}
		if (view_count > exp_up[col])
			return (0);
		if (current_row == size - 1 && view_count != exp_up[col])
			return (0);
	}
	return (1);
}

int	ft_calcul_down(int **grid, int size, int exp_down[], int current_row)
{
	int	row;
	int	col;
	int	view_count;
	int	temp;

	col = 0;
	while (col < size)
	{
		view_count = 1;
		temp = grid[current_row][col];
		row = current_row - 1;
		while (row >= 0)
		{
			if (temp < grid[row][col])
			{
				view_count++;
				temp = grid[row][col];	
			}
			row--;
		}
		if (view_count > exp_down[col])
			return (0);
		if (current_row == size - 1 && view_count != exp_down[col])
			return (0);
		col++;	
	}


	return (1);
}

int	ft_check_repeat(int **grid, int size, int current_row)
{
	int	row;
	int	col;
	
	col = 0;
	while (col < size)
	{
		row = 0;
		while (row < current_row)
		{
			if (grid[current_row][col] == grid[row][col])
				return (0);
			row++;
		}
		col++;
	}
	
	return (1);
}

int	ft_check_all(int **grid, int size_hor, int current_row, int exp_left, int exp_right, int exp_up[], int exp_down[])
{
	if (!(ft_calcul_left(grid, size_hor, exp_left, current_row)))
		return (0);
	if (!(ft_calcul_right(grid, size_hor, exp_right, current_row)))
		return (0);
	if (!(ft_calcul_up(grid, size_hor, exp_up, current_row)))
		return (0);
	// if (!(ft_calcul_down(grid, size_hor, exp_down, current_row)))
	// 	return (0);
	if (!(ft_check_repeat(grid, size_hor, current_row)))
		return (0);
	return (1);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_factorial(int nb)
{
	if (nb == 1)
		return (1);
	else
		return (nb * ft_factorial(nb - 1));
}

int	**ft_malloc_poss(int size)
{
	int	**poss_grid;
	int	nb_poss;
	int	i;
	int	j;
	
	nb_poss = ft_factorial(size);
	poss_grid = malloc(nb_poss * sizeof(int *));
	if (!poss_grid)
		return (NULL);

	i = 0;
	while (i < nb_poss)
	{
		poss_grid[i] = malloc(size * sizeof(int));
  		if (!poss_grid[i])
		{
			j = 0;
			while (j < i)
				free(poss_grid[j++]);
			free(poss_grid);
			return (NULL);
		}
		i++;
	}
	return (poss_grid);
}

void	ft_fill_poss(int charset[], int **poss_grid, int *i, int l, int r)
{
	int	j;

	if (l == r)
	{
		j = 0;
		while (j < 4)
		{
			poss_grid[*i][j] = charset[j];
			j++;
		}
		(*i)++;
	}
	else
	{
		j = l;
		while (j <= r)
		{
			ft_swap(&charset[l], &charset[j]);
			ft_fill_poss(charset, poss_grid, i, l + 1, r);
			ft_swap(&charset[l], &charset[j]);
			j++;
		}
	}
}

int	**ft_malloc_grid(int grid_size)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc(grid_size * sizeof(int *));
	if (!grid)
		return (NULL);

	i = 0;
	while (i < grid_size)
	{
		grid[i] = malloc(grid_size * sizeof(int));
		if (!grid[i])
		{
			j = 0;
			while (j < i)
				free(grid[j++]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

int	**ft_malloc_views(int size)
{
	int	**views;
	int	i;
	int	j;

	views = malloc(size * sizeof(int *));
	if (!views)
		return (NULL);

	i = 0;
	j = 0;
	while (i < size)
	{
		views[i] = malloc(size * sizeof(int));
		if (!views[i])
		{
			while (j < i)
			{
				free(views[j++]);
			}
			free(views);
			return (NULL);
		}
		i++;
	}
	return (views);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}

int	ft_count_words(char *argv_1)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (argv_1[i])
	{
		if (argv_1[i] != ' ' && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (argv_1[i] == ' ')
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, int start, int end)
{
	char	*dest;
	int		i;

	dest = malloc((end - start) + 2);
	i = 0;
	while (start <= end)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *argv_1)
{
	int	i;
	int	j;
	int	start;
	char	**strs;


	i = 0;
	j = 0;
	start = 0;
	strs = malloc(ft_count_words(argv_1) * sizeof(char *));
	while (argv_1[i])
	{
		if (argv_1[i] == ' ' && i > start)
		{
			if (i > start)
				strs[j++] = ft_strdup(argv_1, start, i - 1);
			start = i + 1;
		}
		else if (argv_1[i] == ' ')
			start = i + 1;
		i++;
	}
	if (i > start && argv_1[i - 1] != ' ')
		strs[j++] = ft_strdup(argv_1, start, i - 1);
	return (strs);
}

int	**ft_get_views(char *argv_1)
{
	int	**views;
	char	**arr;
	int	count;
	int	i;
	int	j;
	int	n;

	count = ft_count_words(argv_1);
	views = ft_malloc_views((count / 4) * sizeof(int *));
	arr = ft_split(argv_1);
	
	i = 0;
	n = 0;
	while (i < (count / 4))
	{
		j = 0;
		while (j < (count / 4))
		{
			views[i][j] = ft_atoi(arr[n]);
			n++;
			j++;
		}
		i++;
	}
	return (views);
}

int	main(int argc, char *argv[])
{
	int	charset[] = {1, 2, 3, 4};
	int	nb_of_views;
	int	size;
	int	**poss;
	int	**grid;
	int	**views;

	nb_of_views = ft_count_words(argv[1]);

	size = nb_of_views / 4;
	
	grid = ft_malloc_grid(size);
	poss = ft_malloc_poss(size);
	views = ft_get_views(argv[1]);
	
	int	i = 0;
	ft_fill_poss(charset, poss, &i, 0, size - 1);
	
	int m = 0;
	for (int i = 0; i < 4; i++) // On parcours chaque ligne de la grille
	{				
		int k = m;
		do
		{
			for (int j = 0; j < 4; j++)
				grid[i][j] = poss[k][j];
			k++;
		} while (!ft_check_all(grid, size, i, views[2][i], views[3][i], views[0], views[1]) && k < 24);
		if (k >= 25)
		{
			m++;
			i = 0;
			continue;
		}
	}

 	// Affiche la grille
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}