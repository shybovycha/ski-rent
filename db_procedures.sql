    delimiter $$

    -- ----------------------------------------------------------------------------------------------

    create procedure `quickSearchEquipment`(in query text, out errMessage varchar(255))
    begin
        declare exit handler for sqlexception
        begin
            set errMessage = 'Error in procedure quickSearchEquipment';
        end;

        select * from `available_equipment` where (`type` like query) OR (`amount` like query) OR (`condition` like query);
    end
    $$

    -- ----------------------------------------------------------------------------------------------

    create procedure `quickSearchUsers`(in query text, out errMessage varchar(255))
    begin
        declare exit handler for sqlexception
        begin
            set errMessage = 'Error in procedure quickSearchEquipment';
        end;

        select * from `users` where (`type` like query) OR (`amount` like query) OR (`condition` like query);
    end
    $$

    -- ----------------------------------------------------------------------------------------------

    delimiter ;
