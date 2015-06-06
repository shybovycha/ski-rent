# Wypożyczalnie sprzętu narciarskiego

## Zadanie

### User stories

1. Przy pierwszym uruchomieniu użytkownik powinien skonfigurować system, dodając istniejący sprzęt do bazy danych
2. Procedura wypożyczania zawiera następne kroki:
    a. klient zamawia sprzęt przez telefon lub internet (nieobowiązkowo)
    b. zostawia dokument (paszport lub dowód tożsamości) na czas pożyczki w biurze
    c. odbiera sprzęt i używa go przez pewny czas (może być dłużej, niż rezerwacja)
    d. oddaje sprzęt i opłaca fakturę
    e. odbiera swój dokument
3. Jeżeli wszystkie sprzęty pewnego typu (narty, deski...) jest zarezerwowany, nikt oprócz osoby rezerwujący  nie może go wypożyczyć
4. System powinien wyświetlić tylko sprzęt dostępny do wynajęcia, a także sprzęt wynajęty i sprzęt zarezerwowany
5. System powinien również umożliwiać reserwację sprzętu
6. Dane dotyczące wypożyczań zachowują się w BD i nie podlegają zmianom

### Schemat BD

Baza danych tworzy się przy pomocy kodu SQL z pliku `db_schema.sql`.

Schemat bazy danych narysowany poniżej:

![DB schema](https://raw.githubusercontent.com/shybovycha/ski-rent/master/doc/db_structure.png)

## Harmonogram i realizowana technologię

Realizowana technologia: C++ w oparciu o framework Qt; baza danych MySQL.

Harmonogram pracy na dwa miesięcy:

    1. projektowanie interfejsu użytkownika - 1 tydzień
    2. łączenie programu z bazą danych (m. in. tworzenie architektury oraz je implementacja) - 1 tydzień
    3. implementacja interfejsu zarządania sprzętem - 1 tydzień
    4. implementacja interfejsu wyświetlenia rezerwacji sprzętu (m. in. architekturne rozwiązanie) - 2 tygodni
    5. implementacja interfejsu wypożyczania i zwracania sprzętu - 2 tygodni
    6. pakowanie programu w wersji "standalone" oraz prezentacja projektu - 1 tydzień
