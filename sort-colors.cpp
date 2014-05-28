class Solution {
public:
    void sortColors(int A[], int n) {
        int r = 0, w = 0, b = 0;
        for (int i = 0; i < n; i++) {
            switch(A[i]) {
            case 0: r++; break;
            case 1: w++; break;
            case 2: b++; break;
            default: break;
            }
        }

        int pos = 0;
        while (r-- > 0)
            A[pos++] = 0;
        while (w-- > 0)
            A[pos++] = 1;
        while (b-- > 0)
            A[pos++] = 2;
    }
};
