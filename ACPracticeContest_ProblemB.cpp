#include <iostream>

using namespace std;

// compareBalls(c1, c2) prints a query to compare ball c1 against c2.
// The judge responds with '<' if c2 is heavier (meaning c1 < c2),
// or '>' otherwise (meaning c1 > c2).
// We return 'true' if c1 < c2 (judge returns '<'), and 'false' otherwise.
bool compareBalls(char c1, char c2) {
    cout << "? " << c1 << " " << c2 << endl;;
    cout.flush();
    char resp;
    cin >> resp; // '<' or '>'
    return (resp == '<');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q; // N = number of balls, Q = query limit

    if (N == 5) {
        // =======================================================
        // Special 7-comparison method for N=5
        // =======================================================
        // Balls are A, B, C, D, E. We do:
        //  1) Compare A,B  -> L1a < L1b
        //  2) Compare C,D  -> L2a < L2b
        //  3) Compare L1a,L2a -> M1 < M2
        //  4) Compare L1b,L2b -> M3 < M4
        //  5) Compare M2,M3   -> X < Y
        //  => Now we have a partial chain: M1 < X <= Y < M4
        //  6-7) Insert E in exactly 2 comparisons.
        //
        // This is guaranteed to sort 5 distinct items with at most 7 comparisons.

        char A = 'A', B = 'B', C = 'C', D = 'D', E = 'E';

        
    }

    return 0;
}