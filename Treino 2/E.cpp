#include <stdio.h>

constexpr int maxN = 1e5+2;
int main() {
    FILE* fin = fopen("bcount.in", "r");

    int n, t, q, l, r;
    int prfx[maxN][3] = {{0}};

    fscanf(fin, "%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        fscanf(fin, "%d", &t);
        prfx[i][0] = prfx[i-1][0];
        prfx[i][1] = prfx[i-1][1];
        prfx[i][2] = prfx[i-1][2];
        prfx[i][t-1]++;
    }

    FILE* fout = fopen("bcount.out", "w");
    while(q--) {
        fscanf(fin, "%d%d", &l, &r);
        fprintf(fout, "%d %d %d\n", prfx[r][0]-prfx[l-1][0], prfx[r][1]-prfx[l-1][1], prfx[r][2]-prfx[l-1][2]);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}