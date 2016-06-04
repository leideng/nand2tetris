// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.

// while(1)
// {
//     if(keyboard == 0)
//           clear the screen
//     else
//           set the screen
// }


(LOOP)
    //get keyboard value
    @KBD
    D=M
    
    //store the keyboard value into variable keyboard
    @keyboard
    M=D
    
    //set variable i=SCREEN
    @SCREEN
    D=A
    
    @i
    M=D
    
    //loop for set/clear the screen
    (SCEENLOOP)
        //get i
        @i
        D=M
        
        //get KBD address value
        @KBD
        D=D-A
        
        //i >= KBD, goto LOOP
        @LOOP
        D; JGE
        
        //otherwise, set or clear the screen block i
        //get the keyboard value
        @keyboard
        D=M
        
        //if keyboard==0, goto CLEAR 
        @CLEAR
        D; JEQ
        
        //otherwise, set the screen
        @i
        A=M
        M=-1
        @INC
        0; JMP
        
        
        (CLEAR)
            @i
            A=M
            M=0
        
        (INC) 
            //i=i+1
            @i
            M=M+1
        
        
        //goto SCEENLOOP
        @SCEENLOOP
        0; JMP
    
    
    
    