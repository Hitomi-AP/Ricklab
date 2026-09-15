from RPLCD.gpio import CharLCD
import RPi.GPIO as GPIO
import time

lcd = CharLCD(
    numbering_mode=GPIO.BCM,
    cols=16,
    rows=2,
    pin_rs=25,
    pin_e=24,
    pins_data=[23, 17, 18, 22]
)

lcd.clear()

lcd.write_string("Bonjour !")
lcd.cursor_pos = (1, 0)
lcd.write_string("Raspberry Pi")

time.sleep(10)

lcd.clear()
GPIO.cleanup()