@261
D=A
@SP
M=D
@Sys.init
0;JMP

//function Main.main 1
(Main.main)
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//call SquareGame.new 0
@_VMTRANSLATOR_0_return_address_Main.main_call_SquareGame.new
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
@0
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@SquareGame.new
0;JMP
(_VMTRANSLATOR_0_return_address_Main.main_call_SquareGame.new)

//pop local 0
@LCL
D=M
@0
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call SquareGame.run 1
@_VMTRANSLATOR_1_return_address_Main.main_call_SquareGame.run
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
@SquareGame.run
0;JMP
(_VMTRANSLATOR_1_return_address_Main.main_call_SquareGame.run)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call SquareGame.dispose 1
@_VMTRANSLATOR_2_return_address_Main.main_call_SquareGame.dispose
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
@SquareGame.dispose
0;JMP
(_VMTRANSLATOR_2_return_address_Main.main_call_SquareGame.dispose)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
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

//function SquareGame.new 0
(SquareGame.new)

//push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Memory.alloc 1
@_VMTRANSLATOR_3_return_address_SquareGame.new_call_Memory.alloc
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
@Memory.alloc
0;JMP
(_VMTRANSLATOR_3_return_address_SquareGame.new_call_Memory.alloc)

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//push constant 30
@30
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Square.new 3
@_VMTRANSLATOR_4_return_address_SquareGame.new_call_Square.new
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
@3
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Square.new
0;JMP
(_VMTRANSLATOR_4_return_address_SquareGame.new_call_Square.new)

//pop this 0
@THIS
D=M
@0
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
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

//function SquareGame.dispose 0
(SquareGame.dispose)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.dispose 1
@_VMTRANSLATOR_5_return_address_SquareGame.dispose_call_Square.dispose
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
@Square.dispose
0;JMP
(_VMTRANSLATOR_5_return_address_SquareGame.dispose_call_Square.dispose)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Memory.deAlloc 1
@_VMTRANSLATOR_6_return_address_SquareGame.dispose_call_Memory.deAlloc
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
@Memory.deAlloc
0;JMP
(_VMTRANSLATOR_6_return_address_SquareGame.dispose_call_Memory.deAlloc)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
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

//function SquareGame.run 2
(SquareGame.run)
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//pop local 1
@LCL
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label WHILE_EXP0
(SquareGame.run$WHILE_EXP0)

//push local 1
@LCL
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//not
@SP
A=M-1
M=!M

//not
@SP
A=M-1
M=!M

//if-goto WHILE_END0
@SP
AM=M-1
D=M
@SquareGame.run$WHILE_END0
D; JNE

//label WHILE_EXP1
(SquareGame.run$WHILE_EXP1)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_7_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_8_END
0;JMP
(_VMTRANSLATOR_7_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_8_END)

//not
@SP
A=M-1
M=!M

//if-goto WHILE_END1
@SP
AM=M-1
D=M
@SquareGame.run$WHILE_END1
D; JNE

//call Keyboard.keyPressed 0
@_VMTRANSLATOR_9_return_address_SquareGame.run_call_Keyboard.keyPressed
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
@0
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Keyboard.keyPressed
0;JMP
(_VMTRANSLATOR_9_return_address_SquareGame.run_call_Keyboard.keyPressed)

//pop local 0
@LCL
D=M
@0
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call SquareGame.moveSquare 1
@_VMTRANSLATOR_10_return_address_SquareGame.run_call_SquareGame.moveSquare
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
@SquareGame.moveSquare
0;JMP
(_VMTRANSLATOR_10_return_address_SquareGame.run_call_SquareGame.moveSquare)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//goto WHILE_EXP1
@SquareGame.run$WHILE_EXP1
0; JMP

//label WHILE_END1
(SquareGame.run$WHILE_END1)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 81
@81
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_11_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_12_END
0;JMP
(_VMTRANSLATOR_11_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_12_END)

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@SquareGame.run$IF_TRUE0
D; JNE

//goto IF_FALSE0
@SquareGame.run$IF_FALSE0
0; JMP

//label IF_TRUE0
(SquareGame.run$IF_TRUE0)

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//not
@SP
A=M-1
M=!M

//pop local 1
@LCL
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(SquareGame.run$IF_FALSE0)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 90
@90
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_13_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_14_END
0;JMP
(_VMTRANSLATOR_13_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_14_END)

//if-goto IF_TRUE1
@SP
AM=M-1
D=M
@SquareGame.run$IF_TRUE1
D; JNE

//goto IF_FALSE1
@SquareGame.run$IF_FALSE1
0; JMP

//label IF_TRUE1
(SquareGame.run$IF_TRUE1)

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.decSize 1
@_VMTRANSLATOR_15_return_address_SquareGame.run_call_Square.decSize
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
@Square.decSize
0;JMP
(_VMTRANSLATOR_15_return_address_SquareGame.run_call_Square.decSize)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE1
(SquareGame.run$IF_FALSE1)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 88
@88
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_16_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_17_END
0;JMP
(_VMTRANSLATOR_16_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_17_END)

//if-goto IF_TRUE2
@SP
AM=M-1
D=M
@SquareGame.run$IF_TRUE2
D; JNE

//goto IF_FALSE2
@SquareGame.run$IF_FALSE2
0; JMP

//label IF_TRUE2
(SquareGame.run$IF_TRUE2)

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.incSize 1
@_VMTRANSLATOR_18_return_address_SquareGame.run_call_Square.incSize
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
@Square.incSize
0;JMP
(_VMTRANSLATOR_18_return_address_SquareGame.run_call_Square.incSize)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE2
(SquareGame.run$IF_FALSE2)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 131
@131
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_19_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_20_END
0;JMP
(_VMTRANSLATOR_19_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_20_END)

//if-goto IF_TRUE3
@SP
AM=M-1
D=M
@SquareGame.run$IF_TRUE3
D; JNE

//goto IF_FALSE3
@SquareGame.run$IF_FALSE3
0; JMP

//label IF_TRUE3
(SquareGame.run$IF_TRUE3)

//push constant 1
@1
D=A
@SP
A=M
M=D
@SP
M=M+1

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE3
(SquareGame.run$IF_FALSE3)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 133
@133
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_21_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_22_END
0;JMP
(_VMTRANSLATOR_21_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_22_END)

//if-goto IF_TRUE4
@SP
AM=M-1
D=M
@SquareGame.run$IF_TRUE4
D; JNE

//goto IF_FALSE4
@SquareGame.run$IF_FALSE4
0; JMP

//label IF_TRUE4
(SquareGame.run$IF_TRUE4)

//push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE4
(SquareGame.run$IF_FALSE4)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 130
@130
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_23_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_24_END
0;JMP
(_VMTRANSLATOR_23_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_24_END)

//if-goto IF_TRUE5
@SP
AM=M-1
D=M
@SquareGame.run$IF_TRUE5
D; JNE

//goto IF_FALSE5
@SquareGame.run$IF_FALSE5
0; JMP

//label IF_TRUE5
(SquareGame.run$IF_TRUE5)

//push constant 3
@3
D=A
@SP
A=M
M=D
@SP
M=M+1

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE5
(SquareGame.run$IF_FALSE5)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 132
@132
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_25_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_26_END
0;JMP
(_VMTRANSLATOR_25_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_26_END)

//if-goto IF_TRUE6
@SP
AM=M-1
D=M
@SquareGame.run$IF_TRUE6
D; JNE

//goto IF_FALSE6
@SquareGame.run$IF_FALSE6
0; JMP

//label IF_TRUE6
(SquareGame.run$IF_TRUE6)

//push constant 4
@4
D=A
@SP
A=M
M=D
@SP
M=M+1

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE6
(SquareGame.run$IF_FALSE6)

//label WHILE_EXP2
(SquareGame.run$WHILE_EXP2)

//push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_27_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_28_END
0;JMP
(_VMTRANSLATOR_27_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_28_END)

//not
@SP
A=M-1
M=!M

//not
@SP
A=M-1
M=!M

//if-goto WHILE_END2
@SP
AM=M-1
D=M
@SquareGame.run$WHILE_END2
D; JNE

//call Keyboard.keyPressed 0
@_VMTRANSLATOR_29_return_address_SquareGame.run_call_Keyboard.keyPressed
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
@0
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Keyboard.keyPressed
0;JMP
(_VMTRANSLATOR_29_return_address_SquareGame.run_call_Keyboard.keyPressed)

//pop local 0
@LCL
D=M
@0
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call SquareGame.moveSquare 1
@_VMTRANSLATOR_30_return_address_SquareGame.run_call_SquareGame.moveSquare
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
@SquareGame.moveSquare
0;JMP
(_VMTRANSLATOR_30_return_address_SquareGame.run_call_SquareGame.moveSquare)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//goto WHILE_EXP2
@SquareGame.run$WHILE_EXP2
0; JMP

//label WHILE_END2
(SquareGame.run$WHILE_END2)

//goto WHILE_EXP0
@SquareGame.run$WHILE_EXP0
0; JMP

//label WHILE_END0
(SquareGame.run$WHILE_END0)

//push constant 0
@0
D=A
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

//function SquareGame.moveSquare 0
(SquareGame.moveSquare)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 1
@THIS
D=M
@1
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

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_31_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_32_END
0;JMP
(_VMTRANSLATOR_31_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_32_END)

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@SquareGame.moveSquare$IF_TRUE0
D; JNE

//goto IF_FALSE0
@SquareGame.moveSquare$IF_FALSE0
0; JMP

//label IF_TRUE0
(SquareGame.moveSquare$IF_TRUE0)

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.moveUp 1
@_VMTRANSLATOR_33_return_address_SquareGame.moveSquare_call_Square.moveUp
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
@Square.moveUp
0;JMP
(_VMTRANSLATOR_33_return_address_SquareGame.moveSquare_call_Square.moveUp)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(SquareGame.moveSquare$IF_FALSE0)

//push this 1
@THIS
D=M
@1
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

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_34_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_35_END
0;JMP
(_VMTRANSLATOR_34_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_35_END)

//if-goto IF_TRUE1
@SP
AM=M-1
D=M
@SquareGame.moveSquare$IF_TRUE1
D; JNE

//goto IF_FALSE1
@SquareGame.moveSquare$IF_FALSE1
0; JMP

//label IF_TRUE1
(SquareGame.moveSquare$IF_TRUE1)

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.moveDown 1
@_VMTRANSLATOR_36_return_address_SquareGame.moveSquare_call_Square.moveDown
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
@Square.moveDown
0;JMP
(_VMTRANSLATOR_36_return_address_SquareGame.moveSquare_call_Square.moveDown)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE1
(SquareGame.moveSquare$IF_FALSE1)

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 3
@3
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_37_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_38_END
0;JMP
(_VMTRANSLATOR_37_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_38_END)

//if-goto IF_TRUE2
@SP
AM=M-1
D=M
@SquareGame.moveSquare$IF_TRUE2
D; JNE

//goto IF_FALSE2
@SquareGame.moveSquare$IF_FALSE2
0; JMP

//label IF_TRUE2
(SquareGame.moveSquare$IF_TRUE2)

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.moveLeft 1
@_VMTRANSLATOR_39_return_address_SquareGame.moveSquare_call_Square.moveLeft
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
@Square.moveLeft
0;JMP
(_VMTRANSLATOR_39_return_address_SquareGame.moveSquare_call_Square.moveLeft)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE2
(SquareGame.moveSquare$IF_FALSE2)

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push constant 4
@4
D=A
@SP
A=M
M=D
@SP
M=M+1

//eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_40_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_41_END
0;JMP
(_VMTRANSLATOR_40_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_41_END)

//if-goto IF_TRUE3
@SP
AM=M-1
D=M
@SquareGame.moveSquare$IF_TRUE3
D; JNE

//goto IF_FALSE3
@SquareGame.moveSquare$IF_FALSE3
0; JMP

//label IF_TRUE3
(SquareGame.moveSquare$IF_TRUE3)

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.moveRight 1
@_VMTRANSLATOR_42_return_address_SquareGame.moveSquare_call_Square.moveRight
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
@Square.moveRight
0;JMP
(_VMTRANSLATOR_42_return_address_SquareGame.moveSquare_call_Square.moveRight)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE3
(SquareGame.moveSquare$IF_FALSE3)

//push constant 5
@5
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Sys.wait 1
@_VMTRANSLATOR_43_return_address_SquareGame.moveSquare_call_Sys.wait
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
@Sys.wait
0;JMP
(_VMTRANSLATOR_43_return_address_SquareGame.moveSquare_call_Sys.wait)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
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

//function Square.new 0
(Square.new)

//push constant 3
@3
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Memory.alloc 1
@_VMTRANSLATOR_44_return_address_Square.new_call_Memory.alloc
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
@Memory.alloc
0;JMP
(_VMTRANSLATOR_44_return_address_Square.new_call_Memory.alloc)

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

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

//pop this 0
@THIS
D=M
@0
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push argument 1
@ARG
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push argument 2
@ARG
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//pop this 2
@THIS
D=M
@2
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.draw 1
@_VMTRANSLATOR_45_return_address_Square.new_call_Square.draw
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
@Square.draw
0;JMP
(_VMTRANSLATOR_45_return_address_Square.new_call_Square.draw)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
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

//function Square.dispose 0
(Square.dispose)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Memory.deAlloc 1
@_VMTRANSLATOR_46_return_address_Square.dispose_call_Memory.deAlloc
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
@Memory.deAlloc
0;JMP
(_VMTRANSLATOR_46_return_address_Square.dispose_call_Memory.deAlloc)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
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

//function Square.draw 0
(Square.draw)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//not
@SP
A=M-1
M=!M

//call Screen.setColor 1
@_VMTRANSLATOR_47_return_address_Square.draw_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_47_return_address_Square.draw_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_48_return_address_Square.draw_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_48_return_address_Square.draw_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
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

//function Square.erase 0
(Square.erase)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Screen.setColor 1
@_VMTRANSLATOR_49_return_address_Square.erase_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_49_return_address_Square.erase_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_50_return_address_Square.erase_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_50_return_address_Square.erase_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
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

//function Square.incSize 0
(Square.incSize)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push constant 254
@254
D=A
@SP
A=M
M=D
@SP
M=M+1

//lt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_51_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_52_END
0;JMP
(_VMTRANSLATOR_51_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_52_END)

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push constant 510
@510
D=A
@SP
A=M
M=D
@SP
M=M+1

//lt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_53_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_54_END
0;JMP
(_VMTRANSLATOR_53_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_54_END)

//and
@SP
AM=M-1
D=M
A=A-1
M=D&M

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@Square.incSize$IF_TRUE0
D; JNE

//goto IF_FALSE0
@Square.incSize$IF_FALSE0
0; JMP

//label IF_TRUE0
(Square.incSize$IF_TRUE0)

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.erase 1
@_VMTRANSLATOR_55_return_address_Square.incSize_call_Square.erase
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
@Square.erase
0;JMP
(_VMTRANSLATOR_55_return_address_Square.incSize_call_Square.erase)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 2
@THIS
D=M
@2
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

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//pop this 2
@THIS
D=M
@2
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.draw 1
@_VMTRANSLATOR_56_return_address_Square.incSize_call_Square.draw
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
@Square.draw
0;JMP
(_VMTRANSLATOR_56_return_address_Square.incSize_call_Square.draw)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(Square.incSize$IF_FALSE0)

//push constant 0
@0
D=A
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

//function Square.decSize 0
(Square.decSize)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 2
@THIS
D=M
@2
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

//gt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_57_GT
D;JGT
@SP
A=M-1
M=0
@_VMTRANSLATOR_58_END
0;JMP
(_VMTRANSLATOR_57_GT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_58_END)

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@Square.decSize$IF_TRUE0
D; JNE

//goto IF_FALSE0
@Square.decSize$IF_FALSE0
0; JMP

//label IF_TRUE0
(Square.decSize$IF_TRUE0)

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.erase 1
@_VMTRANSLATOR_59_return_address_Square.decSize_call_Square.erase
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
@Square.erase
0;JMP
(_VMTRANSLATOR_59_return_address_Square.decSize_call_Square.erase)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 2
@THIS
D=M
@2
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

//pop this 2
@THIS
D=M
@2
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push pointer 0
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

//call Square.draw 1
@_VMTRANSLATOR_60_return_address_Square.decSize_call_Square.draw
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
@Square.draw
0;JMP
(_VMTRANSLATOR_60_return_address_Square.decSize_call_Square.draw)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(Square.decSize$IF_FALSE0)

//push constant 0
@0
D=A
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

//function Square.moveUp 0
(Square.moveUp)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 1
@THIS
D=M
@1
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

//gt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_61_GT
D;JGT
@SP
A=M-1
M=0
@_VMTRANSLATOR_62_END
0;JMP
(_VMTRANSLATOR_61_GT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_62_END)

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@Square.moveUp$IF_TRUE0
D; JNE

//goto IF_FALSE0
@Square.moveUp$IF_FALSE0
0; JMP

//label IF_TRUE0
(Square.moveUp$IF_TRUE0)

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Screen.setColor 1
@_VMTRANSLATOR_63_return_address_Square.moveUp_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_63_return_address_Square.moveUp_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

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

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_64_return_address_Square.moveUp_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_64_return_address_Square.moveUp_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 1
@THIS
D=M
@1
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

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//not
@SP
A=M-1
M=!M

//call Screen.setColor 1
@_VMTRANSLATOR_65_return_address_Square.moveUp_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_65_return_address_Square.moveUp_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
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

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_66_return_address_Square.moveUp_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_66_return_address_Square.moveUp_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(Square.moveUp$IF_FALSE0)

//push constant 0
@0
D=A
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

//function Square.moveDown 0
(Square.moveDown)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push constant 254
@254
D=A
@SP
A=M
M=D
@SP
M=M+1

//lt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_67_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_68_END
0;JMP
(_VMTRANSLATOR_67_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_68_END)

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@Square.moveDown$IF_TRUE0
D; JNE

//goto IF_FALSE0
@Square.moveDown$IF_FALSE0
0; JMP

//label IF_TRUE0
(Square.moveDown$IF_TRUE0)

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Screen.setColor 1
@_VMTRANSLATOR_69_return_address_Square.moveDown_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_69_return_address_Square.moveDown_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
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

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_70_return_address_Square.moveDown_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_70_return_address_Square.moveDown_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 1
@THIS
D=M
@1
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

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//pop this 1
@THIS
D=M
@1
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//not
@SP
A=M-1
M=!M

//call Screen.setColor 1
@_VMTRANSLATOR_71_return_address_Square.moveDown_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_71_return_address_Square.moveDown_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

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

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_72_return_address_Square.moveDown_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_72_return_address_Square.moveDown_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(Square.moveDown$IF_FALSE0)

//push constant 0
@0
D=A
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

//function Square.moveLeft 0
(Square.moveLeft)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 0
@THIS
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

//gt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_73_GT
D;JGT
@SP
A=M-1
M=0
@_VMTRANSLATOR_74_END
0;JMP
(_VMTRANSLATOR_73_GT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_74_END)

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@Square.moveLeft$IF_TRUE0
D; JNE

//goto IF_FALSE0
@Square.moveLeft$IF_FALSE0
0; JMP

//label IF_TRUE0
(Square.moveLeft$IF_TRUE0)

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Screen.setColor 1
@_VMTRANSLATOR_75_return_address_Square.moveLeft_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_75_return_address_Square.moveLeft_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

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

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_76_return_address_Square.moveLeft_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_76_return_address_Square.moveLeft_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
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

//pop this 0
@THIS
D=M
@0
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//not
@SP
A=M-1
M=!M

//call Screen.setColor 1
@_VMTRANSLATOR_77_return_address_Square.moveLeft_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_77_return_address_Square.moveLeft_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
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

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_78_return_address_Square.moveLeft_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_78_return_address_Square.moveLeft_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(Square.moveLeft$IF_FALSE0)

//push constant 0
@0
D=A
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

//function Square.moveRight 0
(Square.moveRight)

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

//pop pointer 0
@SP
A=M-1
D=M
@THIS
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push constant 510
@510
D=A
@SP
A=M
M=D
@SP
M=M+1

//lt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_79_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_80_END
0;JMP
(_VMTRANSLATOR_79_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_80_END)

//if-goto IF_TRUE0
@SP
AM=M-1
D=M
@Square.moveRight$IF_TRUE0
D; JNE

//goto IF_FALSE0
@Square.moveRight$IF_FALSE0
0; JMP

//label IF_TRUE0
(Square.moveRight$IF_TRUE0)

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//call Screen.setColor 1
@_VMTRANSLATOR_81_return_address_Square.moveRight_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_81_return_address_Square.moveRight_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
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

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_82_return_address_Square.moveRight_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_82_return_address_Square.moveRight_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
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

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//pop this 0
@THIS
D=M
@0
D=A+D
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1

//not
@SP
A=M-1
M=!M

//call Screen.setColor 1
@_VMTRANSLATOR_83_return_address_Square.moveRight_call_Screen.setColor
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
@Screen.setColor
0;JMP
(_VMTRANSLATOR_83_return_address_Square.moveRight_call_Screen.setColor)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

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

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 0
@THIS
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//push this 1
@THIS
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//push this 2
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=D+M

//call Screen.drawRectangle 4
@_VMTRANSLATOR_84_return_address_Square.moveRight_call_Screen.drawRectangle
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
@4
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Screen.drawRectangle
0;JMP
(_VMTRANSLATOR_84_return_address_Square.moveRight_call_Screen.drawRectangle)

//pop temp 0
@R5
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1

//label IF_FALSE0
(Square.moveRight$IF_FALSE0)

//push constant 0
@0
D=A
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

