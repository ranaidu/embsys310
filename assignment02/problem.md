## Program 1
			`int main() {
			int counter = 0;
			counter ++;
			counter ++;
			counter ++;
			counter ++;
			counter ++;
			counter ++;
			counter ++;
			return 0;
			}`
### 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
#### a. What is the value of the “counter” from the “Locals” window?
-2147483648
#### b. What is the value of the “counter” in the “Registers” window?
0x80000000
#### c. Please note down if the N and/or V flags are set in the APSR register. And explain why.
Both N and V flags are set. MSB is set to 1 so -ve number and N flag gets set. As the counter is already the max +ve value 0x7FFFFFFF(2147483647) of the integer type, adding 1 will give arithmetic overflow and looped over to the other end of the integer range. So V flag gets set.

### 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”
#### a. What happens to the value of “counter” in the “Locals” window?

The value of counter variable in local window is ZERO.
The range of the integer(signed) is -2147483648 to 2147483647. When you write 0xFFFFFFFF (4294967295) to an interger variable it gets looped over the ranges and the value will be -1. Incrementing the counter value will become ZERO.

#### b. Please note down if the N and/or V flags are set in the APSR register. And explain why.
No flag was set.


### 3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
#### a. What is the value of “counter” in the “Locals” window after incrementing for each value?
2147483648
#### b. Please note down if the N and/or V flags are set in the APSR register. And explain why.
Both was set to 1, MSB is going to set to 1 and overflow happened with addition, so these flags was get set.But as the data type is unsigned integer the sign is not considered.


### 4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:
#### a. What is the value of “counter” in the “Locals” window after incrementing for each value?
The value of the counter variable in local window is ZERO. 0xFFFFFFFF(4294967295) is the max value of the unsigned integer(0-4294967295). Adding 1 to the varaible will looped and become ZERO.

#### b. Please note down if the N and/or V flags are set in the APSR register. And explain why.
No flag was set


### 5. Move the “counter’ variable outside of main (at the top of the file):
#### a. What is the scope of the variable “counter”? 
Global
#### b. Is it still visible in the “Locals” view? 
No
#### c. In which window view can we track “counter” now?
Watch and memory windows
#### d. What is the address of the “counter” variable in memory?
0x20000000


### 6. Change the source code to the following, then run the program in the simulator:
			`int counter = 0x0;
			int main() 
			{
			int *p_int = (int *)0x20000000;
			++(*p_int);
			++(*p_int);
			++(*p_int);
			counter ++;
			return 0;
			}`
#### a. What is the value of “counter” at the end of the program (halting at the return 0 statement)
4
#### b. Explain why the counter value has changed? 
p_int pointer variable is pointing to the same counter memory location so incrementing pointer variable is same as incrementing the counter variable.

### 7. Change the setting of IAR to run the same program on the evaluation board:
#### a. What is the address where “counter” is stored?
0x20000000
#### b. Is the “counter” variable stored in RAM or ROM?
RAM
#### c. What is the value of “counter” at the end of the program (halting at the return 0 statement).
4


