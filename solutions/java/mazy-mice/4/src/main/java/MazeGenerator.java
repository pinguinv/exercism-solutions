import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Stack;

/**
 * Generating mazes with iterative backtracking algorithm
 */
public class MazeGenerator {

    private static class Cell {
        final int x;
        final int y;
        boolean visited = false;

        public Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private enum Direction {
        UP(0, -1),
        RIGHT(1, 0),
        DOWN(0, 1),
        LEFT(-1, 0);

        // Notes for me to remember:
        // you can always access private members of a nested type
        // from the containing type, thus no getters are needed
        private final int dx;
        private final int dy;

        Direction(int dx, int dy) {
            this.dx = dx;
            this.dy = dy;
        }
    }

    private Cell[][] cells;
    private char[][] maze;

    private int mazeHeight;
    private int mazeWidth;

    private static final char EMPTY_CELL = ' ';
    private static final char ENTRY_EXIT_ARROW = '⇨';
    private static final char HORIZONTAL_WALL = '─';
    private static final char VERTICAL_WALL = '│';

    private static final char[] POSSIBLE_WALLS = {
            '┼', // 0000 - no neighbours (impossible)
            '│', // 0001 - top
            '│', // 0010 - bottom
            '│', // 0011 - vertical
            '─', // 0100 - right
            '└', // 0101 - top and right
            '┌', // 0110 - bottom and right
            '├', // 0111 - vertical and right
            '─', // 1000 - left
            '┘', // 1001 - top and left
            '┐', // 1010 - bottom and left
            '┤', // 1011 - vertical and left
            '─', // 1100 - horizontal
            '┴', // 1101 - horizontal and top
            '┬', // 1110 - horizontal and bottom
            '┼', // 1111 - horizontal and vertical
    };

    public char[][] generatePerfectMaze(int rows, int columns) {
        return generateMaze(rows, columns, new Random());
    }

    public char[][] generatePerfectMaze(int rows, int columns, int seed) {
        return generateMaze(rows, columns, new Random(seed));
    }

    private char[][] generateMaze(int rows, int columns, Random random){
        if (rows < 5 || rows > 100 || columns < 5 || columns > 100) {
            throw new IllegalArgumentException("Rows and columns must be between 5 and 100");
        }

        mazeHeight = cellToMazeCoord(rows);
        mazeWidth = cellToMazeCoord(columns);

        cells = new Cell[rows][columns];
        maze = getFilledMaze(rows, columns);

        Stack<Cell> cellStack = new Stack<>();

        for (int iY = 0; iY < rows; iY++) {
            for (int iX = 0; iX < columns; iX++) {
                cells[iY][iX] = new Cell(iX, iY);
            }
        }

        Cell currentCell = cells[random.nextInt(rows)][0];

        // Make exit
        maze[cellToMazeCoord(currentCell.y)][mazeWidth - 1] = ENTRY_EXIT_ARROW;

        // Make entry
        currentCell = cells[random.nextInt(rows)][0];

        maze[cellToMazeCoord(currentCell.y)][0] = ENTRY_EXIT_ARROW;
        maze[cellToMazeCoord(currentCell.y)][1] = EMPTY_CELL;
        currentCell.visited = true;

        cellStack.push(currentCell);

        while (!cellStack.empty()) {
            currentCell = cellStack.pop();

            List<Cell> unvisitedNeighbours = getUnvisitedNeighbours(currentCell);

            if (!unvisitedNeighbours.isEmpty()) {
                cellStack.push(currentCell);

                // Randomly choose unvisited neighbour
                int randomIndex = random.nextInt(unvisitedNeighbours.size());

                Cell chosenCell = unvisitedNeighbours.get(randomIndex);

                markAsVisitedAndRemoveTheWall(currentCell, chosenCell);

                cellStack.push(chosenCell);
            }
        }

        beautifyTheMaze();

        return maze;
    }

    private boolean isUnvisitedNeighbour(Cell cell, Direction dir){
        final int x = cell.x,
                y = cell.y;

        final int rows = cells.length,
                columns = cells[0].length;

        // These two 'if' statements below check if index is in bounds
        switch (dir) {
            case UP, DOWN -> {
                if (y + dir.dy >= 0 && y + dir.dy < rows)
                    return !cells[y + dir.dy][x].visited;
            }

            case LEFT, RIGHT -> {
                if (x + dir.dx >= 0 && x + dir.dx < columns)
                    return !cells[y][x + dir.dx].visited;
            }
        }

        return false;
    }

    private List<Cell> getUnvisitedNeighbours(Cell cell){

        List<Cell> unvisitedNeighbours = new ArrayList<>();

        // This is brilliant
        for (Direction dir : Direction.values()){
            if (isUnvisitedNeighbour(cell, dir))
                unvisitedNeighbours.add(cells[cell.y + dir.dy][cell.x + dir.dx]);
        }

        return unvisitedNeighbours;
    }

    private char[][] getFilledMaze(int rows, int columns){
        int heightChars = 2 * rows + 1, widthChars = 2 * columns + 1;
        char[][] maze = new char[heightChars][widthChars];

        // Initially fill the inside of the maze with vertical walls
        for (int iY = 1; iY < heightChars - 1; iY++) {
            for (int iX = 0; iX < widthChars ; iX++) {
                maze[iY][iX] = VERTICAL_WALL;
            }
        }

        // Make horizontal walls of the maze
        for (int iY = 0; iY < heightChars; iY += 2) {
            for (int iX = 1; iX < widthChars - 1; iX++) {
                maze[iY][iX] = HORIZONTAL_WALL;
            }
        }

        // Corners
        maze[0][0] = POSSIBLE_WALLS[6];
        maze[0][widthChars - 1] = POSSIBLE_WALLS[10];
        maze[heightChars - 1][0] = POSSIBLE_WALLS[5];
        maze[heightChars - 1][widthChars - 1] = POSSIBLE_WALLS[9];

        return maze;
    }

    private void markAsVisitedAndRemoveTheWall(Cell current, Cell chosen) {
        int currX = current.x, currY = current.y;
        int chosenX = chosen.x, chosenY = chosen.y;

        maze[(cellToMazeCoord(currY) + cellToMazeCoord(chosenY)) / 2]
                [(cellToMazeCoord(currX) + cellToMazeCoord(chosenX)) / 2] = EMPTY_CELL;

        maze[cellToMazeCoord(chosenY)][cellToMazeCoord(chosenX)] = EMPTY_CELL;

        chosen.visited = true;
    }

    private void beautifyTheMaze(){
        // Check possible places where other walls could be inserted
        for (int iY = 0; iY < mazeHeight; iY += 2) {
            for (int iX = 0; iX < mazeWidth; iX += 2) {
                maze[iY][iX] = determineWallBySurrounding(iX, iY);
            }
        }
    }

    private char determineWallBySurrounding(int x, int y){
        
        byte neighboursSum = 0;
        final byte topMask = 0b0001;
        final byte bottomMask = 0b0010;
        final byte rightMask = 0b0100;
        final byte leftMask = 0b1000;

        // 4 'if' statements:
        // if on top border, do not check top;
        if (y != 0) {
            neighboursSum |= maze[y - 1][x] == EMPTY_CELL ? 0 : topMask;
        }

        // if on right border, do not check right side; and so on...
        if (x != mazeWidth - 1) {
            neighboursSum |= maze[y][x + 1] == EMPTY_CELL ? 0 : rightMask;
        }

        // bottom
        if (y != mazeHeight - 1) {
            neighboursSum |= maze[y + 1][x] == EMPTY_CELL ? 0 : bottomMask;
        }

        if (x != 0) {
            neighboursSum |= maze[y][x - 1] == EMPTY_CELL ? 0 : leftMask;
        }

        return POSSIBLE_WALLS[neighboursSum];
    }

    private int cellToMazeCoord(int c){
        return 2 * c + 1;
    }
}
