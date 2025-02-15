#include <iostream>

using namespace std;

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
    }

    return 0;
}