int min (int a, int b)
{
	return (a>b)?b:a;
}
int minfind(int a, int b, int c )
{
	return min(min(a,b), c);
}

int minDistanceDP(char *str1, char *str2, int m, int n, int **dp)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(dp[m-1][n-1] !=-1)
        return dp[m-1][n-1];

    if(str1[m-1]==str2[n-1])
        return dp[m-1][n-1]=minDistanceDP(str1, str2, m-1, n-1, dp);
    else
        return dp[m-1][n-1] = 1+ minfind(
                        minDistanceDP(str1, str2, m-1, n, dp),
                        minDistanceDP(str1, str2, m,   n-1, dp),
                        minDistanceDP(str1, str2, m-1, n-1, dp)
                        );
}
int minDistance(char* word1, char* word2)
{
    int row=strlen(word1);
    int col=strlen(word2);
    printf("%d..%d", row, col);

    int** dp = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
        dp[i] = (int*)malloc(col*sizeof(int));

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        {
            dp[i][j]=-1;
        }
    return  minDistanceDP(word1, word2, strlen(word1), strlen(word2), dp);
}