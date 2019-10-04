import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){

        Scanner wymiar = new Scanner(System.in);

        System.out.println("Podaj dlugosc wykreslanki: ");
        int n = wymiar.nextInt();

        ArrayList slownik = new ArrayList(); //zbior slow wczytanych z pliku
        String alfabet = "";

        Plik a = new Plik(); // odczyt z pliku
        alfabet = a.odczyt(slownik);

        char[] pierwsze = new char[slownik.size()]; //tablica pierwszych znakow w celu szybszego wyszukiwania slow
        // a nie przeszukiwania wszyststkich slow

        Wykreslanka q = new Wykreslanka();
        q.stworzTab(slownik, pierwsze); // stworzenie tablicy z pierwszysmi literami

        String ciag = q.generator(alfabet, n);
        //System.out.println(ciag);

        //ciag = "PIESSVZDFBSTARANTULADGNDSFPIESSDBFSREDKOT"; //mozesz odkomentowac i probowac sobie jak to dziala

        q.wyszukiwanie(pierwsze, slownik, ciag);






    }


}
