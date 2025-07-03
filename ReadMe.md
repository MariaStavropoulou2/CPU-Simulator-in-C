# CPU Simulator in C

This project is a simple CPU simulator implemented in the C programming language.  
It simulates a 4-bit architecture with two registers (`R1`, `R2`) and a main memory consisting of 10 words of 4 bits each.

---

## 🔧 Features

- Two 4-bit registers: `R1`, `R2`
- Main memory: 10 addresses (`memory[10][4]`)
- Commands for loading, storing, adding, subtracting, and viewing data
- Command-line based interpreter (one instruction per line)
- Binary-to-decimal conversions and overflow handling

---

## 📌 Commands Supported

| Command           | Description                                                       |
|------------------|-------------------------------------------------------------------|
| `BOOT`           | Initializes memory and registers with random 0/1 values           |
| `LOAD R1 5`      | Loads the contents of memory address 5 into register `R1`         |
| `STORE R2 3`     | Stores the contents of register `R2` into memory address 3        |
| `ADD R1`         | Adds `R1 + R2` and stores the result in `R1`                      |
| `SUB R2`         | Subtracts `R1` from `R2` and stores the result in `R2`            |
| `SHOW R1`        | Displays the current binary value of register `R1`                |
| `MEM`            | Displays the current contents of the entire memory                |
| `STOP`           | Terminates the program                                            |

---

## 💻 Example Session

```text
Enter command: BOOT
System initialized.

Enter command: LOAD R1 2
Loaded into R1.

Enter command: SHOW R1
R1: 1010

Enter command: LOAD R2 3
Loaded into R2.

Enter command: ADD R1
Addition result stored in R1.

Enter command: SHOW R1
R1: 1100

Enter command: STORE R1 5
Stored R1 into memory.

Enter command: MEM
Address 0: 0001
Address 1: 1010
...
Address 5: 1100
...

Enter command: STOP
Program terminated.
