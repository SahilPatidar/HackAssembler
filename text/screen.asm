
(LOOP)


@SCREEN
D=A

@i
M=D

@KBD
D=M
@WHITE
D;JEQ

D=-1

(WHITE)
@val
M=D


(SCREEN1)

@i
D=M

@KBD 
D=D-A

@LOOP
D;JGE

@val
D=M


@i
A=M
M=D
D=A+1
@i
M=D


@SCREEN1
0;JMP
