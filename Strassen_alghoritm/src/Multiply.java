/*-------------------------------------------------------------------------------*/
// Klasa zawiera jedna metode ktora mnozy dwie macierze podane jako dwa pierwsze
// argumenty i zapisuje wynik na trzeciej macierzy podanej jako trzeci argument

public class Multiply {
    private int rozmiar;

    public void mnozenie(int [][]tabA, int [][]tabB, int [][]tabC){

        this.rozmiar = tabA.length;

        for (int i = 0; i < rozmiar; i++) {
            for (int j = 0; j < rozmiar; j++) {

                tabC[i][j] = 0;
                for (int k = 0; k < rozmiar; k++) {

                    tabC[i][j] += tabA[i][k] * tabB[k][j];
                }
            }

        }
    }

}
