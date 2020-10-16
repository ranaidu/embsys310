Problem 1: Embedded device example

Using the telegraph example, and the challenges listed in the module as reference, and describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.

Another interesting example I think of is Electronic toll collection system which allows nonstop toll collection as well as continuous monitoring of traffic.

How it works?
* Each vehicle will have a unique RFID tag.
* Toll plaza will have a receiver module which contains microcontroller.
* This microcontroller will connect to different peripherical like LCD display, RFID reader, Controller…
* Every time vehicle approach to toll plaza tag fixed on vehicle activate by signal of reader and send ID to the reader.
* System access the data corresponding to that ID and transaction begin, depend on the balance available, toll will deduct directly.
* All toll plazas will be connected to each other to centralized server thus updating and monitoring is very easy.

Design  Challenges:
* Response – microcontroller should complete its response before the vehicle cross the plaza, so the response should be fast.
* Throughput – The number of vehicles might be huge some time
* Testability – The data/connectivity of the module might lost. The conditions in the outdoors might be entirely different than the test environment.
* Reliability – The system should be reliable. Both toll plaza authority and vehicle user reliable on this system.
* Program Installation and Updates – May need some special procedure to updates as it is practically not possible to unmount and do the updates.
* Security – Need to protect the user data like vehicle registration, bank Inforamtions…  
