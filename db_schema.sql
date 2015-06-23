SET character_set_client = utf8;

CREATE TABLE `equipment` (
  `id` int(11) NOT NULL,
  `type` varchar(50) DEFAULT NULL,
  `amount` int(11) DEFAULT '0',
  `condition` char(1) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `history` (
  `id` int(11) NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `surname` varchar(100) DEFAULT NULL,
  `country` varchar(50) DEFAULT NULL,
  `city` varchar(75) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `phone` varchar(15) DEFAULT NULL,
  `type` varchar(50) DEFAULT NULL,
  `amount` int(11) DEFAULT '0',
  `condition` char(1) DEFAULT NULL,
  `rent_from` datetime DEFAULT NULL,
  `rent_to` datetime DEFAULT NULL,
  `price` float DEFAULT NULL,
  `document_type` varchar(20) DEFAULT NULL,
  `document_number` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `prices` (
  `type` varchar(50) NOT NULL DEFAULT '',
  `condition` char(1) NOT NULL DEFAULT '',
  `time` int(11) NOT NULL DEFAULT '0',
  `price` float DEFAULT NULL,
  PRIMARY KEY (`type`,`condition`,`time`)
);

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `surname` varchar(100) DEFAULT NULL,
  `country` varchar(50) DEFAULT NULL,
  `city` varchar(75) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `phone` varchar(15) DEFAULT NULL,
  `document_type` varchar(20) DEFAULT NULL,
  `document_number` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `rent` (
  `user_id` int(11) NOT NULL DEFAULT '0',
  `equipment_id` int(11) NOT NULL DEFAULT '0',
  `amount` int(11) DEFAULT '1',
  `rent_from` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`user_id`,`equipment_id`,`rent_from`),
  KEY `equipment_id` (`equipment_id`),
  CONSTRAINT `rent_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`),
  CONSTRAINT `rent_ibfk_2` FOREIGN KEY (`equipment_id`) REFERENCES `equipment` (`id`)
);

CREATE TABLE `reservations` (
  `user_id` int(11) NOT NULL DEFAULT '0',
  `equipment_id` int(11) NOT NULL DEFAULT '0',
  `amount` int(11) DEFAULT '1',
  `rent_from` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `rent_to` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`user_id`,`equipment_id`,`rent_from`,`rent_to`),
  KEY `equipment_id` (`equipment_id`),
  CONSTRAINT `reservations_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`),
  CONSTRAINT `reservations_ibfk_2` FOREIGN KEY (`equipment_id`) REFERENCES `equipment` (`id`)
);

CREATE VIEW `available_equipment` AS select `A`.`id` AS `id`,`A`.`type` AS `type`,sum(((coalesce(`A`.`amount`,0) - coalesce(`B`.`amount`,0)) - coalesce(`C`.`amount`,0))) AS `amount`,`A`.`condition` AS `condition` from ((`equipment` `A` left join `rent` `B` on((`A`.`id` = `B`.`equipment_id`))) left join `reservations` `C` on((`A`.`id` = `C`.`equipment_id`))) group by `A`.`id`;

CREATE VIEW `usable_equipment` AS select `E`.`id` AS `id`,`E`.`type` AS `type`,`E`.`amount` AS `amount`,`E`.`condition` AS `condition` from (`equipment` `E` join `prices` `P` on(((`E`.`type` = `P`.`type`) and (`E`.`condition` = `P`.`condition`))));