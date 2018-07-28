#define _XOPEN_SOURCE 500
#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define DIM_MIN 3
#define DIM_MAX 9
int gameboard[DIM_MAX][DIM_MAX];
int d;
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }
    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }
    // greet user with instructions
    greet();
    // initialize the board
    init();
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();
        // draw the current state of the board
        draw();
        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", gameboard[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }
        // prompt for move
        printf("Tile to move: ");
        int tile =get_int();
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }
        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);
        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(50000);
        }
        // sleep thread for animation's sake
        usleep(50000);
    }
    // close log
    fclose(file);
    // success
    return 0;
}
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(1000000);
}
void init(void)
{
    int c=(d*d)-1;
    for(int i=0;i<d;++i)
    {
        for(int j=0;j<d;++j)
        {
            gameboard[i][j]=c;
            --c;
        }
    }
    if(((d*d))%2==0)
    {
        gameboard[d-1][d-3]=1;
        gameboard[d-1][d-2]=2;
    }
}
void draw(void)
{
    int j=0;
    for(int i=0;i<d;++i)
    {
        for(j=0;j<d;++j)
        {if(gameboard[i][j]==0)
        printf("_");
        else
        {
            printf("%d", gameboard[i][j]);
            printf("  ");
        }
        }
        printf("\n");
    }
}
bool move(int c)
{
    int cell_i=0;int cell_j=0;
    for(int i=0;i<d;++i)
    {
        for(int j=0;j<d;++j)
        {
            if(gameboard[i][j]==c)
            {
            cell_i=i;
            cell_j=j;
            }
        }
    }
    if (cell_i-1 >= 0 && gameboard[cell_i-1][cell_j] == 0)
    {
    gameboard[cell_i-1][cell_j] = gameboard[cell_i][cell_j];
    gameboard[cell_i][cell_j] = 0;
    return true;
    }
    else if (cell_i+1<d && gameboard[cell_i+1][cell_j] == 0)
    {
    gameboard[cell_i+1][cell_j]=gameboard[cell_i][cell_j];
    gameboard[cell_i][cell_j]=0;
    return true;
    }
    else if (cell_j-1 >= 0 && gameboard[cell_i][cell_j-1]== 0)
    {
    gameboard[cell_i][cell_j-1] = gameboard[cell_i][cell_j];
    gameboard[cell_i][cell_j] = 0;
    return true;
    }
    else if (cell_j+1< d && gameboard[cell_i][cell_j+1]==0)
    {
    gameboard[cell_i][cell_j+1] = gameboard[cell_i][cell_j];
    gameboard[cell_i][cell_j] = 0;
    return true;
    }
    printf("invalid move");
    return false;
        }
        bool won(void)
        {
            int arrtmp[d*d];
            int count=0;
            for(int i=0;i<d;++i)
                    {
                        for(int j=0;j<d;++j)
                        {
                            gameboard[i][j]=arrtmp[count];
                            ++count;
                        }
                    }
                    for(int i=0;i<(d*d)-1;++i)
                    {
                        if(arrtmp[i]==arrtmp[i+1]+1)
                        continue;
                        else
                        return false;
                    }
                    return true;
                        }
