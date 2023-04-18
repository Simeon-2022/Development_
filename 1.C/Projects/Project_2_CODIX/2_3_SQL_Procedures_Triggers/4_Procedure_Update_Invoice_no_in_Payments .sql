EXECUTE update_payments_with_invoices_3;

CREATE OR REPLACE PROCEDURE update_payments_with_invoices_3 AS
    invoice_number_due invoices_test.inv_no%TYPE; -- 
    payment_found BOOLEAN := TRUE;
BEGIN
    WHILE payment_found LOOP
        payment_found := FALSE; -- set to false at the beginning of each iteration
        FOR payment_rec IN (
            SELECT *
            FROM over_payments_test
        --  WHERE invoice_no IS NULL AND original_payment_id IS NOT NULL
        )
        LOOP
            BEGIN
                -- Find the invoice that this payment can cover
                SELECT inv_no
                INTO invoice_number_due -- to be set to null
                FROM invoices_test
                WHERE customer_id =
                    (
                        SELECT i.customer_id
                        FROM invoices_test i, payments_test p 
                        WHERE i.inv_no = p.invoice_no
                        AND p.payment_id = payment_rec.original_payment_id
                        AND ROWNUM = 1
                    )
                    AND amount_due > 0
                    AND ROWNUM = 1;
                    
                IF invoice_number_due IS NOT NULL THEN -- an invoice with funds available is found
                    payment_found := TRUE; -- set to true to continue the loop
                    -- Update the payment with the invoice number
               insert into payments_test ( invoice_no, payment_id, payment_dt, amount , payment_method, currency, iban, bank_name, created_by, free_text , original_payment_id) 
               values ( invoice_number_due , payment_rec.payment_id, payment_rec.payment_dt, payment_rec.amount , payment_rec.payment_method , payment_rec.currency, payment_rec.iban, payment_rec.bank_name, payment_rec.created_by, payment_rec.free_text , payment_rec.original_payment_id);
    
                delete over_payments_test where payment_id = payment_rec.payment_id;     
                    
                END IF;
            EXCEPTION
                WHEN OTHERS THEN
                    -- Handle any other exceptions by logging them
                    DBMS_OUTPUT.PUT_LINE('Error processing payment_id: ' || payment_rec.payment_id || ', error message: ' || SQLERRM);
                    NULL;
            END;
             COMMIT;
        END LOOP;
        IF NOT payment_found THEN -- exit the loop if there are no more funds available
            EXIT;
        END IF;
    END LOOP;
END;
/

