//#include "flood_fill.h"

// fill -> It takes the 2d array, size of the array, the current point to be filled, and the char that needs to be replaced
// 1. Check if the current point is invalid (out of bounds, doesnt match the char to be replaced)
// 2. Return if true (ending recusion)
// 3. Else, update char at current point to 'F'
// 4. Call fill recursively for the neighbor points: left, right, up, down

// Why is to_fill tab[begin.y][begin.x] and not tab[begin.x][begin.y]
// Regarding 2. Why is cur.y/x = size.y/x out of bounds, why is the point being at the bottom row or at the rightmost column out of bounds?
// Why does the return under 'if (cur.y < 0....)' have no value?
// Why do we need to write (t_point) before changing the value of the coordinates of the current point?

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_point
{
	int		x;
	int		y;
}			t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);	
}

// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

// int main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char**  area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point begin = {7, 4};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }
