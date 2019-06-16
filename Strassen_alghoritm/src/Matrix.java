/*----------------------------------------------------------------------------------------------*/
// Klasa Matrix zawiera metody alokujaca pamiec, tworzaca i wypisujaca macierz
// zawiera dwa konstruktory. Ten z 2 parametrami tworzy macierz o zadanym rozmiarzei wypelnia
// ja losowymi liczbami z zadanego przedzialu. Ten z 1 parametrem tworzy macierz zerowa o zadanym
// rozmiarze

import java.util.Random;

public class Matrix {

    Random r = new Random(); //stworzenie obiektu klasy Random - do losowania

    int rozm; //ROZMIAR MACIERZY rozm x rozm | mi max wchodza jakies 20k x 20k
    int b; //bound - rozrzut losowania, call it przedzial XD 0 - 9 oczywiscie jesli dasz b = 10
    public int [][] tab;

    //KONSTRUKTOR x2 parametry
    Matrix(int rozmiar, int przedzial){
        this.rozm = rozmiar;
        this.b = przedzial;
        this.tab = stworz_macierz(1);
    }
    //KONSTRUKTOR x1 parametr
    Matrix(int rozmiar){
        this.rozm = rozmiar;
        this.tab = stworz_macierz(0);
    }
    private int[][] stworz_macierz(int a){

        int [][] tab = new int[rozm][rozm]; //dynamiczna alokacja pamięci dla tablicy

        //DWA FORY DO WYPELNIENIA MACIERZY
        //jesli a == 1 to wypelnia losowymi, jesli 0 to tworzy zerowa macierz
        if (a==1){
            for (int i = 0; i < tab.length; i++) {
                for (int j = 0; j < tab[i].length; j++) {
                    tab[i][j] = r.nextInt(b);
                }
            }
        }
        if (a==0){
            for (int i = 0; i < tab.length; i++) {
                for (int j = 0; j < tab[i].length; j++) {
                    tab[i][j] = 0;
                }
            }
        }
        return tab;
    }
    public void wypisz_macierz(){

        System.out.println("________");
        for (int i = 0; i < tab.length; i++) {
            for (int j = 0; j < tab[i].length; j++) {
                System.out.print(tab[i][j] + " ");
            }
            System.out.println("");
        }
        //System.out.println("________");
    }
}
