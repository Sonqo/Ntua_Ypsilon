.include "m16def.inc"

.DSEG
	_tmp_: .byte 2

.CSEG

main:
	ldi r24, low(RAMEND)	; initializing stack pointer
	out SPL, r24
	ldi r24, high(RAMEND)
	out SPH, r24			
	ser r24					; initializing PORTD for output
	out DDRD, r24
	clr r24
	rcall lcd_init

write_2_nibbles:
	push r24
	in r25, PIND 
	andi r25, 0x0F
	andi r24, 0xF0
	add r24, r25 
	out PORTD, r24 
	sbi PORTD, PD3		; enable pulse
	cbi PORTD, PD3 
	pop r24 
	swap r24 
	andi r24, 0xF0 
	add r24, r25
	out PORTD, r24
	sbi PORTD, PD3		; enable pulse
	cbi PORTD, PD3
	ret

lcd_data:				; data transfered located in register r24
	sbi PORTD, PD2 
	rcall write_2_nibbles
	ldi r24, 43			; 43ms delay
	ldi r25, 0
	rcall wait_usec
	ret

lcd_command:
	cbi PORTD, PD2 
	rcall write_2_nibbles
	ldi r24, 39			; 39ms delay
	ldi r25, 0 
	rcall wait_usec 
	ret

lcd_init:
	ldi r24, 40
	ldi r25, 0 
	rcall wait_msec		; initial delay of 40ms
	ldi r24, 0x30		; setting to 8-bit mode
	out PORTD, r24 
	sbi PORTD, PD3		; enable pulse
	cbi PORTD, PD3 
	ldi r24, 39
	ldi r25, 0 
	rcall wait_usec 
	ldi r24, 0x30		; re-setting to 8-bit mode
	out PORTD, r24
	sbi PORTD, PD3		; enable pulse
	cbi PORTD, PD3
	ldi r24, 39
	ldi r25, 0
	rcall wait_usec
	ldi r24, 0x20		; switch to 4-bit mode
	out PORTD, r24
	sbi PORTD, PD3		; enable pulse
	cbi PORTD, PD3
	ldi r24, 39
	ldi r25, 0
	rcall wait_usec
	ldi r24, 0x28		; two-line display in a 5x8 mannner
	rcall lcd_command 
	ldi r24, 0x0c		; hide cursor
	rcall lcd_command
	ldi r24, 0x01		; clear display
	rcall lcd_command
	ldi r24, low(1530)
	ldi r25, high(1530)
	rcall wait_usec
	ldi r24, 0x06		; disable screen shifting
	rcall lcd_command 
	ret

scan_row:				; scanning row number r24 for pressed keys, returns respective status in r24
		ldi r25, 0x08
back:	lsl r25
		dec r24
		brne back
		out PORTC, r25
		nop				; waitng for status switching to take place
		nop
		in r24, PINC
		andi r24, 0x0F	; status isolated in LSBs of r24
		ret

scan_keypad:			; returns in register pair r25:r24 the keypad status of all 16 keys - calls scan row
		ldi r24, 0x01
		rcall scan_row	; checking 1st line
		swap r24
		mov r27, r24
		ldi r24, 0x02
		rcall scan_row	; checking 2nd line
		add r27, r24
		ldi r24, 0x03
		rcall scan_row	; checking 3rd line
		swap r24
		mov r26, r24
		ldi r24, 0x04
		rcall scan_row	; checking 4th line
		add r26, r24
		movw r24, r26
		ret

scan_keypad_rising_edge:	
		mov r22, r24	; save delay timer(r24) before first read
		rcall scan_keypad
		push r24		; save status to stack
		push r25
		mov r24, r22	
		ldi r25, 0x00
		rcall wait_msec	; delay before rechecking
		rcall scan_keypad
		pop r23
		pop r22
		and r24, r22	; discard
		and r25, r23
		ldi r26, low(_tmp_)
		ldi r27, high(_tmp_)
		ld r23, X+
		ld r22, X
		st X, r24 
		st -X, r25 
		com r23
		com r22 
		and r24, r22
		and r25, r23
		ret

keypad_to_hex: 
		movw r26, r24 
		ldi r24, 0x0E
		sbrc r26, 0
		ret
		ldi r24, 0x00
		sbrc r26, 1
		ret
		ldi r24, 0x0F
		sbrc r26, 2
		ret
		ldi r24, 0x0D
		sbrc r26, 3 
		ret 
		ldi r24, 0x07
		sbrc r26, 4
		ret
		ldi r24, 0x08
		sbrc r26, 5
		ret
		ldi r24, 0x09
		sbrc r26, 6
		ret
		ldi r24, 0x0C
		sbrc r26, 7
		ret
		ldi r24, 0x04
		sbrc r27, 0 
		ret
		ldi r24, 0x05
		sbrc r27, 1
		ret
		ldi r24, 0x06
		sbrc r27, 2
		ret
		ldi r24, 0x0B
		sbrc r27, 3
		ret
		ldi r24, 0x01
		sbrc r27, 4
		ret
		ldi r24, 0x02
		sbrc r27, 5
		ret
		ldi r24, 0x03
		sbrc r27, 6
		ret
		ldi r24, 0x0A
		sbrc r27, 7
		ret
		clr r24
		ret

wait_msec:			; delay routine, calls wait_usec
	push r24 
	push r25 
	ldi r24, low(998) 
	ldi r25, high(998) 
	rcall wait_usec
	pop r25 
	pop r24 
	sbiw r24, 1 
	brne wait_msec 
	ret

wait_usec:
	sbiw r24, 1 
	nop 
	nop 
	nop 
	nop 
	brne wait_usec 
	ret 