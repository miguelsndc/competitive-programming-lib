/*
    Exponenciacao Rapida de Matrizes  O(m³ log (b))
    Calcula recorrências lineares
*/

int m = 2; // tamanho da matriz
class Matrix{
    public:
        vector<vector<ll>> mat = {{0, 0}, {0, 0}};

        void setSize(int k) {
            m = k;
            mat.assign(m, vector<ll>(m, 0));
        }

        Matrix operator * (const Matrix &p){
            Matrix ans;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < m; j++)
                    for(int k = ans.mat[i][j] = 0; k < m; k++)
                        ans.mat[i][j] = (ans.mat[i][j] + 1LL * (mat[i][k] % MOD) * (p.mat[k][j] % MOD)) % MOD;
            return ans;
        }
};

// O(log(b))
Matrix fexp(Matrix a, ll b){
    Matrix ans;
    for(int i = 0; i < m; i++)
        ans.mat[i][i] = 1;
    
    while(b){
        if(b & 1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}

