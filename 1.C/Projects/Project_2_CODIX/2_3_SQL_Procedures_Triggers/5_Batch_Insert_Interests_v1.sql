SET TIMING ON;
CREATE OR REPLACE PROCEDURE insert_interests(var_ext_reff varchar2)
AS
    var_limit1                   NUMBER := 5000;
    var_limit2                   NUMBER := 8000;
    var_under_limit1_days        NUMBER := 10;
    var_above_limit1_days        NUMBER := 15;
    var_above_limit2_days        NUMBER := 20;
    var_interest_percent         NUMBER(10,2) := 0.05;
    var_days_to_new_issue_date   NUMBER := 5;
    var_days_to_new_due_date     NUMBER;
    var_invoice_max_seq          NUMBER;
    CURSOR c_not_payed IS SELECT i.inv_no, i.amount, i.amount_due, i.issue_date, 
                                     i.due_date, I.currency, i.customer_id, I.seq, i.original_invoice_id, c.credit_limit 
                            FROM invoices i
                           INNER JOIN customers c
                              ON c.customer_id = i.customer_id
                           WHERE i.amount_due IS NOT NULL
                             AND i.original_invoice_id IS NULL 
                             AND ( var_ext_reff IS NULL OR c.external_reference = var_ext_reff )
                             AND NOT EXISTS ( SELECT inv.inv_no FROM invoices inv WHERE original_invoice_id = i.inv_no );
    var_c_not_payed              c_not_payed%ROWTYPE;
    failed_insert                EXCEPTION;
BEGIN
    OPEN c_not_payed;
    FETCH c_not_payed INTO var_c_not_payed;
    WHILE c_not_payed %FOUND
    LOOP
        SELECT MAX(seq) INTO var_invoice_max_seq
        FROM invoices
        WHERE customer_id = var_c_not_payed.customer_id;
                
        IF var_c_not_payed.credit_limit < var_limit1 THEN var_days_to_new_due_date := var_under_limit1_days; 
        ELSE IF var_c_not_payed.credit_limit BETWEEN var_limit1 AND var_limit2 THEN var_days_to_new_due_date := var_above_limit1_days; 
            ELSE var_days_to_new_due_date := var_above_limit2_days; 
            END IF;
        END IF;
        
        INSERT INTO invoices(inv_no, 
                    amount, 
                    amount_due, 
                    currency,
                    issue_date, 
                    due_date, 
                    customer_id, 
                    seq, 
                    original_invoice_id) 
             VALUES (TO_CHAR(var_c_not_payed.customer_id)||'_'||TO_CHAR(var_invoice_max_seq + 1)||'_'||TO_CHAR(var_c_not_payed.due_date + var_days_to_new_issue_date, 'YYYYMMDD'),
                    ROUND(var_c_not_payed.amount_due*var_interest_percent, 2),
                    ROUND(var_c_not_payed.amount_due*var_interest_percent, 2), 
                    var_c_not_payed.currency, 
                    var_c_not_payed.due_date + var_days_to_new_issue_date, 
                    var_c_not_payed.due_date + var_days_to_new_issue_date + var_days_to_new_due_date, 
                    var_c_not_payed.customer_id,
                    var_invoice_max_seq + 1,
                    var_c_not_payed.inv_no);
        IF SQL%NOTFOUND THEN RAISE failed_insert;
        END IF;
        COMMIT;    
        FETCH c_not_payed INTO var_c_not_payed;
    END LOOP;
EXCEPTION
    WHEN failed_insert THEN ROLLBACK; RAISE failed_insert;
END;
/
exec insert_interests('EXT42');
exec insert_interests('');
/
BEGIN
    DBMS_SCHEDULER.CREATE_JOB (
            job_name => 'JOB_INSERT_INTERESTS',
            job_type => 'PLSQL_BLOCK',
            job_action => 'exec insert_interest('');',
            number_of_arguments => 0,
            start_date => TRUNC(SYSDATE) + INTERVAL '1' DAY,
            repeat_interval => 'FREQ=DAILY;BYHOUR=0;BYMINUTE=0;BYSECOND=0',
            end_date => NULL,
            enabled => TRUE,
            auto_drop => FALSE,
            comments => 'Insert interest 5 days after due_date.');
END;
/
BEGIN
    DBMS_SCHEDULER.RUN_JOB(job_name => 'JOB_INSERT_INTERESTs', USE_CURRENT_SESSION => FALSE);
END;
/
select i.inv_no,i.amount, i.amount_due, i.issue_date, i.due_date, i.customer_id, c.credit_limit, I.ORIGINAL_INVOICE_ID, I.SEQ
from invoices i
inner join customers c
on c.customer_id = i.customer_id
where C.customer_id = 42 AND I.AMOUNT_DUE IS NOT NULL
order by 6, 9;
/
DELETE FROM invoices
where customer_id = 42 and ORIGINAL_INVOICE_ID is not NULL;
/