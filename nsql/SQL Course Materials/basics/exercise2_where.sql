-- Get the orders placed by this year(using 2018)

select * from orders
where order_date > '2017-12-31' and order_date < '2019-01-01';
