import time
import board
import busio
import adafruit_am2320
import smbus

I2C_CH = 1
CONT_H_RES_MODE = 0x10
BH1750_DEV_ADDR = 0x23


i2c2 = smbus.SMBus(I2C_CH)

i2c = busio.I2C(board.SCL, board.SDA)
am = adafruit_am2320.AM2320(i2c)


def getLux():
    luxBytes = i2c2.read_i2c_block_data(BH1750_DEV_ADDR, CONT_H_RES_MODE,2)
    lux = int.from_bytes(luxBytes, byteorder='big')
    return lux

def getTemp():
    for i in range(0, 2):
        try:
            temp = am.temperature
        except:
            pass
    return temp

def getPh():
	
	return ph

def getHum():
    for i in range(0, 2):
        try:
            hum = am.relative_humidity
        except:
            pass
    return hum
