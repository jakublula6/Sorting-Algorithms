//Jakub Lula 1EF-DI 2021

#include <stdio.h> //biblioteka do obsługi operacji wejścia/wyjścia
#include <stdlib.h> //biblioteka z funkcja do czyszczenia ekranu

//Inicjalizacja tablicy liczb wprowadzonych przez użytkownika
int *tab_wej;

//Menu wyboru algorytmu:
int menu ()
{
    int opcja;
    printf("Dostepne algorytmy:\n");
    printf("1) Sortowanie babelkowe\n");
    printf("2) Sortowanie przez wstawianie\n");
    printf("3) Sortowanie przez zliczanie\n");
    printf("4) Sortowanie przez wybor\n");
    printf("5) Sortowanie szybkie (Quick sort) \n");
    printf("6) Sortowanie kubelkowe\n");
    printf("9) Wczytaj nowe liczby do sortowania\n");
    printf("0 - Wyjscie z programu\n");

    printf("Podaj numer wybranej opcji: ");
    scanf("%d", &opcja);
    printf("\n");
    return opcja;
}

//Wczytanie liczb
int wczytaj()
{
    int n;
    printf("Podaj ilosc liczb do posortowania: ");
    scanf("%d", &n);

    tab_wej = realloc(tab_wej, n* sizeof(int));
    for(int i=0;  i<n; i++)
    {
        printf("Podaj kolejna liczbe calkowita: ");
        scanf("%d", &tab_wej[i]);
    }
    system("cls");
    return n;
}

//Czyszczenie ekranu
void wyczysc()
{
    printf("Wcisnij dowolny klawisz zeby kontynuowac");
    getch();
    system("cls");
}

//Zamiana dwoch zmiennych miejscami
void zamien(int *a, int*b)
{
    int pomocnicza = *a;
    *a = *b;
    *b = pomocnicza;
}

//Kopiowanie tablicy
void copy(int wejscie[], int wyjscie[], int n)
{
    for(int i = 0; i<n; i++)
    {
        wyjscie[i] = wejscie[i];
    }
}

//Wypisanie tablicy
void drukuj(int tablica [], int ilosc)
{
    printf("\n");
    for(int i=0; i<ilosc;i++)
    {
        printf("%d, ", tablica[i]);
    }
    printf("\n");
}

//Sortowanie babelkowe
//Opis slowny sortowania babelkowego
void babelkowe_opis()
{
    printf("Sortowanie babelkowe\n");
    printf("Metoda sortowania, w ktorej komputer przesuwajac sie po kolejnych elementach tablicy sprawdza,\n");
    printf("czy sa one ulozone we wlasciwej kolejnosci i w razie potrzeby zamienia je miejscami.\n");
    printf("Dzieki kolejnym porownaniom elementow tablicy na jej ostatniej pozycji znajdzie sie najwieksza z liczb.\n");
    printf("W zwiazku z tym jesli program przeiteruje tablice i razy, ostatnie i-liczb znajdzie sie na wlasciwej pozycji.\n");
    printf("Gdy petla wykona sie n-1 (n - ilosc liczb) otrzymamy tablice posortowana.\n\n");
    printf("Zlozonosc obliczeniowa tego algorytmu wynosi: O(n^2)\n\n");
}

//Schemat blokowy sortowania babelkowego:
void babelkowe_schemat()
{
    printf("Schemat blokowy: \n\n");
    printf("                          ___________________                              \n");
    printf("                         (_______Start_______)                             \n");
    printf("                                   |                                       \n");
    printf("                          _________V_________                              \n");
    printf("                         |______ i = 0 ______|                             \n");
    printf("         ------------------------> |                                       \n");
    printf("         |                         V                                       \n");
    printf("         |                         /\\                                     \n");
    printf("         |                        /  \\                                    \n");
    printf("         |                        i<n-1  ---------- Nie -----              \n");
    printf("         |                        \\  /                      |             \n");
    printf("         |                         \\/              _________V_________    \n");
    printf("         |                         | Tak          (______ Koniec _____)    \n");
    printf("         |                _________V_________                              \n");
    printf("         |               |_______ j = 0 _____|                             \n");
    printf("         |         --------------> |                                       \n");
    printf("         |         |               V                                       \n");
    printf("         |         |               /\\                                     \n");
    printf("         |         |              /  \\                                    \n");
    printf("         |         |            j<n-1-i   --------Nie----------------_     \n");
    printf("         |         |              \\  /                               |    \n");
    printf("         |         |               \\/                                |    \n");
    printf("         |         |               | Tak                             |     \n");
    printf("         |         |               V                                 |     \n");
    printf("         |         |               /\\                                |    \n");
    printf("         |         |              /  \\                               |    \n");
    printf("         |         |         tab[j]>tab[j+1] --------Nie----         |     \n");
    printf("         |         |              \\  /                      |        |    \n");
    printf("         |         |               \\/                       |        |    \n");
    printf("         |         |               |  Tak                   |        |     \n");
    printf("         |         |      _________V__________              |        |     \n");
    printf("         |         |     | tab[j] <->tab[j+1] |             |        |     \n");
    printf("         |         |     |____________________|             |        |     \n");
    printf("         |         |               | <----------------------         |     \n");
    printf("         |         |      _________V_________                        |     \n");
    printf("         |         ------|_____ j = j+1 _____|                       |     \n");
    printf("         |                                                           |     \n");
    printf("         |                          ---------------------------------      \n");
    printf("         |                          |                                      \n");
    printf("         |                __________V________                              \n");
    printf("         |               |_____ i = i+1 _____|                             \n");
    printf("         |                          |                                      \n");
    printf("         ---------------------------                                       \n");
}

//Funkcja sortująca
void babelkowe_sort(int n)
{
    //Utworzenie lokalnej kopii tablicy
    int *tablica = (int *)malloc(n * sizeof(int));
    copy(tab_wej, tablica, n);
    int licznik = 0;

    printf("Tablica przed sortowaniem:");
    drukuj(tablica, n);
    printf("\n");

    for(int i = 0; i < n-1; i++)
    {
        printf("Wykonanie petli po raz %d:\n", i+1);
        for(int j = 0; j < n-1-i; j++)
        {
            if(tablica[j]>tablica[j+1])
            {
                printf("%d jest wieksze od %d wiec zamieniam je miejscami",tablica[j], tablica[j+1]);
                zamien(&tablica[j], &tablica[j+1]);
                drukuj(tablica, n);
            }
            else
            {
                printf("%d nie jest wieksze od %d wiec nie zamieniam ich miejscami\n",tablica[j], tablica[j+1]);
            }
            licznik++;
        }
        printf("Tablica po wykonaniu petli:");
        drukuj(tablica, n);
        printf("\n");
    }
    printf("\nIlosc porownan: %d\n", licznik);
    free(tablica);
}


//Sortowanie przez wstawianie
//Opis słowny sortowania przez wstawianie
void wstaw_opis()
{
    printf("Sortowanie przez wstawianie bardzo czesto porownywane jest\ndo wkladania katry w odpowiednie miejsce w uporzadkowanej talii.\n");
    printf("Komputer wybiera drugi element z tablicy i porownuje go z pierwszym elementem,\n");
    printf("Jesli pierwszy element jest wiekszy to zamienia je miejscami. \nW ten sposob pierwsze dwa elementy tablicy sa ciagiem posortowanym.\n");
    printf("Nastepnie wybiera kolejne elementy z tablicy wstawiajac je w odpowiednie miejsca ciagu posortowanego. \nOperacje powtarza az do wstawienia wszystkich elementow na wlasciwe miejsce.\n");
    printf("Mimo zlozonosci O(n^2) jest on bardzo wydajny dla wstepnie posortowanych ciagow. \nJest jednoczesnie stosunkowo prosty w implementacji.\n\n");
}

//Schemat blokowy
void wstaw_schemat()
{
    printf("Schemat blokowy: \n\n");
    printf("                          ___________________                              \n");
    printf("                         (_______Start_______)                             \n");
    printf("                                   |                                       \n");
    printf("                          _________V_________                              \n");
    printf("                         |______ i = 1 ______|                             \n");
    printf("         ------------------------> |                                       \n");
    printf("         |                         V                                       \n");
    printf("         |                         /\\                                     \n");
    printf("         |                        /  \\                                    \n");
    printf("         |                        i<n  ---------- Nie ------               \n");
    printf("         |                        \\  /                     |              \n");
    printf("         |                         \\/             _________V_________     \n");
    printf("         |                         | Tak         (______ Koniec _____)     \n");
    printf("         |                _________V_________                              \n");
    printf("         |               |      j = i - 1    |                             \n");
    printf("         |               |___ temp = tab[i]__|                             \n");
    printf("         |         --------------> |                                       \n");
    printf("         |         |               V                                       \n");
    printf("         |         |               /\\                                     \n");
    printf("         |         |              /  \\                                    \n");
    printf("         |         |            temp<tab[j]--------Nie----------------     \n");
    printf("         |         |               i                                 |     \n");
    printf("         |         |             j>=0                                |     \n");
    printf("         |         |              \\  /                               |    \n");
    printf("         |         |               \\/                                |    \n");
    printf("         |         |               | Tak                             |     \n");
    printf("         |         |      _________V__________                       |     \n");
    printf("         |         |     | tab[j+1] =  tab[j] |                      |     \n");
    printf("         |         |     |______  j --  ______|                      |     \n");
    printf("         |         |______________|                                  |     \n");
    printf("         |                          ---------------------------------      \n");
    printf("         |                          |                                      \n");
    printf("         |                __________V________                              \n");
    printf("         |               |      i = i+1      |                             \n");
    printf("         |               |_ tab[j+1] = temp _|                             \n");
    printf("         |                          |                                      \n");
    printf("         ---------------------------                                       \n");
}

//Funkcja sortująca
void wstaw_sort(int n)
{
    //Utworzenie lokalnej kopii tablicy
    int *tablica = (int *)malloc(n * sizeof(int));
    copy(tab_wej, tablica, n);

    printf("Tablica przed sortowaniem:");
    drukuj(tablica, n);
    printf("\n");

    int i, j, temp;
    // używam i = 1 oraz while j>=0 zamisat i = 2 oraz while j>0 ponieważ C indeksuje tablicę zaczynając od 0
    for (i = 1; i<n; i++)
    {
        //Zmienna wybrana do wstawienia 
        temp = tablica[i];
        j = i - 1;
        while(temp<tablica[j] && j>=0)
        {
            tablica[j+1] = tablica[j];
            j--;
        }
        //Wstawienie zmiennej na właściwe miejsce
        tablica[j+1] = temp;
        printf("Ruch %d:", i);
        drukuj(tablica, n);
        printf("Wstawiana liczba: %d \n\n", temp);
    }
    printf("Wynik dzialania algorytmu:");
    drukuj(tablica, n);
    free(tablica);
}


//Sortowanie przez zliczanie

void zlicz_opis()
{
    printf("Sortowanie przez zliczanie\n");
    printf("Metoda sortowania, w ktorej komputer przesowajac sie po kolejnych elementach tablicy,\n");
    printf("liczy ilosc wystapien poszczegolnych liczb poczawszy od zera a skonczywszy \nna wartosci maksymalnej wystepujacej w sortowanej tablicy\n");
    printf("Nastepnie komputer wypisuje kolejne liczby calkowite, wypisujac dana liczbe tyle razy, \nile razy wstapila w tablicy wejsciowej.\n");
    printf("Wada tej metody jest mozliwosc stosowania jej wylacznie w przypadku liczb calkowitych.\n");
    printf("Zlozonosc tej metody wynosi O(n+k) gdzie k jest iloscia wartosci kluczy a n iloscia sortowanych elementow.\n\n");
}

//Schemat blokowy
void zlicz_schemat()
{
    printf("Schemat blokowy: \n\n");
    printf("                          ___________________                              \n");
    printf("                         (_______Start_______)                             \n");
    printf("                                   |                                       \n");
    printf("                          _________V_________                              \n");
    printf("                         |______ i = 0 ______|                             \n");
    printf("         ------------------------> |                                       \n");
    printf("         |                         V                                       \n");
    printf("         |                         /\\                                     \n");
    printf("         |                        /  \\                                    \n");
    printf("         |                       i<=m  ---------- Nie ------               \n");
    printf("         |                        \\  /                      |             \n");
    printf("         |                         \\/                       |             \n");
    printf("         |                         | Tak                    |              \n");
    printf("         |                _________V_________               |              \n");
    printf("         |               |  licznik[i] = 0   |              |              \n");
    printf("         |               |____ i = i + 1 ____|              |              \n");
    printf("         |                         |                        |              \n");
    printf("         |_________________________|                        |              \n");
    printf("                                                            |              \n");
    printf("                                    ________________________|              \n");
    printf("                                   |                                       \n");
    printf("                          _________V_________                              \n");
    printf("                         |______ i = 0 ______|                             \n");
    printf("         ------------------------> |                                       \n");
    printf("         |                         V                                       \n");
    printf("         |                         /\\                                     \n");
    printf("         |                        /  \\                                    \n");
    printf("         |                         i<n   -------- Nie ------               \n");
    printf("         |                        \\  /                      |             \n");
    printf("         |                         \\/                       |             \n");
    printf("         |                         | Tak                    |              \n");
    printf("         |       __________________V____________________    |              \n");
    printf("         |      | licznik[tab[i]] = licznik[tab[i]] + 1 |   |              \n");
    printf("         |      |______________ i = i + 1 ______________|   |              \n");
    printf("         |                         |                        |              \n");
    printf("         |_________________________|                        |              \n");
    printf("                                                            |              \n");
    printf("                                    ________________________|              \n");
    printf("                                   |                                       \n");
    printf("                          _________V_________                              \n");
    printf("                         |     index = 0     |                             \n");
    printf("                         |______ i = 0 ______|                             \n");
    printf("         ------------------------> |                                       \n");
    printf("         |                         V                                       \n");
    printf("         |                         /\\                                     \n");
    printf("         |                        /  \\                                    \n");
    printf("         |                        i<=m  --------- Nie ------               \n");
    printf("         |                        \\  /                     |              \n");
    printf("         |                         \\/             _________V_________     \n");
    printf("         |                         | Tak         (______ Koniec _____)     \n");
    printf("         |                         V                                       \n");
    printf("         |                         /\\                                     \n");
    printf("         |                        /  \\                                    \n");
    printf("         |                    licznik[i] > 0 -- Nie --                     \n");
    printf("         |                        \\  /               |                    \n");
    printf("         |                         \\/                |                    \n");
    printf("         |                         | Tak             |                     \n");
    printf("         |                _________V_________        |                     \n");
    printf("         |               |______ j = 0 ______|       |                     \n");
    printf("         |          ------------- >|                 |                     \n");
    printf("         |         |               V                 |                     \n");
    printf("         |         |              /\\                 |                    \n");
    printf("         |         |             /  \\                |                    \n");
    printf("         |         |          j<licznik[i] --Nie --> |                     \n");
    printf("         |         |             \\  /                |                    \n");
    printf("         |         |              \\/                 |                    \n");
    printf("         |         |              | Tak              |                     \n");
    printf("         |         |     _________V_________         |                     \n");
    printf("         |         |    |  tab [index] = i  |        |                     \n");
    printf("         |         |    | index = index + 1 |        |                     \n");
    printf("         |         |    |____ j = j + 1 ____|        |                     \n");
    printf("         |         |______________|                  |                     \n");
    printf("         |                                  _________V_________            \n");
    printf("         |                                 |____ i = i + 1 ____|           \n");
    printf("         |                                           |                     \n");
    printf("         |___________________________________________V                     \n");    
    printf("                                                                           \n");
}

//Szukanie wartości maxymalnej
int maximum(int tablica[], int n)
{
    int max = 0;
    for(int i = 0; i<n; i++)
    {
        if(tablica[i]> max)
        {
            max = tablica[i];
        }
    }
    return max;
}

//Szukanie wartości minimalnej
int minimum (int tablica[], int n)
{
    int min = tablica[0];
    for(int i = 0; i<n; i++)
    {
        if(tablica[i]< min)
        {
            min = tablica[i];
        }
    }
    return min;
}

//Funkcja sortująca
void zlicz_sort(int n)
{
    //Utworzenie lokalnej kopii tablicy
    int *tablica = (int *)malloc(n * sizeof(int));
    copy(tab_wej, tablica, n);

    int max = maximum(tablica, n);
    int min = minimum(tablica, n);
    int m = max - min + 1;
    int wystapienia[m];
    int wynik[n];
    int i;

    //Przygotowanie tablicy liczników
    for(i = 0; i<=m; i++)
    {
        wystapienia[i] = 0;
    }
    
    //Zliczanie elementów
    for(i = 0; i<n; i++)
    {
        wystapienia[tablica[i]-min]++;
    }

    //Wyświetlenie wyników liczenia
    printf("Tablica przed sortowaniem:");
    drukuj(tablica, n);
    printf("\nWyniki zliczania: \n");
    //Optymalizacja sposobu wyświetlenia
    if(m<=7)
    {
        for(i = 0; i<=m; i++)
        {
            printf("Liczba %d wystepuje %d razy.\n", i+min, wystapienia[i]);
        }
    }
    else
    {
        printf("(Jesli ilosc wystapien byla rowna 0 liczba zostala pominieta na liscie )\n\n");
        for(i = 0; i<=m; i++)
        {
            if(wystapienia[i]!=0)
            {
                printf("Liczba %d wystepuje %d razy.\n", i+min, wystapienia[i]);
            }
        }
    }

    //Zapis zliczonych elementów 
    int indeks = 0;
    for(i = 0; i<=m; i++)
    {
        if(wystapienia[i]>0)
        {
            for(int j = 0; j<wystapienia[i]; j++)
            {
                tablica[indeks]= i+min;
                indeks ++;
            }
        }
    }
    printf("\nWynik dzialania algorytmu:");
    drukuj(tablica, n);
    free(tablica);
}

//Sortowanie przez wybor
//Opis słowny sortowania przez wybór
void wybor_opis()
{
    printf("Sortowanie przez wybor to jedna z najprostszych metod sortowania.\n");
    printf("Komputer zaczynajac od i-tego indeksu tablicy przeszukuje ja w poszukiwaniu wartosci minimalnej,\n");
    printf("a nastepnie umieszcza wartosc minimalna w komorce tablicy o indeksie i.\n");
    printf("Operacje powtarza do momentu gdy wartosc minmalna bedzie jednoczesnie wartoscia maksymalna.\n");
    printf("Algorytm ten jest algorytmem niestabilnym jednak moze zostac odpowiednio zmodyfikowany \nw celu uzysaknia algorytmu stabilnego.\n");
    printf("Zlozonosc tej metody wynosi O(n^2)\n\n");
}

//Schemat blokowy
void wybor_schemat()
{
    printf("Schemat blokowy: \n\n");
    printf("                          ___________________                              \n");
    printf("                         (_______Start_______)                             \n");
    printf("                                   |                                       \n");
    printf("                          _________V_________                              \n");
    printf("                         |______ i = 0 ______|                             \n");
    printf("         ------------------------> |                                       \n");
    printf("         |                         V                                       \n");
    printf("         |                        /\\                                      \n");
    printf("         |                       /  \\                                     \n");
    printf("         |                        i<n   ---------- Nie ------              \n");
    printf("         |                       \\  /                       |             \n");
    printf("         |                        \\/               _________V_________    \n");
    printf("         |                         | Tak          (______ Koniec _____)    \n");
    printf("         |                _________V_________                              \n");
    printf("         |               |      min = i      |                             \n");
    printf("         |               |____ j = i + 1 ____|                             \n");
    printf("         |         --------------> |                                       \n");
    printf("         |         |               V                                       \n");
    printf("         |         |              /\\                                      \n");
    printf("         |         |             /  \\                                     \n");
    printf("         |         |              j<n    --------Nie----------------       \n");
    printf("         |         |             \\  /                                |    \n");
    printf("         |         |              \\/                                 |    \n");
    printf("         |         |               | Tak                             |     \n");
    printf("         |         |               V                                 |     \n");
    printf("         |         |              /\\                                 |    \n");
    printf("         |         |             /  \\                                |    \n");
    printf("         |         |        tab[j]<tab[min] --------Nie----          |     \n");
    printf("         |         |             \\  /                       |        |    \n");
    printf("         |         |              \\/                        |        |    \n");
    printf("         |         |               |  Tak                   |        |     \n");
    printf("         |         |      _________V__________              |        |     \n");
    printf("         |         |     |____ min = j _______|             |        |     \n");
    printf("         |         |               | <----------------------         |     \n");
    printf("         |         |      _________V_________                        |     \n");
    printf("         |         ------|_____ j = j+1 _____|                       |     \n");
    printf("         |                                                           |     \n");
    printf("         |                          ---------------------------------      \n");
    printf("         |                          |                                      \n");
    printf("         |                __________V________                              \n");
    printf("         |               |tab[min] <=> tab[i]|                             \n");
    printf("         |               |_____ i = i+1 _____|                             \n");
    printf("         |                          |                                      \n");
    printf("         ---------------------------                                       \n");
}

//Funkcja sortująca
void wybor_sort(int n)
{
    //Utworzenie lokalnej kopii tablicy
    int *tablica = (int *)malloc(n * sizeof(int));
    copy(tab_wej, tablica, n);

    //Wyswietlenie tablicy przed sortowaniem
    printf("Tablica przed sortowaniem:");
    drukuj(tablica, n);
    printf("\n");

    int min;
    int zamiany = 0;
    for(int i = 0; i<n; i++)
    {
        min = i;
        for(int j = i+1; j<n; j++)
        {
            if(tablica[j]<tablica[min])
            {
                min = j;
            }
        }
        printf("Zaczynajac od indeksu %d znajduje minimalna wartosc %d", i, tablica[min]);
        zamien(&tablica[min], &tablica[i]);
        drukuj(tablica, n);
        printf("\n");
        zamiany++;
    }
    printf("Wynik dzialania algorytmu:");
    drukuj(tablica, n);
    printf("Ilosc zamian: %d \n", zamiany);
    free(tablica);
}

//Sortowanie szybkie
//Opis słowny sortowania szybkiego
void szybkie_opis()
{
    printf("Sortowanie szybkie jest algorytmem opartym o zasade 'dziel i zwyciezaj'. \nKomputer wybiera element dzielacy tablice na dwie czesci, tzw. pivot,\n");
    printf("a nastepnie porzadkuje dwie czesci tak, aby w lewej czesci byly elementy mniejsze od pivota, \nzas w prawej elementy wieksze. \n");
    printf("Nastepnie funkcja wywoluje sama siebie celem posortowania powstalych dwoch czesci. \nRekurencja jest przerywana w momencie sortowania zbioru 1-elementowego.\n");
    printf("Zlozonosc tej metody wynosi O(n*log(n)), \njednak w przypadku niekorzystnego ulozenia danych wejsciowych moze wzrosnac do O(n^2)\n\n");
}

//Schemat blokowy
void szybkie_schemat()
{
    printf("Schemat blokowy: \n\n");
    printf("                          ___________________                              \n");
    printf("                         (_______Start_______)                             \n");
    printf("                                   |                                       \n");
    printf("                      _____________V_______________                        \n");
    printf("                     |           i = lewy          |                       \n");
    printf("                     |          j = prawy          |                       \n");
    printf("                     | piwot = tab[(lewy+prawy)/2] |                       \n");
    printf("                     |___________ i = 0 ___________|                       \n");
    printf("                                   |                                       \n");
    printf("    -----------------------------> |                                       \n");
    printf("    |    ------------------------> |                                       \n");
    printf("    |    |                         V                                       \n");
    printf("    |    |                        /\\                                      \n");
    printf("    |    |                       /  \\                                     \n");
    printf("    |    |                    piwot>tab[i]  ------ Nie -----               \n");
    printf("    |    |                       \\  /                       |             \n");
    printf("    |    |                        \\/                        |             \n");
    printf("    |    |                         | Tak                    |              \n");
    printf("    |    |                  _______V_________               |              \n");
    printf("    |    |                 |___ i = i + 1 ___|              |              \n");
    printf("    |    |                         |                        |              \n");
    printf("    |    |_________________________|                        |              \n");
    printf("    |                                                       |              \n");
    printf("    |                               ________________________|              \n");
    printf("    |    ------------------------> |                                       \n");
    printf("    |    |                         V                                       \n");
    printf("    |    |                        /\\                                      \n");
    printf("    |    |                       /  \\                                     \n");
    printf("    |    |                    piwot<tab[j]  ------ Nie -----               \n");
    printf("    |    |                       \\  /                       |             \n");
    printf("    |    |                        \\/                        |             \n");
    printf("    |    |                         | Tak                    |              \n");
    printf("    |    |                  _______V________                |              \n");
    printf("    |    |                 |___ j = j- 1 ___|               |              \n");
    printf("    |    |                         |                        |              \n");
    printf("    |    |_________________________|                        |              \n");
    printf("    |                                                       |              \n");
    printf("    |                               ________________________|              \n");
    printf("    |                              |                                       \n");
    printf("    |                              V                                       \n");
    printf("    |                             /\\                                      \n");
    printf("    |                            /  \\                                     \n");
    printf("    |                             i<j  --------- Nie -------               \n");
    printf("    |                            \\  /                       |             \n");
    printf("    |                             \\/                        |             \n");
    printf("    |                              | Tak                    |              \n");
    printf("    |                    __________V________                |              \n");
    printf("    |                   | tab[j] <=> tab[i] |               |              \n");
    printf("    |                   |      j = j-1      |               |              \n");
    printf("    |                   |_____ i = i+1 _____|               |              \n");
    printf("    |                              |                        |              \n");
    printf("    |______________________________V                        |              \n");
    printf("                                    ________________________|              \n");
    printf("                                   |                                       \n");
    printf("                                   V                                       \n");
    printf("                                  /\\                                      \n");
    printf("                                 /  \\                                     \n");
    printf("                                j>lewy  --------- Nie ------               \n");
    printf("                                 \\  /                       |             \n");
    printf("                                  \\/                        |             \n");
    printf("                                   | Tak                    |              \n");
    printf("                    _______________V_____________           |              \n");
    printf("                   |_|_quick_sort(tab, lewy,j)_|_|          |              \n");
    printf("                                   |<-----------------------               \n");
    printf("                                   V                                       \n");
    printf("                                  /\\                                      \n");
    printf("                                 /  \\                                     \n");
    printf("                                i<prawy --------- Nie ------               \n");
    printf("                                 \\  /                       |             \n");
    printf("                                  \\/                        |             \n");
    printf("                                   | Tak                    |              \n");
    printf("                   ________________V______________          |              \n");
    printf("                  |_|_quick_sort(tab,j+1,prawy)_|_|         |              \n");
    printf("                                   |<-----------------------               \n");
    printf("                         __________V_________                              \n");
    printf("                        (_______Koniec_______)                             \n\n");
}

//Funkcja sortująca
void quick_sort(int tablica[], int lewy, int prawy, int n)
{
    int i = lewy;
    int j = prawy;
    int piwot = tablica[(lewy+prawy)/2];
    
    printf("Piwot: %d \n", piwot);

    while(1)
    {
        while(piwot>tablica[i])
        {
            i++;
        }
        while(piwot<tablica[j])
        {
            j--;
        }
        if(i < j)
        {
            zamien(&tablica[i], &tablica[j]);
            i++;
            j--;
        }
        else
        {
            printf("Po zamianie:");
            drukuj(tablica, n);
            printf("\n");
            break;
        }
    }
    if(j>lewy)
    {
        quick_sort(tablica, lewy,j,n);
    }
    if(i<prawy)
    {
        quick_sort(tablica, j+1,prawy,n);
    }
}

//Obsługa funkcji quick_sort(ze wzgledu na rekurencyjne działanie funkcji)
void szybkie_sort(int ilosc)
{
    //Utworzenie kopii tablicy dla funkcji quick sort
    int *tablica = (int *)malloc(ilosc * sizeof(int));
    copy(tab_wej, tablica, ilosc);

    //Prezentacja tablicy początkowej
    printf("Tablica przed sortowaniem:");
    drukuj(tablica, ilosc);
    printf("\n");

    //wyqołanie funkcji
    quick_sort(tablica, 0, ilosc-1, ilosc);
    
    //Prezentacja wyniku działania funkcji
    printf("Wynik dzialania algorytmu:");
    drukuj(tablica, ilosc);

    //Zwolnienie zarezerwowanej pamięci
    free(tablica);
}

//Sortowanie kubelkowe
//Opis słowny sortowania kubełkowego
void kubelkowe_opis()
{
    printf("Sortowanie kubelkowe polega na podzieleniu zbioru n-sortowanych liczb na n tzw  \"kubelkow\" \nodpowiadajacych n-zakresom liczb.\n");
    printf("Liczby powinny nalezec do przedzialu [0,1) co uzyskujemy \ndzielac je przez najwieksza liczbe w tablicy zwiekszona o 1.\n");
    printf("Niestety wyznaczenie wartosci maksymalnej tablicy ma zlozonosc O(n). \nNie zostanie to jednak uwzglednone w obliczeniu zlozonosci algorytmu poniewaz jest to krok opcjonalny,\n");
    printf("Nastepnie algorytm iterujac przez kolejne elementy listy liczb do sortowania\nprzypisuje kolejne liczby do odpowiadajacych im kubelkow.\n");
    printf("Elementy kubelkow sa nastepnie sortowane przy uzyciu dowolnej metody, \nw naszym przypadku bedzie to sorotwanie babelkowe.\n");
    printf("Otrzymane listy uporzadkowanych elementow sa ostatecznie scalane w liste wynikowa.\n");
    printf("Zlozonosc tej metody wynosi O(n) jednak moze ona wzrosnac do O(n^2) w przypadku, \ngdy liczby nie sa rozlozone jednostajnie.\n");
    printf("Najlepsza sytuacja jest duza ilosc elementow sortowanych nalezacych do malego zakresu.\n\n");
}

//Obsługa listy

//Symulacja elementu listy za pomocą struktury
struct element
{
    float wartosc;
    struct element *next;
};

//Dodawanie elementu do listy
struct element *dodaj(struct element *head, struct element *new)
{
    new->next = head;
    head = new;
    return head;
}
//Wyświetlenie listy
void wyswietl(struct element *head)
{
    struct element *x = head;
    while(x!=NULL)
    {
        printf("%f, ", x->wartosc);
        x = x->next;
    }
}

//Dodanie do tablicy list
void dodaj_tab(struct element *head[], struct element *new[], int i, float x)
{
    new[i]=(struct element*)malloc(sizeof(struct element));
    new[i]->wartosc = x;
    head[i]=dodaj(head[i],new[i]);
}

//Odwrócenie kolejności elementów listy
struct element *odwroc(struct element *x)
{
    struct element *headO = NULL;
    struct element *y = NULL;
    while(x != NULL)
    {
        y = (struct element*)malloc(sizeof(struct element));
        y->wartosc = x->wartosc;
        headO = dodaj(headO, y);
        x = x->next;
    }
    return headO;
}

//Zwolnienie pamięci
struct element *usun(struct element *head)
{
    struct element *x;
    while (head != NULL)
    {
        x = head->next;
        free(head);
        head = x;
    }
    return head;
}

//Funkcja sortowania bąbelkowego dla listy
void sortuj(struct element *head)
{
    struct element *x = head;
    struct element *y = head->next;
    float pom;
    while(x!=NULL)
    {
        while(y!=NULL)
        {
            if(x->wartosc>y->wartosc)
            {
                pom = x->wartosc;
                x->wartosc = y->wartosc;
                y->wartosc = pom;
            }
            y = y->next;
        }
        y = x->next;
        x = x->next;
    }
}

//Funkcja sortująca
void kubelkowe_sort(int n)
{
    //Utworzenie kopii tablicy
    int *tablica = (int *)malloc(n * sizeof(int));
    copy(tab_wej, tablica, n);
    
    
    //Inicjalizacja tablicy list
    struct element *head[n], *new[n];
    //"Nullowanie" wskaźników
    for(int i = 0; i<n; i++)
    {
        head[i]=NULL;
        new[i]=NULL;
    }
    
    //Prezentacja tablicy początkowej
    printf("Tablica przed sortowaniem:");
    drukuj(tablica, n);
    printf("\n");

    //Wyznaczenie wartości maksymalnej
    int max = maximum(tablica, n);
    float liczba;
    for(int i = 0; i<n; i++)
    {
        //Zmiana na zakres [0,1)
        liczba = tablica[i]/(float)(max+1);

        //Przypisanie liczby do przedziału 
        dodaj_tab(head,new, n*liczba, liczba);
        
    }
    
    //Wyświetlenie zawartości kubełków
    printf("Aby spelnic warunek nalezenia do przedzialu [0,1) liczby podzielono przez %d \n",max+1);
    for(int i = 0; i<n; i++)
    {
        printf("Zawartosc kubelka nr. %d:\n", i+1);
        if(head[i]!=NULL)
        {
            //Sortowanie zawartości kubełków
            sortuj(head[i]);
            wyswietl(head[i]);
        }
        else
        {
            printf("Kubelek jest pusty");
        }
        printf("\n\n");
    }
    
    //Lista wynikowa
    struct element *headW = NULL, *newW = NULL;
    
    //Scalenie list do listy wynikowej
    struct element *x = head[0];
    for(int i = 0; i<n; i++)
    {
        x = head[i];
        while(x!=NULL)
        {
            newW=(struct element*)malloc(sizeof(struct element));
            //Porót do wartości bazowej (int)(liczba*max+1)
            newW->wartosc = (int)(x->wartosc*(max+1));
            headW=dodaj(headW,newW);
            x = x->next;
        }
    }
    printf("Po sortowaniu i zamianie do wartosci poczatkowych:\n");

    //Ponieważ domyslnie elementy są wyświetlane w odwrotnej kolejności, odwracam listę aby wyświetlić ją w sposób przyjaźniejszy użytkownikowi
    headW = odwroc(headW);
    wyswietl(headW);
    printf("\n");

    //Zwolnienie pamięci zarezerwowanej dla list
    headW = usun(headW);
    for(int i = 0; i<n; i++)
    {
        head[i] = usun(head[i]);
    }
}

//Sprawdzenie czy w tablicy są liczby ujemne
int sa_ujemne(ilosc)
{
    for(int i = 0; i<ilosc; i++)
    {
        if(tab_wej[i]<0)
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    printf("Witaj w programie do prezentacji dzialania algorytmow sortujacych! \n");

    //Wczytanie tablicy od uzytkownika
    int ilosc;
    ilosc = wczytaj();

    //Wybor algorytmu z menu
    int wybor;
    do
    {
        printf("Podane liczby to:\n");
        drukuj(tab_wej, ilosc);
        printf("\n");

        wybor=menu();
        system("cls");

        switch (wybor)
        {
        case 1:
            babelkowe_opis();
            wyczysc();
            babelkowe_schemat();
            wyczysc();
            babelkowe_sort(ilosc);
            printf("\nKoniec przentacji sortowania babelkowego\n");
            break;
        case 2:
            wstaw_opis();
            wyczysc();
            wstaw_schemat();
            wyczysc();
            wstaw_sort(ilosc);
            printf("\nKoniec przentacji sortowania przez wstawianie\n");
            break;
        case 3:
            zlicz_opis();
            wyczysc();
            zlicz_schemat();
            wyczysc();
            zlicz_sort(ilosc);
            printf("\nKoniec przentacji sortowania przez zliczanie\n");
            break;
        case 4:
            wybor_opis();
            wyczysc();
            wybor_schemat();
            wyczysc();
            wybor_sort(ilosc);
            printf("\nKoniec przentacji sortowania przez wybor\n");
            break;
        case 5:
            szybkie_opis();
            wyczysc();
            szybkie_schemat();
            wyczysc();
            szybkie_sort(ilosc);
            printf("\nKoniec przentacji sortowania szybkiego\n");
            break;
        case 6:
            kubelkowe_opis();
            wyczysc();
            if(sa_ujemne(ilosc) == -1)
            {
                printf("Brak mozliwosci sortowania kubelkowego liczb ujemnych!\n");
                printf("\nKoniec prezentacji sortowania kubelkowego\n");
                break;
            }
            else
            {
                kubelkowe_sort(ilosc);
                printf("\nKoniec prezentacji sortowania kubelkowego\n");
                break;
            }
        case 9:
            ilosc = wczytaj();
            break;
        case 0:
            printf("Dziekuje za skorzystanie z programu!\n");
            printf("Wcisnij dowolny klawisz aby zamknac program");
            getch();
            system("cls");
            free(tab_wej);
            break;
        default:
            printf("Blad wyboru!");
            break;
        }

        //Wymazywanie ekranu
        if(wybor != 0)
        {
            wyczysc();
        }

    } while(wybor != 0);
    return 0;
}