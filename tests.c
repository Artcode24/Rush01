#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rush01.h"

void	ft_free_grid(int **grid)
{
	for (int i = 0; i < 4; i++)
		free(grid[i]);
	free(grid);
}

int	**ft_create_grid(void)
{
	int **grid = malloc(sizeof(int *) * 4);
	if (!grid)
		return (NULL);

	for (int i = 0; i < 4; i++)
	{
		grid[i] = malloc(sizeof(int) * 4);
		if (!grid[i])
		{
			for (int j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}

	grid[0][0] = 1; grid[0][1] = 2; grid[0][2] = 3; grid[0][3] = 4;
	grid[1][0] = 2; grid[1][1] = 3; grid[1][2] = 4; grid[1][3] = 1;
	grid[2][0] = 3; grid[2][1] = 4; grid[2][2] = 1; grid[2][3] = 2;
	grid[3][0] = 4; grid[3][1] = 1; grid[3][2] = 2; grid[3][3] = 3;

	return (grid);
}

int	**ft_create_grid_false(void)
{
	int **grid = malloc(sizeof(int *) * 4);
	if (!grid)
		return (NULL);

	for (int i = 0; i < 4; i++)
	{
		grid[i] = malloc(sizeof(int) * 4);
		if (!grid[i])
		{
			for (int j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}

	grid[0][0] = 1; grid[0][1] = 2; grid[0][2] = 3; grid[0][3] = 4;
	grid[1][0] = 2; grid[1][1] = 3; grid[1][2] = 4; grid[1][3] = 1;
	grid[2][0] = 2; grid[2][1] = 4; grid[2][2] = 1; grid[2][3] = 2;
	grid[3][0] = 4; grid[3][1] = 1; grid[3][2] = 2; grid[3][3] = 3;

	return (grid);
}

int	**ft_create_grid_incomplete(void)
{
	int **grid = malloc(sizeof(int *) * 4);
	if (!grid)
		return (NULL);

	for (int i = 0; i < 4; i++)
	{
		grid[i] = malloc(sizeof(int) * 4);
		if (!grid[i])
		{
			for (int j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}

	grid[0][0] = 1; grid[0][1] = 2; grid[0][2] = 3; grid[0][3] = 4;
	grid[1][0] = 2; grid[1][1] = 3; grid[1][2] = 4; grid[1][3] = 1;

	return (grid);
}

void	test_factorial(void)
{
	if (ft_factorial(1) == 1)
		printf("ft_factorial :) OK - Expected (1) Returned (%d)\n", ft_factorial(1));
	else
		printf("ft_factorial :( KO - Expected (1) Returned %d\n", ft_factorial(1));
	if (ft_factorial(2) == 2)
		printf("ft_factorial :) OK - Expected (2) Returned (%d)\n", ft_factorial(2));
	else
		printf("ft_factorial :( KO - Expected (2) Returned %d\n", ft_factorial(2));
	if (ft_factorial(4) == 24)
		printf("ft_factorial :) OK - Expected (24) Returned (%d)\n", ft_factorial(4));
	else
		printf("ft_factorial :( KO - Expected (24) Returned %d\n", ft_factorial(4));
	if (ft_factorial(9) == 362880)
		printf("ft_factorial :) OK - Expected (362880) Returned (%d)\n", ft_factorial(9));
	else
		printf("ft_factorial :( KO - Expected (362880) Returned %d\n", ft_factorial(9));
}

void	test_calcul_left(void)
{
	int **grid = ft_create_grid();
	
	if (ft_calcul_left(grid, 4, 4, 0) == true)
		printf("ft_calcul_left :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_left(grid, 4, 2, 0) == false)
		printf("ft_calcul_left :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_left(grid, 4, 2, 2) == true)
		printf("ft_calcul_left :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_left(grid, 4, 3, 2) == false)
		printf("ft_calcul_left :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (FALSE) Returned (TRUE)\n");

	ft_free_grid(grid);
}

void	test_calcul_right(void)
{
	int **grid = ft_create_grid();
	
	if (ft_calcul_right(grid, 4, 1, 0) == true)
		printf("ft_calcul_right :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_right(grid, 4, 3, 0) == false)
		printf("ft_calcul_right :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_right(grid, 4, 2, 2) == true)
		printf("ft_calcul_right :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_right(grid, 4, 1, 2) == false)
		printf("ft_calcul_right :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (FALSE) Returned (TRUE)\n");

	ft_free_grid(grid);
}

void	test_calcul_up(void)
{
	// int **grid = ft_create_grid();
	int **grid = ft_create_grid_incomplete();
	int exp_up[] = {4, 3, 2, 1};
	int exp_up_false[] = {1, 4, 3, 2};
	
	if (ft_calcul_up(grid, 4, exp_up, 0) == true)
		printf("ft_calcul_up :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_up(grid, 4, exp_up_false, 3) == false)
		printf("ft_calcul_up :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_up(grid, 4, exp_up, 2) == true)
		printf("ft_calcul_up :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_up(grid, 4, exp_up_false, 3) == false)
		printf("ft_calcul_up :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (FALSE) Returned (TRUE)\n");

	ft_free_grid(grid);
}

void	test_calcul_down(void)
{
	// int **grid = ft_create_grid();
	int **grid = ft_create_grid_incomplete();
	int exp_down[] = {1, 2, 2, 2};
	int exp_down_false[] = {2, 4, 3, 1};
	
	if (ft_calcul_down(grid, 4, exp_down, 0) == true)
		printf("ft_calcul_down :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_down :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_down(grid, 4, exp_down_false, 3) == false)
		printf("ft_calcul_down :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_down :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_down(grid, 4, exp_down, 1) == true)
		printf("ft_calcul_down :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_down :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_down(grid, 4, exp_down_false, 3) == false)
		printf("ft_calcul_down :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_down :( KO - Expected (FALSE) Returned (TRUE)\n");

	ft_free_grid(grid);
}

void	test_check_repeat(void)
{
	int	**grid = ft_create_grid();
	int	**grid_false = ft_create_grid_false();

/* 	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", grid_false[i][j]);
		}
		printf("\n");
	} */

	if (ft_check_repeat(grid, 4, 2) == true)
		printf("ft_check_repeat :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_check_repeat :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_check_repeat(grid_false, 4, 2) == false)
		printf("ft_check_repeat :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_check_repeat :( KO - Expected (FALSE) Returned (TRUE)\n");

	ft_free_grid(grid);
	ft_free_grid(grid_false);
}

void	test_swap(void)
{
	int	a = 42;
	int	b = 24;

	ft_swap(&a, &b);

	if (a == 24 && b == 42)
		printf("ft_swap :) OK - Expected (a == 24, b == 42) Returned (a == %d, b == %d)\n", a, b);
	else
		printf("ft_swap :( KO - Expected (a == 24, b == 42) Returned (a == %d, b == %d)\n", a, b);

}

void	test_atoi(void)
{
	char c = '4';

	if (ft_atoi(c) == 4)
		printf("ft_atoi :) OK - Expected (4) Returned (%d)\n", ft_atoi(c));
	else
		printf("ft_atoi :( K0 - Expected (4) Returned (%d)\n", ft_atoi(c));
}

void	test_create_poss(void)
{
	int	**poss_grid = ft_malloc_poss(4);

	int	i = 0;
	int	charset[] = {1, 2, 3, 4};
	int	size = 4;

	ft_fill_poss(charset, poss_grid, &i, 0, size - 1);

	printf("possibilities :) KK\n");
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", poss_grid[i][j]);
		}
		printf(" - (%d)", i + 1);
		printf("\n");
	}
}

void	test_create_views(int argc, char *argv[])
{
	int	**views = ft_get_views(argc, argv);

	printf("possibilities :) KK\n");
 	for (int i = 0; i < (argc - 1) / 4; i++)
	{
		if (i == 0)
			printf("UP:    ");
		else if (i == 1)
			printf("DOWN:  ");
		else if (i == 2)
			printf("LEFT:  ");
		else if (i == 3)
			printf("RIGHT: ");

		for (int j = 0; j < (argc - 1) / 4; j++)
		{
			printf("%d ", views[i][j]);
		}
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	printf("\n");
	test_factorial();
	printf("\n");
	test_calcul_left();
	printf("\n");
	test_calcul_right();
	printf("\n");
	test_calcul_up();
	printf("\n");
	test_calcul_down();
	printf("\n");
	test_check_repeat();
	printf("\n");
	test_swap();
	printf("\n");
	test_atoi();
	printf("\n");
	test_create_poss();
	printf("\n");
	test_create_views(argc, argv);
	printf("\n");
}