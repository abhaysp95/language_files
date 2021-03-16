/* Practice Problem 1 */


Drop table customer cascade constraints;
Drop table greetingcard cascade constraints;

create table customer(
customerid VARCHAR2(5) primary key check(customerid like 'C%'),
custname VARCHAR2(10));

insert into customer values('C101','Stephan');
insert into customer values('C102','Simon');
insert into customer values('C103','Eliza');
insert into customer values('C104','Maria');


Create table greetingcard (
cardid VARCHAR2(5) primary key check(cardid like 'GC%'),
customerid VARCHAR2(5) references customer(customerid),
category  VARCHAR2(20),
Price NUMBER);

Insert into greetingcard values ('GC101','C101','Festive Special', 250);
Insert into greetingcard values ('GC102', 'C102', 'Wedding Special', 400);
Insert into greetingcard values ('GC103','C104', 'Birthday Special', 450);
Insert into greetingcard values ('GC104','C102', 'Festive Special', 500);
Insert into greetingcard values ('GC105', 'C103','Birthday Special', 300);
Insert into greetingcard values ('GC106', 'C104','Wedding Special', 600);

select * from customer;
select * from greetingcard;



/* Practice Problem 2 */


DROP TABLE patient cascade constraints ;
drop table doctor cascade constraints;
drop table consultation cascade constraints;

Create table patient(
patientid varchar2(5) primary key check(patientid like 'P%'),
pname varchar2(15) not null,
city varchar2(15)
);

Insert into patient values('P101','Kevin','New York');
Insert into patient values('P102','Merlin','Boston');
Insert into patient values('P103','Eliza','Chicago');
Insert into patient values('P104','Robert','New York');
Insert into patient values('P105','David','Chicago');

Create table doctor (
doctorid varchar2(5) primary key check(doctorid like 'D%'),
dname  VARCHAR2(20),
dept  VARCHAR2(20),
salary NUMBER);


Insert into doctor values ('D201','Jane', 'Cardiology', 150000);
Insert into doctor values ('D202','Maria', 'Nephrology', 110000);
Insert into doctor values ('D203','John', 'Cardiology', 160000);
Insert into doctor values ('D204','Jack', 'Neurology', 125000);



Create table consultation(
consultationid number primary key,
patientid varchar2(5) references patient(patientid),
doctorid varchar2(5) references doctor(doctorid),
fee number
);


Insert into consultation values(501,'P101','D204',500);
Insert into consultation values(502,'P102','D201',600);
Insert into consultation values(503,'P103','D202',450);
Insert into consultation values(504,'P104','D203',550);
Insert into consultation values(505,'P105','D203',550);
Insert into consultation values(506,'P101','D202',450);

select * from patient;
select * from doctor;
select * from consultation;


-- this example is from infytq practice problems
