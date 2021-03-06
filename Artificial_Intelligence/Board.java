//Brian Ryan K00202212 Assignment 1 Artificial Intelligence April 2017
import java.util.ArrayList;

public class Board
{
    private int N;
    private int[][] blocks;

    public Board(int[][] blocks)
    {
    // construct a board from an N-by-N array of blocks
    // (where blocks[i][j] = block in row i, column j)
        N = blocks[0].length;
        this.blocks = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                this.blocks[i][j] = blocks[i][j];
            }
        }
    }

    public int dimension()
    {
    // board dimension N
        return N;
    }

    public int hamming()
    {
    // number of blocks out of place
        int error = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (blocks[i][j] != i*N + j + 1 && blocks[i][j] != 0) {
                    error += 1;
                }
            }
        }
        return error;
    }

    public int manhattan()
    {
    // sum of Manhattan distances between blocks and goal
        int error = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (blocks[i][j] != 0)
                {
                    int rowSteps = (blocks[i][j] - 1)/N;
                    int colSteps = (blocks[i][j] - 1) % N;
                    error += Math.abs(rowSteps - i) + Math.abs(colSteps - j);
                }
            }
        }
        return error;
    }

    public boolean isGoal()
    {
    // is this board the goal board?
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (blocks[i][j] != i*N + j + 1 && (i != N - 1 || j != N - 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    public Board twin()
    {
    // a board that is obtained by exchanging two adjacent blocks in the same row
        Board newBoard = new Board(blocks);
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = N - 2; j >= 0; j--)
            {
                if (newBoard.blocks[i][j] != 0 && newBoard.blocks[i][j + 1] != 0)
                {
                    newBoard.exch(i, j, i, j + 1);
                    return newBoard;
                }
            }
        }
        return null;
    }

    public boolean equals(Object y)
    {
    // does this board equal y?
        if (y == this) return true;
        if (y == null) return false;
        if (y.getClass() != this.getClass()) return false;
        Board that = (Board) y;
        if (that.blocks.length != N || that.blocks[0].length != N)
        {
            return false;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (this.blocks[i][j] != that.blocks[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    public Iterable<Board> neighbors()
    {
    // all neighbouring boards
        if (N < 2)
        {
            return null;
        }
        ArrayList<Board> boards = new ArrayList<Board>();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (blocks[i][j] == 0)
                {
                    if (j > 0)
                    {
                        boards.add(getNeighbor(i, j, i, j - 1));
                    }
                    if (j < N - 1)
                    {
                        boards.add(getNeighbor(i, j, i, j + 1));
                    }
                    if (i > 0) {
                        boards.add(getNeighbor(i, j, i - 1, j));
                    }
                    if (i < N - 1)
                    {
                        boards.add(getNeighbor(i, j, i + 1, j));
                    }
                    return boards;
                }
            }
        }
        return null;
    }

    private void exch(int i0, int j0, int i, int j)
    {
        int temp = blocks[i0][j0];
        blocks[i0][j0] = blocks[i][j];
        blocks[i][j] = temp;
    }

    private Board getNeighbor(int i0, int j0, int i, int j)
    {
        Board newBoard = new Board(blocks);
        newBoard.exch(i0, j0, i, j);
        return newBoard;
    }

    public String toString()
    {
    // string representation of this board
        String s = "" + N + "\n";
        for (int i = 0; i < N; i++)
        {
            s += " ";
            for (int j = 0; j < N; j++)
            {
                s += blocks[i][j] + "  ";
            }
            s += "\n";
        }
        return s;
    }
}
