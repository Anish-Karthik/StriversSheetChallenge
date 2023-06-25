def rotateMatrix(a, n, m):
    for k in range(min(n,m)//2):
        st = a[k][k]
        for i in range(k, n-k-1):
            a[i][k] = a[i+1][k]
        for j in range(k, m-k-1):
            a[n-k-1][j] = a[n-k-1][j+1]

        for i in range(n-k-1, k, -1):
            a[i][m-k-1] = a[i-1][m-k-1]
        for j in range(m-k-1, k, -1):
            a[k][j] = a[k][j-1]
        a[k][k+1] = st
