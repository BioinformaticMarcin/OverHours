import java.util.ArrayList;
import java.util.Random;

public class Wykreslanka {

    void stworzTab(ArrayList slownik, char[] pierwsze){

        String s = "";
        char c;
        for (int i = 0; i < slownik.size(); i++) {
            s = (String)slownik.get(i); //Pobierz slowo ze slownika, musi byc string bo w ArrayLList sa obiekty
            pierwsze[i] = s.charAt(0); //Pobierz pierwsza litere z kazdego slowa i daj do tab-pierwsze
            //System.out.println(pierwsze[i]);
        }
    }
    String generator(String alfabet, int wymiar){

        String s = "";
        Random r = new Random();

        for (int i = 0; i < wymiar; i++) {
            s = s + alfabet.charAt(r.nextInt(alfabet.length()));
        }
        return s;
    }
    void wyszukiwanie(char[] pierwsze, ArrayList slownik, String ciag){

        String slowo = "";

        for (int i = 0; i < ciag.length(); i++) { //przechodze po kolei ciag
            for (int j = 0; j < pierwsze.length; j++) { //przechodze przez moja tablice pierwszych liter

                if (ciag.charAt(i) == pierwsze[j]){ //porownuje znak z ciagu ze wszystkimi z tab-pierwsze
                    slowo = (String)slownik.get(j); //pobieram cale slowo z rownoleglej ArrayList - ma te same
                                                    // indeksy co tab-pierwsze

                    if (ciag.length() > i + slowo.length()-1){   //sprawdzam czy slowo wgl ma szanse zmiescic sie w ciagu
                        // np koncowka ciagu: "...avrPIE" PIES na 100% sie nie
                        // zmiesci wiec po co dalej drazycz czy to to samo

                        for (int k = 0; k < slowo.length(); k++) { //przechodze przez slowo

                            if (slowo.charAt(k) == ciag.charAt(i + k)) { //porownuje kolejne litery slowa
                                                                        // i nastepujace po pierwszej litery ciagu

                                if (k == slowo.length() - 1) { //jesli przeszlismy cala petle

                                    System.out.println("Na pozycji: " + i + " znaleziono: " + slowo);

                                    pierwsze[j] = 0; //usuwam wykorzystane litery aby zmniejszyc zlozonosc
                                    // obliczeniowa wyszukiwania, co niestety sprowadza sie do odnalezienia
                                    // max jednego z podanych slow ciagu. Gdyby wgl ktos mial takie szczescie
                                    // zeby trafic na wiecej niz jedno. Jesli w wykreslance ma byc wiecej takich
                                    // samych slow usun te linie

                                    i = i + slowo.length() - 1; //przesuwam sie w calym ciagu o tyle liter ile ma
                                    // slowo aby ponownie nie sprawdzac jego liter w pierwszych. problem bedzie
                                    // jesli w slowkach znajdzie sie np GLUKOZA i KOZA wtedy ciag "dsfvsaGLUKOZAavbfsed"
                                    // znajdzie tylko GLUKOZA
                                }
                            } else { break; }
                        }
                    } else { break; }
                }
            }
        }
    }

}
