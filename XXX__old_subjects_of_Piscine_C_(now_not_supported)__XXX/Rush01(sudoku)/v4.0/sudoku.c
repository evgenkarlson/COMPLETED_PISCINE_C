#include "header.h"

// N is used for size of Sudoku grid. Size will be NxN
#define GRID_SIZE 9

#define TRUE 1

#define FALSE 0

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED_VALUE 0

int		display_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

// allocate memory for the grid
int		**alloc_sudoku(void)
{
	int row;
	int col;
	int **grid;

	row = 0;
	grid = (int **)malloc(sizeof(int *) * 9);
	while (row < 9)
	{
		grid[row] = (int *)malloc(sizeof(int) * 9);
		col = 0;
		while (col < 9)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	return (grid);
}

// free memory
void	free_sudoku_memory(int **grid)
{
	int row;

	row = 0;
	while (row < GRID_SIZE)
	{
		free(grid[row]);
		row++;
	}
	free(grid);
}

// This function finds an entry in grid that is still unassigned
int find_unassigned_place(int **grid, int *row, int *col);

// Checks whether it will be legal to assign num to the given row,col
int can_assign_num(int **grid, int row, int col, int num);

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
int solve_sudoku(int **grid)
{
    int *row = malloc(sizeof(int));
	int *col = malloc(sizeof(int));
	int num;

    // If there is no unassigned location, we are done
    if (!find_unassigned_place(grid, row, col))
       return 1; // success!
    // consider digits 1 to 9
	num = 1;
	while (num <= 9) {
		if (can_assign_num(grid, *row, *col, num) == TRUE)
        {
            // make tentative assignment
            grid[*row][*col] = num;

            // return, if success, yay!
            if (solve_sudoku(grid) == TRUE)
                return TRUE;

            // failure, unmake & try again
            grid[*row][*col] = UNASSIGNED_VALUE;
        }
		num++;
	}
    return 0; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
int find_unassigned_place(int **grid, int *row, int *col)
{
	while (*row < GRID_SIZE)
	{
		while (*col < GRID_SIZE)
		{
			if (grid[*row][*col] == UNASSIGNED_VALUE)
                return TRUE;
			*col = *col + 1;
		}
		*row = *row + 1;
		*col = 0;
	}
    return FALSE;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
int has_row_number(int **grid, int row, int num)
{
	int col;

	col = 0;

	while (col < GRID_SIZE)
	{
		if (grid[row][col] == num)
		{
			return TRUE;
		}
		col++;
	}
    return FALSE;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
int has_col_number(int **grid, int col, int num)
{
	int row;

	row = 0;
	while (row < GRID_SIZE)
	{
		if (grid[row][col] == num)
            return TRUE;
		row++;
	}
    return FALSE;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
int has_box_number(int **grid, int box_start_row, int box_start_col, int num)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < 3)
	{
		while (col < 3)
		{
			if (grid[row+box_start_row][col+box_start_col] == num)
                return TRUE;
			col++;
		}
		row++;
		col = 0;
	}
    return FALSE;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
int can_assign_num(int **grid, int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !has_row_number(grid, row, num) &&
           !has_col_number(grid, col, num) &&
           !has_box_number(grid, row - row % 3 , col - col % 3, num);
}

void print_sudoku(int **grid)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < GRID_SIZE)
	{
		while (col < GRID_SIZE)
		{
			// print space is it's not a last column
			if (col == 8)
				ft_putnbr(grid[row][col]);
			else
			{
				ft_putnbr(grid[row][col]);
				ft_putchar(' ');
			}
			col++;
		}
		row++;
		col = 0;
		ft_putchar('\n');
	}
}

// check if the proposed number can be placed into this row/col
int		can_put_number(int **grid, int current_number, int row, int col)
{
	int i;
	int row_start;
	int col_start;

	i = 0;
	row_start = (row / 3) * 3;
	col_start = (col / 3) * 3;
	while (i < 9)
	{
		if (grid[row][i] == current_number)
			return (0);
		if (grid[i][col] == current_number)
			return (0);
		if (grid[row_start + (i % 3)][col_start + (i / 3)] == current_number)
			return (0);
		i++;
	}
	return (1);
}

// populate grid with 1-9 or 0 if it's a dot using arguments passed to the program
int		populate_sudoku(int **grid, int size, char **str)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (str[i + 1][j])
		{
			if (str[i + 1][j] == '.')
				grid[i][j] = 0;
			else if (str[i + 1][j] >= '0' && str[i + 1][j] <= '9')
				if (can_put_number(grid, str[i + 1][j] - 48, i, j))
					grid[i][j] = str[i + 1][j] - 48;
				else
					return (display_error());
			else
				return (display_error());
			j++;
		}
		if (j != 9)
			return (display_error());
		i++;
	}
	return TRUE;
}

int		main(int argc, char **argv)
{
	int **grid;

	grid = alloc_sudoku();

	if (argc != 10)
		return (display_error());

	if (!populate_sudoku(grid, argc, argv))
		return (0);

    // // 0 means unassigned cells
    if (solve_sudoku(grid) == TRUE) {
		print_sudoku(grid);
	}
    else
        display_error();
	free_sudoku_memory(grid);
    return 0;
}

// from pdf
// ./rush-1 "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."

// 9 1 4 3 7 5 2 6 8
// 2 8 7 4 9 6 1 5 3
// 3 6 5 8 1 2 4 7 9
// 8 4 6 5 2 1 3 9 7
// 5 2 9 6 3 7 8 1 4
// 7 3 1 9 8 4 5 2 6
// 1 5 3 7 4 9 6 8 2
// 6 9 8 2 5 3 7 4 1
// 4 7 2 1 6 8 9 3 5




// simple
// ./rush-1 "......82." ".5.2.9673" "7....8..1" "3...42.18" ".1.835264" "...6....." "23....9.7" "..1....8." "5........"

// 1 9 3 4 6 7 8 2 5
// 4 5 8 2 1 9 6 7 3
// 7 2 6 3 5 8 4 9 1
// 3 6 5 9 4 2 7 1 8
// 9 1 7 8 3 5 2 6 4
// 8 4 2 6 7 1 5 3 9
// 2 3 4 1 8 6 9 5 7
// 6 7 1 5 9 4 3 8 2
// 5 8 9 7 2 3 1 4 6




// hard
// ./rush-1 "........." "2..6.1..5" "..42.39.." ".31...85." "6..7.5..9" ".85...47." "..65.92.." "4..1.6..7" "........."

// 5 6 3 8 9 7 1 2 4
// 2 9 8 6 4 1 7 3 5
// 1 7 4 2 5 3 9 6 8
// 7 3 1 9 6 4 8 5 2
// 6 4 2 7 8 5 3 1 9
// 9 8 5 3 1 2 4 7 6
// 8 1 6 5 7 9 2 4 3
// 4 2 9 1 3 6 5 8 7
// 3 5 7 4 2 8 6 9 1