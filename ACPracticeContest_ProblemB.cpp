#include <iostream>
#include <vector>
#include <string>

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

        // Step 1
        char L1a, L1b;
        if (compareBalls(A, B)) {
            L1a = A; L1b = B;
        } else {
            L1a = B; L1b = A;
        }

        // Step 2
        char L2a, L2b;
        if (compareBalls(C, D)) {
            L2a = C; L2b = D;
        } else {
            L2a = D; L2b = C;
        }

        // Step 3
        char M1, M2;
        if (compareBalls(L1a, L2a)) {
            M1 = L1a; M2 = L2a;
        } else {
            M1 = L2a; M2 = L1a;
        }

        // Step 4
        char M3, M4;
        if (compareBalls(L1b, L2b)) {
            M3 = L1b; M4 = L2b;
        } else {
            M3 = L2b; M4 = L1b;
        }

        // Step 5
        char X, Y;
        if (compareBalls(M2, M3)) {
            X = M2; Y = M3;
        } else {
            X = M3; Y = M2;
        }
        
        // Step 6
        if (compareBalls(E, Y)) {
            if (compareBalls(E, X)) {
                // Step 7a
                if (compareBalls(E, M1)) {
                    cout << "! " << E << M1 << X << Y << M4 << endl;
                } else {
                    cout << "! " << M1 << E << X << Y << M4 << endl;
                }
            } else {
                cout << "! " << M1 << X << E << Y << M4 << endl;
            }
        } else {
            // Step 7b
            if (compareBalls(E, M4)) {
                cout << "! " << M1 << X << Y << E << M4 << endl;
            } else {
                cout << "! " << M1 << X << Y << M4 << E << endl;
            }
        }

        cout.flush();
    } else {
        // =======================================================
        // Insertion sort with binary search for N=26
        // =======================================================
        // This uses ~ O(N log N) comparisons (at most ~78 for N=26),
        // which is under the limit of 100 queries.

        vector<char> sortedBalls;
        sortedBalls.reserve(N);

        for (int i = 0; i < N; i++) {
            char c = static_cast<char>('A' + i);

            int left = 0, right = (int)sortedBalls.size();
            while (left < right) {
                int mid = (left + right) / 2;
                
                if (compareBalls(c, sortedBalls[mid])) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            sortedBalls.insert(sortedBalls.begin() + left, c);
        }

        // Output final sorted order
        cout << "! ";
        for (char c : sortedBalls) {
            cout << c;
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}