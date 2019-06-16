public class Strassen {

    public void algstr (int [][]tabA, int [][]tabB, int [][]tabD, int rozmiar){

        // najprostszy przypadek: kiedy macierz ma rozmiar 1 na 1:
        if (rozmiar == 1) {
            tabD[0][0] = tabA[0][0] * tabB[0][0];
            return;
        }

        else{
            int newRozmiar = rozmiar/2;

            // Alokacja tak dużej pamieci taaa wiem pewnie mozna to zrobic lepiej
            // ale nie w tym czasie
            int [][] a11 = new int[newRozmiar][newRozmiar];
            int [][] a12 = new int[newRozmiar][newRozmiar];
            int [][] a21 = new int[newRozmiar][newRozmiar];
            int [][] a22 = new int[newRozmiar][newRozmiar];

            int [][] b11 = new int[newRozmiar][newRozmiar];
            int [][] b12 = new int[newRozmiar][newRozmiar];
            int [][] b21 = new int[newRozmiar][newRozmiar];
            int [][] b22 = new int[newRozmiar][newRozmiar];

            int [][] d11 = new int[newRozmiar][newRozmiar];
            int [][] d12 = new int[newRozmiar][newRozmiar];
            int [][] d21 = new int[newRozmiar][newRozmiar];
            int [][] d22 = new int[newRozmiar][newRozmiar];

            int [][] p1 = new int[newRozmiar][newRozmiar];
            int [][] p2 = new int[newRozmiar][newRozmiar];
            int [][] p3 = new int[newRozmiar][newRozmiar];
            int [][] p4 = new int[newRozmiar][newRozmiar];
            int [][] p5 = new int[newRozmiar][newRozmiar];
            int [][] p6 = new int[newRozmiar][newRozmiar];
            int [][] p7 = new int[newRozmiar][newRozmiar];

            int [][] aResult = new int[newRozmiar][newRozmiar];
            int [][] bResult = new int[newRozmiar][newRozmiar];


            // dzielenie macierzy na 4 podmacierze
            for (int i = 0; i < newRozmiar; i++) {
                for (int j = 0; j < newRozmiar; j++) {
                    a11[i][j] = tabA[i][j];
                    a12[i][j] = tabA[i][j + newRozmiar];
                    a21[i][j] = tabA[i + newRozmiar][j];
                    a22[i][j] = tabA[i + newRozmiar][j + newRozmiar];

                    b11[i][j] = tabB[i][j];
                    b12[i][j] = tabB[i][j + newRozmiar];
                    b21[i][j] = tabB[i + newRozmiar][j];
                    b22[i][j] = tabB[i + newRozmiar][j + newRozmiar];
                }
            }

            // obliczanie macierzy od M1 do M7:

            sumuj(a11, a22, aResult, newRozmiar); // a11 + a22
            sumuj(b11, b22, bResult, newRozmiar); // b11 + b22
            algstr(aResult, bResult, p1, newRozmiar); // p1 = (a11+a22) * (b11+b22)

            sumuj(a21, a22, aResult, newRozmiar); // a21 + a22
            algstr(aResult, b11, p2, newRozmiar); // p2 = (a21+a22) * (b11)

            odejmij(b12, b22, bResult, newRozmiar); // b12 - b22
            algstr(a11, bResult, p3, newRozmiar); // p3 = (a11) * (b12 - b22)

            odejmij(b21, b11, bResult, newRozmiar); // b21 - b11
            algstr(a22, bResult, p4, newRozmiar); // p4 = (a22) * (b21 - b11)

            sumuj(a11, a12, aResult, newRozmiar); // a11 + a12
            algstr(aResult, b22, p5, newRozmiar); // p5 = (a11+a12) * (b22)

            odejmij(a21, a11, aResult, newRozmiar); // a21 - a11
            sumuj(b11, b12, bResult, newRozmiar); // b11 + b12
            algstr(aResult, bResult, p6, newRozmiar); // p6 = (a21-a11) * (b11+b12)

            odejmij(a12, a22, aResult, newRozmiar); // a12 - a22
            sumuj(b21, b22, bResult, newRozmiar); // b21 + b22
            algstr(aResult, bResult, p7, newRozmiar); // p7 = (a12-a22) * (b21+b22)


            // obliczanie c21, c21, c11 i c22:

            sumuj(p3, p5, d12, newRozmiar); // c12 = p3 + p5
            sumuj(p2, p4, d21, newRozmiar); // c21 = p2 + p4

            sumuj(p1, p4, aResult, newRozmiar); // p1 + p4
            sumuj(aResult, p7, bResult, newRozmiar); // p1 + p4 + p7
            odejmij(bResult, p5, d11, newRozmiar); // d11 = p1 + p4 - p5 + p7

            sumuj(p1, p3, aResult, newRozmiar); // p1 + p3
            sumuj(aResult, p6, bResult, newRozmiar); // p1 + p3 + p6
            odejmij(bResult, p2, d22, newRozmiar); // d22 = p1 + p3 - p2 + p6

            // grupowanie wyników w jedną macierz:
            for (int i = 0; i < newRozmiar; i++) {
                for (int j = 0; j < newRozmiar; j++) {
                    tabD[i][j] = d11[i][j];
                    tabD[i][j + newRozmiar] = d12[i][j];
                    tabD[i + newRozmiar][j] = d21[i][j];
                    tabD[i + newRozmiar][j + newRozmiar] = d22[i][j];
                }
            }
        }
    }
    private void sumuj(int [][]tabA, int [][]tabB, int [][]result, int rozmiar){

        for (int i = 0; i < rozmiar; i++) {
            for (int j = 0; j < rozmiar; j++) {
                result[i][j] = tabA[i][j] + tabB[i][j];
            }
        }
    }
    private void odejmij(int [][]tabA, int [][]tabB, int [][]result, int rozmiar){

        for (int i = 0; i < rozmiar; i++) {
            for (int j = 0; j < rozmiar; j++) {
                result[i][j] = tabA[i][j] - tabB[i][j];
            }
        }
    }
}
