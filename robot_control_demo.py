import pygame
import sys
import serial
from pygame.locals import *

pygame.init()

# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

size = (700, 500)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("MOARbots Joystick Control")

joystickRaw = pygame.joystick.Joystick(0);
joystickRaw.init()

class JoystickAbstractionLayer:
	def __init__(self, joystick):
		self.joystick = joystick
		self.sticks = []

	@property
	def y1(self):
		return self.joystick.get_axis(1)

	@property
	def x1(self):
		return self.joystick.get_axis(0)

	@property
	def y2(self):
		return self.joystick.get_axis(3)

	@property
	def x2(self):
		return self.joystick.get_axis(2)

def map(value, leftMin, leftMax, rightMin, rightMax):
    # Figure out how 'wide' each range is
    leftSpan = leftMax - leftMin
    rightSpan = rightMax - rightMin

    # Convert the left range into a 0-1 range (float)
    valueScaled = float(value - leftMin) / float(leftSpan)

    # Convert the 0-1 range into a value in the right range.
    return rightMin + (valueScaled * rightSpan)

joystick = JoystickAbstractionLayer(joystickRaw)
joystick_deadband = 10

wixel = serial.Serial(sys.argv[1], 115200)

while True:
	pygame.event.pump()

	for event in pygame.event.get():
		if event.type == QUIT:
			print("QUIT")
			pygame.quit()
			wixel.close()
			sys.exit()

	lside = map(abs(joystick.y1), 0, 1, 0, 255)
	rside = map(abs(joystick.y2), 0, 1, 0, 255)
	if (lside > 0 and lside < joystick_deadband) or (lside < 0 and lside > joystick_deadband):
		lside = 0

	if (rside > 0 and rside < joystick_deadband) or (rside < 0 and rside > joystick_deadband):
		rside = 0

	directionFlags = 0b00000000

	if joystick.y1 < 0:
		directionFlags |= (1 << 0)
	else:
		directionFlags &= ~(1 << 0)

	if joystick.y2 < 0:
		directionFlags |= (1 << 1)
	else:
		directionFlags &= ~(1 << 1)

	lside = int(lside)
	rside = int(rside)


	print(str(lside) + " :: " + str(rside) + " ::/:: " + str(bin(directionFlags)))


	wixel.write(chr(0xFF))
	wixel.write(chr(lside))
	wixel.write(chr(rside))
	wixel.write(chr(directionFlags))
	wixel.write(chr(0xFF))

	pygame.display.update()