class Solution {
public:
    typedef long long ll;
    typedef vector<ll> vl;
    typedef vector<vl> vvl;

    const ll MOD = 1e9 + 7;

    vvl multiply(vvl& A, vvl& B) {
        int n = A.size(), m = A[0].size(), k = B[0].size();

        vvl C(n, vl(k, 0));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                for(int l = 0; l < m; l++)
                    C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % MOD;

        return C;
    }

    vvl power(vvl& A, ll k) {
        int n = A.size();

        vvl ret(n, vl(n, 0)), B = A;

        for(int i = 0; i < n; i++)
            ret[i][i] = 1;

        while(k) {
            if(k & 1)
                ret = multiply(ret, B);

            B = multiply(B, B);
            k >>= 1;
        }

        return ret;
    }

    int numTilings(int n) {

        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;

        // F(n)=2F(n-1)+F(n-3)

        vvl M = {
            {2,0,1},
            {1,0,0},
            {0,1,0}
        };

        vvl Mp = power(M, n - 2);

        // Base vector = [F(2),F(1),F(0)] = [2,1,1]

        ll ans =
            (Mp[0][0] * 2 +
             Mp[0][1] * 1 +
             Mp[0][2] * 1) % MOD;

        return ans;
    }
};
