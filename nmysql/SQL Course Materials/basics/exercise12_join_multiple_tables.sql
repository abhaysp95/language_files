-- join more than 2 tables

use sql_invoicing;

select
	p.date,
	p.payment_id,
	c.name,
	p.invoice_id,
	p.amount,
	pm.name as "payment method"
from payments p
join clients c
	on p.client_id = c.client_id
join payment_methods pm
	on pm.payment_method_id = p.payment_method
order by p.amount desc;
