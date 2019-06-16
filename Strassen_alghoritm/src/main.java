/*---------------------------------------------------------------------------*/
// Klasa zawiera metode main oraz dwie statyczne zmienne rozmiar macierzy i
// przedzial pseudolosowych liczb w macierzy

public class main {
    final static int rozm = 2000;  //algorytm Strassena dziala tylko na macierze
                                // kwadratowe o boku dlugosci podzielnej
                                // przez 4, czyli mozliwe wartosci to an = 4 + (n - 1)4 (he he)
                                // np. 4, 8, 12... szeregów nie umiem pisac XD
    final static int przedzial = 3;

    public static void main(String [] args){



        Matrix A = new Matrix(rozm, przedzial);
        Matrix B = new Matrix(rozm, przedzial);
        Matrix C = new Matrix(rozm);
        Matrix D = new Matrix(rozm);

//        A.wypisz_macierz( );
//        B.wypisz_macierz( );
//        C.wypisz_macierz( );

        //MNOZENIE ZWYLKYM SPOSOBEM
        Multiply mult = new Multiply();

        long start = System.currentTimeMillis();
        mult.mnozenie(A.tab, B.tab, C.tab);
        long finish = System.currentTimeMillis(); //...a ty mnie wciaz za to winisz XD
        long czas = finish - start;
        System.out.println("Czas wykonywania zwyklego mnożenia to: " + czas + "ms");

        //C.wypisz_macierz( );

        //MNOZENIE ALGORYTMEM STRASSENA
        Strassen str = new Strassen();

        start = System.currentTimeMillis();
        str.algstr(A.tab, B.tab, D.tab, rozm);
        finish = System.currentTimeMillis(); //...a ty mnie wciaz za to winisz XD
        czas = finish - start;
        System.out.println("Czas wykonywania mnożenia alg strassena to: " + czas + "ms");

        //D.wypisz_macierz();



        System.out.println("\nEXIT_CODE_0xb002345 ZAKONCZONY POMYSLNIE!");
    }
}
