@17
D=A
@SP
A=M
M=D
@SP
M=M+1

@17
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_0_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_1_END
0;JMP
(_VMTRANSLATOR_0_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_1_END)

@17
D=A
@SP
A=M
M=D
@SP
M=M+1

@16
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_2_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_3_END
0;JMP
(_VMTRANSLATOR_2_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_3_END)

@16
D=A
@SP
A=M
M=D
@SP
M=M+1

@17
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_4_EQ
D;JEQ
@SP
A=M-1
M=0
@_VMTRANSLATOR_5_END
0;JMP
(_VMTRANSLATOR_4_EQ)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_5_END)

@892
D=A
@SP
A=M
M=D
@SP
M=M+1

@891
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_6_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_7_END
0;JMP
(_VMTRANSLATOR_6_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_7_END)

@891
D=A
@SP
A=M
M=D
@SP
M=M+1

@892
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_8_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_9_END
0;JMP
(_VMTRANSLATOR_8_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_9_END)

@891
D=A
@SP
A=M
M=D
@SP
M=M+1

@891
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_10_LT
D;JLT
@SP
A=M-1
M=0
@_VMTRANSLATOR_11_END
0;JMP
(_VMTRANSLATOR_10_LT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_11_END)

@32767
D=A
@SP
A=M
M=D
@SP
M=M+1

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_12_GT
D;JGT
@SP
A=M-1
M=0
@_VMTRANSLATOR_13_END
0;JMP
(_VMTRANSLATOR_12_GT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_13_END)

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1

@32767
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_14_GT
D;JGT
@SP
A=M-1
M=0
@_VMTRANSLATOR_15_END
0;JMP
(_VMTRANSLATOR_14_GT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_15_END)

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
D=M-D
@_VMTRANSLATOR_16_GT
D;JGT
@SP
A=M-1
M=0
@_VMTRANSLATOR_17_END
0;JMP
(_VMTRANSLATOR_16_GT)
@SP
A=M-1
M=-1
(_VMTRANSLATOR_17_END)

@57
D=A
@SP
A=M
M=D
@SP
M=M+1

@31
D=A
@SP
A=M
M=D
@SP
M=M+1

@53
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
M=D+M

@112
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
M=M-D

@SP
A=M-1
M=-M

@SP
AM=M-1
D=M
A=A-1
M=D&M

@82
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
A=A-1
M=D|M

@SP
A=M-1
M=!M

