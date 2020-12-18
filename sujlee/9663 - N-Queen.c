#include <stdio.h>

int map[14][14] = {0, };
int ans = 0;
int N;

int isValid(int i, int cnt) { //유효성 검사
    int x, y;
    for (x = 0; x < cnt; x++) {
        if (map[i][x] == 1)
            return (0);
    }

    for (x = cnt - 1, y = i - 1; y >= 0; x--, y--) {
        if (map[y][x] == 1)
            return (0);
    }

    for (x = cnt - 1, y = i + 1; y < N; x--, y++) {
        if (map[y][x] == 1)
            return (0);
    }
    
    return (1);
}

void dfs(int cnt) {
    
    int i;

    if (cnt == N) {
        ans++;
        return;
    }
    for (i = 0; i < N; i++) {
        if (map[i][cnt] == 0 && isValid(i, cnt) == 1) {
            map[i][cnt] = 1;
            dfs(cnt+1);
            map[i][cnt] = 0;
        }
    }

}

int main() {

    scanf("%d", &N);
    dfs(0);
    printf("%d\n", ans);
    return 0;
}