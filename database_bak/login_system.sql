create table users (
	user_id int(11) AUTO_INCREMENT PRIMARY KEY not null,
	user_fist varchar(256) not null,
	user_last varchar(256) not null,
	user_email varchar(256) not null,
	user_uid varchar(256) not null,
	user_pwd varchar(256) not null
);

insert into users (user_first, user_last, user_email, user_uid, user_pwd) values ('Denial', 'Nielson', 'usermmtut@gmail.com', 'Admin', 'admintest123');
insert into users (user_first, user_last, user_email, user_uid, user_pwd) values ('Jane', 'Foster', 'JFoster@gmail.com', 'jfstr', 'jane4jane');
insert into users (user_first, user_last, user_email, user_uid, user_pwd) values ('Brian', 'Ocorner', 'BrainDS@ocorner.com', 'Brian', '1loveMi0');
