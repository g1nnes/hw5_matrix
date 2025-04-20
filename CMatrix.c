int main()
{
    int a[2][2] = {
        {6, 4},
        {8, 3}
    };

    int b[2][3] = {
    {1,2,3},
    {4,5,6}
    };

    int c[2][3] = {
    {2,4,6},
    {1,3,5}
    };
    int constant = 3;

    for (int i = 0; i < sizeof(b); i++) {
        for (int j = 0; j < sizeof(b[0]); j++) {
            b[i][j] = b[i][j] * constant;
        }
    }

    int newMatrix[sizeof(c[0])][sizeof(c)];
    for (int i = 0; i < sizeof(newMatrix); i++) {
        for (int j = 0; j < sizeof(newMatrix[0]); j++) {
            newMatrix[i][j] = c[j][i];
        }
    }

    int shrunkenRows = 0;
    int shrunkenColumn = 0;
    if (sizeof(b) < sizeof(c)) {
        shrunkenRows = sizeof(b);
    }
    else {
        shrunkenRows = sizeof(c);
    }

    if (sizeof(b[0]) < sizeof(c[0])) {
        shrunkenColumn = sizeof(b[0]);
    }
    else {
        shrunkenColumn = sizeof(c[0]);
    }
    const int newRows = shrunkenRows;
    const int newColumn = shrunkenColumn;
}