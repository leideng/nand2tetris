// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

// R2 = 0;
// for i=1,2,... R1
// {
//      R2 = R0 + R2
// }

//set R2=0
    @R2
    M=0
    
//set i=1
    @i
    M=1
    
//mail loop
(LOOP)
//get i and store into D register
    @i
    D=M
    
//get R1, and get i-R1
    @R1
    D=D-M
    
    //if i-R1 > 0, goto END
    @END
    D; JGT
    
    //get R0
    @R0
    D=M
    
    //R2=R0+R2
    @R2
    M=D+M
    
    //i=i+1
    @i
    M=M+1
    
    //goto loop
    @LOOP
    0;JMP
(END)
    //infite loop
    @END
    0; JMP
    
        