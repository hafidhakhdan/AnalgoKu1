/**
* Nama : Hafidh Akhdan N
* NPM : 140810180061
*/

#include <iostream>
using namespace std;

const int N = 5;
string Men_name[N] = {"Victor", "Wyatt", "Xavier", "Yancey", "Zeus"};
string Women_name[N] = {"Amy", "Bertha", "Clare", "Diane", "Erika"};

int Men_preference[N][N] = {
    {1, 0, 3, 4, 2},
    {3, 1, 0, 2, 4},
    {1, 4, 2, 3, 0},
    {0, 3, 2, 1, 4},
    {1, 3, 0, 4, 2},
};

int Women_preference[N][N] = {
    {4, 0, 1, 3, 2},
    {2, 1, 3, 0, 4},
    {1, 2, 3, 4, 0},
    {0, 4, 3, 2, 1},
    {3, 1, 4, 2, 0},
};

int stable[N][2];
bool Men_match[N];
bool Women_match[N];

int getManMatch(int woman)
{
    for (int i = 0; i < N; i++)
    {
        if (stable[i][1] == woman)
        {
            return stable[i][0];
            break;
        }
    }
    return -1;
}

int getPreferenceLevel(int woman, int man)
{
    for (int i = 0; i < N; i++)
    {
        if (Women_preference[woman][i] == man)
        {
            return i;
            break;
        }
    }
    return -1;
}

void matchingProcess(int M, int W)
{
    stable[M][0] = M;
    stable[M][1] = W;
    Men_match[M] = true;
    Women_match[W] = true;
}

void traversalMatch()
{
    cout << "HASIL STABLE-MATCHING:\n";
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
        {
        }
        cout << "(" << Men_name[stable[i][0]] << "," << Women_name[stable[i][1]] << ")\n";
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int M = j;
            if (Men_match[M] == false)
            {
                int W = Men_preference[M][i];
                if (Women_match[W] == true)
                {
                    int xM = getManMatch(W);
                    int xM_prep = getPreferenceLevel(W, xM);
                    int M_prep = getPreferenceLevel(W, M);
                    if (M_prep < xM_prep)
                    {
                        matchingProcess(M, W);
                        Men_match[xM] = false;
                        stable[xM][1] = -1;
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    matchingProcess(M, W);
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }

    traversalMatch();
}
