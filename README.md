# Samsung-riscv 

This internship program focuses on RISC-V architecture using the VSDSquadron Mini platform. It leverages open-source tools to provide students with hands-on experience in VLSI SoC design and RISC-V development.

Guided by Mr. Kunal Ghosh, Co-Founder of VSD, this program offers an opportunity to gain practical knowledge and industry insights in RISC-V









<details>
  <summary>📜 Task 1 : Development of C Based LAB </summary>

![C Code compiled on gcc Compiler](https://github.com/user-attachments/assets/bd8429ec-23df-4fa4-9ca7-788d9e5befa7)

![C Code compiled on riscv gcc Compiler](https://github.com/user-attachments/assets/8d30a9e8-ff7f-4d84-88ce-7f7bf6364a15)

![Cat command for Code Display](https://github.com/user-attachments/assets/f08ed42c-ec33-487b-ada5-56fcca0de43e)

![Objdump using -O1 format](https://github.com/user-attachments/assets/de0dfade-b114-4417-a3c5-ca6e793e1961)

![Objdump using -Ofast format](https://github.com/user-attachments/assets/4a0f67a8-af2b-436a-91a5-c1b3fab28aa5)
</details>

<details>
  <summary>📜 Task 2 : Simulation with Spike </summary>

![Debugging in -O1](https://github.com/user-attachments/assets/ff05cc31-cb15-4532-bff6-a316e5f23cc1)

![Debugging in Ofast](https://github.com/user-attachments/assets/7cb3355e-e048-4d71-b4ee-3cf634b47b2c)

![Objdump in -O1 Format](https://github.com/user-attachments/assets/4552d0c2-eedc-4b80-a6e0-a9b534cdb5ca)

![objdump in -Ofast](https://github.com/user-attachments/assets/75e01393-ff8c-4d51-9a07-86361e636014)

![Spike Simulation](https://github.com/user-attachments/assets/bc55c580-9bf2-45f5-be19-8a8468126369)
</details>

<details>
  <summary>📜 Task 3 : RISCV instructions </summary>

![Objdump in -O1 Format](https://github.com/user-attachments/assets/82cfea2b-41b0-40d6-a244-d321eb30b4d4)


## 1. addi sp, sp, -16
Opcode(ADDI): 0010011  
Immediate: -16 = 1111111111110000 (12 bits)  
Registers: sp(rd) = 00010, sp(rs1) = 00010  

| imm[11:0]       | rs1    | funct3 | rd    | opcode  |
|------------------|--------|--------|-------|---------|
| 111111000000    | 00010  | 000    | 00010 | 0010011 |
---

## 2. sd ra, 8(sp)
Opcode(SD): 0100111  
Immediate: 8 (split into two parts: imm[11:5] and imm[4:0])  
Registers: rs1 = sp = 00010, rs2 = ra = 00001  

| imm[11:5] | rs2   | rs1   | funct3 | imm[4:0] | opcode  |
|-----------|-------|-------|--------|----------|---------|
| 0000000   | 00001 | 00010  | 011    | 01000    | 0100111 |
---

## 3. li a5, 100
Opcode(ADDI): 0010011  
Immediate: 100 = 00000001100100  
Registers: rd = a5 = 01010, rs1 = x0 = 00000  

| imm[11:0]     | rs1   | funct3 | rd    | opcode  |
|---------------|-------|--------|-------|---------|
| 00001100100   | 00000 | 000    | 01010 | 0010011 |
---

## 4. addiw a5, a5, -1
Opcode(ADDIW): 0011011  
Registers: rd = a5 = 01010, rs1 = a5 = 01010  
Immediate: -1 = 111111111111 (sign-extended 12-bit value)  

| imm[11:0]     | rs1   | funct3 | rd    | opcode  |
|---------------|-------|--------|-------|---------|
| 111111111111  | 01010 | 000    | 01010 | 0011011 |
---

## 5. bnez a5, 10190
Opcode(BNE): 1100011  
Registers: rs1 = a5 = 01010, rs2 = x0 = 00000  
Immediate: Offset (branch) = 10190  

| imm[12|10:5] | rs2   | rs1   | funct3 | imm[4:1|11] | opcode  |
|--------------|-------|-------|--------|------------|---------|
| 101001       | 00000 | 01010 | 001    | 101010     | 1100011 |
---

## 6. li a2, 1830
Opcode(ADDI): 0010011  
Immediate: 1830 = 0001110010110  
Registers: rd = a2 = 00010, rs1 = x0 = 00000  

| imm[11:0]      | rs1   | funct3 | rd    | opcode  |
|-----------------|-------|--------|-------|---------|
| 000111001011   | 00000 | 000    | 00010 | 0010011 |
---

## 7. lui a0, 0x21
Opcode(LUI): 0110111  
Immediate (0x21 << 12): 000000100001  
Register (rd): a0 = 00010  

| imm[31:12]      | rd      | opcode  |
|------------------|---------|---------|
| 000000100001     | 00010   | 0110111 |
---

## 8. jal ra, 10414
Opcode(JAL): 1101111  
Immediate: 10414  
Register (rd): ra = 00001  

| imm[20] | imm[10:1] | imm[11] | imm[19:12] | rd    | opcode  |
|---------|-----------|---------|------------|-------|---------|
|   0     |0101000101 |    0    |  10010100  | 00001 | 1101111 |
---

## 9. li a0, 0
Opcode(ADDI): 0010011  
Immediate: 0  
Registers: rd = a0 = 00010, rs1 = x0 = 00000  

| imm[11:0]     | rs1   | funct3 | rd    | opcode  |
|---------------|-------|--------|-------|---------|
| 000000000000  | 00000 | 000    | 00010 | 0010011 |
---

## 10. ld ra, 8(sp)
Opcode(LD): 0000011  
Immediate: 8  
Registers: rd = ra = 00001, rs1 = sp = 00010  

| imm[11:0]      | rs1   | funct3 | rd    | opcode  |
|-----------------|-------|--------|-------|---------|
| 000000001000    | 00010 | 011    | 00001 | 0000011 |
---

## 11. addi sp, sp, 16
Opcode(ADDI): 0010011  
Immediate: 16 = 000000010000  
Registers: sp(rd) = 00010, sp(rs1) = 00010  

| imm[11:0]      | rs1   | funct3 | rd    | opcode  |
|-----------------|-------|--------|-------|---------|
| 000000010000    | 00010 | 000    | 00010 | 0010011 |
---

## 12. ret
Opcode(JALR): 1100111  
Immediate: 0  
Registers: rd = x0 = 00000, rs1 = ra = 00001  

| imm[11:0]     | rs1   | funct3 | rd    | opcode  |
|---------------|-------|--------|-------|---------|
| 000000000000  | 00001 | 000    | 00000 | 1100111 |
---

## 13. mv a1, a0
Opcode(ADDI): 0010011  
Immediate: 0  
Registers: rd = a1 = 00011, rs1 = a0 = 00010  

| imm[11:0]     | rs1   | funct3 | rd    | opcode  |
|---------------|-------|--------|-------|---------|
| 000000000000  | 00010 | 000    | 00011 | 0010011 |
---

## 14. li a3, 0
Opcode(ADDI): 0010011  
Immediate: 0  
Registers: rd = a3 = 00111, rs1 = x0 = 00000  

| imm[11:0]     | rs1   | funct3 | rd    | opcode  |
|---------------|-------|--------|-------|---------|
| 000000000000  | 00000 | 000    | 00111 | 0010011 |
---

## 15. li a0, 0
Opcode(ADDI): 0010011  
Immediate: 0  
Registers: rd = a0 = 00010, rs1 = x0 = 00000  

| imm[11:0]     | rs1   | funct3 | rd    | opcode  |
|---------------|-------|--------|-------|---------|
| 000000000000  | 00000 | 000    | 00010 | 0010011 |
---
tions.md…]()
</details>

<details>
  <summary>📜 Task 4 : RISC-V Core Functional Simulation
  </summary> Run the command as follows :
1. Installing iverilog and gtkwave
  
   Open your terminal and type the following to install 
   iverilog and GTKWave

    sudo apt install iverilog
    sudo apt install gtkwave
2. To run and simulate the verilog code
   
   iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
   ./iiitb_rv32i

3. To see the simulation waveform in GTKWave
   
    gtkwave iiitb_rv32i.vcd
   
![terminalinstructions](https://github.com/user-attachments/assets/dfb8947f-cea8-4fc5-a9f9-7946365be2dc)

32-bits instruction

![instructions](https://github.com/user-attachments/assets/dc8821ed-a8c7-464d-8f2d-1abdce3ecc77)

1. add r6,r1,r2
![add](https://github.com/user-attachments/assets/f3aa4dc6-1e62-40a6-9db6-10aea5ae7ab2)

2. and r8,r1,r3
![and](https://github.com/user-attachments/assets/5dc78647-5430-41ff-b4d0-95059f9f65e7)
   
3. beq r0,r0,r15
![beq](https://github.com/user-attachments/assets/437e502e-ab45-4e3f-9846-acc20cf1a0ee)

4. xor r10,r1,r4
![xor](https://github.com/user-attachments/assets/d9b45186-0549-481c-9657-ea59c682da2e)

5. sub r7,r1,r2
![sub1](https://github.com/user-attachments/assets/c22924cb-3e9b-4a33-9776-11631a6b74aa)

6. slt r11,r2,r4
![slt](https://github.com/user-attachments/assets/5f1cf316-8bd2-45d9-802d-fa7a3e855e64)

7. or r9,r2,r5
![or](https://github.com/user-attachments/assets/586fd6ed-238f-4d27-8590-c6721efb70b7)

8. addi r12,r4,5
![addi](https://github.com/user-attachments/assets/d7c794c3-0453-4ec0-a860-11e593029115)

waveforms
![waveforms](https://github.com/user-attachments/assets/b37e106d-f853-4a04-99e8-420fa8d44038)

</details>

<details>
  <summary>📜 Task 5 : Project Overview  </summary>

1. Circuit Diagram
   ![Circuit Diagram](https://github.com/user-attachments/assets/0bcb1d67-c8bc-47cd-8735-87b48a8893a8)

2. Components Required

   Microcontroller – VSDsquadron mini

   LEDs (at least 4) – To represent binary values and parity

   Resistors (~220Ω for LEDs)

   Push Buttons (3) – To simulate binary input (Here I 
   simulated switch Manually)

   Breadboard – For easy circuit assembly

   Jumper Wires – For connections

3. Table for pin connections
   ![Table for pin connections](https://github.com/user-attachments/assets/e891b009-6031-4323-b64e-954a7a6a5782)

4. Example scenario
   ![Table for pin connections](https://github.com/user-attachments/assets/7261159b-6417-4f1f-a894-42e956460cd3)

5. Overview of application

A parity checker is a logic circuit used to detect errors in transmitted data. It verifies the correctness of the received data by analyzing the parity bit, which is an extra bit added to the original data to ensure the total number of 1s is either even or odd.

There are two main types of parity checkers: even parity checkers and odd parity checkers. An even parity checker counts the number of 1s in the received data and ensures that the total number of 1s is even, including the parity bit. If the count is odd, it indicates an error.
Conversely, an odd parity checker ensures that the total number of 1s is odd. If the count is even, it indicates an error.

In My project, LEDs represent binary data, and a 4th LED indicates the parity (error detection).

🔹 How It Works?
-Three LEDs (PC0, PC1, PC2) Represent a 3-Bit Binary Number

-Each LED ON = 1, OFF = 0

-The combination of ON/OFF states forms a 3-bit binary input
 User Inputs Data by Connecting PC4, PC5, PC6 to VCC (1) or GND (0)

-If an input pin is left open, an internal pull-down resistor ensures it is read as 0

-When connected to VCC, it is read as 1 The System Computes Parity

-Even Parity: If the number of 1s in the binary input is even, the parity LED (PC3) remains OFF (0)
Odd Parity: If the number of 1s is odd, the parity LED (PC3) turns ON (1) Detecting Errors

-If the expected parity and computed parity do not match, it indicates a possible error.
This is a simple error detection mechanism used in communication systems.

</details>

<details>
  <summary>📜 Task 6 : Project Demonstration and code </summary>

Demonstration



https://github.com/user-attachments/assets/6853f46d-5616-47ca-afcc-480296e5c712


Code 

[main.txt](https://github.com/user-attachments/files/18933778/main.txt)

</details>






