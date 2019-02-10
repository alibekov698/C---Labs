#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char map[12][30];

void polygon() {
    srand((unsigned int) time(NULL));

    for(int r = 0; r < 12; r++) {
        for(int c = 0; c < 30; c++) {
            map[r][c] = '.';
        }
    }

    for(int mine = 0; mine < 10;) {
        int r = rand() % 12;
        int c = rand() % 30;
        if(map[r][c] == '.') {
            map[r][c] = '*';
            mine++;
        }
    }

}

void addProximities() {

    for(int r = 0; r < 12; r++) {
        for(int c = 0; c < 30; c++) {
            if(map[r][c] == '*') {
                if ((r >= 0 && r < 12) && (c+1 >= 0 && c+1 < 30)) {
                    map[r][c+1] = '1';
                }
                if((r >= 0 && r < 12) && (c-1 >= 0 && c-1 < 30)) {
                    map[r][c-1] = '1';
                }
                if((r-1 >= 0 && r-1 < 12) && (c >= 0 && c < 30)) {
                    map[r-1][c] = '1';
                }
                if((r+1 >= 0 && r+1 < 12) && (c >= 0 && c < 30)) {
                    map[r+1][c] = '1';
                }
                if((r-1 >= 0 && r-1 < 12) && (c-1 >= 0 && c-1 < 30)) {
                    map[r-1][c-1] = '1';
                }
                if((r+1 >= 0 && r+1 < 12) && (c-1 >= 0 && c-1 < 30)) {
                    map[r+1][c-1] = '1';
                }
                if((r-1 >= 0 && r-1 < 12) && (c+1 >= 0 && c+1 < 30)) {
                    map[r-1][c+1] = '1';
                }
                if((r+1 >= 0 && r+1 < 12) && (c+1 >= 0 && c+1 < 30)) {
                    map[r+1][c+1] = '1';
                }
            }
        }
    }

    for(int r = 0; r < 12; r++) {
        for(int c = 0; c < 30; c++) {
            if(map[r][c] == '1') {
                int count = 0;

                if ((r >= 0 && r < 12) && (c+1 >= 0 && c+1 < 30) && (map[r][c+1] == '*')) {
                    count++;
                }
                if((r >= 0 && r < 12) && (c-1 >= 0 && c-1 < 30) && (map[r][c-1] == '*')) {
                    count++;
                }
                if((r-1 >= 0 && r-1 < 12) && (c >= 0 && c < 30) && (map[r-1][c] == '*')) {
                    count++;
                }
                if((r+1 >= 0 && r+1 < 12) && (c >= 0 && c < 30) && (map[r+1][c] == '*')) {
                    count++;
                }
                if((r-1 >= 0 && r-1 < 12) && (c-1 >= 0 && c-1 < 30) && (map[r-1][c-1] == '*')) {
                    count++;
                }
                if((r+1 >= 0 && r+1 < 12) && (c-1 >= 0 && c-1 < 30) && (map[r+1][c-1] == '*')) {
                    count++;
                }
                if((r-1 >= 0 && r-1 < 12) && (c+1 >= 0 && c+1 < 30) && (map[r-1][c+1] == '*')) {
                    count++;
                }
                if((r+1 >= 0 && r+1 < 12) && (c+1 >= 0 && c+1 < 30) && (map[r+1][c+1] == '*')) {
                    count++;
                }
                map[r][c] = count + '0';
            }
        }

    }
}
 _Bool view[12][30];
int main () {
    polygon();
    addProximities();

    while(1){
        for(int r = 0; r < 12; r++) {
            for(int c = 0; c < 30; c++) {
                if(view[r][c])
                    printf("%c",map[r][c]);
                else
                    printf("%c",'?');
            }
            printf("\n");
        }
        int x,y;
        scanf("%i %i",&x,&y);
        view[x][y] = 1;
        if(map[x][y]=='*'){
            for(int r = 0; r < 12; r++) {
            for(int c = 0; c < 30; c++) {
                    printf("%c",map[r][c]);
            }
            printf("\n");
        }
            printf("BOOOOOM");
            break;
        }
    }
    return 0;
}
