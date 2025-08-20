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

    private Cell[][] cells;
    private char[][] maze;

    private int mazeHeight;
    private int mazeWidth;

    private static final int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

    private static final char EMPTY_CELL = ' ';
    private static final char ENTRY_EXIT_ARROW = '⇨';
    private static final char HORIZONTAL_WALL = '─';
    private static final char VERTICAL_WALL = '│';

    private static final char[] OTHER_WALLS = {
            '└', // box drawings light up and right
            '┘', // box drawings light up and left
            '┴', // box drawings light up and horizontal
            '┌', // box drawings light down and right
            '┐', // box drawings light down and left
            '┬', // box drawings light down and horizontal
            '├', // box drawings light vertical and right
            '┤', // box drawings light vertical and left
            '┼', // box drawings light vertical and horizontal
    };

    private Random random;

    public char[][] generatePerfectMaze(int rows, int columns) {
        return generateMaze(rows, columns, new Random());
    }

    public char[][] generatePerfectMaze(int rows, int columns, int seed) {
        return generateMaze(rows, columns, new Random(seed));
    }

    private char[][] generateMaze(int rows, int columns, Random random){
        this.random = random;

        if (rows < 5 || rows > 100 || columns < 5 || columns > 100) {
            throw new IllegalArgumentException("Rows and columns must be between 5 and 100");
        }

        mazeHeight = cellToMazeCords(rows);
        mazeWidth = cellToMazeCords(columns);

        cells = new Cell[rows][columns];
        maze = getFilledMaze(rows, columns);

        Stack<Cell> cellStack = new Stack<>();

        for (int iY = 0; iY < rows; iY++) {
            for (int iX = 0; iX < columns; iX++) {
                cells[iY][iX] = new Cell(iX, iY);
            }
        }

        Cell currentCell = cells[this.random.nextInt(rows)][0];

        // Make exit
        maze[cellToMazeCords(currentCell.y)][mazeWidth - 1] = ENTRY_EXIT_ARROW;

        // Make entry
        currentCell = cells[this.random.nextInt(rows)][0];

        maze[cellToMazeCords(currentCell.y)][0] = ENTRY_EXIT_ARROW;
        maze[cellToMazeCords(currentCell.y)][1] = EMPTY_CELL;
        currentCell.visited = true;

        cellStack.push(currentCell);

        while (!cellStack.empty()) {
            currentCell = cellStack.pop();

            boolean hasUnvisitedNeighbours = false;
            for (int dir = 0; dir < 4; dir++) {
                hasUnvisitedNeighbours |= isUnvisitedNeighbour(currentCell, dir);
            }

            if (hasUnvisitedNeighbours) {
                cellStack.push(currentCell);
                Cell chosenCell = randomlyChooseUnvisitedNeighbour(currentCell);

                markAsVisitedAndRemoveTheWall(currentCell, chosenCell);

                cellStack.push(chosenCell);
            }
        }

        beautifyTheMaze();
        printTheMaze();

        return maze;
    }

    private boolean isUnvisitedNeighbour(Cell cell, int direction){
        final int x = cell.x,
                y = cell.y;

        final int rows = cells.length,
                columns = cells[0].length;

        switch (direction) {
            case UP -> {
                if (y - 1 >= 0)
                    return !cells[y - 1][x].visited;
            }

            case RIGHT -> {
                if (x + 1 < columns)
                    return !cells[y][x + 1].visited;
            }

            case DOWN -> {
                if (y + 1 < rows)
                    return !cells[y + 1][x].visited;
            }

            case LEFT -> {
                if (x - 1 >= 0)
                    return !cells[y][x - 1].visited;
            }

            default -> throw new IllegalArgumentException("Direction must be 0, 1, 2 or 3");
        }

        return false;
    }

    private Cell randomlyChooseUnvisitedNeighbour(Cell cell){
        // Randomly find unvisited neighbour
        int direction = this.random.nextInt(4);

        while (!isUnvisitedNeighbour(cell, direction))
            direction = this.random.nextInt(4);

        Cell chosenNeighbour = null;

        switch (direction){
            case UP -> chosenNeighbour = cells[cell.y - 1][cell.x];
            case RIGHT -> chosenNeighbour = cells[cell.y][cell.x + 1];
            case DOWN -> chosenNeighbour = cells[cell.y + 1][cell.x];
            case LEFT -> chosenNeighbour = cells[cell.y][cell.x - 1];
            default -> throw new IllegalArgumentException("Direction must be 0, 1, 2 or 3");
        }

        return chosenNeighbour;
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
        maze[0][0] = OTHER_WALLS[0];
        maze[0][widthChars - 1] = OTHER_WALLS[2];
        maze[heightChars - 1][0] = OTHER_WALLS[3];
        maze[heightChars - 1][widthChars - 1] = OTHER_WALLS[5];

        return maze;
    }

    private void markAsVisitedAndRemoveTheWall(Cell current, Cell chosen) {
        int currX = current.x, currY = current.y;
        int chosenX = chosen.x, chosenY = chosen.y;

        maze[(cellToMazeCords(currY) + cellToMazeCords(chosenY)) / 2]
                [(cellToMazeCords(currX) + cellToMazeCords(chosenX)) / 2] = EMPTY_CELL;

        maze[cellToMazeCords(chosenY)][cellToMazeCords(chosenX)] = EMPTY_CELL;

        chosen.visited = true;
    }

    private void beautifyTheMaze(){
        // Check possible places where OTHER_WALLS could be inserted
        for (int iY = 0; iY < mazeHeight; iY += 2) {
            for (int iX = 0; iX < mazeWidth; iX += 2) {
                maze[iY][iX] = determineWallBySurrounding(iX, iY);
            }
        }
    }

    private char determineWallBySurrounding(int x, int y){
        char wall = OTHER_WALLS[8];

        byte neighboursSum = 0;
        final byte topMask = 0b0001;
        final byte rightMask = 0b0010;
        final byte bottomMask = 0b0100;
        final byte leftMask = 0b1000;

        // 4 'if' statements:
        // if on top border, do not check top; and so on...
        if (y != 0) {
            neighboursSum |= maze[y - 1][x] == EMPTY_CELL ? 0 : topMask;
        }

        // if on right border, do not check right side;
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

        wall = switch (neighboursSum) {
            // only top neighbour; only bottom; vertical
            case 1, 4, 5 -> VERTICAL_WALL;

            // only right; only left; horizontal
            case 2, 8, 10 -> HORIZONTAL_WALL;

            // top and right
            case 3 -> OTHER_WALLS[0];

            // top and left
            case 9 -> OTHER_WALLS[1];

            // top and horizontal
            case 11 -> OTHER_WALLS[2];

            // bottom and right
            case 6 -> OTHER_WALLS[3];

            // bottom and left
            case 12 -> OTHER_WALLS[4];

            // bottom and horizontal
            case 14 -> OTHER_WALLS[5];

            // vertical and right
            case 7 -> OTHER_WALLS[6];

            // vertical and left
            case 13 -> OTHER_WALLS[7];

            // vertical and horizontal
            case 15 -> OTHER_WALLS[8];

            default -> wall;
        };

        return wall;
    }

    private int cellToMazeCords(int c){
        return 2 * c + 1;
    }

    private void printTheMaze(){
        StringBuffer buffer = new StringBuffer(mazeHeight * (mazeWidth + 1));

        for (char[] line: maze) {
            for (char c : line) {
                buffer.append(c);
            }

            buffer.append('\n');
        }

        buffer.deleteCharAt(buffer.length() - 1);

        System.out.println(buffer);
    }

    public static void main(String[] args) {
        MazeGenerator mg = new MazeGenerator();

        mg.generatePerfectMaze(5,5);
    }
}
