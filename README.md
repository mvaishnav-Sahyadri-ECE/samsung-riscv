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
  </summary>
1. Installing iverilog and gtkwave
   Open your terminal and type the following to install 
   iverilog and GTKWave
   ```sh
sudo apt install iverilog
sudo apt install gtkwave
```sh
iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
./iiitb_rv32i






































































