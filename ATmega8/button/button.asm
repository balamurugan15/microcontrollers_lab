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
   rjmp ext0_interrupt      ; Addr $01

.ORG 0x09
   rjmp tmr0      ; Addr $09


; Program starts here after Reset
;
start:
	LDI r16,0x04
   OUT SPH,r16
   LDI r16,0x5F
   OUT SPL,r16
   CBI DDRD,2
   SBI PORTD,2
   LDI r16,(1<<INT0)
   OUT GICR,r16
   LDI r16, (1<<ISC01)
   OUT MCUCR, r16
   LDI r16, 0x01
   OUT TIMSK,r16
   SBI DDRD,0
   SBI DDRD,1
   SEI


	


forever:	

rjmp forever

ext0_interrupt:
	LDI r17,0x64
	SBI PORTD,1
	OUT TCNT0,r17
	LDI r17,0x03
	OUT TCCR0,r17
reti


tmr0:
  LDI r18,0x00
  CBI PORTD,1
  OUT TCCR0,r18
  SBIS PIND,2
  SBI PORTD,0
  SBIC PIND,2
  CBI PORTD,0
reti


