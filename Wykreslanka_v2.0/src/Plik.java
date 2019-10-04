import java.io.*;
import java.util.ArrayList;

public class Plik {
    String odczyt(ArrayList slownik){

        String alfabet = "";
        try {
            FileReader file = new FileReader("slowa.txt");
            BufferedReader buff = new BufferedReader(file);

            char c;
            boolean eof = false;
            boolean jest = false;

            while (!eof){
                String slowo = buff.readLine(); //pobierz do bufora kolejna linie
                if (slowo == null) { //jesli == null to znaczy ze nic dalej nie ma i trzeb przerwac odczyt
                    eof = true; //oznaczam EndOfFile jako true
                    break;
                }
                else {
                    slownik.add(slowo); //do slownika dodaje odczytane slowo

                    for (int i = 0; i < slowo.length(); i++) { //caly ten duzy for sluzy do stworzenia alfabetu,
                                                                // ktory zlozony jest tylko z liter, z ktorych skladaja
                                                                // sie slowa w pliku - ulatwienie, bo ze wszystkich
                                                                // dostepnych znakow, duzo mniej prawdopodobne ze
                                                                // znajdzie sie w tym ciagu slowo
                        c = slowo.charAt(i); // biore pierwsza litere z odczytanego slowa
                        //System.out.print(c + " ");
                        for (int j = 0; j < alfabet.length(); j++) { // przechodze alfabet
                            //System.out.print(alfabet.charAt(j) + " ");
                            if (alfabet.charAt(j) == c){ //sprawdzam, czy taki znak juz jest w alfabecie
                                jest = true;
                                break;
                            }
                            else {jest = false;}
                        }
                        if (!jest){ //jesli jest dodaje do alfabetu kolejna litere
                            alfabet = alfabet + c;
                            //System.out.println("\n" + alfabet);
                        }
                    }
                    //System.out.println((String)slownik.get(slownik.size()-1));
                }
            }
            System.out.println("Alfabet dla wykreslanki: " + alfabet);
            buff.close(); //zamkniecie buforu
        }
        catch (IOException e){
            System.out.println("Blad pliku: " + e);
        }
        return alfabet;
    }
}
