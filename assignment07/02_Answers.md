### 2. Generate the map file for your program and provide details on:
#### a. How much total ROM your program is occupying?
452 Bytes
#### b. How much total RAM your program is using?
8196 Bytes
#### c. What part of your program is using the most ROM?
vector_table, zero_init3, data_init were using more ROM.
#### d. What part of your program is using the most RAM?
Linker is taking more RAM

### 3. Bonus: Is there anything that can be done to optimize the usage of ROM or RAM resources? Explain any options.

Compiler optimization setting to high is decreasing the ROM size drastically. Also coding like unintialized variables will decrese ROM size.