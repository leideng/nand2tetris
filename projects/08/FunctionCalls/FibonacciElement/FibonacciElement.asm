@261
D=A
@SP
M=D
@Sys.init
0;JMP

//function Main.fibonacci 0
(Main.fibonacci)

//push argument 0
@ARG
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1

//lt                     // check if n < 2
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_0_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_1_END
0;JMP
(_VMTRANSLATOR_0_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_1_END)

//if-goto IF_TRUE
@SP
AM=M-1
D=M
@Main.fibonacci$IF_TRUE
D; JNE

//goto IF_FALSE
@Main.fibonacci$IF_FALSE
0; JMP

//label IF_TRUE          // if n<2, return n
(Main.fibonacci$IF_TRUE)

//push argument 0        
@ARG
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//return
@LCL
D=M
@R13
M=D
@5
A=D-A
D=M
@R14
M=D
@SP
AM=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@R13
A=M-1
D=M
@THAT
M=D
@R13
D=M
@2
A=D-A
D=M
@THIS
M=D
@R13
D=M
@3
A=D-A
D=M
@ARG
M=D
@R13
D=M
@4
A=D-A
D=M
@LCL
M=D
@R14
A=M
0;JMP

//label IF_FALSE         // if n>=2, return fib(n-2)+fib(n-1)
(Main.fibonacci$IF_FALSE)

//push argument 0
@ARG
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1

//sub
@SP
AM=M-1
D=M
A=A-1
M=M-D

//call Main.fibonacci 1  // compute fib(n-2)
@_VMTRANSLATOR_2_return_address_Main.fibonacci_call_Main.fibonacci
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Main.fibonacci
0;JMP
(_VMTRANSLATOR_2_return_address_Main.fibonacci_call_Main.fibonacci)

//push argument 0
@ARG
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 1
@1
D=A
@SP
A=M
M=D
@SP
M=M+1

//sub
@SP
AM=M-1
D=M
A=A-1
M=M-D

//call Main.fibonacci 1  // compute fib(n-1)
@_VMTRANSLATOR_3_return_address_Main.fibonacci_call_Main.fibonacci
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Main.fibonacci
0;JMP
(_VMTRANSLATOR_3_return_address_Main.fibonacci_call_Main.fibonacci)

//add                    // return fib(n-1) + fib(n-2)
@SP
AM=M-1
D=M
A=A-1
M=D+M

//return
@LCL
D=M
@R13
M=D
@5
A=D-A
D=M
@R14
M=D
@SP
AM=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@R13
A=M-1
D=M
@THAT
M=D
@R13
D=M
@2
A=D-A
D=M
@THIS
M=D
@R13
D=M
@3
A=D-A
D=M
@ARG
M=D
@R13
D=M
@4
A=D-A
D=M
@LCL
M=D
@R14
A=M
0;JMP

//function Sys.init 0
(Sys.init)

//push constant 4
@4
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Main.fibonacci 1   // Compute the 4'th fibonacci element
@_VMTRANSLATOR_4_return_address_Sys.init_call_Main.fibonacci
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Main.fibonacci
0;JMP
(_VMTRANSLATOR_4_return_address_Sys.init_call_Main.fibonacci)

//label WHILE
(Sys.init$WHILE)

//goto WHILE              // Loop infinitely
@Sys.init$WHILE
0; JMP

