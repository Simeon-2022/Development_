--UPDATE INVOICES SET DUE_DATE = NULL;
/
CREATE OR REPLACE PROCEDURE insert_due_date AS
    cursor c_insert_due_date is
        select i.inv_no,i.due_date, i.issue_date,c.credit_limit,c.customer_id
        from invoices i
        inner join customers c
        on i.customer_id = c.customer_id
        where i.due_date is NULL;
    var_c_insert_due_date c_insert_due_date%ROWTYPE;
    var_due_date date;
    var_counter number := 0;
BEGIN
    open c_insert_due_date;
    fetch c_insert_due_date into var_c_insert_due_date;
    while c_insert_due_date %found
    LOOP
        CASE
            WHEN var_c_insert_due_date.credit_limit < 5000 THEN
                var_due_date := var_c_insert_due_date.issue_date + INTERVAL '10' DAY;
            WHEN var_c_insert_due_date.credit_limit BETWEEN 5000 AND 8000 THEN
                var_due_date := var_c_insert_due_date.issue_date + INTERVAL '15' DAY;
            ELSE
                var_due_date := var_c_insert_due_date.issue_date + INTERVAL '20' DAY;
        END CASE;
        UPDATE invoices
        SET due_date = var_due_date
        WHERE inv_no = var_c_insert_due_date.inv_no;
        
        var_counter := var_counter + 1;
        
        if mod(var_counter, 100) = 0 then
            commit;
        end if;
        
        fetch c_insert_due_date into var_c_insert_due_date;
    END LOOP;
    
    if mod(var_counter, 100) <> 0 then
        commit;
    end if;
    
    close c_insert_due_date;
END;
/
exec insert_due_date;
/
SELECT * FROM INVOICES
INNER JOIN CUSTOMERS C
ON INVOICES.CUSTOMER_ID = C.CUSTOMER_ID
WHERE DUE_DATE IS NULL;
/
select i.due_date, i.issue_date,c.credit_limit,c.customer_id
from invoices i
inner join customers c
on i.customer_id = c.customer_id
where c.customer_id = 30;
/
create table over_payments (
       invoice_no      varchar2(50),
       payment_id      varchar2(60),
       payment_dt      date,
       amount          number(10,2),
       payment_method  varchar2(10),
       currency        varchar2(3),
       fg_processed    varchar2(1),
       iban            varchar2(60),
       bank_name       varchar2(100),
       created_by      varchar2(50),
       free_text       varchar2(1000),
       original_payment_id varchar2(60),
       constraint op_paym_no_pk primary key (payment_id) ,
       CONSTRAINT op_fk_inv FOREIGN KEY (invoice_no) REFERENCES 
invoices(inv_no)
);
/
alter table over_payments
   add constraint fk_over_pay_id_orig_paym_id
   foreign key (original_payment_id) references payments(payment_id)
   deferrable initially deferred;
/
   
   