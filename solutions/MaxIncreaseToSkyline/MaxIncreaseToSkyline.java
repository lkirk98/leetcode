import java.util.Arrays;

/*
In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well. 

At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

Notes:

    1 < grid.length = grid[0].length <= 50.
    All heights grid[i][j] are in the range [0, 100].
    All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.


*/
public class MaxIncreaseToSkyline {

	final private static int CITY_SIZE = 4;
	
	public static int maxIncreaseKeepingSkyline (int[][] grid) {
		/* Keeping track of the max height of buildings when looking at the
		 * city from a certain direction. Keeps from accessing the grid
		 * as often when growing buildings.
		 */
		int[] vertical_heights = new int[CITY_SIZE];
		int[] horizontal_heights = new int[CITY_SIZE];
		
		for(int i = 0; i < CITY_SIZE; i++) {
			vertical_heights[i] = findMaxVerticalHeight(grid, i);
			horizontal_heights[i] = findMaxHorizontalHeight(grid, i);
		}
		
        int growth = 0;
        
        /* Now finding maximum growth */
        for(int i = 0; i < CITY_SIZE; i++) {
        	for(int j = 0; j < CITY_SIZE; j++) {
        		int building = grid[i][j];
        		
        		/* Finding the smallest size of building in
        		 * building's skyline
        		 */
        		int min_skyline = vertical_heights[j];
        		if(horizontal_heights[i] < min_skyline)
        			min_skyline = horizontal_heights[i];
        		
        		/* updating the building and tracking growth */
        		if (building < min_skyline) {
        			grid[i][j] = min_skyline;
        			growth += min_skyline - building;
        		}
        	}
        }
        
        return growth;
    }
	
	/* 
	 * Returns the maximum height of a building at an index,
	 * looking horizontally at the city
	 */
	private static int findMaxHorizontalHeight (int[][] grid, int index) {
		int max = 0;
		
		for (int i = 0; i < CITY_SIZE; i++)
			if (grid[index][i] > max) max = grid[index][i];
		
		
		return max;
	}
	
	/* 
	 * Returns the maximum height of a building at an index,
	 * looking vertically at the city
	 */
	private static int findMaxVerticalHeight (int[][] grid, int index) {
		int max = 0;
		
		for (int i = 0; i < CITY_SIZE; i++)
			if (grid[i][index] > max) max = grid[i][index];
		
		
		return max;
	}

}
