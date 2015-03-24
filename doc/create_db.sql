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
		A.id, 
        A.`type`, 
        A.amount - B.amount - C.amount as amount,
        A.`condition`
	from equipment as A
    left join rent as B on A.id = B.equipment_id
    left join reservations as C on A.id = C.equipment_id;