// http://users.ece.cmu.edu/~eno/coding/CCodingStandard.html

#include <stdio.h>
#include <string.h>

int main(void) {
    
    int myArray[3][4][2][5] =
    {
        {
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            }
        },
        {
            
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            }
        },
        {
            
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            },
            {
                {0, 1, 2, 3, 4},{0, 1, 2, 3, 4}
            }
        }
    };
    
    int i, j, k, l;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 2; k++) {
                for (l = 0; l < 5; l++) {
                    printf("myArray[%d][%d][%d][%d] = %d\n", i, j, k, l, myArray[i][j][k][l]);
                }
            }
        }
    }
	
    return 0;
}
