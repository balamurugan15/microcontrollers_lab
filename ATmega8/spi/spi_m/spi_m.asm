; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def  temp  =r16

; Define here Reset and interrupt vectors, if any
;
reset:
   rjmp start
   reti      ; Addr $01
   reti      ; Addr $02
   reti      ; Addr $03
   reti      ; Addr $04
   reti      ; Addr $05
   reti      ; Addr $06        Use 'rjmp myVector'
   reti      ; Addr $07        to define a interrupt vector
   reti      ; Addr $08
   reti      ; Addr $09
   reti      ; Addr $0A
   reti      ; Addr $0B        This is just an example
   reti      ; Addr $0C        Not all MCUs have the same
   reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset
;
start:
	LDI r16,0x00
	OUT DDRD,r16
	LDI r16,0xFF
	OUT PORTD,r16
   SBI DDRB,3
   SBI DDRB,5
   CBI DDRB,2
   LDI r16,(1<<SPE)|(1<<MSTR)|(1<<SPR0)
	OUT SPCR,r16

forever:
	IN r0,PIND
	OUT SPDR,r0
  	Wait_Transmit:
		sbis SPSR,SPIF
		rjmp Wait_Transmit
		;LDI r16,(1<<SPIF)
		;MOV r0,SPCR
		;AND r16,r0
		;BREQ Wait_Transmit
		;

rjmp forever

