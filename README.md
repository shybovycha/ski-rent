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

Baza danych tworzy się przy pomocy następnego kodu SQL:

    create database ski_rent;

    use ski_rent;

    create table users (id int primary key auto_increment, `name` varchar(100), surname varchar(100), document_type varchar(20), document_number varchar(20), country varchar(50), city varchar(75), address varchar(100), phone varchar(15));

    create table equipment (id int primary key auto_increment, `type` varchar(50), amount int default 0, `condition` char(1));

    create table prices (`type` varchar(50), `condition` char(1), `time` int, price float, primary key (`type`, `condition`, `time`));

    create table rent (user_id int, equipment_id int, amount int default 1, rent_from datetime, primary key (user_id, equipment_id, rent_from), foreign key (user_id) references users (id), foreign key (equipment_id) references equipment (id));

    create table reservations (user_id int, equipment_id int, amount int default 1, rent_from datetime, rent_to datetime, primary key (user_id, equipment_id, rent_from, rent_to), foreign key (user_id) references users (id), foreign key (equipment_id) references equipment (id));

    create table history (id int primary key auto_increment, `name` varchar(100), surname varchar(100), pesel varchar(20), country varchar(50), city varchar(75), address varchar(100), phone varchar(15), `type` varchar(50), amount int default 0, `condition` char(1), rent_from datetime, rent_to datetime, price float);

    create view available_equipment as
		select
			`A`.`id` AS `id`,
			`A`.`type` AS `type`,
			sum((coalesce(`A`.`amount`,0) - coalesce(`B`.`amount`,0)) - coalesce(`C`.`amount`,0)) AS `amount`,
			`A`.`condition` AS `condition`
		from
			((`equipment` `A` left join `rent` `B` on ((`A`.`id` = `B`.`equipment_id`))) left join `reservations` `C` on((`A`.`id` = `C`.`equipment_id`)))
		group by A.id;

    delimiter $$

    -- ----------------------------------------------------------------------------------------------

    create procedure `quickSearchEquipment`(searchQuery text, out errMessage varchar(255))
    begin
        declare exit handler for sqlexception
        begin
            set errMessage = 'Error in procedure quickSearchEquipment';
        end;

        select * from `available_equipment` where (`type` like searchQuery) OR (`amount` like searchQuery) OR (`condition` like searchQuery);
    end
    $$

    -- ----------------------------------------------------------------------------------------------

    create procedure `quickSearchUsers`(searchQuery text, out errMessage varchar(255))
    begin
        declare exit handler for sqlexception
        begin
            set errMessage = 'Error in procedure quickSearchEquipment';
        end;

        select * from `users` where (`type` like searchQuery) OR (`amount` like searchQuery) OR (`condition` like searchQuery);
    end
    $$

    -- ----------------------------------------------------------------------------------------------

    delimiter ;

Schemat bazy danych narysowany poniżej:

[]()

## Harmonogram i realizowana technologię

Realizowana technologia: C++ w oparciu o framework Qt; baza danych MySQL.

Harmonogram pracy na dwa miesięcy:

    1. projektowanie interfejsu użytkownika - 1 tydzień
    2. łączenie programu z bazą danych (m. in. tworzenie architektury oraz je implementacja) - 1 tydzień
    3. implementacja interfejsu zarządania sprzętem - 1 tydzień
    4. implementacja interfejsu wyświetlenia rezerwacji sprzętu (m. in. architekturne rozwiązanie) - 2 tygodni
    5. implementacja interfejsu wypożyczania i zwracania sprzętu - 2 tygodni
    6. pakowanie programu w wersji "standalone" oraz prezentacja projektu - 1 tydzień
