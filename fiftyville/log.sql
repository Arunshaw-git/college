-- Keep a log of any SQL queries you execute as you solve the mystery.
.schema -- to check all the tables and also the relations among tables.

 SELECT description
  FROM crime_scene_reports
  WHERE year=2023
   AND day = 28
   AND month = 7
   AND street ='Humphrey Street';-- to find the details of the crime scene at the time on which the duck was stolen.
 -- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

 SELECT transcript,name
  FROM interviews
  WHERE year=2023
   AND dAY = 28
   AND month = 7 ;-- checked the transcript and the name of the three interviewees, so i know more details about the robbery.

SELECT activity,license_plate,minute,hour
FROM bakery_security_logs
WHERE year=2023
 AND day= 28
 AND month = 7
 AND minute >34
 AND minute <45
 AND hour =10 ;-- to get the license plate number the car which left within the 10 mins of the robbery becuase of the interviwees said so.

SELECT account_number,transaction_type,amount
FROM atm_transactions
WHERE year =2023
 AND day = 28
 AND month = 7
 AND transaction_type = 'withdraw'
 AND atm_location ='Leggett Street';-- to check the transactions becuase the second interviewee said they saw someone withdraw some money from the atm at 'Leggett Street'.

 select city,hour,minute
 from flights,airports
 where destination_airport_id = airports.id
  and year=2023
  AND day= 29
  AND month = 7
  and origin_airport_id =(select id from airports where city ="Fiftyville");-- to checck the earliest flight next day of the robbery because the last interviewee heard the robber.

select name from people,bank_accounts where id = person_id and  person_id in(select person_id from bank_accounts where account_number in (SELECT account_number from atm_transactions where year =2023 and d
ay = 28 and month = 7 and transaction_type = 'withdraw' AND atm_location ='Leggett Street'));-- to get the names of the people who withdrew on the day of robbbery .

select flights.id,city,hour,minute  from flights,airports where destination_airport_id = airports.id and year=2023 AND day= 29 AND month = 7 and -- to get the id of the flight of the earliest leaving flight.

select * from passengers where flight_id =36;-- to get the passsport_number of the passengers with the flight_id 36 which will leave the earliest.

select name,license_plate from people where passport_number in (select passport_number from passengers where flight_id =36);-- to get the deatails of the passengers on the flight to NYC



select name,caller,receiver,day,month from people,phone_calls where day = 28 and caller=phone_number and phone_number='(367) 555-5533';-- to check who talked to bruce less than a minute on 28th day of july

