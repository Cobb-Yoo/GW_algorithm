import java.util.Scanner;
import java.util.Random;

public class Life_20161501 {
        final private static int GRIDSIZE = 18;

        public static void main(String args[]) {
                boolean[][] board = new boolean[GRIDSIZE][GRIDSIZE];
                char choice;
                int x = 1;
                Scanner sc = new Scanner(System.in);

                do {
                        System.out.print("Start with a (r)andom board, the (q)ueen bee shuttle or the (g)lider pattern? ");
                        choice = sc.next().charAt(0);
                } while (choice != 'r' && choice != 'q' && choice != 'g');

                clearGrid(board);
                setup(board, choice);

                do {
                        System.out.printf("Viewing generation #%d:\n\n", x++);
                        displayGrid(board);
                        genNextGrid(board);
                        System.out.print("\n(q)uit or any other key + ENTER to continue: ");
                        choice = sc.next().charAt(0);
                } while (choice != 'q');
        }

        public static void setup(boolean[][] board, char which) {
                Random randomNumbers = new Random();

                clearGrid(board);

                if (which == 'q') {
                        board[5][1] = true;
                        board[5][2] = true;
                        board[6][3] = true;
                        board[7][4] = true;
                        board[8][4] = true;
                        board[9][4] = true;
                        board[10][3] = true;
                        board[11][2] = true;
                        board[11][1] = true;
                } else if (which == 'g') {
                        board[17][0] = true;
                        board[16][1] = true;
                        board[15][1] = true;
                        board[16][2] = true;
                        board[17][2] = true;
                } else {
                        for (int row = 0; row < board.length; row++) {
                                for (int col = 0; col < board[row].length; col++) {
                                        if (randomNumbers.nextInt() % 2 == 0)
                                                board[row][col] = true;
                                        }
                                }
                        }
                }

  public static void displayGrid(boolean[][] grid) {
                System.out.print("   ");
                for (int x = 1; x <= grid.length; x++) {
                        if ((x / 10) != 0)
                                System.out.printf("%d", x / 10);
                        else
                                System.out.print(" ");
                }

                System.out.println();
                System.out.print("   ");

                for (int x = 1;x <= grid.length;x++){
                        System.out.printf("%d",x%10);
                }
                System.out.println();

                for(int r =0;r < grid.length;r++){
                        System.out.printf("%d",r + 1);
                        if (r + 1 < 10)
                                System.out.print("  ");
                        else
                                System.out.print(" ");

                        for (int c = 0;c < grid.length;c++){
                                if(grid[r][c] == true)
                                        System.out.print("*");
                                else
                                        System.out.print(" ");
                        }
                        System.out.println();
                }
        }

        public static void clearGrid(boolean[][] grid) {
                int i,j;
                for(i=0;i<grid.length;i++) {
                        for(j=0;j<grid.length;j++){
                                grid[i][j] = false;
                        }
                }
        }


  public static void genNextGrid(boolean[][] grid) {
                boolean tmp [][] = new boolean [grid.length+2][grid.length+2];
                int i,j;
                int count;

                clearGrid(tmp);

                for(i=1;i<grid.length+1;i++){
                        for(j=1;j<grid.length+1;j++) {
                                tmp[i][j] = grid[i-1][j-1];
                        }
                }

                for(i=1;i<grid.length+1;i++) {
                        for(j=1;j<grid.length+1;j++){
                                count = countNeighbors(tmp,i,j);

                                if(tmp[i][j]) {
                                        if(count<=1) //lone
                                                grid[i-1][j-1] = false;
                                        else if (count >= 4) //over
                                                grid[i-1][j-1] = false;
                                }
                                else { //birth
                                        if(count == 3) grid[i-1][j-1] = true;
                                }
                        }
                }
        }

        public static int countNeighbors(final boolean[][] grid, final int row, final int col){
                int i,j;
                int count=0;

                for(i=row-1;i<=row+1;i++){
                        for(j=col-1;j<=col+1;j++){
                                if(grid[i][j]) count++;
                        }
                }

                if(grid[row][col]) count--;

                return count;
        }
}

