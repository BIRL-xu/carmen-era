from era_comm import *

p = ArmConfigPublisher()

i = 0

while True:
  p.shoulder_yaw = i
  print p.shoulder_yaw
  p.send()
  i += 1