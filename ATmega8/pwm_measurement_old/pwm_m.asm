; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def  temp  =r16

.def start_timel = r28
.def start_timeh = r29

.def end_timel = r30
.def end_timeh = r31


; Define here Reset and interrupt vectors, if any
;
reset:
   rjmp start
   rjmp ext0      ; Addr $01
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
	LDI r16,0x04
   OUT SPH,r16
   LDI r16,0x5F
   OUT SPL,r16
   CBI DDRD,2
   SBI PORTD,2
   LDI r16,(1<<INT0)
   OUT GICR,r16
   LDI r16, ((1<<ISC01) | (1<<ISC00))
   OUT MCUCR, r16

	LDI r23,0x01
	
	LDI r20,0x00;
	
	
	LDI r16,0x00;
	OUT TCNT1H,r16
	OUT TCNT1L,r16

	LDI r16,((1<<WGM12) | (1<<CS10))
	OUT TCCR1B,r16
	SEI
	
	
forever:



	
	

rjmp forever




ext0:
; set clock to timer
  ; in r18,SREG
; Disable interrupts
   cli
   IN r26,TCNT1L
   IN r27,TCNT1H
   SEI
  ; out SREG,r18
	LDI r16,0x01
	AND r23,r16
	BREQ fall_detected
	
	rise_detected:
	LDI r16, (1<<ISC01) ; detect falling edge
   OUT MCUCR, r16
   MOV start_timel,r26
   MOV start_timeh,r27
   LDI r23,0x00
   rjmp nxt

	fall_detected:
	MOV end_timel,r26
   MOV end_timeh,r27
	LDI r16, ((1<<ISC01) | (1<<ISC00)) ;detect rising edge
   OUT MCUCR, r16
   LDI r16,((1<<WGM12))
	OUT TCCR1B,r16

 ;  SUB Z,Y
   SUB r26,start_timel;
   SBC r27,start_timeh
   LDI r16,0x00
	
	nxt:
	reti




