## Digital_Access_Control_System with Atemga32:

## *********  Overview  *********  

 - This project implements a secure two-step authentication system using the ATmega32 microcontroller.
 - The system first requests a User ID, then a Password.
 - It provides three password attempts with a countdown shown on a Seven-Segment Display (SSD).
 - If the ID is wrong, the system shuts down immediately.
 - If the password is correct within the allowed attempts, access is granted.

## *********  features  ********* 
Two-step authentication:
1- Enter ID → Verify.
2- Enter Password → Verify (up to 3 attempts).
3- Three password attempts shown on SSD countdown.
4- mmediate access if password is correct before 3 attempts finish.
5- Green LED + LCD message "Access Granted" on success.
6- Shutdown mechanism if:
   - ID is incorrect.
   - Password attempts exceed 3 without success.
7- CLCD displays all prompts and status messages.
   
## *********  How It Works  *********  
1- Startup → LCD displays "Enter ID:".

2- ID Verification:
   - If correct → LCD displays "Enter Password:" and SSD shows 3 attempts remaining.
   - If incorrect → System shuts down immediately.

3- Password Attempts: 
   - User can enter the password up to 3 times.
   - SSD updates after each failed attempt (3 → 2 → 1).

4- If password is correct at any attempt:
   - Green LED turns ON.
   - LCD displays "Access Granted".

5- If all 3 attempts fail → LCD displays "Access Denied" and system shuts down.




